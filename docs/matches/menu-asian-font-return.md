# Asian-font return contract

`MenuManager::enableAsianFont(bool)` was declared `void` in MenuManager.h,
although its existing matched implementation explicitly returns `bool`.
The native Language widget calls it at `0x002efc9c` and compares R0 against
zero at `0x002efca0`, using the return value to decide whether glyphs need
preloading. A void declaration cannot represent that existing contract.

Correct only the public declaration to `bool`. The parameter, nonvirtual
method, mangled symbol, storage layout and existing implementation body are
unchanged. This enables the real typed API to replace an opaque proxy in
future Language reconstruction. The Language function remains unmatched;
none of its source variants or branch hints are integrated here.

The already matched implementation still compares the old font setting,
returns false when it is unchanged, updates it otherwise, and returns true.
Its normal native comparison remains:

```text
OK  _ZN11MenuManager15enableAsianFontEb  0x002e3f61  22 bytes
```

The worker first verified the private declaration in MenuManager,
Application and Preferences profiles and their scheduled JNI dependency:
177 function comparisons and 109 section comparisons passed. The
coordinator then corrected the production declaration and ran the complete
native gate: 190 profiles, 5,434 functions, 5,338 sections and 181 regions,
all 10,953 comparisons exact, exit 0. All 1,036 frozen inputs remained
stable throughout the run.

This is a declaration correction to an existing match. No function body,
assembly marker, catalogue status or matched-byte total changes. Matched
remains 61.31%, Fully Linked 20.01%, and all original function identities
remain accounted for. Other proposed Script return-type corrections remain
private where native callers do not distinguish the inferred return type.
