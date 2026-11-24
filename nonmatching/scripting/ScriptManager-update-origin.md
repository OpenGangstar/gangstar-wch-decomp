# ScriptManager::update: compiler-origin diagnostic, still unmatched

Target `_ZN13ScriptManager6updateEi`, Thumb `0x0033f511`, remains 1,228 bytes
versus native 1,220; its complete input section remains 1,232 bytes. The six
source forms remain exhausted. No source, header, ABI or optimizer change was
made by this diagnostic, and no matching credit is added.

One frontend/assembler pair used the authenticated historical 884-input fixture
and its original options, adding only tree/RTL dump output. Generated assembly
and the **entire object file** are byte-identical to the saved baseline:

```text
assembly SHA256: a9bfa0849ead393c2bfb7f230ec237204b9453595fe6ae5b9d16761666649ed9
object SHA256: 3f2a5a3c75756c606c4ead89f7a2b0495f6572fe4524534052857dbd074e557f
frontend invocations: 1
assembler invocations: 1
linker invocations: 0
```

No namespace correspondence or output modification is needed. All frozen inputs
and newly recorded executable/runtime hashes remain stable. The historical
receipt did not contain executable hashes, and its frontend argv was reconstructed
from the unchanged builder rather than a direct command log. Exact regenerated
output establishes output equivalence; it does not recover the missing historical
executable receipt or prove a current-main/global build.

## First argument-setup mismatch

Before the first MenuManager::setText call, native sets R1 and R3 to zero before
moving its receiver into R0. The candidate moves the receiver first. RTL expand
already emits receiver UID50 before zero-argument UIDs51/53. Instruction splitting
replaces the minus-one argument UID52 with two instructions, UIDs880/881. The
post-reload scheduler produces the final sequence880/50/51/53/881, retaining the
receiver-before-zero ordering established at expansion. The native sequence is
different; final code alone does not establish a different original signature or
C++ evaluation-order requirement.

## Loop-tail duplication

The block-reordering pass explicitly reports `Duplicated bb 46 (created bb 80)`
and creates tail instructions UIDs938/939/940 from UIDs455/456/457. The preceding
rnreg dump has one tail. This localizes an observed duplicate increment/bound
block to compiler block reordering, rather than a missing source callback or
state update. It does not justify disabling cross-jumping globally, adding a
barrier or rewriting the already verified callback semantics.

The diagnostic stops without another source form. Native section overflow,
existing relocated-neighbor limitations and old versus current owner contexts
remain unresolved. No linker or native target comparison was run. Complete
inputs, commands, 117 dumps, 113 function extracts and preservation/origin proofs
remain in the coordinator's private compiler-origin packet.
