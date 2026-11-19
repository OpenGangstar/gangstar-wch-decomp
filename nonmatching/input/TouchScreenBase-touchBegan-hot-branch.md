# Touch beginning: rejected hot-branch hint

Target: `TouchScreenBase::touchBegan(const Point2D<short>&, long)`, Thumb
`0x0034ccf1`, native 140 bytes. Base: main PR #742, `30e19c51`.
This patch remains unapplied and unmatched; no code or Fully Linked credit.

The six source forms and the previous unchanged-source RTL allocation audit
are already exhausted. That audit identifies the active/known-zero value in R3
instead of native R4, allowing reuse of R3 for the subsequent first-point
address and forcing a different store/address order. One separately bounded
escalation tests whether weighting the initial inactive-slot branch as hot
changes this allocation. The only source change from the saved body is
`if (__builtin_expect(!slot.active, 1))`; the predicate and all operations,
field types, method signature, layout and ordinary compiler flags are retained.

The hint fails. It still loads the active byte into R3, swaps the persistent
this/point register choices, and increases the differences from seven to 17
bytes. Function and full-section checks fail first at 0x0e. Executable size
remains 140, SHA256:
`d171bbf52552b1c0da86b73b8016c33f91daeadd6f8541cba9b01d6b3c85445e`.
A subsequent unchanged-source control in the SAME current context reproduces
the exact archived unhinted SHA256
`9452611f1b628eff572d8f83b9ec64e5037666ac4b3aaed4e7d8ab081b82e11d`,
seven differing bytes and first difference 0x32. It is the retained best result.
No opposite hint or additional source variation was tried.

Both normal strict runs preserve all 35 existing functions, all 44 existing
sections and the GOT region; the new complete 28-byte message section also
passes. The hint and unhinted function/section fail, build exit 1. No derived
consumer or new full-project gate is claimed for this rejected artifact.

The first metadata setup mistakenly added the already compiled `_trace`
method as an import. The ordinary guard rejected it with:

```text
BUILD FAILED: external Thumb binding would replace compiled symbol: _ZNK15TouchScreenBase6_traceEPKc
```

Removing that incorrect added import makes the actual compiled method satisfy
the call. The guard is never bypassed. Existing offsetof-style warnings in
TouchIDListSupport.h remain warnings; no related header change is included.

Configure `WCH_BASE_LIB` and apply this patch only in an isolated checkout;
`python tools/build.py string-startup-touchscreenbase` should fail the target
function and section while preserving the existing comparisons. Native 140-byte
function and 28-byte message extent assertions and normal overlap checks stay
active. No compiler output, register pin, barrier or guessed return type is used.

The unsuccessful GNU hint does not meet the requirements for credited code and
is never applied to production. Further branch-hint trials require new causal
evidence; do not repeat a probability grid. The original assembly remains.
