# SoundManager cutscene entry

The restriction predicate reproduces the retail sequence of sound IDs.
Cutscene entry stops the radio track, marks the cutscene active, and
mutes populated channels for music and restricted effects. It stops the
radio again after updating the channels.

```text
OK  _ZNK12SoundManager15isRestrictedSfxEi  0x00352979  220 bytes
OK  _ZN12SoundManager13beginCutsceneEv  0x003533b9  188 bytes
```

The exit candidate remains pending. Its four indexed Thumb loads differ
at offsets 0x50, 0x52, 0x8a and 0x8c.
