# EventManager::_attach and _detach exact matches

```text
OK  _ZN12EventManager7_attachEiP14IEventReceiver  0x00354665  192 bytes
OK SECTION .event_manager_private_attach  0x00354664  192 bytes
OK  _ZN12EventManager7_detachEiP14IEventReceiver  0x00354725  316 bytes
OK SECTION .event_manager_private_detach  0x00354724  316 bytes
```

Both work on the manager's fixed inline arrays: `groups[200]`, each holding an
event ID, a receiver count and a receiver array, plus `groupCount`.

- `_attach` finds the group for the event, creating one at the end if none
  exists, and appends the receiver unless it is already present.
- `_detach` finds the group and the receiver, shifts later receivers down,
  clears the slot at the old count, and when the group becomes empty shifts
  later groups down (an 808-byte `memcpy` per group) and resets the slot at the
  old group count. The clears at `receivers[count]` and `groups[groupCount]`
  happen before the decrements, exactly as retail stores them.

Earlier forms (188 and 292 bytes) acted on the found group inside the search
loop. Retail keeps a separate found index:

```cpp
int index = -1;
for (int i = 0; i < groupCount; ++i) {
    if (groups[i].eventID == eventID) {
        index = i;
        break;
    }
}
if (index < 0) ...
```

That index is the second copy of the group number retail keeps beside the loop
counter (and, in `_attach`, the peeled first iteration's shared tail). In
`_detach` the group is addressed as `groups[index]` each time rather than
through a cached reference.

No header change, hint, inline assembly or register constraint is used.
`memcpy` is bound to its PLT entry. The new sections are named
`.event_manager_private_attach`/`_detach` because `.event_manager_attach` and
`.event_manager_detach` already hold the public wrappers.

Full gate: `python -B tools/build.py --all` exited 0 with 5,509 function,
5,586 section and 181 region comparisons and no mismatch or skip.
