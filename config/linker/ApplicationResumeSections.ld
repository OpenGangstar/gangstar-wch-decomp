SECTIONS
{
 .application_resume_method 0x2d4e88 : { *application-helpers.o(.text._ZN11Application6ResumeEv) }
 .application_resume_tag 0x413d4c : { *application-helpers.o(.rodata.application_resume_tag) }
 .application_resume_message 0x413d68 : { *application-helpers.o(.rodata.application_resume_message) }
 .application_resume_map 0x40b608 : { *application-helpers.o(.rodata.application_resume_map) }
 .application_first_resume 0x4b5398 : { *application-helpers.o(.data.isFirstTime) }
}
