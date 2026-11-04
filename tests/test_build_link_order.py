"""Object precedence must reach GNU ld without moving the GOT harness or skipping checks."""

import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

from tools import build


class BuildLinkOrderTests(unittest.TestCase):
    def link_inputs(self, option=None, present=False):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            manifests = root / 'config' / 'matches'
            manifests.mkdir(parents=True)
            base = {'source': 'probe.cpp', 'compiler_flags': [], 'assembler_flags': [],
                    'linker_script': 'probe.ld', 'functions': ['dependency_probe']}
            (manifests / 'dependency.json').write_text(json.dumps(base))
            main = dict(base, dependencies=['dependency'], retail_got=True,
                        functions=['primary_probe'])
            if present:
                main['source_first'] = option
            (manifests / 'primary.json').write_text(json.dumps(main))
            harness = root / 'build' / 'matches' / 'primary' / 'retail-got.cpp'
            with patch.object(build, 'ROOT', root), patch.object(build, 'run') as commands, \
                    patch.object(build, 'load_base_library', return_value=(object(), None)), \
                    patch.object(build.ElfFile, 'load', return_value=object()), \
                    patch.object(build, 'write_harness', return_value=(harness, 0)), \
                    patch.object(build.check, 'check_function', return_value=0) as comparisons:
                passed = build.build_unit('primary', root / 'compiler', root / 'retail.so')
                self.assertTrue(passed)
                links = [call.args[0] for call in commands.call_args_list
                         if Path(call.args[0][0]).name.startswith('arm-eabi-ld')]
                self.assertEqual(len(links), 2)
                # Both images must still be checked after the ordering change.
                self.assertEqual([call.args[2]
                                  for call in comparisons.call_args_list],
                                 ['dependency_probe', 'primary_probe'])
                command = links[-1]
                return command[command.index('-o') + 2:]

    def test_default_keeps_dependencies_before_source_and_harness_first(self):
        self.assertEqual(self.link_inputs(), [
            'build/matches/primary/retail-got.o',
            'build/matches/dependency/dependency.o',
            'build/matches/primary/primary.o'])

    def test_explicit_false_preserves_legacy_order(self):
        self.assertEqual(self.link_inputs(False, True), self.link_inputs())

    def test_source_first_reorders_only_game_objects(self):
        self.assertEqual(self.link_inputs(True, True), [
            'build/matches/primary/retail-got.o',
            'build/matches/primary/primary.o',
            'build/matches/dependency/dependency.o'])

    def test_invalid_order_flag_fails_before_any_compiler_invocation(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            manifests = root / 'config' / 'matches'
            manifests.mkdir(parents=True)
            for value in ('yes', None, 1, []):
                (manifests / 'primary.json').write_text(json.dumps({'source_first': value}))
                with self.subTest(value=value), patch.object(build, 'ROOT', root), \
                        patch.object(build, 'run') as commands, \
                        self.assertRaisesRegex(ValueError, 'source_first must be a boolean'):
                    build.build_unit('primary', root / 'compiler', root / 'retail.so')
                commands.assert_not_called()


if __name__ == '__main__':
    unittest.main()
