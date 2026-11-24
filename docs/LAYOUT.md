# The layout of the original build

The retail library records the name of every translation unit it compiled, in
link order, in its `STT_FILE` symbols. `config/files.tsv` is that list.

**689 source files.** 181 are classified as game objects; other entries
include the engine, its dependencies and empty platform objects. Game helpers
also occur in mixed-origin objects. The [provenance ledger](PROVENANCE-CORRECTIONS.md)
accounts for the two corrected FreeType objects without removing any original
function or assembly marker.

`src/game/` reproduces the game's own layout one for one, so that a function
that was compiled from `Vehicle.cpp` is decompiled in
`src/game/vehicles/Vehicle.cpp`.

## How a function is attributed to a file

Two independent signals, combined:

* **Scope.** Most of the game's classes live in a file named after them.
  `Vehicle` → `Vehicle.cpp`, `Menus` → `Menus.cpp`. Where the scope of a
  mangled name names a file that exists in the manifest, the attribution is
  exact.
* **Anchors.** A `STT_FILE` symbol is followed by the local symbols of its
  object file, and the linker lays the objects out contiguously in `.text`.
  The address of a local symbol therefore marks a position inside a known
  object, and the closest anchor below a function identifies its object.

Where both apply they agree on **97.2%** of the functions, which is what
makes the combination trustworthy. `tools/layout.py` implements it.

One caveat worth knowing: the retail build stripped the `STT_FILE` symbols of
the Irrlicht objects, so they inherit the name of the object that precedes
them. That is why a number of Irrlicht translation units are attributed to
`lib1funcs.asm`. It does not affect the game code.

## The gameplay areas

The 181 files classified as game objects fall into sixteen areas. The areas are how the project is
organised, how the assembly is filed and how the progress is reported.

| Area | Functions | What it holds |
| --- | ---: | --- |
| `ui` | 807 | The menu system, its widgets, the individual game menus |
| `core` | 261 | Shared helpers, containers, threading, cameras, logging |
| `rendering` | 366 | Render effects, billboards, sky boxes, LOD, sprites |
| `ai` | 313 | NPC and police behaviour, the behaviour model, state machines, the player test harness |
| `vehicles` | 307 | Vehicles, their sounds, their wheels |
| `world` | 289 | Level objects, spawn points, scene nodes, paths, streaming |
| `missions` | 283 | Main and side missions, checkpoints, rewards, the wanted level |
| `audio` | 281 | The sound manager, the ADPCM and Wav decoders, streaming, the radio |
| `persistence` | 259 | Save games, preferences, file systems, data streams |
| `hud` | 232 | The HUD manager, the minimap, gauges and markers |
| `characters` | 232 | The character model, its animation, its physical attributes |
| `input` | 229 | Touch screen, accelerometer, analogue stick, control handlers |
| `app` | 222 | The application object, loading screen, screen fades, the JNI layer |
| `scripting` | 194 | The scripting runtime, the script manager, the event system |
| `combat` | 145 | Weapons, projectiles, damage feedback |
| `meta` | 130 | Achievements, items, races, factions |

## The file manifest

`config/files.tsv` has one row per file:

```
source_file  origin  area  functions
```

`origin` is `game` or the key of a vendored library. `functions` is how many
functions of the retail library are attributed to that file.

## The function catalogue

`config/functions.tsv` has one row per function of the retail library:

```
address  size  source_file  origin  area  status  symbol  demangled
```

`status` is `pending` when the function still has an assembly file under
`asm/`, and `matched` when it does not. The status is derived, never edited
by hand.

## The assembly

`asm/<area>/<symbol>.s` holds the disassembly of one function. The file name
is the mangled symbol, which makes it easy to find and to relate to the
catalogue.

Two kinds of names need care:

* A handful of names — the compiler generated `__tcf_0` helpers above all —
  occur in more than one translation unit. For those the address is appended
  to the file name so that every function keeps its own file.
* Some symbols are over 330 characters long, which is beyond the file name
  limit of most file systems. Those are truncated and a hash of the full name
  is appended. The mapping stays deterministic.

## The symbol map

`config/symbols.tsv` is the full symbol map: every defined symbol in the
retail library with its address, size, section, origin, area and demangled
name. 70,867 rows. It is the reference for anything the catalogue does not
cover.
