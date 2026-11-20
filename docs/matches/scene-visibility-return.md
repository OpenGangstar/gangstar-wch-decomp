# Consumed scene visibility return

The matching interface declared ISceneNode::getVisibility as returning float.
The observed fork returns the address of visibility storage; use an opaque
void pointer until its original pointee type is identified. This corrects only
the consumed ABI view, not the engine implementation or a game function body.
The existing interface notice explicitly marks unused return types provisional.

The retail getter at Thumb 0x00272879 is eight bytes:
`96 23 5b 00 c0 18 70 47`. It computes this + 300 and returns that address.
Vehicle::UpdatePhysic loads virtual slot 76 at 0x0030f26e, calls it at
0x0030f270, then immediately reads a word through returned R0 at 0x0030f272.
The original pointee structure is not claimed recovered.

Original GCC 4.2.1 before/after interface probes both compile and assemble.
The partial class view stays 340 bytes/alignment 4. Its eight-byte ARM
pointer-to-member representation remains `4c00000001000000`, preserving the
same virtual slot and this adjustment. No fields or virtual entries move.
No native Windows implementation or launcher code changes.

Full canonical native preservation passes 191 profiles, 5436 functions, 5340
sections and 181 regions: all 10957 comparisons exact, exit 0, 1068 frozen
inputs stable. No function, assembly marker, classification or progress credit
changes. Matched/Fuzzy stays 61.56%; Fully Linked stays 20.01%.
