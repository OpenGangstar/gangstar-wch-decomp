# FPSCamera::scroll exact match

`FPSCamera::scroll(std::list<Point2D<short>*> const&)` matches all 280 retail
bytes at Thumb address `0x00333e41`, and its strict section ends at the retail
extent.

```text
OK  _ZN9FPSCamera6scrollERKSt4listIP7Point2DIsESaIS3_EE  0x00333e41  280 bytes
OK SECTION .fps_scroll  0x00333e40  280 bytes
```

## Source form

The function turns the drag from the previous touch point into rotations:

- **Horizontal drag:** turns the player around Z by `(fov / 320) * dx` degrees
  (multiplied by π/180) through a quaternion product.
- **Vertical drag:** scaled by `fov / 480`, it adjusts the vertical angle.

It then stores the touch point.

The earlier body differed in 14 bytes. All of them were stack-slot order and the
scheduling that follows from it; nothing was missing. Four spellings give
retail's pseudo and spill order:

- **The vertical field of view.** It is written as a float scale,
  `getFOV() / 480.0f`, so TER sinks the conversion and divide into their use,
  and the raw call result becomes a later temporary.
- **The touch coordinates.** `int y, x;` is declared before assigning x and
  then y. Pseudo numbers follow reverse declaration order.
- **`dx` before the previous Y value.** Computing `dx` before reading the
  previous Y selects retail's reload registers.
- **The vertical delta.** It is a named float, so fold keeps `scale * dy` in
  retail operand order. When both operands are declarations they are not
  swapped.

`FPSCamera` does not declare `scroll`, and `std::list` is incomplete in this
unit. The function is therefore an `extern "C"` definition of the retail
mangled name. It uses a file-local field view and the existing
`TouchPointListView`. No header is changed.

No branch hint, inline assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py --all` exited 0 with 5,559 function, 5,642 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
