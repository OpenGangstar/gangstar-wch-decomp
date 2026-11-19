# RenderFX::SetMember(as_value&) composition candidate

This is an uncounted candidate for the 200-byte Thumb function at
`0x003eea49`. Its assembly file remains present. The accompanying
[patch](renderfx-set-member-value.patch) preserves the source, native placement
and comparison selectors against source baseline `5012b833`.

The public-domain gameswf
[container.h](https://github.com/weihuoya/gameswf/blob/7fdd64b3cdae7ad36ecaf1da023a5cb61cd38a9e/tu-testbed/base/container.h)
declares `tu_stringi` as composition of a `tu_string`, with a constructor
accepting `const tu_string&`. Earlier candidates used inheritance or fabricated
shared storage bases. This candidate uses the real composition and copy
constructor receiver. The existing canonical string destructor and its branch
hint are unchanged. The virtual `set_member` signature returns `bool` and takes
the string and value by const reference; its result is unused.

Apply only in a separate checkout with the matching baseline:

```sh
git apply --check --ignore-space-change nonmatching/rendering/renderfx-set-member-value.patch
git apply --ignore-space-change nonmatching/rendering/renderfx-set-member-value.patch
python tools/build.py renderfx-animation
```

Exit 1 is expected. All 114 previous renderer function comparisons and 33
section/region comparisons passed in the private trial. The target and its
whole section fail; downstream consumers were skipped, so no consumer pass is
claimed. The patch retains their checks and removes only stale retail imports
for the newly compiled target. It does not remove the target assembly file.

```text
MISMATCH  _ZN8RenderFX9SetMemberEPKcS1_RN7gameswf8as_valueE  0x003eea49
  expected : 31 1c ff f7 4f fa 00 28 28 d0 06 1c 00 2e 0e d0
  actual   : 31 1c ff f7 4f fa 00 28 27 d0 06 1c 00 2e 11 d0
  differs at 0x38
```

Both native and candidate have an 80-byte frame: the fallback value occupies
SP0..39, the inner string SP44..59, the outer string SP60..75 and the stack
guard SP76. Genuine composition fixes the old constructor argument-order
difference. The remaining observed layout difference starts with inner-string
cleanup: native branches to a cold heap-free block; the candidate places the
free inline. The canonical destructor's existing heap-likely hint is a strong
explanation, but no isolation trial proves it the sole cause. Do not replace
the member destructor with an invented unhinted clone.

The complete candidate has 89 positional byte differences, largely reflecting
shifted blocks and branch/call displacements. Equal size and correct behavior
are insufficient for credit. Only the target definition is newly emitted; no
helper, vtable or data definition is added. Compiler flags, existing bodies,
native addresses and strict section checks remain unchanged.
