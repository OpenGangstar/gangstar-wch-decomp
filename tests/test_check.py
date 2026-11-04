"""Regression checks for ARM symbol extraction and relocation boundaries."""

import struct
import argparse
import unittest
from contextlib import redirect_stderr, redirect_stdout
import io
from pathlib import Path
from unittest.mock import patch
from types import SimpleNamespace

from tools.check import check_function, main, relocations_for, select_function, symbol_bytes
from tools.elf import EM_ARM, EM_386, ET_EXEC, ElfFile, Section, STT_FUNC, STT_OBJECT, Symbol


class ObjectComparisonTests(unittest.TestCase):
    def fixture(self, machine=EM_ARM, value=1, kind=STT_FUNC):
        # The function is followed by padding that must never enter its bytes.
        text = b"\x01\x20\x70\x47\xaa\xbb"
        symbol = Symbol("probe", value, 4, kind, 0, 1)
        elf = ElfFile("synthetic.o", text, e_machine=machine)
        elf.sections = [
            SimpleNamespace(sh_type=0),
            SimpleNamespace(sh_type=1, sh_offset=0, sh_addr=0),
        ]
        elf.symbols = [symbol]
        return elf, symbol

    def test_thumb_marker_is_not_a_byte_offset(self):
        elf, symbol = self.fixture()
        self.assertEqual(symbol_bytes(elf, symbol), b"\x01\x20\x70\x47")

    def test_arm_function_keeps_aligned_offset(self):
        elf, symbol = self.fixture(value=0)
        self.assertEqual(symbol_bytes(elf, symbol), b"\x01\x20\x70\x47")

    def test_odd_data_symbol_is_not_thumb(self):
        elf, symbol = self.fixture(kind=STT_OBJECT)
        self.assertEqual(symbol_bytes(elf, symbol), b"\x20\x70\x47\xaa")

    def test_non_arm_odd_offset_is_preserved(self):
        elf, symbol = self.fixture(machine=EM_386)
        self.assertEqual(symbol_bytes(elf, symbol), b"\x20\x70\x47\xaa")

    def test_thumb_relocations_at_start_and_end(self):
        elf, _ = self.fixture()
        # Offset zero touches the function; offset four belongs to its neighbour.
        elf.data += struct.pack("<IIII", 0, 2, 4, 2)
        elf.sections.append(SimpleNamespace(
            sh_type=9, sh_info=1, sh_entsize=8, sh_size=16, sh_offset=6,
        ))
        self.assertEqual(relocations_for(elf, "probe"), ["0x0"])

    def test_linked_thumb_symbol_uses_section_virtual_address(self):
        elf, symbol = self.fixture(value=0x8001)
        elf.e_type = ET_EXEC
        elf.sections[1].sh_addr = 0x8000
        self.assertEqual(symbol_bytes(elf, symbol), b"\x01\x20\x70\x47")

    def test_linked_relocation_offsets_are_virtual_addresses(self):
        elf, _ = self.fixture(value=0x8001)
        elf.e_type = ET_EXEC
        elf.sections[1].sh_addr = 0x8000
        elf.data += struct.pack("<IIII", 0x8000, 2, 0x8004, 2)
        elf.sections.append(SimpleNamespace(
            sh_type=9, sh_info=1, sh_entsize=8, sh_size=16, sh_offset=6,
        ))
        self.assertEqual(relocations_for(elf, "probe"), ["0x8000"])

    def test_relocations_use_the_selected_duplicate(self):
        elf, first = self.fixture(value=0x8001)
        elf.e_type = ET_EXEC
        elf.sections[1].sh_addr = 0x8000
        second = Symbol("probe", 0x8005, 4, STT_FUNC, 0, 1)
        elf.symbols.append(second)
        elf.data += struct.pack("<II", 0x8004, 2)
        elf.sections.append(SimpleNamespace(
            sh_type=9, sh_info=1, sh_entsize=8, sh_size=8, sh_offset=6,
        ))
        self.assertEqual(relocations_for(elf, "probe", symbol=first), [])
        self.assertEqual(relocations_for(elf, "probe", symbol=second), ["0x8004"])
        with self.assertRaisesRegex(ValueError, "ambiguous function"):
            relocations_for(elf, "probe")


class DuplicateFunctionTests(unittest.TestCase):
    def image(self):
        data = b"\x01\x20\x70\x47\x02\x20\x70\x47"
        return ElfFile("synthetic.elf", data, e_type=ET_EXEC, e_machine=EM_ARM,
                       sections=[Section(0, "", 0, 0, 0, 0, 0, 0, 0, 1, 0),
                                 Section(1, ".text", 1, 6, 0x8000, 0, 8, 0, 0, 2, 0)],
                       symbols=[Symbol("__tcf_3", 0x8001, 4, STT_FUNC, 0, 1),
                                Symbol("__tcf_3", 0x8005, 4, STT_FUNC, 0, 1)])

    def invoke(self, image, *arguments):
        stdout, stderr = io.StringIO(), io.StringIO()
        with patch("tools.check.load_base_library", return_value=(self.image(), Path("retail.so"))), \
             patch("tools.check.ElfFile.load", return_value=image), \
             patch("tools.check.Path.exists", return_value=True), \
             redirect_stdout(stdout), redirect_stderr(stderr):
            code = main(["synthetic.elf", "--func", "__tcf_3", *arguments])
        # Run every success/failure fixture through the loaded-image entry too.
        # The file loader must remain a CLI responsibility, with identical
        # diagnostics and verification after loading.
        parser = argparse.ArgumentParser()
        parser.add_argument("--func", default="__tcf_3")
        parser.add_argument("--address", type=lambda value: int(value, 0))
        parser.add_argument("--compiled-func")
        args = parser.parse_args(arguments)
        loaded_stdout, loaded_stderr = io.StringIO(), io.StringIO()
        with patch("tools.check.load_base_library") as retail_load, \
             patch("tools.check.ElfFile.load") as image_load, \
             redirect_stdout(loaded_stdout), redirect_stderr(loaded_stderr):
            loaded_code = check_function(self.image(), image, args.func,
                                         address=args.address,
                                         compiled_func=args.compiled_func)
        retail_load.assert_not_called()
        image_load.assert_not_called()
        self.assertEqual((loaded_code, loaded_stdout.getvalue(), loaded_stderr.getvalue()),
                         (code, stdout.getvalue(), stderr.getvalue()))
        return code, stdout.getvalue(), stderr.getvalue()

    def test_machine_and_file_type_checks_have_loaded_cli_parity(self):
        for machine, kind in ((EM_386, ET_EXEC), (EM_ARM, 0)):
            image = self.image()
            image.e_machine, image.e_type = machine, kind
            with self.subTest(machine=machine, kind=kind):
                code, stdout, stderr = self.invoke(image, "--address", "0x8001")
                self.assertEqual((code, stdout), (2, ""))
                self.assertIn("expected an ARM relocatable object or linked image", stderr)

    def test_cli_rejects_missing_object_before_loading_or_comparing(self):
        with patch("tools.check.Path.exists", return_value=False), \
             patch("tools.check.load_base_library") as retail_load, \
             patch("tools.check.ElfFile.load") as image_load, \
             patch("tools.check.check_function") as compare, \
             redirect_stderr(io.StringIO()) as stderr:
            self.assertEqual(main(["missing.o", "--func", "probe"]), 2)
        self.assertEqual(stderr.getvalue(), "missing.o does not exist\n")
        retail_load.assert_not_called()
        image_load.assert_not_called()
        compare.assert_not_called()

    def test_ambiguous_retail_name_is_rejected(self):
        code, stdout, stderr = self.invoke(self.image())
        self.assertEqual(code, 2)
        self.assertEqual(stdout, "")
        self.assertIn("ambiguous function __tcf_3", stderr)
        self.assertIn("--address", stderr)

    def test_address_selects_matching_duplicate_in_both_images(self):
        code, stdout, stderr = self.invoke(self.image(), "--address", "0x8005")
        self.assertEqual((code, stderr), (0, ""))
        self.assertEqual(stdout, "OK  __tcf_3  0x00008005  4 bytes\n")

    def test_matching_first_copy_cannot_hide_wrong_selected_bytes(self):
        image = self.image()
        image.data = image.data[:4] + b"\x03\x20\x70\x47"
        code, stdout, stderr = self.invoke(image, "--address", "0x8005")
        self.assertEqual(code, 1)
        self.assertEqual(stdout, "")
        self.assertIn("MISMATCH  __tcf_3  0x00008005", stderr)

    def test_thumb_marker_must_be_explicit(self):
        code, _, stderr = self.invoke(self.image(), "--address", "0x8004")
        self.assertEqual(code, 2)
        self.assertIn("0x00008004 is not in the retail library", stderr)

    def test_single_misplaced_definition_is_rejected(self):
        image = self.image()
        image.symbols = [image.symbols[0]]
        code, _, stderr = self.invoke(image, "--address", "0x8005")
        self.assertEqual(code, 1)
        self.assertIn("linked at 0x00008001; expected 0x00008005", stderr)

    def test_same_definition_repeated_is_not_ambiguous(self):
        image = self.image()
        image.symbols = [image.symbols[0], image.symbols[0]]
        self.assertEqual(select_function(image, "__tcf_3").st_value, 0x8001)

    def test_imports_and_absolute_bindings_are_not_definitions(self):
        image = self.image()
        for section in (0, 0xfff1):
            with self.subTest(section=section):
                image.symbols = [Symbol("__tcf_3", 0x8005, 4, STT_FUNC, 0, section)]
                code, _, stderr = self.invoke(image, "--address", "0x8005")
                self.assertEqual(code, 2)
                self.assertIn("is not in synthetic.elf", stderr)


class RenumberedCallbackTests(unittest.TestCase):
    image = DuplicateFunctionTests.image
    invoke = DuplicateFunctionTests.invoke
    # Exercise the CLI with different compiler callback names while retaining
    # all address, size, byte, definition and relocation requirements.
    def renamed_image(self):
        image = self.image()
        for symbol in image.symbols:
            symbol.name = "__tcf_0"
        return image

    def mapped(self, image, *arguments):
        return self.invoke(image, "--address", "0x8005", "--compiled-func", "__tcf_0", *arguments)

    def test_renumbered_callback_is_explicitly_reported(self):
        code, stdout, stderr = self.mapped(self.renamed_image())
        self.assertEqual((code, stderr), (0, ""))
        self.assertEqual(stdout, "OK  __tcf_3  0x00008005  4 bytes (compiled: __tcf_0)\n")

    def test_mapping_still_checks_selected_bytes(self):
        image = self.renamed_image()
        image.data = image.data[:4] + b"\x03\x20\x70\x47"
        code, _, stderr = self.mapped(image)
        self.assertEqual(code, 1)
        self.assertIn("MISMATCH  __tcf_3  0x00008005 (compiled: __tcf_0)", stderr)

    def test_mapping_rejects_wrong_address_and_size(self):
        image = self.renamed_image()
        image.symbols = [image.symbols[0]]
        self.assertEqual(self.mapped(image)[0], 1)
        image = self.renamed_image()
        image.symbols[1].st_size = 2
        self.assertEqual(self.mapped(image)[0], 1)

    def test_mapping_rejects_import_and_absolute_symbols(self):
        for section in (0, 0xfff1):
            image = self.renamed_image()
            image.symbols = [Symbol("__tcf_0", 0x8005, 4, STT_FUNC, 0, section)]
            with self.subTest(section=section):
                self.assertEqual(self.mapped(image)[0], 2)

    def test_mapping_rejects_unresolved_selected_relocations(self):
        image = self.renamed_image()
        image.data += struct.pack("<II", 0x8004, 2)
        image.sections.append(SimpleNamespace(
            sh_type=9, sh_info=1, sh_entsize=8, sh_size=8, sh_offset=8))
        code, stdout, _ = self.mapped(image)
        self.assertEqual(code, 1)
        self.assertIn("relocation(s)", stdout)

    def test_mapping_requires_address_and_linked_image(self):
        code, _, stderr = self.invoke(self.renamed_image(), "--compiled-func", "__tcf_0")
        self.assertEqual(code, 2)
        self.assertIn("require two __tcf_N", stderr)
        image = self.renamed_image()
        image.e_type = 1
        self.assertEqual(self.mapped(image)[0], 2)

    def test_mapping_rejects_ordinary_and_empty_function_names(self):
        for name in ("probe", ""):
            with self.subTest(name=name):
                code, _, stderr = self.invoke(self.renamed_image(), "--address", "0x8005", "--compiled-func", name)
                self.assertEqual(code, 2)
                self.assertIn("require two __tcf_N", stderr)
        code, _, _ = self.invoke(self.renamed_image(), "--func", "probe", "--address", "0x8005", "--compiled-func", "__tcf_0")
        self.assertEqual(code, 2)


if __name__ == "__main__":
    unittest.main()
