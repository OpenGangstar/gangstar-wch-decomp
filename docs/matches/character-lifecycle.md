# Character lifecycle matching

The constructor aliases, destructor family, attack and kick dispatch, vehicle
entry, factory cleanup, player-event destructors and NPC debug drawing are
verified with the recovered 296-byte Character layout. NPC references use
the same recovered pointer fields. Existing Character::getOutOfVehicle, plus NPC::grabSceneNode, dropSceneNode,
goToVehicle and Load, retain
their retail bytes after replacing opaque field accesses.

The destructor uses the permitted hint
`__builtin_expect(s_nodePoolID[objectType] == 255, 1)` for its unpooled
shadow cleanup branch. Every destructor variant and all affected existing
comparisons pass. The virtual interface includes the original Update override
and pure applyDamage slot; shoot(float, bool) returns bool, as its retail
return instructions and attack forwarding require.

`python tools/build.py --all` passed 9,370 function, section and region
comparisons. The constructor preserves the native uninitialized fields.

```text
OK  _ZN9CharacterD0Ev  0x002f2a79  124 bytes
OK  _ZN9CharacterD2Ev  0x002f2af5  116 bytes
OK  _ZN9CharacterD1Ev  0x002f2af5  116 bytes
OK REGION .got+0x360  0x004b03a8  17972 bytes
OK SECTION .character_vtable  0x004aa030  240 bytes
OK SECTION .npc_vtable  0x004aad80  240 bytes
```
