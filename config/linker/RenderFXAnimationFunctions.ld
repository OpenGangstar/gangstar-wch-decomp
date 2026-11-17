vsprintf = 0x001c4070;
SECTIONS
{
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
