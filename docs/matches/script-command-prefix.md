# Script command prefix and print-call interface

The common command view now contains only its four-byte opcode. The previous
view included a payload argument, making sizeof(ScriptCommand) eight bytes even
for native commands that allocate only four. This correction removes a known
integration prerequisite for the unmatched loader; it credits no new function.

The retained native loader audit identifies eighteen no-payload opcodes that
allocate four bytes, zero the opcode, then store the integer read from the
stream. Opcode 65 instead uses the existing eight-byte MissionStart record:
opcode at offset zero, integer argument at offset four. Its declaration moves
unchanged into Script.h, with a global DataStream forward declaration. The
existing Read implementation remains unchanged in ScriptManager.cpp.

Script::addCommand is the only canonical user of the former common argument
field. Its opcode-65 branch now reads the genuine MissionStart payload view.
These are flat serialized-record views, not a newly invented inheritance tree
or a claim that unrelated C++ types gain common-initial-sequence guarantees.
The established compiler configuration retains -fno-strict-aliasing.

## Effective print-call ABI

printCommand is declared static. Both direct native call sites pass the command
in R0: loadCommand at 0x0033de12 and nextCommand at 0x0033cefe. The latter first
calls getInstance, then overwrites that returned manager pointer with the
command before calling printCommand. A static member invoked through a receiver
expression preserves that expression's side effects while using this argument
placement.

The empty two-byte callee and mangled name do not alone prove original source
staticness; the declaration models the observed effective ABI. Original source
and interprocedural unused-argument behavior remain unavailable. No callee body
or existing caller implementation was altered to force this interpretation.

## Verification and remaining work

All 191 canonical ARM profiles rebuilt successfully after the four-file change:
5,465 function, 5,488 section and 181 region checks, 11,134 total. All 891 frozen
source/configuration/tool files stayed unchanged during that build. A separate
read-only audit covered all 4,296 existing matched game entries without gaps.
Representative literal comparison output:

```text
OK  _ZN6Script10addCommandEPN7Structs13ScriptCommandE  0x003390a5  36 bytes
OK  _ZN13ScriptManager12printCommandERKN7Structs13ScriptCommandE  0x0033d005  2 bytes
OK  _ZN7Structs12MissionStart4ReadER10DataStream  0x0033d93d  28 bytes
```

The saved dispatcher already uses a four-byte common prefix and typed payload
views. Its 78 payload declarations agree with the canonical records. Future
reuse of its private payload header must omit the duplicate MissionStart
declaration. The saved cleanup reads only the opcode through the common view;
its seven payload views, pointer offsets, deletion/clearing order and scalar
record lifetime remain independent requirements. Do not add owning destructors
or infer that deleting an unrelated typed object through this prefix is valid.

loadCommand, executeCommand and cleanCommand remain unmatched. Correcting these
interfaces does not resolve their earlier compiler/layout residuals or reset
attempt budgets. No assembly marker or generated progress status changes.
Matched and Fuzzy Matched remain 63.64%; Fully Linked remains 20.39%. No native
Windows implementation files were modified, and no Windows build was run.
