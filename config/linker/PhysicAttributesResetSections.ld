PROVIDE(sqrt = 0x001c401c);
PROVIDE(__aeabi_f2d = 0x001c48f8);
PROVIDE(__aeabi_d2f = 0x001c4310);
PROVIDE(__aeabi_uidiv = 0x001c4604);
PROVIDE(__aeabi_fcmpeq = 0x001c470c);
PROVIDE(__aeabi_fsub = 0x001c4328);
PROVIDE(__aeabi_fdiv = 0x001c4520);
PROVIDE(__aeabi_fcmpge = 0x001c4364);
PROVIDE(__aeabi_fcmple = 0x001c43ac);
_ZdaPv = 0x001c461c;
SECTIONS
{
    .physic_get_jump_height 0x0031a6fc : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes13GetJumpHeightERKN3irr4core8vector3dIfEEi) }
    .physics_segment_height 0x0031da28 : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes29IntersectSegmentWithHeightMapERKN3irr4core8vector3dIfEES5_RS3_S6_) }
    .physic_position_on_jump 0x0031a67c : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes16IsPositionOnJumpERKN3irr4core8vector3dIfEE) }
    .physic_find_lower 0x0031a40c : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes17FindLowerCostNodeEPN3irr4core5arrayI9AStarNodeNS1_12irrAllocatorIS3_EEEEPi) }
    ASSERT(SIZEOF(.physic_find_lower) == 192, "Strict native192 lower-cost-node extent")
    .physic_surface_0 0x0031e99c : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes21UpdateEdgesCollisionsEi) }
    .physic_surface_1 0x0031e0c8 : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes5CleanEv) }
    .physic_surface_2 0x003200f8 : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes4InitEttRKN3irr4core8vector3dIfEE) }

    .physic_segments_intersect 0x003196fc : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes17SegmentsIntersectERKN3irr4core8vector3dIfEES5_S5_S5_) }
    .physic_cleanup_0 0x00319cd4 : { *ai-startup-physicattributes.o(.text._ZN10PhysicInfo5ResetEP7b2World .gnu.linkonce.t._ZN10PhysicInfo5ResetEP7b2World) }
    .physic_cleanup_1 0x00319c20 : { *ai-startup-physicattributes.o(.text._Z15SafeDeleteArrayIN3irr4core5arrayItNS1_12irrAllocatorItEEEEEvRPT_ .gnu.linkonce.t._Z15SafeDeleteArrayIN3irr4core5arrayItNS1_12irrAllocatorItEEEEEvRPT_) }
    .physic_attributes_destructor 0x00321324 : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributesD1Ev .text._ZN16PhysicAttributesD2Ev) }
    .physic_info_ctor 0x00319dd0 : { *ai-startup-physicattributes.o(.text._ZN10PhysicInfoC1Ev .text._ZN10PhysicInfoC2Ev .gnu.linkonce.t._ZN10PhysicInfoC1Ev .gnu.linkonce.t._ZN10PhysicInfoC2Ev) *ai-startup-character.o(.gnu.linkonce.t._ZN10PhysicInfoC1Ev .gnu.linkonce.t._ZN10PhysicInfoC2Ev) *ai-startup-playertest.o(.gnu.linkonce.t._ZN10PhysicInfoC1Ev .gnu.linkonce.t._ZN10PhysicInfoC2Ev) *ai-startup-npc.o(.gnu.linkonce.t._ZN10PhysicInfoC1Ev .gnu.linkonce.t._ZN10PhysicInfoC2Ev) }
    .physic_attributes_ctor 0x0031b29c : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributesC1EiP6b2Body .text._ZN16PhysicAttributesC2EiP6b2Body) }
    ASSERT(SIZEOF(.physic_info_ctor) == 96, "PhysicInfo native96 extent")
    .physic_attributes_reset_info 0x00319d64 : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes15ResetPhysicInfoEv) }
    .physic_delete_world 0x00319e30 : { *ai-startup-physicattributes.o(.gnu.linkonce.t._Z10SafeDeleteI7b2WorldEvRPT_) }
    .physic_clean_world 0x00319e50 : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes10CleanWorldEv) }
    .b2_contact_listener_add 0x003196e8 : { *ai-startup-physicattributes.o(.gnu.linkonce.t._ZN17b2ContactListener3AddEPK14b2ContactPoint) }
    .b2_contact_listener_persist 0x003196ec : { *ai-startup-physicattributes.o(.gnu.linkonce.t._ZN17b2ContactListener7PersistEPK14b2ContactPoint) }
    .b2_contact_listener_remove 0x003196f0 : { *ai-startup-physicattributes.o(.gnu.linkonce.t._ZN17b2ContactListener6RemoveEPK14b2ContactPoint) }
    .b2_contact_listener_result 0x003196f4 : { *ai-startup-physicattributes.o(.gnu.linkonce.t._ZN17b2ContactListener6ResultEPK15b2ContactResult) }
    .contact_listener_result 0x003196f8 : { *ai-startup-physicattributes.o(.text._ZN15ContactListener6ResultEPK15b2ContactResult) }
    .contact_listener_remove 0x0031a5ec : { *ai-startup-physicattributes.o(.text._ZN15ContactListener6RemoveEPK14b2ContactPoint) }
    .b2_contact_listener_delete 0x00319a20 : { *ai-startup-physicattributes.o(.gnu.linkonce.t._ZN17b2ContactListenerD0Ev) }
    .b2_contact_listener_destructor 0x00319a40 : { *ai-startup-physicattributes.o(.gnu.linkonce.t._ZN17b2ContactListenerD1Ev) }
    .contact_filter_destructor 0x00319a58 : { *ai-startup-physicattributes.o(.gnu.linkonce.t._ZN13ContactFilterD1Ev) }
    .contact_filter_delete 0x0031d9fc : { *ai-startup-physicattributes.o(.gnu.linkonce.t._ZN13ContactFilterD0Ev) }
    .contact_listener_delete 0x00320300 : { *ai-startup-physicattributes.o(.gnu.linkonce.t._ZN15ContactListenerD0Ev) }
    .contact_listener_destructor 0x0032032c : { *ai-startup-physicattributes.o(.gnu.linkonce.t._ZN15ContactListenerD1Ev) }
    .b2_contact_listener_vtable 0x004abd38 : { *ai-startup-physicattributes.o(.gnu.linkonce.d.rel.ro._ZTV17b2ContactListener) }
}

/* Verified binary navigation loader and its original readonly literals. */
_Znaj = 0x001c3ff8;
fopen = 0x001c45bc;
fread = 0x001c4598;
fclose = 0x001c4628;
__stack_chk_fail = 0x001c42e0;
SECTIONS
{
    .physics_load_arrays 0x00319ed4 : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes10LoadArraysEPc) }
    .load_arrays_mode 0x004014f0 : { *ai-startup-physicattributes.o(.rodata.loadArraysMode) }
    .load_arrays_error 0x00420a68 : { *ai-startup-physicattributes.o(.rodata.loadArraysError) }
}
