"""Regression coverage for FreeType provenance and retained pending markers."""

import tempfile
import unittest
from pathlib import Path
from os.path import normcase

from tools.catalogue import status_for
from tools.layout import asm_filename
from tools.provenance import classify


class Naming:
    def filename(self, symbol, address):
        return asm_filename(symbol, address, False)


class FreeTypeCacheProvenanceTests(unittest.TestCase):
    def test_cache_prefixes_without_file_attribution(self):
        for name in ("FTC_MruNode_Prepend", "ftc_cache_resize"):
            with self.subTest(name=name):
                info = classify(name)
                self.assertEqual(info.origin, "freetype")
                self.assertIsNone(info.area)

    def test_umbrella_files_cover_static_helpers(self):
        for name, source in (("cache_static_helper", "ftcache.c"),
                             ("parse_font_matrix", "type1cid.c")):
            with self.subTest(source=source):
                self.assertEqual(classify(name, source).origin, "freetype")

    def test_no_broad_prefix_or_filename_match(self):
        for name, source in (("parse_font_matrix", None),
                             ("cache_static_helper", "ftcache.cpp"),
                             ("parse_font_matrix", "type1cid.cpp"),
                             ("FTCWidget", "Widget.cpp"),
                             ("ftcache_helper", "Cache.cpp"),
                             ("_ZN7Vehicle11getSkinMeshEv", "Vehicle.cpp")):
            with self.subTest(name=name, source=source):
                self.assertEqual(classify(name, source).origin, "game")


class PendingMarkerTests(unittest.TestCase):
    def test_vendor_reclassification_retains_existing_area_marker(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "core").mkdir()
            (root / "core/FTC_MruNode_Prepend.s").touch()
            self.assertEqual(status_for(None, "FTC_MruNode_Prepend", 1,
                                        root, Naming()), "pending")
            inventory = {normcase(path.name) for path in root.rglob("*.s")}
            self.assertEqual(status_for(None, "FTC_MruNode_Prepend", 1,
                                        root, Naming(), inventory), "pending")
            self.assertEqual(status_for(None, "FT_NoMarker", 3,
                                        root, Naming(), inventory), "matched")

    def test_game_status_still_uses_its_assigned_area(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "core").mkdir()
            (root / "core/Example.s").touch()
            inventory = {normcase("Example.s")}
            self.assertEqual(status_for("core", "Example", 1,
                                        root, Naming(), inventory), "pending")
            self.assertEqual(status_for("ui", "Example", 1,
                                        root, Naming(), inventory), "matched")

    def test_vendor_fallback_uses_duplicate_address_aware_filename(self):
        class DuplicateNaming:
            def filename(self, symbol, address):
                return asm_filename(symbol, address, True)
        inventory = {normcase(asm_filename("helper", 0x101, True))}
        self.assertEqual(status_for(None, "helper", 0x101, Path("unused"),
                                    DuplicateNaming(), inventory), "pending")
        self.assertEqual(status_for(None, "helper", 0x201, Path("unused"),
                                    DuplicateNaming(), inventory), "matched")

    def test_vendor_inventory_preserves_filesystem_case_rules(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "core").mkdir()
            (root / "core/ftc_gnode_compare.s").touch()
            expected = ("pending" if (root / "core/FTC_GNode_Compare.s").exists()
                        else "matched")
            inventory = {normcase(path.name) for path in root.rglob("*.s")}
            self.assertEqual(status_for(None, "FTC_GNode_Compare", 1,
                                        root, Naming(), inventory), expected)
