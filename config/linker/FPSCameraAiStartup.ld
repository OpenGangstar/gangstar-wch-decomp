PROVIDE(__aeabi_fmul = 0x001c4724);
PROVIDE(__aeabi_i2f = 0x001c41e4);
PROVIDE(__aeabi_fdiv = 0x001c4520);
OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/ai-startup-fpscamera/retail-symbols.ld
INCLUDE config/linker/CameraSections.ld
_ZdlPv = 0x001c42b0;
__aeabi_fcmpgt = 0x001c419c;
__aeabi_fcmplt = 0x001c479c;
__aeabi_fadd = 0x001c4154;
__aeabi_fmul = 0x001c4724;
__aeabi_i2f = 0x001c41e4;
__aeabi_f2iz = 0x001c44cc;
__aeabi_fsub = 0x001c4328;
__aeabi_fcmpeq = 0x001c470c;
sqrtf = 0x001c4184;
__aeabi_atexit = 0x001c494c;
_ZN28retail_fpscamera_transitions16civPassive_transE = 0x004295a4;
_ZN28retail_fpscamera_transitions17scriptedNpc_transE = 0x004296d0;
_ZN28retail_fpscamera_transitions19civAggressive_transE = 0x00429700;
_ZN28retail_fpscamera_transitions16gangMember_transE = 0x004297e4;
_ZN28retail_fpscamera_transitions9cop_transE = 0x004297f0;
_ZN28retail_fpscamera_transitions10swat_transE = 0x00429928;
_ZN28retail_fpscamera_transitions17civ_vehicle_transE = 0x00429934;
_ZN28retail_fpscamera_transitions17cop_vehicle_transE = 0x004299c4;
_ZN28retail_fpscamera_transitions11guard_transE = 0x00429a78;
_ZN28retail_fpscamera_transitions22scripted_vehicle_transE = 0x00429b20;
SECTIONS
{
    .fps_scroll 0x00333e40 : { *ai-startup-fpscamera.o(.text._ZN9FPSCamera6scrollERKSt4listIP7Point2DIsESaIS3_EE) }
    .fps_update_touch_inputs 0x00334388 : { *ai-startup-fpscamera.o(.text._ZN9FPSCamera17updateTouchInputsEv) }
    .fps_zoom_touch 0x003342ac : { *ai-startup-fpscamera.o(.text._ZN9FPSCamera4zoomERKSt4listIP7Point2DIsESaIS3_EE) }
    .fps_update 0x003344f4 : { *ai-startup-fpscamera.o(.text._ZN9FPSCamera6updateEf) }
    .fps_init 0x00333fec : { *ai-startup-fpscamera.o(.text._ZN9FPSCamera4initEP11LevelObjecti) }
    .fps_vtable 0x004accb0 : { *ai-startup-fpscamera.o(.data.rel.ro._ZTV9FPSCamera) }
    .fps_enter 0x00333f70 : { *ai-startup-fpscamera.o(.text._ZN9FPSCamera5enterEv) }
    .fps_exit 0x003340c0 : { *ai-startup-fpscamera.o(.text._ZN9FPSCamera4exitEv) }
    .fps_vertical_angle 0x00333db8 : { *ai-startup-fpscamera.o(.text._ZN9FPSCamera16incVerticalAngleEf) }
    .fps_zoom 0x00333f58 : { *ai-startup-fpscamera.o(.text._ZN9FPSCamera4zoomEi) }
    .camera_variant_ctor 0x00334100 : { *ai-startup-fpscamera.o(.text._ZN9FPSCameraC1Ev .text._ZN9FPSCameraC2Ev) }
    .camera_variant_debug 0x00333e0c : { *ai-startup-fpscamera.o(.text._ZN9FPSCamera5debugEPN3irr5video12IVideoDriverE) }
    .camera_variant_dtor 0x00333fcc : { *ai-startup-fpscamera.o(.text._ZN9FPSCameraD1Ev .text._ZN9FPSCameraD2Ev) }
    .ai_startup_function_0 0x00333e10 : { *ai-startup-fpscamera.o(.text.__tcf_3) }
    .ai_startup_function_1 0x00334154 : { *ai-startup-fpscamera.o(.text._Z41__static_initialization_and_destruction_0ii) }
    .ai_startup_function_2 0x00334298 : { *ai-startup-fpscamera.o(.text._GLOBAL__I__ZN9FPSCameraC2Ev) }
    .ai_startup_storage_0 0x004b9dbc (NOLOAD) : { *ai-startup-fpscamera.o(.bss._ZN3irr5scene6quake315irrEmptyStringcE) }
    .ai_startup_storage_1 0x004b9ddc (NOLOAD) : { *ai-startup-fpscamera.o(.bss._ZN3irr2ps5vHalfE) }
    .ai_startup_storage_2 0x004b9de8 (NOLOAD) : { *ai-startup-fpscamera.o(.bss._ZN8gameloft2ai11civ_passiveE) }
    .ai_startup_storage_3 0x004b9df0 (NOLOAD) : { *ai-startup-fpscamera.o(.bss._ZN8gameloft2ai12npc_scriptedE) }
    .ai_startup_storage_4 0x004b9df8 (NOLOAD) : { *ai-startup-fpscamera.o(.bss._ZN8gameloft2ai13civ_agressiveE) }
    .ai_startup_storage_5 0x004b9e00 (NOLOAD) : { *ai-startup-fpscamera.o(.bss._ZN8gameloft2ai11gang_memberE) }
    .ai_startup_storage_6 0x004b9e08 (NOLOAD) : { *ai-startup-fpscamera.o(.bss._ZN8gameloft2ai3copE) }
    .ai_startup_storage_7 0x004b9e10 (NOLOAD) : { *ai-startup-fpscamera.o(.bss._ZN8gameloft2ai4swatE) }
    .ai_startup_storage_8 0x004b9e18 (NOLOAD) : { *ai-startup-fpscamera.o(.bss._ZN8gameloft2ai11civ_vehicleE) }
    .ai_startup_storage_9 0x004b9e20 (NOLOAD) : { *ai-startup-fpscamera.o(.bss._ZN8gameloft2ai11cop_vehicleE) }
    .ai_startup_storage_10 0x004b9e28 (NOLOAD) : { *ai-startup-fpscamera.o(.bss._ZN8gameloft2ai5guardE) }
    .ai_startup_storage_11 0x004b9e30 (NOLOAD) : { *ai-startup-fpscamera.o(.bss._ZN8gameloft2ai16scripted_vehicleE) }
    .shared_startup_empty_text 0x0044d91c : { *(.gnu.linkonce.r.localStartupEmptyText) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
ASSERT(SIZEOF(.ai_startup_storage_0) == 32, "_ZN3irr5scene6quake315irrEmptyStringcE extent");
ASSERT(SIZEOF(.ai_startup_storage_1) == 12, "_ZN3irr2ps5vHalfE extent");
ASSERT(SIZEOF(.ai_startup_storage_2) == 8, "_ZN8gameloft2ai11civ_passiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_3) == 8, "_ZN8gameloft2ai12npc_scriptedE extent");
ASSERT(SIZEOF(.ai_startup_storage_4) == 8, "_ZN8gameloft2ai13civ_agressiveE extent");
ASSERT(SIZEOF(.ai_startup_storage_5) == 8, "_ZN8gameloft2ai11gang_memberE extent");
ASSERT(SIZEOF(.ai_startup_storage_6) == 8, "_ZN8gameloft2ai3copE extent");
ASSERT(SIZEOF(.ai_startup_storage_7) == 8, "_ZN8gameloft2ai4swatE extent");
ASSERT(SIZEOF(.ai_startup_storage_8) == 8, "_ZN8gameloft2ai11civ_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_9) == 8, "_ZN8gameloft2ai11cop_vehicleE extent");
ASSERT(SIZEOF(.ai_startup_storage_10) == 8, "_ZN8gameloft2ai5guardE extent");
ASSERT(SIZEOF(.ai_startup_storage_11) == 8, "_ZN8gameloft2ai16scripted_vehicleE extent");
