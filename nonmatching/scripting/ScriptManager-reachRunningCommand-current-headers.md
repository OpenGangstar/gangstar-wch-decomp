# Running-command dispatch: current-header replay

The adjacent unapplied patch targets the 112-byte
`ScriptManager::reachRunningCommand(int)` at Thumb address `0x0033d271`.
It remains pending, with its assembly marker intact and no match credit.

The earlier six-form search covered loop structure and likelihood variants.
The current coherent Script/ScriptManager interfaces and enum-width profile
justify a bounded replay of the archived source, rather than another grid.
The plain archived source compiles to 122 bytes and fails the strict native
link placement because it overlaps the following `missionIdle` section;
that attempt exits 2 before any complete target comparison or old closure.

The archived best form compiles to 112 bytes and reproduces the exact prior
linked hash `5d58ffb92afe3530e878f2af66b80b768c55bcfb3e10c569a75853497009e8a3`.
Ten byte differences remain. Its canonical build exits 1:

```text
MISMATCH  _ZN13ScriptManager19reachRunningCommandEi  0x0033d271
  expected : f0 b5 57 46 46 46 c0 b4 06 1c 80 68 81 b0 8a 46
  actual   : f0 b5 57 46 46 46 c0 b4 05 1c 80 68 81 b0 8a 46
  differs at 0x8
```

The new `.handler` section also fails. All 143 existing functions, 133
existing sections and the global GOT region pass. The coordinator checked
the actual linked function size and hash, then independently repeated the
native function comparison. The remaining register allocation and loop
comparison differences are not corrected by the current headers.

The retained source contains a GNU likelihood hint from the archived best
form. It remains quarantined and unaccepted; the hint has not established
a byte match. No production function or shared header is changed.

For reproduction, apply the adjacent patch in an isolated checkout and run
`python tools/build.py script-manager-helpers --baselib <retail-library>`
with the original configured toolchain available. The patch includes its
source declaration, manifest selection, native placement, allocation PLT
binding and external Thumb callee binding. The JSON retains the exact
comparison output and differing offsets. Further source work requires new
evidence about the original allocation or source context.
