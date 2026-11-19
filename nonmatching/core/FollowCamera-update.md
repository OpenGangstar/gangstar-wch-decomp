# FollowCamera update: recovered facing-helper candidate

This function is **not matched**. The complete native function is 776 bytes at
Thumb `0x00333ab1`; the retained candidate has the same extent but fails its
frame and dataflow comparison. The original assembly remains pending.

Baseline: `cd3301292ca3e38471e30a6a944ae0f9581b7b53` (PR #739). Apply only in an
isolated checkout:

```powershell
git apply --check nonmatching/core/FollowCamera-update.patch
git apply nonmatching/core/FollowCamera-update.patch
$env:WCH_BASE_LIB = 'C:/path/to/your/libsanangeles.so'
python tools/build.py ai-startup-followcamera
```

Expected exit is **1**: both the new function and its full section fail. Existing
matches must remain exact. Do not delete its assembly or credit equal size.

## Bounded family follow-up

PR #739 supplies the real compiled facing helper in this translation unit.
One current-hierarchy adaptation of archived form six replaces its surrogate
Player view with the real `PlayerTest` downcast, uses the existing float
`Character::unknown156` height field, and grants only ordinary friend access.
It changes no layout or existing body. That form emits 784 bytes, as did the
archived sixth candidate; seeing the real facing helper does not inline its
three calls or solve the frame mismatch.

One final helper-reuse form replaces only the pending body's hand-expanded
`followCameraOffset` calls with `up.crossProduct(getFacing())`. Existing matched
helpers remain unchanged. This emits the native 776-byte extent with a 196-byte
frame, versus native 204. All fields, receiver casts and soft-float calls use
current actual interfaces. No new surrogate, branch hint, forced-inline helper,
compiler option, assembly or output edit is introduced.

## Exact result and limits

```text
MISMATCH  _ZN12FollowCamera6updateEf  0x00333ab1
  expected : 4d 46 44 46 f0 b4 c4 69 b3 b0 07 1c 00 2c 00 d1
  actual   : 4d 46 44 46 f0 b4 c4 69 b1 b0 07 1c 00 2c 00 d1
  differs at 0xe
```

The owner preserves all **13 existing function checks, six section checks and
one GOT region check**, including the newly matched 220-byte facing function.
The new target's physical 776-byte section also fails; its strict extent
assertion is necessary but insufficient. The only newly emitted function is
this pending update; complete unlinked target SHA256 is
`2bd82094c8f420f66dfd47c3a8ee078c5970d1bb0aead72912facafc5314bdab`.
The ordinary friend declaration has only this private owning proof; no new
full 190-profile preservation gate is claimed or shared header change accepted.

The six historical forms and these two bounded family follow-ups remain
uncredited. Do not restart their stack-lifetime/ordering search without new
evidence. No production source, header, profile or matched byte changes.
