# TouchScreenBase touch-ID list

The complete 88-byte getTouchIDList function matches using the actual
STLport allocator-proxy, iterator, node creation, insert and push_back chain.
The licensed restricted ABI view keeps an eight-byte circular sentinel and
12-byte nodes; its allocator and std::less hierarchy reuse existing interfaces.
The public forward declaration remains unchanged. No global std::list primary
is added, and vendor allocation/sort/clear functions remain native imports.

The function inserts active internal point indices 0 through 7, sorts the
list and returns it through the real hidden result pointer. No unused
comparator register value or padding is forced. Seven layout assertions
pass; GCC 4.2.1 retains its two non-POD offsetof warning pairs.

```text
OK  _ZNK15TouchScreenBase14getTouchIDListEv  0x0034cbc1  88 bytes
OK SECTION .touchscreen_id_list  0x0034cbc0  88 bytes
```

SHA-256: `2cf0a7d858d2664d6c387009998e45f2f4bb5dd6bcae12b491f2fe9026fbce74`.
Reproduce with:

```sh
python tools/build.py string-startup-touchscreenbase sdk-startup-touchscreenwin32
```

The derived ARM verification image now uses
the real compiled base method instead of an obsolete external Thumb binding
and explicitly compares that method and section. The iPhone profile has no
compiled-base dependency, so its native binding remains valid.

All prior 34 owning-unit function checks and 44 regions pass. Consumer
closure covers 33 builds, 1,389 functions, 1,872 sections and 33 regions.
The sole added definition is the game method; no helper or data is newly
emitted. All 51 prior allocated object sections, 30 symbolic relocation targets
and 45 prior linked entries are unchanged. Five pre-existing unused Rct aliases
remain baseline-only evidence, not new native matching claims.

The helpers adapt licensed STLport reference source from commit
`e64e7c849b0b659d3e198e4efaed563601e554be`; this does not establish the exact
retail STLport version. No source-unit completion or vendor progress is
credited. Native Windows execution was not tested.
