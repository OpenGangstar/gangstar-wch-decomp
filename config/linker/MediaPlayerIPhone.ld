OUTPUT_FORMAT("elf32-littlearm")
OUTPUT_ARCH(arm)
INCLUDE build/matches/media-player-iphone/retail-symbols.ld
SECTIONS
{
    .media_play_empty 0x002d3be0 : { *media-player-iphone.o(.text._ZN17MediaPlayerIPhone9playMovieEPKc .gnu.linkonce.t._ZN17MediaPlayerIPhone9playMovieEPKc) }
    .media_stop_empty 0x002d3be4 : { *media-player-iphone.o(.text._ZN17MediaPlayerIPhone9stopMovieEv .gnu.linkonce.t._ZN17MediaPlayerIPhone9stopMovieEv) }

    .media_trace 0x002d3be8 : { *media-player-iphone.o(.text._ZNK17MediaPlayerIPhone6_traceEPKc) }
    .media_ctor 0x002d3c04 : { *media-player-iphone.o(.text._ZN17MediaPlayerIPhoneC1Ev .text._ZN17MediaPlayerIPhoneC2Ev) }
    .media_category 0x00413af8 : { *media-player-iphone.o(.rodata.media_player_category) }
    .media_enter 0x00413b0c : { *media-player-iphone.o(.rodata.media_player_enter) }
    .media_leave 0x00413b24 : { *media-player-iphone.o(.rodata.media_player_leave) }
    .got 0x004b0048 : { *(.got.plt) . = 0x360; *(.got) }
    .verification 0x00600000 : { *retail-got.o(.text) }
}
