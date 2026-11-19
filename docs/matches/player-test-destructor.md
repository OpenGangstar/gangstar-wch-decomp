# PlayerTest destructor family and genuine inheritance

Five destructor entries now match with `PlayerTest : IMapTrackable, Character`,
replacing the two provisional complete interface classes. The primary marker
base is at offset 0 and Character at +4. Legacy interface names remain typedefs
of the real classes, with compatibility accessors retained.

The existing Vehicle marker interface and three-float SaveVector3 helper were
extracted unchanged into shared headers. Context records now occupy their
observed storage at 452–483; metric methods use the corresponding words instead
of duplicate scalar declarations. Same-word aliases preserve existing readers.

Independent legacy/proposed compiler probes agree: Player 516 bytes, Character
296, Vehicle 1,012, alignment 4. Player photo targets remain at 484, context
values at 508, and the two 16-byte context records at 452. The Player size is a
legacy compatibility measurement, not an independently recovered retail
allocation extent.

## Preserving existing functions

The existing 668-byte photo function required a matched-body rewrite under the
genuine hierarchy. A standard C++ full-expression initializer keeps the actual
value-return temporary alive through Y/Z/X subtraction and constructs the used
direction vector. Both native stack objects are retained without default-zero
stores, dummy storage, new helpers or a reference-return ABI guess. Pointer and
scalar assignments precede their uses; temporary pointers are not used after
the initializer completes. Original lexical source is not claimed.

The first copy-initialization trial merged storage and emitted 676 bytes; it
failed strict extent and was not linked. The final initializer reproduces every
native photo byte. Required existing-body changes are explicitly scoped:

- Character constructor initialization uses the same three zeros through facing.
- Five Player metric methods use the existing context-record words; teleportTo
  and snipe call the genuine position APIs directly.
- CopController, CopVehicleController, GuardController, SpawnPoint and SaveGame
  replace legacy position wrappers with native GetPosition/SetPosition APIs.
- FPSCamera's owner helper uses the real base-to-derived conversion, preserving
  null handling and the native four-byte adjustment.
- NPC weapon setup and InfoHelp retain native initialization order through
  independent local declaration ordering. Their algorithms remain unchanged.
- CameraVariants and Rocket forward declarations use the actual Character alias.

An earlier full migration run exposed CopController wrapper-copy growth. A later
run exposed two reversed InfoHelp initialization bytes. Those failures are
retained; neither was credited as a successful gate.

## Exact verification

Both the isolated current-checkout migration and the final integrated checkout
pass `python tools/build.py --all`: **190 profiles, 10,687 comparisons**
(5,304 functions, 5,202 sections and 181 regions), exit 0, no failures or skips.
Final output includes:

```text
OK  _ZN10PlayerTestD1Ev  0x003015e5  208 bytes
OK  _ZN10PlayerTestD2Ev  0x003015e5  208 bytes
OK  _ZN10PlayerTestD0Ev  0x0030362d  212 bytes
OK  _ZThn4_N10PlayerTestD1Ev  0x003015d0  20 bytes
OK  _ZThn4_N10PlayerTestD0Ev  0x00303618  20 bytes
OK  _ZN10PlayerTest5photoEP6Weapon  0x00303079  668 bytes
OK SECTION .player_vtable  0x004aaf30  288 bytes
```

Independent integrated ELF extraction confirms real executable definitions,
complete native function equality, and all 288 compiled vtable bytes. No compiled
definition is replaced by an absolute binding. Photo's SHA-256 is
`463af1e6e9f409295f5be0f53ce2056c71a848722836f9e4bd1f16cce2df2813`;
the vtable SHA-256 is
`c941a63deda4470dc3a12ebba9f822ccf8eed0bd384f109660161a96916d5502`.

The destructor retains the documented GNU hint
`__builtin_expect(photoTargets.free_when_destroyed, 1)`. Its complete native
body and every affected existing match pass the full gate, satisfying the
maintainer's branch-hint condition. No inline assembly, register pin, barrier,
compiler-output edit or optimization-flag change is used.

The five assembly files were removed only after integrated verification.
Progress is regenerated normally: **4,259/4,661 entries, 342,198/575,264 code
bytes (59.49%)**. D1/D2 aliases follow existing catalogue accounting; no new
alias convention was introduced. PlayerTest remains incomplete, so Fully Linked
stays **110,400 bytes, 19.19%, 123/208 report units**. Near misses receive no
credit. Windows port and launcher files were not changed or executed.
