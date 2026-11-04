# SoundManager lifecycle helpers

The singleton getter allocates the retail 148-byte manager on first use.
Clear uses its virtual deleting destructor and resets the singleton.
Toggle dispatches to the matched init or unInit method according to the
initialized flag.

```text
OK  _ZN12SoundManager11getInstanceEv  0x002d40cd  48 bytes
OK  _ZN12SoundManager5clearEv  0x00352751  36 bytes
OK  _ZN12SoundManager11toggleSoundEv  0x00352789  24 bytes
```
