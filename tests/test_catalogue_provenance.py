"""Regression coverage for dependency provenance and retained pending markers."""

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


class GameswfBaseProvenanceTests(unittest.TestCase):
    CASES = (
        ("_ZN6logger21register_log_callbackEPFvNS_8log_typeEPKcE", "logger.cpp"),
        ("_ZN6logger25set_standard_log_handlersEv", "logger.cpp"),
        ("_ZN6logger5errorEPKcz", "logger.cpp"),
        ("_ZN6logger3msgEPKcz", "logger.cpp"),
        ("_ZN6logger4vmsgEPKcz", "logger.cpp"),
        ("_ZN6logger15standard_loggerENS_8log_typeEPKc", "logger.cpp"),
        ("_Z12reverse_scanPKcS0_c", "file_util.cpp"),
        ("_ZN9file_util13get_extensionEPKc", "file_util.cpp"),
    )

    def test_all_eight_proven_base_helpers(self):
        for symbol, source in self.CASES:
            with self.subTest(symbol=symbol):
                info = classify(symbol, source)
                self.assertEqual(info.origin, "gameswf")
                self.assertIsNone(info.area)

    def test_generic_names_and_near_filenames_stay_game(self):
        for symbol, source in (("_Z12reverse_scanPKcS0_c", None),
                               ("_ZN6logger5errorEPKcz", None),
                               ("helper", "logger.cpp.backup"),
                               ("helper", "mylogger.cpp"),
                               ("helper", "file_util.cpp.old"),
                               ("helper", "file_util.c"),
                               ("_Z15PVRTCDecompressPKviiiPh", "PVRTDecompress.cpp")):
            with self.subTest(symbol=symbol, source=source):
                self.assertEqual(classify(symbol, source).origin, "game")

    def test_reclassified_base_helpers_keep_original_markers_pending(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "core").mkdir()
            for symbol, source in self.CASES:
                (root / "core" / Naming().filename(symbol, 1)).touch()
            inventory = {normcase(path.name) for path in root.rglob("*.s")}
            for symbol, source in self.CASES:
                with self.subTest(symbol=symbol):
                    info = classify(symbol, source)
                    self.assertEqual(status_for(info.area, symbol, 1, root,
                                                Naming(), inventory), "pending")


class FreeTypePSNamesProvenanceTests(unittest.TestCase):
    PENDING = ("ps_unicode_value", "compare_uni_maps", "ps_unicodes_char_index",
               "ps_unicodes_char_next", "ps_get_macintosh_name",
               "ps_get_standard_strings", "ps_unicodes_init", "psnames_get_service")

    def test_all_eight_psnames_helpers_and_existing_helper(self):
        for symbol in self.PENDING + ("ft_get_adobe_glyph_index",):
            with self.subTest(symbol=symbol):
                info = classify(symbol, "psmodule.c")
                self.assertEqual(info.origin, "freetype")
                self.assertIsNone(info.area)
        self.assertEqual(classify("ft_get_adobe_glyph_index").origin, "freetype")

    def test_no_broad_ps_or_comparator_classification(self):
        for symbol, source in (("compare_uni_maps", None),
                               ("ps_unicode_value", None),
                               ("psnames_get_service", None),
                               ("helper", "psmodule.cpp"),
                               ("helper", "psmodule.c.old"),
                               ("helper", "mypsmodule.c")):
            with self.subTest(symbol=symbol, source=source):
                self.assertEqual(classify(symbol, source).origin, "game")

    def test_eight_pending_markers_and_existing_absent_marker(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            (root / "core").mkdir()
            for symbol in self.PENDING:
                (root / "core" / Naming().filename(symbol, 1)).touch()
            inventory = {normcase(path.name) for path in root.rglob("*.s")}
            for symbol in self.PENDING:
                info = classify(symbol, "psmodule.c")
                self.assertEqual(status_for(info.area, symbol, 1, root,
                                            Naming(), inventory), "pending")
            self.assertEqual(status_for(None, "ft_get_adobe_glyph_index", 1,
                                        root, Naming(), inventory), "matched")
