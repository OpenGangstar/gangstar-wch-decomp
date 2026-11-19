# Follow and vehicle camera facing vectors

`FollowCamera::getFacing() const` returns a zero vector when no owner is attached.
Otherwise it obtains the owner's position, subtracts the camera position,
computes the cross product with the upward axis, normalizes it, and returns the
result through the original vector value ABI.

The accepted source reuses the existing modified-fork `up.crossProduct(facing)`
implementation. The saved hand-expanded candidate used equivalent signed
products, but the recovered helper restores the native compiler dataflow. No
shared vector implementation, existing function body, compiler option or class
layout was changed. No branch hint, assembly or output rewriting is used.

The owning profile now links the actual compiled function instead of an
external Thumb import. Its complete physical section has a strict 220-byte
extent assertion and an independent native comparison:

```text
OK  _ZNK12FollowCamera9getFacingEv  0x003336ad  220 bytes
OK SECTION .follow_camera_facing  0x003336ac  220 bytes
```

The complete executable function SHA256 is
`2a75b747322e141e91c1da4ed8ead1376e86ba0f45f8b70e85a0ded927e4aa9c`.
The owner retains twelve existing function checks, five section checks and its
full GOT region check. The native function is real executable code, not an
absolute retail substitute. FollowCamera::update remains pending, so this
match alone does not complete the compilation unit for Fully Linked progress.

## VehicleCamera sibling

The native VehicleCamera function has the same algorithm and 220-byte extent.
It reuses the accepted source with the existing `vehicle` field as its receiver.
The header gains only the missing ordinary private method declaration; no
virtual slot, class storage or existing function body changes.

```text
OK  _ZNK13VehicleCamera9getFacingEv  0x00335769  220 bytes
OK SECTION .vehicle_camera_facing  0x00335768  220 bytes
```

The complete executable function SHA256 is
`b4aa33ea50b713d4bf9a23ab4fa9b4c7338f1db7a099d0fd7ecd3f3f06c655af`.
Its owner likewise retains twelve existing function checks, five section checks
and one GOT region check. Initial setup retained the old external FollowCamera
binding and correctly rejected replacing a compiled symbol; that import was
removed. The first VehicleCamera adaptation did not compile until it used the
actual vehicle field and gained its missing nonvirtual declaration. Neither
setup correction changed emitted compiler output or existing function bodies.
Both functions are ordinary C++ and share the already recovered fork helper.

## Integrated verification

`python tools/build.py --all` passed all 190 profiles: 5,429 function checks,
5,333 section checks and 181 region checks, totaling **10,943 native comparisons**.
All 959 source/configuration/tool/nonmatching input hashes remained stable
throughout the gate. No function or profile failed or was skipped. Independent
executable extraction confirms both function hashes above in the integrated
images. The two assembly markers are removed only after this review.

This family adds two functions and 440 matched bytes. It leaves incomplete
camera units incomplete for Fully Linked accounting. Existing matched function
bodies, compiler options and native Windows port code are unchanged.
