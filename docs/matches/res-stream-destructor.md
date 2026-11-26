# ResStream destructor exact match

`ResStream::~ResStream()` matches retail exactly in all three forms, and its
vtable is placed and compared at `0x004ad698`.

```text
OK  _ZN9ResStreamD0Ev  0x0034eed9  60 bytes
OK  _ZN9ResStreamD1Ev  0x0034ef15  56 bytes
OK  _ZN9ResStreamD2Ev  0x0034ef15  56 bytes
OK SECTION .resstream_vtable  0x004ad698  48 bytes
```

## Source form

```cpp
ResStream::~ResStream()
{
    Close();
    char* d = data;
    if (d) {
        data = d;   // no-op write-back, commented in the source
        delete[] d;
    }
}
```

The earlier form differed only in the register used for the vtable store.
With exactly three block-local values, GCC 4.2.1's local allocator sorts
them with a fixed three-element sequence that leaves the PIC base in the
wrong register. Storing the just-loaded pointer back inside the delete block
reuses the field-offset value there, so that value becomes non-local. With
two local values left, the sort gives retail's registers. Postreload removes
the store, so it emits no code.

## Integration

The destructor is the class's key function, so the vtable is now emitted in
this unit; it matches retail byte for byte. The GameObjectManager unit, which
links this object, places the destructors and vtable at their retail
addresses instead of binding the destructor externally.
