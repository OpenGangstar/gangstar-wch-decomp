# MiniMap::_calculateXYOffset exact match

`MiniMap::_calculateXYOffset(irr::core::vector3d<float> const&,
irr::core::rect<int> const&, bool, bool) const` matches all 2012 retail bytes at
Thumb address `0x00329901`, including relocations. The section comparison
covers 2016 bytes, since the trailing `c046c046` padding matches retail too.

## Source form

The function projects a world position onto the minimap. When the point lies
outside the map radius, or when `north` is set, it projects the point onto the
map border by angle. Details that the retail bytes require, each commented in
the source:

- **Zero-angle frequency.** The zero-angle test has a second, redundant spelling:
  `angle==0 || ({ struct Z { unsigned k; } u = { angle==0 }; Z t = u; t.k==1u; })`.
  At branch-prediction time the aggregate copy is an integer equality, which the
  opcode heuristic predicts at 29%. That raises the zero arm's estimated
  frequency. Jump threading then removes the test, so the final edge
  probability still comes from the call-prediction hint. Basic-block reordering
  needs this frequency split to reach retail's block order.
- **Zero-length frequency.** Inside the `offset.dotProduct(rotated) > 0` arm
  there is an always-false `goto` back into the zero-length arm. Its condition is
  built from the shared `zero` bool, so profile predicts it at 21% (positive).
  DOM later folds it through the equivalence recorded for `zero` on that edge.
- **Call-prediction hints.** Three no-code `__builtin_prefetch(frameModule)`
  hints lower the zero-angle, not-quarter and not-three-quarter edges.
- **RADTODEG.** `(angle+PI)*(180.0f/PI)` folds to retail's literal `0x42652ee0`.
- **Half extents.** One half-extent variable serves both axes, which keeps
  retail's evaluation order for the radius.
- **rotateBy.** Irrlicht's `vector2d<float>::rotateBy` is imported as a weak
  `extern "C"` alias, so the call goes through the GOT as it does in retail.
