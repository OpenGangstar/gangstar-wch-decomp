# Shooting with the canonical player event

Unapplied current-context candidate for Vehicle::shoot. It replaces an old
manual two-stage event lifetime workaround with the unchanged canonical
PlayerEvent constructor using IEvent(22). Only a private nonvirtual NPC
isHostileTo declaration and native helper placements are prerequisites.

Existing 188 functions/112 regions remain exact. Real PlayerEvent D0/D1 and
three complete sections add two function/three region checks, totaling 190/115.
The actual vtable symbol is 20 bytes in a 24-byte aligned section; all 24 native
bytes are checked. Actual D2 shares D1 address/section/36 bytes; it receives
no distinct native-function credit. No compiled-name mapping or synthetic
alias bypass is used. Initial erroneous 20-byte section assertion and rejected
non-tcf mapping attempt are preserved as harness failures, then corrected.

The coordinator independently replays the public patch in a fresh current-root
clone: 1116/native1140 bytes, verifier exit 1,190 functions/115 regions exact,
884 stable inputs. The target and its complete section still fail. No original
helper body is replaced by a native import. Sixteen model measurements remain
unchanged in the private prerequisite probes.

No production body, assembly marker, catalogue status or matched/Fully Linked
credit changes. These artifacts preserve accurate partial work for a future
evidence-based attempt. Verify each candidate independently in a separate
checkout; their source-model and preservation scopes must not be combined.

```text
MISMATCH  _ZN7Vehicle5shootEv  0x00310909
  expected : 56 46 4d 46 44 46 f0 b4 db 49 b1 b0 07 1c 89 46
  actual   : 56 46 4d 46 44 46 f0 b4 d6 49 a9 b0 06 1c 89 46
  differs at 0xc
```

Linked SHA256: `683e3c4049171ab5e3158872ae3103ebd9d0aaf8950c26f969a6a7f3957ec44b`.
