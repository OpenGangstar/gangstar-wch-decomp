/* Exact GS3DStuff loader closure shared by owner and direct dependents. */
SECTIONS {
    .gs_load 0x002dfb14 : { *gs3d-stuff.o(.text._ZN9GS3DStuff4loadEiRi) }
    .gs_load_weights 0x00414c4c : { *gs3d-stuff.o(.rodata.LoadingPercents) }
    .gs_load_switch 0x00414644 : { *gs3d-stuff.o(.rodata._ZN9GS3DStuff4loadEiRi) }
    .gs_load_profile 0x414558 : { *gs3d-stuff.o(.rodata.gs_load_profile) . = ALIGN(4); }
    .gs_load_sun 0x414578 : { *gs3d-stuff.o(.rodata.gs_load_sun) . = ALIGN(4); }
    .gs_load_heightmap 0x414588 : { *gs3d-stuff.o(.rodata.gs_load_heightmap) . = ALIGN(4); }
    .gs_load_navigation 0x4145a8 : { *gs3d-stuff.o(.rodata.gs_load_navigation) . = ALIGN(4); }
    .gs_load_background 0x4145c0 : { *gs3d-stuff.o(.rodata.gs_load_background) . = ALIGN(4); }
    .gs_load_glow 0x4145d4 : { *gs3d-stuff.o(.rodata.gs_load_glow) . = ALIGN(4); }
    .gs_load_main_menu 0x413c7c : { *gs3d-stuff.o(.rodata.gs_load_main_menu) . = ALIGN(4); }
    .gs_load_missions 0x4145e4 : { *gs3d-stuff.o(.rodata.gs_load_missions) . = ALIGN(4); }
    .gs_load_scripts 0x4145f4 : { *gs3d-stuff.o(.rodata.gs_load_scripts) . = ALIGN(4); }
    .gs_load_highlights 0x414608 : { *gs3d-stuff.o(.rodata.gs_load_highlights) . = ALIGN(4); }
    .gs_load_blood_puddle 0x41461c : { *gs3d-stuff.o(.rodata.gs_load_blood_puddle) . = ALIGN(4); }
    .gs_load_blood_particle 0x414630 : { *gs3d-stuff.o(.rodata.gs_load_blood_particle) . = ALIGN(4); }
}
