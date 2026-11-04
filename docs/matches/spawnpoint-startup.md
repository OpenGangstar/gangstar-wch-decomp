# SpawnPoint startup

The startup code reuses the SDK string, half-vector and AI transition lists
from the previously matched startup functions. It then zeros six spawn centers
and the spawn-point list. The list cleanup deletes each node and advances the
head before clearing the tail and count.

The first attempt matched the wrapper and string cleanup. Assigning each
center's coordinates in field order matched the initializer on the second
attempt. Using the list head as the loop condition matched the list cleanup
on the third attempt.

```text
OK  __tcf_5  0x00306ff9  48 bytes
OK  _Z41__static_initialization_and_destruction_0ii  0x00306e25  448 bytes
OK  _GLOBAL__I__ZN10SpawnPoint16s_innerCenterCivE  0x00306fe5  20 bytes
OK  __tcf_6  0x003070cd  52 bytes
```
