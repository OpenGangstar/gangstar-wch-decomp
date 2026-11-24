"""The layout of the retail library: which source file every function came from.

The retail shared object was shipped with its symbol table intact, which gives
the project two independent signals about the original source tree.

**The file manifest.**  ``STT_FILE`` symbols are emitted once per object file.
The retail library lists 689 of them, so the complete list of source files
Gameloft compiled into the game is known exactly.

**Per-function attribution.**  Two signals are combined:

* *Scope.*  Most of the game's classes live in a file named after them
  (``Vehicle`` -> ``Vehicle.cpp``).  Where the scope names a file that exists
  in the manifest, the attribution is exact.
* *Anchors.*  A ``STT_FILE`` symbol is followed by the local symbols of its
  object file, and the linker lays the objects out contiguously in ``.text``.
  The address of a local symbol therefore marks a position inside a known
  object, and the closest anchor below a function identifies its object.

The two signals agree on 97% of the functions where both apply, which is what
makes the combination trustworthy.
"""

from __future__ import annotations

import bisect
import hashlib
from dataclasses import dataclass, field

from .elf import ElfFile

#: The source file name reported for functions whose object file could not be
#: identified.
UNKNOWN_SOURCE = "<unknown>"

#: Longest file name component that is portable across the filesystems people
#: use to check this repository out on.  Most common ones stop at 255 bytes.
MAX_FILENAME_LENGTH = 200

#: How much of a truncated name is kept before the hash is appended.
TRUNCATED_PREFIX_LENGTH = 150


def asm_filename(symbol: str, address: int | None = None, unique: bool = False) -> str:
    """The file name a function's assembly is stored under.

    The name is the mangled symbol, which keeps the mapping obvious.  Some
    symbols in this library are over 330 characters long, which exceeds the file
    name limit of most filesystems, so long names are truncated and a hash of
    the full symbol is appended.  The mapping stays deterministic.

    A handful of names -- the compiler generated ``__tcf_0`` helpers above all
    -- occur in more than one translation unit.  For those the address is
    appended so that every function keeps its own file.
    """
    if len(symbol) <= MAX_FILENAME_LENGTH:
        name = symbol
    else:
        digest = hashlib.sha256(symbol.encode("utf-8")).hexdigest()[:12]
        name = symbol[:TRUNCATED_PREFIX_LENGTH] + "_" + digest
    if unique and address is not None:
        name = f"{name}_{address:08x}"
    return name + ".s"


class AsmNaming:
    """Resolves the assembly file of every function in the library."""

    def __init__(self, elf: ElfFile) -> None:
        import collections

        counts = collections.Counter(f.name for f in elf.functions(".symtab"))
        self.duplicates = {name for name, count in counts.items() if count > 1}

    def filename(self, symbol: str, address: int) -> str:
        return asm_filename(symbol, address, symbol in self.duplicates)


def source_name(path: str | None) -> str:
    """The bare file name of a source path reported by the symbol table."""
    if not path:
        return UNKNOWN_SOURCE
    return path.replace("\\", "/").rsplit("/", 1)[-1]


def file_manifest(elf: ElfFile) -> list[str]:
    """Every source file name the retail library mentions, in link order."""
    names: list[str] = []
    seen = set()
    for symbol in elf.symbols:
        if symbol.table != ".symtab" or symbol.st_type != 4:
            continue
        name = source_name(symbol.name)
        if name not in seen:
            seen.add(name)
            names.append(name)
    return names


def _anchor_table(elf: ElfFile) -> tuple[list[int], list[str]]:
    """Addresses of local symbols and the object each one belongs to."""
    objects: list[str] = []
    owner_of_address: dict[int, int] = {}
    current = -1
    for symbol in elf.symbols:
        if symbol.table != ".symtab":
            continue
        if symbol.st_type == 4:
            current += 1
            objects.append(source_name(symbol.name))
            continue
        if symbol.st_bind == 0 and symbol.st_value:  # STB_LOCAL
            owner_of_address.setdefault(symbol.st_value, current)

    anchors = sorted(owner_of_address.items())
    addresses = [address for address, _ in anchors]
    owners = [objects[owner] for _, owner in anchors if owner >= 0 and owner < len(objects)]
    # ``owners`` and ``addresses`` must stay aligned; rebuild to be safe.
    aligned_addresses: list[int] = []
    aligned_owners: list[str] = []
    for address, owner in anchors:
        if 0 <= owner < len(objects):
            aligned_addresses.append(address)
            aligned_owners.append(objects[owner])
    return aligned_addresses, aligned_owners


def build_attribution(elf: ElfFile) -> dict[int, str]:
    """Map a function address to the source file it was compiled from."""
    manifest = set(file_manifest(elf))
    scope_hints = {name[:-4] for name in manifest if name.endswith(".cpp")}

    addresses, owners = _anchor_table(elf)

    attribution: dict[int, str] = {}
    for function in elf.functions(".symtab"):
        index = bisect.bisect_right(addresses, function.st_value) - 1
        owner = owners[index] if index >= 0 else None
        attribution[function.st_value] = owner or UNKNOWN_SOURCE

    # The scope of a member function usually names the file it lives in, and
    # that signal is exact where it applies, so it wins over the anchor.
    from .demangle import mangled_scope

    for function in elf.functions(".symtab"):
        scope, _ = mangled_scope(function.name)
        if scope and scope in scope_hints:
            attribution[function.st_value] = scope + ".cpp"

    # Empty IPhone/Win32 objects share the entry mapping symbol at 0x349314.
    # AnimObject owns FSelect's internal $d at 0x349330 and its module
    # initializer, _GLOBAL__I__Z7FSelectfff. The first boundary anchor alone
    # therefore attributes this leading function to the wrong object.
    for function in elf.functions(".symtab"):
        if (function.name == "_Z7FSelectfff" and function.st_value == 0x00349315
                and "AnimObject.cpp" in manifest):
            attribution[function.st_value] = "AnimObject.cpp"
    return attribution


@dataclass
class FileManifest:
    """The original source file manifest of the retail library."""

    #: Source file name -> the functions it contributed.
    functions: dict[str, list[str]] = field(default_factory=dict)
    #: Source file name -> the gameplay area it belongs to.
    areas: dict[str, str] = field(default_factory=dict)
    #: Every source file name the library mentions.
    files: list[str] = field(default_factory=list)


def build_object_origins(elf: ElfFile) -> dict[int, str]:
    """Refine the origin of every function using its object file.

    A single symbol is not always enough to tell engine code from game code:
    the static functions of an Irrlicht translation unit live at file scope and
    therefore carry no ``irr::`` prefix.  Whole object files, on the other
    hand, are never mixed, so the majority origin of an object is applied to
    every function it contains.
    """
    import collections

    from .provenance import classify

    attribution = build_attribution(elf)
    functions = elf.functions(".symtab")

    per_file: dict[str, list] = collections.defaultdict(list)
    for function in functions:
        per_file[attribution.get(function.st_value, UNKNOWN_SOURCE)].append(function)

    file_origin: dict[str, str] = {}
    for name, members in per_file.items():
        votes = collections.Counter(classify(f.name, name).origin for f in members)
        file_origin[name] = votes.most_common(1)[0][0]

    refined: dict[int, str] = {}
    for function in functions:
        owner = attribution.get(function.st_value, UNKNOWN_SOURCE)
        origin = classify(function.name, owner).origin
        if origin == "game" and file_origin.get(owner, "game") != "game":
            origin = file_origin[owner]
        refined[function.st_value] = origin
    return refined


def build_manifest(elf: ElfFile) -> FileManifest:
    """Build the source file manifest of *elf*."""
    from .provenance import area_for_file

    attribution = build_attribution(elf)
    manifest = FileManifest(files=file_manifest(elf))
    for symbol in elf.symbols:
        if symbol.table != ".symtab" or symbol.st_type != 4:
            continue
        name = source_name(symbol.name)
        manifest.functions.setdefault(name, [])
        manifest.areas.setdefault(name, area_for_file(name) or "core")
    for function in elf.functions(".symtab"):
        owner = attribution.get(function.st_value, UNKNOWN_SOURCE)
        manifest.functions.setdefault(owner, []).append(function.name)
        manifest.areas.setdefault(owner, area_for_file(owner) or "core")
    return manifest
