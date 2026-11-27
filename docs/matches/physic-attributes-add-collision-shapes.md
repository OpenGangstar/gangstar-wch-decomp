# PhysicAttributes::AddCollisionShapes exact match

`PhysicAttributes::AddCollisionShapes(int, unsigned short)` matches all 1816
retail bytes at Thumb address `0x0031e285`, including relocations. The other
sections of `PhysicAttributes.cpp` are unchanged, including
`ContactListener::Add`.

## Source form

For each height-map edge that a jump crosses, the function builds a Box2D
polygon shape and its jump data, then records the created body in the target
cell. Details that the retail bytes require, each commented in the source:

- **Spill-slot order.** Retail's spill slots need gcse1's expression hash table
  at 181 buckets, which means 720–727 RTL instructions before gcse1. The body is
  kept at 724. `int count` saves one instruction.
- **Moving block.** The velocity is read into a local, and `velocity.y` is read
  first. SRA then emits the `x` load first, and the velocity and product
  registers tie and resolve as in retail.
- **Address add order.** The target loop carries three extra IVs whose
  combination `k1 + k2 - k3` always equals `b`. ivopts removes them, and their
  freed SSA names give the loop's address add retail's operand order.
- **Max tail.** The inner maximum is bound as `const float&`, so out-of-SSA
  coalesces the result with it and keeps retail's `bne` polarity.
- **Store order.** The jump data is stored in field order, which gives
  allocation the live ranges retail has.
- **DECL_UID pad.** An 86-enumerator enum after the function keeps
  `ContactListener::Add`'s temporaries in retail order. It must be re-swept
  after any change to this body.
