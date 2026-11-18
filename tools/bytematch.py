"""Export verified catalogue progress in objdiff's version-2 report format.

This is an adapter for our linked byte checker, not an objdiff build. CI needs
only the public catalogue. Unmatched functions have no partial-match credit;
data measures remain zero until data coverage is tracked. Complete/link code
measures sum finished source units, independently of whole-library completion.
"""

from __future__ import annotations

if __package__ in (None, ""):
    import sys
    from pathlib import Path
    sys.path.insert(0, str(Path(__file__).resolve().parent.parent))
    __package__ = "tools"

import argparse
import json
from collections import defaultdict
from pathlib import Path

from .project import read_tsv, repo_path


def measures(rows: list[dict], units: int, *, complete_code: int = 0,
             complete_units: int = 0) -> dict:
    total = sum(int(r["size"], 16) for r in rows)
    matched = [r for r in rows if r["status"] == "matched"]
    done = sum(int(r["size"], 16) for r in matched)
    percent = 100 * done / total if total else 0
    return {
        "fuzzy_match_percent": percent,
        "total_code": total, "matched_code": done,
        "matched_code_percent": percent,
        "total_data": 0, "matched_data": 0, "matched_data_percent": 0,
        "total_functions": len(rows), "matched_functions": len(matched),
        "matched_functions_percent": 100 * len(matched) / len(rows) if rows else 0,
        "complete_code": complete_code,
        "complete_code_percent": 100 * complete_code / total if total else 0,
        "complete_data": 0, "complete_data_percent": 0,
        "total_units": units, "complete_units": complete_units,
    }


def report(rows: list[dict]) -> dict:
    game = [r for r in rows if r["origin"] == "game"]
    if not game:
        raise ValueError("catalogue has no game functions")
    groups = defaultdict(list)
    sources = defaultdict(list)
    for row in game:
        groups[(row["area"], row["source_file"])].append(row)
        sources[row["source_file"]].append(row)
    # An original source can have startup helpers attributed to another area.
    # Keep existing viewer unit names, but never finish a fragment while any
    # function from that same source remains pending elsewhere in the report.
    complete_sources = {source for source, functions in sources.items()
                        if all(r["status"] == "matched" for r in functions)}
    units = []
    for (area, source), functions in sorted(groups.items()):
        source_path = f"src/game/{area}/{source}"
        complete = source in complete_sources
        code = sum(int(r["size"], 16) for r in functions)
        units.append({
            "name": f"game/{area}/{Path(source).stem}",
            "measures": measures(functions, 1, complete_code=code if complete else 0,
                                 complete_units=int(complete)),
            "sections": [],
            "functions": [{
                "name": r["symbol"], "size": int(r["size"], 16),
                "fuzzy_match_percent": 100 if r["status"] == "matched" else 0,
                "metadata": {"demangled_name": r["demangled"],
                             "virtual_address": int(r["address"], 16)},
            } for r in sorted(functions, key=lambda r: (int(r["address"], 16), r["symbol"]))],
            "metadata": {"complete": complete, "source_path": source_path,
                         "progress_categories": ["game", area]},
        })
    def aggregate(functions: list[dict], members: list[dict]) -> dict:
        return measures(functions, len(members),
                        complete_code=sum(u["measures"]["complete_code"] for u in members),
                        complete_units=sum(u["measures"]["complete_units"] for u in members))

    categories = [{"id": "game", "name": "Game code", "measures": aggregate(game, units)}]
    for area in sorted({r["area"] for r in game}):
        subset = [r for r in game if r["area"] == area]
        categories.append({"id": area, "name": area,
                           "measures": aggregate(subset, [u for u in units
                                                          if area in u["metadata"]["progress_categories"]])})
    return {"version": 2, "measures": aggregate(game, units),
            "units": units, "categories": categories}


def main() -> int:
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("--functions", type=Path, default=repo_path("config/functions.tsv"))
    parser.add_argument("-o", "--output", type=Path, default=repo_path("build/android-arm/report.json"))
    args = parser.parse_args()
    result = report(read_tsv(args.functions))
    args.output.parent.mkdir(parents=True, exist_ok=True)
    args.output.write_text(json.dumps(result, indent=2) + "\n", encoding="utf-8")
    m = result["measures"]
    print(f"ByteMatch: {m['matched_functions']}/{m['total_functions']} functions; "
          f"{m['matched_code']}/{m['total_code']} bytes ({m['matched_code_percent']:.2f}%); "
          f"Fully Linked {m['complete_code']}/{m['total_code']} bytes "
          f"({m['complete_code_percent']:.2f}%, {m['complete_units']}/{m['total_units']} units); "
          f"Fuzzy Matched {m['fuzzy_match_percent']:.2f}%")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
