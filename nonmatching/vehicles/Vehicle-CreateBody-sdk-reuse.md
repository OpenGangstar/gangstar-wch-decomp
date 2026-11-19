# Vehicle CreateBody: SDK destructor reuse and word enums

Unmatched function `Vehicle::CreateBody()`, Thumb `0x0030fac9`, native 1,044
bytes. Base: main PR #744, `13c21956`. The complete patch remains unapplied;
assembly and progress remain pending. A four-byte size deficit is not a claim
that only four bytes differ, or that the function is nearly byte-identical.

## New ABI evidence and bounded reconstruction

The paired enum-default audit exposed a real difference in the old candidate:
its b2ShapeDef type was stored as a byte. Retail stores the complete word:
`0x0030fbb8` initializes type at object+4 to -1, and `0x0030fbe8` stores 1 to
that same word. The retail factory at `0x003ff338` reads object+4 as a word.
The verified original NDK `-fno-short-enums` default produces those word stores.
Do not infer a byte field from the old candidate or retype it to make it fit.
No member storage or layout was changed in this reconstruction.

With that correct default, the archived fifth owner/lifetime form grows to
1,080 bytes and the sixth stays 1,060; neither fits 1,044. One automatic-object
experiment replaces weak method attributes with weak-symbol pragmas. It emits
1,050 bytes but leaves the referenced D1 symbols GLOBAL, losing the genuine
native weak linkage. It is REJECTED, not a better valid candidate. Initial
validation also found absent native D2 variants and stopped before compilation;
only actual D1 names were used in that rejected form. No symbol or output is
patched to repair it.

The retained reconstruction instead reuses the actual empty SDK destructor
bodies already verified in Character/GS3DStuff, preserving the licensed full
Box2D 2.0.1 constructor source. No synthetic noinline destructor, register pin,
barrier or output edit is added. Automatic objects receive real compiler-
generated weak destructors and keep the native 436-byte frame. Their generated
sizes agree with retail (base D1/D0 24/32, polygon D1/D0 36/44, circle D1/D0
36/44), but those sizes alone are NOT new linked helper-byte proofs.

This SDK-source model with the earlier peeled wheel loop emits 1,064 bytes.
Transferring the previously measured ordinary zero-based wheel loop emits
1,040. Pool 76 bytes, wheel initialization 66, cleanup 28 and frame 436 agree
in size with native. The four-byte code deficit occurs before CreateWheels;
retail's call ends at +0x35a, the candidate at +0x356. These are instruction-size
and dataflow diagnostics, not a relocated native comparison. No operation was
added merely to fill the deficit.

A single grouped-circle declaration model emits 1,028 and is not retained.
An unchanged-body rebase onto the actual current main source/headers reproduces
the complete 1,040-byte object. The genuine minimal prerequisites are the
CreateWheels/Box2DUserInfo declarations, b2Body::CreateShape and b2Vec2::SetZero;
fields, virtual slots and existing bodies remain unchanged. Initial setup
assertions/compilation exposed a friend-declaration text match and the omitted
SetZero/CreateShape members; corrected setup adds only those documented APIs.

The original SDK archive also supplies GetInertia/GetLocalCenter inline APIs.
The retained patch uses those verified interfaces, adapted to the already
recovered storage names, instead of the same direct field reads. This produces
EXACTLY the same complete 1,040-byte object as the direct-field model:
SHA256 `53830deb1d04112adceb9d15ea3c52b3c277c3f5b533afb27fea7223366e4b9b`.
The cached archive is `_scratch/vehicle-create-wheels/Box2D_v2.0.1.zip`, pinned
in the earlier readonly audit; its license remains in VehicleBodyShapes.h.

## Reproduction and remaining proof

Apply Vehicle-CreateBody-sdk-reuse.patch only in an isolated checkout, set up
the normal matching SDK and run:

```powershell
python nonmatching/vehicles/Vehicle-CreateBody-sdk-reuse-probe.py --baselib C:/path/to/libsanangeles.so
```

The probe reuses the actual owning build compiler/assembler path and stops
immediately after primary-object assembly. It deliberately exits **3**, never
links, never compares native bytes and never claims preservation. It can take
--repo and --toolchain paths for an isolated source tree. Tested output:

```text
{"symbol": "_ZN7Vehicle10CreateBodyEv", "native_address": "0x30fac9", "native_size": 1044, "compiled_size": 1040, "input_section_size": 1040, "raw_sha256": "53830deb1d04112adceb9d15ea3c52b3c277c3f5b533afb27fea7223366e4b9b", "native_extent_matches": false, "linked": false, "native_bytes_compared": false, "old_match_closure_checked": false, "credited": false}
COMPILE-ONLY: no native byte comparison or old-match proof.
```

The original 1,044-byte extent requirement is not relaxed. Existing production
matching profiles/linker scripts are not changed by the patch; before any
future full link, the coordinator must place and compare all newly emitted
SDK destructor/vtable definitions without masking them as imports, retain all
old Vehicle/header-consumer comparisons, then verify the complete target and
run the full native gate. None of those combined Vehicle/header proofs is claimed here. The independent
SDK-only proof below covers the reused helper component. New
D2 aliases point at existing destructor bodies but have no separate retail
catalogue entry and receive no progress credit. No engine function receives
new credit from this prerequisite reuse.

Root reviewed and parked the candidate. No more local lifetime/weak-spelling/
loop variants are authorized by this handoff. The explicit imports/pragma
experiment is invalid; retain this genuine SDK-source model for a new causal
lead. No original assembly, generated table, denominator or Windows port file
is changed.


## Independent SDK-only native proof

A separate normal verification image includes only VehicleBodyShapes.h, not
Vehicle::CreateBody. It compiles the same complete SDK classes under the current
ordinary flags and places all real destructor/vtable definitions at retail
addresses. The final frozen run passes six full functions, nine complete
sections (including all three 16-byte vtables) and the full 17,972-byte GOT
region: 16 comparisons, exit 0. Every tracked input hash remains stable.
An independent ELF audit proves all 11 primary function/object symbols,
including the two D2 aliases, remain allocated definitions with their genuine
weak linkage; no ABS import replaces compiled code. No compiled Vehicle code
is present. Unused retail address imports are not compiled definitions.

Exact function/GOT output:

```text
OK  _ZN10b2ShapeDefD0Ev  0x002db47d  32 bytes
OK  _ZN10b2ShapeDefD1Ev  0x002db49d  24 bytes
OK  _ZN12b2PolygonDefD0Ev  0x002df629  44 bytes
OK  _ZN12b2PolygonDefD1Ev  0x002df3f5  36 bytes
OK  _ZN11b2CircleDefD0Ev  0x002f462d  44 bytes
OK  _ZN11b2CircleDefD1Ev  0x002f4441  36 bytes
OK REGION .got+0x360  0x004b03a8  17972 bytes
```

This validates complete-class SDK reuse without the old weak-attribute alias
assembler failure. It does not prove the Vehicle function, all shared-header
consumers or an original retail SDK version. These helpers were already matched
elsewhere and receive zero new progress credit. The private fixture, normal
manifest/linker script, full outputs and proof remain under
_scratch/vehicle-shape-sdk-support-current/. Initial setup omitted GOT comparison;
the final run copies the actual owning .got offset descriptor and verifies it.
A symbol-presence assertion was corrected to distinguish unused ABS retail
imports from actual compiled Vehicle code. No assertion, binding or overlap
guard is bypassed to claim a match.
