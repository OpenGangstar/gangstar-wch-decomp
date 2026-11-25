# Claude handoff — Gangstar: West Coast Hustle

Prepared 2026-11-25 (Pacific/Auckland). The user asked Codex to finish current
work and hand over to Claude. Do not start another Codex worker wave.

## Objective and rules

Continue the complete, 100% byte-matched C/C++ decompilation of the original
game code: 4,550 functions and 561,716 bytes. This goal is NOT complete.
Dependencies are excluded, but all 17,703 retail entries remain catalogued.
Read AGENTS.md completely, DECOMPILATION-AGENT.md, docs/BUILDING.md and
docs/WORK-ORDER.md before changing anything.

Take over as sole coordinator. Only the coordinator assigns ownership,
integrates, commits, pushes, opens PRs or merges. Workers must not spawn workers
or publish Git changes. Record binary, address and function ownership in
DECOMP_TASKS.md before assigning work. No Codex workers are active at handoff;
historical assignments are released. Recheck your runtime capacity: AGENTS asks
for four workers where possible; Codex allowed only three plus its coordinator.

Use reuse-first selection. Default first pass: six candidate compile/compare
iterations; stop after three materially different forms emit identical unmatched
bytes. Revisit parked work only with new evidence or a specific bounded
escalation. Do not play the game. Application packaging belongs to OpenGangstar's
launcher; keep Windows porting separate from matching work.

The user already authorized necessary downloads/Git tools, reviewed commits
and pushes, consolidated PRs roughly hourly while actively working, and merging
after exact-head validation, successful CI, no conflicts and a fresh base.
Do not request those permissions again. Never commit game data, proprietary
tools or generated binaries. Never edit compiler output or hand-edit config/*.tsv.

## Workspace and toolchain

Continue in this SAME worktree to retain private evidence:

```text
C:/Users/Ethan/.codex/worktrees/combat-rocket-review/gangstar-wch
```

The separate maintainer checkout is
`C:/Users/Ethan/Documents/GitHub/OpenGangstar/games/gangstar-wch`.
Ignored _scratch receipts are local to the Codex worktree, not interchangeable
with that checkout.

The handoff batch is [PR #793](https://github.com/OpenGangstar/gangstar-wch-decomp/pull/793),
source branch `match/hourly-decomp-after-792`. Fetch main, verify final PR status
and create a fresh `match/<task>` branch before new work. Do not resume a merged
PR branch blindly. The final user-facing completion reports actual merge status;
obtain its future merge SHA from Git rather than expecting this document to
embed the hash of the PR containing itself.

Retail library, never commit:

```text
C:/Users/Ethan/Documents/GitHub/OpenGangstar/games/gangstar-wch/baselib/libsanangeles.so
SHA256 b322b642d365a34c48e140234b7ef4efd965d1e81acd2b95d9034e2f4386ea8a
```

Matching compiler root:

```text
C:/Users/Ethan/Documents/GitHub/OpenGangstar/games/gangstar-wch/toolchain/android-ndk-1.6_r1/build/prebuilt/windows/arm-eabi-4.2.1
cc1plus SHA256 914b3fe8024cdfe8358b6fc6f78ce672136db1f03ccd609a8cb8a432de7bb734
```

Preserve manifest options/toolchains. Matching Cygwin is in the maintainer
checkout's `toolchain/cygwin32/bin`. Read docs/GHIDRA.md for MCP setup; do not
assume Claude inherits a live Codex MCP connection.

## Finished work and verified progress

- PR #792 merged as `560a7aae6c99b87083f3420e3e17dc639c8db15e`, matching
  PlayerTest::initDriving(bool), 184 bytes.
- Commit `21d07fbf` corrects the four-byte command prefix, exposes the existing
  flat eight-byte MissionStart payload and models printCommand's effective
  command-in-R0 call ABI as static. Existing Script::addCommand explicitly
  changed to the same +4 typed payload view and remains byte-identical.
  No inheritance or owning destructor was invented.
- Commit `27721826` matches Script::nextCommand(int), 252 bytes. The permitted
  `__builtin_expect(getState() == State2, 1)` guard changes allocation and
  removes the prior extra load/move without changing callbacks or memory phases.

```text
OK  _ZN6Script11nextCommandEi  0x0033ce19  252 bytes
OK SECTION .script_next_command  0x0033ce18  252 bytes

4297 / 4550 game functions
357742 / 561716 matched bytes = 63.69%
Fully Linked: 114548 bytes = 20.39%, 126 / 202 units
Fuzzy Matched: 63.69% (no partial credit for unmatched functions)
```

Script remains incomplete, so Fully Linked does not increase. See
docs/matches/script-next-command.md and docs/matches/script-command-prefix.md.
The reconstructed bool reflects zero/one on every retail exit; original bool
versus int spelling is unavailable from observed callers ignoring the result.
Complete physical ABI and machine bytes were verified, not inferred from size.

The fresh canonical gate passed all 191 ARM profiles: 5,466 function, 5,489
section and 181 region comparisons, 11,136 total. All 891 frozen build inputs
remained unchanged. Independent audit covered all 4,296 previous matched game
entries without gaps. 105 unit tests and repository/progress checks passed.
An initial canonical build failed on incomplete Mission; adding the genuine
Mission.h include fixed it. The failed log remains preserved. Only after the
successful complete gate was nextCommand's assembly marker removed.

A private raw gate stopped on two references carrying the owned function's
expected size change from 254 to 252. All other reference fields, caller bytes
and all 20 off-target relocation sections were independently verified unchanged.
That particular annotation update was accepted; no output was normalized or
edited. Do not generalize this into permission to waive raw failures.

## Validation and publication receipts

Paths below are relative to the exact worktree:

- `_scratch/next-command-handoff-link/verification.json` and `checks.log`:
  genuine three-object link; all 28 function / 14 section-region selectors pass.
- `_scratch/next-command-global-final/result.json`, `build.log`,
  `old-coverage.json`: successful full gate and all old entries.
- `_scratch/next-command-global/`: initial missing-include failure.
- `_scratch/next-command-state2-root-review.json`: private raw review.
- `_scratch/pr793-accepted-report.json`: frozen complete ByteMatch report.
- `_scratch/pr793-main-artifact-verification.json`: final publication receipt;
  verify it exists rather than assuming merge/publication from this document.

Required checks before each commit:

```powershell
python -B -m unittest discover -s tests
python -B tools/check_repository.py
python -B tools/progress.py --check
```

For a necessary complete ARM check, preserve profile options and avoid a global
toolchain override:

```powershell
$env:WCH_TOOLCHAIN_ROOT = $null
$env:PATH = 'C:/Users/Ethan/Documents/GitHub/OpenGangstar/games/gangstar-wch/toolchain/cygwin32/bin;' + $env:PATH
python -B tools/build.py --all --baselib C:/Users/Ethan/Documents/GitHub/OpenGangstar/games/gangstar-wch/baselib/libsanangeles.so
```

Regenerate catalogue, symbol map and progress with the retail library before
each push. CI has no game data: include exact local comparison output in PRs.
The working private helper `_scratch/hourly-pr-api.py` retrieves credentials
internally; never print its token or raw private environment values.

## Best unfinished targets and next steps

### ScriptManager::loadCommand — 0x0033ddd5, native 2436 bytes

Corrected canonical interfaces now support a coherent current reconstruction,
but its sole retained-body replay still emits 2440 function/input bytes.
UNMATCHED, no linker or overlap suppression. All 145 old functions and 173
allocated payloads preserve. A genuine new local type-15 jump-table label
`.L739` was classified specifically; the original failed receipt remains.

Read `_scratch/worker-script-load-command-current-trial/REPORT.md`, its
`focused-code-census/REPORT.md`, and `_scratch/loader-current-root-mapping-ledger.json`.
The +4 bytes are entirely branch-width accounting: native/current both have
953 mapping-code instructions, equal paired case-body counts/reader targets,
340 data bytes and equal alignment. Current has 15 long internal exits versus
native 13, with corresponding short-branch differences. Code totals are 2100
versus 2096. No allocation/read is missing and there is no extra pool word.

NEW, UNTESTED feasibility lead: source groups 18 no-payload opcodes into one
pre-profile CFG edge. Separate identical cases might retain multiple edges
until late crossjump merging and accumulate different frequency, explaining
native's no-payload fallthrough into the early common tail. First prove actual
GCC 4.2.1 edge-versus-label probability and merge staging, and audit old forms.
This is a hypothesis, not an approved trial, known original source shape or
guaranteed fix. Do not resume random case-order/hint/flag permutations. Earlier
six plus later three source controls remain spent.

### ScriptManager::reachRunningCommand — 0x0033d271, 112 bytes

Pass 041 comparison canonicalization motivated one genuine per-iteration
scriptCount snapshot after callbacks/appends but before local index increment.
The one trial stays 112 bytes and changes only two whole-object bytes, fixing
branch orientation. Nine NONRELOCATED native byte differences remain, chiefly
manager/index register roles. No new linked comparison or credit.

Read `_scratch/worker-reach-running-origin-plan/neutral-preparation/ORIGIN-REPORT.md`,
`per-iteration-count-trial/REPORT.md` and `per-iteration-count-proposal/UNAPPLIED.patch`.
Best proposed whole source SHA256:
`919239c283621032448fc0259b690a8271dbc260200bddefd1919510e9c0bade`.
This is a historical private context, not canonical integration. No further
source refinement ran. New work needs specific allocator/lifetime evidence.

### Other scripting work

Script::executeCommand at 0x00339cb9 remains unmatched: native 12636 bytes,
preferred retained candidate 12320, distinct later context 12380. Its records
already use the four-byte prefix. All 78 payload declarations agree with current
readers; that compatibility adds no matched bytes. See
`_scratch/worker-execute-command-prefix-compatibility/REPORT.md`.

ScriptManager::cleanCommand at 0x0033ffc1 remains unmatched, native 212 bytes.
Common view reads only opcode. Seven payload views need exact +4/+8/+12 pointer
offsets and original delete/clear order; opcode 114 deletes without clearing.
Scalar record deletion is separate. Do not invent owning destructors or base
ownership. See `_scratch/worker-clean-command-prefix-compatibility/REPORT.md`.

## Avoid repeated dead ends

ResStream tiny-three and onTargetReached normal comparator code were checked
across actual r1/r3/r4b frontends; no supported allocator version switch emerged.
Different hashes alone justify nothing; those negatives do not prove all target
backend code identical. Accelerometer cold-store order already agrees with
retail. Lock late-boolean/min-crossjump controls failed and remain uncredited.
GetNativeSoundRaw still lacks an authentic original prototype; generated recomp
or JNI callback signatures are not retail ABI evidence.

A large archive scan and repeated family searches already occurred. Read
target-specific records before broad repeats. The successful nextCommand method
combined exact neutral output, primary allocation math and one untried Script
State2 hint. Old Mission-state hints were distinct. Conditional modeled post-hint
priorities were not separately observed; do not report them as runtime facts.

DECOMP_TASKS.md contains 21 legacy raw 0x97 bytes: preserve with byte-safe edits,
not silent transcoding. Its newest handoff checkpoint supersedes stale ownership
and percentages. Never assume a lock file or old registry row proves a live agent.

User-provided AndroidRecomp and BackStabRecomp projects are references, not byte
match proof. Older Irrlicht/Vita paths may have moved; revalidate them. Genuine
upstream interfaces can help, but dependencies stay outside the game target.
