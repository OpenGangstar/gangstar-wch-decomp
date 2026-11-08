_ZdaPv = 0x001c461c;
SECTIONS
{
    .physic_attributes_destructor 0x00321324 : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributesD1Ev .text._ZN16PhysicAttributesD2Ev) }
    .physic_info_ctor 0x00319dd0 : { *ai-startup-physicattributes.o(.text._ZN10PhysicInfoC1Ev .text._ZN10PhysicInfoC2Ev) }
    .physic_attributes_reset_info 0x00319d64 : { *ai-startup-physicattributes.o(.text._ZN16PhysicAttributes15ResetPhysicInfoEv) }
}
