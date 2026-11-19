# Character-specific animation selector

`Character::getSpecificAnimation(int)` maps generic animation IDs through the
character's existing state field, weapon type and two-handed status. The source
retains the native calls, signed state guards, return values and global int
member-function ABI.

The earlier nested-switch candidate had 47 differing bytes in shared return
block placement. Separating the four equal-return pairs for states 1 and 2
allows ordinary compiler tail merging to reproduce the native layout. This
single bounded family transfer changes no mapping, helper, class layout,
compiler flag or existing matched function. No hint, assembly or compiler-output
editing is used.

```text
OK  _ZN9Character20getSpecificAnimationEi  0x002f1a31  714 bytes
OK SECTION .character_specific_animation  0x002f1a30  716 bytes
```

The complete executable function SHA256 is
`3862975a7753774bca7dcc61f3d5585ab878eb41ce604f1317db4244d81fab77`.
The compiler-emitted physical section additionally contains the native two-byte
Thumb alignment instruction `c0 46`. Independent retail/executable extraction
confirms all 716 bytes. The linker asserts the complete physical extent; no
padding or executable output is inserted or edited.

The function replaces its prior external Thumb import. Its native section is
placed through the shared Character section script in the Character, NPC and
Player verification images. NPC and Player profiles compare the real compiled
function and section and import the newly needed Weapon::isTwoHanded helper as
Thumb code. The initial full run correctly stopped when a consumer attempted
to retain an external binding over this new compiled definition; dependency
metadata and shared placement were then repaired before a fresh frozen gate.

Historical grouped-return sources remain preserved as diagnostic history.
Production code uses separate equal-return cases and the original assembly is
removed only after the complete integrated native gate succeeds. Character has
other pending functions, so this selector alone does not complete a Fully
Linked unit.

## Integrated verification

A fresh corrected `python tools/build.py --all` passed all 190 profiles:
5,432 function checks, 5,336 section checks and 181 region checks, totaling
**10,949 native comparisons**. All 965 source/configuration/tool/nonmatching
input hashes stayed stable; no profile failed or was skipped. Independent
extraction confirms the same complete 714-byte executable hash and native
alignment bytes in all three verification images. Existing matched bodies and
compiler options are unchanged.

This adds one game function and 714 matched bytes. The separately replayed
ready candidate remains uncredited: compiling against this real selector emits
the same complete two-byte near miss. Its 114 existing owner functions, 32
sections and GOT region remain exact.
