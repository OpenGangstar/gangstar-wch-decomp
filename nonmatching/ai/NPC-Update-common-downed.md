# NPC Update: corrected common downed-state gate, unmatched

Target `_ZN3NPC6UpdateEi`, Thumb `0x002ffe0d`, native 3,012 bytes. The adjacent
source file preserves the tested function statements with repository LF endings, including the earlier
initial chase-category5 correction. It is an unmatched source fragment, not a
replacement for canonical NPC.cpp or a standalone translation unit.

## Proven behavior correction

At native 0x2fff34, unknown28 selects authored/non-authored handling. Non-authored
alive characters pass 0x3005ae/0x3005b6 to the common isDown call at 0x2fff48. Dead
characters also reach this common fresh call after a false initial down test
(300804) or a nonterminal fade (300840/3008ac). A true common down test reaches
300428: UpdateSceneNode, optional lastHitVehicle timer reset, then return.
Only the alpha-zero forceDespawn path terminates before this common gate.

The previous 3,024-byte candidate put this scene-only return inside
`if (unknown28)`, so non-authored alive and nonterminal dead/fade paths skipped
it. Its actual emitted machine CFG independently confirms the omission, not
just its source indentation. All three native isDown GOT literals resolve to
the same verified Character method.

The one approved correction preserves the fade block verbatim under
`if (!unknown28 && isDead() && isDown())`, followed by the common
`if (isDown())` scene-only return. This retains the authored path's one call
and the dead path's separate fresh call after callbacks. No receiver or flag
snapshot, header, compiler option, import or other function changes.

## Earlier common-gate control result and limitations

The earlier tested source body SHA256 is
`2f03fec26287936ef93a98a2325345caa5c95475448b4b4a5cccb462729d68b3`.
That is the actual tested CRLF body. The then-published LF text has SHA256
`18a060aa776fec2aaf4a69b9a2d3be0404b791163bf7ff90c964329b3d753a59`; line-ending conversion is disclosed and no additional compilation is claimed.
Exactly one primary compile/assemble control emitted 3,044 bytes for both the
function and input section, versus native 3,012. Raw target SHA256:
`b3b961e05ce9a7d495800ca8e2277d9d67e2bcbea8bf0bef5a55c77ce5c12837`.
The strict prelink guard reports:

```text
STRICT PRELINK EXTENT {"symbol_size": 3044, "input_section": ".text._ZN3NPC6UpdateEi", "input_section_size": 3044, "native_required": 3012}
STOP: function/inputsection must both equal native3012; native link skipped
```

NPC native linking, target/full-section comparison, old NPC owner/GOT checks and
target-present consumers were skipped. Physics and Character dependencies passed
152 function and 44 section/region checks before the guard. No native candidate
ELF exists and no matching credit is claimed. The behavior correction is retained
even though its emitted code is larger than the older, incorrect candidate.

The coordinator independently extracted the actual 3,044-byte object/section,
verified all 73 other raw definitions unchanged and all 1,065 frozen inputs stable.
The worker also verified 95 other allocated payloads and 60 other semantic
relocation sections. A generated anonymous photographedFlag name hash changed
between compiler runs; its exact pair was narrowly audited with payload/binding
unchanged, without changing object output. Definition/import sets are identical.

The genuine weak PhysicInfo C1/C2 constructor aliases still share one unchanged
96-byte section. Their earlier native placement failure remains unresolved and
was not rerun or bypassed after the target failed its prelink extent check.

## Required context before another experiment

The actual run used the established NDK 1.6r1 GCC 4.2.1 NPC profile and a preserved
private source/type fixture. It is not a new current-main or all-profile gate.
Thirteen private header proposals still differ from canonical: NPC,
RadioStationController, SoundManager, Character, PlayerTest, FactoryProducts,
Quaternion, SceneNode, VideoDriver, GS3DStuff, CarSoundCallbacks, Vehicle and
SpawnPoint. These prerequisites are not silently integrated with this fragment.
The exact full source, headers, baseline 3,024 object, candidate 3,044 object,
commands and frozen hashes remain in the coordinator's local
`_scratch/worker-npc-update-common-downed-control` packet. Its source-only patch
records the precise delta against the earlier corrected fixture.

A future experiment must recover that complete context or deliberately rebase
it with separate preservation gates. Correcting the common gate alone does not
resolve the remaining32-byte excess, constructor placement or matching budget.
No second source form was tried in that control. The later short-circuit control
below preserves its proven common gate. Original assembly and canonical progress
remain unchanged.

## Later null-player short-circuit control

The current published fragment additionally tests `player &&` before comparing
the saved nonnull `initialTarget` with the adjusted player interface. Native
`0x002ffe54` skips that comparison entirely when GetPlayer returns null. The
earlier candidate instead joined its null/non-null pointer conversion before
comparing. Both skip the player-only block for null, so this is a control-flow
reconstruction rather than a behavior correction. It preserves the saved target
across the getter; it does not introduce a fresh target-field read.

One approved source insertion, absent from fourteen recovered definitions,
reproduces the native local skip shape. Candidate `+0x48` now branches to
`+0x52`, followed on the nonnull path by ADD r3,r0,#4 and CMP r4,r3. However,
function and entire input section remain **3,044 bytes**, and frame remains
308 versus native 284. The strict prelink output above is unchanged. No NPC
native link or complete target comparison ran; no matching credit is added.

Raw target SHA256 is
`a8027b874343c919ad967a7fbc01312f3dbea921aed31814c55b765b34e57ce0`.
The current published LF fragment SHA256 is
`f46e0b2910be6d1172ad0b3047ba487c96a5d4a6c93e8e7d096e30b9f80f93c0`.
The coordinator independently extracted the actual object/function/section,
verified its size/hash and changed branch encoding, and checked the public
source differs only by the authorized guard. The JSON companion records these
results and skipped gates.

All 73 previous raw definitions, off-target allocated payloads, imports and real
helpers remain unchanged. All 61 semantic relocation sections, including the
target, retain their meanings. Frozen dependency checks pass 152 functions and 44
sections/regions. The complete 1,065-input fixture authenticates; 71 differing or
missing paths against current main are explicitly disclosed in the private
packet. These are historical-context checks, not a current-main/global build.
No helper import replaces the real PhysicInfo constructor, whose native placement
remains unresolved. The single trial stopped without further source variants.
## Later reconstruction

This earlier fragment is retained as historical evidence. The newer
[storage and callback reconstruction](NPC-Update-storage.cpp) also restores the
post-getVehicle category reload. See the
[reviewed reconstruction notes](../2026-11-24-reconstruction-notes.md) for its
actual failed extent and context limitations. Neither fragment is matched.
