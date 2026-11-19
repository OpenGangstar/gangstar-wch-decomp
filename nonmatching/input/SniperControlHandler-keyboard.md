# Sniper keyboard handler: separate key aliases

Unmatched candidate for `SniperControlHandler::onKeyboardEvent(const IEvent*)`,
Thumb `0x0032f201`, native 400 bytes. Baseline production source is PR #740,
`39ae587ea4430b0b566500ef933dd8344e4e9fb3`. No credit or assembly deletion.

All six archived forms retain grouped keyboard aliases. This single bounded
follow-up transfers the separate-case structure that recovered the Character
animation selector. Six pairs receive independent, identical bodies;
existing key operations, pressed/released handling, zoom limits and static
FOV initialization remain intact. Private declarations add the established
FPS-camera accessor and Character friendship used by the historical probe.
No existing function implementation is edited. These declarations are not
accepted shared-header changes and have no broad preservation proof.

The first compile failed because Character::hide and Character::show are
private. Adding the same private friendship as the historical probe repairs
access without changing layout or existing bodies. The one completed source
form emits 476 bytes against the native 400. Only the assigned target is a
new function definition. The strict prelink guard stops before linking,
exit 3; **no linked comparison or old-function preservation is claimed**.

```text
BUILD ai-startup-snipercontrolhandler
{"size": 476, "native_size": 400, "section_size": 476, "new_definitions": ["_ZN20SniperControlHandler15onKeyboardEventEPK6IEvent"], "raw_sha256": "03046e25722782e0b1ee9f20be2206ea504ed81ce23f912dba70fd793280836c", "linked": false}
Prelink extent/helper guard failed; no linked comparison claimed.
```

Apply the patch only in an isolated checkout. With `WCH_BASE_LIB` configured,
`python tools/build.py ai-startup-snipercontrolhandler` is expected to fail
strict section extent/overlap checks. The patch retains the native 400-byte
function, 392-byte dispatch table and four-byte FOV assertions. It does not
move native targets, relax overlap checks or edit compiler output.

Historical variants v2 through v6 have 400-byte function symbols; size alone
never establishes a match, and their old private header context is not this
current candidate context. No numeric reorder or second follow-up was tried.
Further trials require new evidence. Production ARM and Windows sources are
unchanged because this patch remains unapplied.
