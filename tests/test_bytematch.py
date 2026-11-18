import unittest

from tools.bytematch import report
from tools.progress import collect
from tools.project import read_tsv, repo_path


class ByteMatchTests(unittest.TestCase):
    def test_catalogue_totals_match_progress(self):
        path = repo_path("config/functions.tsv")
        result = report(read_tsv(path))
        progress = collect(path)
        m = result["measures"]
        self.assertEqual(m["total_code"], progress["total_bytes"])
        self.assertEqual(m["matched_code"], progress["done_bytes"])
        self.assertEqual(m["matched_functions"], progress["done_functions"])
        self.assertEqual(m["total_functions"], progress["functions"])
        self.assertEqual(sum(u["measures"]["total_code"] for u in result["units"]), m["total_code"])
        self.assertEqual(sum(u["measures"]["matched_code"] for u in result["units"]), m["matched_code"])

    def test_aliases_vendor_and_pending(self):
        def row(symbol, status, origin="game"):
            return dict(symbol=symbol, status=status, origin=origin, area="combat",
                        source_file="Weapon.cpp", size="0x10", address="0x330665",
                        demangled=symbol)
        result = report([row("ctor1", "matched"), row("ctor2", "matched"),
                         row("pending", "asm"), row("vendor", "matched", "irrlicht")])
        m = result["measures"]
        self.assertEqual((m["matched_code"], m["total_code"]), (32, 48))
        self.assertEqual((m["matched_functions"], m["total_functions"]), (2, 3))
        self.assertEqual(m["complete_code"], 0)
        self.assertEqual(m["complete_units"], 0)
        self.assertEqual(m["total_data"], 0)
        unit = result["units"][0]
        self.assertFalse(unit["metadata"]["complete"])
        self.assertEqual(unit["metadata"]["source_path"], "src/game/combat/Weapon.cpp")
        self.assertEqual([f["fuzzy_match_percent"] for f in unit["functions"]], [100, 100, 0])

    def test_empty_catalogue_fails(self):
        with self.assertRaises(ValueError):
            report([])

    @staticmethod
    def row(symbol, source, area, status, size=16, origin="game"):
        return dict(symbol=symbol, status=status, origin=origin, area=area,
                    source_file=source, size=hex(size), address="0x330665",
                    demangled=symbol)

    def test_linked_code_sums_finished_units_not_all_matched_functions(self):
        rows = [self.row("done", "Done.cpp", "combat", "matched", 20),
                self.row("half", "Partial.cpp", "combat", "matched", 30),
                self.row("todo", "Partial.cpp", "combat", "pending", 50)]
        result = report(rows)
        m = result["measures"]
        self.assertEqual((m["matched_code"], m["complete_code"], m["total_code"]),
                         (50, 20, 100))
        self.assertEqual(m["fuzzy_match_percent"], 50)
        self.assertEqual(m["matched_code_percent"], 50)
        self.assertEqual(m["complete_code_percent"], 20)
        self.assertEqual((m["complete_units"], m["total_units"]), (1, 2))
        units = {u["name"]: u for u in result["units"]}
        self.assertTrue(units["game/combat/Done"]["metadata"]["complete"])
        self.assertFalse(units["game/combat/Partial"]["metadata"]["complete"])
        for category in result["categories"]:
            self.assertEqual(category["measures"]["complete_code"], 20)
            self.assertEqual(category["measures"]["complete_units"], 1)

    def test_source_fragment_cannot_hide_unfinished_code_in_another_area(self):
        rows = [self.row("startup", "Shared.cpp", "core", "matched", 10),
                self.row("main", "Shared.cpp", "combat", "pending", 90)]
        result = report(rows)
        self.assertEqual(result["measures"]["matched_code"], 10)
        self.assertEqual(result["measures"]["complete_code"], 0)
        self.assertTrue(all(not u["metadata"]["complete"] for u in result["units"]))
        rows[1]["status"] = "matched"
        finished = report(rows)
        self.assertEqual(finished["measures"]["complete_code"], 100)
        self.assertEqual(finished["measures"]["complete_units"], 2)
        for unit in finished["units"]:
            self.assertTrue(unit["metadata"]["complete"])
            self.assertEqual(unit["measures"]["complete_code_percent"], 100)

    def test_pending_zero_size_function_still_blocks_completion(self):
        result = report([self.row("done", "Test.cpp", "core", "matched"),
                         self.row("todo", "Test.cpp", "core", "pending", 0)])
        self.assertEqual(result["measures"]["matched_code_percent"], 100)
        self.assertEqual(result["measures"]["complete_code"], 0)
        self.assertFalse(result["units"][0]["metadata"]["complete"])

    def test_vendor_does_not_block_game_unit_and_alias_accounting_is_preserved(self):
        result = report([self.row("C1", "Test.cpp", "core", "matched"),
                         self.row("C2", "Test.cpp", "core", "matched"),
                         self.row("vendor", "Test.cpp", "core", "pending",
                                  origin="irrlicht")])
        self.assertEqual(result["measures"]["complete_code"], 32)
        self.assertEqual(result["measures"]["total_functions"], 2)
        self.assertEqual(result["measures"]["complete_units"], 1)
        self.assertEqual(result["measures"]["complete_data"], 0)

    def test_real_catalogue_rollups_and_all_or_nothing_completion(self):
        rows = [r for r in read_tsv(repo_path("config/functions.tsv")) if r["origin"] == "game"]
        complete_sources = {r["source_file"] for r in rows
                            if all(f["status"] == "matched" for f in rows
                                   if f["source_file"] == r["source_file"])}
        result = report(rows)
        expected = sum(int(r["size"], 16) for r in rows if r["source_file"] in complete_sources)
        self.assertEqual(result["measures"]["complete_code"], expected)
        for unit in result["units"]:
            self.assertLessEqual(unit["measures"]["complete_code"], unit["measures"]["matched_code"])
        for category in result["categories"]:
            members = [u for u in result["units"]
                       if category["id"] in u["metadata"]["progress_categories"]]
            self.assertEqual(category["measures"]["complete_code"],
                             sum(u["measures"]["complete_code"] for u in members))
            self.assertEqual(category["measures"]["complete_units"],
                             sum(u["measures"]["complete_units"] for u in members))
