/* Native placements for the remaining already-matched Application dependency methods. */
SECTIONS
{
    .retained_app_helper_0 0x002d3c38 : { *application-helpers.o(.text._ZN11Application16SetIsDemoVersionEb) }
    .retained_app_helper_1 0x002d3c40 : { *application-helpers.o(.text._ZN11Application16GetIsDemoVersionEv) }
    .retained_app_helper_2 0x002d3c68 : { *application-helpers.o(.text._ZN11Application6ReInitEPN3irr14IrrlichtDeviceE) }
    .retained_app_helper_3 0x002d3c78 : { *application-helpers.o(.text._ZN11Application20InitIPhoneFileSystemEv) }
    .retained_app_helper_4 0x002d3c90 : { *application-helpers.o(.text._ZN11Application21dumpMonitoredPointersEv) }
    .retained_app_helper_5 0x002d3c94 : { *application-helpers.o(.text._ZN11Application10SetDrawAllEb) }
    .retained_app_helper_6 0x002d3c48 : { *application-helpers.o(.text._ZN11Application19GetMaterialRendererEv) }
    .retained_app_helper_7 0x002d3c5c : { *application-helpers.o(.text._ZN11Application18SetDefaultLanguageEi) }
    .retained_app_helper_8 0x002d3c6c : { *application-helpers.o(.text._ZN11Application11ReInitWin32EPN3irr14IrrlichtDeviceE) }
    .retained_app_helper_9 0x002d446c : { *application-helpers.o(.text._ZN11Application16startSoundThreadEv) }
    .retained_app_helper_10 0x002d4408 : { *application-helpers.o(.text._ZN11Application17RegisterForUpdateEP10IUpdatable) }
    .retained_app_helper_11 0x002d3f7c : { *application-helpers.o(.text._ZN11Application27UnRegisterForIrrlichtEventsEPN3irr14IEventReceiverE) }
    .retained_app_helper_12 0x002d3fcc : { *application-helpers.o(.text._ZN11Application25UnRegisterForDrawingOnHUDEP9IDrawable) }
    .retained_app_helper_13 0x002d3ff0 : { *application-helpers.o(.text._ZN11Application27UnRegisterForDrawingInSceneEP9IDrawable) }
    .retained_app_helper_14 0x002d4318 : { *application-helpers.o(.text._ZN11Application25RegisterForIrrlichtEventsEPN3irr14IEventReceiverE) }
    .retained_app_helper_15 0x002d5558 : { *application-helpers.o(.text._ZN11Application25RegisterForDrawingInSceneEP9IDrawable) }
    .retained_app_helper_16 0x002d4390 : { *application-helpers.o(.text._ZN11Application23RegisterForDrawingOnHUDEP9IDrawable) }
    .retained_app_helper_17 0x002d4268 : { *application-helpers.o(.text._ZN11Application5PauseEv) }
    .retained_app_helper_18 0x002d4208 : { *application-helpers.o(.text._ZN11Application19StartGlobalResumingEv) }
    .retained_app_helper_19 0x002d4a6c : { *application-helpers.o(.text._ZN11Application8LogoDrawEv) }
    .retained_app_helper_20 0x002d4b08 : { *application-helpers.o(.text._ZN11Application18GlobalResumingDrawEv) }
    .retained_app_helper_21 0x002d4e40 : { *application-helpers.o(.text._ZN11Application9StartLogoEv) }
    .retained_app_helper_22 0x002d5898 : { *application-helpers.o(.text._ZN11Application10LogoUpdateEv) }
    .retained_app_helper_23 0x002d53e0 : { *application-helpers.o(.text._ZN11Application14stopMonitoringEPv) }
    .retained_app_helper_24 0x002d5c40 : { *application-helpers.o(.text._ZN11Application15startMonitoringEPvPKc) }
    .retained_app_helper_25 0x002d3cb8 : { *application-helpers.o(.text._ZN11Application10IsLogoOverEv) }
    .retained_app_helper_26 0x002d3c9c : { *application-helpers.o(.text._ZN11Application20IsGlobalResumingOverEv) }
}
