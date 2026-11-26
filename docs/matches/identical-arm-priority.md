# Identical-arm allocation hints: formatAmount and checkFiles

Two functions match exactly with one *identical-arm* statement each:

```text
OK  _ZNK13StringManager12formatAmountEibb  0x0034b3c5  480 bytes
OK  _ZNK19DataReloaderManager10checkFilesEv  0x0034c119  248 bytes
```

## The technique

GCC 4.2.1 keeps a statement of the form

```cpp
if (test) store; else store;   // both arms identical
```

until after register allocation: it has no tree-level tail merging and no
cross-jumping before reload. After reload the cross-jump pass merges the two
arms, the branch disappears, and the now-unused test is deleted, so no code
is emitted. The test's operand uses still count during allocation, so the
test can raise one value's allocation priority or lengthen its live range.
The arms must be stores (register copies fold away earlier). Each use is
commented in the source.

## StringManager::formatAmount

The function formats an amount with thousands separators and an optional
currency suffix. The block layout already matched (commented one-field
struct tests and a no-code prefetch); only `this` and the buffer address had
each other's callee-saved registers. In the non-dollar currency arm,

```cpp
if (output == szBuffer) *output = 0; else *output = 0;
```

gives the buffer address one more use and `this` a longer live range, which
gives retail's register choice. Its jump table, suffix strings and `nbsp`
pointer are placed at their retail addresses and compared.

## DataReloaderManager::checkFiles

The function reloads monitored files that changed. Two documented no-code
prefetch hints set the branch probabilities, and an identical-arm store on
the success path,

```cpp
if (it == monitoredFiles.end()) item->changed = false; else item->changed = false;
```

ranks the function-pointer value above the static-buffer value, as retail
does. Its two message strings are placed and compared.
