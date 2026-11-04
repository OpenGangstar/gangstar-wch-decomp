"""Compile, link and byte-check the source units in config/matches/.

Usage: python tools/build.py logs
       python tools/build.py --all

Windows defaults to the local NDK r4b and Cygwin runtime described in
docs/COMPILER-NOTES.md. Override the compiler root with --toolchain or
WCH_TOOLCHAIN_ROOT. On other hosts the root must contain bin/arm-eabi-g++.
This builds verification images, not a complete game library.
"""

from __future__ import annotations

if __package__ in (None, ""):
    import pathlib
    import sys

    sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent.parent))
    __package__ = "tools"

import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
import sys

from . import check
from .elf import ElfFile
from .project import BASE_LIB_SHA256, ROOT, find_base_library, load_base_library
from .retail_got import write_harness
from .thumb_bindings import write_bindings


def run(command: list[str], environment: dict[str, str]) -> None:
    """Fail immediately rather than checking stale output after a failed step."""
    subprocess.run(command, cwd=ROOT, env=environment, check=True)


def function_selector(entry) -> tuple[str, int | None, str | None]:
    """Validate a manifest selector for either CLI or in-memory comparison."""
    if isinstance(entry, str) and entry:
        return entry, None, None
    if not isinstance(entry, dict) or set(entry) not in ({"name", "address"}, {"name", "address", "compiled_name"}):
        raise ValueError("function selector must be a name or {name, address[, compiled_name]}")
    name, address = entry["name"], entry["address"]
    if not isinstance(name, str) or not name or isinstance(address, bool):
        raise ValueError("function selector requires a name and integer address")
    if isinstance(address, str):
        address = int(address, 0)
    if not isinstance(address, int) or not 0 <= address <= 0xffffffff:
        raise ValueError("function address must be a 32-bit integer")
    compiled_name = None
    if "compiled_name" in entry:
        compiled_name = entry["compiled_name"]
        if not isinstance(compiled_name, str) or not compiled_name:
            raise ValueError("compiled_name must be a nonempty callback name")
    return name, address, compiled_name


def comparison_arguments(entry) -> list[str]:
    """Translate a validated manifest selector into the checker's CLI options."""
    name, address, compiled_name = function_selector(entry)
    arguments = ["--func", name]
    if address is not None:
        arguments += ["--address", f"0x{address:08x}"]
    if compiled_name is not None:
        arguments += ["--compiled-func", compiled_name]
    return arguments


def check_section(retail: ElfFile, image: ElfFile, name: str, offset: int = 0) -> bool:
    """Check emitted data and alignment as well as individual function bytes."""
    section = image.section(name)
    if section is None or not section.is_alloc or section.sh_size == 0:
        print(f"MISSING SECTION {name}", file=sys.stderr)
        return False
    if offset < 0 or offset >= section.sh_size:
        raise ValueError(f"invalid comparison offset in {name}")
    address = section.sh_addr + offset
    actual = image.data[section.sh_offset + offset:section.sh_offset + section.sh_size]
    retail_section = retail.section_for_address(address)
    if retail_section is None or address + len(actual) > retail_section.sh_addr + retail_section.sh_size:
        raise ValueError(f"comparison extends beyond a retail section: {name}")
    expected = retail.read_at(address, len(actual))
    ok, detail = check.compare(expected, actual)
    if ok:
        label = f"REGION {name}+0x{offset:x}" if offset else f"SECTION {name}"
        print(f"OK {label}  0x{address:08x}  {len(actual)} bytes")
    else:
        print(f"MISMATCH SECTION {name}\n{detail}", file=sys.stderr)
    return ok


def build_unit(name: str, compiler_root: Path | None, base_library: Path,
               active: tuple[str, ...] = ()) -> bool:
    if name in active:
        raise ValueError("cyclic build dependency: " + " -> ".join((*active, name)))
    manifest = json.loads((ROOT / "config" / "matches" / f"{name}.json").read_text())
    source_first = manifest.get("source_first", False)
    if not isinstance(source_first, bool):
        raise ValueError("source_first must be a boolean")
    for dependency in manifest.get("dependencies", []):
        if not build_unit(dependency, compiler_root, base_library, (*active, name)):
            return False
    return _build_unit(name, compiler_root, base_library, manifest)


def build_units(names: list[str], compiler_root: Path | None, base_library: Path) -> bool:
    """Plan one invocation, then verify each required unit once, dependencies first.

    This is not an incremental cache: every invocation compiles from source.
    As with a normal build, inputs must not be edited while it is running.
    """
    manifests = {}
    ordered = []

    def visit(name, active=()):
        if name in active:
            raise ValueError("cyclic build dependency: " + " -> ".join((*active, name)))
        if name in manifests:
            return
        manifest = json.loads((ROOT / "config/matches" / f"{name}.json").read_text())
        if not isinstance(manifest.get("source_first", False), bool):
            raise ValueError("source_first must be a boolean")
        for dependency in manifest.get("dependencies", []):
            visit(dependency, (*active, name))
        manifests[name] = manifest
        ordered.append(name)

    for name in names:
        visit(name)
    results = {}
    for name in ordered:
        manifest = manifests[name]
        failed = [dep for dep in manifest.get("dependencies", []) if not results[dep]]
        if failed:
            print(f"SKIP {name}: failed dependencies: {', '.join(failed)}", file=sys.stderr)
            results[name] = False
        else:
            print(f"BUILD {name}")
            results[name] = _build_unit(name, compiler_root, base_library, manifest)
    return all(results.values())


def _build_unit(name: str, compiler_root: Path | None, base_library: Path,
                manifest: dict) -> bool:
    """Build and compare a unit whose dependencies have already passed."""
    source_first = manifest.get("source_first", False)
    dependency_objects = [f"build/matches/{dep}/{dep}.o"
                          for dep in manifest.get("dependencies", [])]
    if compiler_root is None:
        compiler_root = ROOT / manifest.get("toolchain",
            "toolchain/android-ndk-r4b/build/prebuilt/windows/arm-eabi-4.2.1")
    compiler_root = compiler_root.resolve()
    output = ROOT / "build" / "matches" / name
    output.mkdir(parents=True, exist_ok=True)
    assembly = (output / f"{name}.s").relative_to(ROOT).as_posix()
    obj = (output / f"{name}.o").relative_to(ROOT).as_posix()
    image = (output / f"{name}.elf").relative_to(ROOT).as_posix()
    environment = os.environ.copy()
    extension = ".exe" if os.name == "nt" else ""
    binary = compiler_root / "bin"

    if os.name == "nt":
        environment["PATH"] = str(ROOT / "toolchain/cygwin32/bin") + os.pathsep + environment["PATH"]
        # Avoid legacy Cygwin driver's fork failure on current Windows.
        frontend = compiler_root / "libexec/gcc/arm-eabi/4.2.1/cc1plus.exe"
        run([str(frontend), "-quiet", *manifest["compiler_flags"],
             manifest["source"], "-o", assembly], environment)
        run([str(binary / "arm-eabi-as.exe"), *manifest["assembler_flags"],
             "-o", obj, assembly], environment)
    else:
        run([str(binary / "arm-eabi-g++"), *manifest["compiler_flags"],
             "-c", manifest["source"], "-o", obj], environment)

    objects = [obj, *dependency_objects] if source_first else [*dependency_objects, obj]
    retail, _ = load_base_library(base_library)
    compiled_source = ElfFile.load(str(ROOT / obj))
    dependencies = ()
    if manifest.get("retail_got") or manifest.get("external_thumb_functions"):
        dependencies = tuple(ElfFile.load(str(ROOT / path)) for path in dependency_objects)
    if manifest.get("retail_got"):
        harness_source, _ = write_harness(retail, compiled_source, output, dependencies)
        harness_obj = output / "retail-got.o"
        harness_flags = ["-O0", "-fpic", "-fno-exceptions", "-fno-rtti",
                         "-fno-unwind-tables", "-fno-asynchronous-unwind-tables",
                         "-mthumb", "-march=armv5te"]
        if os.name == "nt":
            harness_assembly = output / "retail-got.s"
            run([str(frontend), "-quiet", *harness_flags,
                 str(harness_source), "-o", str(harness_assembly)], environment)
            run([str(binary / "arm-eabi-as.exe"), *manifest["assembler_flags"],
                 "-o", str(harness_obj), str(harness_assembly)], environment)
        else:
            run([str(binary / "arm-eabi-g++"), *harness_flags, "-c",
                 str(harness_source), "-o", str(harness_obj)], environment)
        # The harness must establish hash insertion order before the game unit.
        objects.insert(0, harness_obj.relative_to(ROOT).as_posix())

    if manifest.get("external_thumb_functions"):
        if not manifest.get("linker_script"):
            raise ValueError("external Thumb functions require a linked verification image")
        compiled = (*dependencies, compiled_source)
        binding_source = write_bindings(retail, compiled,
                                        manifest["external_thumb_functions"], output)
        binding_object = output / "external-thumb.o"
        run([str(binary / f"arm-eabi-as{extension}"), *manifest["assembler_flags"],
             "-o", str(binding_object), str(binding_source)], environment)
        objects.append(binding_object.relative_to(ROOT).as_posix())

    comparison_file = obj
    if manifest.get("linker_script"):
        run([str(binary / f"arm-eabi-ld{extension}"),
             "-T", manifest["linker_script"], "-Map", str(output / f"{name}.map"),
             "-o", image, *objects], environment)
        comparison_file = image

    linked = (ElfFile.load(str(ROOT / comparison_file))
              if manifest.get("linker_script") else compiled_source)
    passed = True
    for symbol in manifest["functions"]:
        function, address, compiled_func = function_selector(symbol)
        result = check.check_function(retail, linked, function, address=address,
                                      compiled_func=compiled_func)
        passed = result == 0 and passed
    if manifest.get("sections"):
        for section in manifest["sections"]:
            if isinstance(section, str):
                passed = check_section(retail, linked, section) and passed
            else:
                passed = check_section(retail, linked, section["name"], section["offset"]) and passed
    return passed


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    available = sorted(p.stem for p in (ROOT / "config/matches").glob("*.json"))
    parser.add_argument("units", nargs="*", help="configured unit names")
    parser.add_argument("--all", action="store_true", help="build every configured unit")
    parser.add_argument("--baselib", help="retail libsanangeles.so")
    parser.add_argument("--toolchain", type=Path,
                        default=os.environ.get("WCH_TOOLCHAIN_ROOT"))
    args = parser.parse_args(argv)
    names = available if args.all else args.units
    if not names:
        parser.error("select at least one unit or --all")
    unknown = set(names) - set(available)
    if unknown:
        parser.error("unknown unit(s): " + ", ".join(sorted(unknown)))

    try:
        base_library = find_base_library(args.baselib)
        if hashlib.sha256(base_library.read_bytes()).hexdigest() != BASE_LIB_SHA256:
            raise ValueError("retail SHA-256 differs from the repository target")
        passed = build_units(names, args.toolchain, base_library)
        return 0 if passed else 1
    except (OSError, ValueError, subprocess.CalledProcessError) as error:
        print(f"BUILD FAILED: {error}", file=sys.stderr)
        return 2


if __name__ == "__main__":
    raise SystemExit(main())
