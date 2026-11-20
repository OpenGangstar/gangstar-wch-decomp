"""Compile-only diagnostic for the unapplied SDK-reuse data-reloader candidate.

Always exits 3 after successful assembly: no link or native-match acceptance.
"""
from pathlib import Path
import argparse
import hashlib
import json
import os
import sys

SCRIPT_ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(SCRIPT_ROOT))
from tools import build, check
from tools.elf import ElfFile

NAME = "_ZNK19DataReloaderManager10checkFilesEv"
PROFILE = "sdk-startup-datareloadermanager"


class ProbeFinished(Exception):
    pass


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--repo", type=Path, default=SCRIPT_ROOT)
    parser.add_argument("--toolchain", type=Path)
    parser.add_argument("--baselib", type=Path, required=True)
    args = parser.parse_args()
    repo = args.repo.resolve()
    manifest = json.loads((repo / "config/matches/sdk-startup-datareloadermanager.json").read_text())
    original_root, original_run = build.ROOT, build.run
    obj = "build/matches/sdk-startup-datareloadermanager/sdk-startup-datareloadermanager.o"
    if os.name == "nt":
        os.environ["PATH"] = str(SCRIPT_ROOT / "toolchain/cygwin32/bin") + os.pathsep + os.environ["PATH"]

    def run(command, environment):
        original_run(command, environment)
        if obj not in [str(part) for part in command]:
            return
        compiler = ElfFile.load(str(repo / obj))
        retail = ElfFile.load(str(args.baselib.resolve()))
        symbol = check.find_symbol(compiler, NAME)
        native = check.find_symbol(retail, NAME)
        if symbol is None or native is None:
            raise RuntimeError("The expected compiled and native function definitions are required")
        result = {
            "symbol": NAME,
            "native_address": hex(native.st_value),
            "native_size": native.st_size,
            "compiled_size": symbol.st_size,
            "input_section_size": compiler.sections[symbol.st_shndx].sh_size,
            "raw_sha256": hashlib.sha256(check.symbol_bytes(compiler, symbol)).hexdigest(),
            "native_extent_matches": symbol.st_size == native.st_size,
            "linked": False,
            "native_bytes_compared": False,
            "old_match_closure_checked": False,
            "credited": False,
        }
        (repo / "build/matches/sdk-startup-datareloadermanager/sdk-reuse-probe.json").write_text(
            json.dumps(result, indent=2) + "\n", encoding="utf-8")
        print(json.dumps(result), flush=True)
        print("COMPILE-ONLY: no native byte comparison or old-match proof.", flush=True)
        raise ProbeFinished()

    build.ROOT, build.run = repo, run
    try:
        build._build_unit(PROFILE, args.toolchain, args.baselib.resolve(), manifest)
    except ProbeFinished:
        return 3
    finally:
        build.ROOT, build.run = original_root, original_run
    raise RuntimeError("Probe failed to stop after primary-object assembly")


if __name__ == "__main__":
    raise SystemExit(main())
