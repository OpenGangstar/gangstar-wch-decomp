# AGENTS.md

The rules of this repository. They are binding for human contributors and for
AI agents alike. Where this file and a task description disagree, this file
wins.

Read it completely before you change anything.

## What this project is

A matching decompilation of the native library of **Gangstar: West Coast
Hustle** (Gameloft, 2013, Android). The target is `libsanangeles.so`, an
ARM EABI shared object built with GCC 4.2.1 from a Gameloft fork of the
Irrlicht engine.

The game code is 4,550 functions in 182 translation units. The vendored
engine and its dependencies are out of scope.
The complete catalogue retains all 17,703 retail function entries, including
103 pending FreeType and 8 pending gameswf functions corrected from the original game classification.
See `docs/PROVENANCE-CORRECTIONS.md`; no original entry or assembly marker was
removed. Select game work by `origin=game` in `config/functions.tsv`.

## The repository in one paragraph

`config/functions.tsv` is the work queue: one row per function of the retail
library, with its address, size, original source file, gameplay area and
status. `asm/<area>/<symbol>.s` holds the disassembly of every function that
has not been decompiled yet. `src/game/<area>/<File>.cpp` holds the C++. A
function counts as matched when its assembly file has been deleted and a C++
definition has replaced it.

## Work selection

Maintainer direction on 2026-10-29 replaces the strict area-completion order with
the reuse-first workflow in `docs/WORK-ORDER.md`. Prioritize automated reuse,
relatives of existing matches, and small representatives that unlock large
families. Work may cross gameplay areas; an incomplete area does not hold up
the queue. The objective remains 100% byte-matched game code.

Use a default first-pass budget of six candidate compile/compare iterations.
Stop earlier when three materially different source forms produce identical
function bytes. Preserve the best candidate and exact differences, then park
the function. Revisit it with new evidence or a bounded escalation; do not spend
successive turns repeating a stalled search while fresh work is available.

## Before you change anything

1. `README.md` — what the project is and how it is put together.
2. `docs/BUILDING.md` — the toolchain and how a match is verified.
3. `docs/LAYOUT.md` — the original file layout and the gameplay areas.
4. `CONTRIBUTING.md` — how to land a change.

Then run the checks to confirm your checkout is sound:

```sh
python3 -m unittest discover -s tests
python3 tools/check_repository.py
python3 tools/progress.py --check
```

If the retail library is not available, the analysis tools say so and stop.
That is expected in CI, which has no game data.

## How a function is decompiled

1. Pick a function that still has an assembly file. `config/functions.tsv`
   lists them; the files are sorted by area.
2. Read the assembly. `tools/elf.py` and the symbol map tell you what the
   function calls and which class it belongs to. The demangled name in the
   header of the assembly file is the real name of the function.
3. Write the C++ in the matching file under `src/game/<area>/`. Put the
   function in the same place the retail build put it.
4. Compile it with the matching toolchain and compare it with the retail
   bytes. The comparison is the only proof that counts.
5. Delete `asm/<area>/<symbol>.s` when the function matches.

## Rules that are not negotiable

- **A match is a byte for byte comparison**, not a "looks right". Report the
  output of the comparison tool exactly as it printed it.
- **Plain C++.** No inline assembly inside a function, no register pins, no
  barriers to force an ordering.
  Maintainer clarification on 2026-10-25: GCC branch-likelihood hints are
  permitted when the complete function and affected existing matches compare
  byte for byte. Document each use and its exact comparison output.
- **Nothing edits compiler output.** A function that only matches after a
  post-processing step is not matched.
- **Never commit game data.** The retail library, the APK and the assets stay
  out of the repository. `tests/check_repository.py` enforces this.
- **Never commit proprietary tools.** The NDK is not ours to redistribute.
- **Do not edit the generated tables by hand.** `config/*.tsv` is written by
  `tools/catalogue.py` and `tools/symbol_map.py`. Regenerate them.
- **Do not delete files you did not create.** In particular, do not delete
  assembly files to make progress numbers look better.
- **Never edit an existing decompiled function** to make it match without
  saying so in the commit message.

## Reporting

Say what you ran and what it printed. If a build failed, if a step was
skipped, or if a function is close but not exact, say so plainly. A near
miss honestly reported is useful; a claimed match that does not build costs
somebody a day.

## Git

- Branch from an up-to-date `main`: `git switch -c match/<what> origin/main`.
  Never commit to `main`, never force-push a shared branch.
- Conventional commit subjects with a scope (`feat(src):`, `fix(tools):`,
  `docs:`). Keep commits small: one function or one small family each.
- Before every commit:

```sh
python3 -m unittest discover -s tests
python3 tools/check_repository.py
python3 tools/progress.py --check
```

- Before every push, also regenerate the tables if the retail library is
  available:

```sh
python3 tools/catalogue.py
python3 tools/symbol_map.py
python3 tools/progress.py
```

- Open a pull request to `main` with the comparison output in it. CI has no
  game data and cannot build, so the build result you report is taken on
  trust: report it exactly.

# Gangstar West Coast Hustle Decompilation

## Agent Structure

The main Codex agent is the sole coordinator.

Use exactly four decompilation sub-agents when at least
four independent functions are available.

The main agent must:
- Identify functions requiring decompilation.
- Assign distinct functions to sub-agents.
- Maintain a central function ownership registry.
- Review all completed work.
- Handle integration, commits, and pull requests.
- Assign new work as agents become available.

Sub-agents must not spawn additional agents.

## Function Ownership

Each function may have only one assigned agent.

Before assigning work:
1. Identify the function by binary, address, and name.
2. Check whether another agent owns the function.
3. Record the assignment in the ownership registry.
4. Give the agent an explicit scope.

Agents must never:
- Work on another agent's assigned function.
- Modify code owned by another active agent.
- Claim an already assigned function.
- Expand their scope without coordinator approval.

If an agent discovers that another function requires
changes, it must report this to the main agent.

The main agent decides whether to assign that function
to an available agent.

Function ownership is released only after the main
agent has reviewed and accepted the work.

## Parallel Decompilation

Keep four agents working concurrently whenever enough
independent work is available.

Each agent should:
1. Analyze its assigned function.
2. Reconstruct the function in C/C++.
3. Preserve original behavior and ABI compatibility.
4. Compare against the original ARM machine code.
5. Test or validate the reconstruction.
6. Report completion to the main agent.

Agents must not wait for other agents unless there
is a genuine dependency.

When an agent finishes, the main agent should review
its work and assign another available function.

## Function Registry

Maintain a file named DECOMP_TASKS.md.

Track:
- Binary/library name
- Function address
- Function name
- Assigned agent
- Status
- Matching percentage
- Relevant source files

Statuses:
- AVAILABLE
- ASSIGNED
- IN_PROGRESS
- REVIEW
- COMPLETED
- BLOCKED

Only the main agent may modify ownership assignments.

## Pull Request Restrictions

Sub-agents are strictly prohibited from:
- Creating pull requests.
- Merging pull requests.
- Pushing branches.
- Committing changes.
- Running gh pr create.
- Running gh pr merge.

Sub-agents must submit their results to the main
Codex agent for review.

Only the main Codex agent may:
1. Review completed decompilation work.
2. Verify function ownership and changes.
3. Run applicable builds and tests.
4. Integrate approved changes.
5. Create commits.
6. Push branches.
7. Create pull requests.

The main agent must not create a PR until it has
reviewed the relevant work.

## Decompilation Quality

Prioritize accurate reconstruction of the original
Gangstar West Coast Hustle code.

Do not invent implementations to increase the
decompilation percentage.

Preserve:
- Original control flow
- Function signatures
- Data structures
- Calling conventions
- Memory layouts
- Original game behavior

Track matching progress separately from Windows
porting progress.

Do not play through the game as part of decompilation.
Use static analysis, compilation, and targeted tests.

## Shared Files

Avoid simultaneous edits to shared headers, build
scripts, or global structures.

If multiple functions require changes to the same
shared file, the main agent must coordinate those
changes or perform the integration itself.
