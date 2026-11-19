/* Actual native Volumes localization and all14 literal spans. */
SECTIONS
{
    .widgets_volumes_localization 0x002ef414 : { *ai-startup-menuwidget.o(.text._ZN7Widgets7Volumes18UpdateLocalizationEv) }
    ASSERT(SIZEOF(.widgets_volumes_localization) == 736, "Volumes native736 exact extent")
    .volumeSfxText 0x0041b430 : { *ai-startup-menuwidget.o(.rodata.volumeSfxText) }
    .volumeSfxSlider 0x0041b448 : { *ai-startup-menuwidget.o(.rodata.volumeSfxSlider) }
    .volumeMuteOn 0x0041b1dc : { *ai-startup-menuwidget.o(.rodata.volumeMuteOn) }
    .volumeSfxMute 0x0041b468 : { *ai-startup-menuwidget.o(.rodata.volumeSfxMute) }
    .volumeValueFormat 0x00406338 : { *ai-startup-menuwidget.o(.rodata.volumeValueFormat) }
    .volumeSfxValue 0x0041b488 : { *ai-startup-menuwidget.o(.rodata.volumeSfxValue) }
    .volumeMusicText 0x0041b4a8 : { *ai-startup-menuwidget.o(.rodata.volumeMusicText) }
    .volumeMusicSlider 0x0041b4c0 : { *ai-startup-menuwidget.o(.rodata.volumeMusicSlider) }
    .volumeMusicMute 0x0041b4e4 : { *ai-startup-menuwidget.o(.rodata.volumeMusicMute) }
    .volumeMusicValue 0x0041b504 : { *ai-startup-menuwidget.o(.rodata.volumeMusicValue) }
    .volumePlaylistTitle 0x0041b528 : { *ai-startup-menuwidget.o(.rodata.volumePlaylistTitle) }
    .volumePlaylistFormat 0x0041b548 : { *ai-startup-menuwidget.o(.rodata.volumePlaylistFormat) }
    .volumePlaylistValue 0x0041b568 : { *ai-startup-menuwidget.o(.rodata.volumePlaylistValue) }
    .volumeMuteOff 0x0040d120 : { *ai-startup-menuwidget.o(.rodata.volumeMuteOff) }
}
