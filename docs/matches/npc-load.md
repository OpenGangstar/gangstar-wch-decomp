# NPC data loading

`NPC::Load` at Thumb address `0x002fdcfd` matches all 236 retail bytes.
It uses the permitted GCC hint
`__builtin_expect(s_nodePoolID[objectType] == 255, 1)` to reproduce the
retail unpooled branch order. The complete function, all existing affected
functions, the NPC virtual table and the full GOT compare exactly.

`python tools/build.py --all` passed all 9,349 retail comparisons.

```text
OK REGION .got+0x360  0x004b03a8  17972 bytes
OK  _ZN3NPC4LoadERKN7Structs3NPCE  0x002fdcfd  236 bytes
OK SECTION .npc_vtable  0x004aad80  240 bytes
```

The reconstructed layout also preserves the original uninitialized fields
and the NPC constructor's 456-byte allocation extent.
