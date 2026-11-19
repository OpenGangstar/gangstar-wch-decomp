# Application::InitIPhone on the Android retail target

The complete 18-byte Thumb function at `0x002d3c7d` is reconstructed literally:
it calls the existing `InitIPhoneFileSystem` helper, then stores a true boolean
at address zero. The instruction and its zero address were checked against the
retail library and relocations; no known object field replaces that address.
This is an observed platform stub, not a working initialization implementation.
No runtime execution or fault test was performed.

The method's device-pointer and four float parameter types are encoded in its
native symbol. The provisional `void` return type is inferred from the platform
interface; the non-template mangled name does not encode it, and no native
caller was found that proves the original return declaration. External or
dynamic use is not ruled out. The literal null store has undefined C++ behavior;
the complete GCC 4.2.1 output, rather than portable behavior on another compiler,
is the matching proof.

The new nonvirtual declaration changes no Application data layout or virtual
slots. The existing two-byte filesystem helper remains a real compiled
definition. The 20-byte physical target section contains the complete function
and two native alignment bytes, with an exact linker-size assertion.

The comparison tool printed in both the owning image and the GSFade image that
also links the Application object:

```text
OK  _ZN11Application20InitIPhoneFileSystemEv  0x002d3c79  2 bytes
OK  _ZN11Application10InitIPhoneEPN3irr14IrrlichtDeviceEffff  0x002d3c7d  18 bytes
OK SECTION .application_init_iphone  0x002d3c7c  20 bytes
```

The 18-byte function SHA-256 is
`f5352de0f04a2630a96a14fce39c9e97f32c4a294a8cc2af5567f278a918dbc7`.
Seven targeted profiles pass 433 function, 453 section and seven GOT region
comparisons: 893 checks, retaining all 889 previous checks.

A historical declaration context regressed `Cash::drawCash`; that failure does
not reproduce in the current checkout. Both the current baseline and the new
declaration context retain its exact 332 bytes and identical Cash objects.
Cash and its thunk pass without any source repair. This does not establish a
specific cause for the historical regression; the complete current header
closure must still pass before integration is accepted.

The coordinator's combined gate exposed one different compatibility regression:
`NPC::equipWeapon` reversed two independent null initializations. Swapping only
the adjacent declarations of `rightModel` and `leftModel` restores the existing
complete 208-byte match. This is an explicit change to an already matched
function; its values, calls, control flow and behavior remain unchanged. The
private NPC/PlayerTest closure passes all 454 checks. The coordinator's combined
ten-profile recheck passes 979 function, 519 section and ten region comparisons
(1,508 total), including both menu notifications and the NPC consumer.
