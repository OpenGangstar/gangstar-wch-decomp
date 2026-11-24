# Current-model Vehicle AI integration, still unmatched

The accompanying patch prepares the existing value-timing method against the
current genuine model. It changes only three files: real PhysicInfo/Randomizer
includes plus the method definition, its ordinary nonvirtual declaration, and
Vehicle's friend access to LevelObject. No canonical change has been applied.
The public patch normalizes the private patch's CRLF endings to LF, omits one
optional empty-context prefix, and passes `git apply --check`. The original CRLF
patch failed that check against LF sources; its blank context marker also triggered
a whitespace warning before normalization. Both hashes and these formatting distinctions are recorded in the JSON's
`current_context_replay` section.

One original current-profile frontend/assembler pair succeeded, retaining
`-fno-short-enums`, current const helper declarations and the genuine hierarchy.
All 1142 frozen inputs/tools remained stable during the run. The method text is
identical to the previously tested 3224-byte fragment after explicit line-ending
normalization; it was not redesigned for this replay.

The current function and complete input section are both **3224 bytes versus
3220 native**, frame 476. The strict extent gate fails. No linker or relocated
target comparison ran; this is not a four-byte mismatch claim or a matched unit.
All 202 current baseline and 197 historical function payloads are preserved.
Current baseline preservation also covers 230 nonempty allocated payloads, 1688
semantic references and all 323 imports, with five expected imports added.

Generated anonymous names and local labels changed. Explicit correspondences
cover `.L982/.L977` to `.L996/.L991` and historical `C.131`/current `C.145` to
`C.146`, including its constant section. Raw unmapped failures are retained;
no compiler output was rewritten. The historical comparison additionally
discloses the former undefined Vehicle vtable becoming the genuine current
188-byte definition. That is not identical historical symbol metadata.

The real used PhysicInfo constructor emits normally: C1/C2 share one 96-byte
physical body, whose unrelocated bytes equal both existing genuine providers.
Reset remains a real weak GOT dependency. Retail has a named C1 and Reset, but
no named C2; no separate native C2 credit is claimed. Future linking must place
and verify this genuine support without replacing emitted definitions with
retail-address imports. The other four new imports are the existing AI
dependencies, not invented helpers.

Compared with the historical 3224-byte candidate, ten raw bytes change in eight
instructions. They permute Y/Z register transport on three incoming paths and
the corresponding shared stores; final SP280/SP284/SP288 still contain XYZ.
GetPlayer field offsets 312/368/372 and both recovered lateral arithmetic
windows remain unchanged. No new ABI or semantic correction is established.

Detailed source/input, constructor, raw/mapped preservation and command receipts
remain in `_scratch/worker-vehicle-ai-current-prepare/`; the ten-byte proof is in
`_scratch/worker-vehicle-ai-context-delta/`. The C++ fragment and older receipts
remain separately identified. Assembly markers, canonical source, progress and
Fully Linked credit are unchanged.
