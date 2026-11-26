# MenuManager::_positionMapOnPoint exact match

`MenuManager::_positionMapOnPoint(irr::core::vector2d<float>&)` matches all
308 retail bytes at Thumb address `0x002e6731`, including relocations.

```text
OK  _ZN11MenuManager19_positionMapOnPointERN3irr4core8vector2dIfEE  0x002e6731  308 bytes
```

## Source form

The function converts a map point into the map view's coordinate frame,
centres the view on it and clamps the view to the map bounds.

Details that the retail bytes require:

- **Height read back through a view.** The vertical position starts from
  the height read again through a file-local view of the map size. As a
  separate single-use value, it becomes part of the vertical product's
  expression, and RTL CSE later merges the duplicate load.
- **Conversion into the same variable.** The float-to-int conversion is
  assigned back into the same variable. Because the definition has the same
  root variable, temporary-expression replacement keeps the multiplication
  at its definition, as retail does. The centring adjustment goes into a
  new variable, so the conversion is substituted into it and lands after
  the horizontal adjustment.
- **Early loads.** The view width and height are read into constants before
  the horizontal adjustment.
- **Definition without a header change.** `MenuManager.h` does not declare
  the method, so it is defined through its mangled name; the file already
  declares it for its caller.

No branch hint, inline assembly, register constraint, output edit or header
change is used. The other MenuManager.cpp functions keep their bytes; one
local jump-table label in `setText` is renumbered without any byte change.

## Verification

`python -B tools/build.py menu-manager-helpers` passes. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,620 function, 5,709
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,619, 5,709 and 180.
