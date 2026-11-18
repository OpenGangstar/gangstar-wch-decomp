# HUD lifecycle, component registration, and supporting lookups

This batch reconstructs 34 catalogue entries covering 12,718 retail bytes.
Constructor and destructor aliases count as separate catalogue entries; their
shared machine-code ranges are not additional unique executable storage.

CHudManager is an IUpdatable with its original virtual destructor and update
slot. Its component fields now use the existing concrete class declarations.
The vector at offsets 192â€“203 is the existing STLport std::vector<HudElement*>;
its automatic destruction performs the original base cleanup exactly once.
The constructor preserves allocation sizes, asset names, field store order,
component insertion order, and component registration. The destructor preserves
unregistration, deletion, pointer clearing, and the observed SafeDelete calls.
The four HUD modes preserve their original visibility, registration, control
mode, event, and accelerometer operations. Mode setters retain their retail
weak linkage, including existing calls through the GOT.

The shared component declarations were moved from their original implementation
files into headers. Wheel's 84-byte and MiniMap's 116-byte observed allocation
extents are represented without assigning meanings to unrecovered padding.
Control-handler interface retention is shared between its original verification
unit and driving HUD; no compiler output is modified.

The member at CHudManager offset 204 is an ITouchable default receiver.
CameraManager implements that existing three-slot interface; its constructor
now assigns the correctly typed member. The original constructor bytes and
all existing camera functions remain exact. The emitted ITouchable vtable at
0x004ac418 has a 20-byte symbol and a 24-byte aligned section; the entire
section, including padding, is compared with retail. Pure slots resolve to the
same zero value as the other verified pure interface tables.

Existing CHudManager::init and three HUD reset loops were updated to use the
recovered fields and vector. Their complete bytes remain unchanged. Weapon::photo
uses the existing offset-56 partial view of Background to preserve its original
store. Cash::drawCash needed the two independent local declarations reordered
after the ASprite header gained methods; the original 332 bytes remain exact.
These existing functions receive no new matching credit.

Application's two completion getters preserve boolean normalization and logical
negation. ASprite's frame-time lookup reads the unsigned duration at offset 2
of a nine-byte animation-frame record. GetFrameIdx performs the original linear
name search, using frame count at SpriteData offset 12 and the blob-relative
name offset at SpriteFrame offset 24; the 28-byte frame stride is unchanged.
ASpriteData's constructor zeros only the seven observed words at offsets
28 through 52; no initialization of its unrecovered prefix is invented.
MediaPlayerIPhone's constructor only emits its two observed trace calls; its
class declaration asserts neither payload storage nor a recovered base layout.
TargetMarker::draw reuses existing sprite, vector, and matrix interfaces and
preserves both transforms, draw calls, and final identity transform.

## Verification

The integrated scoped commands passed before removal of each assembly file.
The complete regression command is `python tools/build.py --all` against the
local retail library and GCC 4.2.1 toolchain. No imported ABS definition is
credited as a reconstruction. Initial full runs exposed the CameraManager
interface retention, Weapon incomplete-type access, and Cash scheduling
regression described above; these were corrected and rechecked.

GCC reports `inline function 'virtual Radio::~Radio()' used but never defined`.
The verification retains the original external virtual destructor calls; this
warning does not prevent compilation, linking, or byte comparison.

The final full command exited 0 with 9,558 retail function, section, and GOT-region comparisons. The 84 unit tests, repository check, progress check, and whitespace check passed. The emitted ToggleButton touch method and thunk are retained at 0x0032c234 and compare as one complete 32-byte section, including their padding.

Exact new-function comparison output:

```text
OK  _ZNK17MediaPlayerIPhone6_traceEPKc  0x002d3be9  28 bytes
OK  _ZN17MediaPlayerIPhoneC1Ev  0x002d3c05  48 bytes
OK  _ZN17MediaPlayerIPhoneC2Ev  0x002d3c05  48 bytes
OK  _ZN11Application20IsGlobalResumingOverEv  0x002d3c9d  26 bytes
OK  _ZN11Application10IsLogoOverEv  0x002d3cb9  28 bytes
OK  _ZN11CHudManager15setThrottleModeENS_12ThrottleModeE  0x002ebc9d  140 bytes
OK  _ZN11CHudManager15setSteeringModeENS_12SteeringModeE  0x002ebd29  244 bytes
OK  _ZN10CCameraHud4showEv  0x00322c5d  376 bytes
OK  _ZN10CCameraHud4hideEv  0x00322dd5  212 bytes
OK  _ZN11CDrivingHud4showEv  0x003230ad  596 bytes
OK  _ZN11CDrivingHud4hideEv  0x00323301  332 bytes
OK  _ZN11CHudManager5blinkEi  0x00323705  184 bytes
OK  _ZN11CHudManager24unregUpdatableComponentsEv  0x003238f5  168 bytes
OK  _ZN11CHudManager22regUpdatableComponentsEv  0x0032399d  168 bytes
OK  _ZN11CHudManager21regDrawableComponentsEv  0x00323be9  244 bytes
OK  _ZN11CHudManager23unregDrawableComponentsEv  0x00323da9  244 bytes
OK  _ZN11CHudManagerD0Ev  0x00324669  784 bytes
OK  _ZN11CHudManagerD2Ev  0x00324979  780 bytes
OK  _ZN11CHudManagerD1Ev  0x00324979  780 bytes
OK  _ZN11CHudManagerC1Ev  0x00324c85  2572 bytes
OK  _ZN11CHudManagerC2Ev  0x00324c85  2572 bytes
OK  _ZN11CWalkingHud4showEv  0x003256dd  298 bytes
OK  _ZN11CWalkingHud4hideEv  0x00325809  182 bytes
OK  _ZN10CSniperHudC1EP11CHudManager  0x00325add  48 bytes
OK  _ZN10CSniperHudC2EP11CHudManager  0x00325add  48 bytes
OK  _ZN10CSniperHudD1Ev  0x00325b0d  24 bytes
OK  _ZN10CSniperHudD2Ev  0x00325b0d  24 bytes
OK  _ZN10CSniperHud4showEv  0x00325b25  340 bytes
OK  _ZN10CSniperHud4hideEv  0x00325c79  212 bytes
OK  _ZNK12TargetMarker4drawEv  0x0032be75  832 bytes
OK  _ZNK7ASprite13GetAFrameTimeEii  0x003499b9  36 bytes
OK  _ZN7ASprite11GetFrameIdxEPKc  0x00349a81  64 bytes
OK  _ZN11ASpriteDataC2Ev  0x0034a3b5  18 bytes
OK  _ZN11ASpriteDataC1Ev  0x0034a3b5  18 bytes
```
