# Mission::update exact match

`Mission::update(int)` matches all 536 retail bytes at Thumb address
`0x003365f1`. Its strict section and its 24-byte switch table (`0x0042a714`)
both compare exactly.

```text
OK  _ZN7Mission6updateEi  0x003365f1  536 bytes
OK SECTION .mission_update  0x003365f0  536 bytes
OK SECTION .mission_update_table  0x0042a714  24 bytes
```

## Source form

The function is a six-case switch over the mission state:

- the intro, where the screen-press or skipped-blocking-command skip shows the
  HUD outside cinematics;
- the running objective and its conditions;
- the failure case, which falls into the shared `setTextToPrint(-1)` clear;
- the text timers.

The skip tests use three static inline ScriptManager helpers: `screenPressed`,
`blockingSkipped` and `skipRequested`.

The hint-free form already reached 536 bytes. It placed two cold blocks in the
wrong order: the `introAnimation.Update(elapsed)` call came before the case-2
cinematic HUD block. Three materially different hint-free spellings gave
identical bytes.

## Branch hint (documented)

Per the maintainer clarification of 2026-10-25 in AGENTS.md, one GCC
branch-likelihood hint is used:

```cpp
if (introAnimation.animation != -1 && __builtin_expect(!introAnimation.IsAnimOver(), 0))
    introAnimation.Update(elapsed);
```

Marking the still-playing case as unlikely lowers the frequency of the `Update`
block, so basic-block reordering places that trace last, as retail does. The
complete function, its switch table and every existing match compare byte for
byte, as shown below.

## Verification

`python -B tools/build.py --all` exited 0 with 5,552 function, 5,635 section
and 181 region comparisons and no mismatch or skip. Unit tests, repository
checks and progress checks pass.
