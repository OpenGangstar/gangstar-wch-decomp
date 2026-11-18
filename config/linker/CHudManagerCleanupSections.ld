/* Shared HUD template cleanup bodies and the no-exception overflow shim. */
puts = 0x001c41b4;
abort = 0x001c42d4;
SECTIONS
{
    .hud_cleanup_0 0x323b68 : { *hud-manager-helpers.o(.text._Z10SafeDeleteI11CDrivingHudEvRPT_ .gnu.linkonce.t._Z10SafeDeleteI11CDrivingHudEvRPT_) }
    .hud_cleanup_1 0x323b88 : { *hud-manager-helpers.o(.text._Z10SafeDeleteI11CWalkingHudEvRPT_ .gnu.linkonce.t._Z10SafeDeleteI11CWalkingHudEvRPT_) }
    .hud_cleanup_2 0x323ba8 : { *hud-manager-helpers.o(.text._Z10SafeDeleteI10CSniperHudEvRPT_ .gnu.linkonce.t._Z10SafeDeleteI10CSniperHudEvRPT_) }
    .hud_cleanup_3 0x323bc8 : { *hud-manager-helpers.o(.text._Z10SafeDeleteI10CCameraHudEvRPT_ .gnu.linkonce.t._Z10SafeDeleteI10CCameraHudEvRPT_) }
    .hud_cleanup_4 0x3238a0 : { *hud-manager-helpers.o(.text._ZSt26__stl_throw_overflow_errorPKc .gnu.linkonce.t._ZSt26__stl_throw_overflow_errorPKc) }
}
