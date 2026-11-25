# GS3DStuff::PrintNodeProperties exact match

```text
OK  _ZN9GS3DStuff19PrintNodePropertiesEPN3irr5scene10ISceneNodeEbi  0x002de6dd  528 bytes
OK SECTION .gs_print_node_properties  0x002de6dc  528 bytes
OK SECTION .gs_node_format  0x00414508  28 bytes
OK SECTION .gs_leaf_format  0x00414524  16 bytes
OK SECTION .gs_indent  0x00410720  4 bytes
```

Debug helper that prints a scene node's four-character type (unless it is one
of four ignored types), prints leaf nodes' types, builds an indentation string
for the depth, and optionally recurses into the children, returning the count
of ignored nodes.

This builds on the reviewed typed reconstruction in
`nonmatching/rendering/GS3DStuff-PrintNodeProperties-typed.patch` (STLport
string model and weak `append`/`_M_allocate_block` bindings), which differed in
four bytes: two spill slots (the stack guard's GOT offset and the short-string
end) were swapped.

Those slots follow GCC's gcse hash-table size: reload hands out stack slots
by pseudo number, and the pseudos are created in hash-bucket order. Writing
the upper three type bytes as unsigned shifts, `(type << 16 >> 24)` etc.,
instead of `(unsigned char)(type >> n)` produces fewer RTL instructions before
gcse (the final instructions are the same `lsl`/`lsr` pairs), which shrinks the
table from 51 to 49 buckets and gives retail's slot order. This spelling is
chosen for that compiler effect; the extracted values are identical.

`GS3DStuff.h` declares the static method. The format and indent strings are
placed at their retail addresses. No hint, inline assembly or register
constraint is used.

Full gate: `python -B tools/build.py --all` exited 0 with 5,532 function,
5,613 section and 181 region comparisons and no mismatch or skip.
