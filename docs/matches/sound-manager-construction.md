# SoundManager construction

Both retail constructor aliases at `0x00353525` match their entire shared
680-byte body and section. Native/linked SHA256:
`c43032e1d4bb02b50f9bbc9d6a08c2894f43af2dcf9456cb28d8bc32e8d16992`.
Raw object SHA256:
`9235e6231cfb1486dac653a95feb1c50d0cd691cfd51f5e4c372ba5227744682`.

After six historical forms, the coordinator authorized one bounded experiment:
replace only four pointer-zero stores in each newly allocated row with ordinary
`memset(channels,0,4*sizeof(CSound*))`. Native code allocates exactly 16 bytes,
zeros the four pointers without any intervening callback, then reloads the count.
The original loop had seven differing scheduling bytes. The ordinary constant
memset expands to the complete native instruction sequence, with no emitted
memset call, builtin forcing, inline assembly, barriers, pinned registers,
compiler-flag changes or output edits. No eighth source search was performed.

The reconstructed constructor preserves frequency allocation, resource-name
classification, original sound-pool construction, radio construction and final
field initialization. The four source string payloads match complete native
sections at `0x00436374`, `0x0043637c`, `0x00436380` and `0x00436388`.

## Coherent class declarations

Native-backed shared views restore the four-byte floating field at offset 60,
three bytes at 141 followed by the word at 144, SoundEntry defaults and the
ordinary RadioStationController constructor declaration. Original layout is
unchanged: SoundManager 148 bytes/alignment 4, SoundEntry 12 bytes and
RadioStationController 32 bytes.

The initial private reconstruction used incomplete local pool class views.
Integration instead moves the existing complete StaticSound, StreamingSound and
two pool declarations into four shared headers, included at their original
locations by their owning source files. SoundManager includes these same
complete declarations. All original function bodies are unchanged; no duplicate
incompatible class view is introduced by this reconstruction.

## Verification

The worker first passed the current 71-function/75-region owner baseline and
header-only gate, then the matching candidate's 73-function/80-region checks.
All 36 affected profiles also passed 2,281 function, 2,182 section and 35 region
checks with 1,068 stable inputs. These are private prerequisite checks, not proof
of the later coherent-header integration.

The coordinator independently rebuilt the constructor and both existing sound
owner profiles after extracting the complete declarations, then ran the final
combined 191-profile gate. It passed 5,443 functions, 5,353 sections and 181
regions: all 10,977 comparisons exact, exit 0, all 1,072 inputs stable.

Exact constructor comparison lines:

```text
OK  _ZN12SoundManagerC1Ev  0x00353525  680 bytes
OK  _ZN12SoundManagerC2Ev  0x00353525  680 bytes
OK SECTION .soundmanager_ctor  0x00353524  680 bytes
OK SECTION .memorySoundPrefix  0x00436374  8 bytes
OK SECTION .musicSoundPrefix  0x0043637c  4 bytes
OK SECTION .swavSuffix  0x00436380  8 bytes
OK SECTION .wavSuffix  0x00436388  8 bytes
```

Only the two verified constructor assembly markers are removed. The catalogue
counts both original aliases, preserving its existing identity and denominator
conventions; they share one 680-byte machine-code body and are not presented as
two different implementations. SoundManager still has pending functions and
receives no Fully Linked credit. No Windows port or launcher files change.
