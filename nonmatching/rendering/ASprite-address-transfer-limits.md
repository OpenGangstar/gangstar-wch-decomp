# Limits of the PaintFModule address-association finding

The verified PaintFModule match in `docs/matches/asprite-paint-fmodule.md`
demonstrates a specific source representation: add a serialized integer table
offset and a typed record's integer byte displacement before adding the blob
pointer. It does not justify regrouping arbitrary pointer arithmetic, changing
pointer fields into offsets, or reopening exhausted source searches.

The coordinator reviewed these bounded follow-up investigations on 2026-11-24.
None supports another source form or adds matching credit. No compiler,
assembler, linker or new compiler dump was run for these transfer reviews.

| Function | Retail address | Actual relevant representation | Conclusion |
| --- | --- | --- | --- |
| Path::Load | 0x00300bc5 | `Structs::Path::values` is a real integer pointer; source and destination address additions already have the native operand association | Four remaining register-selection differences are not an offset/blob association defect |
| AnimObject::IsAnimOver | 0x00349445 | Calls the out-of-line GetAnimDuration API | No owned animation-table expression to change |
| MiniMap::_calculateXYOffset | 0x00329901 | Calls GetFrame, GetFModule and GetModule out of line; relevant native field loads agree | No owned serialized-table address expression to change |
| Script::executeCommand | 0x00339cb9 | Command arguments use actual pointers/fixed views; dynamic dispatch uses a global table and byte index | No serialized-offset/index/blob triple; native and candidate dispatch associations already agree |
| PhysicAttributes::IntersectSegmentWithHeightMap, PhysicInfo overload | 0x0031b9a9 | Genuine pointer tables and unsigned-short index arrays; all three relevant 20-byte record sites already multiply the index before adding the loaded record base | No third serialized integer offset to regroup across a pointer dereference |

## Candidate provenance and limits

Path's authenticated later whole-vector assignment candidate is 200 bytes, as
is native, but still fails at four byte positions. Its two relevant address ADDs
already match exactly. Do not repeat that assignment trial or earlier six forms.

AnimObject's retained 108-byte and later 112-byte candidates remain distinct;
neither is an exact match for native 112. Their relevant receiver/call prefixes
already agree. Missing historical 112-byte objects are not reconstructed proof.

MiniMap's preferred v3 function is 2012 bytes, in a 2016-byte input section;
native function size is 2012. Its retained diagnostic and previously reconstructed
baseline objects are byte-identical, but the reconstructed object is not an
original historical compiler artifact. The existing linked target remains
unmatched. Alignment bytes are not part of the function.

Script's authentic latest corrected candidate is 12320 bytes, superseding the
older six-form preferred 12380 bytes. Preserve its eight later semantic
corrections. Native remains 12636 bytes. The addressing review does not repeat
or validate the entire switch, stack frame or callback graph.

Heightmap's authenticated historical v3/v6 candidate is 4848 bytes versus native
4800. Later selective-cache 4844 and corrected coherent-context 4864 candidates
exist and must not be conflated with that historical pair. The historical
diagnostic's `--no-check-sections` limitation is retained; it is not an accepted
native image. This review supplies no geometry rollback or current global proof.

Detailed source, object and instruction provenance is retained locally under
`_scratch/worker-path-asprite-address-reuse`,
`_scratch/worker-anim-over-asprite-address-reuse`,
`_scratch/worker-minimap-asprite-address-reuse`,
`_scratch/worker-execute-asprite-address-reuse` and
`_scratch/worker-heightmap-asprite-address-reuse`.

Existing source budgets remain spent. Reopen these functions only with a
different concrete compiler, type, API or control-flow finding. None of these
negative reviews changes the accepted 220-byte PaintFModule match.
