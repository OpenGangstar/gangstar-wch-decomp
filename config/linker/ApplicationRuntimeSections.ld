SECTIONS
{
    .application_completion_0 0x002d3cb8 : { *application-helpers.o(.text._ZN11Application10IsLogoOverEv) }
    .application_completion_1 0x002d3c9c : { *application-helpers.o(.text._ZN11Application20IsGlobalResumingOverEv) }

    .application_stop_monitoring 0x002d53e0 : { *application-helpers.o(.text._ZN11Application14stopMonitoringEPv) }
    .application_start_monitoring 0x002d5c40 : { *application-helpers.o(.text._ZN11Application15startMonitoringEPvPKc) }
    .application_logo_draw 0x002d4a6c : { *application-helpers.o(.text._ZN11Application8LogoDrawEv) }
    .application_logo_update 0x002d5898 : { *application-helpers.o(.text._ZN11Application10LogoUpdateEv) }
    .application_resume_draw 0x002d4b08 : { *application-helpers.o(.text._ZN11Application18GlobalResumingDrawEv) }
    .application_resume 0x002d4208 : { *application-helpers.o(.text._ZN11Application19StartGlobalResumingEv) }
    .application_start_logo 0x002d4e40 : { *application-helpers.o(.text._ZN11Application9StartLogoEv) }
    .application_pause 0x002d4268 : { *application-helpers.o(.text._ZN11Application5PauseEv) }
    .application_register_events 0x002d4318 : { *application-helpers.o(.text._ZN11Application25RegisterForIrrlichtEventsEPN3irr14IEventReceiverE) }
    .application_register_scene 0x002d5558 : { *application-helpers.o(.text._ZN11Application25RegisterForDrawingInSceneEP9IDrawable) }
    .application_register_hud 0x002d4390 : { *application-helpers.o(.text._ZN11Application23RegisterForDrawingOnHUDEP9IDrawable) }
    .application_register_update 0x002d4408 : { *application-helpers.o(.text._ZN11Application17RegisterForUpdateEP10IUpdatable) }
    .application_unregister_events 0x002d3f7c : { *application-helpers.o(.text._ZN11Application27UnRegisterForIrrlichtEventsEPN3irr14IEventReceiverE) }
    .application_unregister_hud 0x002d3fcc : { *application-helpers.o(.text._ZN11Application25UnRegisterForDrawingOnHUDEP9IDrawable) }
    .application_unregister_scene 0x002d3ff0 : { *application-helpers.o(.text._ZN11Application27UnRegisterForDrawingInSceneEP9IDrawable) }
    .application_start_sound 0x002d446c : { *application-helpers.o(.text._ZN11Application16startSoundThreadEv) }
}
