PROVIDE(__aeabi_fcmpeq = 0x001c470c);
PROVIDE(__aeabi_fsub = 0x001c4328);
PROVIDE(__aeabi_fdiv = 0x001c4520);
PROVIDE(__aeabi_fcmpge = 0x001c4364);
PROVIDE(__aeabi_fcmple = 0x001c43ac);
_ZdaPv = 0x001c461c;
SECTIONS
{
    .physic_segments_intersect 0x003196fc : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes17SegmentsIntersectERKN3irr4core8vector3dIfEES5_S5_S5_) }
    .physic_cleanup_0 0x00319cd4 : { *ai-startup-physicattributes.o(.text._ZN10PhysicInfo5ResetEP7b2World .gnu.linkonce.t._ZN10PhysicInfo5ResetEP7b2World) }
    .physic_cleanup_1 0x00319c20 : { *ai-startup-physicattributes.o(.text._Z15SafeDeleteArrayIN3irr4core5arrayItNS1_12irrAllocatorItEEEEEvRPT_ .gnu.linkonce.t._Z15SafeDeleteArrayIN3irr4core5arrayItNS1_12irrAllocatorItEEEEEvRPT_) }
    .physic_attributes_destructor 0x00321324 : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributesD1Ev .text._ZN16PhysicAttributesD2Ev) }
    .physic_info_ctor 0x00319dd0 : { *ai-startup-physicattributes.o(.text._ZN10PhysicInfoC1Ev .text._ZN10PhysicInfoC2Ev) }
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
