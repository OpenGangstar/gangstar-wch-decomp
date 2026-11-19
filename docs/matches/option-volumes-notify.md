# Menus::OptionVolumes::Notify

The complete 168-byte Thumb function at `0x002eb085` matches retail. It delegates
to Options, handles playlist changes from widget 7, wraps the selected channel
between -2 and the final playlist, and updates the volume widget only when the
selection changes. The algorithm, variables, evaluation counts and source order
remain those of the faithful candidate.

The successful reconstruction uses the canonical MenuManager getter, the real
`Widgets::Volumes` pointer type and its `SetPlaylist` member. The complete
Volumes declaration is copied verbatim from the existing MenuWidget translation
unit, including its real overrides and fields. Both translation units therefore
share the same definition; no new class implementation, constructor, vtable or
data storage is introduced.

Getter-only and likelihood experiments did not match. Reusing the complete
interface fixes the seven remaining register-related bytes without hints,
compiler flags, register constraints, lifetime changes or output modification.

```text
OK  _ZN5Menus13OptionVolumes6NotifyEPK10MenuWidgeti  0x002eb085  168 bytes
OK SECTION .option_volumes_notify  0x002eb084  168 bytes
```

The complete native function SHA-256 is
`b3903b79ffccf5248b13f0831bdc9c886e58ab600952dad9650e575b979e82ba`.
The linker asserts the complete physical 168-byte extent. The only new native
Thumb import is the verified six-byte `SoundManager::getPlaylistCount` at
`0x00352821`, which has no compiled definition in this image's dependency
closure. The compiled Options and Services handlers retain their real
definitions and are not overridden.

The private closure passes 638 function, 413 section and five GOT comparisons
(1,056 total), retaining all 1,054 previous checks. The coordinator's integrated
`python tools/build.py --all` exits 0 across 190 profiles with 5,296 function,
5,193 section and 181 region comparisons: 10,670 successes, without failures or
skips. This adds 168 matched bytes; the original source group remains incomplete,
so Fully Linked credit does not increase.
