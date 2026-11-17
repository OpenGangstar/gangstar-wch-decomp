__stack_chk_fail = 0x001c42e0;
vsprintf = 0x001c4070;
SECTIONS
{
    .renderfx_named_registerdisplaycallback 0x003ee14c : { *renderfx-animation.o(.text._ZN8RenderFX23RegisterDisplayCallbackEPKcPFvRN7gameswf12render_stateEPvES5_) }
    .renderfx_named_isanimover 0x003ee168 : { *renderfx-animation.o(.text._ZN8RenderFX10IsAnimOverEPKc) }
    .renderfx_named_getframecount 0x003ee184 : { *renderfx-animation.o(.text._ZN8RenderFX13GetFrameCountEPKc) }
    .renderfx_named_gettext 0x003ee260 : { *renderfx-animation.o(.text._ZN8RenderFX7GetTextEPKc) }
    .renderfx_named_setposition 0x003ee290 : { *renderfx-animation.o(.text._ZN8RenderFX11SetPositionEPKcii) }
    .renderfx_named_setcolorfilter 0x003ee2c8 : { *renderfx-animation.o(.text._ZN8RenderFX14SetColorFilterEPKcij) }
    .renderfx_named_setcolortransform 0x003ee2e4 : { *renderfx-animation.o(.text._ZN8RenderFX17SetColorTransformEPKcjj) }
    .set_character_text 0x003eebd0 : { *renderfx-animation.o(.text._ZN8RenderFX7SetTextEPN7gameswf9characterEPKcb) }
    .set_named_text 0x003eec4c : { *renderfx-animation.o(.text._ZN8RenderFX7SetTextEPKcS1_b) }
    .format_named_text 0x003eeca8 : { *renderfx-animation.o(.text._ZN8RenderFX10FormatTextEPKcS1_z) }
    .format_character_text 0x003eed28 : { *renderfx-animation.o(.text._ZN8RenderFX10FormatTextEPN7gameswf9characterEPKcz) }
    .renderfx_string_buffer 0x004bd500 (NOLOAD) : { *renderfx-animation.o(.bss.s_stringBuffer) }
    .set_named_focus 0x003ef4f4 : { *renderfx-animation.o(.text._ZN8RenderFX8SetFocusEPKci) }
    .find_characters 0x003ed2ac : { *renderfx-animation.o(.text._ZN8RenderFX14FindCharactersEPN7gameswf9characterEPKci) }
    .enable_character 0x003ec270 : { *renderfx-animation.o(.text._ZN8RenderFX10SetEnabledEPN7gameswf9characterEb) }
    .enable_named_character 0x003ee274 : { *renderfx-animation.o(.text._ZN8RenderFX10SetEnabledEPKcb) }
    .set_named_character_visibility 0x003ee2ac : { *renderfx-animation.o(.text._ZN8RenderFX10SetVisibleEPKcb) }
    .activate_animation 0x0041aa40 : { *renderfx-animation.o(.rodata.activateAnimation) }
    .focus_out_animation 0x0044dc50 : { *renderfx-animation.o(.rodata.focusOutAnimation) }
    .disabled_animation 0x0041aa4c : { *renderfx-animation.o(.rodata.disabledAnimation) }
    .goto_character_label 0x003ec218 : { *renderfx-animation.o(.text._ZN8RenderFX9GotoFrameEPN7gameswf9characterEPKcb) }
    .play_character_animation 0x003ec260 : { *renderfx-animation.o(.text._ZN8RenderFX8PlayAnimEPN7gameswf9characterEPKci) }
    .goto_character_frame 0x003ec2dc : { *renderfx-animation.o(.text._ZN8RenderFX9GotoFrameEPN7gameswf9characterEib) }
    .goto_named_frame 0x003ee1a0 : { *renderfx-animation.o(.text._ZN8RenderFX9GotoFrameEPKcib) }
    .goto_named_label 0x003ee1c0 : { *renderfx-animation.o(.text._ZN8RenderFX9GotoFrameEPKcS1_b) }
    .play_named_animation 0x003ee1dc : { *renderfx-animation.o(.text._ZN8RenderFX8PlayAnimEPKcS1_i) }
}
