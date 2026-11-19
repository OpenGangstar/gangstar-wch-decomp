# RenderFX::SetMember(const char*, const char*, gameswf::as_value&)

The 200-byte Thumb function at `0x003eea49` matches the retail library exactly
in its owner and both native consumers. It preserves character lookup, fallback
target lookup, temporary value/string lifetimes and virtual member assignment.
The virtual method returns `bool`; the caller ignores that result.

The reconstruction uses genuine `tu_stringi` composition around a `tu_string`
and the real long-call string copy constructor. The partial method table exposes
the existing slot at offset 28 without moving later methods. No complete engine
character layout, extra helper body, vtable or data definition is invented.

**The existing shared `tu_string` destructor body changes:** its previous
`__builtin_expect` hint is removed, and the condition now follows the authentic
SDK `if (using_heap())`. The free operation, storage and object lifetimes are
unchanged. This permits the original cold inner-string cleanup while preserving
every previous match; no separate destructor clone is used.

```text
OK  _ZN8RenderFX9SetMemberEPKcS1_RN7gameswf8as_valueE  0x003eea49  200 bytes
OK SECTION .renderfx_set_member_value  0x003eea48  200 bytes
```

SHA-256 of the complete native function:
`a27dd88831d4d86bf8fe1faad8f7b206f3fce3b48da29aa3de218f267ae8339e`.

The complete affected closure passes 625 function comparisons and 361
section/region comparisons, including all 114 previous renderer functions and
33 previous section/region checks. The sole direct header user is `menufx.cpp`;
both object consumers are included. All previous allocated payloads and
normalized relocation records remain unchanged. Only the target definition is
newly emitted. Stale target imports are removed rather than masking its real
compiled definition.

The coordinator's full integrated gate passes 190 profiles and 10,596 comparisons
(5,281 functions, 5,134 sections and 181 regions), exit 0, with no mismatches or
skipped profiles. The original source is still incomplete, so these 200 matched
bytes add no Fully Linked credit.

Primary reference: public-domain
[container.h](https://github.com/weihuoya/gameswf/blob/7fdd64b3cdae7ad36ecaf1da023a5cb61cd38a9e/tu-testbed/base/container.h),
`tu_stringi` at lines 1768 onward and the string destructor at lines 1451 onward.
Its SHA-256 is `82f95c2c95fad85594d1d6167e26a76652026ddee3d381212f94698ff781505e`.
Only helper structure is reused; the different upstream storage layout is not
transplanted. The earlier hinted candidate remains documented as a historical
failure under `nonmatching/rendering/`.
