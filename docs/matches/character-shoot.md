# Character::shoot exact match

`Character::shoot(float, bool)` matches all 2608 retail bytes at Thumb address
`0x002f55d1`, including relocations and its two jump tables (`0x0041bfd0`).

```text
OK  _ZN9Character5shootEfb  0x002f55d1  2608 bytes
```

## Source form

The function handles a shot by the character: it validates the weapon and
its readiness, selects the animation for the current action, then either
casts a gun ray (applying damage, hit warnings and blood) or launches a
projectile toward the target.

Details that the retail bytes require:

- **One shared failure return.** Every failure path does `goto fail;`. A
  documented no-code `__builtin_prefetch(this)` right after the label keeps
  that block from being removed as an empty forwarder, so all paths share
  retail's single `movs r0,#0` and the guard cleanup.
- **Inner switches for the type tests.** Each two-way animation choice is a
  `switch (type)` instead of `if/else if`, which gives the even edge
  probabilities retail's arm traces need.
- **Ready edge.** A second documented no-code prefetch on the "ready" edge
  sets that branch to 50%, which places the isReady blocks and resolves
  every block-order tie in both switches. The required range was found with
  a model of GCC's block reordering pass that reproduces the compiler's
  dumps.
- **HUD block.** The HUD test is `if (hit) switch (...) { case 8: ... break;
  default: __builtin_prefetch(this); }`, which sets that block's frequency
  so local allocation breaks its priority ties as retail does. The faction
  is read before the friendliness test, and the dot product assigns its
  operands to locals inside the expression, which gives retail's high
  registers.
- **Projectile.** The X difference is computed first and the Y value is
  stored twice; the extra use keeps it live across the Z loads as retail
  does, and flow removes the first store.

All hints and the duplicate store carry source comments. Behaviour is
unchanged. No inline assembly, register constraint, flag change, output
edit or header change is used. The PlayerTest and NPC units, which link
this object, place the new sections, and PlayerTest no longer lists
`shoot` as external.

## Verification

`python -B tools/build.py ai-startup-character`, `ai-startup-playertest`
and `ai-startup-npc` pass. A fresh complete build, `python -B
tools/build.py --all`, exited 0 with 5,655 function, 5,713 section and 180
region comparisons and no mismatch or skip; the previous baseline was
5,654, 5,713 and 180.
