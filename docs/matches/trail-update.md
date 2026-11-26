# Trail::Update exact match

`Trail::Update()` matches all 324 retail bytes at Thumb address `0x003485f1`,
including relocations.

```text
OK  _ZN5Trail6UpdateEv  0x003485f1  324 bytes
```

## Source form

`Update` ages the trail points, drops expired ones, rebuilds the index
buffer for the active segment and sets each point's vertex alpha from its
remaining life.

Details that the retail bytes require:

- **Vertex indexing in the alpha loop.** The two vertices of each point are
  written as `buffer->vertices[i * 2]` and `buffer->vertices[i * 2 + 1]`
  through the array's `operator[]`. Its unsigned index gives a stride-72
  induction variable that outranks the mesh buffer pointer in global
  register allocation. The buffer then takes r7, and the PIC register,
  which conflicts with it, falls to r8 as in retail.

No branch hint, inline assembly, register constraint, output edit or header
change is used. The other Trail.cpp functions keep their bytes.

## Verification

`python -B tools/build.py sdk-startup-trail` passes. A fresh complete build,
`python -B tools/build.py --all`, exited 0 with 5,621 function, 5,709 section
and 180 region comparisons and no mismatch or skip; the previous baseline
was 5,620, 5,709 and 180.
