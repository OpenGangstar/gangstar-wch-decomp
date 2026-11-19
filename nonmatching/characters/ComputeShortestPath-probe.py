"""Compile the unapplied pathfinding candidate and stop before linking.

Run from a disposable repository root after applying ComputeShortestPath.patch.
Exit 3 deliberately means analysis only; this never grants matching credit.
"""

from pathlib import Path
import hashlib
import json
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT))
from tools import build, check
from tools.elf import ElfFile

TARGET = "_ZN16PhysicAttributes19ComputeShortestPathEiiN3irr4core8vector3dIfEES3_f"
CTOR = "_ZN10PhysicInfoC1Ev"
OBJECT = "build/matches/ai-startup-physicattributes/ai-startup-physicattributes.o"
original_run = build.run


class AnalysisFinished(Exception):
    pass


def run(command, environment):
    original_run(command, environment)
    if Path(command[0]).name != "arm-eabi-as.exe" or OBJECT not in command:
        return
    elf = ElfFile.load(str(ROOT / OBJECT))
    target = check.find_symbol(elf, TARGET)
    ctor = check.find_symbol(elf, CTOR)
    symbols = [symbol for symbol in elf.symbols if symbol.table == ".symtab"]
    references = []
    for section in elf.sections:
        if section.sh_type != 9 or section.sh_info != target.st_shndx:
            continue
        for offset in range(section.sh_offset, section.sh_offset + section.sh_size, 8):
            position, info = struct.unpack_from("<II", elf.data, offset)
            if symbols[info >> 8].name == CTOR:
                references.append({"offset": position, "type": info & 255})
    print(json.dumps({
        "size": target.st_size,
        "native_size": 1668,
        "section_size": elf.sections[target.st_shndx].sh_size,
        "raw_sha256": hashlib.sha256(check.symbol_bytes(elf, target)).hexdigest(),
        "ctor_size": ctor.st_size,
        "ctor_binding": ctor.st_info >> 4,
        "ctor_references": references,
        "linked": False,
    }, indent=2), flush=True)
    raise AnalysisFinished("Prelink analysis only; no linked comparison claimed.")


if __name__ == "__main__":
    if sys.platform != "win32":
        raise SystemExit("This prelink probe requires the original Windows ARM SDK workflow.")
    build.run = run
    try:
        result = build.main([*sys.argv[1:], "ai-startup-physicattributes"])
    except AnalysisFinished as error:
        print(error)
        result = 3
    raise SystemExit(result)
