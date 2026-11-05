# Animation object lifecycle

AnimObject selects, advances, and draws sprite animations. The native
profile verifies the recovered lifecycle, playback policies, frame
advancement, drawing, and vtable. The constructor calls the retail
Reset address during verification. Reset, IsAnimOver, and the current
bounding rectangle method remain pending.

```text
OK  _Z18PlayPolicy_Onetimefff  0x00349335  4 bytes
OK  _ZN10AnimObject6UnloadEv  0x00349339  6 bytes
OK  _ZN10AnimObject4LoadEv  0x00349341  12 bytes
OK  _ZN10AnimObjectC2Ev  0x00349375  44 bytes
OK  _ZN10AnimObjectC1Ev  0x00349375  44 bytes
OK  _ZN10AnimObjectD1Ev  0x003493a1  32 bytes
OK  _ZN10AnimObjectD2Ev  0x003493a1  32 bytes
OK  _ZN10AnimObject11SetPositionEfff  0x003493c1  8 bytes
OK  _ZN10AnimObject10ChangeAnimEi  0x003493c9  4 bytes
OK  _ZN10AnimObject7RestartEv  0x003493cd  12 bytes
OK  _ZN10AnimObject7SetAnimEi  0x003493d9  40 bytes
OK  _ZN10AnimObject7SetAnimEii  0x00349401  18 bytes
OK  _ZN10AnimObject4DrawEv  0x0034950d  84 bytes
OK  _ZN10AnimObject6UpdateEi  0x00349639  12 bytes
OK  _Z15PlayPolicy_Loopfff  0x00349561  80 bytes
OK  _ZN10AnimObject11UpdateFrameEv  0x003495b1  136 bytes
OK SECTION .anim_vtable  0x004ad2a8  16 bytes
```
