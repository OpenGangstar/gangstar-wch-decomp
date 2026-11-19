SECTIONS
{
    .player_d1 0x003015e4 : { *ai-startup-playertest.o(.text._ZN10PlayerTestD1Ev .text._ZN10PlayerTestD2Ev) }
    ASSERT(SIZEOF(.player_d1) == 208, "Player destructor D1/D2 native extent")
    .player_d0 0x0030362c : { *ai-startup-playertest.o(.text._ZN10PlayerTestD0Ev) }
    ASSERT(SIZEOF(.player_d0) == 212, "Player destructor D0 native extent")
    .player_thunk_d1 0x003015d0 : { *ai-startup-playertest.o(.text._ZThn4_N10PlayerTestD1Ev) }
    ASSERT(SIZEOF(.player_thunk_d1) == 20, "Player destructor D1 thunk native extent")
    .player_thunk_d0 0x00303618 : { *ai-startup-playertest.o(.text._ZThn4_N10PlayerTestD0Ev) }
    ASSERT(SIZEOF(.player_thunk_d0) == 20, "Player destructor D0 thunk native extent")
    .player_vtable 0x004aaf30 : { *ai-startup-playertest.o(.data.rel.ro._ZTV10PlayerTest .rodata._ZTV10PlayerTest) }
    ASSERT(SIZEOF(.player_vtable) == 288, "Player native vtable extent")
}
