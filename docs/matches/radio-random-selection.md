# Radio random selection

Song and jingle selection reuse the same recovered queue algorithm. Each method
refills an empty station queue, selects a random remaining entry, removes that
entry by shifting the following entries, and returns its ID. The song method
reuses the verified jingle source with the corresponding fields.

The original loop reload uses ordinary pointer arithmetic `*(station + stations)`
to preserve operand order. No integral address conversion, branch hint, or
compiler-output modification is required. Existing declarations and data layouts
are unchanged.

`python tools/build.py string-startup-radiostationcontroller` exited 0 with every
existing function, section, and GOT check preserved:

```text
OK  _ZN22RadioStationController18selectRandomJingleEi  0x003520c1  130 bytes
OK  _ZN22RadioStationController16selectRandomSongEi  0x003522b1  130 bytes
```
