# Radio station controller

The controller layout separates the configured stations and the working
queues. The destructor releases both arrays and the ad lists. The station
reader loads the jingle and song arrays, and the ad selector draws without
replacement until its working list is refilled.

```text
OK  _ZN22RadioStationController14selectRandomAdEv  0x00352069  88 bytes
OK  _ZN22RadioStationControllerD1Ev  0x00352145  144 bytes
OK  _ZN22RadioStationControllerD2Ev  0x00352145  144 bytes
OK  _ZN7Structs12RadioStation4ReadER10DataStream  0x003521d5  112 bytes
```

The jingle and song selectors remain pending. Their closest candidates
differ in the same three Thumb instructions, at offsets 0x32, 0x62 and
0x64 in each function.
