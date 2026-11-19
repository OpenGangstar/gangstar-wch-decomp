# PlayerTest::Respawn: recovered-hierarchy candidate

This candidate is **not matched** and must not be credited. The original
544-byte assembly marker remains pending. The patch is outside production.

The source/configuration baseline is `647af517e490e93bd17904c9c8db18fe1cac7c79`
(PR #738). Subsequent documentation commits do not change these inputs. Apply
only in an isolated checkout:

```powershell
git apply --check nonmatching/ai/PlayerTest-Respawn.patch
git apply nonmatching/ai/PlayerTest-Respawn.patch
$env:WCH_BASE_LIB = 'C:/path/to/your/libsanangeles.so'
python tools/build.py ai-startup-playertest
```

The expected command exit is **1**: the target and its section fail. Existing
matching functions and sections must retain their successful comparisons.

## Reconstruction and scope

One bounded adaptation of the archived sixth candidate uses the recovered
`PlayerTest`/`Character` hierarchy. The secondary Character receiver invokes
`GetPosition()` directly, matching the native slot call, instead of the old
proxy `position()` interface. The genuine inherited flags and next-animation
fields replace a raw offset store and obsolete field spelling. No header,
existing function, compiler option or generated table changes are included.
The first adaptation did not compile until the old `nextAnimation248` spelling
was replaced by the recovered `Character::nextAnimation` field.

The new target needs explicit Thumb metadata for `_processWantedLevel`,
`Factions::init`, `GameObjectManager::getObjectList` and `GameObjectList::GetFirst`.
These imports are not compiled in this profile's closure. Without metadata,
some calls use BLX to Thumb destinations. The private profile corrects their
modes and adds the target, its section comparison and a strict 544-byte extent
assertion. No compiler output is edited.

## Verified result

The final private native link passes all **83 existing owner function checks,
24 section checks and one region check**. Dependencies also pass. This is not
a new full-profile gate or a successful target proof. Both target and target
section fail at offset `0x46`:

```text
MISMATCH  _ZN10PlayerTest7RespawnEv  0x003049e5
  expected : 42 46 20 1c d3 58 98 47 00 22 f0 23 f2 50 d4 23
  actual   : 42 46 20 1c d3 58 98 47 f0 23 f7 50 d4 23 5b 00
  differs at 0x46
```

The function and physical section are both 544 bytes. All 37 call instructions
have native order, mode and immediate destination or register operand. That
ledger alone does not prove their argument dataflow or virtual-slot selection.
The first difference reuses the live zero in R7 for clearing fields, whereas
native materializes another zero in R2. Subsequent instructions shift and other
allocation differences remain. Only 114 of 544 bytes agree at the same offsets;
this metric earns no matching credit. The complete unlinked target SHA256 is
`f53735e5466e9d7d75ddccc65238b5a65efc99925b354ad55f950190628cda80`.

The six historical forms remain archived. This bounded hierarchy adaptation
does not resolve the match; do not restart their ordering/zero-allocation
search without new evidence. No gameplay or application execution was used.
