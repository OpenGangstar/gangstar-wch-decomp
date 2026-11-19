# TrailMgr render: explicit count cache

Unmatched target TrailMgr::Render(), Thumb 0x00349271, native 56 bytes.
Base: main PR #743, 68f0bc30. Patch remains unapplied; no credit.

One separately bounded model caches trailCount before the loop and refreshes
that local only after Trail::Render(), matching the native count-load paths.
Skipped iterations perform no call or store that could alter the count. Null
and positive-life guards, signed index/count, layouts, call and ordinary flags
are unchanged. An ordinary nonvirtual declaration is the sole header change.
This is distinct from the three exhausted guard-only forms; no further form
was tried.

The compiler emits the EXACT same 48-byte function and 48-byte input section
as those earlier forms, SHA256
`aa0563936c93c7c45d5b105880c18eb7b0a2b002e2be9fadfeb34dfd4b3a6594`.
Only the target is newly defined. The strict 56-byte extent guard stops before
linking, exit 3:

```text
Prelink extent/helper guard failed; no linked comparison claimed.
```

No target/native link, body-era old closure or new header-consumer proof is
claimed. Earlier declaration-only preservation remains separate evidence, not
proof of this body. Native code has two loop latches; the candidate merges
them. Explicitly caching the count does not resolve that layout difference.
No padding, hints, stubs, compiler-output edits or overlap bypass are used.

Set WCH_BASE_LIB, apply the patch only in an isolated checkout and run
`python tools/build.py string-startup-trailmgr`. The linker also retains the
native 56-byte assertion. The real external Thumb Trail::Render binding is
kept; no compiled definition is replaced. Production source/header, original
assembly and generated progress remain unchanged. Coordinator review releases
ownership; another local loop/guard variation needs a distinct causal lead.
