/* Exact reconstructed string setter, coordinate helper and mouse callback. */
SECTIONS
{
    .renderfx_send_event 0x003ef138 : { *renderfx-animation.o(.text._ZN8RenderFX9SendEventERNS_5EventE) }
    .renderfx_send_table 0x0044dea4 : { *renderfx-animation.o(.rodata._ZN8RenderFX9SendEventERNS_5EventE) }
    .renderfx_send_0 0x0044de3c : { *renderfx-animation.o(.rodata.renderfx_send_0) }
    .renderfx_send_1 0x0044de48 : { *renderfx-animation.o(.rodata.renderfx_send_1) }
    .renderfx_send_2 0x0044de58 : { *renderfx-animation.o(.rodata.renderfx_send_2) }
    .renderfx_send_4 0x00449e1c : { *renderfx-animation.o(.rodata.renderfx_send_4) }
    .renderfx_send_6 0x00449e24 : { *renderfx-animation.o(.rodata.renderfx_send_6) }
    .renderfx_send_7 0x0044ce0c : { *renderfx-animation.o(.rodata.renderfx_send_7) }
    .renderfx_send_8 0x0044de64 : { *renderfx-animation.o(.rodata.renderfx_send_8) }
    .renderfx_send_9 0x0044de70 : { *renderfx-animation.o(.rodata.renderfx_send_9) }
 .renderfx_clear_fonts 0x003eee94 : { *renderfx-animation.o(.text._ZN8RenderFX10ClearFontsEPN7gameswf14player_contextE) }
 .renderfx_search_find 0x003eed68 : { *renderfx-animation.o(.text._ZN8RenderFX11SearchIndex4FindEPKc) }
 .renderfx_color_transform 0x003ecf04 : { *renderfx-animation.o(.text._ZN8RenderFX17SetColorTransformEPN7gameswf9characterEjj) }
 .renderfx_member_string 0x003eeb70 : { *renderfx-animation.o(.text._ZN8RenderFX9SetMemberEPKcS1_S1_) }
 .renderfx_local_position 0x003eccd8 : { *renderfx-animation.o(.text._Z16GetLocalPositionPN7gameswf9characterEff) }
 .renderfx_mouse_callback 0x003eca68 : { *renderfx-animation.o(.text._Z38sprite_can_handle_mouse_event_callbackPN7gameswf9characterE) }
}
