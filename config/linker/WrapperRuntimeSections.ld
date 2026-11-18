/* Reconstructed wrapper functions and the complete original browser URL. */
SECTIONS
{
    .wrapper_init 0x002d2758 : { *path-name.o(.text.appInit) }
    .wrapper_resource_path 0x004134e4 : { *path-name.o(.rodata.wrapper_resource_path) }
    .wrapper_deinit 0x002d26f0 : { *path-name.o(.text.appDeinit) }
    .wrapper_accelerometer 0x002d25a8 : { *path-name.o(.text.appOnAccelerometer) }
    .wrapper_pause 0x002d2730 : { *path-name.o(.text.appPause) }
    .wrapper_run 0x002d269c : { *path-name.o(.text.appRun) }
    .wrapper_touch 0x002d2510 : { *path-name.o(.text.appOnTouch) }
    .wrapper_device 0x004b671c (NOLOAD) : { *path-name.o(.bss.device) }
    .wrapper_key_up 0x002d2654 : { *path-name.o(.text.appOnKeyUp) }
    .wrapper_key_down 0x002d2678 : { *path-name.o(.text.appOnKeyDown) }
    .wrapper_application 0x004b6720 (NOLOAD) : { *path-name.o(.bss.app) }
    .wrapper_app_resume 0x002d24f4 : { *path-name.o(.text.appResume) }
    .wrapper_launch_twitter 0x002d2714 : { *path-name.o(.text.launchTwitter) }
    .wrapper_twitter_url 0x00413498 : { *path-name.o(.rodata.wrapper_twitter_url) }
}
