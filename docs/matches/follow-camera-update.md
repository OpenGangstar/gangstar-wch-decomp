# FollowCamera::update exact match

`FollowCamera::update(float)` matches all 776 retail bytes at Thumb address
`0x00333ab1`, including relocations.

```text
OK  _ZN12FollowCamera6updateEf  0x00333ab1  776 bytes
```

## Source form

The follow camera keeps its owner at a fixed distance. When the owner moves
outside the distance band, the camera is placed behind the owner along the
owner's camera offset, resetting that offset from the facing direction the
first time. It then follows the owner's ground height and looks at the
owner.

Details that the retail bytes require:

- **Two repositioning arms.** Retail has two separate copies of the
  repositioning code, one for a distance above the maximum and one for a
  distance below the minimum, with distinct temporaries and cross-jumped
  tails. The source has the same two arms under their two conditions; both
  limits are 450 in this build.
- **Call first in the flag block.** The first statement of each `flag32`
  block is the `followCameraOffset(getFacing())` call, so the call
  heuristic places the block out of line as in retail.
- **No named origin.** The next position is built directly from
  `owner->GetPosition() + owner->getCameraOffset() * distance`. A named
  origin in each arm made the sibling scopes share stack slots; retail
  keeps the position temporaries apart, which gives its 204-byte frame.
- **Ground height helper.** The owner's ground height is read through a
  file-local view and an inline helper, which reloads the owner for each
  height as retail does.
- **Unused results.** The facing and right vectors are computed but not
  used, because retail makes both calls.

No branch hint, inline assembly, register constraint, output edit or header
change is used. The other FollowCamera.cpp functions keep their bytes. The
earlier non-matching draft and patch under `nonmatching/core/` are retired.

## Verification

`python -B tools/build.py ai-startup-followcamera` passes. A fresh complete
build, `python -B tools/build.py --all`, exited 0 with 5,623 function, 5,710
section and 180 region comparisons and no mismatch or skip; the previous
baseline was 5,622, 5,709 and 180 (the new section is the function's
placement).
