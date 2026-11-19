"""Generate the project's tables from the retail library.

Two tables are produced:

``config/functions.tsv``
    The function catalogue: one row per function in the retail library, with
    its address, size, original source file, origin, gameplay area, status and
    demangled name.  This is the project's work queue.

``config/files.tsv``
    The original source file manifest: every file the retail build compiled,
    with the number of functions attributed to it.

Status is derived from the presence of a matching file under ``asm/``: a
function that still has an ``asm/<area>/<symbol>.s`` file has not been
decompiled yet.
"""

from __future__ import annotations

if __package__ in (None, ""):  # allow "python tools/catalogue.py.py" as well
    import pathlib
    import sys

    sys.path.insert(0, str(pathlib.Path(__file__).resolve().parent.parent))
    __package__ = "tools"

import argparse
from pathlib import Path
from os.path import normcase

from .demangle import demangle_many
from .elf import ElfFile
from .layout import AsmNaming, build_attribution, build_object_origins, file_manifest, source_name
from .project import load_base_library, repo_path, write_tsv
from .provenance import classify

FUNCTION_HEADER = [
    "address",
    "size",
    "source_file",
    "origin",
    "area",
    "status",
    "symbol",
    "demangled",
]

FILE_HEADER = [
    "source_file",
    "origin",
    "area",
    "functions",
]


def status_for(area: str | None, symbol: str, address: int, asm_root: Path, naming,
               pending_filenames: set[str] | None = None) -> str:
    """``matched``/``pending`` depending on whether the asm file is gone."""
    filename = naming.filename(symbol, address)
    if area is None:
        # A corrected vendor origin can still have a pending marker in its old
        # gameplay area. Preserve that status without moving assembly files,
        # including case-insensitive matches on the host filesystem.
        if pending_filenames is None:
            pending_filenames = {normcase(path.name) for path in asm_root.rglob("*.s")}
        return "pending" if normcase(filename) in pending_filenames else "matched"
    area_dir = asm_root / area
    if (area_dir / filename).exists():
        return "pending"
    return "matched"


def build_function_rows(elf: ElfFile, asm_root: Path) -> list[list[object]]:
    attribution = build_attribution(elf)
    origins = build_object_origins(elf)
    naming = AsmNaming(elf)
    pending_filenames = {normcase(path.name) for path in asm_root.rglob("*.s")}
    functions = elf.functions(".symtab")
    demangled = demangle_many([f.name for f in functions if f.name.startswith("_Z")])

    rows: list[list[object]] = []
    for function in functions:
        owner = source_name(attribution.get(function.st_value))
        info = classify(function.name, owner)
        origin = origins.get(function.st_value, info.origin)
        if origin != "game":
            info.area = None
        rows.append(
            [
                f"0x{function.st_value:08x}",
                f"0x{function.st_size:x}",
                owner,
                origin,
                info.area or "-",
                status_for(info.area, function.name, function.st_value, asm_root, naming,
                           pending_filenames),
                function.name,
                demangled.get(function.name, function.name),
            ]
        )
    return rows


def build_file_rows(elf: ElfFile) -> list[list[object]]:
    attribution = build_attribution(elf)
    origins = build_object_origins(elf)
    manifest = file_manifest(elf)

    counts: dict[str, int] = {}
    file_origin: dict[str, str] = {}
    file_area: dict[str, str] = {}
    for function in elf.functions(".symtab"):
        owner = source_name(attribution.get(function.st_value))
        counts[owner] = counts.get(owner, 0) + 1
        if owner not in file_origin:
            info = classify(function.name, owner)
            file_origin[owner] = origins.get(function.st_value, info.origin)
            file_area[owner] = (info.area or "-") if file_origin[owner] == "game" else "-"

    rows: list[list[object]] = []
    for name in manifest:
        rows.append(
            [
                name,
                file_origin.get(name, "-"),
                file_area.get(name, "-"),
                counts.get(name, 0),
            ]
        )
    return rows


def main(argv: list[str] | None = None) -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--baselib", help="path to the retail libsanangeles.so")
    parser.add_argument(
        "--output",
        type=Path,
        default=repo_path("config", "functions.tsv"),
        help="where to write the function catalogue",
    )
    parser.add_argument(
        "--files-output",
        type=Path,
        default=repo_path("config", "files.tsv"),
        help="where to write the source file manifest",
    )
    parser.add_argument(
        "--asm-root",
        type=Path,
        default=repo_path("asm"),
        help="the directory holding the pending assembly",
    )
    args = parser.parse_args(argv)

    elf, _ = load_base_library(args.baselib)

    functions = build_function_rows(elf, args.asm_root)
    write_tsv(args.output, FUNCTION_HEADER, functions)
    print(f"wrote {args.output} ({len(functions)} functions)")

    files = build_file_rows(elf)
    write_tsv(args.files_output, FILE_HEADER, files)
    print(f"wrote {args.files_output} ({len(files)} source files)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
