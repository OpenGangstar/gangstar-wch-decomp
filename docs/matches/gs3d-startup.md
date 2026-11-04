# GS3DStuff startup

The startup wrapper reuses the SDK string and AI transition-list initialization
already recovered in SaveGame. GS3DStuff initializes the half-vector after the
ten lists, then initializes its light-node array and registers its cleanup.
The array's pointer and counters start at zero. Both flags and the final word
start at one. The cleanup calls operator delete when the ownership flag is set.

The first compile matched both cleanup callbacks and the wrapper. Its
initializer used zero for all six array fields. Tracing the saved initialization
argument through the retail initializer identified the three fields set to one.
The second compile matched all four functions.

```text
OK  __tcf_9  0x002dd091  48 bytes
OK  _Z41__static_initialization_and_destruction_0ii  0x002dcec5  368 bytes
OK  _GLOBAL__I__ZN9GS3DStuff15s_bulletManagerE  0x002dd035  20 bytes
OK  __tcf_10  0x002df605  36 bytes
```
