# RenderFX::DBG_TraceContextInformation

The 124-byte Thumb function at `0x003ed2f5` matches the retail library exactly.
It reuses the exact collection function's typed name/string interface and the
actual array-reference return from `FindCharacters`. The character is reloaded
from that array after `printf`, before the original type check and `puts` call.
No loop restructuring, hint, compiler flag or existing method-body change is used.

```text
OK  _ZN8RenderFX27DBG_TraceContextInformationEPN7gameswf9characterE  0x003ed2f5  124 bytes
OK SECTION .renderfx_trace_context  0x003ed2f4  124 bytes
```

Function SHA-256:
`74a77ecf86ce7215a38f8f839283579e7ea7ec6656d09206d30bf76f348275af`.
The only new definitions are this function and its two print literal arrays.
Each string symbol is 22 bytes in a 24-byte physical section; the complete
sections, including two native zero padding bytes, compare at `0x0044ddf8`
and `0x0044de10`. The initial private assertion incorrectly required a 22-byte
section and was corrected after independently verifying the full native span.
The source arrays, addresses and compiler output were unchanged by that repair.

The real function and both literal regions are retained and explicitly checked
in the owning image and both native dependency consumers. No compiled definition
is masked. All old allocated code/data payloads remain identical. A missing
nonvirtual method declaration is added to the partial RenderFX interface without
changing layouts or vtable slots.

The full current-root gate passes 190 profiles and 10,557 comparisons, preserving
all previous function/section checks and compiler profiles. The affected private
closure passes 616 functions, 326 sections and five GOT regions. Source provenance
for the shared gameswf accessors is documented in the CollectCharacters match
note. The original source remains incomplete; this adds 124 matched bytes and
no Fully Linked credit.
