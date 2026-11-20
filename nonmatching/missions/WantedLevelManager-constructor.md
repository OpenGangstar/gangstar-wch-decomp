# Wanted-level constructor constants

This unapplied fragment preserves the semantically correct reconstruction of
WantedLevelManager::WantedLevelManager(), C1/C2 aliases at Thumb 0x00342b09,
native 184 bytes. It is a function body for the current named field interface,
not a standalone translation unit or an accepted native build.

A later archived candidate regressed unknown56 and unknown64 to 10000.0.
The coordinator independently read the native little-endian double literals:

| Native address | Bytes | Value | Destination offsets |
| --- | --- | ---: | --- |
| 0x00342b98 | 00 00 00 00 00 88 c3 40 | 10000.0 | 40/44 |
| 0x00342ba0 | 00 00 00 00 00 88 b3 40 | 5000.0 | 48/52 |
| 0x00342ba8 | 00 00 00 00 00 00 00 00 | 0.0 | 56/60 and 64/68 |

Native loads at 0x00342b42/0x00342b44 feed the last four stores. Therefore
both trailing doubles must be 0.0. The initial 10000.0 and 5000.0 values remain
unchanged. Event registration remains 22,16,19 in that order. Offsets 16/20
are not newly initialized. Normal C++ base construction remains implicit.

The corrected body exactly equals the earlier reuse-first reconstruction.
Its historical handoff reports 184 bytes and first difference 0x28, but its
actual object/linked image is missing; that output is not newly reproduced.
The surviving late 176-byte image is semantically incorrect and must not be
used as the preferred valid candidate. Its SHA256 is
`cb4ce1e1246bb78a4d8ddd2a10a4ee9b93e32ab582502446424b07309b4f3197`.
Its actual comparison, independently rerun by the coordinator, begins:

```text
MISMATCH  _ZN18WantedLevelManagerC1Ev  0x00342b09
  expected : 30 b5 29 4a 29 4b 81 b0 7a 44
  actual   : 30 b5 27 4a 27 4b 81 b0 7a 44
  differs at 0x2
```

C2 produces the same failure. A sixth old experiment also added `-fno-gcse`;
that rejected compiler variation is not imported here. Current saved owning
images contain the aliases only as zero-size absolute native imports, which
cannot prove compiled C++ definitions.

No fresh source compile, target comparison of this corrected body, strict
native link, target-present owner closure or transitive header gate is claimed.
The native literal audit and retained-image audit passed; reviewed inputs
remained stable. Existing interfaces already match the old correct context,
so this correction does not authorize another exhausted source-order grid.

No production body, header, marker, catalogue status, compiler flags, matched
bytes or Fully Linked measure changes. Future acceptance still requires the
complete corrected function and affected existing definitions to match.
