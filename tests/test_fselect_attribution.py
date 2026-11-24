"""Keep the leading AnimObject function out of empty platform objects."""
from types import SimpleNamespace
import unittest

from tools.layout import build_attribution


def image(address=0x00349315, include_animobject=True):
    def symbol(name, kind, value=0):
        return SimpleNamespace(name=name, st_type=kind, st_value=value,
                               st_bind=0, table='.symtab')
    symbols = [symbol('IPhone.cpp', 4), symbol('$t', 0, 0x00349314),
               symbol('Win32.cpp', 4), symbol('$t', 0, 0x00349314)]
    if include_animobject:
        symbols += [symbol('AnimObject.cpp', 4), symbol('$t', 0, 0x00349314),
                    symbol('$d', 0, 0x00349330)]
    function = symbol('_Z7FSelectfff', 2, address)
    return SimpleNamespace(symbols=symbols, functions=lambda table: [function])


class FSelectAttributionTests(unittest.TestCase):
    def test_retained_internal_mapping_corrects_empty_boundary_owners(self):
        self.assertEqual(build_attribution(image())[0x00349315], 'AnimObject.cpp')

    def test_correction_requires_the_known_retail_identity(self):
        self.assertEqual(build_attribution(image(0x00349317))[0x00349317], 'IPhone.cpp')

    def test_correction_requires_the_original_source_manifest(self):
        self.assertEqual(build_attribution(image(include_animobject=False))[0x00349315],
                         'IPhone.cpp')
