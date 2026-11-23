# On-foot keyboard sharing: 1,324 bytes, still unmatched

Target `_ZN21COnFootControlHandler15onKeyboardEventEPK6IEvent`,
Thumb `0x0032e835`, native **1,320 bytes**. The retained
[delta](OnFoot-keyboard-sharing.patch) applies to the private corrected seventh
form, not directly to current HEAD. Its corrected nonzero V/Y predicates are a
prerequisite. No matching credit or assembly-marker removal follows.

## Two separately verified source controls

Retail V calls `immobilize` then joins Y's shared reload/test/mobilize/store
body. The old source duplicated that prefix. One source-only fallthrough
control reproduced the native 46-byte V/Y instruction union, versus 56 before.
The entire function/input section fell from **1,332 to 1,328 bytes**.

Fresh analysis of that actual 1,328-byte object then proved that keys 5 and 8
still duplicated the door-call tail. A separate control shares that expression:
key 8 jumps to a label after key 5's null guard. It retains key 8's own initial
guard and callbacks, bypasses only the native-absent second null check, and
reloads global `car` after callbacks. No initialized local is bypassed.

The ninth form has one shared door call; its key-5/8 instruction union is
74 bytes versus 78 before and 72 native. V/Y stays 46 bytes. **Both the function
and entire input section are 1,324 bytes**, still four over native.

```text
function_size: 1324
whole_input_section_size: 1324
native_function_size_gate: false
native_section_size_gate: false
```

**No linker ran**, no source retry occurred, and no native-placement,
target/table/GOT/neighbor or current-root linked-closure claim is made.
There is no padding, pool editing, likelihood hint, compiler flag, header,
receiver cache, or adjustment of unrelated cases.

## Evidence and limits

The first control's baseline reproduces the complete saved seventh-form object
byte-for-byte. Seventh-function raw SHA256:
`da64eae629f3c8a7aba6a2abaed4d06f908f5693820fd8bc60ff016bb441b4bb`.
Eighth-function/full-section raw SHA256:
`ea55f66a2ae68108d9353f7f1d32cd82b2ab8fbd6c088af71a4b5534f5169c4a`.
Ninth-function/full-section raw SHA256:
`a8bb0b55c8494727332b647d05c12fa95e38b87832aceeb0d909996edc80a8dd`.

The ninth form reuses the frozen eighth-form context without another baseline
compile. Each source control consumes exactly one compiler/assembler pair.
All off-target definition records, allocated payloads, and raw relocation
sections are unchanged. Exact-name/attribute import multisets are preserved:
seventh-to-eighth symbol order changes are disclosed, not called object identity.
All 151 dispatch-entry direct/virtual-slot call-trace sets remain identical;
predicates, guard bypass and fresh receiver reads are checked separately. These
bounded checks are not arbitrary-value or whole-source equivalence proofs.

Private packages `_scratch/opencode-onfoot-vy-shared-control/` and
`_scratch/opencode-onfoot-door-tail-control/` retain exact source, generated
assembly/objects, frozen inputs/toolchains, commands/exits and proof scripts.
Run their `proof.py` scripts for read-only verification; do not rerun compilation.
The frozen historical interface context is not installed in canonical headers.

The six original forms, predicate seventh, sharing eighth and door-tail ninth
remain spent. This batch is finished; no additional form is authorized.
