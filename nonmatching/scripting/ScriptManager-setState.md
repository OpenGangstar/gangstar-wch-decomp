# Script-manager state: verified NDK enum replay

Unmatched candidate for `ScriptManager::setState(State)`, Thumb `0x0033f1ed`,
native 732 bytes. Production base: `14ca327` after the verified NDK enum-width
baseline. No credit or assembly deletion. This is one bounded replay of the
saved canonical source, not a new six-form search.

An independent original-compiler sizeof probe corrects an inaccurate old note:
the archived State declaration occupied one byte with its actual historical
flags, and four bytes with the adopted NDK baseline. The old note claimed four
bytes. That type-width correction alone does not change this candidate's
executable: both actual linked functions have SHA256
`1392b85553336e5bec82510ce73f2d217f3edc5942a878bae3acf0ae7e601cc8`.
Both are 732 bytes, with the same first difference at 0x20 and 353 equal-offset
bytes. These counts are diagnostics, not a matching percentage or credit.

The source body is copied unchanged from the saved lifetime reconstruction.
Only its necessary private declaration/friend prerequisites are prepared. The
current OctTreeAABB declaration is extracted verbatim to a shared private
header at its original source location; existing members and inline bodies
remain intact, with only ScriptManager friendship added. A stale prerequisite
patch failed its initial check because a declaration had since changed; the
current declaration was then extracted directly. No candidate compile or
comparison occurred before this repair. No root shared-file change is applied.

The first normal strict link required four genuine existing ARM PLT math
bindings: __aeabi_fsub, __aeabi_fmul, __aeabi_fadd and __aeabi_fcmplt. Their
addresses come directly from the retail calls. Correcting these imports does
not change the source form. The resulting executable is placed at the real
native address with strict 732-byte function-section and 28-byte table bounds.

```text
MISMATCH  _ZN13ScriptManager8setStateENS_5StateE  0x0033f1ed
  expected : 53 45 08 d0 96 f7 40 f8 52 46 06 1c 06 2a 09 d9
  actual   : 53 45 08 d0 96 f7 40 f8 51 46 06 1c 06 29 09 d9
  differs at 0x20
```

The whole function section fails at the same offset. The complete dispatch
table also fails, first at 0. All 143 existing owning functions, 133 existing
sections and the GOT region pass. Normal build exit: 1. The private new
shared-header prerequisites have no refreshed full transitive preservation
proof in this replay; the owning checks do not substitute for that proof.
No source variant, width sentinel, alternate compiler option, register
constraint, hint, barrier, output edit or invented relocation is used.

Apply this patch only in an isolated checkout with `WCH_BASE_LIB` configured,
then run `python tools/build.py script-manager-helpers`. Expect the three target
failures above; existing owning comparisons must stay exact. The patch includes
all necessary source/profile/linker prerequisites, but remains unapplied.
Production functions, headers and progress remain unchanged. No further
state-layout trial is justified by this already tested enum-default hypothesis.
