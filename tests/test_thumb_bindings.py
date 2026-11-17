"""External interworking declarations must never replace compiled definitions."""

from pathlib import Path
import tempfile
import unittest

from tools.elf import EM_ARM, ElfFile, Section, Symbol
from tools.thumb_bindings import write_bindings


class ThumbBindingTests(unittest.TestCase):
    def retail(self):
        return ElfFile("retail.so", b"", e_machine=EM_ARM, symbols=[
            Symbol("thumb", 0x1001, 8, 0x12, 0, 1),
            Symbol("arm", 0x2000, 8, 0x12, 0, 1),
            Symbol("data", 0x3001, 8, 0x11, 0, 1),
            Symbol("missing", 0, 0, 0x12, 0, 0),
        ])

    def test_thumb_declaration_preserves_mode_and_emits_no_instructions(self):
        with tempfile.TemporaryDirectory() as directory:
            source = write_bindings(self.retail(), (), ["thumb"], Path(directory))
            self.assertEqual(source.read_text().splitlines(), [
                ".syntax unified", ".thumb", '.global thumb',
                '.thumb_set thumb, 0x00001000',
            ])

    def test_address_selects_a_specific_local_definition(self):
        retail = self.retail()
        retail.sections = [
            Section(0, "", 0, 0, 0, 0, 0, 0, 0, 1, 0),
            Section(1, ".text", 1, 6, 0x5000, 0, 32, 0, 0, 2, 0),
        ]
        retail.symbols.extend([
            Symbol("initialize", 0x5001, 8, 0x02, 0, 1),
            Symbol("initialize", 0x5011, 8, 0x02, 0, 1),
        ])
        with tempfile.TemporaryDirectory() as directory:
            source = write_bindings(retail, (), [
                {"name": "initialize", "address": "0x5011"}
            ], Path(directory))
            self.assertIn(".thumb_set initialize, 0x00005010", source.read_text())
            with self.assertRaisesRegex(ValueError, "not a defined"):
                write_bindings(retail, (), [
                    {"name": "initialize", "address": "0x5013"}
                ], Path(directory))

    def test_arm_data_undefined_and_unknown_names_are_rejected(self):
        with tempfile.TemporaryDirectory() as directory:
            for name in ["arm", "data", "missing", "unknown"]:
                with self.subTest(name=name), self.assertRaisesRegex(ValueError, "not a defined"):
                    write_bindings(self.retail(), (), [name], Path(directory))

    def test_own_or_dependency_definition_cannot_be_overridden(self):
        compiled = ElfFile("compiled.o", b"", symbols=[Symbol("thumb", 1, 8, 0x12, 0, 1)])
        with tempfile.TemporaryDirectory() as directory:
            for objects in [(compiled,), (ElfFile("own.o", b""), compiled)]:
                with self.subTest(objects=objects), self.assertRaisesRegex(ValueError, "replace compiled"):
                    write_bindings(self.retail(), objects, ["thumb"], Path(directory))

    def test_duplicate_bindings_are_rejected(self):
        with tempfile.TemporaryDirectory() as directory, self.assertRaisesRegex(ValueError, "duplicate"):
            write_bindings(self.retail(), (), ["thumb", "thumb"], Path(directory))

    def test_symbol_names_cannot_inject_assembler_directives(self):
        retail = self.retail()
        retail.symbols.append(Symbol("bad\n.byte 1", 0x4001, 8, 0x12, 0, 1))
        with tempfile.TemporaryDirectory() as directory, self.assertRaisesRegex(ValueError, "assembler symbol"):
            write_bindings(retail, (), ["bad\n.byte 1"], Path(directory))

    def test_non_arm_image_is_rejected(self):
        with tempfile.TemporaryDirectory() as directory, self.assertRaisesRegex(ValueError, "ARM"):
            write_bindings(ElfFile("other.elf", b""), (), [], Path(directory))


if __name__ == "__main__":
    unittest.main()
