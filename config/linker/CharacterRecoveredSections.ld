PROVIDE(__aeabi_fcmpge = 0x001c4364);
__cxa_pure_virtual = 0;
SECTIONS
{
    .character_npc_event_dtor 0x002f5158 : { *ai-startup-character.o(.gnu.linkonce.t._ZN5EvNPCD1Ev) }
    .character_npc_event_delete 0x002f626c : { *ai-startup-character.o(.gnu.linkonce.t._ZN5EvNPCD0Ev) }
    .character_npc_event_vtable 0x004aa120 : { *ai-startup-character.o(.gnu.linkonce.d.rel.ro._ZTV5EvNPC) }
    .character_exit_vehicle 0x002f6000 : { *ai-startup-character.o(.text._ZN9Character11exitVehicleEb) }
    .character_animation_0 0x002f23fc : { *ai-startup-character.o(.text._ZN9Character13bindAnimationEPKcRNS_13AnimationInfoEPN3irr5scene10ISceneNodeE) }
    .character_animation_1 0x002f405c : { *ai-startup-character.o(.text._ZN9Character6UpdateEi) }
    .character_animation_resource 0x0041bcb0 : { *ai-startup-character.o(.rodata.characterAnimationResource) }
    .character_animation_shadow 0x0041bcc4 : { *ai-startup-character.o(.rodata.characterShadowNodeName) }
    .character_action_0 0x002f2184 : { *ai-startup-character.o(.text._ZN9Character5debugEPN3irr5video12IVideoDriverE) }
    .character_action_1 0x002f6298 : { *ai-startup-character.o(.text._ZN9Character8hitByCarEifP11LevelObject) }
    .character_action_2 0x002f64b8 : { *ai-startup-character.o(.text._ZN9Character8hijackedEv) }
    .character_hit_car_table 0x0041c20c : { *ai-startup-character.o(.rodata._ZN9Character8hitByCarEifP11LevelObject) }
    .character_recovered_002f1839 0x002f1838 : { *ai-startup-character.o(.text.__tcf_1 .gnu.linkonce.t.__tcf_1) }
    .character_recovered_002f7415 0x002f7414 : { *ai-startup-character.o(.text._ZN9Character6attackEv .gnu.linkonce.t._ZN9Character6attackEv) }
    .character_recovered_002f6fb9 0x002f6fb8 : { *ai-startup-character.o(.text._ZN9Character4kickEv .gnu.linkonce.t._ZN9Character4kickEv) }
    .character_recovered_002f2af5 0x002f2af4 : { *ai-startup-character.o(.text._ZN9CharacterD2Ev .gnu.linkonce.t._ZN9CharacterD2Ev .text._ZN9CharacterD1Ev .gnu.linkonce.t._ZN9CharacterD1Ev) }
    .character_recovered_002f2a79 0x002f2a78 : { *ai-startup-character.o(.text._ZN9CharacterD0Ev .gnu.linkonce.t._ZN9CharacterD0Ev) }
    .character_recovered_002f2ed9 0x002f2ed8 : { *ai-startup-character.o(.text._ZN9Character11goToVehicleEP7Vehiclebbbb .gnu.linkonce.t._ZN9Character11goToVehicleEP7Vehiclebbbb) }
    .character_recovered_002f3231 0x002f3230 : { *ai-startup-character.o(.text._ZN9CharacterC1Ei .gnu.linkonce.t._ZN9CharacterC1Ei .text._ZN9CharacterC2Ei .gnu.linkonce.t._ZN9CharacterC2Ei) }
    .character_vtable 0x004aa030 : { *ai-startup-character.o(.data.rel.ro._ZTV9Character) }
}
INCLUDE config/linker/PlayerEventSections.ld
