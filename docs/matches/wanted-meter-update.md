# Wanted meter update

`WantedMeter::update(double)` matches all 80 bytes at Thumb `0x0032c851`,
including its complete physical section. It leaves the unused elapsed argument,
flags-bit guard, base frame, signed manager-field test, five animation updates
and native reload/call order unchanged.

The source reuses the indexed traversal already used by the matched draw
method. GCC peels the first iteration itself; emitted code has the native four
static SetAnim/UpdateFrame call sites. Manually peeling the source first caused
another compiler peel and six calls, so that failed form was not integrated.

The existing timer-field condition uses the maintainer-permitted GNU hint
`__builtin_expect(condition, 1)`. Without it, the pointer-loop trial placed the
addition in a separate cold block. The hint restores the native branch layout;
indexed traversal also removes the extra cursor-copy instruction. The only
shared-header prerequisite is ordinary friend access to the existing manager
field. No field type, layout, calling convention or existing matched body is
changed. No dummy declarations, forced registers, barriers, production option
changes or compiler-output edits are used.

Six archived source forms were audited, not reset. Four bounded current-context
forms were tested: saved manual peel (100 bytes), saved pointer loop (84), that
loop with the hint (84), and indexed traversal with the same hint (80). The
initial source-call count was corrected by inspecting emitted code before any
matching claim. All failed forms remain uncredited.

## Exact verification

```text
OK  _ZN11WantedMeter6updateEd  0x0032c851  80 bytes
OK SECTION .wanted_meter_update  0x0032c850  80 bytes
```

Native and linked function SHA256:
`5d1df700fb9cbc7586421a81c2db36f0dc6da836ffc63d7d7f8056928be2af74`.
The original Thumb bindings for SetAnim and UpdateFrame are explicit in the
verification profile; no compiled definition is overridden. The entire native
80-byte section is retained with a strict extent assertion.

The friend-only prerequisite independently passed 190 profiles and 10,935
comparisons with the target absent; all 955 frozen inputs remained unchanged.
The independent linked owner check passed every existing comparison and the
new function/full-section checks. The final independent root full gate passed 190 profiles: 5,426 function checks,
5,330 section checks and 181 region checks = 10,937 comparisons. Exit 0, no
mismatch or skip; all 955 frozen inputs remained unchanged. This verifies the
complete hinted function and every affected existing match.

Only the verified assembly marker is removed. This adds 80 real matched bytes.
The constructor C1/C2 aliases remain pending, so the source group does not yet
qualify for Fully Linked credit. The denominator and Windows port are unchanged.
