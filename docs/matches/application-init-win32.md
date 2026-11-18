# Application::InitWin32

The original Android game's InitWin32 method now matches all 118 native bytes.
Despite its name, this reconstructs the retail ARM platform path; it does not
change the native Windows port.

The method allocates the real FileSystemWin32, TouchScreenWin32 and
AccelerometerWin32 objects, registers both input objects through their actual
base classes, calls Application::Init and applies the saved orientation. Native
constructor, Init and orientation implementations remain imported where pending.

Five existing class declarations were extracted unchanged into four shared
headers. Coordinator comparison against the preceding commit proved all five
class bodies byte-for-byte identical, including attributes and inline methods.
The original translation units include those headers at the declaration positions;
namespace boundaries and intervening Help data remain in place. Four emitted
bound getters are retained at their native addresses and explicitly compared in
both Application consumer images, with no additional progress credit.

Exact output from the accepted coordinator verification:

```text
OK  _ZN11Application9InitWin32EPN3irr14IrrlichtDeviceE  0x002d5821  118 bytes
OK  _ZNK16TouchScreenWin3212getLeftBoundEv  0x0034d02d  4 bytes
OK  _ZNK16TouchScreenWin3213getRightBoundEv  0x0034d031  4 bytes
OK  _ZNK16TouchScreenWin3211getTopBoundEv  0x0034d035  4 bytes
OK  _ZNK16TouchScreenWin3214getBottomBoundEv  0x0034d039  4 bytes
OK  _ZNK4Cash8drawCashEiPKiRii  0x00327a71  332 bytes
OK  _ZNK16SceneNodeManager3crcEPKc  0x003215b5  58 bytes
```

An initial full sweep found two existing-function scheduling regressions after
adding the genuine Application declarations: Cash::drawCash differed by five
bytes and SceneNodeManager::crc changed the ordering of independent zero/-1
initializations. These were not accepted. Cash now declares its first loop index
before the counters; crc swaps the declarations of its independent initial values.
Their algorithms, comments, ABI and behavior are unchanged, and every original
byte is restored. The existing-body edits are explicitly disclosed in the commit.
Cash used four bounded source forms, including the initial unchanged body; crc
matched after its first declaration-order correction. No hints, barriers,
register pins, inline assembly or compiler-output modifications were used.

The initial GSFade check also exposed missing Thumb metadata for the newly called
native constructors/factory methods. Their real native imports were added;
no compiled definitions were masked. Earlier failed comparisons are preserved
locally alongside the successful proof.

Fresh `python tools/build.py --all`: 182 profiles, 10234 exact
function/section/GOT comparisons, exit zero. Local log:
_scratch/application-init-win32-accepted-full.log and .exit. All existing matches,
including both edited functions and the newly integrated destructor family,
remain exact. Progress adds only this 118-byte game function.
