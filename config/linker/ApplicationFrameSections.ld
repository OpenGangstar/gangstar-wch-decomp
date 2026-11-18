/* Native code and data for the application frame and texture-reload updates. */
SECTIONS
{
    .application_global_resuming_update 0x002d4bc0 : { *application-helpers.o(.text._ZN11Application20GlobalResumingUpdateEv) }
    .application_main_update 0x002d50f0 : { *application-helpers.o(.text._ZN11Application6UpdateEv) }
    .resume_update_literals 0x00413ca0 : { *application-helpers.o(.rodata.str1.4) }
    .application_update_loop 0x00413d94 : { *application-helpers.o(.rodata.application_update_loop) }
    .app_s_frameUpdateStart 0x004b683c (NOLOAD) : { *application-helpers.o(.bss.s_frameUpdateStart) }
    .app_s_frameTotalUpdateTime 0x004b6840 (NOLOAD) : { *application-helpers.o(.bss.s_frameTotalUpdateTime) }
    .app_s_frameUpdateCount 0x004b6844 (NOLOAD) : { *application-helpers.o(.bss.s_frameUpdateCount) }
    .app_s_frameUpdateTime 0x004b6848 (NOLOAD) : { *application-helpers.o(.bss.s_frameUpdateTime) }
}
