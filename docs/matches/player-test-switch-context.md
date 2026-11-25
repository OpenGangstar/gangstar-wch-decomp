# PlayerTest::switchContext exact match

`PlayerTest::switchContext(PlayerTest::eContext, bool)` matches all 900 retail
bytes at Thumb address `0x00301a75`, including relocations.

```text
OK  _ZN10PlayerTest13switchContextENS_8eContextEb  0x00301a75  900 bytes
```

## Source form

`switchContext` swaps the player between the normal and jail character
models. It does the following:

1. It freezes or unlocks the running scripts and resets the wanted level.
2. It reuses the cached scene node for the new context, or constructs the
   context's model. The constructed model has its materials, culling, user
   data and sky colour set up.
3. It binds the `Bip01-node` animation and stores the active animation record
   in the context cache.
4. For the jail context, it switches the map and saves the game.

Details that the retail bytes require:

- **Model construction.** The construct arm comes first: `if
  (!inactiveContextNodes[context]) { construct } else { reuse }`. Building
  that arm first changes pseudo order and CSE reuse, so the 440 constant is
  the one kept across the Collada call.
- **Model filename.** The filename is chosen by a `switch` whose `Context1`
  case body comes first. The compare order is still context 0 then 1, but
  the bodies are emitted jail first, which gives retail's reload register
  rotation.
- **Animation binding.** `bindAnimation` is called through a `Character*`
  formed as `this + 4`, the offset of the Character base after the
  IMapTrackable vptr. The pointer is used twice, for the call and for the
  animation record address, so it stays a separate temporary. That orders
  the `this + 4` computation before `this + 168`, as retail schedules it.
  The ordinary base conversion folds into the call, and sched2 then issues
  it after the record address.

## Header changes

- **`PlayerTest.h`:** the 44 bytes at `+440` become a union. One member keeps
  the existing fields (`unknown440` to `unknown448` and `contextRecords`). The
  other is `ContextAnimation contextAnimations[2]`, a pair of 16-byte records
  matching `Character::AnimationInfo`. Retail copies those records to and from
  the active animation at `+168`. No offset or class size changes.
- **`Map.h`:** `PlayerTest` is a friend, because `switchContext` calls the
  private `Map::setMap`.

## Strings and data

The model names `./char_pthug.bdae` (`0x0041df94`) and
`./char_pthug_jail.bdae` (`0x0041df7c`) are hidden externs bound to their
retail addresses. `Bip01-node` (`0x0041d8d0`) is the same retail string that
NPC.cpp places, so it is bound the same way. Defining the strings in this unit
adds a GOT entry, which shifts the literal pools of the other PlayerTest
functions.

Two `CHudManager` callees, `retroEffect` and `showCash`, are placed at their
retail addresses.

No branch hint, inline assembly, register constraint or output edit is used.

## Verification

`python -B tools/build.py ai-startup-playertest` passes, including
`PlayerTest::Update`. A fresh complete build, `python -B tools/build.py --all`, exited 0 with
5,600 function, 5,688 section and 181 region comparisons and no mismatch or
skip; the previous baseline was 5,599, 5,687 and 181.
