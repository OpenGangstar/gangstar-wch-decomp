# Decompilation function registry

The main Codex agent records assignments and releases ownership after review
and acceptance. Use the binary, address, and function name to identify each
entry. Follow the workflow in [AGENTS.md](AGENTS.md).

<!-- active-ownership:start -->
## Current coordinator dispatches

The previous four-worker OpenCode batch was published in PR772. This execution
exposes three native worker slots plus the coordinator; the prior OpenCode
command/tool surface is unavailable here. Three independent reuse reviews are
assigned below. The complete byte-matching goal remains active and incomplete. Workers used private scratch
files; only the coordinator integrates
canonical changes. Prior SoundManager and Billboard probes were reviewed and
rejected without credit; their ownership is released.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x00344821 | SaveGame::SampleAndSave(char const*) | unassigned | BLOCKED | Reviewed unchanged-object diagnostic: first reversal at post-reload sched2, no justified source trial; ownership released | src/game/persistence/SaveGame.cpp |
| libsanangeles.so | 0x00348cfd | Trail::CreateMeshSceneNode() | unassigned | COMPLETED | 100%; canonical function/full section exact, 191 profiles and 10,984 comparisons pass, all 4,285 matched entries directly verified. Ownership released after acceptance | src/game/world/Trail.cpp; src/game/core/SceneNode.h |
| libsanangeles.so | 0x0034fbf9 | CarSounds::UpdateTurboSounds() | unassigned | BLOCKED | Reviewed family audit confirms prior trial already used accepted types; no new experiment justified, ownership released | src/game/vehicles/CarSounds.cpp; src/game/vehicles/CarSoundCallbacks.h |
| libsanangeles.so | 0x003485f1 | Trail::Update() | unassigned | BLOCKED | Reviewed single derived-offset trial: 320/324 bytes and 312 differences, baseline remains better. Mesh and old owner checks exact; ownership released | src/game/world/Trail.cpp |
| libsanangeles.so | 0x00348735 | Trail::BuildPoint(int, bool) | unassigned | BLOCKED | Reviewed full contracts and helper census; no new discrepancy, 760/812 remains unmatched; ownership released | src/game/world/Trail.cpp |
| libsanangeles.so | 0x00331a09 | WeaponManager::getKeepWeaponsWhenBustedCost() regression diagnosis only | unassigned | COMPLETED | Original shared header restored; canonical targeted gate passes. Worker control caught restored state and does not isolate compiler cause; no function edits | src/game/combat/WeaponManager.cpp; src/game/core/SceneNode.h |
| libsanangeles.so | 0x002f39e1 | Character::runToTarget(int) | unassigned | BLOCKED | Reviewed native contracts and four prior forms; no new source discrepancy, ownership released | src/game/characters/Character.cpp |
| libsanangeles.so | 0x003160d9 | GameObjectManager::getAttackableTarget(Character*) | unassigned | BLOCKED | Reviewed actual identical 316-byte forms and 12-byte discrepancy; no new source correction, ownership released | src/game/world/GameObjectManager.cpp |
| libsanangeles.so | 0x0031cf75 | PhysicAttributes::GetNextRandomPos(int, int, vector3df) | unassigned | BLOCKED | Reviewed corrected helper and physical ABI analysis; no new source correction. Ownership released | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x00328c49 | Map::draw() const | unassigned | BLOCKED | Reviewed unchanged-object diagnostic: first group differs before RTL and second at sched2; no source trial justified, ownership released | src/game/world/Map.cpp |
| libsanangeles.so | 0x002ecb01 | Widgets::Help::SetIcon(char const*) | unassigned | BLOCKED | Reviewed pinned upstream API and matched callees; no new wrapper mechanism, ownership released | src/game/ui/MenuWidget.cpp |

| libsanangeles.so | 0x0031eb99 | PhysicAttributes::GetHeight(int, vector3df const&, bool, bool) | unassigned | BLOCKED | Corrected4982/native5038 candidate has faithful coefficients, B-anchored normals and snapshots; only known multiplication operand ordering differs. No new source trial justified; ownership released | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x002dfb15 | GS3DStuff::load(int, int&) | unassigned | COMPLETED | 100%; function/full section2576B exact, all191 profiles11112 comparisons pass,880 additional merged GS checks exact,1098 frozeninputs stable. Genuine array alias and loader-local adapter accepted; ownership released | src/game/rendering/GS3DStuff.cpp; config/linker/GS3DLoadSections.ld |

| libsanangeles.so | 0x00329901 | MiniMap::_calculateXYOffset(vector3df const&, recti const&, bool, bool) const | unassigned | BLOCKED | Unchanged diagnostic reproduced exact object; first spills at greg, no source trial. Coordinator physical ABI and complete body verified live; no new source constraint. Pending candidate unchanged; ownership released | src/game/hud/MiniMap.cpp |

| libsanangeles.so | 0x002dd7e1 | GS3DStuff::updateVisibility(unsigned int) | unassigned | BLOCKED | Corrected complete CFG and native truth tables agree candidate; no new source correction, ownership released | src/game/rendering/GS3DStuff.cpp |

| libsanangeles.so | 0x002ff5d1 | NPC::attackTarget() | unassigned | BLOCKED | Proven retarget-success path skips empty-driver validation natively. Sole else-if correction emits2072/native2108; strict prelink rejected, coordinator verified71 other raw definitions and1063 stable inputs. Dependencies152/44 pass; NPC target/owner/GOT skipped. Corrected source preserved without credit; ownership released. | src/game/ai/NPC.cpp; _scratch/worker-npc-attack-retarget-else-control/ |
| libsanangeles.so | 0x0031aa5d | PhysicAttributes::GetRandomDestination(unsigned short, unsigned short&, vector3df const&, float, float) | unassigned | BLOCKED | Reviewed all eleven differences as three scalar spill slots, with identical frame and address-taken buffers. Approve one unchanged-v3 diagnostic dump build to identify the first allocation decision, requiring exact emitted payload identity; no source or optimizer changes | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x00327a71 | Cash::drawCash(int, int const*, int&, int) const - header regression diagnosis only | unassigned | COMPLETED | Two controls reviewed: nested Quaternion tag alone reproduces the Cash regression; six other headers preserve all owner checks. Reviewed read-only audit: type and constructor additions remain confounded. Type-only and declaration-only controls preserve Cash exactly. Prepare a fresh complete-input header-only snapshot with declaration-only Quaternion and six other reviewed headers; coordinator runs the global gate | src/game/ui/Cash.cpp; proposed SDK headers |

| libsanangeles.so | 0x00316c29 | LevelObject::grabSceneNode(int, void***) - loader dependency preservation audit only | unassigned | COMPLETED | Coordinator ran actual-loader closure: original owner and dependency checks exact, fourteen support sections exact; pending loader function/full section retain exactly four differences. Ownership released | src/game/world/LevelObject.cpp; config/matches/level-object.json; config/linker/LevelObject.ld |

| libsanangeles.so | 0x002df605 | __tcf_10 GS3D light array cleanup - existing match type audit only | unassigned | COMPLETED | Reviewed exact restricted-array layout and lifetime; unknown16 semantics remain unresolved. Read-only compare GS3DLightNodes placeholder and existing Irrlicht array layout/lifetime with matched native startup and cleanup. Identify exact mechanical field mapping and risks; no source edits or compilation | src/game/rendering/GS3DStuff.cpp; src/game/rendering/GS3DStuff.h; src/game/core/Array.h |

| libsanangeles.so | 0x003268e1 | AnalogStick::processTouch(long) | unassigned | BLOCKED | Complete422-instruction/938B readback and focused mode/deadzone/event/common-tail audit accepted. Actual1028/native1016 source preserves observed joins and callback rereads; no new source cause or compile. Related20B thunk remains uncredited. Ownership released. | src/game/input/AnalogStick.cpp; _scratch/worker-analog-touch-join-constraints/ |

| libsanangeles.so | 0x00330015 | Rocket::launch(vector3df) | unassigned | BLOCKED | Complete repaired CFG verified byte for byte; remaining cache differences were already investigated. No new source experiment justified; ownership released | src/game/combat/Rocket.cpp |

| libsanangeles.so | 0x002fc495 | Item::isUsable() - exact-loader dependency preservation fixture only | unassigned | COMPLETED | Fixture preparation reviewed and accepted; coordinator executing fresh 191-profile gate. No claim of completed global verification yet; ownership released | src/game/meta/Item.cpp; config/matches; config/linker |

| libsanangeles.so | 0x002e078d | GS3DStuff::update(StateMachine*) | unassigned | BLOCKED | Complete repaired CFG matches preserved source constraints; new loader types are unused here. No new trial justified, original target-only/full-context limitations retained; ownership released | src/game/rendering/GS3DStuff.cpp |

| libsanangeles.so | 0x002df995 | OctTreeAABB::OctTreeAABB(ISceneNode*, unsigned int) | unassigned | BLOCKED | Full344-byte native code CFG verified after normal delete-flow repairs; preserved388/native384 candidate already models counters and cleanup. No new source trial justified; ownership released | src/game/rendering/GS3DStuff.cpp |

| libsanangeles.so | 0x002df655 | OctTreeAABB::OctTreeAABBNode constructor | unassigned | BLOCKED | Full repaired CFG verified against native and final828/native832 candidate; no new source discrepancy or trial justified. Ownership released | src/game/rendering/GS3DStuff.cpp; _scratch/worker-octree-child-initialization-current/ |

| libsanangeles.so | 0x0031b9a9 | PhysicAttributes::IntersectSegmentWithHeightMap(PhysicInfo&, plane3df const&, vector3df const&, vector3df const&, vector3df&, vector3df&) | unassigned | BLOCKED | Corrected current candidate4864/native4800 preserves41 old functions and passes relocated38/11 checks. Single no-tree-sink control4832 restores native frame but regresses7 old functions; rejected. Ownership released | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x0031ad31 | PhysicAttributes::SetHeightAttributes(vector3df const&, PhysicInfo*) | unassigned | BLOCKED | Complete1344-byte code CFG verified and source predicates match saved1400/native1388 candidate. No new source trial justified; ownership released | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x002dd33d | OctTreeAABB::OctTreeAABBNode::getPolysIter(...) const | unassigned | BLOCKED | Complete602-byte code CFG independently verified; saved616/native620 candidate already uses genuine arrays and known predicates. No new source trial justified; ownership released | src/game/rendering/GS3DStuff.cpp |

| libsanangeles.so | 0x0031da29 | PhysicAttributes::IntersectSegmentWithHeightMap(vector3df const&, vector3df const&, vector3df&, vector3df&) | unassigned | BLOCKED | Complete566-byte code CFG and five-pointer ABI verified; saved592/native596 candidate already has correct large-call arguments and snapshots. No new trial justified; ownership released | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x0031a6fd | PhysicAttributes::GetJumpHeight(vector3df const&, int) | unassigned | BLOCKED | Confirmed B-C interpolation correction compiled once in current context:588/native596, strict extent rejected before link. All41 prior raw functions and semantic relocations unchanged; linked38/11 checks not run. Correct candidate preserved; ownership released | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x0031b3e9 | PhysicAttributes::SetHeightAttributes(ISceneNode*, vector3df const&, PhysicInfo&) | unassigned | BLOCKED | Complete1006-byte code CFG verified; normal audit confirms current B-anchored helper graph, with known CSE/operand-register differences in1036/native1040 candidate. No new source trial justified; ownership released | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x0031a67d | PhysicAttributes::IsPositionOnJump(vector3df const&) | unassigned | BLOCKED | Complete122-byte code CFG and all native operands verified; no new gap in guard, center distance or strict90000 test. Historical candidate recovery limits retained; ownership released | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x0031a40d | PhysicAttributes::FindLowerCostNode(array<AStarNode>*, int*) - existing matched prerequisite audit | unassigned | COMPLETED | Current192-byte function/full section exact; audit identifies missing accepted FindLower192 and LoadArrays1336 in legacy source. Current-prefix/header rebase required with41 raw functions and38/11 gates retained; ownership released | src/game/characters/PhysicAttributes.cpp; config/matches/ai-startup-physicattributes.json; config/linker/PhysicAttributesResetSections.ld |

| libsanangeles.so | 0x0031ff49 | PhysicAttributes::GetHeight(vector3df const&, int, bool) | unassigned | BLOCKED | Complete234-byte code CFG and native operand flow agree retained source. Four-parameter physical ABI correction proposed; no new source trial. Historical candidate recovery limits retained; ownership released | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x0031aa5d | PhysicAttributes::GetRandomDestination - current-context replay | unassigned | BLOCKED | Current replay retains exactly old724-byte target and11 stack operands; all41 raw functions, owner38/11 and Character/NPC dependencies pass. No new source form justified; ownership released | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x0031dc7d | ContactFilter::ShouldCollide(b2Shape*, b2Shape*) | unassigned | BLOCKED | Complete1058-byte native code and explicit bool ABI verified; faithful v2 remains1084/native1100, no new source gap or compile justified. Ownership released | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x00320ca1 | PhysicAttributes::ComputeShortestPath(int, int, vector3df, vector3df, float) | unassigned | BLOCKED | Original-terminal predicate corrected once:1672/native1668, strict prelink rejected;41 old raw functions and semantic relocations unchanged. Portable incremental patch accepted; ownership released | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x0031da29 | PhysicAttributes::IntersectSegmentWithHeightMap(vector3df const&, vector3df const&, vector3df&, vector3df&) - current-context proposal | unassigned | BLOCKED | Reactivated: resolve whether the remaining enum flag or later declarations actually affect this wrapper or its inlined callees. Audit existing objects and declarations only; no speculative replay, compilation or metadata writes | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x002deba1 | GS3DStuff::checkPickableProximity(std::vector<Item*>&) | unassigned | BLOCKED | Complete330-byte native code restored and faithful source audited;352 artifact lacks exact historical input closure,360 control already rejected. No further trial; ownership released | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002e1e15 | GSFailure::draw2d(StateMachine const*) | unassigned | BLOCKED | Complete292-byte native code and explicit self/callback ABI verified;284/native308 source has no newly identified gap. No compile; ownership released | src/game/app/GSFailure.cpp |

| libsanangeles.so | 0x002e6731 | MenuManager::_positionMapOnPoint(vector2df&) | unassigned | BLOCKED | Complete288-byte native code and self/point ABI restored; typed312/native308 source matches native constraints, no new trial. Ownership released | src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x002e2725 | GSInGameMenu::update(StateMachine*) | unassigned | BLOCKED | Complete332-byte native code verified;356/native352 source snapshots and interfaces agree. Double/audio analysis prototypes repaired separately; no compile, ownership released | src/game/ui/GSInGameMenu.cpp |

| libsanangeles.so | 0x002e6865 | MenuManager::_scrollMap(std::list<Point2D<short>*> const&) | unassigned | BLOCKED | Complete216-byte native code verified against retained232/native228 source; signed list/point and callback snapshots agree. No compile; ownership released | src/game/ui/MenuManager.cpp |

| libsanangeles.so | 0x002e6949 | MenuManager::updateMarkers() | unassigned | BLOCKED | One native-supported pre-getter top snapshot compiled356/native360;77 old functions and semantic relocations unchanged, strict extent rejected before link. Corrected candidate preserved; ownership released | src/game/ui/MenuManager.cpp |

| libsanangeles.so | 0x002eb45d | Menus::ServiceWeaponShop::Update() | unassigned | BLOCKED | Complete356-byte native code verified; retained380-byte candidate remains80-byte mismatch with no new source gap. No compile; ownership released | src/game/ui/MenuState.cpp |

| libsanangeles.so | 0x0031d7a1 | ContactListener::Persist(b2ContactPoint const*) | unassigned | BLOCKED | Complete578-byte native code and two-carrier void ABI verified; six forms exhausted,604-byte candidate still341 equal bytes historically. No new source gap; ownership released | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x002e6149 | MenuManager::tearDown() | unassigned | BLOCKED | Complete284-byte native code restored after returning-delete overrides; saved300-byte candidate retains only two known compare/branch differences. No new trial; ownership released | src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x002eb9dd | Menus::ServiceMissions::Notify(MenuWidget const*, int) | unassigned | BLOCKED | Complete328-byte native code verified; retained340-byte candidate remains113-byte mismatch, signed loop/callback snapshots agree. No compile; ownership released | src/game/ui/MenuState.cpp |

| libsanangeles.so | 0x00320351 | ContactListener::Add(b2ContactPoint const*) | unassigned | BLOCKED | Read-only complete native CFG, callback/body snapshot and contact-interface audit reusing confirmed Persist contracts. Six prior forms retained; recover fixture limits before conclusions. No compiler or metadata writes. | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x002e6db1 | MenuManager::_zoomMap(std::list<Point2D<short>*> const&) | unassigned | BLOCKED | Read-only complete native CFG, pinch-point lifetime and repeated Map callback snapshot audit. Preserve prior identical-form stop; no compiler or metadata writes. | src/game/ui/MenuManager.cpp |

| libsanangeles.so | 0x002eb6a9 | Menus::ServiceCorruption::Notify(MenuWidget const*, int) | unassigned | BLOCKED | Read-only complete native CFG, callback snapshot and Wanted/Player/widget physical interfaces audit. Prior196/native184 forms retained; no compiler or metadata writes. | src/game/ui/MenuState.cpp |

| libsanangeles.so | 0x002e6ab1 | MenuManager::_drawMap() const | unassigned | BLOCKED | Read-only complete native CFG and texture/rectangle/matrix callback snapshot audit against current432/native424 candidate. Preserve prior layout controls; no compiler or metadata writes. | src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x0031e285 | PhysicAttributes::AddCollisionShapes(int, unsigned short) | unassigned | BLOCKED | Complete1726-byte native code verified; sole per-edge info-array snapshot control1808/native1816 preserves44 old functions and semantic relocations. Strict prelink rejected, no linked checks. Corrected source retained; ownership released. | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x002efc31 | Widgets::Language::OnEvent(RenderFX::Event&) | unassigned | BLOCKED | Read-only complete native CFG, localization/font and callback snapshot audit. Prior372-byte typed-API candidate and80 differences retained; no compiler or metadata writes. | src/game/ui/MenuWidget.cpp |

| libsanangeles.so | 0x002e6fe1 | MenuManager::updateMap() | unassigned | BLOCKED | Read-only complete native CFG, touch-list dispatch and callback-sensitive state snapshots. Retain authentic388-byte candidate and rejected old hint; no compiler or metadata writes. | src/game/ui/MenuManager.cpp |

| libsanangeles.so | 0x002e7165 | MenuManager::initMap() | unassigned | BLOCKED | Read-only complete native CFG and texture/hierarchy/clamp snapshots using related confirmed Map interfaces. Eight previous forms preserved; no compiler or metadata writes. | src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x002efda5 | Widgets::Controls::OnEvent(RenderFX::Event&) | unassigned | BLOCKED | Read-only complete native CFG and HUD/Preferences callback lifetimes using related confirmed Language interfaces. Existing372-byte form retained; no compiler or metadata writes. | src/game/ui/MenuWidget.cpp |

| libsanangeles.so | 0x002e4e7d | MenuManager::update(StateMachine*) | unassigned | BLOCKED | Read-only complete native CFG, double-timer and game/menu callback snapshots. Preserve six forms and two rejected historical regressions; no compiler or metadata writes. | src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x002efafd | Widgets::GameSetting::OnEvent(RenderFX::Event&) | unassigned | BLOCKED | Read-only complete native CFG and Preferences/event/sound snapshots using confirmed sibling interfaces. Two previous six-form waves retained; no compiler or metadata writes. | src/game/ui/MenuWidget.cpp |

| libsanangeles.so | 0x002e5e4d | MenuManager::preloadGlyphs(bool) | unassigned | BLOCKED | Exclusive bounded family queue: read-only complete native-flow and callback/source constraint audit. Preserve prior budgets and fixture limits; no compilation or metadata writes. Report each result for coordinator review. | src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x002e51fd | MenuManager::setText(eText, char const*, int*) | unassigned | BLOCKED | Reviewed all17 original/actual switch paths, null/visibility/formatting and cleanup joins. All465 native instructions994B exact and owned; no new source guard discrepancy or compile. Candidate1100/native1104 remains unmatched; ownership released. | src/game/ui/MenuManager.cpp; _scratch/worker-settext-switch-join-constraints/ |
| libsanangeles.so | 0x002e574d | MenuManager::setup(bool) | unassigned | BLOCKED | Reviewed complete687-instruction/1682B native body and all166 matching actual branch/call instructions. Remaining1792-byte/50-difference artifact is confined to established spill/init clusters; no source guard cause or compile. Ownership released. | src/game/ui/MenuManager.cpp; _scratch/worker-menu-setup-join-constraints/ |
| libsanangeles.so | 0x002ef901 | Widgets::Objective::OnEvent(RenderFX::Event&) | unassigned | BLOCKED | Exclusive bounded family queue: read-only complete native-flow and callback/source constraint audit. Preserve prior budgets and fixture limits; no compilation or metadata writes. Report each result for coordinator review. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ed299 | Widgets::MapLegend::OnEvent(RenderFX::Event&) | unassigned | BLOCKED | Exclusive bounded family queue: read-only complete native-flow and callback/source constraint audit. Preserve prior budgets and fixture limits; no compilation or metadata writes. Report each result for coordinator review. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee6ed | Widgets::Controls::UpdateLocalization() | unassigned | BLOCKED | Exclusive bounded family queue: read-only complete native-flow and callback/source constraint audit. Preserve prior budgets and fixture limits; no compilation or metadata writes. Report each result for coordinator review. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x003160d9 | GameObjectManager::getAttackableTarget(Character*) | unassigned | BLOCKED | Exclusive bounded family queue: read-only complete native-flow and callback/source constraint audit. Preserve prior budgets and fixture limits; no compilation or metadata writes. Report each result for coordinator review. | src/game/world/GameObjectManager.cpp |
| libsanangeles.so | 0x003179d5 | LevelObject::CastRay(vector3df const&, vector3df const&, vector3df&, vector3df&, LevelObject*&, bool) | unassigned | BLOCKED | Exclusive bounded family queue: read-only complete native-flow and callback/source constraint audit. Preserve prior budgets and fixture limits; no compilation or metadata writes. Report each result for coordinator review. | src/game/world/LevelObject.cpp |
| libsanangeles.so | 0x00317fb5 | LevelObject::canGoToPoint(vector3df const&, vector3df&, vector3df&) | unassigned | BLOCKED | Exclusive bounded family queue: read-only complete native-flow and callback/source constraint audit. Preserve prior budgets and fixture limits; no compilation or metadata writes. Report each result for coordinator review. | src/game/world/LevelObject.cpp |

| libsanangeles.so | 0x002e7ac5 | Menus::ServiceWeaponShop::Refresh() | unassigned | BLOCKED | Read-only complete native CFG and weapon/widget/localization callbacks, reusing accepted Update interfaces. Prior six forms retained; no compiler or metadata writes. | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002ee061 | Widgets::Dialog::OnEvent(RenderFX::Event&) | unassigned | BLOCKED | Read-only complete native CFG and dialog/event callback lifetime audit. Recover prior forms first; no compiler or metadata writes. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ef0b1 | Widgets::Corruption::UpdateLocalization() | unassigned | BLOCKED | Read-only complete native CFG and localization/Wanted callback snapshots, reusing confirmed Corruption Notify interfaces. Prior forms retained; no compiler or metadata writes. | src/game/ui/MenuWidget.cpp |

| libsanangeles.so | 0x002e8551 | MenuState::OnEvent(RenderFX::Event&) | unassigned | BLOCKED | Read-only complete native CFG and base/event/widget callback snapshots. Preserve existing232-byte typed-getter candidate and prior46 differences; no compiler or metadata writes. | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e86fd | MenuState::GotFocus() | unassigned | BLOCKED | Read-only complete native CFG and focus/widget callback receiver lifetimes. Preserve248-byte candidate and12 known register differences; no compiler or metadata writes. | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002eac65 | Menus::OptionGameSettings::Notify(MenuWidget const*, int) | unassigned | BLOCKED | Read-only complete native CFG and option/localization callback snapshots. Preserve prior tail/receiver investigations; no compiler or metadata writes. | src/game/ui/MenuState.cpp |

| libsanangeles.so | 0x002ea479 | Menus::MainMenu::Notify(MenuWidget const*, int) | unassigned | BLOCKED | Obsolete read-only ownership reconciled against actualworkerdispatches; no currentworker assigned andno newcompiler/source/matching result accepted. Recover historicalaudit before anyfutureassignment. | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002eb12d | Menus::ServiceCarRental::Update() | unassigned | BLOCKED | Independent repaired metadata readback accepted: all358 real instructions778B exact,302 formerly missing bytes restored and explicit self-R0/void ABI. No additional source constraint, trial or matching credit; ownership released. | src/game/ui/MenuState.cpp; _scratch/worker-rental-update-repaired-readback/ |
| libsanangeles.so | 0x002eb761 | Menus::ServiceCarRental::Notify(MenuWidget const*, int) | unassigned | BLOCKED | Sole typed-plus-v4 source control rejected at452/native448 before link. All252 other raw functions, semantic relocations and261 other allocated payloads unchanged;940 frozen inputs stable. Linked owner/GOT/suffix gates skipped, no credit; ownership released. | src/game/ui/MenuState.cpp; _scratch/worker-rental-notify-typed-v4-control/ |

| libsanangeles.so | 0x002fe999 | NPC::freeze() | unassigned | COMPLETED | 100%; coordinator verified function/full224B section in both real linked images. All191 profiles,11114 comparisons and all4286 prior matched catalogue functions exact;1102 frozen inputs stable. Only verified marker removed; all17703 identities retained. Ownership released after acceptance. | src/game/ai/NPC.cpp; docs/matches/npc-freeze.md |
| libsanangeles.so | 0x003009d1 | NPC::SetTarget(LevelObject*) | unassigned | BLOCKED | Reviewed complementary-source census: only final hinted object/image survives; earlier source and logs cannot establish exact donor blocks. No replay or compile, prior six forms retained. Ownership released. | src/game/ai/NPC.cpp; _scratch/worker-npc-settarget-complementary-reuse/ |
| libsanangeles.so | 0x002fe615 | NPC::triggerCombatSFX(int) | unassigned | BLOCKED | Independent metadata readback accepted: all157 real instructions330B and signed28B/seven-case table exact, complete decompile and static type-R0/void ABI restored. Source remains368B/eight differences; no new compile or credit. Ownership released. | src/game/ai/NPC.cpp; _scratch/worker-npc-sfx-switch-readback/ |

| libsanangeles.so | 0x003351dd | VehicleCamera::goToSide(bool) | unassigned | BLOCKED | Independent repaired metadata readback accepted: all133 real instructions300B exact and owned, physical receiver/argument/void ABI persists, complete pseudocode. No new source cause or compilation; ownership released. | src/game/vehicles/VehicleCamera.cpp; _scratch/worker-vehicle-family-repaired-readback/ |
| libsanangeles.so | 0x00335849 | VehicleCamera::update(float) | unassigned | BLOCKED | Independent repaired metadata readback accepted: all387 real instructions900B exact and owned, physical receiver/argument/void ABI persists, complete pseudocode. No new source cause or compilation; ownership released. | src/game/vehicles/VehicleCamera.cpp; _scratch/worker-vehicle-family-repaired-readback/ |
| libsanangeles.so | 0x00309f0d | Vehicle::dropSceneNode() | unassigned | BLOCKED | Reviewed eight actual 328-byte images and five unique payloads. All prefixes already exact; every final-clear source places field844 store before SP restore, opposite retail. No complementary source or new compile; ownership released. | src/game/vehicles/Vehicle.cpp; _scratch/worker-vehicle-drop-complementary-reuse/ |


| libsanangeles.so | 0x002ffe0d | NPC::Update(int) | unassigned | BLOCKED | Complete1320-instruction metadata readback exposed a proven missing common downed-state gate. Sole source correction emits3044/native3012, strict prelink rejected; coordinator verified all73 old raw definitions and1065 frozen inputs. Dependencies152/44 pass; NPC target/owner/GOT gates skipped. Faithful candidate preserved, no credit; ownership released. | src/game/ai/NPC.cpp; _scratch/worker-npc-update-common-downed-control/ |


| libsanangeles.so | 0x0030d6c9 | Vehicle::UpdatePhysic(float) | unassigned | BLOCKED | Independent repaired metadata readback accepted: all3799 real instructions8848B exact and owned, physical receiver/argument/void ABI persists, complete pseudocode. No new source cause or compilation; ownership released. | src/game/vehicles/Vehicle.cpp; _scratch/worker-vehicle-family-repaired-readback/ |


| libsanangeles.so | 0x003ef511 | RenderFX::UpdateCursor(RenderFX::Cursor&, int) | unassigned | BLOCKED | Complete916-instruction readback exposed unconditional fourth-reference update after failed animations. Sole else correction emits1996/native2012; strict prelink rejected, coordinator verified109 old raw definitions. No nativeLD or linked gates; faithful candidate preserved without credit, ownership released. | src/game/rendering/menufx.cpp; _scratch/worker-renderfx-cursor-release-else-control/ |


| libsanangeles.so | 0x00312081 | Vehicle::_processAIFlags() | unassigned | BLOCKED | Complete1345-instruction readback exposed pursuit/wait precedence and wrong late-read destination. Separate approved controls emit3040 then3056/native3220. Coordinator verified197 old raw definitions and925/929 stable inputs; strict prelink stops, no nativeLD/linked gates or credit. Both corrections preserved; ownership released. | src/game/vehicles/Vehicle.cpp; _scratch/worker-vehicle-ai-flags-adjusted-snapshot-control/ |


| libsanangeles.so | 0x00304ec9 | PlayerTest::Update() | /root/event_character_punched | IN_PROGRESS | Bounded read-only event construction/weak-call/lexical-home transfer audit using newly exact punched event block; latest2204 source preserved, no repeated die/guard/DSE grid or compiler permission. | src/game/ai/PlayerTest.cpp; _scratch/worker-player-update-single-die-control/ |


| libsanangeles.so | 0x00313b01 | Vehicle::Update(int) | unassigned | BLOCKED | Damage correction3924/3928 versus native4020 preserved. Dump proves143csa tail sharing; whole-TU no-crossjumping4008 regresses5 old definitions and is rejected. Subsequent98-native/89-actual snapshot audit proves receiver/argument timing faithful, no new source cause. No credit; ownership released. | src/game/vehicles/Vehicle.cpp; _scratch/worker-vehicle-update-visibility-snapshots/ |


| libsanangeles.so | 0x003026b9 | PlayerTest::move(float, float) | unassigned | BLOCKED | Complete1040-instruction/2342B metadata readback accepted; targeted24-join audit and newly complete pseudocode find no new source association gap. Preferred2512/native2496 source remains unmatched with no valid v6ELF or current linked closure. No compiler trial; ownership released. | src/game/ai/PlayerTest.cpp; _scratch/worker-player-move-join-constraints/readback/ |


| libsanangeles.so | 0x002eac65 | Menus::OptionGameSettings::Notify(MenuWidget const*, int) | unassigned | BLOCKED | Reviewed exact457-instruction join audit and1048/native1056 structural census: -16B code,+4B alignment,+4B duplicate literal. All53 direct callees match; indirect difference is faithful shared localization tail, no event-vptr omission or new trial. Ownership released. | src/game/ui/MenuState.cpp; _scratch/worker-options-notify-join-constraints/structure/ |


| libsanangeles.so | 0x0030c035 | Vehicle::step() | unassigned | BLOCKED | Complete1809-instruction/4214B readback accepted. Original4 listed padding records8B plus omitted2B alignment distinguished from referenced literal words; no new source join gap. Preferred4336/native4372 remains unmatched and unlinked under current proof; ownership released. | src/game/vehicles/Vehicle.cpp; _scratch/worker-vehicle-step-join-constraints/readback/ |


| libsanangeles.so | 0x00339cb9 | Script::executeCommand(Structs::ScriptCommand const*, int, int) | unassigned | BLOCKED | Prior cases and frame-home coverage authenticated; highest homes and hidden-result ABI were already analyzed. No new source/storage evidence or compile; preferred12320/native12636 remains unmatched. Ownership released. | src/game/scripting/Script.cpp; _scratch/worker-script-execute-join-constraints/ |


| libsanangeles.so | 0x0030406d | PlayerTest::updateCarInteraction() | unassigned | BLOCKED | Current-context1684 target and68 switch strict-linked; all84/26 owner and four current dependencies exact, but target/fullsection first0x18 and switch0x4 mismatch. Primary object and1109 inputs stable; LF-to-CRLF prefix fidelity limitation disclosed. No credit; ownership released after review. | src/game/ai/PlayerTest.cpp; _scratch/worker-player-carinteraction-join-constraints/ |


| libsanangeles.so | 0x0030d149 | Vehicle::CreateWheels(Box2DUserInfo*) | unassigned | BLOCKED | Independent repaired readback accepted:598 real instructions/1338B plus2 padding and68 literals equal native1408. Physical selfR0/infoR1 and complete CFG verified; no new source discrepancy in1440 candidate. No compiler or credit; ownership released. | src/game/vehicles/Vehicle.cpp; _scratch/worker-vehicle-wheels-join-constraints/ |


| libsanangeles.so | 0x002f661d | Character::switchMoveAnimation() | unassigned | BLOCKED | Repaired computed switch independently verified:548 real instructions/1154B and206 indices/23 targets exact; boolself ABI persists. Restored joins add no new source constraint; known v5/v6 proposals not repeated. No compile/credit, ownership released. | src/game/characters/Character.cpp; _scratch/character-switch-move-lock/ |


| libsanangeles.so | 0x00303bb9 | PlayerTest::switchAnim() | unassigned | BLOCKED | Preferred4correction1076/native1072,79oldraw/485inputs stable. Rawwordcopy andsharedstate3joinnative-localshape achieved. Residual4B genuinealignmentpadding; equal491realinstr/1028code/44literal butblock/registerbytes stilldiffer. NoLD/credit, ownershipreleased afterfinalcensus. | src/game/ai/PlayerTest.cpp |


| libsanangeles.so | 0x002f517d | Character::switchCombatAnimation() | unassigned | BLOCKED | Sharedready corrected1100/native1108 preserved.110oldraw/409inputs stable. Read-only census:6 fewer codebytes+4 fewer literals minus2 extra padding; direct/indirect calls and physicalboolargs agree, no new source cause. NoLD/credit; ownership released. | src/game/characters/Character.cpp |


| libsanangeles.so | 0x002f710d | Character::punch() | unassigned | BLOCKED | Freshrepaired344 real instructions/734B plus2padding/40literals exactnative776, boolself ABI persists. Restoredtail matchesknowncorrected780source; no newsourceconstraint or compile. Callee-type artifacts disclosed; ownership released. | src/game/characters/Character.cpp |


| libsanangeles.so | 0x002f6c45 | Character::punched(int,int,LevelObject*) | unassigned | BLOCKED | Fresh repaired400 instructions/844B plus40literals exactnative884;55indices90..144/6targets and4parameter voidABI verified. Restoredjoins addno newsourceconstraint; known868/basevptr andconstructorattempts preserved. No compile/credit;ownershipreleased. | src/game/characters/Character.cpp |


| libsanangeles.so | 0x002f3489 | Character::updateAnimation(float) | unassigned | BLOCKED | Fresh repaired383real/874B plus2padding/16literal exactnative892; boolselfR0/floatR1 verified. Restoredtails matchtyped896, no newsourceconstraint. Prior6+2 andinvalidoldlinklimits retained; ownershipreleased. | src/game/characters/Character.cpp |


| libsanangeles.so | 0x002f4659 | Character::show() | unassigned | BLOCKED | Fresh repaired252 instructions/544B plus56literal exactnative600, voidselfABI verified. Restoreddoor/listtails addno newsourceconstraint; known12operanddifferences/fiveforms retained. No compile/credit;ownershipreleased. | src/game/characters/Character.cpp |

| libsanangeles.so | 0x00301a75 | PlayerTest::switchContext(eContext,bool) | unassigned | BLOCKED | Nodeindex snapshot corrected876/native900,85oldraw/976inputs independentlystable; freshafterbindindex preserved, noLD/credit. Deleteflow fixed and393real/862B+padding/pool full900retail exact. Alloldcontext/closurelimits retained;ownershipreleased. | src/game/ai/PlayerTest.cpp |


| libsanangeles.so | 0x002f1d91 | Character::setAnimation(int,float,bool,bool,bool) | unassigned | BLOCKED | 178real/378B plus2padding/16literal exactnative396; completeflow andallphysicalargs/B148/149/150stores/callbacksnapshots agreeactual396. Sixforms including3identicalretained, old99/18notcurrentclosure. No compiler/credit;ownershipreleased. | src/game/characters/Character.cpp |


| libsanangeles.so | 0x002f48b1 | Character::initInVehicle(Vehicle*) | unassigned | BLOCKED | Fresh repaired186 instructions/404B plus52literals exactnative456, voidself/vehicleABI verified. Restoredtail agreesactual456 withthreeidenticalforms; no newsourceconstraint or compiler/credit. Ownershipreleased. | src/game/characters/Character.cpp |


| libsanangeles.so | 0x0033ce19 | Script::nextCommand(int) | unassigned | BLOCKED | Fresh110/252B fullnativeinstructioncoverage exact, no pool/pad/gap. Actual254/16relocs identicalarchived; guards/recursion/snapshots/callees agree, no newcause. Returntype unresolved/256section overlap retained, no compile/credit. Ownershipreleased. | src/game/scripting/Script.cpp |


| libsanangeles.so | 0x002f4a79 | Character::positionInVehicle(bool) | unassigned | BLOCKED | Fresh repaired268 instructions/588B plus52literals exactnative640; voidself/boolleftABI verified. RestoreddoorXYZ/PlayerNPCtails agreeactual640, no newsourcecause. Priorfiveattempt/partialclosure limits retained; ownershipreleased. | src/game/characters/Character.cpp |


| libsanangeles.so | 0x003399f1 | Script::rewind() | unassigned | BLOCKED | Reviewed 275 instructions/624 code bytes plus32 literals, all retail-exact. Focused guards, joins, widths and snapshots reveal no new discrepancy; no compile or matching credit. Prior five hierarchy forms preserved; ownership released. | src/game/scripting/Script.cpp |

| libsanangeles.so | 0x00303315 | PlayerTest::getAttackableTarget(LevelObject*,Weapon*,LevelObject*) | unassigned | BLOCKED | Independent OpenCode fresh MCP verifies full700 memory and298 instructions/662 code bytes; complete decompilation equals repaired export. Seven prior forms recovered, preferred696 remains unmatched; no new source constraint or compile. Explicit storage flags remain saved-only evidence. Ownership released after review. | src/game/ai/PlayerTest.cpp; _scratch/opencode-player-readback/ |


| libsanangeles.so | 0x002f4cf9 | Character::throwOutDriver(bool) | unassigned | BLOCKED | Reviewed 128 instructions/284 code bytes plus4 literals, all retail-exact. Driver/vehicle snapshots and physical arguments agree with the candidate; no new correction or compile. Prior six forms and old85/12 closure limits retained; ownership released. | src/game/characters/Character.cpp |


| libsanangeles.so | 0x002f2d95 | Character::die(bool) | unassigned | BLOCKED | Reviewed137 real instructions/310 bytes plus2 padding/12 literals, all retail-exact. Guards, physical arguments and snapshots agree with candidate; three identical prior forms retained. No compile or matching credit; ownership released. | src/game/characters/Character.cpp |

| libsanangeles.so | 0x0033f1ed | ScriptManager::setState(State) | unassigned | BLOCKED | Coordinator committed guarded seven-entry/five-target dispatch34f232 branch/JumpTable repair; five actual ANALYSIS operand-1 refs preserved. Fresh independent full732function/28table,312instruction/698code readback verifies restored four cases plus common-store fifth target. Source constraints unchanged, sixform budget retained; no compile/credit. Ownership released. | src/game/scripting/ScriptManager.cpp; _scratch/opencode-script-readback/; _scratch/opencode-script-switch-readback/ |


| libsanangeles.so | 0x002f26ad | Character::ready(float) | unassigned | BLOCKED | Independent OpenCode fresh MCP verifies133 instructions/272 code bytes, full284 memory and36-byte nine-entry/seven-target table. Source constraints agree; saved linked284 candidate differs at96/106 and two table entries. Prior exhausted forms recovered; no new compile or credit. Ownership released after review. | src/game/characters/Character.cpp; _scratch/opencode-character-readback/ |

| libsanangeles.so | 0x002d4015 | Application::UnRegisterForUpdate(IUpdatable*) | unassigned | BLOCKED | OpenCode reviewed complete recovered budget including complete-TU and inline diagnostics. Actual46/native48 mismatch persists;77 old definitions/semantic relocations stable and five matched relatives exact. No new source constraint, compile or credit. Ownership released after review. | src/game/app/Application.cpp; _scratch/opencode-application-unregister/ |

| libsanangeles.so | 0x002f55d1 | Character::shoot(float,bool) | /root/event_vehicle_destructor | IN_PROGRESS | Bounded read-only event lifetime and helper-lowering audit against newly exact punched event block; preserve accepted HUD guard and current2622/2624 native2608 residual evidence. No source/compiler trial. | nonmatching/characters/Character-shoot-blocked-hud.cpp; _scratch/opencode-character-shoot-hud-guard-control/residual/ |
| libsanangeles.so | 0x003ee721 | RenderFX::SearchIndex::Clear() | unassigned | BLOCKED | Reviewed native180-byte audit and recovered genuine manual180-byte candidate with10 differences at40/42,6a/6c,72..75,88/8a; authentic176 remains preferred interface evidence. End comparison/address ordering already tried; no new source constraint or compile.112 saved functions/24 regions exact,963 inputs stable. Ownership released. | src/game/rendering/menufx.cpp; _scratch/opencode-searchindex-clear/ |
| libsanangeles.so | 0x00303fe9 | PlayerTest::updateAnim(float) | unassigned | BLOCKED | Coordinator committed only actualfalse faddCALL_RETURN303038 clear and nativeThumb continuation decode;30304a alreadyNONE. Independent fresh132memory/54instruction/120code readback verifies restored8instructions/20bytes and fullpseudocode. Wholeprogrammemory/calls/boundaries/ABI unchanged. Authentic116 remains unmatched, oldsix+SDKbudgetretained, no newsourcecause/compile/credit. Ownershipreleased. | src/game/ai/PlayerTest.cpp; _scratch/opencode-player-updateanim/repaired-readback/ |
| libsanangeles.so | 0x003f02c5 | RenderFX::SearchIndex::Init(RenderFX&) | unassigned | BLOCKED | Complete488 native-byte/container/callback/cleanup audit accepted. Authentic492 remains oversized with15 unresolved relocations; enum pair raw/semantic identical. Prior sixforms and authentic escalation recovered,1448inputs stable; no new source constraint or compile. Ownership released. | src/game/rendering/menufx.cpp; _scratch/opencode-searchindex-init/ |
| libsanangeles.so | 0x003efced | RenderFX::UpdateInput(int,int) | unassigned | BLOCKED | Complete852-byte original/source/object ABI/callback/snapshot/lifetime audit accepted; authentic840 and historical852 remain unmatched. Sixforms plus enumreplays recovered, all1458inputs stable. No new sourceconstraint, compile orcredit; ownershipreleased. | src/game/rendering/menufx.cpp; _scratch/opencode-renderfx-updateinput/ |
| libsanangeles.so | 0x0033f511 | ScriptManager::update(int) | unassigned | BLOCKED | Accepted fresh1220memory/506instruction/1128code readback and complete native/source/objectaudit. Preferred1228/1232section, all71relocations and884inputs stable, sixforms recovered. No newsourceconstraint; no compiler/credit. Ownershipreleased. | src/game/scripting/ScriptManager.cpp; _scratch/opencode-scriptmanager-update/ |
| libsanangeles.so | 0x003ed6e5 | RenderFX::Find(char const*,gameswf::character*) | unassigned | BLOCKED | Complete416native-byte/typedname/parentlifetime/source/object audit accepted. Authentic408 remains unmatched; earlierparentnegatives plus sixforms/authentic/enum controls recovered,1780inputs stable. No newsourcecause, compile orcredit. Ownershipreleased. | src/game/rendering/menufx.cpp; _scratch/opencode-renderfx-find/ |
| libsanangeles.so | 0x00302361 | PlayerTest::moveTo(Vehicle const&) | unassigned | BLOCKED | Complete620native/265instruction/596code vector/callback/guard/ABI audit reports no newsourceconstraint. Sixforms628/616/616/616/620/620 recovered; bestv5 has255differences at14, survivingobjectv6 notpairedv5. No compiler/metadata/sourcechange orcredit; ownershipreleased. | src/game/ai/PlayerTest.cpp; _scratch/opencode-player-moveto/ |
| libsanangeles.so | 0x0033ffc1 | ScriptManager::cleanCommand(Structs::ScriptCommand*) | unassigned | BLOCKED | Guarded118/9 switchrepair committed and independentlyfresh212+472memory/90instructions202body/fullpseudocode verified.1888boundedcleanupscenarios agreepreferredsource, no newsourceconstraint. Numericcandidate33differences remainsunmatched; savedrootglobalmetadata/refproof distinguishedfromfreshgetters. No compile/budgetreset/credit; ownershipreleased. | src/game/scripting/ScriptManager.cpp; _scratch/opencode-scriptmanager-clean/ |
| libsanangeles.so | 0x003f0041 | RenderFX::Update(int,bool) | unassigned | BLOCKED | Complete248native-byte/source/object callback/lifetime/width/ABI audit reports no newconstraint; best12/current17 known blocklayout differences remain. Oldbudget/replays retained, no compile/MCP/source/metadatachange orcredit. Ownershipreleased. | src/game/rendering/menufx.cpp; _scratch/opencode-renderfx-update/ |
| libsanangeles.so | 0x00303701 | PlayerTest::PlayerTest(b2World*) C1/C2 aliases | unassigned | BLOCKED | Native376instructions/772code+100literal audit reports no newtype/initializer/ABI constraint. Actualv4 remains864/native872; fourforms828/856/856/864 recovered, all14calls/modes and currentCharacter prerequisites agree. No compile/source/metadatachange or credit; ownershipreleased. | src/game/ai/PlayerTest.cpp; _scratch/opencode-player-constructor/ |
| libsanangeles.so | 0x003ece05 | RenderFX::ForceTexturesToVRAM(bool,gameswf::player_context*) | unassigned | BLOCKED | All256nativebytes audited; old/authenticcandidates identical withtwo known commutedload differences. Guards/reloads/lifetimes/physicalABI unchanged, no newconstraint or compile/credit. Ownershipreleased. | src/game/rendering/menufx.cpp; _scratch/opencode-renderfx-force-textures/ |
| libsanangeles.so | 0x002f4465 | Character::initPhysic() | unassigned | BLOCKED | Complete456native-byte/195instruction/410code audit accepted:best452=408code+44literals, nativeextra2code+2padding. Tenforms and14callees/20layoutvalues/6weakdestructors/3vtables verified. No newsourcecause or trial, budgetretained; ownershipreleased. | src/game/characters/Character.cpp; _scratch/opencode-character-initphysic/ |
| libsanangeles.so | 0x003edde5 | RenderFX::Load(char const*,gameswf::player_context*) | unassigned | BLOCKED | Coordinator reviewed negative independent sibling search: actual loaders establish tu_string but not Load SP20 lifetime; no justified source/compiler trial. Four old forms retained; ownership released. | src/game/rendering/menufx.cpp; _scratch/opencode-renderfx-load/ |
| libsanangeles.so | 0x002ff181 | NPC::_detect() | unassigned | BLOCKED | Full1104native/473instruction/1040code+64literal audit reports no newconstraint. Fourforms recovered;v2/v3/v4 linked1100bodies identical, all57callees/provenanceverified; knownoffsetrecomputation and threeidenticalstop retained. No compiler/source/metadatachange orcredit; ownershipreleased. | src/game/ai/NPC.cpp; _scratch/opencode-npc-detect/ |
| libsanangeles.so | 0x003ed9ed | RenderFX::PreloadGlyphs(unsigned short*,int,char const*,int,bool,bool,gameswf::filter*) | unassigned | BLOCKED | Full492native-byte Unicode/ABI/guard/snapshot/lifetime audit reports no newconstraint. Sixforms/allrevisits recovered; authentic500 remainsoversized, two520probes raw/semanticidentical. No compile/source/metadatachange orcredit; ownershipreleased. | src/game/rendering/menufx.cpp; _scratch/opencode-renderfx-preload-glyphs/ |
| libsanangeles.so | 0x002fde51 | NPC::isUnderCar() | unassigned | BLOCKED | Native416/171instructions408code+8literal geometry/callback/ABI audit reports no newconstraint; all34callees verified. Sixforms exhausted, onlyfinal420relocatedartifact survives, earlier416forms logs-only. No compiler/source/metadatachange orcredit; ownershipreleased. | src/game/ai/NPC.cpp; _scratch/opencode-npc-under-car/ |
| libsanangeles.so | 0x00310909 | Vehicle::shoot() | /root/event_on_despawn | IN_PROGRESS | Bounded read-only event construction/lifetime transfer audit against newly exact Character-punched event block and accepted Vehicle destructor; authenticate prior forms first, no compiler or repeat of position perturbation control. | src/game/vehicles/Vehicle.cpp; _scratch/opencode-vehicle-shoot-perturbation-control/CONTINUATION-REPORT.md |
| libsanangeles.so | 0x00324399 | CHudManager::update(double) | unassigned | BLOCKED | Complete720native-byte/doubleABI/iterator/callback/guard audit reports no newconstraint. Nineartifacthashes/514inputs stable, authentic720 retains14known setup/GOT-register/equivalentjoin differences. No compile/source/metadatachange orcredit; ownershipreleased. | src/game/hud/CHudManager.cpp; _scratch/opencode-hud-update/ |
| libsanangeles.so | 0x0033ddd5 | ScriptManager::loadCommand(DataStream&) | unassigned | BLOCKED | Nineexhaustedforms/provenance verified;1000boundedscenariosagree and951reachable nativeinstructionscovered, notwholeCFG/sourceequivalence. Saved2440/native2436 diagnosticstillfails at2. No newsourceconstraint/compiler/credit; ownershipreleased. | src/game/scripting/ScriptManager.cpp; _scratch/opencode-scriptmanager-load/ |
| libsanangeles.so | 0x0033820d | MissionConditionStayWithin::evaluate(int) | unassigned | BLOCKED | Sixforms/403inputs verified; first240bytes identical and11088bounded suffixscenarios agree, notwholeCFG/sourceequivalenceorNaNconversionproof. Actual524 retains228differences atf0; savedtarget/root9function10region checks pass. No newconstraint/compiler/credit; ownershipreleased. | src/game/missions/MissionConditionStayWithin.cpp; _scratch/opencode-mission-staywithin/ |
| libsanangeles.so | 0x003365f1 | Mission::update(int) | unassigned | BLOCKED | Native536/candidate524 delta accounted:206reachable non-unconditionalinstructions pair, five missing16bitbranches and2paddingbytes. Guards/calls/operands/successors agree withinpairedCFG; saved34functions27regions exact, target/switch remainunmatched. Sixforms+constructorreplay retained, no compiler/credit; ownershipreleased. | src/game/missions/Mission.cpp; _scratch/opencode-mission-update/ |
| libsanangeles.so | 0x003470f9 | SideMission::enableCheckpoints(array<Checkpoint*>&,vector3df) | unassigned | BLOCKED | Sixforms+twoAPIescalations recovered; full332/147instruction audit accounts13differences,23calls unchanged. Twooriginalcallers confirm12B byvaluevector invisiblepointerABI. Savedtarget/root27functions10regions eachpass, targetstillfails92; no newsourcecause/compiler/credit. Ownershipreleased. | src/game/missions/SideMission.cpp; _scratch/opencode-side-mission-checkpoints/ |
| libsanangeles.so | 0x00343141 | WantedLevelManager::onEvent(IEvent const*,EventManager const*) | unassigned | BLOCKED | All142reachable non-unconditionalinstructions and9actiontableedges pair; nativeextra2Bbranch balances2Blesspadding,total368. Saved17functions20regions exact, target/actiontable stillfail1a. Sixforms retained, no newsourcecause/compiler/credit; ownershipreleased. | src/game/missions/WantedLevelManager.cpp; _scratch/opencode-wanted-event/ |
| libsanangeles.so | 0x003130a1 | Vehicle::explode() | unassigned | COMPLETED | 100%; post-jumpTo timeline receiver snapshot yields exact740function/fullsection inprivateandcurrentcanonicalimages. Full191profiles11116comparisons pass with1115stableinputs; all4287oldcreditedselectors plusnewtarget directlyverified. Onlyverifiedmarkerremoved; all17703identities retained andonestatuschange.4288/4550,354058/561716=63.03%; FullyLinked20.39% unchanged. Ownershipreleasedafteracceptance. | src/game/vehicles/Vehicle.cpp; docs/matches/vehicle-explode.md; _scratch/opencode-explode-integration/ |
| libsanangeles.so | 0x0030ae3d | Vehicle::getCollisionRect(vector3df*,float) | unassigned | BLOCKED | Sixforms exhausted, fullnative/actualgeometry/carrier/guard/ABI audit reports no newconstraint. Actual736/native752, oldobject/image differonly46callrelocations; saved189functions113regions separateownerexact nottargetclosure. No compiler/source/metadatachange orcredit; ownershipreleased. | src/game/vehicles/Vehicle.cpp; _scratch/opencode-vehicle-collision-rect/ |
| libsanangeles.so | 0x0032a0f9 | MiniMap::draw2d() const | unassigned | BLOCKED | ONEtwo-statement control confirmsnativepost-GetFrame sprite reload; baselinewholeobject15a201... exact. Corrected1348function/1352section vsnative1380failsstrictprelink,noLD. Allnontargetpayloads/relocs/imports andrawgenuine20Bthunk unchanged;1136inputs stable. Canonicalpendingparent unedited, no credit; ownershipreleased. | _scratch/opencode-minimap-frame-sequence-control/REPORT.md; nonmatching/hud/_ZNK7MiniMap6draw2dEv.cpp |
| libsanangeles.so | 0x0030a731 | Vehicle::isDoorClear(bool,b2Body*) const | unassigned | BLOCKED | Sixforms retained; all180nativeinstructionencodings verified, best388/native396 stillfailsc. Bestobjectclosure hasone nonrelocationbyte discrepancy; no owner/neighborclosure inferred. No newsourceconstraint/compiler/credit; ownershipreleased. | src/game/vehicles/Vehicle.cpp; _scratch/opencode-vehicle-door-clear/ |
| libsanangeles.so | 0x00310e75 | Vehicle::OnDespawn() | unassigned | BLOCKED | Nineforms recovered;308bodies old+revisitv1..v3 identical, only4comparisonoperanddifferences5e/7e/88/ec. NewexplodeTimelineAPI hasnocounterpart; existingrealEvent21 alreadycorrect andnativeonlyderivedvptr. No missingguard/width/ABI/operation or newsourcecause, no compiler; ownershipreleased. | src/game/vehicles/Vehicle.cpp; _scratch/opencode-vehicle-despawn/ |
| libsanangeles.so | 0x00313b01 | Vehicle::Update(int) | unassigned | BLOCKED | ONEevent-contract control3936/3936vsnative4020,strictprelinkfail/noLD. Baseline3924/3928 reproduced; actualbasevptr-ID20-derivedvptr andfreshmanager-before-construction/D1scope verified.199olddefs/226payloads/1448relocs/306imports preservedwithdisclosedsingle-IDcorrespondence; no helpers/binding/flagsdrift. Publicfragmentupdatedandtokenverified; budgetspent/no credit, ownershipreleased. | nonmatching/vehicles/Vehicle-Update-event-contract.md; _scratch/opencode-vehicle-update-event-contract-control/ |
| libsanangeles.so | 0x00311251 / 0x00311499 | Vehicle destructor family D0 / D1-D2 aliases | unassigned | BLOCKED | Mainreviewedpersistentreceipt. ActualD0extent584/D1-D2extent580,562/558matchingbytecountsnotextents; onlyac..c1diffs. Fourforms+contextreplay/identicalstop retained; oldv2headersnotretained,no freshsizeclaim. Saved187/110+supportchecks notcurrent-sourceproof. No newsourcecause/compiler/credit; ownershipreleased. | src/game/vehicles/Vehicle.cpp; _scratch/opencode-vehicle-destructors/ |
| libsanangeles.so | 0x003179d5 | LevelObject::CastRay(vector3df const&,vector3df const&,vector3df&,vector3df&,LevelObject*&,bool) | unassigned | BLOCKED | Mainreviewedpersistentreceipt:641real/1418code+2padding+84literals=1504, savedlivebytesexactnotfreshRPC. Two1484objects raw/73symbolicrelocs identical, frame580vs588. Boundednegative/provenancelimits retained; oldbudgets exhausted,no compiler/credit. Ownershipreleased. | src/game/world/LevelObject.cpp; _scratch/opencode-levelobject-castray/ |
| libsanangeles.so | 0x0030fac9 | Vehicle::CreateBody() | unassigned | BLOCKED | Mainreviewedpersistedreceipt andranreadonlyreproduce.py exit0:1044nativebytes/1040fullobjectsection,3identicalobjects/47calls exactsequence. Six+SDK/enum/lifetime/helperbudgets retained; no newconstraint or linkedtargetclosure, no compile/credit. Ownershipreleased. | src/game/vehicles/Vehicle.cpp; _scratch/opencode-vehicle-create-body/ |
| libsanangeles.so | 0x00310fa9 | Vehicle::disable() | unassigned | BLOCKED | Mainreviewed416native audit/39stableinputs; best416only3CMPoperandbytes34/4a/54 differ, hinted420rejected. Event21 derived-only/lifetimealreadycorrect, newexplode20/Timelinefactsinapplicable. No newconstraint/compiler/credit; ownershipreleased. | src/game/vehicles/Vehicle.cpp; _scratch/opencode-vehicle-disable/ |
| libsanangeles.so | 0x00309a4d | Vehicle::setupSceneNode(int,ISceneNode*,int,void**) | unassigned | BLOCKED | Mainreviewed736byte/300instruction/43call audit;3savedpairsidentical570differencesat14,49relocssame,884inputclosuresstable. NewTimeline/eventAPIunused, allsnapshotsalreadycorrect. Oldbudgets/provenancelimits retained; no compiler/credit, ownershipreleased. | src/game/vehicles/Vehicle.cpp; _scratch/opencode-vehicle-setup-node/ |
| libsanangeles.so | 0x00317fb5 | LevelObject::canGoToPoint(vector3df const&,vector3df&,vector3df&) | unassigned | BLOCKED | Mainreviewed1304real/3022code+6pad+92pool nativeaudit;4actual3120objects/209relocs identical, savedELFs88differences482.65realinstructionoperand/orderdifferences, allbranches/calls unchanged. Budgets/threeidenticalstop retained; no newconstraint/compiler/credit, ownershipreleased. | src/game/world/LevelObject.cpp; _scratch/opencode-levelobject-can-go/ |
| libsanangeles.so | 0x0032da91 | CDrivingControlHandler::onEvent(IEvent const*,EventManager const*) | unassigned | BLOCKED | ONEkey73receivercontrol confirmscapturedvehicleacrosscallbacks/bothflagwrites,126callsequence unchanged. Wholev5baselineobject reproducedexact; control2144function/fullsectionvsnative2172 failsstrict/noLD, frame164vs180.454inputs/allnontargetpayloads/relocs/imports stable; publicprivate-contextdelta preserved. Budgetspent/no credit, ownershipreleased. | nonmatching/input/Driving-key73-visibility-receiver.md; _scratch/opencode-driving-visibility-control/ |
| libsanangeles.so | 0x0032d72d | CControlManager::update() | unassigned | BLOCKED | Mainreviewed6forms/v6actual396/native400, saved18functions6regions exact.175realinstructions+alignment(old176),21calls/event13payload16bytes/guards/snapshots/ABI agree; no newcause/current-sourceclosure/compile/credit. Ownershipreleased. | src/game/input/CControlManager.cpp; _scratch/opencode-control-update/ |
| libsanangeles.so | 0x00334a81 | LockCamera::init(LevelObject*,int) | unassigned | BLOCKED | Mainreviewed23/23oversizedtexts/noerrors:11pendingcataloguehits/1zeroABSbinding/no newCpp/ASM/provenance.72artifactboundedabsence/unknownbudget retained, no compiledcandidatecomparisoninvented. No compiler/source/metadata permission; ownershipreleased. | src/game/core/LockCamera.cpp; _scratch/opencode-lock-camera-init/ |
| libsanangeles.so | 0x003514b9 | CSoundDecoderMSADPCM::Decode(short*,int,bool) | unassigned | BLOCKED | Mainreviewedall652nativebytes/5forms668/668/684/656/656, usev5.onotmutablepoolobject(targetabsent). ABI/PCM/nibble/reload/EOF/loop auditnegative; relocatedvtablefailure notnativeproof. No sixthsourcecause/compile/credit; ownershipreleased. | src/game/audio/CSoundDecoderMSADPCM.cpp; _scratch/opencode-msadpcm-decode/ |
| libsanangeles.so | 0x0032e835 | COnFootControlHandler::onKeyboardEvent(IEvent const*) | unassigned | BLOCKED | Mainreviewed/readonlyproofpassed ninth1324function/fullsectionnative1320,strictfail/noLD/noRetry. Sharedcall/guardbypass/freshcarreads verified, doorunion78->74native72,VY46retained,151calltraces/oldpayloads/importattributes stable. Publictwo-controldelta preserved; nine-formbudgetspent,no credit, ownershipreleased. | nonmatching/input/OnFoot-keyboard-sharing.md; _scratch/opencode-onfoot-door-tail-control/REPORT.md |
| libsanangeles.so | 0x00353095 | SoundManager::_getReadySound(int) | unassigned | BLOCKED | Mainreviewed222/native224/3equivalentformstop; nativepreStopreload knowneliminatedbyFRE/PRE/CSE, notmissingnewquery. Allownership/callback/ABIconstraints alreadyrepresented; saved71/75and73/80closures1078inputs stable. No newcause/compiler/credit, ownershipreleased. | src/game/audio/SoundManager.cpp; _scratch/opencode-ready-sound/ |
| libsanangeles.so | 0x0032f201 | SniperControlHandler::onKeyboardEvent(IEvent const*) | unassigned | BLOCKED | Mainreviewednegativeaudit: bestv2archive400/87differences, dispatchtableexact; workingCppv3notv6/no v2objectclosure; split-alias476unlinked. Budget/threeidenticalstop retained,no newsourcecause/compiler/credit, ownershipreleased. | src/game/input/SniperControlHandler.cpp; _scratch/opencode-sniper-keyboard/ |
| libsanangeles.so | 0x00352a55 | SoundManager::endCutscene() | unassigned | BLOCKED | Mainreviewed236/sixcommutedLDRoperandbytesmismatch50; v3restoredsource/v6objectprovenancetrap, completeunitv3saved73/80checks1078inputs. Allguards/callbacks/ABIrepresented, no newsourcecause/compiler/credit, ownershipreleased. | src/game/audio/SoundManager.cpp; _scratch/opencode-sound-end-cutscene/ |


| libsanangeles.so | 0x00310e75 | Vehicle::OnDespawn(), _ZN7Vehicle9OnDespawnEv | unassigned | BLOCKED | Unchanged-source diagnostic proves CMP orientation originates before RTL, not reload/scheduling; all old payloads preserved. No independent pointer-type evidence or justified source trial. Ownership released. | src/game/vehicles/Vehicle.cpp; src/game/vehicles/VehicleEvents.h |
| libsanangeles.so | 0x00311499 | Vehicle destructor D1/D2 aliases, _ZN7VehicleD1Ev / _ZN7VehicleD2Ev | unassigned | COMPLETED | 100%; coordinator exact native aliases plus D0/table accepted, full191 profiles/11122 comparisons and all4291 credited entries verified. Ownership released. | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x002f6c45 | Character::punched(int,int,LevelObject*), _ZN9Character7punchedEiiP11LevelObject | unassigned | BLOCKED | Coordinator independently reviewed final884-byte candidate, native stack homes and complete event block exact; nine voice-layout bytes still differ. Public unapplied patch preserved; all114/33 plus switch exact, no credit. Controls spent; ownership released. | src/game/characters/Character.cpp; src/game/core/GameEvents.h |

| libsanangeles.so | 0x00311251 | Generated Vehicle deleting destructor, _ZN7VehicleD0Ev; associated _ZTV7Vehicle at0x004ab1f8 | unassigned | COMPLETED | 100%; real584-byte generated D0 and complete192-byte table exact,188-byte table symbol and native four-byte gap preserved. Global gate passed; ownership released. | src/game/vehicles/Vehicle.cpp |
<!-- active-ownership:end -->

The coordinator restored native OctTreeAABBNode depth at offset60 and size64.
All190 profiles/10953 comparisons remain exact,1063 frozeninputs stable. No
constructor body or byte credit changes. See docs/matches/octree-node-depth.md.

The coordinator accepted the CarSoundSettings auxiliary gain declaration correction
after all 190 native profiles and 10,953 existing comparisons passed. This shared
field change adds no matched function or bytes; Init and UpdateTurboSounds remain
unmatched. See docs/matches/car-sound-auxiliary-gain.md.

| Binary/library | Address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | ---: | --- |
| libsanangeles.so | 0x002e3f61 | MenuManager::enableAsianFont(bool) declaration consistency | — | COMPLETED | Existing22B body unchanged; public return corrected void-to-bool to match implementation/nativecaller. Full190profiles/10953comparisons exact,1036stableinputs. No newbytes/status changes; ownership released after coordinator acceptance. | src/game/hud/MenuManager.h; docs/matches/menu-asian-font-return.md |
| libsanangeles.so | 0x0039324d | Catalogue provenance support: logger/file_util/PVRTC candidates (no decompilation) | — | COMPLETED | The eight proven gameswf entries (494 bytes) are reclassified after coordinator review. All 17,703 identities and post-constructor statuses remain unchanged; no matched or linked bytes are added. PVRTC remains deferred. | tools/provenance.py; docs/PROVENANCE-CORRECTIONS.md |
| libsanangeles.so | 0x00375375 | Catalogue provenance support: psmodule.c (no decompilation) | — | COMPLETED | The eight pending PSNames entries (1,060 bytes) are correctly classified as FreeType. The existing 280-byte helper is unchanged. All identities, statuses and native inputs are preserved; 102 tests and report audits pass. | tools/provenance.py; docs/PROVENANCE-CORRECTIONS.md |
| libsanangeles.so | 0x00364bf5 | Catalogue provenance support: ftcache.c (FTC_MruNode_Prepend anchor; no engine decompilation) | — | COMPLETED | Maintainer-approved95-function FreeType correction verified; all17,703 functionidentities/statuses retained, all95 staypending and publicauditlistsall95. Zero matched/linkedbytes added;96tests pass. | tools/provenance.py; tools/layout.py; config/functions.tsv (read-only) |
| libsanangeles.so | 0x004ab060 | EvNPCVehicle construction support (vtable anchor; no out-of-line constructor credit) | — | BLOCKED | Direct and implicit-copy support probes emit identical 56-byte sections and relocations, one event/raise/cleanup, with no retained base-vptr construction sequence. Local copy hypothesis rejected. Four-site native audit confirms mixed retained/elided base-vptr stores; no unique constructor/linkage inference. No game body or shared constructor changed. | src/game/characters/NPCVehicleEvent.h; private probe |
| libsanangeles.so | 0x0034425d | SaveGame::LoadAndApply(char const*) | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/persistence/SaveGame.cpp |
| libsanangeles.so | 0x003069f9 | SpawnPoint::spawn(int) | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/world/SpawnPoint.cpp |
| libsanangeles.so | 0x00300e2d | PlayerTest::addCurrentDriftDistance | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00300e4d | PlayerTest::addCurrentJumpDistance | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00419e70 | Shared tutorialPartFormat data prerequisite | — | BLOCKED | Preservation review accepted privately: 640 functions, 421 regions and 832 allocated payloads unchanged. No accepted consumer requires external linkage yet, so no root integration or progress credit. | src/game/ui/MenuWidget.cpp; src/game/ui/MenuState.cpp; shared declaration header (private) |
| libsanangeles.so | 0x002fe269 | NPC::equipWeapon(bool, bool) | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002e41f1 | gameswf::tu_string constructor/layout preservation prerequisite | — | COMPLETED | Historical union accepted after 190 profiles and 10,656 native comparisons; all prior matches and linked proofs preserved. Actual 16-byte ABI assertions pass; no new game credit. | src/game/rendering/RetailSwfString.h |
| libsanangeles.so | 0x003b1e41 | gameswf::font::get_glyph historical-source support | — | COMPLETED | Older source confirms POD rectangle but not retail glyph hierarchy; native entity48 nonowning and word56 provider clearing clarified. No new constructor/ownership correction or trial. | native support evidence |
| libsanangeles.so | 0x00389b01 | gameswf::tu_string::resize(int) verification support | — | COMPLETED | Pinned2008 source has exact tag-first layout and four native resize transition algorithms; constructor/allocator differences remain. No compiled match or game credit. | native support evidence |
| libsanangeles.so | 0x003d8891 | gameswf::glyph destructor verification support | — | COMPLETED | Native destructor ownership and actual vtable verified independently; vendor evidence only, no game credit. | native support evidence |
| libsanangeles.so | 0x003d8a39 | gameswf::array<glyph>::resize verification support | — | COMPLETED | Native stride60, halfword52 initialization and inline constructor verified; vendor evidence only, no game credit. | native support evidence |
| libsanangeles.so | 0x002e73e1 | gameswf::weak_ptr<gameswf::character>::check_proxy() const | — | COMPLETED | Exact 52-byte executable vendor support body independently verified. This does not add game-progress credit; the owning game target remains unmatched. | src/game/rendering/CharacterParentAccess.h (private trial) |
| libsanangeles.so | 0x00301091 | PlayerTest::setClosestShop(Shop*) | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00332f95 | CameraManager::tappedTarget | — | COMPLETED | 100% | src/game/core/CameraManager.cpp |
| libsanangeles.so | 0x00334a81 | LockCamera::init | — | BLOCKED | Coordinator reran156instruction/native artifact audit: no real init definition in36saved paths; identical old logs are not independent candidates. No new target comparison/size/hash/closure invented; no new source/credit, ownership released. | src/game/core/LockCamera.cpp |
| libsanangeles.so | 0x003351dd | VehicleCamera::goToSide | — | BLOCKED | Coordinator verified both final304B branch-lifetime images: inverted129differences,if/else10; original/unary8differences remains best. Strict fit/real neighbor and26oldmatches/13selectors pass, but target fails. Bounded forms stopped, no credit; ownership released. | src/game/vehicles/VehicleCamera.cpp |
| libsanangeles.so | 0x00333095 | CameraManager::processTouchRelease | — | COMPLETED | 100% | src/game/core/CameraManager.cpp |
| libsanangeles.so | 0x003340c1 | FPSCamera::exit | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x0033530d | VehicleCamera::init | — | COMPLETED | 100% | src/game/vehicles/VehicleCamera.cpp |
| libsanangeles.so | 0x00305ccd | Shop::triggered | — | COMPLETED | 100% | src/game/ui/Shop.cpp |
| libsanangeles.so | 0x00301759 | PlayerTest::justStoleCar | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00332cf5 | CameraManager::getClickedTarget | — | BLOCKED | 668/672B; authentic SDK center helper form leaves whole assembly/object/ELF identical; old27/9 exact, no credit | src/game/core/CameraManager.cpp |
| libsanangeles.so | 0x003336ad | FollowCamera::getFacing | — | COMPLETED | 100%;220-byte function and complete section exact, recovered crossProduct reused. Combined190-profile/10943-comparison native gate passes with959inputs stable. Ownership released after coordinator acceptance. | src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x00335769 | VehicleCamera::getFacing | — | COMPLETED | 100%;220-byte function and complete section exact via matched sibling reuse. Ordinary private declaration adds no storage/virtual slot. Combined190-profile/10943-comparison gate passes; ownership released after acceptance. | src/game/vehicles/VehicleCamera.cpp; src/game/core/CameraVariants.h |
| libsanangeles.so | 0x00333f71 | FPSCamera::enter | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x00333fed | FPSCamera::init | — | COMPLETED | 100% | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x00305e29 | Shop::trigger | — | COMPLETED | 100% | src/game/ui/Shop.cpp |
| libsanangeles.so | 0x003344f5 | FPSCamera::update | — | COMPLETED | 100% | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x003339bd | FollowCamera::goBehind | — | COMPLETED | 100% | src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x00305cd5 | Shop::getId | — | COMPLETED | 100% | src/game/ui/Shop.cpp |
| libsanangeles.so | 0x003342ad | FPSCamera::zoom (touch list) | — | COMPLETED | 100% | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x0033560d | VehicleCamera::updatePosition | — | COMPLETED | 100% | src/game/vehicles/VehicleCamera.cpp |
| libsanangeles.so | 0x00333e41 | FPSCamera::scroll (touch list) | — | BLOCKED | The real Character receiver and completed float product restore native 280-byte extent, 32-byte pool and all 20 call instructions. Exactly 14 bytes still differ in spills/scheduling, first at +0x1e; all 40 existing comparisons pass. Reviewed uncredited patch and complete evidence preserved; no further form without new evidence. | src/game/core/FPSCamera.cpp; nonmatching/core/FPSCamera-scroll.patch |
| libsanangeles.so | 0x002e3c1d | GSWeaponShopMenu::dtor | — | COMPLETED | 100% | src/game/ui/GSWeaponShopMenu.cpp |
| libsanangeles.so | 0x00335849 | VehicleCamera::update | — | BLOCKED | Correct per-profile prerequisite gate passed190/10,923 after setup recovery. Sixth form retains native968 extent but matches553/968 bytes; all existing owner checks pass. Target and full section fail, first+0x1e. Six-form budget exhausted; preserve evidence, no credit or canonical integration. | src/game/vehicles/VehicleCamera.cpp |
| libsanangeles.so | 0x00334389 | FPSCamera::updateTouchInputs | — | BLOCKED | Coordinator reran native162-instruction/18-call/12-store audit. Saved380/native364B target spills16B into real neighbor; no current closure. Six forms and three-identical stop exhausted, no new compile/credit; ownership released. | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x002e3c49 | GSWeaponShopMenu::ctor | — | COMPLETED | 100% | src/game/ui/GSWeaponShopMenu.cpp |
| libsanangeles.so | 0x00333451 | FollowCamera::updatePosition | — | COMPLETED | 100% | src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x00332771 | CameraManager::update | — | BLOCKED | Coordinator reran actual1120/native1148B comparison, mismatch12; separate current27/9 exact,24 historical inputs stable. Native operations already preserved; no new causal correction/compile/credit; ownership released. | src/game/core/CameraManager.cpp |
| libsanangeles.so | 0x00301a3d | PlayerTest::Stop | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00333789 | FollowCamera::init | — | COMPLETED | 100% | src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x00333ab1 | FollowCamera::update | — | BLOCKED | Real-hierarchy adaptation784/native776; one recovered crossProduct reuse restores776extent but frame196/native204 fails0xe. Owner13functions6sections1GOT exact. Reviewed unapplied patch retained; no credit or further lifetime/ordering forms without new evidence. Ownership released. | src/game/core/FollowCamera.cpp; nonmatching/core/FollowCamera-update.patch |
| libsanangeles.so | 0x002e1571 | GSCarRepairMenu::draw2d(StateMachine const*) | — | COMPLETED | 100%; coordinator independently reproduced136B function/section, then190 profiles/10953 comparisons exact with1033 inputs stable. Final pending car-repair function; complete1330B unit, no hints or existing-body edits. Ownership released after acceptance. | src/game/ui/GSCarRepairMenu.cpp; docs/matches/car-repair-draw2d.md |
| libsanangeles.so | 0x00334c25 | LockCamera::update | — | BLOCKED | Coordinator reran native and36-artifact audit:148instructions/28calls account for current interfaces; no real update definition survives, so no fresh target comparison or size/hash invented. Three historical failures retained; no new source/credit, ownership released. | src/game/core/LockCamera.cpp |
| libsanangeles.so | 0x003017ed | PlayerTest::jumpFinished | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301821 | PlayerTest::driftFinished | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301855 | PlayerTest::addDistanceDriven | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301ebd | PlayerTest::setLastUsedVehicle | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003017b1 | PlayerTest::onTargetReached | — | BLOCKED | Original-compiler GDB trace completed with same60/payloads/relocs and342/112 old checks. Actual priorities5555(this)/3333(offset)/625(zero) and live conflicts explain current R4/R5/R6; retail input difference unknown. No source/flag trial justified. | src/game/ai/PlayerTest.cpp (private) |
| libsanangeles.so | 0x003018d1 | PlayerTest::setAnim | — | COMPLETED | 100%; coordinator fifth form uses the genuine vector value copy. All62 bytes and native64-byte physical section match, SHA0e50d2448d90d307aec64981e5bb4349de63db5db3786feaac5b7afb0168315c. Full190/10,925 passes with frozen inputs; verified marker removed. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301f69 | PlayerTest::SetSpeed | — | COMPLETED | 100%; restored native weak/default binding. Integrated declaration-only correction independently proved all 48 bytes and passed 190 profiles/10,687 checks; no body edits or new progress credit. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003019c9 | PlayerTest::stopMoving | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00302685 | PlayerTest::UpdateSceneNode | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003013bd | PlayerTest::ResetPlayerTest | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301f01 | PlayerTest::setVehicle | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003025cd | PlayerTest::isFacingTarget | — | BLOCKED | Coordinator reran native/artifact audit: prior184/192B failures survive only as logs, no real target definition remains; native import is not proof. Current hierarchy/vector operations already agree, separate84functions/26regions exact. No new source/compile/credit; ownership released. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x002f42cd | Character::updatePosition | — | COMPLETED | 100% | src/game/characters/Character.cpp |
| libsanangeles.so | 0x00301911 | PlayerTest::initDriving | — | BLOCKED | Coordinator reran nine-image audit: best184B has four register-operand differences at0x66; five forms identical, no new semantic discrepancy. Separate84functions/26regions exact,45inputs stable. No new compile/credit; ownership released. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00334fe9 | SceneCamera::Load | — | COMPLETED | 100%; all96 native bytes independently verified in root. Full190/10,917 pass; actual GS3D COMDAT provider and generatedcleanup36 preserved. Completes original15-entry/646-byte source group. | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x0031ff49 | PhysicAttributes::GetHeight(const vector3df&, int, bool) | — | BLOCKED | Coordinator reran audit: five historical failures, no actual target definition in105 inspected artifacts; current native import is not C++ proof. Existing saved38functions/11regions exact. No new candidate; ownership released. | src/game/characters/PhysicAttributes.cpp; _scratch/worker-physics-height-current |
| libsanangeles.so | 0x00334fa1 | SceneCamera::SceneCamera (C1/C2 aliases) | — | COMPLETED | 100% | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x00334f71 | SceneCamera::~SceneCamera (D1/D2 aliases) | — | COMPLETED | 100% | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x0031a67d | PhysicAttributes::IsPositionOnJump | — | BLOCKED | Five logs but only two unmapped source artifacts survive; last three forms demonstrably not all identical. Actual vector APIs and float ABI reveal no new gap; no justified source replay. | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x00334f29 | SceneCamera::~SceneCamera (D0) | — | COMPLETED | 100% | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x00334f5c | SceneCamera::~SceneCamera (D1 thunk) | — | COMPLETED | 100% | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x00334f14 | SceneCamera::~SceneCamera (D0 thunk) | — | COMPLETED | 100% | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x00334ee5 | SceneCamera::init | — | COMPLETED | 100% | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x00334ee9 | SceneCamera::debug | — | COMPLETED | 100% | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x00334eed | SceneCamera::update | — | COMPLETED | 100% | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x0031ccf1 | PhysicAttributes::SetCurrentJumpShape | — | COMPLETED | Existing100%; five-vector storage maps corners0..3 and center4. Only final destination spelling changed; all644 native bytes independently preserved and root190/10,690 pass. | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x00301df9 | PlayerTest::finishedStopDriving | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301261 | PlayerTest::_SetTarget | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x0030142d | PlayerTest::applyDamage | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301eec | PlayerTest::setVehicle (secondary thunk) | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301a28 | PlayerTest::Stop (secondary thunk) | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301418 | PlayerTest::applyDamage (secondary thunk) | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301101 | PlayerTest::getCarAnimName | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003015e5 | PlayerTest::~PlayerTest (D1/D2 aliases) | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x0030a3e5 | Vehicle::mobilize | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00309189 | Vehicle::stopDriving | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030a491 | Vehicle::cleanTargets | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030b22d | Vehicle::getNearestDoorDummy | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00307b88 | Vehicle::getMarkerType (secondary thunk) | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x003090e9 | Vehicle::_cleanupSounds | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00349051 | TrailMgr::FreeTrail | — | COMPLETED | 100% | src/game/world/TrailMgr.cpp |
| libsanangeles.so | 0x00348f95 | TrailMgr::TrailMgr (C1/C2 aliases) | — | COMPLETED | 100% | src/game/world/TrailMgr.cpp |
| libsanangeles.so | 0x00349231 | TrailMgr::AllocTrail | — | COMPLETED | 100% | src/game/world/TrailMgr.cpp |
| libsanangeles.so | 0x003490f9 | TrailMgr::Update | — | COMPLETED | 100% | src/game/world/TrailMgr.cpp |
| libsanangeles.so | 0x003490dd | TrailMgr::~TrailMgr (D1/D2 aliases) | — | COMPLETED | 100% | src/game/world/TrailMgr.cpp |
| libsanangeles.so | 0x00349121 | TrailMgr::SetSegmentWidth | — | COMPLETED | 100% | src/game/world/TrailMgr.cpp |
| libsanangeles.so | 0x00349271 | TrailMgr::Render | — | BLOCKED | One explicit count-cache escalation reproduces the same48/native56 bytes as the three guard forms; prelink3, no link or body/header closure. Native two latches remain merged. No credit or further local loop variants. | nonmatching/world/TrailMgr-Render-count-cache.patch; src/game/world/TrailMgr.cpp |
| libsanangeles.so | 0x003490b9 | TrailMgr::~TrailMgr (D0) | — | COMPLETED | 100% | src/game/world/TrailMgr.cpp |
| libsanangeles.so | 0x00349149 | TrailMgr::CleanUp | — | COMPLETED | 100% | src/game/world/TrailMgr.cpp |
| libsanangeles.so | 0x00348fb5 | TrailMgr::AllocTrailList | — | BLOCKED | Coordinator checked the actual linked candidate: 152/native154 bytes, identical to the old hinted form; mismatch at0x6. Genuine-type unhinted form160B fails strict link. Existing14functions/6regions and12modelvalues preserved; no credit, ownership released. | src/game/world/TrailMgr.cpp |
| libsanangeles.so | 0x00349189 | TrailMgr::Init | — | COMPLETED | 100% | src/game/world/TrailMgr.cpp |
| libsanangeles.so | 0x003484e5 | Trail::SetLastAddedPoint | — | COMPLETED | 100% | src/game/world/Trail.cpp |
| libsanangeles.so | 0x00348575 | Trail::~Trail (D1/D2 aliases) | — | COMPLETED | 100% | src/game/world/Trail.cpp |
| libsanangeles.so | 0x00348491 | Trail::ModifyLife | — | COMPLETED | 100% | src/game/world/Trail.cpp |
| libsanangeles.so | 0x00348ef1 | Trail::Init | — | COMPLETED | 100% | src/game/world/Trail.cpp |
| libsanangeles.so | 0x0034854d | Trail::~Trail (D0) | — | COMPLETED | 100% | src/game/world/Trail.cpp |
| libsanangeles.so | 0x00348489 | Trail::SetSegmentWidth | — | COMPLETED | 100% | src/game/world/Trail.cpp |
| libsanangeles.so | 0x0034848d | Trail::Render | — | COMPLETED | 100% | src/game/world/Trail.cpp |
| libsanangeles.so | 0x00348595 | Trail::Trail (C1/C2 aliases) | — | COMPLETED | 100% | src/game/world/Trail.cpp |
| libsanangeles.so | 0x003484f5 | Trail::CleanUp | — | COMPLETED | 100% | src/game/world/Trail.cpp |
| libsanangeles.so | 0x003485f1 | Trail::Update (no arguments) | — | BLOCKED | Coordinator reran the retained-image audit:320/native324B fails at0xa; five earlier forms recovered. Native frame and semantic operations already accounted for. Separate16functions/6regions are exact but not target closure; no new compile or credit. Ownership released. | src/game/world/Trail.cpp |
| libsanangeles.so | 0x00348a61 | Trail::AddPoint | — | COMPLETED | 100% | src/game/world/Trail.cpp |
| libsanangeles.so | 0x00348ba5 | Trail::Update (point overload) | — | COMPLETED | 100% | src/game/world/Trail.cpp |
| libsanangeles.so | 0x00348cfd | Trail::CreateMeshSceneNode | — | BLOCKED | Coordinator reran the retained-image audit: actual520/native500B overlaps Trail::Init by20B; mismatch at0x4. Saved disassembly is stale. Separate16functions/6regions remain exact; six earlier forms exhausted, no new source evidence or credit. Ownership released. | src/game/world/Trail.cpp |
| libsanangeles.so | 0x00348735 | Trail::BuildPoint | — | BLOCKED | Coordinator reran the actual-image audit:760/native812B fails at0xc; table/GOT remain exact. Six earlier forms already include the genuine cross-product expression and scalar/UV variants. No new source correction or compile; separate16functions/6regions are not target closure. Ownership released. | src/game/world/Trail.cpp |
| libsanangeles.so | 0x0030a731 | Vehicle::isDoorClear | — | BLOCKED | Coordinator reran the native audit:180instructions/12calls, no semantic correction. Actual best388/native396B fails at0xc. Standalone imports and fitting extent do not prove owner or neighbor closure. No new compile or credit; ownership released. | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030ae3d | Vehicle::getCollisionRect | — | BLOCKED | Coordinator reran retained-image audit:736/native752B fails at0x1c; six forms exhausted with no new semantic discrepancy. Separate188functions/112regions are exact but not target closure. No new compile or credit; ownership released. | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030822d | Vehicle::UpdateCarSounds | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00307bcd | Vehicle::_adjustEnginePitch | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0034f515 | CarSounds::UpdateClutchSound | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034fa8d | CarSounds::UpdateStartupSound | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x00350441 | CarSounds::InitOnOffCrossFadeGains | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034fdf5 | CarSounds::Update | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x00350381 | SoundFade::InitFadeGains | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034f151 | CarSoundParameters::CarSoundParameters (C1/C2 aliases) | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034f155 | CarSoundParameters::~CarSoundParameters (D1/D2 aliases) | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034f205 | SoundFade::StartFade | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034f251 | SoundFade::Update | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034f2dd | CarSounds::FilterRPMValues | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034f1ed | SoundFade::SoundFade (C1/C2 aliases) | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034f1f5 | SoundFade::~SoundFade (D1/D2 aliases) | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034f1f9 | SoundFade::GetNbRemainingFades | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034f1fd | SoundFade::GetState | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034f201 | SoundFade::GetVolume | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x003501e9 | SoundFade::Clean | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034f361 | CarSounds::InterpolateLinear | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034fb61 | CarSounds::InterpolateFlatEnded | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034ff89 | CarSounds::SetRPMFilterCoefficients | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0035020d | CarSounds::Clean | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034f359 | CarSounds::RemoveTurboSounds | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034f2a9 | CarSounds::CarSounds (C1/C2 aliases) | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034f3a5 | CarSounds::StopAllSounds | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034f9a5 | CarSounds::UpdateRumbleSound | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x003502a9 | CarSounds::~CarSounds (D1/D2 aliases) | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034f555 | CarSounds::UpdateOffEngineSounds | — | BLOCKED | Third canonical560B form unchanged506/560; native typed fields established, all242oldfunctions123sections2GOT pass; no new source evidence, parked | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034f785 | CarSounds::UpdateOnEngineSounds | — | BLOCKED | Six source forms reviewed; the surviving fifth candidate is 544 bytes with 52 differing bytes. No new semantic or API correction was found; parked without credit. | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034fbf9 | CarSounds::UpdateTurboSounds | — | BLOCKED | Coordinator reran real-definition audit: recovered500/native508B candidate fails at0xc and15 existing checks; no closure. Initial empty-import hash explicitly rejected. Native field240 float-use evidence retained; no new source compile or credit. Ownership released. | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x00350019 | CarSounds::AddTurboSounds | — | BLOCKED | Coordinator independently checked the one genuine-float replay:468/native464B object and15semanticrelocations identical to old source. Strict link fails extent and actual neighbor overlap; no target ELF or credit. Current54functions/12sections/1GOT baseline exact. Ownership released. | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0035047d | CarSounds::Init | — | BLOCKED | Coordinator reran actual-definition audit:1032B candidate differs eight addressing bytes from0xb2. Native settings192->CarSounds288->float multiplication supports a separate shared declaration correction; no target replay or match credit. Ownership released. | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x00308999 | Vehicle::InitV6naSounds | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00308bb1 | Vehicle::Init4CylNaSounds | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00308701 | Vehicle::InitV6TurboSounds | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0034f159 | CarSoundSettings::CarSoundSettings (C1/C2 aliases) | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x00350239 | CarSoundSettings::~CarSoundSettings (D1/D2 aliases) | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0030840d | Vehicle::InitV8Z06Sounds | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0034f175 | TurboSoundSettings::TurboSoundSettings (C1/C2 aliases) | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0035021d | TurboSoundSettings::~TurboSoundSettings (D1/D2 aliases) | — | COMPLETED | 100% | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x00311149 | Vehicle::startDriving | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00312fb9 | Vehicle::playHorn | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00310e75 | Vehicle::OnDespawn | — | BLOCKED | Coordinator reran nine-image audit: best308B differs only four comparison-operand bytes. Earlier comparison/hint grids exhausted. Separate current188functions/112regions exact, not target closure. No new source correction or credit; ownership released. | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00309f0d | Vehicle::dropSceneNode | — | BLOCKED | Coordinator reran eight-image audit: best328B differs only four scheduling bytes at0x128 after six revisits. Native does not individually drop animators. Separate188functions/112regions exact, not target closure; no new compile/credit. Ownership released. | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x003092b5 | CCarFactory::createMorph | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00311eb1 | CCarMorphingMesh::~CCarMorphingMesh (D1) | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030b12d | Vehicle::debug | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00309231 | CustomSkinnedMeshSceneNode::CustomSkinnedMeshSceneNode (C1) | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00310fa9 | Vehicle::disable | — | BLOCKED | Coordinator reran immutable-image audit: best416B differs only three comparison bytes; hinted420B regression rejected. Native cleanup/call ordering already correct. Root current closure skipped during full gate; no new compile or credit. Ownership released. | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00309601 | Vehicle::UpdateCarTireTrails | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030b9a5 | Vehicle::repair | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00312d19 | Vehicle::playDriveSfx | — | BLOCKED | Coordinator reran actual-image audit:680/656/668B candidates versus672 native, all fail at0xe. Earlier forms already preserve cache refresh and callback rereads; no new semantic/type correction or compile. No current closure or credit; ownership released. | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x003130a1 | Vehicle::explode | — | BLOCKED | Coordinator reran canonical coverage/target audit: corrected health224 and ordinary event construction,740B target still fails0x20. Existing188functions/112regions exact;190unique canonical header profiles/10953comparisons exact after documented harness repair. Unapplied candidate only, no credit; ownership released. | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00309a4d | Vehicle::setupSceneNode | — | BLOCKED | Coordinator reran current-context proof: genuine animator ownership and existing factory getter remove invented interfaces, but complete736B target equals old candidate and fails0x14. Existing188functions/112regions exact; strict extent/neighbor fit. Unapplied candidate only, no credit; ownership released. | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00311e41 | CCarMorphingMesh::~CCarMorphingMesh (virtual D0 thunk) | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00311e55 | CCarMorphingMesh::~CCarMorphingMesh (D0) | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00311e9d | CCarMorphingMesh::~CCarMorphingMesh (virtual D1 thunk) | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030b68d | Vehicle::ResetBodyPosition | — | BLOCKED | Coordinator reran actual four forms788/772/796/784 versus792B and native330-instruction audit. Two slots remain but no concrete source/helper hypothesis; all three actual SetXForm points already distinct, no padding. Old188/112 omit newcollision, no current closure. No compile/credit; ownership released. | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00311fb5 | CustomSkinnedMeshSceneNode::~CustomSkinnedMeshSceneNode (D1) | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030bccd | Vehicle::setSpeed | — | BLOCKED | Coordinator reran actual-image audit: two real880/native872B candidates fail at0xc. Genuine physics operations and matched velocity-write relatives already present; no new causal source correction, compile or current closure. Ownership released. | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00310499 | Vehicle::grabSceneNode | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030fac9 | Vehicle::CreateBody | — | BLOCKED | Reviewed SDK-source/word-enum model1040/native1044; real weak SDK destructors and436B frame, four-byte pre-wheel size deficit. Current-main/getter replays identical; no link, helper/header closure or credit. Reject1050B strong-binding pragma form. | nonmatching/vehicles/Vehicle-CreateBody-sdk-reuse.patch; src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00310909 | Vehicle::shoot | — | BLOCKED | Coordinator reran actual-image audit: canonical PlayerEvent trial1116/native1140B fails0xc. Existing188/112 plus verified helpers total190functions/115regions exact; D2 is physical D1 alias with no distinct credit. No match; ownership released. | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0032f0e1 | SniperControlHandler::handleStickMove | — | COMPLETED | 100% | src/game/input/SniperControlHandler.cpp |
| libsanangeles.so | 0x0032f0e5 | SniperControlHandler::handleStickReleased | — | COMPLETED | 100% | src/game/input/SniperControlHandler.cpp |
| libsanangeles.so | 0x00305cc5 | Shop::unlocked | — | COMPLETED | 100% | src/game/ui/Shop.cpp |
| libsanangeles.so | 0x002e738d | Menus::MainMenu::GameContinue | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002f1445 | LevelObject::setAnimation (int overload) | — | COMPLETED | 100% | src/game/world/LevelObject.cpp |
| libsanangeles.so | 0x002f7505 | LevelObject::setAnimation (string overload) | — | COMPLETED | 100% | src/game/world/LevelObject.cpp |
| libsanangeles.so | 0x0032cb7d | Wheel::~Wheel (D1) | — | COMPLETED | 100% | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x00305d81 | Shop::Load | — | COMPLETED | 100% | src/game/ui/Shop.cpp |
| libsanangeles.so | 0x0032caf1 | Wheel::setHand | — | COMPLETED | 100% | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x0032cba9 | Wheel::update | — | COMPLETED | 100% | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x0032d0f9 | EvWheelReleased::~EvWheelReleased (D1) | — | COMPLETED | 100% | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x0032cbe1 | Wheel::Wheel (C1/C2 aliases) | — | BLOCKED | Coordinator reran native and four-image alias audit:108instructions/14calls, best256B remains mismatched after six forms. Original unsigned conversion does not prove unique member type. No fresh source correction, compile or current closure; ownership released. | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x0032d131 | Wheel::processTouchRelease | — | COMPLETED | 100% | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x0032cf95 | EvWheelTurn::~EvWheelTurn (D1) | — | COMPLETED | 100%; full 190-profile, 10,501-comparison native gate exact; existing event destructor bodies preserved; unmatched parents receive no credit | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x0032cfcd | Wheel::processTouch | — | BLOCKED | Unmatched. Bounded diagnostics/source tests frozen; all existing matches preserved; no new credit | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x0032ccf5 | Wheel::draw2d | — | COMPLETED | 100% | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x0032cf69 | EvWheelReleased::~EvWheelReleased (D0) | — | COMPLETED | 100% | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x0032d18d | EvWheelTurn::~EvWheelTurn (D0) | — | COMPLETED | 100%; full 190-profile, 10,501-comparison native gate exact; existing event destructor bodies preserved; unmatched parents receive no credit | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x0032d11c | Wheel::processTouchRelease (thunk) | — | COMPLETED | 100% | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x0032cb24 | Wheel::~Wheel (D0 thunk) | — | COMPLETED | 100% | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x0032cb39 | Wheel::~Wheel (D0) | — | COMPLETED | 100% | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x0032cb68 | Wheel::~Wheel (D1 thunk) | — | COMPLETED | 100% | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x00305d55 | Shop::Shop (C1/C2 aliases) | — | COMPLETED | 100% | src/game/ui/Shop.cpp |
| libsanangeles.so | 0x002f769d | Checkpoint::~Checkpoint (D1/D2 aliases) | — | COMPLETED | 100% | src/game/missions/Checkpoint.cpp |
| libsanangeles.so | 0x00305df1 | Shop::~Shop (D1/D2 aliases) | — | COMPLETED | 100% | src/game/ui/Shop.cpp |
| libsanangeles.so | 0x002f76bd | Checkpoint::Checkpoint (C1/C2 aliases) | — | COMPLETED | 100% | src/game/missions/Checkpoint.cpp |
| libsanangeles.so | 0x002f7601 | Checkpoint::Load | — | COMPLETED | 100% | src/game/missions/Checkpoint.cpp |
| libsanangeles.so | 0x002f763d | Checkpoint::grabSceneNode | — | COMPLETED | 100% | src/game/missions/Checkpoint.cpp |
| libsanangeles.so | 0x00305f5d | Shop::Update | — | BLOCKED | Current hierarchy/hint/helper/scoped-if all reproduce384B/single0xea miss. Three GCC frontends identical; unchanged-source RTL shows car at R1 in greg, no later rewrite. Existing20functions6sections1GOT pass; no credit or more source/flag grids. | nonmatching/ui/Shop-Update-current-hierarchy.patch; src/game/ui/Shop.cpp |
| libsanangeles.so | 0x002f7539 | Checkpoint::SetPosition | — | COMPLETED | 100% | src/game/missions/Checkpoint.cpp |
| libsanangeles.so | 0x002f7675 | Checkpoint::~Checkpoint (D0) | — | COMPLETED | 100% | src/game/missions/Checkpoint.cpp |
| libsanangeles.so | 0x00306365 | Shop::~Shop (D0) | — | COMPLETED | 100% | src/game/ui/Shop.cpp |
| libsanangeles.so | 0x002f7569 | Checkpoint::enable | — | COMPLETED | 100% | src/game/missions/Checkpoint.cpp |
| libsanangeles.so | 0x002f7809 | Checkpoint::show | — | COMPLETED | 100% | src/game/missions/Checkpoint.cpp |
| libsanangeles.so | 0x002f76f1 | Checkpoint::Update | — | COMPLETED | 100% | src/game/missions/Checkpoint.cpp |
| libsanangeles.so | 0x002f77b9 | Checkpoint::hide | — | COMPLETED | 100% | src/game/missions/Checkpoint.cpp |
| libsanangeles.so | 0x002f7515 | Checkpoint.cpp __tcf_1 | — | COMPLETED | 100% | src/game/missions/Checkpoint.cpp |
| libsanangeles.so | 0x002e7395 | Menus::MainMenu::SetPause | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e87f5 | Menus::MainMenu::GotFocus | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002ea699 | Menus::MainMenu::Update | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002ea479 | Menus::MainMenu::Notify | — | BLOCKED | Map family follow-up finds the native button-0/button-1 shared pair already correct. Reversed outer event order was already tried in v3; other tails have different results or operations. No new source form justified. | src/game/ui/MenuState.cpp (private) |
| libsanangeles.so | 0x0032cce0 | Wheel::draw2d (thunk) | — | COMPLETED | 100% | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x002e7611 | Menus::OptionGameSettings::SetOrientation (int) | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e75f1 | Menus::OptionGameSettings::SetOrientation (enum) | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e7355 | Menus::OptionGameSettings::GetOrientation | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x00305ca5 | Shop::resetAchievementCounters | — | COMPLETED | 100% | src/game/ui/Shop.cpp |
| libsanangeles.so | 0x00306341 | Shop::lock | — | COMPLETED | 100% | src/game/ui/Shop.cpp |
| libsanangeles.so | 0x003060dd | Shop::unlock | — | COMPLETED | 100% | src/game/ui/Shop.cpp |
| libsanangeles.so | 0x002e86bd | Menus::InGameCarRental::Hide | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e86dd | Menus::InGameWeaponShop::Hide | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002dc289 | GS3DStuff::SetCurrentOrientation | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002e8655 | MenuState::Hide | — | COMPLETED | 100%; reviewed native bytes and full190-profile10539-comparison gate exact | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e7cfd | MenuState::UpdateLocalization | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e79d5 | Menus::InfoStatistics::OnFSCommand | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e7a25 | Menus::InfoAchievements::OnFSCommand | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e7a75 | Menus::InfoAbout::OnFSCommand | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002eab21 | Menus::Infos::Update | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e8639 | Menus::Map::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e90cd | Menus::Map::GotFocus | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002ebb31 | Menus::Map::Update | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e8551 | MenuState::OnEvent | — | BLOCKED | Final typed-getter source remains identical to old 232-byte candidate, with 46 differing bytes. All 610 existing dependency functions, 314 sections and five GOT checks pass; parked without credit. | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e7659 | Menus::Achievement::Update | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e7d51 | Menus::Achievement::SetAchievement | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002ea2e5 | Menus::Achievement::Show | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e7815 | Menus::InGameMenu::Notify | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002eb085 | Menus::OptionVolumes::Notify | — | COMPLETED | 100%; complete 168-byte function and physical section using the real Volumes interface. Coordinator full gate passes 190 profiles and 10,670 comparisons; all prior matches retained. | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002eb6a9 | Menus::ServiceCorruption::Notify | — | BLOCKED | Complete widget interface remains 196/native 184. Wanted and Player APIs are already canonical; prior callable cache form was tested. No new genuine interface or dataflow gap found. | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e78ad | Menus::Map::Notify | — | COMPLETED | 100%; native 220-byte function and region exact. Case order 1/2/0/3 selects the native shared tail without hints. Coordinator full 190-profile/10,677-comparison gate and final affected closure pass; independent executable proof exact. | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002eb921 | Menus::ServiceWeaponShop::Notify | — | COMPLETED | 100%; complete 188-byte function/section using real Shop interface and Refresh declaration. Final full gate passes; old function bodies unchanged. | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e76e9 | RenderFX::Event::GetCharacterPath | — | BLOCKED | Authentic 184-byte candidate remains eight bytes short. Read-only ledger attributes the gap to merged return tails and padding; traversal/proxy operations agree. No new semantic or API correction. | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002ea7f5 | Menus::Infos::Notify | — | COMPLETED | 100%; exact 304-byte function and 20-byte switch table; real compiled definition replaces native import. Final 190-profile, 10,675-comparison gate passes. | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002eb9dd | Menus::ServiceMissions::Notify | — | BLOCKED | Signed index restores native 340-byte extent but not bytes; all 1,054 old comparisons pass. Candidate and native agree on calls and loop behavior; no further form authorized. | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002ebf09 | Widgets::Shop::SetAvailabilityText | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ebf0d | Widgets::Shop::GetSelectedItem | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002eef25 | Widgets::Shop::Reset | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002eef45 | Widgets::Shop::Shop (C1/C2 aliases) | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ed17d | Widgets::Shop::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ecb21 | Widgets::Shop::SetItem | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ed6bd | Widgets::Shop::UpdateLocalization | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002f8495 | CustomSkyBoxSceneNode::OnRegisterSceneNode | — | COMPLETED | 100% | src/game/rendering/CustomSkyBoxSceneNode.cpp |
| libsanangeles.so | 0x002f8479 | CustomSkyBoxSceneNode::getType | — | COMPLETED | 100% | src/game/rendering/CustomSkyBoxSceneNode.cpp |
| libsanangeles.so | 0x002f8481 | CustomSkyBoxSceneNode::getBoundingBox | — | COMPLETED | 100% | src/game/rendering/CustomSkyBoxSceneNode.cpp |
| libsanangeles.so | 0x002f8489 | CustomSkyBoxSceneNode::getMaterial | — | COMPLETED | 100% | src/game/rendering/CustomSkyBoxSceneNode.cpp |
| libsanangeles.so | 0x002f8491 | CustomSkyBoxSceneNode::getMaterialCount | — | COMPLETED | 100% | src/game/rendering/CustomSkyBoxSceneNode.cpp |
| libsanangeles.so | 0x002faa61 | CustomSkyBoxSceneNode::clone | — | COMPLETED | 100% | src/game/rendering/CustomSkyBoxSceneNode.cpp |
| libsanangeles.so | 0x002f9591 | CustomSkyBoxSceneNode::render | — | COMPLETED | 100% | src/game/rendering/CustomSkyBoxSceneNode.cpp |
| libsanangeles.so | 0x002fbee9 | CustomSkyBoxSceneNode::~CustomSkyBoxSceneNode (D1) | — | COMPLETED | 100% | src/game/rendering/CustomSkyBoxSceneNode.cpp |
| libsanangeles.so | 0x002fbe29 | CustomSkyBoxSceneNode::~CustomSkyBoxSceneNode (D0) | — | COMPLETED | 100% | src/game/rendering/CustomSkyBoxSceneNode.cpp |
| libsanangeles.so | 0x002fbe01 | CustomSkyBoxSceneNode::~CustomSkyBoxSceneNode (D0 IReferenceCounted thunk) | — | COMPLETED | 100% | src/game/rendering/CustomSkyBoxSceneNode.cpp |
| libsanangeles.so | 0x002fbe15 | CustomSkyBoxSceneNode::~CustomSkyBoxSceneNode (D0 IAttributeExchangingObject thunk) | — | COMPLETED | 100% | src/game/rendering/CustomSkyBoxSceneNode.cpp |
| libsanangeles.so | 0x002fbec1 | CustomSkyBoxSceneNode::~CustomSkyBoxSceneNode (D1 IReferenceCounted thunk) | — | COMPLETED | 100% | src/game/rendering/CustomSkyBoxSceneNode.cpp |
| libsanangeles.so | 0x002fbed5 | CustomSkyBoxSceneNode::~CustomSkyBoxSceneNode (D1 IAttributeExchangingObject thunk) | — | COMPLETED | 100% | src/game/rendering/CustomSkyBoxSceneNode.cpp |
| libsanangeles.so | 0x002faab9 | CustomSkyBoxSceneNode::CustomSkyBoxSceneNode (C2) | — | BLOCKED | Coordinator reran real C2 audit:4988/4992 versus native4936B, mismatch12 and neighbor overrun. Native2066 instruction encodings and geometry1768B verified; no missing source operation or justified trial. No credit; ownership released. | src/game/rendering/CustomSkyBoxSceneNode.cpp |
| libsanangeles.so | 0x002f84c9 | CustomSkyBoxSceneNode::setSkyColor | unassigned | BLOCKED | Retail BGRA/register passing verified; paired legacy-GCC probe changes lowering but cannot establish retail alignment. No type correction or game-header change accepted; review complete, ownership released. | src/game/rendering/CustomSkyBoxSceneNode.cpp |
| libsanangeles.so | 0x002f7a21 | CustomBillboardSceneNode::render | — | COMPLETED | 100% | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002f8405 | CustomBillboardSceneNode::~CustomBillboardSceneNode (D1) | — | COMPLETED | 100% | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002d2999 | LODSceneNode::render | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d299d | LODSceneNode::getLODLevel | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d29a5 | LODSceneNode::ComputeLOD | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d29a9 | LODSceneNode::OnAnimate | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d29c1 | LODSceneNode::setMaxDistance | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d29d9 | LODSceneNode::getType | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d2b11 | LODSceneNode::getBoundingBox | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d2f31 | LODSceneNode::getTransformedBoundingBox | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d2ac9 | LODSceneNode::GetMeshBoundingBox | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d2e95 | LODSceneNode::OnRegisterSceneNode | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d2edd | LODSceneNode::GetMeshTransformedBoundingBox | — | COMPLETED | 100%;84B authentic iterator/list-helper reuse, full190-profile gate and current old checks exact, no flags or layout changes | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d2d61 | LODSceneNode::computeLODLevel | — | BLOCKED | SDK accessor and whole-profile no-copy-prop produce same306B/4 residual bytes; old28/10 exact, copyprop/ivopts causes frozen, no credit | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d2be9 | LODSceneNode::setLODNodesPosition | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d2bad | LODSceneNode::setLODNodesRotation | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d2c25 | LODSceneNode::removeAnimators | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d2c61 | LODSceneNode::addAnimator | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d2b31 | LODSceneNode::LODSceneNode (C2) | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d2c99 | LODSceneNode::addLOD | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d3281 | LODSceneNode::~LODSceneNode (D2) | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002f8351 | CustomBillboardSceneNode::~CustomBillboardSceneNode (D0) | — | COMPLETED | 100% | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002f8315 | CustomBillboardSceneNode::~CustomBillboardSceneNode (D0 IReferenceCounted thunk) | — | COMPLETED | 100% | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002f8329 | CustomBillboardSceneNode::~CustomBillboardSceneNode (D0 IAttributeExchangingObject thunk) | — | COMPLETED | 100% | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002f833c | CustomBillboardSceneNode::~CustomBillboardSceneNode (D0 CSceneNode thunk) | — | COMPLETED | 100% | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002f83c9 | CustomBillboardSceneNode::~CustomBillboardSceneNode (D1 IReferenceCounted thunk) | — | COMPLETED | 100% | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002f83dd | CustomBillboardSceneNode::~CustomBillboardSceneNode (D1 IAttributeExchangingObject thunk) | — | COMPLETED | 100% | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002f83f0 | CustomBillboardSceneNode::~CustomBillboardSceneNode (D1 CSceneNode thunk) | — | COMPLETED | 100% | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002d2f51 | LODSceneNode::LODSceneNode (C1) | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002f800d | CustomBillboardSceneNode::OnAnimate | — | BLOCKED | Unmatched. Bounded diagnostics/source tests frozen; all existing matches preserved; no new credit | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002f7ff8 | _ZThn100_N24CustomBillboardSceneNode9OnAnimateEj | — | COMPLETED | 100%; full 190-profile, 10,501-comparison native gate exact; existing event destructor bodies preserved; unmatched parents receive no credit | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002f7ce9 | CustomBillboardSceneNode::setColor | — | BLOCKED | Coordinator reran retained-image audit: best232B/65differences, first0x16. Six historical forms recovered; stock Irrlicht lacks retail material dirty-cache setter, no new genuine operation or compile. Historical standalone imports are not current closure; ownership released. | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002f7b3d | CustomBillboardSceneNode::CustomBillboardSceneNode (C1) | — | COMPLETED | 100% | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002f7bf1 | CustomBillboardSceneNode::CustomBillboardSceneNode (C2) | — | COMPLETED | 100% | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002f7e51 | CustomBillboardSceneNode::debug | — | COMPLETED | 100% | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002d30d1 | virtual thunk to LODSceneNode::~LODSceneNode (D0) | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d30e5 | virtual thunk to LODSceneNode::~LODSceneNode (D0) | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d30f9 | LODSceneNode::~LODSceneNode (D0) | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d31ad | virtual thunk to LODSceneNode::~LODSceneNode (D1) | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d31c1 | virtual thunk to LODSceneNode::~LODSceneNode (D1) | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d31d5 | LODSceneNode::~LODSceneNode (D1) | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002f96e9 | CustomSkyBoxSceneNode::CustomSkyBoxSceneNode (C1) | — | BLOCKED | Coordinator reran native and geometry audits: 2084 instructions,32 calls and1768 geometry bytes accounted for. Retained5040/native4984B candidate overlaps clone by56B; partial image has no current closure. No causal source correction or new compile; ownership released. | src/game/rendering/CustomSkyBoxSceneNode.cpp |
| libsanangeles.so | 0x002dc591 | GS3DStuff::parseSceneNodeForLOD | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002df34d | GS3DStuff::SetAlpha | — | BLOCKED | One owning-context replay is byte-identical to archived v6: 168 bytes, 34 differences first0x56. Strict current closure preserved; no credit. Historical profile already had word-sized enums. | nonmatching/rendering/GS3DStuff-SetAlpha-owning-context.patch; src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002de5a5 | GS3DStuff::AddToSceneMgr | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002db549 | GS3DStuff::loadPerformanceProfile | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002dbde5 | GS3DStuff::setPerformanceType | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002de919 | GS3DStuff::unload | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002dc715 | GS3DStuff::checkVehicleProximity | — | BLOCKED | Coordinator reran real-image audit: three materially different source forms emit identical584/native580B. Prior failed-link and void/bool return ambiguity preserved; native caller ignores result. No new source correction, compile or credit; ownership released. | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002deba1 | GS3DStuff::checkPickableProximity | — | BLOCKED | Six archived forms reviewed. One bounded named-position/full-delta value capture emits 360 bytes versus native 356 and an extra Character::position() helper. Stopped before owner linking; no native match or owner closure claimed. Private candidate rejected, production inputs unchanged; ownership released after review. | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002dd0c1 | GS3DStuff::checkForDespawn | — | BLOCKED | Coordinator reviewed corrected NPC5/Vehicle3 algorithm and genuine GetPosition API. Final656/native636B fails strict extent; diagnostic overlaps20B of unlinked retail neighbor, not closure. Nonretail wrapper absent; no credit. Ownership released. | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002de6dd | GS3DStuff::PrintNodeProperties | — | BLOCKED | Coordinator reran authentic typed-construction proof:528B still differs four spill bytes; prior corrected POD also four bytes. Correct SSO begin/lifecycle preserved,147oldfunctions/130regions exact, no unsupported helper. All bounded forms stopped, no credit; ownership released. | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002df419 | GS3DStuff::tearDown | — | BLOCKED | Coordinator reran retained-image audit:492B hinted v6 differs131bytes; historical unhinted six-byte near-miss image is absent. Six forms already cover genuine array destruction; SafeDelete would add forbidden semantic writes. No new compile or credit; ownership released. | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002df995 | OctTreeAABB::OctTreeAABB | — | BLOCKED | Coordinator reran actual constructor audit:388/native384B fails0xc and overlaps pending neighbor4B; six forms already include real array lifecycle. No new operation/compile/credit or current closure; ownership released. | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002dce9d | std::string::append(const char*) | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002deebd | GS3DStuff::AddXRef | — | BLOCKED | Coordinator reran actual-image audit:820/native824B fails0xc,181common differences plus4missing; six forms exhausted, no new ownership operation. Historical107/118 is not current closure; no new compile/credit. Ownership released. | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002dcd29 | std::string::_M_append(const char*, const char*) | — | BLOCKED | Reviewed bounded STLport reuse: three source forms have identical 372-byte caller bytes; native extent agrees, but diagnostic link differs at 275 bytes, emits extra helpers and fails existing GOT comparisons. No match credit. Revisit with new inlining/source evidence. | nonmatching/rendering/String-range-append-stlport.* |
| libsanangeles.so | 0x002df655 | OctTreeAABB::OctTreeAABBNode::OctTreeAABBNode | — | BLOCKED | Coordinator reran saved executable alias comparison:812/native832B, mismatch0xe,612 differing common bytes and20 missing. Six forms exhausted; no new compile/credit. Native depth field at60 referred for separate coordinator layout review; constructor ownership released. | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002dad71 | GS3DStuff.cpp::__tcf_8 | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002dc959 | GS3DStuff::DrawBody | — | BLOCKED | Coordinator selected actual928B diagnostic definition and reproduced mismatch12; raw/linked hashes identical to old v6. Current genuine GetPosition adds no helper;147 existing functions/118 owner regions pass,884 stableinputs. Strict936 equality fails, no credit; ownership released. | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002dada9 | GS3DStuff.cpp::__tcf_7 | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x00328df9 | Message::isDisplayed | — | COMPLETED | 100% | src/game/ui/Message.cpp |
| libsanangeles.so | 0x00334ef1 | SceneCamera.cpp::__tcf_1 | — | COMPLETED | 100%; handwritten wrapper replaced by real generated__tcf_0 with explicit native/compiled selector, all36 bytes exact. Both native cleanupaddresses retained; root190/10,917 pass. | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x0034934d | AnimObject::Reset | — | COMPLETED | 100% | src/game/characters/AnimObject.cpp |
| libsanangeles.so | 0x00349445 | AnimObject::IsAnimOver | — | BLOCKED | Coordinator reran actual108/112-byte target failures and378 ordered/unordered branch cases; native receiver/speed/frame semantics agree. Current21/22 exact, no new source/compile/cause or credit; ownership released. | src/game/characters/AnimObject.cpp |
| libsanangeles.so | 0x003f01d1 | MenuFX::GetStateHandler | — | BLOCKED | Authentic ownership source gives 124/142 bytes at limit 70; measured limit-80 probe inlines the checker but emits 168 bytes and fails strict overlap. No profile change adopted. | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x0032cfb8 | _ZThn8_N5Wheel12processTouchEl | — | COMPLETED | 100%; full 190-profile, 10,501-comparison native gate exact; existing event destructor bodies preserved; unmatched parents receive no credit | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x00300bc5 | Path::Load | — | BLOCKED | Genuine SDK whole-vector assignment retains native200extent, four bytes differ at68/6a/72/78 in source/Z registers. All18 existing checks pass; one bounded family trial stopped, no credit or further forms. | src/game/world/Path.cpp |
| libsanangeles.so | 0x0034228d | NPCController::onEvent | unassigned | BLOCKED | Reviewed native CFG and historical candidates; no new semantic cause or compile. Application analysis still omits proven returning delete continuation; original assembly remains authoritative. Ownership released. | src/game/ai/NPCController.cpp; src/game/ai/NPCController.h |
| libsanangeles.so | 0x003511b9 | CSoundDecoderMSADPCM::Init | — | BLOCKED | Six constructor-reuse forms:138/132/132/130/132/132B versus native134; forms2/5/6 exact same raw code and relocations. Retained native placement fails target; old22functions/19regions exact. Reviewed unapplied candidate; no credit or more forms without new evidence. | src/game/audio/CSoundDecoderMSADPCM.cpp; nonmatching/audio/CSoundDecoderMSADPCM-Init.patch |
| libsanangeles.so | 0x0032d72d | CControlManager::update | — | BLOCKED | Coordinator reran native/event audit:176instructions/21calls,396/native400B fails0x6. Selected18realfunctions/6regions exact; six earlier forms recovered, no new causal discrepancy or compile. No credit; ownership released. | src/game/input/CControlManager.cpp |
| libsanangeles.so | 0x00354665 | EventManager::_attach | — | BLOCKED | Coordinator reviewed and reran actual six-image comparisons: forms1–5 identical188/native192B; final192B has97differences. Native fixed inline storage already modeled, no allocation or new source evidence. No fresh compile/current closure/credit; ownership released. | src/game/scripting/EventManager.cpp |
| libsanangeles.so | 0x00354725 | EventManager::_detach | — | BLOCKED | Coordinator reran all six real images284..316B/native316, all mismatch2. Native151instructions/onecall/sixstores verified; no13 current owner definitions present, no current closure/credit. No new correction/compile; ownership released. | src/game/scripting/EventManager.cpp |
| libsanangeles.so | 0x00319dd1 | PhysicInfo::PhysicInfo (C1 only; native C2 absent) | — | COMPLETED | Existing96-byte body moved unchanged to ordinary inline definition, natural weak binding. Root190/10,690 and independent native equality in both images; no output edits or new credit. | src/game/characters/PhysicInfo.h; src/game/characters/PhysicAttributes.cpp (private) |
| libsanangeles.so | 0x0031b29d | PhysicAttributes::PhysicAttributes (C1/C2 aliases) | — | BLOCKED | Canonical260 and all47 old checks/payloads/relocs unchanged under diagnostic. Floatzero154 getsR3 in137lreg, reload picks infoR3/bodyR2 in138greg,149sched2 hoistsbodycopy; no nativeIR cause or further source trial. | src/game/characters/PhysicAttributes.cpp (private) |
| libsanangeles.so | 0x002f2581 | Character::goToCombatIdle | — | BLOCKED | Plain separate handlers leave only function bytes76/9a and8 table bytes different. Two case orders identical; owner113functions31sections1GOT retained. Reviewed unapplied patch, no credit or further ordering variants without new evidence. Ownership released. | src/game/characters/Character.cpp; nonmatching/characters/Character-combat-idle.patch |
| libsanangeles.so | 0x003279f5 | Cash::GetCash | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x003279f1 | Cash::SetCash | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x003279e9 | Cash::SetPosition | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x002d6abd | CCustomMaterialRenderer_VERTEX_COLOR_ALPHA::getVertexAttributeMask | — | COMPLETED | 100% | src/game/core/CCustomMaterialRenderer_VERTEX_COLOR_ALPHA.cpp |
| libsanangeles.so | 0x002d6ab9 | CCustomMaterialRenderer_VERTEX_COLOR_ALPHA::isTransparent | — | COMPLETED | 100% | src/game/core/CCustomMaterialRenderer_VERTEX_COLOR_ALPHA.cpp |
| libsanangeles.so | 0x00305b7d | RenderObject::Render | — | COMPLETED | 100% | src/game/characters/RenderObject.cpp |
| libsanangeles.so | 0x00336dc1 | MissionConditionDriveWell::draw | — | COMPLETED | 100% | src/game/missions/MissionConditionDriveWell.cpp |
| libsanangeles.so | 0x00337d45 | MissionConditionStayBetween::draw | — | COMPLETED | 100% | src/game/missions/MissionConditionStayBetween.cpp |
| libsanangeles.so | 0x00305be9 | RenderObject::RenderObject (C1/C2 aliases) | — | COMPLETED | 100% | src/game/characters/RenderObject.cpp |
| libsanangeles.so | 0x00305bb1 | RenderObject::~RenderObject (D0) | — | COMPLETED | 100% | src/game/characters/RenderObject.cpp |
| libsanangeles.so | 0x00305bd1 | RenderObject::~RenderObject (D1/D2 aliases) | — | COMPLETED | 100% | src/game/characters/RenderObject.cpp |
| libsanangeles.so | 0x00337d5d | MissionConditionStayBetween::onEvent | — | COMPLETED | 100% | src/game/missions/MissionConditionStayBetween.cpp |
| libsanangeles.so | 0x00337d48 | MissionConditionStayBetween::onEvent (thunk) | — | COMPLETED | 100% | src/game/missions/MissionConditionStayBetween.cpp |
| libsanangeles.so | 0x0032d8dd | CDrivingControlHandler::handleAttackReleased | — | COMPLETED | 100% | src/game/input/CDrivingControlHandler.cpp |
| libsanangeles.so | 0x003477b9 | SideMissionManager::debug | — | COMPLETED | 100% | src/game/missions/SideMissionManager.cpp |
| libsanangeles.so | 0x00345f31 | AmbulanceSideMission::end | — | COMPLETED | 100% | src/game/missions/AmbulanceSideMission.cpp |
| libsanangeles.so | 0x003465b1 | DeliverySideMission::end | — | COMPLETED | 100% | src/game/missions/DeliverySideMission.cpp |
| libsanangeles.so | 0x00337eb5 | MissionConditionStayBetween constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/missions/MissionConditionStayBetween.cpp |
| libsanangeles.so | 0x00345f35 | AmbulanceSideMission::getMoneyReward | — | COMPLETED | 100% | src/game/missions/AmbulanceSideMission.cpp |
| libsanangeles.so | 0x003465b5 | DeliverySideMission::getMoneyReward | — | COMPLETED | 100% | src/game/missions/DeliverySideMission.cpp |
| libsanangeles.so | 0x00338080 | MissionConditionStayBetween destructor (D0 thunk) | — | COMPLETED | 100% | src/game/missions/MissionConditionStayBetween.cpp |
| libsanangeles.so | 0x00338095 | MissionConditionStayBetween destructor (D0) | — | COMPLETED | 100% | src/game/missions/MissionConditionStayBetween.cpp |
| libsanangeles.so | 0x003380fc | MissionConditionStayBetween destructor (D1 thunk) | — | COMPLETED | 100% | src/game/missions/MissionConditionStayBetween.cpp |
| libsanangeles.so | 0x00338111 | MissionConditionStayBetween destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/missions/MissionConditionStayBetween.cpp |
| libsanangeles.so | 0x00345f3d | AmbulanceSideMission::getGoalMessage | — | COMPLETED | 100% | src/game/missions/AmbulanceSideMission.cpp |
| libsanangeles.so | 0x003465bd | DeliverySideMission::getGoalMessage | — | COMPLETED | 100% | src/game/missions/DeliverySideMission.cpp |
| libsanangeles.so | 0x00337db9 | MissionConditionStayBetween::evaluate | — | COMPLETED | 100% | src/game/missions/MissionConditionStayBetween.cpp |
| libsanangeles.so | 0x00345f45 | AmbulanceSideMission::getStartMessage | — | COMPLETED | 100% | src/game/missions/AmbulanceSideMission.cpp |
| libsanangeles.so | 0x003465c5 | DeliverySideMission::getStartMessage | — | COMPLETED | 100% | src/game/missions/DeliverySideMission.cpp |
| libsanangeles.so | 0x00337151 | MissionConditionDriveWell constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/missions/MissionConditionDriveWell.cpp |
| libsanangeles.so | 0x00345f4d | AmbulanceSideMission::getEndMessage | — | COMPLETED | 100% | src/game/missions/AmbulanceSideMission.cpp |
| libsanangeles.so | 0x003465cd | DeliverySideMission::getEndMessage | — | COMPLETED | 100% | src/game/missions/DeliverySideMission.cpp |
| libsanangeles.so | 0x00345f55 | AmbulanceSideMission::getObj1Message | — | COMPLETED | 100% | src/game/missions/AmbulanceSideMission.cpp |
| libsanangeles.so | 0x003465d5 | DeliverySideMission::getObj1Message | — | COMPLETED | 100% | src/game/missions/DeliverySideMission.cpp |
| libsanangeles.so | 0x00337311 | MissionConditionDriveWell destructor (D0) | — | COMPLETED | 100% | src/game/missions/MissionConditionDriveWell.cpp |
| libsanangeles.so | 0x00337359 | MissionConditionDriveWell destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/missions/MissionConditionDriveWell.cpp |
| libsanangeles.so | 0x00345f5d | AmbulanceSideMission::getObj2Message | — | COMPLETED | 100% | src/game/missions/AmbulanceSideMission.cpp |
| libsanangeles.so | 0x003465dd | DeliverySideMission::getObj2Message | — | COMPLETED | 100% | src/game/missions/DeliverySideMission.cpp |
| libsanangeles.so | 0x00336e11 | MissionConditionDriveWell::evaluate | — | COMPLETED | 100% | src/game/missions/MissionConditionDriveWell.cpp |
| libsanangeles.so | 0x00347e59 | TaxiSideMission::end | — | COMPLETED | 100% | src/game/vehicles/TaxiSideMission.cpp |
| libsanangeles.so | 0x00347e5d | TaxiSideMission::getMoneyReward | — | COMPLETED | 100% | src/game/vehicles/TaxiSideMission.cpp |
| libsanangeles.so | 0x00347e65 | TaxiSideMission::getGoalMessage | — | COMPLETED | 100% | src/game/vehicles/TaxiSideMission.cpp |
| libsanangeles.so | 0x00347e6d | TaxiSideMission::getStartMessage | — | COMPLETED | 100% | src/game/vehicles/TaxiSideMission.cpp |
| libsanangeles.so | 0x00347e75 | TaxiSideMission::getEndMessage | — | COMPLETED | 100% | src/game/vehicles/TaxiSideMission.cpp |
| libsanangeles.so | 0x00347e7d | TaxiSideMission::getObj1Message | — | COMPLETED | 100% | src/game/vehicles/TaxiSideMission.cpp |
| libsanangeles.so | 0x00347e85 | TaxiSideMission::getObj2Message | — | COMPLETED | 100% | src/game/vehicles/TaxiSideMission.cpp |
| libsanangeles.so | 0x00346b89 | SideMission::getTimer | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00347ebd | TaxiSideMission::clean | — | COMPLETED | 100% | src/game/vehicles/TaxiSideMission.cpp |
| libsanangeles.so | 0x00347ee9 | TaxiSideMission::TaxiSideMission (C1/C2 aliases) | — | COMPLETED | 100% | src/game/vehicles/TaxiSideMission.cpp |
| libsanangeles.so | 0x00346ba1 | SideMission::getReward | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x003470d1 | SideMission::updateTimer | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00347f11 | TaxiSideMission::dropOff | — | COMPLETED | 100% | src/game/vehicles/TaxiSideMission.cpp |
| libsanangeles.so | 0x00347e41 | TaxiSideMission destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/vehicles/TaxiSideMission.cpp |
| libsanangeles.so | 0x00346fd1 | SideMission::stop | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00347f85 | TaxiSideMission::pickUp | — | COMPLETED | 100% | src/game/vehicles/TaxiSideMission.cpp |
| libsanangeles.so | 0x0034810d | TaxiSideMission::begin | — | COMPLETED | 100% | src/game/vehicles/TaxiSideMission.cpp |
| libsanangeles.so | 0x00346b7d | SideMission::inProgress | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00346b5d | SideMission::init | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00346b09 | SideMission::getRange | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00347619 | SideMission::calculateMoney | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x003476c1 | SideMission::calculateTime | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00346d3d | SideMission::isInCheckpointRange | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00346f05 | SideMission::addNPC | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00346ec5 | SideMission::removeCheckpoint | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00346dd1 | SideMission::addCheckpoint | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00346ce1 | SideMission::fadeInFadeOut | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00346e31 | SideMission::removeNPC | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00346f55 | SideMission::isInCheckpointsRange | — | COMPLETED | 100%; genuine release array size/operator[] reuse restores the final comparison order. All70 function bytes and72 physical bytes match; root190/10,927 passes with945 frozen inputs. Verified marker removed; allocator/storage and existing matched bodies unchanged. | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00346d1d | SideMission::start | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00346b8d | SideMission::finished | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00346e55 | SideMission::getCheckpoints | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00346f9d | SideMission::disableCheckpoints | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x003470f9 | SideMission::enableCheckpoints | — | BLOCKED | Bounded accessor adaptation remains319/332 bytes, first+0x92; existing owner checks pass. The final unsigned-index for-loop API form emits338/native332 and stops before linking. Both preserved privately; no credit or canonical target integration. New evidence required before another form. | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00347245 | SideMission::update | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x003477a1 | SideMissionManager::confirm | — | COMPLETED | 100% | src/game/missions/SideMissionManager.cpp |
| libsanangeles.so | 0x003477ed | SideMissionManager::setNextMissionTimer | — | COMPLETED | 100% | src/game/missions/SideMissionManager.cpp |
| libsanangeles.so | 0x00347815 | SideMissionManager::isInSideMission | — | COMPLETED | 100% | src/game/missions/SideMissionManager.cpp |
| libsanangeles.so | 0x0034783d | SideMissionManager::draw | — | COMPLETED | 100% | src/game/missions/SideMissionManager.cpp |
| libsanangeles.so | 0x00347925 | SideMissionManager::isMissionAvailable | — | COMPLETED | 100% | src/game/missions/SideMissionManager.cpp |
| libsanangeles.so | 0x00347bad | SideMissionManager::update | — | COMPLETED | 100% | src/game/missions/SideMissionManager.cpp |
| libsanangeles.so | 0x00347961 | SideMissionManager::initMission | — | COMPLETED | 100% | src/game/missions/SideMissionManager.cpp |
| libsanangeles.so | 0x003479c5 | SideMissionManager::stop | — | COMPLETED | 100% | src/game/missions/SideMissionManager.cpp |
| libsanangeles.so | 0x00345f95 | AmbulanceSideMission::clean | — | COMPLETED | 100% | src/game/missions/AmbulanceSideMission.cpp |
| libsanangeles.so | 0x00346615 | DeliverySideMission::clean | — | COMPLETED | 100% | src/game/missions/DeliverySideMission.cpp |
| libsanangeles.so | 0x00345fa9 | AmbulanceSideMission::dropOff | — | COMPLETED | 100% | src/game/missions/AmbulanceSideMission.cpp |
| libsanangeles.so | 0x003461f9 | AmbulanceSideMission constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/missions/AmbulanceSideMission.cpp |
| libsanangeles.so | 0x00346805 | DeliverySideMission constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/missions/DeliverySideMission.cpp |
| libsanangeles.so | 0x00345fd5 | AmbulanceSideMission::begin | — | COMPLETED | 100% | src/game/missions/AmbulanceSideMission.cpp |
| libsanangeles.so | 0x00346395 | AmbulanceSideMission::pickUp | — | COMPLETED | 100% | src/game/missions/AmbulanceSideMission.cpp |
| libsanangeles.so | 0x00346655 | DeliverySideMission::begin | — | COMPLETED | 100% | src/game/missions/DeliverySideMission.cpp |
| libsanangeles.so | 0x00346571 | AmbulanceSideMission destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/missions/AmbulanceSideMission.cpp |
| libsanangeles.so | 0x00346629 | DeliverySideMission::dropOff | — | COMPLETED | 100% | src/game/missions/DeliverySideMission.cpp |
| libsanangeles.so | 0x003468c9 | DeliverySideMission::pickUp | — | COMPLETED | 100% | src/game/missions/DeliverySideMission.cpp |
| libsanangeles.so | 0x00346ac9 | DeliverySideMission destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/missions/DeliverySideMission.cpp |
| libsanangeles.so | 0x00347a51 | SafeDelete<AmbulanceSideMission> | — | COMPLETED | 100% | src/game/missions/SideMissionManager.cpp |
| libsanangeles.so | 0x00347b69 | SideMissionManager::start | — | COMPLETED | 100% | src/game/missions/SideMissionManager.cpp |
| libsanangeles.so | 0x00347a71 | SafeDelete<DeliverySideMission> | — | COMPLETED | 100% | src/game/missions/SideMissionManager.cpp |
| libsanangeles.so | 0x00347a91 | SafeDelete<TaxiSideMission> | — | COMPLETED | 100% | src/game/missions/SideMissionManager.cpp |
| libsanangeles.so | 0x00347ab1 | SideMissionManager::clean | — | COMPLETED | 100% | src/game/missions/SideMissionManager.cpp |
| libsanangeles.so | 0x00347b01 | SideMissionManager::init | — | COMPLETED | 100% | src/game/missions/SideMissionManager.cpp |
| libsanangeles.so | 0x0033ecc1 | ScriptManager::unlockFrozenScripts | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033e9c1 | ScriptManager::freezeRunningScripts | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033d105 | ScriptManager::pause | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033ec05 | ScriptManager::rewindRunningScripts | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033e955 | SafeDelete<Script> | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033d2f5 | ScriptManager::drawFade | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033d141 | ScriptManager::playerDrives | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033d271 | ScriptManager::reachRunningCommand(int) | — | BLOCKED | Reviewed current-header replay: plain122/native112B link overlap; prior best112B repeats same10 differing bytes. Existing143 functions/133 sections/1 GOT region exact; unaccepted hint remains private. No credit. | _scratch/worker-running-command-current/README.md; src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033ed19 | ScriptManager::findObject | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033ea89 | ScriptManager::setup | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033f4c9 | ScriptManager::checkScreenPress | — | BLOCKED | Six forms exhausted, three assembly-identical; current bool/dimension/rectangle APIs already modeled, no concrete new source gap; parked | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033fc01 | ScriptManager::getAvailableMissionScripts | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033ef8d | ScriptManager::loadScript | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033f0f9 | ScriptManager::moveObject | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033ed95 | ScriptManager::resetGame | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033fcb1 | ScriptManager::unload | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033fda9 | ScriptManager::tearDown | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033ffc1 | ScriptManager::cleanCommand | — | BLOCKED | Separate54 scoped handlers preserve operations; numeric order212B has33 differing function bytes versus141 archived. Full table also fails. Owner143functions133sections1GOT retained. Reviewed unapplied patch, no credit; ownership released, no further ordering forms without new evidence. | src/game/scripting/ScriptManager.cpp; nonmatching/scripting/ScriptManager-cleanCommand.patch |
| libsanangeles.so | 0x0033fe71 | ScriptManager::draw | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033f1ed | ScriptManager::setState(State) | — | BLOCKED | Semantic audit corrected playerclear383-to-native377; actual732B hash589587...,onechangedliteralbyte+728, stillmismatch+0x20. Oldgraph143functions/133sections/1GOT exact,868stableinputs; no currentrootclosure transfer or credit. | _scratch/worker-manager-set-state-current/README.md; src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033f511 | ScriptManager::update(int) | — | BLOCKED | Coordinator reran actual1228B objects/71 matching relocations and invalid moved-startup diagnostic; strict native1220 fit still fails. Native postcallback state/count/timer semantics correct; old140/132 not fullclosure, separate current143/134 exact,960 stableinputs. No new compile/credit; ownership released. | _scratch/worker-script-update-current/README.md; src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x00339385 | Script destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x003392a1 | Script constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x003399c5 | Script::clearScriptObjectAction | — | COMPLETED | 100% | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x0033999d | Script::setScriptObjectAction | — | COMPLETED | 100% | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x0033922d | Script::setState(State, PlayerTest::eContext) | — | COMPLETED | 100%; exact 58-byte executable and full 60-byte section under original NDK enum-width baseline. Full root190/10951 proof passes; no existing body changes. | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x003398b5 | Script::unsetScriptObjectAction(LevelObject*, eScriptAction) | — | BLOCKED | Reviewed authentic iterator/find reuse:128/native136B,98 overlapping differences plus8 missing bytes. Three complete raw outputs/semantic relocations identical; old27functions/12sections/1GOT region exact,885inputs stable. No credit. | _scratch/worker-unset-action-current/README.md; src/game/scripting/Script.cpp |
| libsanangeles.so | 0x0033ce19 | Script::nextCommand(int) | — | BLOCKED | Reviewed current-interface254/native252B object identical archive; strict256B section overlap, exit2. All4native callers ignore return, so bool vsint unproven; declarations stayprivate. Targeted declaration-only317 comparisons exact, no new game credit. | _scratch/worker-next-command-current/README.md; src/game/scripting/Script.cpp |
| libsanangeles.so | 0x003399f1 | Script::rewind() | — | BLOCKED | Coordinator reran audit: two actual656B images preserve27/27 functions and13/13 regions; best357 differing bytes. Five distinct current forms, one unused slot but no grounded next cause. No credit; ownership released. | _scratch/worker-script-rewind-current/README.md; src/game/scripting/Script.cpp |
| libsanangeles.so | 0x003365a5 | Mission::idle | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x00335d8d | Mission::fail | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x00336345 | Mission::message | — | BLOCKED | Reviewed six forms124/120B; extra same-ID timer tail and scheduling remain, current APIs already correct; no new replay evidence | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x003360c1 | Mission constructor (C1/C2 aliases) | — | BLOCKED | Coordinator verified58 native instructions,24 ordered stores and two AnimObject calls. Six historical forms exhausted; surviving object is rejected flag experiment, no surviving linked target proof. No new source correction; ownership released. | src/game/missions/Mission.cpp; _scratch/worker-mission-constructor-current |
| libsanangeles.so | 0x0033602d | Mission destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x00336141 | getFrameModuleRect | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x00335f91 | Mission deleting destructor (D0) | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x00336961 | Mission::end | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x00335e61 | Mission::load | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x0033620d | Mission::draw | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x003363d1 | Mission::start | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x003365f1 | Mission::update | — | BLOCKED | Coordinator reran actual update audit:524/native536B and24B table fail; six logs do not prove identical missing images. Separate32functions/26regions exact, no new causal correction or compile. Ownership released. | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x00338c41 | Revive::update | — | COMPLETED | 100% | src/game/missions/Revive.cpp |
| libsanangeles.so | 0x0033820d | MissionConditionStayWithin::evaluate | — | BLOCKED | Coordinator reran actual-image/native audit:524B v6 differs228bytes at0xf0; historical v1 agreement is not surviving proof. Six forms exhausted,9functions/10regions separate saved checks exact. No new source/credit; ownership released. | src/game/missions/MissionConditionStayWithin.cpp |
| libsanangeles.so | 0x0032c7fd | WantedMeter::draw2d | — | COMPLETED | 100% | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032c7e8 | WantedMeter::draw2d non-virtual thunk | — | COMPLETED | 100% | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032addd | Reward::update | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032c919 | WantedMeter destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032c851 | WantedMeter::update | — | COMPLETED | 100%; indexed-loop reuse plus permitted likelihood hint, exact80 and full190/10937 preservation | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032ae69 | Reward constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032c8b5 | WantedMeter deleting destructor (D0) | — | COMPLETED | 100% | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032c8a0 | WantedMeter deleting destructor thunk (D0) | — | COMPLETED | 100% | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032c904 | WantedMeter complete destructor thunk (D1) | — | COMPLETED | 100% | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032c961 | WantedMeter constructor (C1/C2 aliases) | — | BLOCKED | Coordinator reran evidence audit: retained historical272B candidate differs48bytes; saved SDK forms268/native272. No causal source correction, fresh C++ compile or current closure; ownership released after review. | src/game/missions/WantedMeter.cpp; _scratch/worker-wanted-meter-current |
| libsanangeles.so | 0x0032b0e1 | Reward destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032ad65 | Reward::setAnim | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032b07d | Reward deleting destructor (D0) | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032b068 | Reward deleting destructor thunk (D0) | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032b0cc | Reward complete destructor thunk (D1) | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032ad75 | Reward::setMessage | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032adb1 | Reward::draw2d | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032ad9c | Reward::draw2d non-virtual thunk | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x00342b09 | WantedLevelManager constructor (C1/C2 aliases) | — | BLOCKED | Coordinator verified native double literals and recovered the correct earlier body: offsets56/64 must be0.0, not10000.0. Retained176B image is semantically invalid; correct184B historical image is missing. No new compile, credit or current closure; ownership released. | src/game/missions/WantedLevelManager.cpp |
| libsanangeles.so | 0x00342e05 | WantedLevelManager::_processWantedLevel | — | COMPLETED | 100% | src/game/missions/WantedLevelManager.cpp |
| libsanangeles.so | 0x00343141 | WantedLevelManager::onEvent | — | BLOCKED | Coordinator reran actual368B target/table failures and historical17/20 plus separate root18/22 exact closures. Six prior forms exhausted,28 stableinputs, no new causal correction/compile/credit; ownership released. | src/game/missions/WantedLevelManager.cpp |
| libsanangeles.so | 0x00342fc9 | WantedLevelManager::update | — | BLOCKED | Coordinator reran actual old/current parent audit:360/native376B, mismatch2. Current18/22 and thunk19/23 closures exact,407 inputs stable. No new causal correction or compile/credit; ownership released. | src/game/missions/WantedLevelManager.cpp |
| libsanangeles.so | 0x00342fb4 | WantedLevelManager::update non-virtual thunk | — | COMPLETED | 100%; real 20-byte ARM thunk; full 187-profile, 10,400-comparison native gate exact; parent remains unmatched | src/game/missions/WantedLevelManager.cpp |
| libsanangeles.so | 0x003ed9a9 | RenderFX fscommand_callback_handler regression | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x00352cad | SoundManager::getNumberOfPlayingSounds | — | BLOCKED | 78/80 bytes; measured VRP2 address-operand commutation, ordinary/dump outputs identical, old71 functions/75 regions pass; no new form justified | src/game/audio/SoundManager.cpp |
| libsanangeles.so | 0x0030b59d | Vehicle translation-unit initializer wrapper | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x003ee801 | RenderFX deleting destructor (D0) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ee885 | RenderFX destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ec961 | RenderFX::Initialize | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x0030b311 | Vehicle translation-unit initializer | — | BLOCKED | Coordinator reran initializer audit: six prior forms exhausted; surviving676/native652B image is relocated3e0001 and cannot prove native comparison. Native has no factory construction; no cleanup changes justified. Separate188/112exact, no new compile/credit; ownership released. | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x003ee1ed | RenderFX::SetTexture | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ee721 | RenderFX::SearchIndex::Clear | — | BLOCKED | Authentic iterator candidate is 176 versus 180 native bytes. All 112 existing functions and 24 region checks pass; generic arrays are unchanged and no further source variant is authorized. | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003edbd9 | RenderFX::PreloadGlyphs(char const*, char const*, int, bool, bool, gameswf::filter*) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003edc7d | RenderFX::PreloadGlyphs() | — | BLOCKED | Authentic const-subscript candidate is 360 bytes with only two differing load-encoding bytes. All 113 old functions and 32 region checks pass; consumers are skipped after target failure. No further trial authorized. | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ed9ed | RenderFX::PreloadGlyphs(unsigned short*, int, char const*, int, bool, bool, gameswf::filter*) | — | BLOCKED | Reviewed single implicit-conversion probe: 520 bytes, identical to prior faithful candidate; native target 492 bytes. Strict native overlap fails, exit 2; no linked proof or matching credit. No further form authorized. | src/game/rendering/menufx.cpp (private) |
| libsanangeles.so | 0x003edde5 | RenderFX::Load | — | BLOCKED | Current16-byte union/sourceAPI already covered in prior typedpass; SP20 identity/lifetime/escape stillunproved. Fourforms276/268/268/268 vs312 have no fullpreservationproof; no new source trial. | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003eeb11 | RenderFX::SetMember(char const*, char const*, int) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003eea49 | RenderFX::SetMember(char const*, char const*, gameswf::as_value&) | — | COMPLETED | 100%; exact 200-byte native target in all three images. Shared destructor hint removed with all previous matches retained; full 190-profile, 10596-comparison coordinator gate passes. No Fully Linked credit. | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ed2f5 | RenderFX::DBG_TraceContextInformation | — | COMPLETED | 100%; exact 124-byte target and both 24-byte physical literal sections verified in three images. Full 190-profile/10,557-comparison gate passes. | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ece05 | RenderFX::ForceTexturesToVRAM | — | BLOCKED | Mutable subscript candidate remains 256 bytes with the same two commuted load encodings. All 113 old functions and 32 region checks pass; consumers skipped after target failure. | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ee98d | RenderFX::SetLocalVariable | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ed1bd | RenderFX::CollectCharacters | — | COMPLETED | 100%; exact 240-byte native definition in all three images, full 190-profile/10,545-comparison gate passes. Original source remains incomplete, so no Fully Linked credit. | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ecb09 | RenderFX::TraceHierarchy | — | COMPLETED | 100%; exact 464-byte native target and seven literal regions in three images. Full 190-profile/10,584-comparison gate passes; no Fully Linked credit added. | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x00327d85 | Cash destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327d41 | Cash deleting destructor (D0) | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327d2c | Cash deleting destructor thunk (D0) | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327d70 | Cash complete destructor thunk (D1) | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327bbd | Cash::update | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327db1 | Cash constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327a71 | Cash::drawCash | — | COMPLETED | 100%; current Application declaration context preserves all bytes and entire Cash object; no source repair. | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327a29 | Cash::AlignRight | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327a4d | Cash::AlignLeft | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327be9 | Cash::draw2d() const | — | BLOCKED | Reviewed canonical current-layout320/native324B replay, same old sixth object. Diagnostic17oldfunctions/6regions and exact20B ARM thunk preserved;884inputs stable. No further grid or credit. | _scratch/worker-cash-draw-current/REVIEW.md; src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327bd4 | Cash::draw2d non-virtual thunk | — | COMPLETED | 100%; real 20-byte ARM thunk; combined 186-profile native gate exact; parent remains unmatched and uncredited | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327621 | Background destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/ui/Background.cpp |
| libsanangeles.so | 0x003275dd | Background deleting destructor (D0) | — | COMPLETED | 100% | src/game/ui/Background.cpp |
| libsanangeles.so | 0x003275c8 | Background deleting destructor thunk (D0) | — | COMPLETED | 100% | src/game/ui/Background.cpp |
| libsanangeles.so | 0x0032760c | Background complete destructor thunk (D1) | — | COMPLETED | 100% | src/game/ui/Background.cpp |
| libsanangeles.so | 0x0032764d | Background constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/ui/Background.cpp |
| libsanangeles.so | 0x003274f1 | Background::update | — | COMPLETED | 100% | src/game/ui/Background.cpp |
| libsanangeles.so | 0x00327569 | Background::draw2d | — | COMPLETED | 100% | src/game/ui/Background.cpp |
| libsanangeles.so | 0x00327554 | Background::draw2d non-virtual thunk | — | COMPLETED | 100% | src/game/ui/Background.cpp |
| libsanangeles.so | 0x0032ab69 | RetroEffect destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/rendering/RetroEffect.cpp |
| libsanangeles.so | 0x0032a9a5 | RetroEffect deleting destructor (D0) | — | COMPLETED | 100% | src/game/rendering/RetroEffect.cpp |
| libsanangeles.so | 0x0032a990 | RetroEffect deleting destructor thunk (D0) | — | COMPLETED | 100% | src/game/rendering/RetroEffect.cpp |
| libsanangeles.so | 0x0032ab54 | RetroEffect complete destructor thunk (D1) | — | COMPLETED | 100% | src/game/rendering/RetroEffect.cpp |
| libsanangeles.so | 0x0032aa99 | RetroEffect constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/rendering/RetroEffect.cpp |
| libsanangeles.so | 0x0032abe9 | RetroEffect::draw2d() const | — | BLOCKED | Verified current324/native332B parent; exact20B ARM thunk and11selectedfunctions/8regions preserved. Both native/candidate totalstack168B, differing saves/local split. Six prior forms exhausted; no relevant overlay/material evidence or fresh compile. | _scratch/worker-retro-draw-current/REPORT.md; src/game/rendering/RetroEffect.cpp |
| libsanangeles.so | 0x0032abd4 | RetroEffect::draw2d non-virtual thunk | — | COMPLETED | 100%; real 20-byte ARM thunk; combined 186-profile native gate exact; parent remains unmatched and uncredited | src/game/rendering/RetroEffect.cpp |
| libsanangeles.so | 0x0032b158 | SlideControl deleting destructor thunk | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b16d | SlideControl deleting destructor (D0) | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b19c | SlideControl complete destructor thunk | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b1b1 | SlideControl complete destructor (D1) | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b1dd | SlideControl::reset | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b1f5 | SlideControl constructor (C1/C2 aliases) | — | BLOCKED | Coordinator reran native/alias audit:219instructions/21calls, no new source discrepancy after six forms. Saved500/native492B constructor is relocated0x380001; current verifier rejects placement. Partial9/13oldfunction checks are not closure; no new compile/credit, ownership released. | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b3e1 | SlideControl::update | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b42d | SlideControl::draw2d | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b418 | SlideControl::draw2d non-virtual thunk | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b5ad | SlideControl::processTouchRelease | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b598 | SlideControl::processTouchRelease non-virtual thunk | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b665 | SlideControl::processTouch | — | BLOCKED | Unmatched. Bounded diagnostics/source tests frozen; all existing matches preserved; no new credit | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b650 | _ZThn8_N12SlideControl12processTouchEl | — | COMPLETED | 100%; full 190-profile, 10,501-comparison native gate exact; existing event destructor bodies preserved; unmatched parents receive no credit | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x00326581 | AnalogStick constructor (C1/C2 aliases) | — | BLOCKED | Coordinator reran native/alias audit:360B candidate differs147bytes at0xbb after six forms. Base division versus handle arithmetic shift already correct. Selected26functions/36regions exact, release selectors omitted; no new compile or credit. Ownership released. | src/game/input/AnalogStick.cpp |
| libsanangeles.so | 0x00326d3d | AnalogStick::processTouchRelease | — | COMPLETED | 100% | src/game/input/AnalogStick.cpp |
| libsanangeles.so | 0x00326d28 | AnalogStick::processTouchRelease non-virtual thunk | — | COMPLETED | 100% | src/game/input/AnalogStick.cpp |
| libsanangeles.so | 0x003268e1 | AnalogStick::processTouch | — | BLOCKED | Reviewed faithful1028/native1016: six extra Thumb instructions, equal76B literals and47calls; no semantic/API gap, prior six forms exhausted; parked | src/game/input/AnalogStick.cpp |
| libsanangeles.so | 0x003268cc | _ZThn8_N11AnalogStick12processTouchEl | — | BLOCKED | Current faithful parent emits 1028/1016 bytes and overlaps its next native neighbor; one replay stopped; no linked thunk proof or credit | src/game/input/AnalogStick.cpp |
| libsanangeles.so | 0x0034cfa5 | TouchScreenIPhone deleting destructor (D0) | — | COMPLETED | 100% | src/game/input/TouchScreenIPhone.cpp |
| libsanangeles.so | 0x0034cff5 | TouchScreenIPhone complete destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/input/TouchScreenIPhone.cpp |
| libsanangeles.so | 0x0034cf90 | TouchScreenIPhone deleting destructor thunk | — | COMPLETED | 100% | src/game/input/TouchScreenIPhone.cpp |
| libsanangeles.so | 0x0034cfe0 | TouchScreenIPhone complete destructor thunk | — | COMPLETED | 100% | src/game/input/TouchScreenIPhone.cpp |
| libsanangeles.so | 0x0034cef1 | TouchScreenIPhone OnEvent | — | COMPLETED | 100% | src/game/input/TouchScreenIPhone.cpp |
| libsanangeles.so | 0x0034cedc | TouchScreenIPhone OnEvent non-virtual thunk | — | COMPLETED | 100% | src/game/input/TouchScreenIPhone.cpp |
| libsanangeles.so | 0x0034cde5 | TouchScreenIPhone constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/input/TouchScreenIPhone.cpp |
| libsanangeles.so | 0x0034cd7d | TouchScreenIPhone::getLeftBound | — | COMPLETED | 100% | src/game/input/TouchScreenIPhone.cpp |
| libsanangeles.so | 0x0034cd85 | TouchScreenIPhone::getRightBound | — | COMPLETED | 100% | src/game/input/TouchScreenIPhone.cpp |
| libsanangeles.so | 0x0034cd8d | TouchScreenIPhone::getTopBound | — | COMPLETED | 100% | src/game/input/TouchScreenIPhone.cpp |
| libsanangeles.so | 0x0034cd95 | TouchScreenIPhone::getBottomBound | — | COMPLETED | 100% | src/game/input/TouchScreenIPhone.cpp |
| libsanangeles.so | 0x0034cdcd | TouchScreenIPhone::getTouchIDInRegion | — | COMPLETED | 100% | src/game/input/TouchScreenIPhone.cpp |
| libsanangeles.so | 0x0034cdd9 | TouchScreenIPhone::isRegionPressed | — | COMPLETED | 100% | src/game/input/TouchScreenIPhone.cpp |
| libsanangeles.so | 0x0034cbc1 | TouchScreenBase::getTouchIDList | — | COMPLETED | 100%;88B authentic iterator/list-helper reuse, full190-profile gate and current old checks exact, no flags or layout changes | src/game/input/TouchScreenBase.cpp |
| libsanangeles.so | 0x0034c8c5 | TouchScreenBase::getTouchDisplacement | — | COMPLETED | 100% | src/game/input/TouchScreenBase.cpp |
| libsanangeles.so | 0x0034ccf1 | TouchScreenBase::touchBegan | — | BLOCKED | Coordinator reran65-instruction native audit and reviewed actual140B saved candidate: same7bytes differ at0x32. Current selectors35functions/44sections/1GOT and28B message exact; no new source evidence/compile/credit. Ownership released. | nonmatching/input/TouchScreenBase-touchBegan-initializer-helper.patch; src/game/input/TouchScreenBase.cpp |
| libsanangeles.so | 0x0034d989 | AccelerometerWin32 OnEvent | — | COMPLETED | 100%; actual bool ABI and original missing return preserved; full 186-profile, 10,358-comparison native gate exact | src/game/input/AccelerometerWin32.cpp |
| libsanangeles.so | 0x0034d974 | AccelerometerWin32 OnEvent non-virtual thunk | — | COMPLETED | 100%; actual bool ABI and original missing return preserved; full 186-profile, 10,358-comparison native gate exact | src/game/input/AccelerometerWin32.cpp |
| libsanangeles.so | 0x0034da8d | AccelerometerWin32 deleting destructor (D0) | — | COMPLETED | 100% | src/game/input/AccelerometerWin32.cpp |
| libsanangeles.so | 0x0034dad9 | AccelerometerWin32 complete destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/input/AccelerometerWin32.cpp |
| libsanangeles.so | 0x0034da78 | AccelerometerWin32 deleting destructor thunk | — | COMPLETED | 100% | src/game/input/AccelerometerWin32.cpp |
| libsanangeles.so | 0x0034dac4 | AccelerometerWin32 complete destructor thunk | — | COMPLETED | 100% | src/game/input/AccelerometerWin32.cpp |
| libsanangeles.so | 0x0034d9bd | AccelerometerWin32 constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/input/AccelerometerWin32.cpp |
| libsanangeles.so | 0x0034d941 | AccelerometerWin32::setWide | — | COMPLETED | 100% | src/game/input/AccelerometerWin32.cpp |
| libsanangeles.so | 0x0034d479 | AccelerometerBase::_calcAngles | — | BLOCKED | Coordinator reran five real256/native264B images; v3-v6 identical, mismatch6. Old13/23 closures exact,39 stableinputs; current moved absent. No new causal evidence/compile/credit; ownership released. | src/game/input/AccelerometerBase.cpp |
| libsanangeles.so | 0x0034d689 | AccelerometerBase::moved | — | COMPLETED | 100% | src/game/input/AccelerometerBase.cpp |
| libsanangeles.so | 0x0032d925 | CDrivingControlHandler::handleAttackHeld | — | COMPLETED | 100% | src/game/input/CDrivingControlHandler.cpp |
| libsanangeles.so | 0x0032d935 | CDrivingControlHandler::handleAttackPressed | — | COMPLETED | 100% | src/game/input/CDrivingControlHandler.cpp |
| libsanangeles.so | 0x0032d911 | CDrivingControlHandler::handleWeaponSwitched | — | COMPLETED | 100% | src/game/input/CDrivingControlHandler.cpp |
| libsanangeles.so | 0x0032e589 | COnFootControlHandler::handleWeaponSwitched | — | COMPLETED | 100% | src/game/input/COnFootControlHandler.cpp |
| libsanangeles.so | 0x0032e5d9 | COnFootControlHandler::handleEnterCarPressed | — | COMPLETED | 100% | src/game/input/COnFootControlHandler.cpp |
| libsanangeles.so | 0x0032e5bd | COnFootControlHandler::handleEnterShopPressed | — | COMPLETED | 100% | src/game/input/COnFootControlHandler.cpp |
| libsanangeles.so | 0x0032f0e9 | SniperControlHandler::handleExitSightReleased | — | COMPLETED | 100% | src/game/input/SniperControlHandler.cpp |
| libsanangeles.so | 0x0032e59d | COnFootControlHandler::handleLockPressed | — | COMPLETED | 100% | src/game/input/COnFootControlHandler.cpp |
| libsanangeles.so | 0x0032f18d | SniperControlHandler::handleAttackReleased | — | COMPLETED | 100% | src/game/input/SniperControlHandler.cpp |
| libsanangeles.so | 0x002e2665 | GSInGameMenu::skipFadeIn | — | COMPLETED | 100% | src/game/ui/GSInGameMenu.cpp |
| libsanangeles.so | 0x0032e5ed | COnFootControlHandler::handleStickReleased | — | COMPLETED | 100% | src/game/input/COnFootControlHandler.cpp |
| libsanangeles.so | 0x0032f0f9 | SniperControlHandler::handleAttackHeld | — | COMPLETED | 100% | src/game/input/SniperControlHandler.cpp |
| libsanangeles.so | 0x002e2885 | GSInGameMenu::dtor | — | COMPLETED | 100% | src/game/ui/GSInGameMenu.cpp |
| libsanangeles.so | 0x0032e615 | COnFootControlHandler::handleStickMove | — | COMPLETED | 100% | src/game/input/COnFootControlHandler.cpp |
| libsanangeles.so | 0x0032f159 | SniperControlHandler::handleAttackPressed | — | COMPLETED | 100% | src/game/input/SniperControlHandler.cpp |
| libsanangeles.so | 0x002e28d5 | GSInGameMenu::ctor | — | COMPLETED | 100% | src/game/ui/GSInGameMenu.cpp |
| libsanangeles.so | 0x0032f391 | SniperControlHandler::onEvent | — | COMPLETED | 100% | src/game/input/SniperControlHandler.cpp |
| libsanangeles.so | 0x002e26ad | GSInGameMenu::draw2d | — | COMPLETED | 100% | src/game/ui/GSInGameMenu.cpp |
| libsanangeles.so | 0x0032e69d | COnFootControlHandler::handleAttackReleased | — | COMPLETED | 100% | src/game/input/COnFootControlHandler.cpp |
| libsanangeles.so | 0x0032f201 | SniperControlHandler::onKeyboardEvent | — | BLOCKED | Unmatched: one split-alias follow-up emits 476/400 bytes; prelink guard exit 3, no linked preservation. See nonmatching/input/SniperControlHandler-keyboard.md. | src/game/input/SniperControlHandler.cpp |
| libsanangeles.so | 0x002e2725 | GSInGameMenu::update(StateMachine*) | — | BLOCKED | Reviewed actualv2/v4/v5 identical356/native352B; oldv1assemblyalsomeasures356B, v6hints360. Native sideeffects alreadypreserved,0newC++compiles. Olddtorrelocated0x510001 andsingletonABSimport preventcleanclosureclaim. No credit. | _scratch/worker-ingame-menu-update-current/REVIEW.md; src/game/ui/GSInGameMenu.cpp |
| libsanangeles.so | 0x0032e6f9 | COnFootControlHandler::handleAttackHeld | — | COMPLETED | 100% | src/game/input/COnFootControlHandler.cpp |
| libsanangeles.so | 0x0032e76d | COnFootControlHandler::handleAttackPressed | — | COMPLETED | 100% | src/game/input/COnFootControlHandler.cpp |
| libsanangeles.so | 0x002ed215 | Widgets::Mission::OnEvent(RenderFX::Event&) | — | BLOCKED | Reviewed real popTo member/current-TU replay:132B unchanged,6 register bytes differ. Old192functions/202regions and2native literals exact;308/239 includingdependency,884inputs stable. No credit or repeatedguardgrid. | _scratch/worker-widget-mission-event-current/REVIEW.md; src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x0032ed5d | COnFootControlHandler::onEvent | — | COMPLETED | 100% | src/game/input/COnFootControlHandler.cpp |
| libsanangeles.so | 0x0032e835 | COnFootControlHandler::onKeyboardEvent | — | BLOCKED | Coordinator verified CPP-only V/Y predicate correction changes exactly two branch bytes. Actual1332/native1320B fails strict extent and overlaps compiled neighbor; no candidate ELF/closure. Baseline23realfunctions/8regions exact, no credit; ownership released. | src/game/input/COnFootControlHandler.cpp |
| libsanangeles.so | 0x0032d945 | CDrivingControlHandler::disableAccelerometer | — | COMPLETED | 100% | src/game/input/CDrivingControlHandler.cpp |
| libsanangeles.so | 0x0032da91 | CDrivingControlHandler::onEvent | — | BLOCKED | Coordinator reran native/image audit:2144/native2172B fails0xc, frame164/native180;20realoldfunctions/8selectors exact in saved graph. Fallback is quaternion plus unit-Z vector, not two quaternions; no invented frame padding or new compile. Ownership released. | src/game/input/CDrivingControlHandler.cpp |
| libsanangeles.so | 0x002ed11d | Widgets::About::Enable | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ef041 | Widgets::About::Disable | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ebf35 | Widgets::About::Update | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ecb01 | Widgets::Help::SetIcon | — | BLOCKED | Three forms same6 scheduling bytes; actual original MenuWidget ownership and current flags confirmed, no API or literal correction; no replay | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ecbbd | Widgets::Achievement::SetIcon | — | BLOCKED | Coordinator reproduced actual32B r4b target unchanged from1.6r1 and reviewed own149r.sched2 cause. All308 old functions pass but two vtable selectors missing and GOT regresses; compiler control rejected, no credit. Ownership released. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ecb9d | Widgets::IGMenu::GoToFrame | — | BLOCKED | Bool forwarding is byte-identical to the mismatching void model; disabling sched2 regresses 140 old functions and two sections; all experiments rejected | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ece95 | Widgets::About::Show | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ec565 | Widgets::About constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ed459 | Widgets::About::UpdateLocalization | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee811 | Widgets::About::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ec821 | Widgets::MapLegend constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ecf0d | Widgets::MapLegend::Show | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ed299 | Widgets::MapLegend::OnEvent(RenderFX::Event&) | — | BLOCKED | Reviewed current248/native240B object, same archivedform4; strictlink2. Relocated diagnostic1 rejects targetaddress;192oldfunctions pass,201/202regions, vtable fails real relocatedmethod. No fullclosure or credit;884stableinputs. | _scratch/worker-widget-maplegend-event-current/REVIEW.md; src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002edb61 | Widgets::MapLegend::UpdateLocalization | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ed139 | Widgets::Corruption::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ed1c5 | Widgets::DemoBuy::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002eebc5 | Widgets::BlockingTutorial::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ed809 | Widgets::DemoBuy::UpdateLocalization | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002edd6d | Widgets::IGMenu::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee979 | Widgets::Tutorial::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ef6f5 | Widgets::Tutorial::UpdateLocalization | — | COMPLETED | 100%; native464 exact in owner and consumer. Combined190-profile10656-check root gate passes with previous matches retained; shared value/string interfaces and genuine name chain reused. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ecd99 | Widgets::Volumes::Hide | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee409 | Widgets::Statistics::Show() | — | BLOCKED | Reviewed savedforms4/5/6:identical128B hash00d756...,26differences. Native reset/count/call/reload sideeffects preserved, no newAPI evidence;0freshcompiles. Historical166/124only, no currentclosure or credit. | _scratch/worker-widget-statistics-current/REVIEW.md; src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ef0b1 | Widgets::Corruption::UpdateLocalization | — | BLOCKED | Coordinator source audit finds only static paths and no borrowedname/string/value construction. Real name chain irrelevant; prior three identical forms and typed SetText forwarding supply no new correction. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ef415 | Widgets::Volumes::UpdateLocalization | — | COMPLETED | 100%; ordinary truth-value mute selections and authentic UTF8 interfaces match736 in both images, no hints. Full190-profile10656-comparison coordinator gate passes; no Fully Linked credit. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee67d | Widgets::Achievements::SetCategory(int) | — | BLOCKED | Coordinator verified historical v1/v2/v3 linked112B hash f683ae20f362853a0eb7464386d857a8ca19f4e04e78b94a5f47241db46aa003;14 differing bytes. Stop rule reached; no new evidence or fresh compile, old closure not current proof. | _scratch/worker-achievements-current/historical-review.json; src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002edfbd | Widgets::ConfirmPayment::UpdateLocalization | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002edec1 | Widgets::Confirm::UpdateLocalization | — | COMPLETED | 100%;252 nativecode bytes and compiler-generated vtable36-symbol/40-section match bothimages. Full190-profile10656-comparison coordinator gate passes; no Fully Linked credit. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002eec15 | Widgets::Statistics::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee2c1 | Widgets::Statistics::UpdateLocalization | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee489 | Widgets::Achievements::UpdateLocalization | — | BLOCKED | Saved candidate is500/native500 with only8 spill-slot bytes different, not492-byte size. No borrowedname/string/value dataflow; SDK name chain irrelevant. No replay. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee6ed | Widgets::Controls::UpdateLocalization | — | BLOCKED | Six old292-byte forms; no borrowedname/string/value flow and current HUD fields agree with native widths/choice data. New name chain irrelevant; no replay. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ef901 | Widgets::Objective::OnEvent | — | BLOCKED | Actual Thumb/GOT modes already correct; native duplicates a call that old248 candidate merges, with frame/register differences. Event name is already a pointer; no relevant SDK correction. No replay. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002eeda1 | Widgets::Achievements::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002efda5 | Widgets::Controls::OnEvent(RenderFX::Event&) | — | BLOCKED | Reviewed typedHUD/Preferences372B body identical archivedunhintedform2;258differences. Old192functions/202regions+2literals exact,308/239 includingdependency,884stableinputs. No hintgrid or credit. | _scratch/worker-widget-controls-event-current/REVIEW.md; src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ef9fd | Widgets::MainMenu::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002efafd | Widgets::GameSetting::OnEvent | — | BLOCKED | Two historical six-form waves exhausted; event-name pointer and native singleton/playback call modes already correct. Relocated320-byte diagnostics are not native proof; no new ABI/helper gap. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002efc31 | Widgets::Language::OnEvent(RenderFX::Event&) | — | BLOCKED | Reviewed typedAPI372B target,80differences, sameoldbestbytes. Old192functions/202regions exact,884stableinputs; hintsremainunaccepted. Confirmed Asianfont bool declaration inconsistency separately handed to coordinator; no targetcredit. | _scratch/worker-widget-language-event-current/REVIEW.md; src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002f01c5 | Widgets::Volumes::Show | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002f0249 | Widgets::Arrows::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002e33f1 | GSSideMissionMenu::dtor | — | COMPLETED | 100% | src/game/ui/GSSideMissionMenu.cpp |
| libsanangeles.so | 0x00343761 | Preferences::Exist | — | COMPLETED | 100% | src/game/ui/Preferences.cpp |
| libsanangeles.so | 0x002e3415 | GSSideMissionMenu::ctor | — | COMPLETED | 100% | src/game/ui/GSSideMissionMenu.cpp |
| libsanangeles.so | 0x00343811 | Preferences constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/ui/Preferences.cpp |
| libsanangeles.so | 0x002eff19 | Widgets::Volumes::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x00343785 | Preferences::GetDefaultFilename | — | COMPLETED | 100% | src/game/ui/Preferences.cpp |
| libsanangeles.so | 0x002e365d | GSSideMissionMenu::update | — | COMPLETED | 100% | src/game/ui/GSSideMissionMenu.cpp |
| libsanangeles.so | 0x00343835 | Preferences::GetOrientation | — | COMPLETED | 100%;176B natural automatic objects, unchanged destructor headers; canonical full190-profile gate exact, both real D1 copies explicitly checked | src/game/ui/Preferences.cpp |
| libsanangeles.so | 0x002ee061 | Widgets::Dialog::OnEvent | vehicle_side | BLOCKED | pending | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002e56b1 | MenuManager::updateLocalization | — | COMPLETED | 100% | src/game/hud/MenuManager.cpp |
| libsanangeles.so | 0x003437f1 | Preferences destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/ui/Preferences.cpp |
| libsanangeles.so | 0x002eab95 | Menus::Options::Notify | — | COMPLETED | 100%; canonical typed member getter, exact 208-byte function and section without hints. Combined coordinator closure passes. | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x003437c9 | Preferences deleting destructor (D0) | — | COMPLETED | 100% | src/game/ui/Preferences.cpp |
| libsanangeles.so | 0x003438e5 | Preferences::SampleAndSave | — | COMPLETED | 100%;336B; coordinator native target/full182-profile gate exact; canonical headers unchanged | src/game/ui/Preferences.cpp |
| libsanangeles.so | 0x002eb5d9 | Menus::Services::Notify | — | COMPLETED | 100%; canonical getter and typed IGMenu member, exact 208-byte function/section and both 20-byte literals. Combined coordinator closure passes. | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x00343a39 | Preferences::LoadAndApply | — | COMPLETED | 100%;604B plus native608B region and32B dispatch exact; full190-profile gate passes, completes all13 Preferences.cpp entries | src/game/ui/Preferences.cpp |
| libsanangeles.so | 0x002ea925 | Menus::InfoAchievements::Notify | — | COMPLETED | 100%; complete 224-byte function and section, two documented branch hints. Coordinator full gate passes 190 profiles and 10,658 comparisons; all previous matches retained. | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e8fe9 | Menus::ServiceMissions::GotFocus | — | COMPLETED | 100%; diagnostic and ordinary objects agree. MainMenu private declaration context reverses independent initializations before first RTL; rejected context remains unintegrated. | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002eaa05 | Menus::InfoHelp::Notify | — | COMPLETED | Existing100%; approved adjacent declaration-order compatibility edit restores native284 exactly, SHA566c03298467bb5debc364b1e71953d6a4e0a86cff63bfdcb3fd7ca1c5bf4949. Private190/10917 and integrated root190/10923 passed; no algorithm/flags changes. | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e86fd | MenuState::GotFocus | — | BLOCKED | Typed first-pass getter produces the same 248-byte candidate and 12 register differences. All 234 existing functions and 89 section/region checks pass; no further source trials. | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x0034c085 | DataReloaderManager::_trace | — | COMPLETED | 100% | src/game/world/DataReloaderManager.cpp |
| libsanangeles.so | 0x002e4695 | MenuManager::draw | — | COMPLETED | 100% | src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x002e6149 | MenuManager::tearDown() | — | BLOCKED | Reviewed actual300B target, onlycmp/branchbytes+254/+257differ;6oldforms exhausted. Native globalrental reload/dtor/widgetarray/textureloop semantics correct,0newcompiles. Oldimage74/75currentfunctions(drawabsent),36/36regions; no currentclosure/credit. | _scratch/worker-menu-teardown-current/REPORT.md; src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x0034c089 | DataReloaderManager::monitorFiles | — | COMPLETED | 100% | src/game/world/DataReloaderManager.cpp |
| libsanangeles.so | 0x0034c211 | DataReloaderManager constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/world/DataReloaderManager.cpp |
| libsanangeles.so | 0x002e6731 | MenuManager::_positionMapOnPoint(vector2df&) | — | BLOCKED | Reviewed typed-Map312/native308B object, strict native fit rejects, builder2; no targetcomparison/closure. Header-only75functions/36regions exact;24model-layout measurements unchanged,884inputs stable. One newform, no credit. | _scratch/worker-position-map-current/REPORT.md; src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x0034c0a1 | DataReloaderManager::_MonitoredFiles destructor | — | COMPLETED | 100% | src/game/world/DataReloaderManager.cpp |
| libsanangeles.so | 0x002e6949 | MenuManager::updateMarkers() | — | BLOCKED | Reviewed two faithful current-API356/native360B forms, differing only4 raw bytes; frame36/native44 remains. Both old75functions/36regions exact,884stableinputs,28model-layout measurements preserved. No credit or further source grid. | _scratch/worker-update-markers-current/REPORT.md; src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x0034c0c5 | DataReloaderManager destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/world/DataReloaderManager.cpp |
| libsanangeles.so | 0x002e6865 | MenuManager::_scrollMap(const std::list<Point2D<short>*>&) | — | BLOCKED | Reviewed authentic readonly list-front232/native228B object; strictlink2, no targetimage/bytecomparison/closure. Support-only75functions/36regions exact;31model-layout values unchanged,885stableinputs; no extrahelpers. Oneform, no credit. | _scratch/worker-scroll-map-current/REPORT.md; src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x0034c2e1 | DataReloaderManager deleting destructor (D0) | — | COMPLETED | 100% | src/game/world/DataReloaderManager.cpp |
| libsanangeles.so | 0x002d3349 | SwfFree | — | COMPLETED | 100% | src/game/core/Memory.cpp |
| libsanangeles.so | 0x002d3355 | IrrFree | — | COMPLETED | 100% | src/game/core/Memory.cpp |
| libsanangeles.so | 0x002d3339 | CustomFree | — | COMPLETED | 100% | src/game/core/Memory.cpp |
| libsanangeles.so | 0x002d3361 | CustomAlloc | — | COMPLETED | 100% | src/game/core/Memory.cpp |
| libsanangeles.so | 0x002d3371 | SwfAlloc(size, hint, file, line) | — | COMPLETED | 100% | src/game/core/Memory.cpp |
| libsanangeles.so | 0x002d337d | SwfAlloc(size, hint) | — | COMPLETED | 100% | src/game/core/Memory.cpp |
| libsanangeles.so | 0x002d3389 | IrrAlloc(size, hint) | — | COMPLETED | 100% | src/game/core/Memory.cpp |
| libsanangeles.so | 0x002d3395 | IrrAlloc(unsigned int, irr::MemHint, int, const char*, int) | — | COMPLETED | 100% | src/game/core/Memory.cpp |
| libsanangeles.so | 0x0034c119 | DataReloaderManager::checkFiles() const | — | BLOCKED | Original STLport short-string accessor reconstruction restores native248B extent;21 bytes differ. Three ordinary forms have identical raw bytes/relocations; old11functions/7regions exact. Reviewed unapplied source/configuration and const-vector API prerequisite; no credit or more grids without new evidence. | src/game/world/DataReloaderManager.cpp; nonmatching/world/DataReloaderManager-checkFiles.patch |
| libsanangeles.so | 0x002e2b19 | GSLoading::isGameLoaded | — | COMPLETED | 100% | src/game/app/GSLoading.cpp |
| libsanangeles.so | 0x002e2b2d | GSLoading::setGameLoaded | — | COMPLETED | 100% | src/game/app/GSLoading.cpp |
| libsanangeles.so | 0x0034b2c5 | StringManager::isPackLoaded | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b2d9 | StringManager::isPackSheetLoaded | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b315 | StringManager::switchPack | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b2f1 | StringManager::getNumberOfLoadedPack | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b619 | StringManager::unloadPack | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b351 | strRev | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b375 | strchrs | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b5a5 | StringManager::unloadPackSheet | — | BLOCKED | Canonical108/114B semantic ledger proves all deletes/zeroing present; gap is save/alignment/cursor allocation, six old forms exhausted, no new helper evidence | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b745 | StringManager constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034bb9d | StringManager::loadPack | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034bb5d | StringManager::getString | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b649 | Structs::TextStyle::Read | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b3c5 | StringManager::formatAmount | — | BLOCKED | Unmatched: one bounded separate-case transfer preserves fallthrough but emits 464/480 bytes; prelink guard exit 3, no linked comparison. See nonmatching/persistence/StringManager-formatAmount.md. | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034be9d | StringManager destructor (D1/D2 aliases) | — | COMPLETED | 100%; real240/240/248B family, authentic erase and whole-profile inline80; full190-profile gate and66-build helper closure exact | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034bd51 | StringManager::loadStyles | — | COMPLETED | 100%;332B loader/default40B exact; valid aligned owner/native D1 once, actual Read weak/whole-profile canary metadata; full190 gate and15-build closure pass | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b78d | StringManager::loadPackSheet | — | BLOCKED | Third form1040/976B strict link fails; reviewed +64B block ledger finds compiler allocation/tail duplication, no new semantic gap; parked uncredited | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x002e2bb5 | GSLoading::LoadingPaused | — | COMPLETED | 100% | src/game/app/GSLoading.cpp |
| libsanangeles.so | 0x002e2b71 | GSLoading::LoadingResumed | — | COMPLETED | 100% | src/game/app/GSLoading.cpp |
| libsanangeles.so | 0x002e2ce5 | GSLoading::ctor | — | COMPLETED | 100% | src/game/app/GSLoading.cpp |
| libsanangeles.so | 0x002e2c99 | GSLoading::dtor | — | COMPLETED | 100% | src/game/app/GSLoading.cpp |
| libsanangeles.so | 0x002e2c09 | GSLoading::update | — | COMPLETED | 100% | src/game/app/GSLoading.cpp |
| libsanangeles.so | 0x002e2d45 | GSLoading::draw | — | COMPLETED | 100% | src/game/app/GSLoading.cpp |
| libsanangeles.so | 0x002fd821 | NPC::Stop | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fd49d | NPC::clearGoToVehicle | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fd801 | NPC::UpdateSceneNode | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fda85 | NPC::enable | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fd70d | NPC::GetPosition | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fd6c1 | NPC::_arrest | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fed91 | NPC::applyDamage | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fd869 | NPC::clean | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fd735 | NPC::wait | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fed45 | NPC::notifyAttacked | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fdbc5 | NPC::dropSceneNode | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fe395 | NPC::WarmUp | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002feb49 | NPC::flee | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fd949 | NPC::grabSceneNode | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fda11 | NPC::SetWeapon | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fea79 | NPC::flee(vector) | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fd8bd | NPC::setupSceneNode | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fd995 | NPC::switchAnim | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fd661 | NPC::tagForKill | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fdaad | NPC::init | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fe0e9 | NPC::isHostileTo(LevelObject*) | — | BLOCKED | Reviewed current coherent hierarchy replay:120/native128B, same prior best hash,39 overlapping differences plus8 missing bytes. Existing71 functions/15 regions exact; no credit. Six-form prior budget exhausted. | _scratch/worker-npc-hostility-current/REPORT.md; src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002febc9 | NPC::clearOnAlert | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fef75 | NPC::setHitByCar | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fe999 | NPC::freeze | — | BLOCKED | One true-voice likelihood hint worsens3 to19 byte differences; current unhinted control exactly reproduces saved224B/3-byte miss. Owner71functions14sections1GOT plus dependencies preserved. No credit; private frozen-bit support unapplied. | nonmatching/ai/NPC-freeze-current.patch; src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fdb79 | NPC destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fdb29 | NPC deleting destructor (D0) | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fd565 | NPC::isOutsideSearchRadius | — | BLOCKED | Coordinator reran actual166/native172B image/FP operand audit; mismatch70,26 differences+6 missing. Six forms exhausted, old radius384 mistake already corrected388; no helper contract cause. Historical57/13 vs current71/15 separate,423stableinputs, no compile/credit; ownership released. | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fd611 | NPC.cpp::__tcf_1 | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fec29 | NPC::disable | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fee69 | NPC::OnDespawn | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fe3c9 | NPC constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fdcfd | NPC::Load | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fe169 | NPC::goToVehicle | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x003009d1 | NPC::SetTarget | — | BLOCKED | Coordinator reran real320B hinted target comparison and native receiver/null/type/lifetime audit.57/13 historical checks pass but14 current functions/two regions absent;422 stableinputs. No new causal defect/compile/credit; ownership released. | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fe615 | NPC::triggerCombatSFX(int) | — | BLOCKED | Reviewed actual archived v1/v3/v4: same368B hash072e25f3...,8 byte differences. Stop rule already reached;0 new compiles; old closure is historical only. No credit. | _scratch/worker-npc-combat-sfx-current/REPORT.md; src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fdbed | NPC::debug | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fde51 | NPC::isUnderCar | — | BLOCKED | Coordinator reran actual420/native416B relocated380001 artifact audit; strict native-address check rejects, no transferable byte proof. Native receiver/halfplanes/lifetimes already preserved; old67/13 only,421 stableinputs, no compile/credit; ownership released. | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002f7415 | Character::attack | — | COMPLETED | 100% | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f1839 | Character.cpp::__tcf_1 | — | COMPLETED | 100% | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f710d | Character::punch | camera_tap | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f6fb9 | Character::kick | — | COMPLETED | 100% | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f2af5 | Character destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f2a79 | Character deleting destructor (D0) | — | COMPLETED | 100% | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f6c45 | Character::punched | camera_tap | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f2ed9 | Character::goToVehicle | — | COMPLETED | 100% | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f3231 | Character constructor (C1/C2 aliases) | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f26ad | Character::ready | — | BLOCKED | Single case8 switch-likelihood escalation preserves the exact archived284B function and36B table, both unmatched. Existing114functions32sections1GOT pass; no credit or more hint/case-order variants without new evidence. | nonmatching/characters/Character-ready-switch-likelihood.patch; src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f4cf9 | Character::throwOutDriver | camera_tap | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f61f9 | EvPlayer destructor (D1) | — | COMPLETED | 100% | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f512d | EvPlayer deleting destructor (D0) | — | COMPLETED | 100% | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f39e1 | Character::runToTarget | vehicle_side | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f2d95 | Character::die | camera_tap | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f2185 | Character::debug | — | COMPLETED | 100% | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f64b9 | Character::hijacked | — | COMPLETED | 100% | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f23fd | Character::bindAnimation | — | COMPLETED | 100% | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f1d91 | Character::setAnimation(int, float, bool, bool, bool) | lock_init | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f6001 | Character::exitVehicle | — | COMPLETED | 100% | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f4659 | Character::show | camera_tap | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f48b1 | Character::initInVehicle | lock_init | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f6299 | Character::hitByCar | — | COMPLETED | 100% | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f405d | Character::Update | — | COMPLETED | 100% | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f4465 | Character::initPhysic | — | BLOCKED | Aggregate filter model preserves20 layout values, restores native116B frame and three-halfword copy; target452/native456B, old114functions/33regions exact. Two SDK transfers stay452B; stock constructor regresses InitWorld and is rejected. Reviewed unapplied delta; no credit or further grid without new evidence. | src/game/characters/Character.cpp; nonmatching/characters/Character-initPhysic-filter-aggregate.patch |
| libsanangeles.so | 0x002f4a79 | Character::positionInVehicle | vehicle_side | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f1a31 | Character::getSpecificAnimation | — | COMPLETED | 100%;714-byte function and716-byte section exact in Character/NPC/Player images. Four alias-return pairs separated; full190-profile10949-comparison gate passes with965inputs stable. Ownership released after acceptance. | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f517d | Character::switchCombatAnimation | lock_init | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f3489 | Character::updateAnimation | — | BLOCKED | Coordinator reran three actual animation artifacts: typed896/native892B images identical,642 differences at12 and4B neighbor overlap; original relocated image rejected. Old108/25 vs current114/33 separate;841stableinputs,6+2 budget exhausted, no new semantic defect/compile/credit. Ownership released. | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f661d | Character::switchMoveAnimation | lock_init | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f55d1 | Character::shoot | vehicle_side | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x00303b6d | PlayerTest::shoot | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00303b58 | PlayerTest::shoot non-virtual thunk | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003035d1 | PlayerTest::acquireTarget | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00303315 | PlayerTest::getAttackableTarget | — | BLOCKED | Coordinator reran v7 same-object diagnostic696/native700B:312 differences+4missing, owner84/26 and real Acquire72B exact. Dependency221/272 partial image has51 explicit failures, no full closure. Seven bounded forms stopped; source/header baseline31 gate valid, no match/credit; ownership released. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00303fe9 | PlayerTest::updateAnim | — | BLOCKED | Authentic licensed SDK nonmember plus/Set prerequisite passed 190/10,687 with approved private InfoHelp compatibility edit; one canonical replay116/native132. Stopped pre-link; no credit or further forms. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00303ab9 | PlayerTest::startDriving | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00304701 | PlayerTest::stopDriving | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00302241 | PlayerTest::orientTowards | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00304895 | PlayerTest::teleportTo | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00305a1d | PlayerTest::attack | — | BLOCKED | Coordinator reran all six actual352/356B comparisons; all fail, old lock353 mistake already corrected354. Native receivers/pressed predicates correct, no event lifetime applies. Historical69/18 vs current84/26 separate;443stableinputs, no new compile/credit; ownership released. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003020f1 | PlayerTest::debug | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00340945 | CivAgressiveController destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/ai/CivAgressiveController.cpp |
| libsanangeles.so | 0x00303079 | PlayerTest::photo(Weapon*) | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/PlayerTest.cpp (private compatibility trial) |
| libsanangeles.so | 0x00340901 | CivAgressiveController deleting destructor (D0) | — | COMPLETED | 100% | src/game/ai/CivAgressiveController.cpp |
| libsanangeles.so | 0x0030577d | PlayerTest::snipe | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00340c35 | CivPassiveController destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/ai/CivPassiveController.cpp |
| libsanangeles.so | 0x00304c05 | PlayerTest::onObjectKilled | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00340bf1 | CivPassiveController deleting destructor (D0) | — | COMPLETED | 100% | src/game/ai/CivPassiveController.cpp |
| libsanangeles.so | 0x00341d25 | GuardController destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/ai/GuardController.cpp |
| libsanangeles.so | 0x00341d65 | GuardController deleting destructor (D0) | — | COMPLETED | 100% | src/game/ai/GuardController.cpp |
| libsanangeles.so | 0x00302361 | PlayerTest::moveTo | — | BLOCKED | Coordinator reran all six actual ELF comparisons628/616/616/616/620/620; best620B differs255bytes at20. Native cross-door/callback semantics preserved; historical76/18 only,8 newfunctions/8regions absent,441stableinputs. No new causal defect/compile/credit; ownership released. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003049e5 | PlayerTest::Respawn | — | BLOCKED | Coordinator reran actual544B receiver/lifetime/37-call audit; mismatch70, no semantic correction. Old83/25 remain exact but newer animation helper absent, no full current closure.887 stableinputs, no compile/credit; ownership released. | src/game/ai/PlayerTest.cpp; nonmatching/ai/PlayerTest-Respawn.patch |
| libsanangeles.so | 0x00342221 | GuardController constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/ai/GuardController.cpp |
| libsanangeles.so | 0x00340985 | CivAgressiveController constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/ai/CivAgressiveController.cpp |
| libsanangeles.so | 0x00340c75 | CivPassiveController constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/ai/CivPassiveController.cpp |
| libsanangeles.so | 0x00340f49 | CopController destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/ai/CopController.cpp |
| libsanangeles.so | 0x003408a9 | CivAgressiveController::switchState | — | COMPLETED | 100% | src/game/ai/CivAgressiveController.cpp |
| libsanangeles.so | 0x00340b6d | CivPassiveController::switchState | — | COMPLETED | 100% | src/game/ai/CivPassiveController.cpp |
| libsanangeles.so | 0x00340edd | CopController deleting destructor (D0) | — | COMPLETED | 100% | src/game/ai/CopController.cpp |
| libsanangeles.so | 0x00341305 | CopController constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/ai/CopController.cpp |
| libsanangeles.so | 0x0034084d | CivAgressiveController::onEvent | — | COMPLETED | 100% | src/game/ai/CivAgressiveController.cpp |
| libsanangeles.so | 0x00340cd5 | CivPassiveController::onEvent | — | COMPLETED | 100% | src/game/ai/CivPassiveController.cpp |
| libsanangeles.so | 0x00341139 | CopController::switchState | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/CopController.cpp |
| libsanangeles.so | 0x00341f31 | GuardController::onEvent(IEvent const*, EventManager const*) | — | BLOCKED | Evidence-only188nativeinstructions/25calls/3literals correct, no causal discrepancy/compile. Actualv2=408/native412B hash4538..., currentarchived8/9functions6/7sections lacksnew switchState/table; no currentclosure or credit. | _scratch/worker-guard-event-current/README.md; src/game/ai/GuardController.cpp |
| libsanangeles.so | 0x003420cd | GuardController::switchState | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/GuardController.cpp |
| libsanangeles.so | 0x00342585 | VehicleController::onEvent(IEvent const*, EventManager const*) | — | BLOCKED | Reviewedactualv3/v6 200B,only3equivalentCMP/orientationbytes differ; no semanticwrongcalls/fields/args or newcompile. Oldcurrent11/12functions12/13sections missnew switchState/table; no currentclosure/credit. | _scratch/worker-vehicle-controller-event-current/README.md; src/game/ai/VehicleController.cpp |
| libsanangeles.so | 0x0034171d | CopVehicleController::switchState | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/CopVehicleController.cpp |
| libsanangeles.so | 0x00341381 | CopController::onEvent(IEvent const*, EventManager const*) | — | BLOCKED | Semantic event/call/global/field audit verifies407nativeinstructions, no causal discrepancy/compile. Actualsurvivingform6=876/native894B hash57bec..., old10/15savedgraph only; clean888Bsource2 preserved but no object invented. No credit. | _scratch/worker-cop-event-current/README.md; src/game/ai/CopController.cpp |
| libsanangeles.so | 0x003406a9 | AIManager::clean | — | COMPLETED | 100% | src/game/ai/AIManager.cpp |
| libsanangeles.so | 0x003426b5 | VehicleController::switchState | — | COMPLETED | 100% | src/game/ai/VehicleController.cpp |
| libsanangeles.so | 0x00340741 | AIManager::onEvent | — | COMPLETED | 100% | src/game/ai/AIManager.cpp |
| libsanangeles.so | 0x00340305 | AIManager::addAI(Vehicle*, StateID) | — | BLOCKED | Unmatched: one bounded NPC common-tail reuse emits 244/336 bytes; prelink guard exit 3, no linked comparison. See nonmatching/ai/AIManager-addAI-Vehicle.md. | src/game/ai/AIManager.cpp |
| libsanangeles.so | 0x00340455 | AIManager::addAI(NPC*, StateID) | — | COMPLETED | 100% | src/game/ai/AIManager.cpp |
| libsanangeles.so | 0x003520c1 | RadioStationController::selectRandomJingle | — | COMPLETED | 100% | src/game/ai/RadioStationController.cpp |
| libsanangeles.so | 0x003522b1 | RadioStationController::selectRandomSong | — | COMPLETED | 100% | src/game/ai/RadioStationController.cpp |
| libsanangeles.so | 0x00352335 | RadioStationController constructor (C1/C2 aliases) | — | BLOCKED | Reviewed corrected template placement:604B,12 differences remain;9 oldfunctions/8regions+4nativeconstants exact. Natural DataStream lifetime hits original weak-dtor INTERNAL assembler failure; no object/closure for that variant. No credit. | _scratch/worker-radio-constructor-current/REPORT.md; src/game/ai/RadioStationController.cpp |
| libsanangeles.so | 0x00319cd5 | PhysicInfo::Reset | — | COMPLETED | 100% | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x00319c21 | SafeDeleteArray<array<unsigned short> > | — | COMPLETED | 100% | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x0031a40d | PhysicAttributes::FindLowerCostNode | — | COMPLETED | 100%; one genuine size/indexed-access adaptation restores all192 bytes. Existing24-byte fields preserved; default constructor recovered. Full190/10,935 passes with the real definition verified in all four images, SHA44df9ac5048ac0eb763c8be9f4106770ce089ebea763ef08010f04113702a797. Verified marker removed. | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x003196fd | PhysicAttributes::SegmentsIntersect | — | COMPLETED | 100% | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x0031e0c9 | PhysicAttributes::Clean | — | COMPLETED | 100% | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x0031e99d | PhysicAttributes::UpdateEdgesCollisions | — | COMPLETED | 100% | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x003497e5 | ASprite::GetAnim | — | COMPLETED | 100%; canonical records; coordinator full183-profile gate exact | src/game/rendering/ASprite.cpp |
| libsanangeles.so | 0x0031a6fd | PhysicAttributes::GetJumpHeight | lock_init | BLOCKED | pending | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x003497f5 | ASprite::GetFrame | — | COMPLETED | 100%; canonical records; coordinator full183-profile gate exact | src/game/rendering/ASprite.cpp |
| libsanangeles.so | 0x003200f9 | PhysicAttributes::Init | — | COMPLETED | 100% | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x00353095 | SoundManager::_getReadySound | — | BLOCKED | One -fno-tree-fre falsification still emits 222/native224 bytes: PRE later reuses the slot value and RTL CSE removes its test. Strict extent prevents link; old linked closure NOT RUN. No production flags or further flag sweep. | src/game/audio/SoundManager.cpp (private) |
| libsanangeles.so | 0x00352a55 | SoundManager::endCutscene() | — | BLOCKED | Coordinator verified saved best236B hash42830846...,6 differences; all6 prior forms recovered, no new ABI/source evidence from beginCutscene. Zero fresh compiles/current closure; historical old71/75 only. No credit. | _scratch/worker-sound-end-cutscene-current/REPORT.md; src/game/audio/SoundManager.cpp |
| libsanangeles.so | 0x00353175 | SoundManager::update | vehicle_side | BLOCKED | pending | src/game/audio/SoundManager.cpp |
| libsanangeles.so | 0x00353525 | SoundManager constructor (C1/C2 aliases) | vehicle_side | BLOCKED | pending | src/game/audio/SoundManager.cpp |
| libsanangeles.so | 0x002d5da5 | EvMouseMove destructor (D1) | — | COMPLETED | 100% | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d5df5 | EvKeyboard destructor (D1) | — | COMPLETED | 100% | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d610d | EvMouseMove deleting destructor (D0) | — | COMPLETED | 100% | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d5e45 | EvMouseWheel destructor (D1) | — | COMPLETED | 100% | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d5dc9 | EvKeyboard deleting destructor (D0) | — | COMPLETED | 100% | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d5e19 | EvMouseWheel deleting destructor (D0) | — | COMPLETED | 100% | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d5e95 | EvMouseButton destructor (D1) | — | COMPLETED | 100% | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d5e69 | EvMouseButton deleting destructor (D0) | — | COMPLETED | 100% | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d4015 | Application::UnRegisterForUpdate | — | BLOCKED | Exact _Update helper is identical to failed authentic unregister helpers; conversion-call lifetime boundary is absent here, no new API/inlining evidence; parked uncredited | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d3cb9 | Application::IsLogoOver | — | COMPLETED | 100% | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d3c9d | Application::IsGlobalResumingOver | — | COMPLETED | 100% | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d3c7d | Application::InitIPhone | — | COMPLETED | 100%; exact 18-byte function and 20-byte physical section in two images. Actual helper retained; current Cash unchanged, NPC compatibility restored. Final 190-profile, 10,668-comparison gate passes with no failures or skips. | src/game/app/Application.cpp |
| libsanangeles.so | 0x00325b0d | CSniperHud destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/hud/SniperHud.cpp |
| libsanangeles.so | 0x0034a3b5 | ASpriteData constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/rendering/ASpriteData.cpp |
| libsanangeles.so | 0x003499b9 | ASprite::GetAFrameTime | — | COMPLETED | 100% | src/game/rendering/ASprite.cpp |
| libsanangeles.so | 0x00349815 | ASprite::GetModule | — | COMPLETED | 100%; canonical records; coordinator full183-profile gate exact | src/game/rendering/ASprite.cpp |
| libsanangeles.so | 0x00349c85 | ASprite::GetFModule | — | COMPLETED | 100%; canonical records; coordinator full183-profile gate exact | src/game/rendering/ASprite.cpp |
| libsanangeles.so | 0x00325add | CSniperHud constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/hud/SniperHud.cpp |
| libsanangeles.so | 0x00349825 | ASprite::GetFrameRect | — | COMPLETED | 100%; canonical34B and36Bsection; coordinator full183-profile10276-comparison gate exact | src/game/rendering/ASprite.cpp |
| libsanangeles.so | 0x00325c79 | CSniperHud::hide | — | COMPLETED | 100% | src/game/hud/SniperHud.cpp |
| libsanangeles.so | 0x002d3c05 | MediaPlayerIPhone constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/app/MediaPlayerIPhone.cpp |
| libsanangeles.so | 0x00322dd5 | CCameraHud::hide | — | COMPLETED | 100% | src/game/hud/CCameraHud.cpp |
| libsanangeles.so | 0x00325b25 | CSniperHud::show | — | COMPLETED | 100% | src/game/hud/SniperHud.cpp |
| libsanangeles.so | 0x002d3be9 | MediaPlayerIPhone::_trace | — | COMPLETED | 100% | src/game/app/MediaPlayerIPhone.cpp |
| libsanangeles.so | 0x00322c5d | CCameraHud::show | — | COMPLETED | 100% | src/game/hud/CCameraHud.cpp |
| libsanangeles.so | 0x00325809 | CWalkingHud::hide | — | COMPLETED | 100% | src/game/hud/CWalkingHud.cpp |
| libsanangeles.so | 0x003238f5 | CHudManager::unregUpdatableComponents | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |
| libsanangeles.so | 0x003256dd | CWalkingHud::show | — | COMPLETED | 100% | src/game/hud/CWalkingHud.cpp |
| libsanangeles.so | 0x0032399d | CHudManager::regUpdatableComponents | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |
| libsanangeles.so | 0x00323be9 | CHudManager::regDrawableComponents | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |
| libsanangeles.so | 0x00323da9 | CHudManager::unregDrawableComponents | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |
| libsanangeles.so | 0x00323705 | CHudManager::blink | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |
| libsanangeles.so | 0x00323301 | CDrivingHud::hide | — | COMPLETED | 100% | src/game/hud/CDrivingHud.cpp |
| libsanangeles.so | 0x002ebc9d | CHudManager::setThrottleMode | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |
| libsanangeles.so | 0x002ebd29 | CHudManager::setSteeringMode | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |
| libsanangeles.so | 0x003230ad | CDrivingHud::show | — | COMPLETED | 100% | src/game/hud/CDrivingHud.cpp |
| libsanangeles.so | 0x00324979 | CHudManager destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |
| libsanangeles.so | 0x00324399 | CHudManager::update(double) | — | BLOCKED | Authentic accepted TouchIDList and STLport distance reuse reduces26 to14 differing bytes in native720B; 49 old functions/42 old regions exact. One hint712B rejected by strict720 bound. Reviewed unapplied candidate; no credit or further grids without new evidence. | src/game/hud/CHudManager.cpp; nonmatching/hud/CHudManager-update-authentic-list.patch |
| libsanangeles.so | 0x00324c85 | CHudManager constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |
| libsanangeles.so | 0x00324669 | CHudManager deleting destructor (D0) | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |
| libsanangeles.so | 0x003295a5 | MiniMap constructor (C1/C2 aliases) | hud_registration | BLOCKED | pending | src/game/hud/MiniMap.cpp |
| libsanangeles.so | 0x0032be75 | TargetMarker::draw | — | COMPLETED | 100% | src/game/hud/TargetMarker.cpp |
| libsanangeles.so | 0x0032a0f9 | MiniMap::draw2d() const | — | BLOCKED | Native-backed singleton grouping corrected4-to3calls in existing unmatched body. Full190profiles/10953existing comparisons exact,1042stableinputs; parent1356/native1380B still fails0xe. No parent credit or marker removal; ownership released after coordinator acceptance. | nonmatching/hud/_ZNK7MiniMap6draw2dEv.cpp; _scratch/worker-minimap-draw-current/REPORT.md |
| libsanangeles.so | 0x00329901 | MiniMap::_calculateXYOffset | hud_drawables | BLOCKED | pending | src/game/hud/MiniMap.cpp |
| libsanangeles.so | 0x002eb45d | Menus::ServiceWeaponShop::Update() | — | BLOCKED | Reviewedactualv2/v3 identical380B hash9404...,80differences; hintv4 known72differences. Native calls/fields/storeorder/currentAPIs alreadycorrect;0freshcompiles. Historical217/68only, no currentclosure/credit. | _scratch/worker-weapon-shop-update-current/REVIEW.md; src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e6fe1 | MenuManager::updateMap() | — | BLOCKED | Reviewed authenticunhinted388B/120differences and soleoldhint388B/125differences; hintrejected. Bothold75functions/36regions exact,27modelvalues equal,886stableinputs; canonicalTouchIDList unchanged, noextrahelpers. No credit/furthergrid. | _scratch/worker-menu-update-map-current/REPORT.md; src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x002e6ab1 | MenuManager::_drawMap() const | — | BLOCKED | Reviewed currentcanonical432/native424B object, strictlink2, noELF/nativecomparison/targetclosure. Header-only75/36exact,56modelmeasurementsunchanged,884stableinputs; initial448B snapshot/invalidhelperhashes explicitlyrejected. No credit. | _scratch/worker-draw-map-current/REPORT.md; src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x002e7165 | MenuManager::initMap() | — | BLOCKED | Reviewed8exhaustedforms; best432/native428B targetrelocated0x380001, nativeaddressrejected. Allhistorical7/9only;38inspectedinputs stable. Current texture/hierarchy/clamp/call semantics supplyno causal sourcechange,0newcompiles/credit. | _scratch/worker-init-map-current/REPORT.md; src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x002e7ac5 | Menus::ServiceWeaponShop::Refresh | hud_registration | BLOCKED | pending | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e5e4d | MenuManager::preloadGlyphs(bool) | — | BLOCKED | Reviewed original const-array subscript reuse:460B caller identical oldv5,8 differences;452 was agreeing-byte count, not extent. Old75functions/36regions+3texts exact,884inputs stable; no credit or further grid. | _scratch/worker-preload-glyphs-current/REPORT.md; src/game/ui/MenuManager.cpp |

Coordinator approved one additional initMap comparison on 2026-11-18: separate the address-taken cosine temporary from the final angle, based on the four identified excess halfword stores/reload. Stop after this single proof and retain the original six-pass evidence.

Coordinator approved one final initMap v8 proof on new instruction-diff evidence: v7 leaves exactly one redundant store because its address-taken cosine is assigned twice. Use a separate unaddressed numerator and initialize the clamp input once after division. No other source hypotheses; stop after this proof.
| libsanangeles.so | 0x002e6db1 | MenuManager::_zoomMap | hud_glyphs | BLOCKED | 481/560 bytes (unmatched) | src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x002eb761 | Menus::ServiceCarRental::Notify | — | BLOCKED | Canonical 16-byte record remains untried, but all used fields match the 12-byte prefix at offsets 0/4/8, with pointer-table indexing and no stride/copy/field12 operation. No missing API, load width or signedness correction found to justify another form. | src/game/ui/MenuState.cpp (private) |

Coordinator reviewed the six-pass preloadGlyphs and ServiceWeaponShop::Refresh reports: neither is an exact match; both remain parked without credit. The undelivered _zoomMap assignment is released.

| libsanangeles.so | 0x00349a81 | ASprite::GetFrameIdx(char const*) | — | COMPLETED | 100% | src/game/rendering/ASprite.cpp |
| libsanangeles.so | 0x00349dd5 | ASprite::GetAnimIdx(char const*) | — | COMPLETED | 100%; direct matched frame-lookup reuse, exact64 and full190/10939 preservation; no existing bodies changed | src/game/rendering/ASprite.cpp |


| libsanangeles.so | 0x002e3791 | GSSplash::dtor(StateMachine const*) | — | COMPLETED | 100% | src/game/app/GSSplash.cpp |

| libsanangeles.so | 0x00321445 | SceneNodeManager::getPoolID(int) const | — | COMPLETED | 100%; authentic STLport-derived lookup; full 190-profile, 10,503-comparison gate exact; all old matches retained | src/game/world/SceneNodeManager.cpp |

Coordinator reviewed _zoomMap: three materially different forms emitted identical complete bytes; parked under the early-stop rule without credit.

| libsanangeles.so | 0x0034eed9 | ResStream::~ResStream() (deleting D0) | — | BLOCKED | Unmatched. Current replay and local-allocation audit reproduce the six register bytes; no justified API/source correction found | src/game/world/ResStream.cpp |

| libsanangeles.so | 0x0034ef15 | ResStream::~ResStream() (complete/base D1/D2 aliases) | — | BLOCKED | Unmatched. Current replay and local-allocation audit reproduce the six register bytes; no justified API/source correction found | src/game/world/ResStream.cpp |

Coordinator approves the associated ResStream complete/base destructor aliases required by the deleting-destructor definition. They remain exclusive to hud_glyphs.

| libsanangeles.so | 0x002d6bcd | CCustomMaterialRenderer_VERTEX_COLOR_ALPHA::onUnsetMaterial() | — | COMPLETED | 100% | src/game/core/CCustomMaterialRenderer_VERTEX_COLOR_ALPHA.cpp |

| libsanangeles.so | 0x002d6af1 | CCustomMaterialRenderer_VERTEX_COLOR_ALPHA::onSetMaterial | — | COMPLETED | 100% | src/game/core/CCustomMaterialRenderer_VERTEX_COLOR_ALPHA.cpp |
| libsanangeles.so | 0x002d1f31 | nativePauseSound | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d6c11 | _ZTv0_n12_N42CCustomMaterialRenderer_VERTEX_COLOR_ALPHAD0Ev | — | COMPLETED | 100% | src/game/core/CCustomMaterialRenderer_VERTEX_COLOR_ALPHA.cpp |
| libsanangeles.so | 0x002d6c25 | _ZN42CCustomMaterialRenderer_VERTEX_COLOR_ALPHAD0Ev | — | COMPLETED | 100% | src/game/core/CCustomMaterialRenderer_VERTEX_COLOR_ALPHA.cpp |
| libsanangeles.so | 0x002d6c71 | _ZTv0_n12_N42CCustomMaterialRenderer_VERTEX_COLOR_ALPHAD1Ev | — | COMPLETED | 100% | src/game/core/CCustomMaterialRenderer_VERTEX_COLOR_ALPHA.cpp |
| libsanangeles.so | 0x002d6c85 | _ZN42CCustomMaterialRenderer_VERTEX_COLOR_ALPHAD1Ev | — | COMPLETED | 100% | src/game/core/CCustomMaterialRenderer_VERTEX_COLOR_ALPHA.cpp |

| libsanangeles.so | 0x002d1fd5 | nativeResumeSound | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d2045 | nativeStopSound | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d20b5 | nativeUnloadSound | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d2125 | nativeIsSoundLoaded | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d1ded | nativeLoadSound | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |
| libsanangeles.so | 0x002d1f6d | nativePauseSoundBig | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d19c9 | Java_com_gameloft_android_GAND_GloftGANG_GLMediaPlayer_nativeInit | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |
| libsanangeles.so | 0x002d1fa1 | nativePauseAllSounds | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d2011 | nativeResumeSoundBig | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d2081 | nativeStopSoundBig | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d20f1 | nativeUnloadSoundBig | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |
| libsanangeles.so | 0x002d2161 | nativeIsSoundLoadedBig | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d1e29 | nativeLoadSoundBig | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |
| libsanangeles.so | 0x002d225d | nativeResetSound | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d21fd | nativeSetVolumeBig | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |
| libsanangeles.so | 0x002d2195 | nativeSetVolume | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d22f9 | nativeStopAllSounds | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d2291 | nativeSetPitch | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d232d | nativeUnloadAllSounds | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |
| libsanangeles.so | 0x002d2361 | nativeStopAllSoundPool | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |
| libsanangeles.so | 0x002d2395 | nativeStopAllBigSound | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |
| libsanangeles.so | 0x002d23c9 | nativeDestroySoundPool | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |
| libsanangeles.so | 0x002d23fd | nativeInitSoundPoolArray | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d2431 | nativeLoadMovie | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d248d | nativeIsMediaPlaying | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |
| libsanangeles.so | 0x002d24c1 | nativeIsVideoPlayDone | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d1ec5 | nativePlaySoundBig | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |
| libsanangeles.so | 0x002d1e5d | nativePlaySound | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |

Coordinator approves one contextual replay per parked volume/pitch function after integration of the original 1036-byte initializer and JNI declarations; first test unchanged best bodies in current full source. If still unmatched, one coordinated original-address source-order candidate may be tested for both functions, preserving every accepted wrapper. No further iteration without new evidence.

| libsanangeles.so | 0x002e37d9 | GSSplash::ctor(StateMachine const*) | — | COMPLETED | 100% | src/game/app/GSSplash.cpp |
| libsanangeles.so | 0x002e3831 | GSSplash::update(StateMachine*) | — | COMPLETED | 100% | src/game/app/GSSplash.cpp |

| libsanangeles.so | 0x002e1f65 | GSFailure::dtor(StateMachine const*) | — | COMPLETED | 100% | src/game/app/GSFailure.cpp |
| libsanangeles.so | 0x002e1fd5 | GSFailure::ctor(StateMachine const*) | — | COMPLETED | 100% | src/game/app/GSFailure.cpp |

| libsanangeles.so | 0x002e1e15 | GSFailure::draw2d(StateMachine const*) | — | BLOCKED | Reviewed sibling-derived fast path:284/native308B, identical prior alpha-control output. Diagnostic old28functions/27regions exact; private static-getter closure143functions/134regions exact. No standalone header integration or match credit. | _scratch/worker-failure-draw-current/REVIEW.md; src/game/app/GSFailure.cpp |

| libsanangeles.so | 0x002e20dd | GSFailure::update(StateMachine*) | — | COMPLETED | 100% | src/game/app/GSFailure.cpp |
| libsanangeles.so | 0x002d3be1 | MediaPlayerIPhone::playMovie(char const*) | — | COMPLETED | 100% | src/game/app/MediaPlayerIPhone.cpp |
| libsanangeles.so | 0x002d3be5 | MediaPlayerIPhone::stopMovie() | — | COMPLETED | 100% | src/game/app/MediaPlayerIPhone.cpp |

| libsanangeles.so | 0x00321699 | SceneNodeManager::manage(int, LevelObject*, int) | — | COMPLETED | 100% | src/game/world/SceneNodeManager.cpp |
| libsanangeles.so | 0x00306d2d | SpawnPoint::hasCloseNeighbors() const | — | COMPLETED | 100% | src/game/world/SpawnPoint.cpp |
| libsanangeles.so | 0x00328b41 | Map::setMap(Map::eMapType) | — | COMPLETED | 100% | src/game/world/Map.cpp |

| libsanangeles.so | 0x003219cd | SceneNodeManager::drop(int, irr::scene::ISceneNode const*) | — | BLOCKED | One unchanged current-context replay reproduces the historical bytes; strict target fails, all old checks retained; no further forms | src/game/world/SceneNodeManager.cpp |
| libsanangeles.so | 0x003065e5 | SpawnPoint::CreateAllSpawnInstances() | hud_glyphs | BLOCKED | 327/336 bytes (unmatched) | src/game/world/SpawnPoint.cpp |

| libsanangeles.so | 0x003160d9 | GameObjectManager::getAttackableTarget(Character*) | unassigned | BLOCKED | canonical context unchanged; no credit | src/game/world/GameObjectManager.cpp |
| libsanangeles.so | 0x00328c49 | Map::draw() const | lock_init | BLOCKED | 294/304 bytes; original-order trial unchanged | src/game/world/Map.cpp |
| libsanangeles.so | 0x003218d9 | SceneNodeManager::reclaimGarbage() | — | BLOCKED | One unchanged current-context replay reproduces the historical bytes; strict target fails, all old checks retained; no further forms | src/game/world/SceneNodeManager.cpp |

Coordinator authorizes one unchanged-best integrated-context replay for each parked SceneNodeManager getPoolID, drop and reclaimGarbage after the exact bool manage implementation/header refinement. If needed, one combined original-address method-order trial is allowed with every existing function byte check. No further source search. Map::draw receives only one original-address method-order comparison using its proven typed layout and exact setMap. These are bounded context escalations, not reopened unbounded searches.

| libsanangeles.so | 0x00315f39 | GameObjectManager::getDistanceFromAttackableTarget(Character*, int, LevelObject*, bool) | unassigned | BLOCKED | canonical context unchanged; no credit | src/game/world/GameObjectManager.cpp |

| libsanangeles.so | 0x00321721 | SceneNodeManager::report() const | — | BLOCKED | One unchanged current-context replay reproduces the historical bytes; strict target fails, all old checks retained; no further forms | src/game/world/SceneNodeManager.cpp |

| libsanangeles.so | 0x003015d0 | _ZThn4_N10PlayerTestD1Ev | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00303618 | _ZThn4_N10PlayerTestD0Ev | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x0030362d | _ZN10PlayerTestD0Ev | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00311ef1 | _ZTv0_n12_N26CustomSkinnedMeshSceneNodeD0Ev | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00311f05 | _ZTv0_n24_N26CustomSkinnedMeshSceneNodeD0Ev | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00311f19 | _ZN26CustomSkinnedMeshSceneNodeD0Ev | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00311f8d | _ZTv0_n12_N26CustomSkinnedMeshSceneNodeD1Ev | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00311fa1 | _ZTv0_n24_N26CustomSkinnedMeshSceneNodeD1Ev | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x00315a41 | GameObjectManager::GetMetatypeFromName(char const*) (existing match, private API-context regression review only) | — | COMPLETED | 100% (no body change) | src/game/world/GameObjectManager.cpp |

Coordinator approves a bounded canonical NPC::isHostileTo declaration/member-call replay for the two parked attackable functions. The worker identified that the proper declaration perturbs an old match; at most one independent local declaration-order repair to that old function may be proposed privately, with complete byte verification. No unrelated source changes. Destructor-family scope includes the legacy parked complete destructor only as necessary support for the previously unworked deleting variant and adjustment thunks; preserve and review previous evidence before new candidates.

Coordinator approves one coherent private PlayerTest header-migration prototype as a prerequisite to the assigned destructor family. Scope: PlayerTest shared header and legacy call-view aliases, Character facing fields/constructor initializer only, a shared vector-view declaration if necessary, and unchanged existing PlayerTest bodies except mechanical names/casts required by the authentic base interfaces. Preserve actual primary IMapTrackable plus Character at +4 and payload at +300; no duplicate prefix storage. No other active agent owns these prerequisites. Prove native field offsets, all existing PlayerTest/Character checks, and destructor/table bytes before any integration or credit. Any mismatch must be reported; no broad iterative retuning of existing bodies.

Coordinator authorizes one final mechanically corrected coherent PlayerTest prototype based on the demonstrated context-record overlap and the two wrapper code-generation gaps: represent the actual two 16-byte records once, map distance counters into record 1 (no duplicate storage), and replace legacy position() call names with the corresponding genuine GetPosition/SetPosition calls where needed. No semantic body retuning, extra source-form search, or credit without all old Player/Character and family/table comparisons. This is a bounded layout/API correction to the preserved prototype.

| libsanangeles.so | 0x00311251 | _ZN7VehicleD0Ev | hud_registration | BLOCKED | post-constructor replay unchanged; event scheduling | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00311499 | _ZN7VehicleD1Ev, _ZN7VehicleD2Ev | hud_registration | BLOCKED | post-constructor replay unchanged; event scheduling | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x002fe785 | NPC::UpdateCarPosIfUnderWheel() | — | COMPLETED | 100% | src/game/ai/NPC.cpp |

Coordinator permits a focused diagnostic of the sole old photo regression in the coherent PlayerTest prototype, with at most two mechanically justified ABI/cast/declaration-order proposals only after locating the extra four bytes. No algorithm changes, assembly, register constraints, barriers, or broad source search. All old 76 Player/107 Character functions and destructor/table comparisons must pass for readiness.


| libsanangeles.so | 0x00303701 | PlayerTest::PlayerTest(b2World*) (C1/C2 aliases) | — | BLOCKED | Four old forms already used genuine hierarchy; best 864/native872. Native/candidate 100-byte literal pools equal; eight-byte gap precedes pool. No missing operation among 14 calls proven. Private field/container/shape prerequisites remain unintegrated; no global Array constructor change. | src/game/ai/PlayerTest.cpp (private) |
| libsanangeles.so | 0x0030a955 | Vehicle::Vehicle(int) (C1/C2 aliases) | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00306b11 | SpawnPoint::Load(Structs::SpawnPoint const&) | — | BLOCKED | Vector value boundary already used; first0x1da bytes and all6conversions exact. Single STRB halfword reverses address operands at1da; two saved540images identical. No new source replay justified. | src/game/world/SpawnPoint.cpp |

Coordinator approves private Vehicle-constructor layout refinement of the four native vector members at 512/524/536/548, replacing only constant-index references mechanically in preserved Vehicle/NPC bodies. Storage extent and offsets must remain unchanged. All old Vehicle and NPC/dependency checks plus accepted custom/support/table checks must pass before readiness; no other algorithm changes or additional overlapping storage.
| libsanangeles.so | 0x00307451 | SpawnPoint::canSpawn() const | hud_glyphs | BLOCKED | post-constructor replay unchanged; candidate 820/816 bytes | src/game/world/SpawnPoint.cpp |
| libsanangeles.so | 0x0031da29 | PhysicAttributes::IntersectSegmentWithHeightMap | — | BLOCKED | Recovered crossProduct and real PhysicInfo local restore native arithmetic/196B frame; plain592/native596 differs in return layout. Early/nested forms identical; hint596 fails. Owner38functions10sections1GOT preserved. Reviewed unapplied patch, no credit; ownership released. | src/game/characters/PhysicAttributes.cpp; nonmatching/characters/PhysicAttributes-segment-heightmap.patch |
| libsanangeles.so | 0x0031aa5d | PhysicAttributes::GetRandomDestination | hud_registration | BLOCKED | 713/724 bytes; stack-slot operands | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x00307101 | SpawnPoint::UpdateSpawnCenters() | hud_glyphs | BLOCKED | 872/848-byte candidate; repeated compiler CSE output | src/game/world/SpawnPoint.cpp |
| libsanangeles.so | 0x0031d7a1 | ContactListener::Persist(b2ContactPoint const*) | hud_registration | BLOCKED | 341/604 bytes after six candidates; branch layout | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x0031b9a9 | PhysicAttributes::IntersectSegmentWithHeightMap(PhysicInfo&, plane3df const&, vector3df const&, vector3df const&, vector3df&, vector3df&) | lock_init | BLOCKED | 4848/4800-byte candidate; six forms exhausted | src/game/characters/PhysicAttributes.cpp |

Coordinator authorizes one unchanged-source replay each for SpawnPoint Load/canSpawn against the newly integrated authentic Vehicle constructor header (real IMapTrackable, scalar wheel members, accurate initialization fields). Preserve all existing unit checks; stop unchanged targets without source search, then proceed to the newly assigned centers function.

| libsanangeles.so | 0x00323b69 | SafeDelete<CDrivingHud>(CDrivingHud*&) | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |

| libsanangeles.so | 0x00323b89 | SafeDelete<CWalkingHud>(CWalkingHud*&) | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |
| libsanangeles.so | 0x00323ba9 | SafeDelete<CSniperHud>(CSniperHud*&) | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |

| libsanangeles.so | 0x00323bc9 | SafeDelete<CCameraHud>(CCameraHud*&) | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |

| libsanangeles.so | 0x00341a3d | CopVehicleController::onEvent(IEvent const*, EventManager const*) | — | BLOCKED | 728/744 bytes; authentic event initialization regresses old caller | src/game/ai/CopVehicleController.cpp |

| libsanangeles.so | 0x003238a1 | std::__stl_throw_overflow_error(char const*) | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |

| libsanangeles.so | 0x002f4441 | b2CircleDef::~b2CircleDef() (D1) | — | COMPLETED | 100% | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f462d | b2CircleDef::~b2CircleDef() (D0) | — | COMPLETED | 100% | src/game/characters/Character.cpp |

| libsanangeles.so | 0x00318be5 | LevelObject::canGoToPoint(vector3df const&) | — | COMPLETED | 100% | src/game/world/LevelObject.cpp |

| libsanangeles.so | 0x0031b3e9 | PhysicAttributes::SetHeightAttributes(ISceneNode*, vector3df const&, PhysicInfo&) | — | BLOCKED | Current crossProduct reuse produces byte-identical historical 1,036-byte output. All 37 old functions and nine section/region checks pass; no new helper or ABI correction remains. | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x002ff181 | NPC::_detect() | — | BLOCKED | Coordinator reran actual four-image audit; v2/v3/v4 identical1100/native1104B, three-identical stop confirmed. Native callbacks/events already correct; no array/list destructor model applies. Old69/13 separate from current71/15;895 stableinputs, no compile/credit; ownership released. | src/game/ai/NPC.cpp |

| libsanangeles.so | 0x0031dc7d | ContactFilter::ShouldCollide(b2Shape*, b2Shape*) | — | BLOCKED | Six old forms reviewed; faithful unhinted candidate is 1,084 versus 1,100 bytes. Corrected forms already model actual APIs and native custom filtering; no new source gap found. | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x003179d5 | LevelObject::CastRay(vector3df const&, vector3df const&, vector3df&, vector3df&, LevelObject*&, bool) | unassigned | BLOCKED | 1484/1504 bytes; unchanged-context replay stopped | src/game/world/LevelObject.cpp |

| libsanangeles.so | 0x0034b6f5 | std::__stl_throw_out_of_range(char const*) | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0031ad31 | PhysicAttributes::SetHeightAttributes(vector3df const&, PhysicInfo*) | lock_init | BLOCKED | 1400/1388-byte candidate; six forms exhausted | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x0030d149 | Vehicle::CreateWheels(Box2DUserInfo*) | — | BLOCKED | Coordinator reran six actual1440..1480/native1408B relocated380001 images; placement errors, no native percentage proof. Native599-instruction/75-call/147-store receiver/joint/lifetime audit found no defect; old187/112 omits collision/stepPhysic, no current closure. No compile/credit; ownership released. | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x00319ed5 | PhysicAttributes::LoadArrays(char*) | — | COMPLETED | 100% | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x00313385 | Vehicle::collision(vector3df, int) | — | COMPLETED | 100%; coordinator independently rebuilt1360B function/fullsection and actual onDoorClosed neighbor, then191 profiles/10957 comparisons exact with1068 stableinputs. Truthful math-helper const contracts preserve all old matches; only verified marker removed, no denominator change. Ownership released after acceptance. | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x0030ff41 | Vehicle::Load(Structs::Car const&) | — | BLOCKED | All7 conversions scalar; SceneCamera boundary inapplicable. Sixforms/threeequivalent outputs1380/native1368 confirmed; currentprivateprereqs absent but no new authentic API cause. No replay. | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x00320ca1 | PhysicAttributes::ComputeShortestPath(int, int, vector3df, vector3df, float) | — | BLOCKED | Coordinator reran supported1688/native1668 and rejected1692 object/weak96B constructor/GOT audit. Eleven old images retain overlap/relocation limits;77 inputs stable, full semantic audit found no new causal discrepancy. No compile/credit; ownership released. | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x003116dd | Vehicle::stepPhysic() | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x0031cf75 | PhysicAttributes::GetNextRandomPos(int, int, vector3df) | lock_init | BLOCKED | 1732/1748-byte candidate; six forms exhausted | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x00301a75 | PlayerTest::switchContext(eContext, bool) | — | BLOCKED | One current-layout/NDK-enum replay emits884/native900 bytes; only target newly emitted, prelink3, no owner linked proof. See nonmatching/ai/PlayerTest-switchContext.md. | src/game/ai/PlayerTest.cpp |

| libsanangeles.so | 0x0031e285 | PhysicAttributes::AddCollisionShapes(int, unsigned short) | — | BLOCKED | Native-order/reference corrections materialize, but the candidate remains 1,820 versus 1,816 native bytes. Strict linking fails; all artifacts retained, no further variant authorized. | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x00303bb9 | PlayerTest::switchAnim() | — | BLOCKED | Six forms exhausted; best 1088/1072. Historical gate terminal with 66 successful profiles and one unresolved GameObjectManager fresh-link failure. Current canonical fields add no new ABI/helper evidence; no replay. | src/game/ai/PlayerTest.cpp |

| libsanangeles.so | 0x0030406d | PlayerTest::updateCarInteraction() | — | BLOCKED | 1684-byte candidate not matched; six forms; full 74-profile old gate passed | src/game/ai/PlayerTest.cpp |

| libsanangeles.so | 0x002ff5d1 | NPC::attackTarget() | — | BLOCKED | Coordinator reran223 old functions/59 regions and independently checked native first164 receiver is target, second owner. Corrected2084/native2108B remains mismatched18; original2088B reproduced, sole new definition,1063 stableinputs. Accurate correction preserved unapplied, no credit; ownership released. | src/game/ai/NPC.cpp |

| libsanangeles.so | 0x0034bf8d | StringManager::~StringManager() | — | COMPLETED | 100%; real240/240/248B family, authentic erase and whole-profile inline80; full190-profile gate and66-build helper closure exact | src/game/persistence/StringManager.cpp |

| libsanangeles.so | 0x002ed8ad | Widgets::Mission::UpdateLocalization() | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |

| libsanangeles.so | 0x002eb12d | Menus::ServiceCarRental::Update() | lock_init | BLOCKED | 816-byte candidate unmatched; six forms; one private baseline link incomplete | src/game/ui/MenuState.cpp |

| libsanangeles.so | 0x002eac65 | Menus::OptionGameSettings::Notify | — | BLOCKED | Map follow-up finds only one eligible pair of localization tails, with native type-body order already preserved. The unproven upstream receiver allocation R1/R1 versus native R2/R1 remains; no measured alternative peer ordering or new source proposal. | src/game/ui/MenuState.cpp (private) |

| libsanangeles.so | 0x002e4e7d | MenuManager::update(StateMachine*) | — | BLOCKED | 872-byte candidate unmatched; six forms; rejected two old MenuState regressions | src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x002e51fd | MenuManager::setText(eText, char const*, int*) | — | BLOCKED | Read-only typed switch recovery confirms SP80 is destroyed before SP40 construction; no missing lifetime or ABI operation. Candidate remains 1100/native 1104. Project metadata rolled back; no sixth source form justified. | src/game/ui/MenuManager.cpp |

| libsanangeles.so | 0x00344821 | SaveGame::SampleAndSave(char const*) | — | BLOCKED | Coordinator reran current v6:1388B reproduces historical best, four scheduling bytes88..8b differ. Genuine GetPosition uses nativeABI/no wrapper; owner66/223 and previous LoadAndApply1476 exact,886inputs stable. Six forms exhausted, no credit; ownership released. | src/game/persistence/SaveGame.cpp |

| libsanangeles.so | 0x002e574d | MenuManager::setup(bool) | — | BLOCKED | Native-size1792 retains50 differing bytes in spills/initialization; all previous owning/data checks pass. Dump-only compilation proves unchanged bytes and locates differences at global reload/final scheduling; no missing helper identified. Reproducible source preserved. | src/game/ui/MenuManager.cpp |

| libsanangeles.so | 0x0033ddd5 | ScriptManager::loadCommand(DataStream&) | — | BLOCKED | Evidence-only118opcode audit matches allocation/init/reader/call/return events;78readerbodies unchanged. Saved2440/native2436non-strictdiagnostic fails; no newcompile/sourcecorrection/currentrootclosure. Old143/134+5aggregates are diagnostic only. No credit. | _scratch/worker-load-command-current/README.md; src/game/scripting/ScriptManager.cpp |

| libsanangeles.so | 0x003026b9 | PlayerTest::move(float, float) | — | BLOCKED | Coordinator reviewed six-form deep native audit: accurate2512/native2496B v6 strictfails photo overlap, no ELF. Old2472 images differ2338bytes; historical76/18 vs current84/26 separate. Native receiver/water/animation/math/callback semantics preserved,955stableinputs; no new compile/credit, ownership released. | src/game/ai/PlayerTest.cpp |

| libsanangeles.so | 0x002ffe0d | NPC::Update(int) | — | BLOCKED | Coordinator reran actual3024/native3012B object/helper audit; sole byte102 category1->5 fixes initial chase. Header-only86profiles/7371checks pass,1065inputs stable; target/helper placement fails, no candidateELF/native comparison/credit. Correction frozen unapplied; ownership released. | src/game/ai/NPC.cpp |

| libsanangeles.so | 0x00320351 | ContactListener::Add(b2ContactPoint const*) | lock_init | BLOCKED | best extent 2364/2384 bytes; six forms; header sweep 43/44, known fixture incomplete | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x0039c751 | dump_memory_stats(char const*, int, char const*) | — | COMPLETED | 100% | src/game/core/utility.cpp |

| libsanangeles.so | 0x003935bd | png_memset(void*, unsigned char, int) | — | COMPLETED | 100% | src/game/core/png_helper.cpp |

| libsanangeles.so | 0x003935c9 | png_memcpy(void*, void const*, int) | — | COMPLETED | 100% | src/game/core/png_helper.cpp |

| libsanangeles.so | 0x003935d5 | png_memcmp(void const*, void const*, int) | — | COMPLETED | 100% | src/game/core/png_helper.cpp |

| libsanangeles.so | 0x003935e1 | png_strlen(char const*) | — | COMPLETED | 100% | src/game/core/png_helper.cpp |

| libsanangeles.so | 0x002fd291 | Lock::render() | coordinator | BLOCKED | 304-byte candidate unmatched; six forms; old 8 functions and 10 section/region checks exact | src/game/core/Lock.cpp |

| libsanangeles.so | 0x0034a015 | ASprite::PaintFModule(int, int, int, int, int) const | — | BLOCKED | Coordinator reran audit: actual220B candidate differs28 bytes; current43/37 exact separately, historical39/34 exact with four current definitions absent. Three identical original forms impose stop. No credit; ownership released. | src/game/rendering/ASprite.cpp |

| libsanangeles.so | 0x0034ad9d | ASpriteData::AFrame::Swap() | — | COMPLETED | 100% | src/game/rendering/ASpriteData.cpp |

| libsanangeles.so | 0x0034ac39 | ASpriteData::FModule::Swap() | — | COMPLETED | 100% | src/game/rendering/ASpriteData.cpp |

| libsanangeles.so | 0x0034a3c9 | ASpriteData::Anim::Swap() | — | COMPLETED | 100% | src/game/rendering/ASpriteData.cpp |

| libsanangeles.so | 0x0034acd1 | ASpriteData::Image::Swap() | — | COMPLETED | 100% | src/game/rendering/ASpriteData.cpp |

| libsanangeles.so | 0x0034a231 | ASpriteData::__rect::isIntersecting(int, int) | — | COMPLETED | 100% | src/game/rendering/ASpriteData.cpp |

| libsanangeles.so | 0x0034a655 | ASpriteData::Module::Swap() | — | COMPLETED | 100% | src/game/rendering/ASpriteData.cpp |

| libsanangeles.so | 0x0034a491 | ASpriteData::Frame::Swap() | — | COMPLETED | 100% | src/game/rendering/ASpriteData.cpp |

| libsanangeles.so | 0x0034ae61 | ASpriteData::Swap() | — | COMPLETED | 100% | src/game/rendering/ASpriteData.cpp |

| libsanangeles.so | 0x0034a729 | ASpriteData::Debug() | — | COMPLETED | 100%;1296B plus1140B literal blob; coordinator full183-profile/10267-comparison gate exact | src/game/rendering/ASpriteData.cpp |

| libsanangeles.so | 0x00349e15 | ASprite::PaintModule(int, int, int, int) const | — | BLOCKED | likelihood0/1 emit476/488 versusnative512; oldcurrent42/36 exact; no adoption | src/game/rendering/ASprite.cpp |

| libsanangeles.so | 0x0034a28d | ASprite::GetPixelInfoInFrame(int, int, int, int&, int&) | — | BLOCKED | bounded canonical record trial remains unmatched; frozen private proof reviewed; no credit | src/game/rendering/ASprite.cpp |

| libsanangeles.so | 0x00349315 | FSelect(float, float, float) | — | BLOCKED | Coordinator reran pure-comparison and O1 audits. Direct const helper is identical32B/two-byte miss; single original-source O1 control worsens19bytes. No source/flag adoption, caller gate skipped targetfail; all current bounded hypotheses stopped, ownership released. | src/game/app/IPhone.cpp |

| libsanangeles.so | 0x00349d81 | ASprite::GetAnimDuration(int) | — | BLOCKED | Snapshot86, cursor80, sibling74/native82; canonical80 identical across three frontends, no integration or credit | src/game/rendering/ASprite.cpp |

| libsanangeles.so | 0x002d4a01 | Application::_Update(int) | — | COMPLETED | Existing100%; reviewed authentic STLport proxy reader-path migration (_M_node._M_data); no algorithm/signature change. All native bytes preserved in root190/10923 gate. | src/game/app/Application.cpp |

| libsanangeles.so | 0x003499dd | ASprite::GetAFrame(int, int) | — | COMPLETED | 100%; GNU expect0 hint; full183-profile10277-comparison native gate and caller63/56/2 exact | src/game/rendering/ASprite.cpp |

| libsanangeles.so | 0x002d40fd | Application::ProcessKeyEvent(bool, int) | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d4709 | Application::appKeyPressed(int) | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d4bc1 | Application::GlobalResumingUpdate() | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x0034c599 | TouchScreenBase::getID(long) header integration | — | COMPLETED | 100%; native 68-byte function preserved after interface integration | src/game/input/TouchScreenBase.cpp |

| libsanangeles.so | 0x002d45ad | Application::appKeyReleased(int) | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d4fe1 | Application::_Draw() | — | COMPLETED | Existing100%; reviewed authentic STLport proxy reader-path migration (_M_node._M_data); no algorithm/signature change. All native bytes preserved in root190/10923 gate. | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d50f1 | Application::Update() | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d4861 | Application::displayNumberWithHUDSprite(int, int, int, char const*) | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d4e89 | Application::Resume() | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d5821 | Application::InitWin32(irr::IrrlichtDevice*) | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d4319 | Application::RegisterForIrrlichtEvents(irr::IEventReceiver*) | — | COMPLETED | Existing100%; reviewed mechanical _M_node._M_data reader-path integration under explicit Application prerequisite scope. Original algorithm/signature and all bytes preserved, root190/10923 pass. | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d5559 | Application::RegisterForDrawingInScene(IDrawable*) | — | COMPLETED | Existing100%; reviewed mechanical _M_node._M_data reader-path integration under explicit Application prerequisite scope. Original algorithm/signature and all bytes preserved, root190/10923 pass. | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d4391 | Application::RegisterForDrawingOnHUD(IDrawable*) | — | COMPLETED | Existing100%; reviewed mechanical _M_node._M_data reader-path integration under explicit Application prerequisite scope. Original algorithm/signature and all bytes preserved, root190/10923 pass. | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d4409 | Application::RegisterForUpdate(IUpdatable*) | — | COMPLETED | Existing100%; reviewed mechanical _M_node._M_data reader-path integration under explicit Application prerequisite scope. Original algorithm/signature and all bytes preserved, root190/10923 pass. | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d51f9 | Application::Application() C1/C2 aliases | — | COMPLETED | 100%; both genuine native aliases share exact148-byte body SHA95b28574ae2cf97b30d8c5f91277f100d7ef1d508e4e87fd045bf4ae0ede55f3. Independently verified full190/10923, zero mismatch/skip; two markers removed after acceptance. Catalogue counts296 alias bytes, no new fullylinked unit. | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d4cd1 | Application::Quit() | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d5cf9 | Application::~Application() D1/D2 | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d5c65 | Application::~Application() D0 | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d5591 | Application::Init(irr::IrrlichtDevice*) | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d528d | Application::GetInstance() | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d5eb9 | Application::OnEvent(irr::SEvent const&) | — | BLOCKED | Coordinator iterator reuse restores native596 size, 104-byte frame and all six event slots. Exactly26 scheduling bytes differ at +0x1f6..+0x20f; switch table and all existing owner/JNI comparisons pass. Reviewed unapplied patch preserves evidence without canonical source changes or credit. | src/game/app/Application.cpp |

| libsanangeles.so | 0x002ded05 | GS3DStuff::SetColor(irr::scene::ISceneNode*, irr::video::SColor, GS3DStuff::eColorType) | lock_init | BLOCKED | six candidates; best 452/440 bytes; no credit | src/game/rendering/GS3DStuff.cpp |

| libsanangeles.so | 0x002d24f5 | appResume | — | COMPLETED | 100% | src/game/core/wrapper.cpp |
| libsanangeles.so | 0x002d1415 | Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeDone | — | COMPLETED | 100% | src/game/app/app-android.c |
| libsanangeles.so | 0x002d2715 | launchTwitter | — | COMPLETED | 100% | src/game/core/wrapper.cpp |
| libsanangeles.so | 0x002d134d | Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeOnKeyUp | — | COMPLETED | 100% | src/game/app/app-android.c |
| libsanangeles.so | 0x002d135d | Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeOnKeyDown | — | COMPLETED | 100% | src/game/app/app-android.c |
| libsanangeles.so | 0x002d1dd5 | Java_com_gameloft_android_GAND_GloftGANG_GLMediaPlayer_nativeGetTotalSounds | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |
| libsanangeles.so | 0x002d2655 | appOnKeyUp | — | COMPLETED | 100% | src/game/core/wrapper.cpp |
| libsanangeles.so | 0x002d2679 | appOnKeyDown | — | COMPLETED | 100% | src/game/core/wrapper.cpp |
| libsanangeles.so | 0x002d2511 | appOnTouch | — | COMPLETED | 100% | src/game/core/wrapper.cpp |
| libsanangeles.so | 0x002d26f1 | appDeinit | — | COMPLETED | 100% | src/game/core/wrapper.cpp |
| libsanangeles.so | 0x002d269d | appRun | — | COMPLETED | 100% | src/game/core/wrapper.cpp |
| libsanangeles.so | 0x002d25a9 | appOnAccelerometer | — | COMPLETED | 100% | src/game/core/wrapper.cpp |
| libsanangeles.so | 0x002d2731 | appPause | — | COMPLETED | 100% | src/game/core/wrapper.cpp |
| libsanangeles.so | 0x002d5d89 | Application.cpp::__tcf_4 generated singleton cleanup | — | COMPLETED | 100% | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d2759 | appInit | — | COMPLETED | 100% | src/game/core/wrapper.cpp |
| libsanangeles.so | 0x002d13f5 | Java_com_gameloft_android_GAND_GloftGANG_GameGLSurfaceView_nativePause | — | COMPLETED | 100% | src/game/app/app-android.c |
| libsanangeles.so | 0x002d13d9 | Java_com_gameloft_android_GAND_GloftGANG_GameGLSurfaceView_nativeResume | — | COMPLETED | 100% | src/game/app/app-android.c |
| libsanangeles.so | 0x002d13a1 | Java_com_gameloft_android_GAND_GloftGANG_GameGLSurfaceView_nativeOnTouch | — | COMPLETED | 100% | src/game/app/app-android.c |
| libsanangeles.so | 0x002d13b5 | Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeRender | — | COMPLETED | 100% | src/game/app/app-android.c |
| libsanangeles.so | 0x002d136d | Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeAccelerometer | — | COMPLETED | 100% | src/game/app/app-android.c |
| libsanangeles.so | 0x002d1421 | Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeResize | — | COMPLETED | 100% | src/game/app/app-android.c |
| libsanangeles.so | 0x002d144d | Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeInit | — | COMPLETED | 100% | src/game/app/app-android.c |
| libsanangeles.so | 0x002d1ddd | Java_com_gameloft_android_GAND_GloftGANG_GLMediaPlayer_nativeGetTotalSoundsOfSameInstance | — | COMPLETED | 100% | src/game/app/jni_GLMediaPlayer.c |
| libsanangeles.so | 0x002d1869 | nativeOpenBrowser | — | COMPLETED | 100% | src/game/app/jni_Gangstar.c |
| libsanangeles.so | 0x003eeb71 | RenderFX::SetMember(char const*, char const*, char const*) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003eca0d | CanHandleMouseEvent(gameswf::character*) | — | COMPLETED | 100%; exact92 in owner and both consumers. Combined190-profile10656-check root gate passes; only actualnameaccess expression changed, no hints/flags/data. | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003eccd9 | GetLocalPosition(gameswf::character*, float, float) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003eca69 | sprite_can_handle_mouse_event_callback(gameswf::character*) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x002d1835 | nativeNotifyPause | — | COMPLETED | 100% | src/game/app/jni_Gangstar.c |
| libsanangeles.so | 0x003eed69 | RenderFX::SearchIndex::Find(char const*) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ecf05 | RenderFX::SetColorTransform(gameswf::character*, unsigned int, unsigned int) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x002d18c5 | nativeExit | — | COMPLETED | 100% | src/game/app/jni_Gangstar.c |
| libsanangeles.so | 0x003ed6e5 | RenderFX::Find(char const*, gameswf::character*) | — | BLOCKED | Typed name-chain candidate is 408 versus 416 native bytes; strict size assertion rejects it before linking. No current old-gate or linked match claim; no further variant authorized. | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003f02c5 | RenderFX::SearchIndex::Init(RenderFX&) | — | BLOCKED | Authentic helper candidate emits 492 versus 488 native bytes and fails strict overlap before linked checks. No old-gate or match claim; no further variant authorized. | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x002d18f9 | nativedetectPhoneLang | — | COMPLETED | 100% | src/game/app/jni_Gangstar.c |
| libsanangeles.so | 0x002d192d | nativeUnlockDemo | — | COMPLETED | 100% | src/game/app/jni_Gangstar.c |
| libsanangeles.so | 0x002d1961 | nativeGetVersionMode | — | COMPLETED | 100% | src/game/app/jni_Gangstar.c |
| libsanangeles.so | 0x003ef139 | RenderFX::SendEvent(RenderFX::Event&) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x002d1995 | nativeGetNumLaunch | — | COMPLETED | 100% | src/game/app/jni_Gangstar.c |
| libsanangeles.so | 0x002d16f5 | Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeInit | — | COMPLETED | 100% | src/game/app/jni_Gangstar.c |
| libsanangeles.so | 0x003eee95 | RenderFX::ClearFonts(gameswf::player_context*) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003eefad | RenderFX::InvokeASCallback(gameswf::character*, char const*) | — | BLOCKED | Read-only review confirms three identical 344-byte forms versus 368 native; new character-name APIs do not apply and prior flag probes remain rejected. No new semantic gap. | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003f0041 | RenderFX::Update(int, bool) | — | BLOCKED | Current name-chain trial remains 248 bytes with 17 differing bytes; all 114 old functions and 33 region checks pass. Old best has 12 differences; no further hint or source variant authorized. | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ef201 | RenderFX::SetFocus(gameswf::character*, int) | — | COMPLETED | 100%; exact 356-byte target in three images, full 190-profile/10,590-comparison gate passes. All previous matches retained; no Fully Linked credit. | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003efced | RenderFX::UpdateInput(int, int) | — | BLOCKED | Authentic copy/name/subscript trial emits 840 versus 852 native bytes; strict extent fails and runtime imports remain unresolved. No linked old-gate or match claim; no further source variant. | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ef511 | RenderFX::UpdateCursor(RenderFX::Cursor&, int) | — | BLOCKED | six forms; best1996/2012, inline-functions diagnostic unchanged; no credit | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x002f064d | BulletTraceManager::OnAnimate(unsigned int) | — | BLOCKED | Both machine ABI and primary Irrlicht const-list/value-iterator/pointer-reference APIs already correct; unused stock-position differences irrelevant. No justified trial. | src/game/combat/BulletTraceManager.cpp |
| libsanangeles.so | 0x003514b9 | CSoundDecoderMSADPCM::Decode(short*, int, bool) | — | BLOCKED | Five distinct forms verified; best656 exceeds native652. Native arithmetic matches saved expressions, with no justified sixth-form correction. Relocated/vtable failures are not native proof. | src/game/audio/CSoundDecoderMSADPCM.cpp |
| libsanangeles.so | 0x00317fb5 | LevelObject::canGoToPoint(vector3df const&, vector3df&, vector3df&) | unassigned | BLOCKED | bounded3forms identical3120B,3032equal; current sibling/callers pass; no credit | src/game/world/LevelObject.cpp |
| libsanangeles.so | 0x00330015 | Rocket::launch(vector3df) | — | BLOCKED | one current-interface unchanged replay744B,125bytes differ; old39checks pass; no credit | src/game/combat/Rocket.cpp |
| libsanangeles.so | 0x00304ec9 | PlayerTest::Update() | — | BLOCKED | Coordinator reviewed native965-instruction receiver/timer/lifetime audit; no new semantic correction. Current2200/native2228 object unlinked; old2212 diagnostic lacks eight current definitions, no closure transfer.38 stableinputs, no compile/credit; ownership released. | src/game/ai/PlayerTest.cpp (private) |
| libsanangeles.so | 0x00312081 | Vehicle::_processAIFlags() | — | BLOCKED | Current unchanged safe3060/3220 identical archive; old188/112 and complete76-build header closure2587 functions/2821 regions exact; fixture failures resolved, no credit | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00313b01 | Vehicle::Update(int) | — | BLOCKED | Coordinator reran1639-instruction native audit; two true lifetime/traction predicate fixes preserved. Private model48 profiles/3709 comparisons pass, but sole corrected4036/native4020B fails strict prelink3 with actual PhysicInfo aliases disclosed. No targetELF/closure/credit; ownership released. | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x003215b5 | SceneNodeManager::crc(char const*) const (existing-match regression) | — | COMPLETED | 100% (independent initialization order restored under renderer alias; no new credit) | src/game/world/SceneNodeManager.cpp |

| libsanangeles.so | 0x002dd33d | OctTreeAABB::OctTreeAABBNode::getPolysIter (const box and three output arrays) | — | BLOCKED | Const-SDK context also identical616/native620; both accessor trials parked without integration or credit | src/game/rendering/GS3DStuff.cpp |

| libsanangeles.so | 0x002e078d | GS3DStuff::update(StateMachine*) | — | BLOCKED | one unchanged context replay; 4 instruction/21 GOT differences in GC diagnostic; old destructor overlap blocks integration | src/game/rendering/GS3DStuff.cpp |

| libsanangeles.so | 0x002ddf79 | GS3DStuff::CreateStaticBodies | — | BLOCKED | Prerequisite190/10917 pass. One canonical compoundposition trial1568/native1580, frame180/native172, realordinaryquaternionC1helper28 emitted. Stopped pre-link; no helperoverride/forcedinline/credit. | src/game/rendering/GS3DStuff.cpp |

| libsanangeles.so | 0x002dd7e1 | GS3DStuff::updateVisibility(unsigned int) | — | BLOCKED | six forms; native-size1944 still differs; accessor header regresses Cash; no credit | src/game/rendering/GS3DStuff.cpp |

| libsanangeles.so | 0x002dfb15 | GS3DStuff::load(int, int&) | unassigned | COMPLETED | 100%; function/full section2576B exact, all191 profiles11112 comparisons pass,880 additional merged GS checks exact,1098 frozeninputs stable. Genuine array alias and loader-local adapter accepted; ownership released | src/game/rendering/GS3DStuff.cpp; config/linker/GS3DLoadSections.ld |

| libsanangeles.so | 0x0030c035 | Vehicle::step() | — | BLOCKED | Coordinator reran v6 real4336/native4372B target/fullsection failures; four FP args fixed, old189/113+C1/full96 exact, C2 same real alias,1068inputs stable. No nextcompiled CreateWheels claim, six-source cap reached/no credit; ownership released. | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x0031eb99 | PhysicAttributes::GetHeight(int, vector3df const&, bool, bool) | resume_mission | ASSIGNED | Targeted read-only exact floating-operand and snapshot audit of corrected4982/native5038 source, using newly confirmed physics coefficient/normal lessons. Preserve accepted dirty-ground predicate; no repeated forms or compilation | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x0030d6c9 | Vehicle::UpdatePhysic(float) | — | BLOCKED | Coordinator reran final proof: corrected9104/native9212B function fails strict prelink guard; no new target ELF. All200 old payloads and435 other model sources stable; original970 artifacts preserved. No credit; ownership released. | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x00339cb9 | Script::executeCommand(Structs::ScriptCommand const*, int, int) | — | BLOCKED | Reviewed6forms, final12380/native12636B,frame324/332. Native-backed manager/global, evaluationorder,fade-999,WaitKilled901,base-ID constructor fixes retained privately; WaitStolen421 restored after invalid5thform. Oldgraph31functions/28sections/1GOT exact,842stableinputs; not currentrootclosure. No credit. | _scratch/worker-execute-command-current/README.md; src/game/scripting/Script.cpp |

| libsanangeles.so | 0x002d1de1 | Java_com_gameloft_android_GAND_GloftGANG_GLMediaPlayer_nativeSetStopOnMusic | — | COMPLETED | 100%;2B; DEX-proven ABI; coordinator target and full183-profile gate exact | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d1349 | Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeCanInterrupt | — | COMPLETED | 100%;2B; DEX-proven ABI; coordinator target and full183-profile gate exact | src/game/app/app-android.c |

| libsanangeles.so | 0x002d1335 | Java_com_gameloft_android_GAND_GloftGANG_GameRenderer_nativeGetJNIEnv | — | COMPLETED | 100%;20B; DEX-proven ABI; coordinator target and full183-profile gate exact | src/game/core/CIrrDevicePS3.cpp |

| libsanangeles.so | 0x002d1de5 | GetNativeSoundRaw | — | BLOCKED | native/DEX/relocation/pointer/local-reference audit found no prototype; zero source forms, no credit | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x002d1de9 | GetNativeResourceSoundRawLength | — | BLOCKED | native/DEX/relocation/local-reference audit found no prototype; zero source forms, no credit | src/game/app/jni_GLMediaPlayer.c |

| libsanangeles.so | 0x0032a0e0 | non-virtual thunk to MiniMap::draw2d() const | — | COMPLETED | 100%; full184-profile10311-comparison gate exact; original Map initializer semantics retained; only20Bthunk adds credit, parentdraw2d unmatched | src/game/hud/MiniMap.cpp |

| libsanangeles.so | 0x00328c15 | Map::Map() C1/C2 existing-match compatibility | — | COMPLETED | 100%; full184-profile10311-comparison gate exact; original Map initializer semantics retained; only20Bthunk adds credit, parentdraw2d unmatched | src/game/world/Map.cpp |

| libsanangeles.so | 0x00326795 | EvStickMove D1 existing-match compatibility | — | COMPLETED | 100%; full 190-profile, 10,501-comparison native gate exact; existing event destructor bodies preserved; unmatched parents receive no credit | src/game/input/AnalogStick.cpp |

| libsanangeles.so | 0x00326e15 | EvStickMove D0 existing-match compatibility | — | COMPLETED | 100%; full 190-profile, 10,501-comparison native gate exact; existing event destructor bodies preserved; unmatched parents receive no credit | src/game/input/AnalogStick.cpp |

| libsanangeles.so | 0x003267dd | EvUpDownStickMove D0 existing-match compatibility | — | COMPLETED | 100%; full 190-profile, 10,501-comparison native gate exact; existing event destructor bodies preserved; unmatched parents receive no credit | src/game/input/AnalogStick.cpp |

| libsanangeles.so | 0x00326809 | EvUpDownStickMove D1 existing-match compatibility | — | COMPLETED | 100%; full 190-profile, 10,501-comparison native gate exact; existing event destructor bodies preserved; unmatched parents receive no credit | src/game/input/AnalogStick.cpp |

| libsanangeles.so | 0x0032687d | EvLeftRightStickMove D0 existing-match compatibility | — | COMPLETED | 100%; full 190-profile, 10,501-comparison native gate exact; existing event destructor bodies preserved; unmatched parents receive no credit | src/game/input/AnalogStick.cpp |

| libsanangeles.so | 0x003268a9 | EvLeftRightStickMove D1 existing-match compatibility | — | COMPLETED | 100%; full 190-profile, 10,501-comparison native gate exact; existing event destructor bodies preserved; unmatched parents receive no credit | src/game/input/AnalogStick.cpp |

Coordinator queue review: player_update audits saved candidates of pending game functions >=512 bytes for unspent first-pass budgets or concrete new helper evidence; prefs_loader audits pending <=511-byte saved candidates for exact-but-unintegrated genuine native proofs. Both tasks are read-only queue triage, not function ownership, and neither permits source edits or compilation. Coordinator will identify and assign each next function before decompilation.

Coordinator completed the latest read-only queue triage and assigns prefs_loader only the registered IsPositionOnJump ledger audit. No compilation is authorized for that scope.

Coordinator assigns player_update only Tutorial localization implementation. Volumes localization and setText require separate ownership before any future implementation. Shared string changes stay in isolated candidate mirrors; the coordinator alone integrates common declarations.

Coordinator assigns vehicle_camera read-only queue triage for additional pending game functions with concrete absent canonical string/value/name APIs. Exclude active Tutorial and Volumes localization; no implementation ownership or compile permission is granted by triage. SetText remains parked.

### Bounded pathfinding constructor review after PR735

The coordinator owns only ComputeShortestPath at Thumb 0x00320ca1/1668.
A separate ordinary-object fixture now proves the current PhysicInfo interface
emits the accepted weak 96-byte C1 and a native GOT call. Old v5/v6 emitted a
strong C1/direct call. One replay of the saved genuine-object algorithm is
allowed after independently validating its genuine container/node interfaces
with the target absent. No first-pass budget reset, unrelated body changes,
flags, output edits, or unchecked overlapping verification image are allowed.

The first private prerequisite gate rejected a generic array constructor: it
changed existing CollisionBodyDef and LODSceneNode matches. That failed tree
and full log are retained. Recovery removes only that generic constructor;
the target will reuse the existing zero-storage PathArray initialization view
for its two arrays. This restriction adds no body iteration and changes no
existing matched function. A fresh full target-absent gate is required.

The coordinator reviewed and parked the single current-interface replay. The
restricted target-absent prerequisite passed all 190 profiles and 10,935
comparisons with 952 frozen inputs stable. The body is 1,688/native 1,668 bytes,
frame 460; C1 is the accepted weak 96-byte constructor with R_ARM_GOT32 call,
and only the target is newly emitted. The probe stopped before linking. No
post-body closure or matching percentage is claimed. Public unapplied patch,
Windows prelink reproducer and exact limits are preserved under
nonmatching/characters/ComputeShortestPath*. Ownership is released; no further
source iteration is authorized without new evidence.

### Bounded const-array octree query review after PR735

The coordinator owns only getPolysIter at Thumb 0x002dd33d/620. All six
archived forms use raw array fields. The genuine release size/indexed interfaces
now established by the checkpoint and lower-cost-node matches justify one
const-array accessor adaptation of saved v5. First validate the ordinary const
operator[] interface with the target absent across all profiles. No traversal,
comparison, field, flag, helper, or existing-body changes are authorized.

The private const-overload gate failed an existing WeaponManager function/section
and two dependents skipped. That header change is rejected and preserved only
privately. Native root-array fields are mutable pointers even on a const node;
the single body adaptation will use the existing non-const indexed accessor
and size(), removing the old candidate local pointer's unnecessary constness.
No header changes are needed. All 945 canonical native inputs remain identical
to the accepted full 190-profile/10,935-comparison proof; that exact target-absent
baseline is reused after hashing every input, rather than claiming the rejected
const-overload gate passed. No body trial has occurred before this correction.

The coordinator reviewed the octree replay and released ownership. Its only
new definition is getPolysIter; function and section remain 616/native 620
bytes, with 16 normalized relocations identical to archived v5. Eight raw byte
offsets differ from that old object; this is not a linked/native comparison or
a claimed improvement. The single body adaptation is parked before linking.
No traversal/comparison/field/flag changes, shared headers, canonical bodies,
assembly markers or matching credit were integrated. The failed const-overload
prerequisite and the existing-interface replay are retained separately.

Read-only queue audits also confirmed WantedMeter::update has six saved forms
(100, 84, 84, 84, 88, 88 bytes against native 80); current interfaces provide no
new call/layout gap. No replay was performed. ScriptManager::reachRunningCommand
uses raw script arrays, not the recovered list iterator; six saved source forms
remain parked. The six unregistered PVRTC entries remain unchanged and pending:
legacy dependency-family evidence exists, but exact wrapper/revision attribution
is unresolved. No source assignment or provenance correction was made for them.

| libsanangeles.so | 0x00331a09 | WeaponManager::getKeepWeaponsWhenBustedCost() compiler diagnostic only | — | COMPLETED | Diagnostic complete; both entire objects reproduced, PHI/zero-order divergence isolated; canonical 100% match unchanged | src/game/combat/WeaponManager.cpp |

The coordinator will compare the accepted and rejected-header contexts using
compiler tree/RTL dumps, after proving diagnostic output matches each archived
object. No existing function body, production flag or shared header may change.

A new two-context diagnostic reproduces both complete WeaponManager objects
byte for byte with compiler dumps enabled. The only input difference is the
genuine const array accessor. Equivalent trees first differ in PHI order, then
SSA destruction reverses i/total zero initialization; final assembly removes
one Thumb zero instruction and two alignment bytes. This measured cause
permits one additional private octree const-accessor context check, retaining
the saved const pointer and genuine SDK read APIs. It does not authorize
integration of the regressing header or any unrelated body change.

The two diagnostic compiles reproduce the entire accepted 264-byte and rejected
260-byte WeaponManager objects exactly. Each contains 116 numbered dumps.
After temporary/SSA-name normalization, PHI ordering first differs during SSA
construction; statements remain equivalent through uncprop, and SSA destruction
reverses i/total initialization. Final assembly removes one zero instruction
and two alignment bytes before the unchanged 16-byte literal pool. Pinned GCC
4.2.1 sources explain a consistent declaration-ID/hash/PHI-order mechanism;
Android patch identity is not assumed. See docs/COMPILER-CONTEXT.md. No dummy
declarations, production flags or existing body changes are proposed. Diagnostic
ownership is released. The additional genuine const-SDK octree context is
byte-identical to the first 616-byte accessor replay and is also parked before
linking; no further iteration is authorized without new evidence.

### WantedMeter current-context bounded review

The coordinator reviewed and released the old vehicle_side assignment, then
claimed only WantedMeter::update(double), Thumb 0x0032c851/80. Six saved forms
remain exhausted. The saved first form has four source-level
SetAnim/UpdateFrame calls; later forms have two. These source counts alone do
not establish the emitted static call inventory. Since then the actual
WantedLevelManager fields have been recovered as four doubles and two bools,
replacing opaque byte arrays without changing layout. The measured declaration
ordering diagnostic justifies one current-context replay of the faithful
peeled-loop form. First validate only its ordinary friend access declaration
with the target absent; no field, algorithm, production flag or old body change.

The current first-form replay emits 100/native80 bytes and only the target.
Assembly review found that GCC peels another iteration, emitting six static
animation calls, not the four counted in its source. The earlier selection
rationale incorrectly equated source calls with emitted calls; it is corrected
here. This concrete compiler-peeling evidence authorizes one additional bounded
replay of saved v3, the ordinary pointer loop, against the same independently
preserved prerequisite. It must verify the emitted call inventory before any
matching claim; no new algorithm, declaration, flag or source variation. The
first replay remains a failed, counted attempt, not a budget reset.

The saved-v3 current replay emits 84/native80 bytes, only the target, and the
native four animation call sites. Assembly isolates an outlined timer<=0
addition with an extra branch and one extra this-to-array-pointer copy. This
new emitted-CFG evidence authorizes one ordinary __builtin_expect(cond,1) on
that existing timer condition, as permitted by the maintainer clarification.
No other source, declaration or flag change is authorized. Any credit still
requires the complete native function and affected existing comparisons.

The single pointer-loop likelihood form remains 84/native80 bytes. It restores
the native timer branch layout, leaving a this-to-pointer copy and alignment
gap. The coordinator authorizes one final bounded reuse of the saved indexed
loop (also the traversal style of matched WantedMeter::draw2d) with the same
hint. This uses the actual fixed member array and removes the explicit cursor
local; no invented declarations or register controls. Stop after this form
unless a complete exact match warrants ordinary integration/closure checks.

The final indexed-loop likelihood candidate matches all 80 native function
bytes and its complete physical section. Root full verification passed all
190 profiles and 10,937 comparisons (5,426 functions, 5,330 sections, 181
regions), exit 0, no mismatch or skip, all 955 frozen inputs stable. Native and
linked SHA256 is 5d1df700fb9cbc7586421a81c2db36f0dc6da836ffc63d7d7f8056928be2af74.
The coordinator accepted it, removed only its verified assembly marker and
released ownership. The GNU hint and exact comparison output are documented
in docs/matches/wanted-meter-update.md. Constructor aliases remain pending;
no Fully Linked credit is added. No existing matched body changes.

### WantedMeter constructor rectangle-value review

The coordinator reviewed the six archived constructor forms and releases the
old lock_init ownership. All manually store four touch-region coordinates.
The current engine rectangle interface is already used by touchscreen region
queries and has the same four-float layout. One bounded value-construction
trial from saved v6 may test that genuine interface without changing storage,
public signatures, allocation, loop or existing matched bodies. First verify
only the required includes with the target absent in its sole owning profile;
all other native inputs must match the accepted full baseline exactly.

The rectangle-value form emits 268/native272 bytes and only the two constructor
aliases; it stops before linking. Its emitted height load is still late. One
final bounded check may reuse the existing SDK dimension2d<int> value constructor
for the native integer width/height, then convert those dimensions when storing
the four coordinates. This tests actual value capture through the recovered
const-reference dimension interface; no shared header, field, flag, allocation
or loop changes. Stop after this additional API form if it is not exact.

The coordinator reviewed and parked both bounded SDK-value forms. Rectangle
and dimension candidates each emit 268/native272 bytes; their raw target hashes
differ, and only the two intended C1/C2 aliases are newly defined. Both stop
before linking. The includes-only, target-absent prerequisite passed 12 function,
7 section and 1 region checks with all 955 frozen inputs stable. A file-by-file
audit proves WantedMeter.cpp is the only changed native input and its sole
profile is sdk-startup-wantedmeter; all other source/config/tool inputs are
identical to the accepted full baseline. This is owner prerequisite proof, not
a fresh full-190 or post-body linked proof. Original touch-region type identity
is still unproven; compatible rectangle layout alone does not establish it.
No shared type, header, canonical body, marker, matching credit or Fully Linked
credit is changed. Ownership is released; no further constructor forms are
authorized without new evidence.

### Canonical ASprite data-pointer review

The coordinator owns only GetAnimIdx at Thumb 0x00349dd5/64. Its six archived
forms and later record/helper trials remain exhausted. Current ASprite still
stores its data through a duplicate SpriteData proxy although the actual
ASpriteData header already models the same record/count/offset layout. One
isolated recovery may use ASpriteData* for that field, remove the duplicate
proxy, and make only necessary type-name compatibility edits in _setPtr,
PaintAFrame and GetFrameIdx. Preserve storage, signatures, allocation and all
existing compiled bytes. Validate the target-absent prerequisite across all
190 profiles before one saved canonical lookup replay. Accept no refactor
unless the pending function matches and all old matches survive.

The canonical-data target still differs only at ADD bytes 0x14/0x15: 62/64
linked bytes agree, all 42 existing owner functions, 35 sections and one region
pass. Source recovery alone is not accepted. The existing toolchain provenance
audit identifies r3 as a distinct, previously unrepresented frontend in saved
fidelity comparisons. One controlled diagnostic may replace only the owning
ASprite C++ frontend with r3 while freezing source/options and retaining the
known 1.6 assembler, linker and harness frontend. No production configuration
change or toolchain identity claim is authorized by this diagnostic.

The r3-only frontend diagnostic preserves all 42 old functions, 35 sections and
one region, but emits an identical raw lookup and the same two mismatches.
The coordinator authorizes one final direct-family reuse: copy the existing
matched GetFrameIdx traversal, changing only function/count/table/record names
for animation lookup. It uses the actual mutable data pointer of this non-const
method, unlike every saved const-view form. The canonical-data prerequisite
already preserves all old bytes. No new declarations, helpers, flags, layout
or synthetic operations may be added; park if this direct reuse still fails.

Direct GetFrameIdx reuse matches the complete native64 function and section,
SHA256 a79ca34d6b096e5534188720f8374fd14e6b63176ba3d8e6738e2c1388111d8d; all
existing owner checks pass. Before integration, one compatibility reduction
checks the original shared data view: only add the ordinary GetAnimIdx
declaration, then use an explicit mutable ASpriteData view in the same proven
lookup body. This may avoid type-only compatibility edits to three existing
functions. It is not a new search or algorithm variant; preserve the fully
verified canonical candidate if the reduced prerequisite does not preserve
all old matches. No production source has changed yet.

The reduced declaration-only prerequisite passed all 190 profiles and 10,937
comparisons, target absent, all 955 inputs stable. The same direct-family lookup
with an explicit mutable ASpriteData view matches all native64 bytes and its
complete section; the broader pointer refactor is not integrated. Final root
full verification passed 190 profiles and 10,939 comparisons (5,427 functions,
5,331 sections, 181 regions), exit0, no mismatch or skip, all 955 inputs stable.
SHA256 a79ca34d6b096e5534188720f8374fd14e6b63176ba3d8e6738e2c1388111d8d.
Only the independently verified marker is removed. No existing body, layout,
production option or denominator changes. Ownership released; exact proof in
docs/matches/asprite-animation-name.md.

### Animation-duration value capture review after PR737

The coordinator owns only GetAnimDuration at Thumb 0x00349d81/native82. The
actual first pass had five source forms, followed by separately bounded
canonical, order, indexed and helper studies; no budget is reset. Existing
compiler dumps prove TER replaces the single-use firstFrame memory load with
a fused signed load. One actual Anim-record value snapshot after the existing
Application singleton call may test whether genuine aggregate value capture
preserves the narrow value. Keep the cached record pointer, count guard, data
reload, signed fields, end-pointer loop and runtime stride of 9 bytes. No new helper,
header, field type, attribute, production option or synthetic use is allowed.

The Anim-value snapshot emits 86/native 82 bytes (section 88), only the target,
and stops before linking. It retains the firstFrame halfword but reads it
before the positive-count guard. The existing primary GCC audit also documents
TER invalidation on a real same-root variable definition. One final bounded
dataflow form may reuse a byte cursor first for the cached animation record,
then for the reloaded frame table; both assignments must serve actual reads.
This keeps the firstFrame read inside the guard while testing ordinary buffer
cursor lifetime. No unused operations, volatile, barrier, attribute or flag
changes are allowed. Earlier source/order variants used separate entry/base
variables, not this two-phase cursor. Stop after this form if unmatched.

The two-phase cursor also emits 80/native 82 bytes and is byte-identical in its
entire unlinked target to the archived canonical80; it remains uncredited.
Further inspection of the existing matched two-argument GetAFrame method
revealed a distinct direct-family form: typed frame-data reload and accumulator
inside the positive-count branch, unlike the earlier indexed-duration trial.
The coordinator permits one direct copy of that proven traversal, removing
only the early time exit and returning the accumulated duration (or zero for
nonpositive count). No helper call, new declaration, flag or synthetic narrow
use. This is a separately bounded reuse check, not a reset of earlier attempts.

Direct matched GetAFrame body reuse emits 74/native 82 bytes (section 76), retains
an extra index counter, and stops before linking. Source variants are stopped.
One final controlled diagnostic compares the canonical80 source with the three
installed GCC4.2.1 frontends, holding source/options, original1.6 assembler,
linker and harness frontend fixed. Each non-native extent stops before linking.
This is not a flag search, source-budget reset or production toolchain change.

The coordinator reviewed and parked all duration work. The record snapshot
emits 86/native 82 bytes (section 88), the real two-phase cursor emits 80 (section 80)
and is byte-identical to the old canonical target, and direct GetAFrame-body
reuse emits 74 (section 76) with the extra index counter. Only the target is newly
emitted in each case. All stop before linking; no post-body closure is claimed.
The canonical source then emits identical 80-byte targets with the 1.6 r1, r3
and r4b frontends while source/options and original assembler remain fixed.
All 955 input files are identical across the three contexts. Each extent guard
exits 3 before linker/harness invocation. No field, source body, declaration,
production flag, marker or progress credit is integrated. Current shared types
and all existing matches remain intact. Ownership released; further source
search needs new evidence. See docs/COMPILER-NOTES.md for exact scope.


## Coordinator review: original NDK enum-width baseline

On 2026-11-19, the coordinator reviewed both original NDK setup files and a
controlled 190-profile replay of `-fno-short-enums`. All 10,949 comparisons
passed without failures or skips. The 180 ARM profiles that omitted this
SDK-default flag now list the exact verified arguments; ten were unchanged.
No function ownership, source body, assembly status or progress credit changes.
See docs/COMPILER-NOTES.md. This is a compiler prerequisite, not completion of
any pending function or a substitute for its byte comparison.


## Coordinator SDK-default replay batch, 2026-11-19

The following assignments superseded the historical parked owners during this
read-only compiler-baseline audit. Root reviewed all results and released
ownership; no C++ or
header changes are permitted. Compile each exact saved context twice, first
with its recorded ordinary flags and then with only the verified NDK default
-fno-short-enums added. Other flags must equal the current production profile
with that one flag removed. No arbitrary flag combinations, linking, credit or
integration are authorized by this batch. Stop after one pair per context.
The coordinator reviews results and releases ownership. Worker quota remains
unavailable; compiler subprocesses are not sub-agents.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x002ecb9d | `_ZN7Widgets6IGMenu9GoToFrameEPKc` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/igmenu-frame-bool-current/src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x003017b1 | `_ZN10PlayerTest15onTargetReachedEv` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/player-on-target-reached-gdb-return-trace-current/src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00352cad | `_ZN12SoundManager24getNumberOfPlayingSoundsEv` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/sound-playing-diagnostics-current/src/game/audio/SoundManager.cpp |
| libsanangeles.so | 0x00349445 | `_ZN10AnimObject10IsAnimOverEv` | — | BLOCKED | Coordinator reran actual108/112-byte target failures and378 ordered/unordered branch cases; native receiver/speed/frame semantics agree. Current21/22 exact, no new source/compile/cause or credit; ownership released. | _scratch/animobject-over-negative-likelihood-current/src/game/characters/AnimObject.cpp |
| libsanangeles.so | 0x00300bc5 | `_ZN4Path4LoadERKN7Structs4PathEPN3irr7collada15CColladaFactoryE` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/path-load-vector-assignment-current/src/game/world/Path.cpp |
| libsanangeles.so | 0x0033ffc1 | `_ZN13ScriptManager12cleanCommandEPN7Structs13ScriptCommandE` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/script-clean-command-separate-cases-current/src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0034a015 | `_ZNK7ASprite12PaintFModuleEiiiii` | — | BLOCKED | Coordinator reran audit: actual220B candidate differs28 bytes; current43/37 exact separately, historical39/34 exact with four current definitions absent. Three identical original forms impose stop. No credit; ownership released. | _scratch/asprite-paint-fmodule-canonical-current/src/game/rendering/ASprite.cpp |
| libsanangeles.so | 0x002e8551 | `_ZN9MenuState7OnEventERN8RenderFX5EventE` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/menu-state-on-event-typed-current/src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x003218d9 | `_ZN16SceneNodeManager14reclaimGarbageEv` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/scene-reclaim-current-context/src/game/world/SceneNodeManager.cpp |
| libsanangeles.so | 0x002e86fd | `_ZN9MenuState8GotFocusEv` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/menustate-gotfocus-typed-first-current/src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x003f0041 | `_ZN8RenderFX6UpdateEib` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/renderfx-update-chain-current/src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ece05 | `_ZN8RenderFX19ForceTexturesToVRAMEbPN7gameswf14player_contextE` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/renderfx-force-textures-typed-current/src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x0031b29d | `_ZN16PhysicAttributesC1EiP6b2Body` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/physic-attributes-ctor-rtl-current/src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x0031b29d | `_ZN16PhysicAttributesC2EiP6b2Body` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/physic-attributes-ctor-rtl-current/src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x00333e41 | `_ZN9FPSCamera6scrollERKSt4listIP7Point2DIsESaIS3_EE` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/fps-scroll-real-character-prerequisite-current/src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x002f2581 | `_ZN9Character14goToCombatIdleEv` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/character-combat-idle-plain-cases-current/src/game/characters/Character.cpp |
| libsanangeles.so | 0x002d2d61 | `_ZN12LODSceneNode15computeLODLevelEv` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/lod-compute-sdk-array-current/src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x003470f9 | `_ZN11SideMission17enableCheckpointsERN3irr4core5arrayIP10CheckpointNS1_12irrAllocatorIS4_EEEENS1_8vector3dIfEE` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/side-mission-enable-array-api-current/src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x003edc7d | `_ZN8RenderFX13PreloadGlyphsEv` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/renderfx-preload-all-subscript-current/src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x002eb761 | `_ZN5Menus16ServiceCarRental6NotifyEPK10MenuWidgeti` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/car-rental-full-typed-current/src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002ea479 | `_ZN5Menus8MainMenu6NotifyEPK10MenuWidgeti` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/mainmenu-notify-switch-likelihood-current/src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x003049e5 | `_ZN10PlayerTest7RespawnEv` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/player-respawn-character-interface-current/src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x0034f555 | `_ZN9CarSounds21UpdateOffEngineSoundsEv` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/carsounds-off-engine-canonical-current/src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x002d5eb9 | `_ZN11Application7OnEventERKN3irr6SEventE` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/application-on-event-iterator-current/src/game/app/Application.cpp |
| libsanangeles.so | 0x00330015 | `_ZN6Rocket6launchEN3irr4core8vector3dIfEE` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/rocket-current-context/src/game/combat/Rocket.cpp |
| libsanangeles.so | 0x00333ab1 | `_ZN12FollowCamera6updateEf` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/follow-camera-update-matched-facing-current/src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x002e4e7d | `_ZN11MenuManager6updateEP12StateMachine` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/menu-manager-update/src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x00335849 | `_ZN13VehicleCamera6updateEf` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/vehicle-camera-update-negative-product-current/src/game/vehicles/VehicleCamera.cpp |
| libsanangeles.so | 0x00313385 | `_ZN7Vehicle9collisionEN3irr4core8vector3dIfEEi` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/vehicle-collision/src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030406d | `_ZN10PlayerTest20updateCarInteractionEv` | — | BLOCKED | Code unchanged; anonymous constant payload identical; unlinked, no credit | _scratch/player-car-interaction/src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x002e574d | `_ZN11MenuManager5setupEb` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/menu-manager-setup-qualified-stream-current/src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x002d4015 | `_ZN11Application19UnRegisterForUpdateEP10IUpdatable` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/application-unregister-update-iterator-current/src/game/app/Application.cpp |
| libsanangeles.so | 0x00349d81 | `_ZN7ASprite15GetAnimDurationEi` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/asprite-duration-frontend-r4b-current/src/game/rendering/ASprite.cpp |
| libsanangeles.so | 0x0034228d | `_ZN13NPCController7onEventEPK6IEventPK12EventManager` | — | BLOCKED | Coordinator reran audit: original real v1 is96B with15differences, first42; later94B object has stale ABS-only ELF and no linked proof. Load/gate/pointer scheduling differs but no new semantic API defect; six forms exhausted, no compile/credit. Ownership released. | _scratch/npc-controller-event-switch-current/src/game/ai/NPCController.cpp |
| libsanangeles.so | 0x003219cd | `_ZN16SceneNodeManager4dropEiPKN3irr5scene10ISceneNodeE` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/scene-drop-current-context/src/game/world/SceneNodeManager.cpp |
| libsanangeles.so | 0x003ee721 | `_ZN8RenderFX11SearchIndex5ClearEv` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/renderfx-search-clear-iterator-current/src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x0032c961 | `_ZN11WantedMeterC1EP7ASpritei` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/wanted-meter-ctor-dimension-value-current/src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032c961 | `_ZN11WantedMeterC2EP7ASpritei` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/wanted-meter-ctor-dimension-value-current/src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0034a28d | `_ZN7ASprite19GetPixelInfoInFrameEiiiRiS0_` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/asprite-pixel-info/src/game/rendering/ASprite.cpp |
| libsanangeles.so | 0x003f02c5 | `_ZN8RenderFX11SearchIndex4InitERS_` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/renderfx-search-init-typed-current/src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x002f064d | `_ZN18BulletTraceManager9OnAnimateEj` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/bullet-trace-on-animate/src/game/combat/BulletTraceManager.cpp |
| libsanangeles.so | 0x0031da29 | `_ZN16PhysicAttributes29IntersectSegmentWithHeightMapERKN3irr4core8vector3dIfEES5_RS3_S6_` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/physics-segment-fork-cross-current/src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x00332cf5 | `_ZNK13CameraManager16getClickedTargetEN3irr4core6line3dIfEEb` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/camera-clicked-center-helper-current/src/game/core/CameraManager.cpp |
| libsanangeles.so | 0x0031b3e9 | `_ZN16PhysicAttributes19SetHeightAttributesEPN3irr5scene10ISceneNodeERKNS0_4core8vector3dIfEER10PhysicInfo` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/physics-set-height-cross-current/src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x002e51fd | `_ZN11MenuManager7setTextENS_5eTextEPKcPi` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/menu-manager-set-text-composition-current/src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x0031e285 | `_ZN16PhysicAttributes18AddCollisionShapesEit` | — | BLOCKED | Corrected 1820 / native 1816 bytes; unlinked, no credit | _scratch/physics-add-collision-native-order-current/src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x002e76e9 | `_ZN8RenderFX5Event16GetCharacterPathEv` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/renderfx-event-character-path-typed-current/src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x00321721 | `_ZNK16SceneNodeManager6reportEv` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/scene-report-current-context/src/game/world/SceneNodeManager.cpp |
| libsanangeles.so | 0x003ed6e5 | `_ZN8RenderFX4FindEPKcPN7gameswf9characterE` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/renderfx-find-context-name-current/src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ed9ed | `_ZN8RenderFX13PreloadGlyphsEPtiPKcibbPN7gameswf6filterE` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/renderfx-preload-glyph-array-faithful-current/src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x0030b68d | `_ZN7Vehicle17ResetBodyPositionEv` | — | BLOCKED | Coordinator reran actual four forms788/772/796/784 versus792B and native330-instruction audit. Two slots remain but no concrete source/helper hypothesis; all three actual SetXForm points already distinct, no padding. Old188/112 omit newcollision, no current closure. No compile/credit; ownership released. | _scratch/vehicle-reset-body-position-box2d-current/src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x002eac65 | `_ZN5Menus18OptionGameSettings6NotifyEPK10MenuWidgeti` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/option-game-settings-member-getter-current/src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002eb6a9 | `_ZN5Menus17ServiceCorruption6NotifyEPK10MenuWidgeti` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/service-corruption-full-typed-current/src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x00349e15 | `_ZNK7ASprite11PaintModuleEiiii` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/asprite-paint-module/src/game/rendering/ASprite.cpp |
| libsanangeles.so | 0x003efced | `_ZN8RenderFX11UpdateInputEii` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/renderfx-update-input-typed-current/src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x0034b3c5 | `_ZNK13StringManager12formatAmountEibb` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/stringmanager-format-amount-separate-cases-current/src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x00341a3d | `_ZN20CopVehicleController7onEventEPK6IEventPK12EventManager` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/cop-vehicle-on-event/src/game/ai/CopVehicleController.cpp |
| libsanangeles.so | 0x0030fac9 | `_ZN7Vehicle10CreateBodyEv` | — | BLOCKED | Corrected 1060 / native 1044 bytes; unlinked, no credit | _scratch/vehicle-create-body-sixth-current/src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x003f01d1 | `_ZN6MenuFX15GetStateHandlerEPN7gameswf9characterE` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/menufx-state-handler-typed-current/src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x00320ca1 | `_ZN16PhysicAttributes19ComputeShortestPathEiiN3irr4core8vector3dIfEES3_f` | — | BLOCKED | Coordinator reran supported1688/native1668 and rejected1692 object/weak96B constructor/GOT audit. Eleven old images retain overlap/relocation limits;77 inputs stable, full semantic audit found no new causal discrepancy. No compile/credit; ownership released. | _scratch/physics-shortest-current-replay/src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x002ff5d1 | `_ZN3NPC12attackTargetEv` | — | BLOCKED | Coordinator reran223 old functions/59 regions and independently checked native first164 receiver is target, second owner. Corrected2084/native2108B remains mismatched18; original2088B reproduced, sole new definition,1063 stableinputs. Accurate correction preserved unapplied, no credit; ownership released. | _scratch/npc-attack-target/src/game/ai/NPC.cpp |
| libsanangeles.so | 0x00313b01 | `_ZN7Vehicle6UpdateEi` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/vehicle-update/src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x002e1e15 | `_ZN9GSFailure6draw2dEPK12StateMachine` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/gsfailure-alpha-control-current/src/game/app/GSFailure.cpp |
| libsanangeles.so | 0x003eefad | `_ZN8RenderFX16InvokeASCallbackEPN7gameswf9characterEPKc` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/renderfx-invoke-as-callback/src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ef511 | `_ZN8RenderFX12UpdateCursorERNS_6CursorEi` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/renderfx-update-cursor/src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x0034b78d | `_ZN13StringManager13loadPackSheetEjj` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/stringmanager-load-pack-sheet-cursor-current/src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0032f201 | `_ZN20SniperControlHandler15onKeyboardEventEPK6IEvent` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/sniper-keyboard-separate-cases-current/src/game/input/SniperControlHandler.cpp |
| libsanangeles.so | 0x00340305 | `_ZN9AIManager5addAIEP7VehicleN8gameloft2ai7StateIDE` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/ai-manager-vehicle-npc-reuse-current/src/game/ai/AIManager.cpp |

Coordinator review completed: all 66 contexts compiled and assembled both ways,
with unchanged tracked source/header/manifest hashes. Of 68 functions, 65 retain
identical target bytes and relocation signatures. PlayerTest::updateCarInteraction
retains identical code and a byte-identical 14-byte referenced constant; only its
compiler-generated anonymous-namespace symbol name changes. Two targets change
instruction bytes but still fail native extent: AddCollisionShapes 1820/1816 and
Vehicle::CreateBody 1060/1044. Repeated old-flag controls reproduce both original
raw hashes. No links, native target acceptance, header closure or credit follow.
See docs/matches/ndk-enum-default-replay.md and its complete 68-entry JSON ledger.
The function statuses remain BLOCKED; this is not a global goal blocker.

## PVRTC provenance investigation

The initial assignment was read-only source attribution. After native argument
and caller review, the coordinator authorized exactly one thin-adapter candidate
without changing provenance. The independently verified result is recorded below.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x0020ccd5 | PVRTCDecompress(void const*, int, int, int, unsigned char*) | — | COMPLETED | 100%; coordinator independently rebuilt20B function/fullsection and verified sole definition/native boundaries, then191 profiles/10955 comparisons exact with1065 stableinputs. Only verified marker removed, all17703 identities retained; no provenance/denominator change. Inferred return view documented; ownership released. | src/game/rendering/PVRTDecompress.cpp; local Irrlicht source; private evidence |

## Consumed visibility interface review

This is a declaration-only game-interface prerequisite. The native engine body
is not reconstructed or credited.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x00272879 | irr::scene::ISceneNode::getVisibility consumed return interface | — | COMPLETED | Consumed opaque-address ABI corrected; native getter this+300 and caller word dereference verified. Partial340B/alignment4/member slot unchanged. Full191profiles/10957comparisons exact,1068inputs stable. No engine body or progress credit; ownership released. | src/game/core/SceneNode.h; docs/matches/scene-visibility-return.md |

## Reactivated worker wave after PR 754

The runtime permits four concurrent agents including the coordinator, so this
wave uses three workers. Prior ownership was released only after independent
coordinator proof reruns. Workers remain confined to separate private mirrors;
only the coordinator may edit shared files, integrate, remove markers or use Git.
Existing attempt limits remain binding. Historical trials must be recovered
before proposing a new compile; exhausted searches need a concrete new cause
and separately bounded coordinator approval.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x0020c469 | util_number_is_power_2(unsigned int), `_Z22util_number_is_power_2j` | � | COMPLETED | 100%; coordinator independently rebuilt complete native function/fullsection and verified all191 profiles/10967 comparisons exact,1068 frozen inputs stable. Only verified marker removed; ownership released. | src/game/rendering/PVRTDecompress.cpp; _scratch/worker-pvrtc-power-two-reactivated/ |
| libsanangeles.so | 0x00352cad | SoundManager::getNumberOfPlayingSounds(), `_ZN12SoundManager24getNumberOfPlayingSoundsEv` | � | BLOCKED | Coordinator reran check-evidence.py exit0: actual80B target/fullsection still differs only bytes32/33;23 inputs stable, no compile or new cause. Ownership released. | src/game/audio/SoundManager.cpp; _scratch/worker-sound-count-reactivated/ |
| libsanangeles.so | 0x0031b29d | PhysicAttributes::PhysicAttributes(int,b2Body*), `_ZN16PhysicAttributesC1EiP6b2Body` and same-address C2 alias | � | BLOCKED | Coordinator reran audit.py exit0: both actual260B aliases differ six bytes, real PhysicInfo96 helper exact. Historical37/10 exact, current FindLowerCostNode absent. No new cause or compile; ownership released. | src/game/characters/PhysicAttributes.cpp; _scratch/worker-physic-ctor-reactivated/ |
| libsanangeles.so | 0x0020c6ed | TwiddleUV(unsigned long,unsigned long,unsigned long,unsigned long), `_Z9TwiddleUVmmmm` | � | COMPLETED | 100%; coordinator independently rebuilt complete native function/fullsection and verified all191 profiles/10967 comparisons exact,1068 frozen inputs stable. Only verified marker removed; ownership released. | src/game/rendering/PVRTDecompress.cpp; _scratch/coordinator-twiddleuv-current/ |

| libsanangeles.so | 0x00353175 | SoundManager::update(double), `_ZN12SoundManager6updateEd` | � | BLOCKED | Coordinator reran check-evidence.py exit0: actual428B/fullsection differ bytes230/231;17 inputs stable. Three prior identical forms impose stop, no new cause or compile; ownership released. | src/game/audio/SoundManager.cpp; _scratch/worker-sound-update-reactivated/ |

## PVRTC source-reuse continuation

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x0020c485 | InterpolateColours(int const*,int const*,int const*,int const*,int,int,int,int*), `_Z18InterpolateColoursPKiS0_S0_S0_iiiPi` | � | COMPLETED | 100%; coordinator independently rebuilt complete native function/fullsection and verified all191 profiles/10967 comparisons exact,1068 frozen inputs stable. Only verified marker removed; ownership released. | src/game/rendering/PVRTDecompress.cpp; _scratch/worker-pvrtc-interpolate-current/ |
| libsanangeles.so | 0x0020c5bd | GetModulationValue(int,int,int,int const (*)[16],int const (*)[16],int*,int*), `_Z18GetModulationValueiiiPA16_KiS1_PiS2_` | � | COMPLETED | 100%; coordinator independently rebuilt complete native function/fullsection and verified all191 profiles/10967 comparisons exact,1068 frozen inputs stable. Only verified marker removed; ownership released. | src/game/rendering/PVRTDecompress.cpp; _scratch/worker-pvrtc-modulation-current/ |
| libsanangeles.so | 0x0020c73d | Decompress(AMTC_BLOCK_STRUCT*,int,int,int,int,unsigned char*), `_Z10DecompressP17AMTC_BLOCK_STRUCTiiiiPh` | � | COMPLETED | 100%; coordinator independently rebuilt complete native function(s)/sections, then all191 profiles/10977 comparisons exact with1072 stable inputs, including coherent complete sound class headers. Only verified marker(s) removed; ownership released. | src/game/rendering/PVRTDecompress.cpp; _scratch/worker-pvrtc-decompress-current/ |

## Physics and trail follow-up selection

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x0031a6fd | PhysicAttributes::GetJumpHeight(vector3df const&,int), `_ZN16PhysicAttributes13GetJumpHeightERKN3irr4core8vector3dIfEEi` | � | BLOCKED | Coordinator reran audit.py0: all six historical images short and mismatched; current38/38 functions and11/11 regions exact, no new source cause or compile. Ownership released. | src/game/characters/PhysicAttributes.cpp; _scratch/worker-physics-jump-height-current/ |
| libsanangeles.so | 0x00348fb5 | TrailMgr::AllocTrailList(Trail**,int), `_ZN8TrailMgr14AllocTrailListEPP5Traili` | � | BLOCKED | Coordinator reran check-evidence.py exit0: actual152/native154B function/fullsection fail;19 frozen inputs stable, current relevant types unchanged, four prior forms. No new cause or compile; ownership released. | src/game/world/TrailMgr.cpp; _scratch/worker-trail-allocate-current/ |

| libsanangeles.so | 0x00353525 | SoundManager::SoundManager(), `_ZN12SoundManagerC1Ev` and same-address C2 alias | � | COMPLETED | 100%; coordinator independently rebuilt complete native function(s)/sections, then all191 profiles/10977 comparisons exact with1072 stable inputs, including coherent complete sound class headers. Only verified marker(s) removed; ownership released. | src/game/audio/SoundManager.cpp; _scratch/worker-sound-constructor-current/ |

| libsanangeles.so | 0x002fe999 | NPC::freeze(), `_ZN3NPC6freezeEv`, native224B | � | BLOCKED | Coordinator reran finalize.py0: sole complete-branch escalation reproduces same224B and three differences83/84/b8. All223/59 prior checks exact,886 inputs stable; no credit, ownership released. | src/game/ai/NPC.cpp; _scratch/worker-npc-freeze-complete-branch-current/ |

## Bounded reuse of demonstrated compiler/source patterns

The complete PVRTC source-unit context resolved a measured stack-slot permutation.
Ordinary constant-sized memset resolved the SoundManager constructor's row-store
sequence. The following distinct investigations may test those specific patterns;
they do not reopen arbitrary ordering or flag searches.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x00344821 | SaveGame::SampleAndSave(char const*), `_ZN8SaveGame13SampleAndSaveEPKc` | � | BLOCKED | Sole complete-unit context escalation still1388B/four differing bytes88..8b; coordinator reran finalize.py0, all476/757 previous checks exact,890 inputs stable. No credit; ownership released. | src/game/persistence/SaveGame.cpp; _scratch/worker-savegame-unit-context-current/ |
| libsanangeles.so | 0x003360c1 | Mission::Mission(), `_ZN7MissionC1Ev` and C2 alias | � | COMPLETED | 100%; coordinator reran audit0 and independently rebuilt both128B aliases/fullsection at native definition order, then191profiles/10980 comparisons exact with1072stableinputs. Only verified markers removed; ownership released. | src/game/missions/Mission.cpp; _scratch/worker-mission-zero-initialization-current/ |
| libsanangeles.so | 0x00333e41 | FPSCamera::scroll(touch list), `_ZN9FPSCamera6scrollERKSt4listIP7Point2DIsESaIS3_EE` | � | BLOCKED | Sole updated-canonical unit-context control remains280B/same14-byte miss. Coordinator reran final-audit.py0, genuine current header/dependency checks exact; accepted body texts preserved, no credit; ownership released. | src/game/core/FPSCamera.cpp; _scratch/worker-fps-scroll-unit-context-current/ |

## Next hourly batch: verified zero-initialization pattern investigations

These scopes use the demonstrated ordinary memset pattern only when native
array extent, writes and lifetime support it. No worker may broaden zeroing to
padding, neighboring fields or conditionally initialized storage. Recover prior
budgets before proposing one explicitly bounded trial; wait for coordinator
approval before compiling any exhausted target. Positive results after the PR755
cutoff remain private for the next hourly batch.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x002df655 | OctTreeAABB::OctTreeAABBNode constructor, `_ZN11OctTreeAABB15OctTreeAABBNodeC1ERiiPN3irr4core5arrayIPNS_8RootNodeENS3_12irrAllocatorIS6_EEEEjNS3_8aabbox3dIfEE` (retail C1 only; any emitted C2 alias receives no separate credit) | � | BLOCKED | Coordinator reran diagnostic proof and independently rebuilt final public patch: actual828/native832,611 common differences+4missing;147 old functions118 owner regions exact. Uncredited packet published in PR756; ownership released. | src/game/rendering/GS3DStuff.cpp; _scratch/worker-octree-child-initialization-current/ |
| libsanangeles.so | 0x003295a5 | MiniMap::MiniMap(ASprite*,int,int,int,int), `_ZN7MiniMapC1EP7ASpriteiiii` and C2 alias | � | BLOCKED | Coordinator reran audit0: single bounded memset form remains212B/same39-byte miss at68; all15/17 owner checks and14profile header gate exact,1072 inputs stable. No credit; ownership released. | src/game/hud/MiniMap.cpp; _scratch/worker-minimap-zero-initialization-current/ |
| libsanangeles.so | 0x00326581 | AnalogStick::AnalogStick(ASprite*,int,int), `_ZN11AnalogStickC1EP7ASpriteii` and C2 alias | � | BLOCKED | Coordinator reran audit0: six actual360B aliases retain147 differences beyond exact187B prefix. Native zero stores already exact; opaque storage does not establish original zero-array type or causal link. No new compile or credit; ownership released. | src/game/input/AnalogStick.cpp; _scratch/worker-analog-zero-initialization-current/ |

## Next source-family investigations

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x00352335 | RadioStationController::RadioStationController(), `_ZN22RadioStationControllerC1Ev` and C2 alias if present in catalogue | unassigned | BLOCKED | Coordinator reran best-policy and caller-accounting proofs exit0: corrected count-store order,608/native604 and helper40/native36. No link or credit; ownership released. | src/game/ai/RadioStationController.cpp; _scratch/worker-radio-construction-current/ |
| libsanangeles.so | 0x002f96e9 | CustomSkyBoxSceneNode::CustomSkyBoxSceneNode(ITexture*,ISceneNode*,int), `_ZN21CustomSkyBoxSceneNodeC1EPN3irr5video8ITextureEPNS0_5scene10ISceneNodeEi` | � | BLOCKED | Coordinator reran audit0: actual native Material140B/64instructions/zero calls agrees semantic model; old5040B target already invokes real imported constructor, so inline zeroing cannot explain56B overrun. No new compile/credit; ownership released. | src/game/rendering/CustomSkyBoxSceneNode.cpp; src/game/core/Material.h (read-only); _scratch/worker-skybox-material-initialization-current/ |

| libsanangeles.so | 0x0030c035 | Vehicle::step(), `_ZN7Vehicle4stepEv` | � | BLOCKED | Coordinator reran audit0: all six clamps/twelve native+actual branch sites agree tie/NaN operand selection. Candidate4336/native4372 unchanged; real96B PhysicInfo constructor exact. No new compile/cause/credit; ownership released. | src/game/vehicles/Vehicle.cpp; _scratch/worker-vehicle-step-clamp-current/ |

| libsanangeles.so | 0x0034eed9 and 0x0034ef15 | ResStream destructor family: `_ZN9ResStreamD0Ev` (60B), `_ZN9ResStreamD1Ev`/D2 (shared56B) | � | BLOCKED | Coordinator reran audit0: all five actual D0/60 and D1/D2/56 images same six-byte residual; exact current source context/native placement already tested. No new compile/cause/credit; ownership released. | src/game/world/ResStream.cpp; _scratch/worker-resstream-unit-context-current/ |

## Next independent source-evidence scopes

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x002d1de5 and 0x002d1de9 | GetNativeSoundRaw; GetNativeResourceSoundRawLength (2B each) | unassigned | BLOCKED | Coordinator reran audit exit0:228 pinned files,zero prototype hits,no justified ABI or compile. Both markers retained; ownership released. | src/game/app/jni_GLMediaPlayer.c; _scratch/worker-native-sound-prototypes-current/ |
| libsanangeles.so | 0x00352cad | SoundManager::getNumberOfPlayingSounds(), `_ZN12SoundManager24getNumberOfPlayingSoundsEv` | unassigned | BLOCKED | Coordinator reran relative-reuse audit0: one direct-index matched-relative trial produced identical whole object and same two-byte miss. Public packet published in PR757, no credit; ownership released. | src/game/audio/SoundManager.cpp; _scratch/worker-sound-count-unit-context-current/ |

| libsanangeles.so | 0x002e49ad | MenuManager::updateWidgetVisibility(), `_ZN11MenuManager22updateWidgetVisibilityEv`, existing104B match | unassigned | BLOCKED | Coordinator private initializer-order repair independently passes all affected35 profiles2274 functions2210 regions with count API. Canonical existing body unchanged; prerequisite remains unapplied with unmatched count packet. Ownership released. | src/game/ui/MenuManager.cpp; _scratch/coordinator-sound-count-menu-compat/ |


## Reactivated independent workers after PR 756

Runtime permits three workers alongside the coordinator. Each assignment is
exclusive. Recover historical budgets before compilation; exhausted targets need
a demonstrated source discrepancy and bounded coordinator approval. Use private
scratch mirrors only.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x0034b3c5 | StringManager::formatAmount(int,bool,bool) const | unassigned | BLOCKED | Coordinator reran semantic audit0:50304 modeled cases agree, genuine native signed behavior preserved. No new source discrepancy or compilation; ownership released. | src/game/persistence/StringManager.cpp; _scratch/worker-format-amount-semantics-current/ |
| libsanangeles.so | 0x00349d81 | ASprite::GetAnimDuration(int),native82B | unassigned | BLOCKED | Coordinator reran actual-object audit0:80/native82 and first difference+1e. All later helper/frontend variants recovered; no new source cause or compile. Ownership released. | src/game/rendering/ASprite.cpp; _scratch/worker-asprite-duration-current/ |

| libsanangeles.so | 0x002dcd29 | std::string::_M_append(const char*,const char*),native372B | unassigned | BLOCKED | Coordinator independently applied and rebuilt final public form3:372B,112 exact prefix,60 differences;147 old functions124 sections3 regions exact. No surplus helpers or credit; published unapplied packet, ownership released. | src/game/rendering/GS3DStuff.cpp; src/game/core/NativeAllocator.h (private prerequisites only); _scratch/worker-string-append-inline-current/ |

| libsanangeles.so | 0x00342b09 | WantedLevelManager::WantedLevelManager(),C1/C2 aliases,native184B | unassigned | BLOCKED | Coordinator reran actual-image proof0: recovered correct184B aliases retain16 differences from+28; all18 old functions22 regions exact. Invalid176B candidate rejected, no credit; ownership released. | src/game/missions/WantedLevelManager.cpp; _scratch/worker-wanted-constructor-correct-current/ |


## Complete SoundManager translation-unit context

The prior current-context control included accepted definitions plus one target,
not all four pending definitions. This wave recovers each exact preserved best
body separately; only the coordinator combines the shared file. No independent
new source forms or optimizer changes are authorized. One complete-source context
compile may proceed after genuine interfaces, layouts and per-function semantic
checks are reviewed. Strict native boundaries and every old match remain binding.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x00352a55 | SoundManager::endCutscene(),native236B | unassigned | BLOCKED | One complete-four-body native context reproduces historical misses: end236/6diff,count80/2diff,ready222/native224,update428/2diff. All73 old functions80 regions exact,1078 inputs stable; no source adoption or credit. Ownership released. | src/game/audio/SoundManager.cpp; _scratch/worker-sound-end-complete-unit/ |
| libsanangeles.so | 0x00353095 | SoundManager::_getReadySound(int),native224B | unassigned | BLOCKED | One complete-four-body native context reproduces historical misses: end236/6diff,count80/2diff,ready222/native224,update428/2diff. All73 old functions80 regions exact,1078 inputs stable; no source adoption or credit. Ownership released. | src/game/audio/SoundManager.cpp; src/game/audio/SoundManager.h (read-only); _scratch/worker-sound-ready-complete-unit/ |
| libsanangeles.so | 0x00353175 | SoundManager::update(double),native428B | unassigned | BLOCKED | One complete-four-body native context reproduces historical misses: end236/6diff,count80/2diff,ready222/native224,update428/2diff. All73 old functions80 regions exact,1078 inputs stable; no source adoption or credit. Ownership released. | src/game/audio/SoundManager.cpp; _scratch/worker-sound-update-complete-unit/ |
| libsanangeles.so | 0x00352cad | SoundManager::getNumberOfPlayingSounds(),native80B | unassigned | BLOCKED | One complete-four-body native context reproduces historical misses: end236/6diff,count80/2diff,ready222/native224,update428/2diff. All73 old functions80 regions exact,1078 inputs stable; no source adoption or credit. Ownership released. | src/game/audio/SoundManager.cpp; _scratch/coordinator-sound-complete-unit/ |

| libsanangeles.so | 0x002e49ad | Existing MenuManager::updateWidgetVisibility(),104B compatibility | unassigned | COMPLETED | Existing match preserved privately; full191 prerequisite profiles10980 checks exact. No canonical source integration or new credit; ownership released. | src/game/ui/MenuManager.cpp; _scratch/coordinator-sound-complete-unit/ |

| libsanangeles.so | 0x002e8fe9 | Existing Menus::ServiceMissions::GotFocus() compatibility | unassigned | COMPLETED | Existing match preserved privately; full191 prerequisite profiles10980 checks exact. No canonical source integration or new credit; ownership released. | src/game/ui/MenuState.cpp; _scratch/coordinator-sound-complete-unit/ |


## Next independent bounded investigations

The coordinator reviewed and accepted the three recovered SoundManager body
packages for private integration and now owns their combined context test.
Workers are released from those functions; no matching credit is implied.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x002dcd29 | std::string::_M_append(const char*,const char*),372B | unassigned | BLOCKED | Unmatched. Reviewed the original STLport header feasibility report. No compilation ran. The pinned header routing requires a native include path missing from the local NDK. Kept the fixture and provenance manifest for reference. | src/game/rendering/GS3DStuff.cpp; _scratch/worker-string-original-headers/FEASIBILITY.md |
| libsanangeles.so | 0x00342b09 | WantedLevelManager constructor,C1/C2,184B | unassigned | BLOCKED | Coordinator reran final audit0: one bool-chain trial184B/19diff, first+28, old18/22 exact and890 inputs stable. Integer form excluded, no credit; ownership released. | src/game/missions/WantedLevelManager.cpp; _scratch/worker-wanted-zero-chains/ |
| libsanangeles.so | 0x003511b9 | CSoundDecoderMSADPCM::Init(FILE*,RiffHeader*,FormatHeader*),134B | unassigned | BLOCKED | Coordinator reran audit0:63 native instructions, six actual forms, correct wire signedness/U8 truncation and identical current accepted context. No source defect, compile or credit; ownership released. | src/game/audio/CSoundDecoderMSADPCM.cpp; _scratch/worker-adpcm-init-native-fields/ |

| libsanangeles.so | 0x00352cad | SoundManager::getNumberOfPlayingSounds(),80B | unassigned | BLOCKED | Unmatched. The unsigned accumulator produces 78 of 80 native bytes, with the first mismatch at 0x4b. All 73 existing function and 80 region checks pass. The bounded trial is finished. | src/game/audio/SoundManager.cpp; _scratch/worker-sound-count-unsigned-total/REPORT.md |

| libsanangeles.so | 0x003365f1 | Mission::update(int),native536B | unassigned | BLOCKED | Unmatched. The replay reproduces the 524-byte historical candidate against 536 native bytes. The function and switch table differ. All 34 existing function and 27 region checks pass. The bounded replay is finished. | src/game/missions/Mission.cpp; _scratch/worker-mission-update-after-constructor/REPORT.md |

Coordinator recovery: prior worker handles are absent from the live agent inventory. The three scopes were reassigned without resetting their investigation budgets. The coordinator reviewed the results above and released ownership. Preserve all saved artifacts and check for completed work before any new compilation. Runtime supports three workers alongside the coordinator.


## Resumed evidence-driven investigations

The coordinator authorizes the following bounded scopes after reviewing the
prior negative results. Each scope has a different owner. The runtime permits
three workers alongside the coordinator. All candidate inputs stay private.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x00352cad | SoundManager::getNumberOfPlayingSounds(),80B | unassigned | BLOCKED | Coordinator reran audit0: unsigned-return control reproduces original80B/two-byte mismatch and identical whole object. All73 old functions80 regions exact. Bounded control finished; ownership released. | src/game/audio/SoundManager.cpp; _scratch/worker-sound-count-unsigned-return/ |
| libsanangeles.so | 0x002dcd29 | std::string::_M_append(const char*,const char*),372B | unassigned | BLOCKED | Original-header compile356/native372B and four surplus helpers; sizeof24 confirmed. Dependency policy read-only review found no allocator/copy mismatch. Scope reviewed and released; no credit. | _scratch/worker-string-original-headers/ |
| libsanangeles.so | 0x002ecb01 | Widgets::Help::SetIcon(const char*),32B | unassigned | BLOCKED | Reviewed Ghidra/native callee, argument and literal evidence; prior scheduling mismatch persists, no new compile or credit. Ownership released. | src/game/ui/MenuWidget.cpp; _scratch/worker-help-icon-ghidra/ |

| libsanangeles.so | 0x00352cad | SoundManager::getNumberOfPlayingSounds(),80B | unassigned | BLOCKED | Split-initialization control remains78/native80B,35 common differences plus2 missing, old73/80 exact. Reviewed bounded result, no credit; ownership released. | src/game/audio/SoundManager.cpp; _scratch/worker-sound-count-branch-initialization/ |


## Next Ghidra interface investigations

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x00349315 | FSelect(float,float,float),32B | unassigned | BLOCKED | Reviewed new caller float-return evidence and preserved IEEE behavior; old32B/two-byte mismatch unchanged. No justified compile; ownership released. | src/game/app/IPhone.cpp; _scratch/worker-fselect-ghidra/ |
| libsanangeles.so | 0x00349d81 | ASprite::GetAnimDuration(int),82B | unassigned | BLOCKED | Reviewed two signed-result caller constraints and prior80/native82B mismatch. No stronger alignment evidence or new source cause; no compile. Ownership released. | src/game/rendering/ASprite.cpp; _scratch/worker-asprite-duration-ghidra/ |

Original-header append compile reviewed:356/native372B and four unsupported helper identities; sizeof24 passes. Native allocator/copy/throw policy remains to be compared through Ghidra before further source or macro changes.

| libsanangeles.so | 0x002dcd29 | std::string::_M_append(const char*,const char*),372B | unassigned | BLOCKED | Reviewed negative control: removing noreturn emits348/native372B and fails strict extent. Earlier returning-edge inference was incorrect: native BLS bypasses the fatal call, whose path overwrites values required by normal continuation. Existing noreturn remains consistent with native CFG. Corrections and negative evidence preserved; ownership released. | src/game/rendering/GS3DStuff.cpp; _scratch/worker-string-throw-declaration/ |

| libsanangeles.so | 0x003365f1 | Mission::update(int),536B | unassigned | BLOCKED | Reviewed six-case switch audit and223 instruction-byte comparisons. Ghidra warning does not establish a missing native case; retained524/native536B candidate unchanged. No compilation or credit; ownership released. | src/game/missions/Mission.cpp; _scratch/worker-mission-update-ghidra-cfg/ |
| libsanangeles.so | 0x003398b5 | Script::unsetScriptObjectAction(LevelObject*,eScriptAction),136B | unassigned | BLOCKED | Reviewed native pointer-key lower-bound search, repeated operator[] calls and erase lifetime. No source discrepancy; retained128/native136B candidate unchanged. No compilation or credit; ownership released. | src/game/scripting/Script.cpp; _scratch/worker-script-unset-ghidra/ |


## Ghidra analysis prerequisites

The coordinator owns metadata changes in the shared Ghidra project. Workers
below perform read-only evidence collection before any prototype update.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x001c4154 and0x001c4328 | __aeabi_fadd/fsub analysis interfaces and native-proven caller continuations | unassigned | COMPLETED | Analysis prerequisite only, zero matching credit. Isolated ARMv5t soft-float storage and returning calls repaired; five corrected exports independently checked by coordinator against retail bytes. Original project preserved. Documentation committed as82d70438; metadata ownership released. | docs/GHIDRA.md; _scratch/ghidra-runtime-prototypes/; _scratch/corrected-ghidra-root-verification.json |


## Reactivated workers: independent native-interface investigations

Runtime permits three workers alongside the coordinator. Historical budgets
remain binding. Workers collect fresh Ghidra caller/control-flow evidence and
recover preserved candidates in private mirrors. Compilation of an exhausted
target requires a concrete new discrepancy and bounded coordinator approval.
No shared metadata edits, canonical source edits, Git operations, or delegation
are authorized. The coordinator retains integration and review ownership.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x0031a67d | PhysicAttributes::IsPositionOnJump(vector3df const&),128B | unassigned | BLOCKED | Repaired complete CFG independently byte-verified against original ELF; existing candidate semantics confirmed. No new source constraint or compile. Coordinator reviewed evidence and released ownership; no matching credit. | src/game/characters/PhysicAttributes.cpp; _scratch/worker-position-jump-ghidra/ |
| libsanangeles.so | 0x003f01d1 | MenuFX::GetStateHandler(gameswf::character*),142B | unassigned | BLOCKED | Repaired complete CFG independently byte-verified against original ELF; existing candidate semantics confirmed. No new source constraint or compile. Coordinator reviewed evidence and released ownership; no matching credit. | src/game/rendering/menufx.cpp; _scratch/worker-menufx-handler-ghidra/ |
| libsanangeles.so | 0x002fd565 | NPC::isOutsideSearchRadius(),172B | unassigned | BLOCKED | Repaired complete CFG independently byte-verified against original ELF; existing candidate semantics confirmed. No new source constraint or compile. Coordinator reviewed evidence and released ownership; no matching credit. | src/game/ai/NPC.cpp; _scratch/worker-npc-radius-ghidra/ |


## Next independent functions after corrected CFG review

Use the isolated ARMv5t MCP endpoint8083 with auto-analysis disabled. Preserve
historical attempt budgets; no new compile without a concrete new source cause
and bounded coordinator approval. All worker outputs remain private.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x00349445 | AnimObject::IsAnimOver(),112B | unassigned | BLOCKED | Coordinator reviewed complete native-byte-verified CFG and historical candidate comparisons. Existing semantics confirmed; no new source cause, compilation or matching credit. Ownership released. | src/game/characters/AnimObject.cpp; _scratch/worker-anim-over-corrected-ghidra/ |
| libsanangeles.so | 0x0033d271 | ScriptManager::reachRunningCommand(int),112B | unassigned | BLOCKED | Coordinator reviewed complete native-byte-verified CFG and historical candidate comparisons. Existing semantics confirmed; no new source cause, compilation or matching credit. Ownership released. | src/game/scripting/ScriptManager.cpp; _scratch/worker-running-command-corrected-ghidra/ |
| libsanangeles.so | 0x0034ccf1 | TouchScreenBase::touchBegan(Point2D<short> const&,long),140B | unassigned | BLOCKED | Coordinator reviewed complete native-byte-verified CFG and historical candidate comparisons. Existing semantics confirmed; no new source cause, compilation or matching credit. Ownership released. | src/game/input/TouchScreenBase.cpp; _scratch/worker-touch-began-corrected-ghidra/ |


## Next native call and loop constraints

The previous three scopes are reviewed and released. Historical attempt budgets
remain unchanged. Repaired ARMv5t MCP analysis is available on loopback8083.
Workers must report incomplete analysis to the coordinator and keep all evidence
in private scratch mirrors. No compilation without a concrete new source cause
and bounded approval; no shared metadata, canonical source or Git edits.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x0034228d | NPCController::onEvent(IEvent const*,EventManager const*),96B | unassigned | BLOCKED | Reviewed native CFG and historical candidates; no new semantic cause or compile. Application analysis still omits proven returning delete continuation; original assembly remains authoritative. Ownership released. | src/game/ai/NPCController.cpp; _scratch/worker-npc-event-corrected-ghidra/ |
| libsanangeles.so | 0x002d4015 | Application::UnRegisterForUpdate(IUpdatable*),48B | unassigned | BLOCKED | Reviewed native CFG and historical candidates; no new semantic cause or compile. Application analysis still omits proven returning delete continuation; original assembly remains authoritative. Ownership released. | src/game/app/Application.cpp; _scratch/worker-unregister-corrected-ghidra/ |
| libsanangeles.so | 0x00349271 | TrailMgr::Render(),56B | unassigned | BLOCKED | Reviewed native CFG and historical candidates; no new semantic cause or compile. Application analysis still omits proven returning delete continuation; original assembly remains authoritative. Ownership released. | src/game/world/TrailMgr.cpp; _scratch/worker-trail-render-corrected-ghidra/ |


## Bounded complete-source context controls

The PVRTC result demonstrated that complete translation-unit context can resolve
code generation. Each worker below recovers all preserved pending bodies in its
own original unit, without changing their algorithms or compiler flags. First
verify whether this exact complete context was already tested; do not repeat it.
One complete-context compile is authorized only after documenting input bodies,
interfaces and genuine source discrepancy from earlier partial-context controls.
Keep all candidate bodies private. Reject native extent overlaps; verify every
old match before any integration. This is not permission for new local variants.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x00326581,0x003268cc,0x003268e1 | AnalogStick constructor C1/C2, processTouch thunk, processTouch(long) | unassigned | BLOCKED | Coordinator reran audit0:873 frozen inputs stable, accepted bodies and parent unchanged. Sole complete context emits constructor356/native360, parent1028/native1016, thunk20. Strict prelink rejection; no owner link/credit. Ownership released. | src/game/input/AnalogStick.cpp; _scratch/worker-analog-complete-context/ |
| libsanangeles.so | 0x002d4015,0x002d5eb9 | Application::UnRegisterForUpdate and Application::OnEvent | unassigned | BLOCKED | Coordinator reran actual-object audit0: unregister46/native48, OnEvent596 with historical raw hash unchanged, old primary object payloads unchanged. One failed integration frontend then one authorized mechanical retry. Native extent rejection, no link or credit; ownership released. | src/game/app/Application.cpp; _scratch/worker-application-complete-context/ |
| libsanangeles.so | 0x00348fb5,0x00349271 | TrailMgr::AllocTrailList and TrailMgr::Render | unassigned | BLOCKED | Coordinator independently inspected both actual objects:152/native154 and48/native56, identical prior hashes. Sole complete context fails strict extents;14 prior raw payloads unchanged, no link/credit. Ownership released. | src/game/world/TrailMgr.cpp; _scratch/worker-trail-complete-context/ |


## Next complete-context feasibility investigations

Before any compile, establish that all required genuine candidate bodies and
compatible interfaces survive and that the combined unit was not tested before.
No reconstruction of missing bodies, source tuning, flag changes or speculative
layout changes is authorized. Report novelty and feasibility first. At most one
complete-context control may run after coordinator acceptance. All work is private.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x0034f555,0x0034f785,0x0034fbf9,0x00350019,0x0035047d | CarSounds::UpdateOffEngineSounds,UpdateOnEngineSounds,UpdateTurboSounds,AddTurboSounds,Init | unassigned | BLOCKED | AddTurboSounds accepted separately below after canonical exact function/section and191-profile10982-comparison gate. Other four remain unmatched; all-five context and bounded Turbo operand control reviewed, no further source form. Ownership released. | src/game/vehicles/CarSounds.cpp; _scratch/worker-carsounds-complete-context/ |
| libsanangeles.so | 0x003065e5,0x00306b11,0x00307101,0x00307451 | SpawnPoint::CreateAllSpawnInstances,Load,UpdateSpawnCenters,canSpawn | unassigned | BLOCKED | Coordinator reviewed sole complete-context objects and final evidence. No target improvement; strict extents reject linking, no matching credit. Mission semantic relocation identities independently rerun; Spawn canSpawn comparison limited to actual historical assembly, not undefined old object. Ownership released. | src/game/world/SpawnPoint.cpp; _scratch/worker-spawn-complete-context/ |

| libsanangeles.so | 0x00336345,0x003365f1 | Mission::message(int),Mission::update(int) | unassigned | BLOCKED | Coordinator reviewed sole complete-context objects and final evidence. No target improvement; strict extents reject linking, no matching credit. Mission semantic relocation identities independently rerun; Spawn canSpawn comparison limited to actual historical assembly, not undefined old object. Ownership released. | src/game/missions/Mission.cpp; _scratch/worker-mission-complete-context/ |


## Next paired-function context recovery

Prior Mission/Spawn controls are reviewed and released. The historical inactive
GameObjectManager owner is released after coordinator review of the parked
context result; no live worker owns those functions. New exclusive scopes:

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x00333e41,0x00334389 | FPSCamera::scroll(touch list),FPSCamera::updateTouchInputs() | unassigned | BLOCKED | Reviewed sole complete-context compile and same-object link: scroll280/same14-byte mismatch; touch364/native364 but316 differences. All28 old functions12 regions exact; no credit. Canonical allocator reused, no guessed weak specialization. Ownership released. | src/game/core/FPSCamera.cpp; _scratch/worker-fps-complete-context/ |
| libsanangeles.so | 0x00315f39,0x003160d9 | GameObjectManager::getDistanceFromAttackableTarget and getAttackableTarget | unassigned | BLOCKED | Reviewed actual prior combined object, canonical baseline identity and unchanged flags. Both saved mismatches reproduced; this context was already tested, so no compile repeated. Ownership released. | src/game/world/GameObjectManager.cpp; _scratch/worker-target-manager-complete-context/ |

| libsanangeles.so | 0x003511b9,0x003514b9 | CSoundDecoderMSADPCM::Init and Decode | unassigned | BLOCKED | Reviewed sole complete-context object: Init132/native134 and Decode656/native652, raw payloads and relocations identical historical definitions. Old22 raw functions unchanged; strict extent failures prevent linking, no credit. Ownership released. | src/game/audio/CSoundDecoderMSADPCM.cpp; _scratch/worker-adpcm-complete-context/ |


| libsanangeles.so | 0x0034fbf9 | CarSounds::UpdateTurboSounds() | unassigned | BLOCKED | Sole operand-order control emits identical entire object, independently verified by coordinator. Native508B extent,334 differences from0x76; old54 functions13 regions and Add464 exact. No second form; ownership released. | _scratch/worker-carsounds-turbo-operand/; src/game/vehicles/CarSounds.cpp (read-only canonical) |

| libsanangeles.so | 0x00350019 | CarSounds::AddTurboSounds(TurboSoundSettings*),464B | unassigned | COMPLETED | 100%; coordinator rebuilt canonical Add-only source and full native section exactly, then all191 ARM profiles10982 comparisons passed with1078 stable inputs. All4284 matched catalogue functions have direct successful comparisons. Only this verified marker removed; generated progress62.31%, Fully Linked20.39% unchanged. Ownership released. | src/game/vehicles/CarSounds.cpp; docs/matches/carsounds-add-turbo.md |


## Next family recovery after AddTurboSounds integration

AddTurboSounds is accepted; the other context results above are reviewed and
released. Recover genuine preserved bodies and compatible interfaces first.
Prove that the complete combined source context was not already tested. Do not
compile without coordinator acceptance. Historical budgets remain unchanged.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x0032cbe1,0x0032cfcd | Wheel constructor C1/C2 and processTouch(long) | unassigned | BLOCKED | Coordinator reran audit0:1061 frozen inputs stable; constructor256 and parent300 entirely identical historical linked bytes. Old20 functions12 regions and accepted20-byte thunk exact. One context only, no credit; ownership released. | src/game/vehicles/Wheel.cpp; _scratch/worker-wheel-complete-context/ |
| libsanangeles.so | 0x00332771,0x00332cf5 | CameraManager::update(float),getClickedTarget(line3df,bool)const | unassigned | BLOCKED | Coordinator reviewed final report and independently read actual object sizes/hashes. Sole complete context fails native extents; no target link or credit. Historical identity caveats retained, ownership released. | src/game/core/CameraManager.cpp; _scratch/worker-camera-manager-complete-context/ |
| libsanangeles.so | 0x0034b3c5,0x0034b5a5,0x0034b78d | StringManager::formatAmount,unloadPackSheet,loadPackSheet | unassigned | BLOCKED | Coordinator reviewed final report and independently read actual object sizes/hashes. Sole complete context fails native extents; no target link or credit. Historical identity caveats retained, ownership released. | src/game/persistence/StringManager.cpp; _scratch/worker-string-manager-complete-context/ |


## Next recovery after reviewed Wheel, CameraManager and StringManager controls

The previous scopes are reviewed and released. Historical inactive LevelObject
owners are released by the coordinator before reassignment. Preserve historical
budgets; first recover genuine bodies/interfaces and prove complete-context
novelty. No compilation without coordinator acceptance. No guessed source or
layout changes, canonical/shared edits, Git operations or delegation by workers.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x00354665,0x00354725 | EventManager::_attach(int,IEventReceiver*),_detach(int,IEventReceiver*) | unassigned | BLOCKED | Reviewed actual historical combined sources/logs: both pending methods and all current accepted method/storage declarations already tested together. No fresh compile; prior budgets preserved, ownership released. | src/game/scripting/EventManager.cpp; _scratch/worker-event-manager-complete-context/ |
| libsanangeles.so | 0x003351dd,0x00335849 | VehicleCamera::goToSide(bool),update(float) | unassigned | BLOCKED | Coordinator independently reran native comparisons: side304B/eight differences, update968B/415 differences; actual compiled getFacing220B exact. Old26 functions13 regions pass; one context, no new credit. Ownership released. | src/game/vehicles/VehicleCamera.cpp; _scratch/worker-vehicle-camera-complete-context/ |
| libsanangeles.so | 0x003179d5,0x00317fb5 | LevelObject::CastRay and canGoToPoint(vector3df const&,vector3df&,vector3df&) | unassigned | BLOCKED | Coordinator reviewed final report and actual object: ray1484/native1504, movement3120/native3120 both unchanged from historical payloads/relocations;65 old raw functions unchanged. No target link or credit; ownership released. | src/game/world/LevelObject.cpp; _scratch/worker-level-object-complete-context/ |

| libsanangeles.so | 0x00321721,0x003218d9,0x003219cd | SceneNodeManager::report,reclaimGarbage,drop | unassigned | BLOCKED | Coordinator reran audit0:873 frozen inputs stable, all three target raw payloads identical prior,29 old raw functions unchanged. Report392/native384 and drop208/native210 reject linking; reclaim244 unchanged mismatch. No credit; ownership released. | src/game/world/SceneNodeManager.cpp; _scratch/worker-scene-manager-complete-context/ |

| libsanangeles.so | 0x003485f1,0x00348735,0x00348cfd | Trail::Update(),BuildPoint(int,bool),CreateMeshSceneNode() | resume_mission | IN_PROGRESS | Mesh now500/native500 with only four initialization-order bytes different; same-object strict native link preserves both short actual methods, old16 functions6 regions and24B UV table exact. No credit. Read-only prior-loop/compiler evidence audit before any new source trial. | src/game/world/Trail.cpp; _scratch/worker-trail-unit-complete-context/ |
| libsanangeles.so | 0x002f7ce9,0x002f800d | CustomBillboardSceneNode::setColor and OnAnimate | unassigned | BLOCKED | Coordinator independently compared native image: Color232/65 differences, parent704/13 differences; accepted20B thunk exact. Old20 functions12 sections and GOT pass; complete context unchanged, ownership released. | src/game/rendering/CustomBillboardSceneNode.cpp; _scratch/worker-billboard-complete-context/ |

| libsanangeles.so | 0x0032b1f5,0x0032b665 | SlideControl constructor C1/C2 and processTouch(long) | unassigned | BLOCKED | Coordinator reran audit0:873 inputs stable, all target objects identical historical,18 old raw functions unchanged. Constructor500/native492 rejects linking; no second form or credit. Ownership released. | src/game/ui/SlideControl.cpp; _scratch/worker-slide-complete-context/ |


## Evidence-directed follow-up

Recent independent complete-context controls mostly emitted unchanged bytes.
Further escalation must identify a concrete called-definition, source/type or
compiler mechanism; an untried combination alone is insufficient. Preserve all
negative evidence and original per-function budgets.

| Binary/library | Function address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | --- | --- |
| libsanangeles.so | 0x002f84c9 | CustomSkyBoxSceneNode::setSkyColor(bool) | unassigned | BLOCKED | Retail BGRA/register passing verified; paired legacy-GCC probe changes lowering but cannot establish retail alignment. No type correction or game-header change accepted; review complete, ownership released. | src/game/rendering/CustomSkyBoxSceneNode.cpp; _scratch/worker-sky-color-abi-audit/ |
| libsanangeles.so | 0x002f7ce9 | CustomBillboardSceneNode::setColor(ISceneNode*,SColor) | resume_string | IN_PROGRESS | Unmatched; read-only prior-form and SColor alignment/call-ABI audit. Stock source is reference, not proof of retail packing. No compile authorized. | src/game/rendering/CustomBillboardSceneNode.cpp; _scratch/worker-billboard-color-abi-audit/ |


| libsanangeles.so | 0x00348cfd | Trail::CreateMeshSceneNode() | resume_mission | IN_PROGRESS | Sole archived declaration-order trial produced identical object and linked500B four-byte miss; old16 functions6 regions and UV table exact. No further source variant approved. One unchanged-source compiler-dump diagnostic authorized below. | _scratch/worker-trail-mesh-declaration-order/; src/game/world/Trail.cpp (read-only canonical) |


| libsanangeles.so | 0x002f84c9 | SColor ABI compiler probe supporting setSkyColor investigation | unassigned | BLOCKED | Retail BGRA/register passing verified; paired legacy-GCC probe changes lowering but cannot establish retail alignment. No type correction or game-header change accepted; review complete, ownership released. | _scratch/worker-sky-color-abi-audit/compiler-probe/ |


| libsanangeles.so | 0x00348cfd | Trail mesh compiler-pass diagnostic | resume_mission | IN_PROGRESS | One diagnostic-only compiler/as invocation on unchanged500B source with tree/RTL dumps; verify identical function bytes/semantic relocations before interpreting induction/preheader ordering. No new source trial. Prepare a portable unapplied candidate packet afterward for main-agent review. | _scratch/worker-trail-mesh-ivopts-audit/ |
| libsanangeles.so | 0x002f7ce9 | Billboard setColor class-alignment measurement | unassigned | BLOCKED | Rejected. Coordinator independently read actual object: target276/native232 and existing debug436/native424. Physical color/material sizes unchanged; no link, canonical type untouched. | _scratch/worker-billboard-class-alignment-measurement/ |
| libsanangeles.so | 0x002f800d | CustomBillboardSceneNode::OnAnimate(unsigned int) | unassigned | BLOCKED | Reviewed actual13-byte discrepancy audit: scratch registers and store/GOT-load order only; scalar/helper/call contracts agree existing source. No new correction or compile; ownership released. | _scratch/worker-billboard-animate-contract-audit/ |


The coordinator reproduced the portable mesh packet independently before
publication. It retains the exact four-byte mismatch and all16 accepted
functions, six support regions and UV table. No candidate was credited.

| libsanangeles.so | 0x00352cad | SoundManager::getNumberOfPlayingSounds() | resume_count | IN_PROGRESS | Read-only existing IR/address-provenance audit of native80B/two-byte discrepancy; recover prior diagnostics before proposing any new work. No source edit or compiler invocation authorized. | _scratch/worker-sound-count-address-provenance/; src/game/audio/SoundManager.cpp |
| libsanangeles.so | 0x002f7ce9 | Billboard setColor cached-channel type audit | resume_string | IN_PROGRESS | Read-only comparison of preserved local channel types and SDK getter contracts after rejecting class alignment. No type correction or new compile authorized. | _scratch/worker-billboard-channel-type-audit/ |


PR760 merged after both CI checks passed and conflict-free status was confirmed.
Its main artifact exactly equals the previous ByteMatch report; no progress added.

| libsanangeles.so | 0x00348cfd | Trail mesh derived-vertex control | resume_mission | IN_PROGRESS | One bounded private trial approved from SSA evidence: derive loop-local u16 vertex as2*(i-1) modulo65536, remove only dead outer induction/update. Preserve all stored values, other expressions, types, flags, imports and accepted methods. No second form. | _scratch/worker-trail-mesh-derived-vertex/ |
| libsanangeles.so | 0x002f7ce9 | Billboard cached-channel width measurement | resume_string | IN_PROGRESS | One private measurement approved: widen only four cached channel locals uchar-to-unsigned-int; input values remain0..255, class layout/constructor/body operations/order unchanged. No recovered retail-type claim or second form. | _scratch/worker-billboard-channel-width-measurement/ |

| libsanangeles.so | 0x00352cad | SoundManager count single VRP configuration probe | resume_count | IN_PROGRESS | One genuinely untested whole-TU -fno-tree-vrp probe approved from documented VRP2 commutation. Keep verified80B-source context and every other flag/body/header fixed; require strict target and all73 functions80 regions under the same primary-unit flag. Any regression rejects policy; no flag matrix. | _scratch/worker-sound-count-no-vrp/ |

Coordinator bounded escalation: ComputeShortestPath320ca1 is assigned solely to resume_count for ONE source-only native-array identity control on the corrected1672-byte baseline. Replace only the two local derived PathArray objects with genuine irr::core::array<AStarNode> objects, initialized through the same six observed field assignments in the same closed-then-open order. Keep the original-terminal correction, member path type, all other source/headers/flags/imports/linker unchanged. This tests nominal local/base-pointer representation using the confirmed native helper type; it does not reset prior budgets or authorize another form. Exact extent and preservation gates remain mandatory.

The sole shortest-path primary-array control is an identical-output negative: entire object matches the corrected1672-byte baseline exactly, including all41 old definitions. No type-identity cause or extra source form is claimed. Resume_count remains the sole owner for a read-only instruction/padding/literal-pool census of that actual artifact; no additional compiler invocation is authorized.

Coordinator authorized ONE unchanged-source compiler-dump diagnostic for the corrected1672-byte ComputeShortestPath artifact. Both retail and candidate have1620 real instruction bytes and48 literal bytes; the candidate has4 additional alignment bytes. Resume_count must prove entire object identity before interpreting tree/RTL reload/block/minipool diagnostics. No source or optimization changes, no link, and no further source trial authorized.

Coordinator approved one bounded shortest-path cleanup-factoring control after observing six actual operator-delete call sites in137lreg/138greg versus four after146rnreg and in retail. Resume_count must first map those sites, then test a positive valid-info body guard with one common final open/closed cleanup. Constructors, epoch update, valid-path operations, invalid-path cleanup order and original-terminal predicate stay unchanged. Use the already byte-identical diagnostic command configuration; no new optimization flags, header/type changes, output edits or second source form. Strict1668 extent and all41 old-payload gates remain mandatory. This tests pre-allocation CFG structure and does not assert retail IR is known.

Evidence-directed NPC::freeze escalation (sole owner resume_mission): coordinator independently compared actual native-address v2/v4/v5 ELFs. V2 differs ONLY at first-voice bytes71/72/be and has an exact second voice branch; V4/V5 differ ONLY at second-voice bytes83/84/b8 and have an exact first branch. Approve ONE source-only reuse control combining V4 first-voice spelling with V2 second-voice spelling, on the current complete-branch fixture: case0 default88 then !driver86; case1 default76 then !driver73. All other source, headers, flags, imports and linker remain fixed. No hints or second form. Require exact224 function/fullsection, native bytes and full available owner/dependency preservation before review. No credit until coordinator verifies.

Coordinator authorizes one CarRental Notify typed-plus-v4 source control, sole owner resume_string at Thumb0x002eb761/native448B. Keep the proven typed body and prerequisite context; replace only the availability/flags/suffix graph with the archived v4 readable bool and ternary spelling. The old typed confirmation tail and v4 index/table fragments are independently exact, but do not establish a complete matching loop. This is a bounded compiler-lowering hypothesis, not a match claim. Preserve exact compiler flags, all other source/types/imports/placements, strict native extent and every available old owner/dependency/GOT/suffix check. Compare the actual old typed object first, record precise source provenance, preserve all artifacts, and stop after this one form. No other control or canonical integration is authorized.

Coordinator authorizes ONE source-only NPC::Update correction at Thumb0x002ffe0d/native3012B, sole owner resume_mission. Native and actual corrected3024 object prove the current source skips the common fresh isDown check on alive/un-authored and nonterminal dead/fade paths. Replace only the authored/dead grouping with `if (!unknown28 && isDead() && isDown()) { existing fade verbatim }` followed by the existing common `if (isDown()) { UpdateSceneNode(); if (lastHitVehicle) unknown448=0; return; }`. Preserve the earlier category5 correction, all callbacks, other source/headers/flags and historical baseline context. Freeze inputs and retain the actual3024 baseline separately; compare old raw definitions and semantic relocations. Require strict3012 target/section extent before linking. Any genuine helper placement problem is reported separately, not bypassed or silently rerouted. No second source form, matching credit or canonical integration without coordinator review.

Coordinator authorizes ONE source-only Vehicle::_processAIFlags precedence correction at Thumb0x00312081/native3220B, sole owner resume_count. Independent native and actual3060 ELF proofs show retail selects valid pursuit before waiting, while every archived source selects waiting first. Re-nest only the unchanged bodies as inline original pursuit predicate first, original wait condition/body second, ordinary destination body last. Preserve null-target fallback, pre-dispatch target validation, steering construction/tail and all callback rereads, particularly elapsed/duration and flag reads after Stop. No predicate/field caching, header/constructor/flag/import/linker changes or second form. Freeze the proven safe3060 baseline and inputs; compare every available old raw definition/semantic relocation and require exact3220 target/section extent before linking. Preserve unmatched evidence and report skipped native/owner gates honestly. No matching credit or canonical integration without coordinator review.

Coordinator authorizes ONE source-only NPC::attackTarget guard-association correction at Thumb0x002ff5d1/native2108B, sole owner resume_mission. Verified native successful character-to-vehicle retarget ends2ffc3e with a direct branch to geometry2ff6f4, bypassing empty-driver validation2ff6ee/2ff992. Actual2084 candidate instead reloads the new target and performs that validation. Change only the following independent empty-vehicle `if` to `else if` attached to the full preceding character/player-in-vehicle condition. Preserve all guards, false-condition fallback, callback rereads, earlier animation correction, source context, headers, flags, imports and placements. Freeze actual2084 baseline separately; compare old raw functions/semantic relocations and require exact2108 function/section before native linking. One form only, no speculative alternatives, credit or canonical integration.

Coordinator authorizes ONE source-only RenderFX::UpdateCursor release-reference guard correction at Thumb0x003ef511/native2012B, sole owner resume_string. Native3efca8 directly joins fifth-clear after synthetic Event2 when both animations fail; fourth-reference assignment3efcba occurs only if either animation succeeds. All six archived sources assign fourth unconditionally after optional click. Make only that assignment the else arm of the existing `if (!animated)` click block. Keep the retained focus, animation results, event construction/callback order, fifth-clear and every other statement/type/flag unchanged. Use one actually paired preserved baseline source/object/profile, disclose its real1996-or2000 extent rather than claiming an absent best artifact, freeze inputs and compare old raw definitions/semantic relocations. Require exact2012 function/section before native linking. One form, no hint/helper/type/flag/context grid or credit without full review.

Coordinator authorizes ONE additional source-only Vehicle::_processAIFlags correction for a newly proven independent defect, sole owner resume_count at Thumb0x00312081/native3220B. Use the preserved3040 pursuit-first baseline unchanged except final displacement construction. Native3121c8/1ce/1d4 snapshots adjustedDestination fields260/264/268 before virtual GetPosition3121de; both old3060 and corrected3040 instead read destination248/252/256 after that callback. Immediately after the existing side calculation, capture `const vector3df adjustedSnapshot = adjustedDestination;` and form the existing displacement from that snapshot minus GetPosition(). Preserve all later arithmetic/callbacks and the accepted pursuit-first correction; no other type/flag/header/import/linker or source changes. Freeze actual3040 baseline separately, compare old raw/semantic payloads and require exact3220 function/section before native linking. One new-evidence control only, not a reset or speculative member/cache matrix.

Coordinator authorizes ONE source-only PlayerTest::Update guard-association correction at Thumb0x00304ec9/native2228B, sole owner resume_mission. Native updateCarInteraction3054b2 returns via3054b6 directly to scene visibility30536c, skipping byte376 test/finishedStopDriving; actual weak2200 candidate rejoins the independent byte376 test. Change only the immediately following `if (!vehicleVisibleInCinematic)` to `else if` attached to `if (unknown372)`. Preserve the preceding cancellation, null/false fallback, callbacks, weak prerequisite context, every other body/header/flag/import and all old limitations. Freeze actual2200 baseline separately and compare old payloads/semantic relocations; require exact2228 function/section before linking. No second form, fixture-context grid or matching credit without full coordinator review.

Coordinator authorizes ONE source-only Vehicle::Update damage-region correction at Thumb0x00313b01/native4020B, sole owner resume_count. Native double constants and real PLT identities prove both health-ratio comparisons are strict `< 0.3`, not `>= 1.2`. Native material-node/flag420 guard is a common post-damage join after both dead/light and nondead paths, still inside non-death-water; current4036 source incorrectly nests it only in nondead else. Change those two comparisons with double0.3 and move only that existing guard to its verified common level. Preserve original positivity test, separate fresh ratio after callbacks, all inner bodies/evaluation order, prior lifetime/traction fixes and all headers/flags. Freeze actual4036 baseline; compare all old raw/semantic payloads. Compile/as one form only and stop for coordinator review before native linking regardless of extent, because the historical fixture mislabeled dcmpge as1c4244. Correct retail identities are dcmplt1c4244 and dcmpge1c4448; canonical linker files already use correct identities. No silent binding substitution, padding or credit.

Vehicle Update damage control reviewed as unmatched: actual3924 function/3928 inputsection versus native4020, no native linker ran. Coordinator independently verified199 unchanged old raw definitions,1065 stable inputs and two genuine dcmplt relocations. Resume_count remains sole owner for a read-only native-versus3924 code/pool/padding/call census, including separate classification of the4 extra inputsection bytes. No new compiler/source/flag/binding experiment is authorized. Preserve the corrected damage semantics and original private binding error as explicit evidence.

Coordinator authorizes ONE unchanged-source Vehicle Update compiler/assembler diagnostic on the corrected3924 candidate, sole owner resume_count. The native/candidate share all191 direct external calls but candidate merges two native glass setVisible sites and differs in internal branch layout. Add only established tree/RTL dump options, not optimization policy flags. Before interpreting any pass, prove the3924 target raw bytes, all199 old raw definitions, imports, allocated payloads and semantic relocations unchanged; disclose narrow generated anonymous-name pairs rather than claiming raw labels identical. Locate the first actual pass that shares the two glass callbacks and how native48/candidate25 long internal branches arise from the emitted CFG/layout. No source form, crossjumping flag probe, output edit, linker run or further experiment is authorized. Preserve the best corrected source and strict extent limitation.

Coordinator authorizes ONE whole-primary-TU `-fno-crossjumping` probe on unchanged corrected3924 Vehicle Update, sole owner resume_count. The unchanged-output diagnostic proves first merging of native separate glass visibility sites occurs at actual143csa CFG cleanup, before147bbro layout; it does not prove retail used this flag. Append only that flag to the real baseline primary compiler arguments, keep dependency/harness policies, source, headers and all other flags fixed. Compare target extent and all199 old raw definitions/semantic relocations/imports/allocated payloads; any old regression rejects flag adoption. Do not link even an exact extent until coordinator reviews the known private helper-binding error. One policy control only, no flag matrix, source retune or credit without complete native and current preservation gates.

Coordinator authorizes ONE source-only PlayerTest::Update virtual-call correction on the preserved2216 car-interaction-else baseline, sole owner resume_mission. Original ISceneNode vtable addresspoint49084c proves slot208 targets updateAbsolutePosition(bool) at273141, while slot228 targets setCameraOffset(float) at272abd. Native3053e6 uses208/R1=0; actual2216 uses228 from the wrong source call. Replace only `sceneNode->setCameraOffset(0.0f)` with `sceneNode->updateAbsolutePosition(false)`. No header, layout, other body, flag or prerequisite change. Freeze actual2216 baseline, preserve old raw/semantic payloads and require exact2228 function/section before native linking. One form only; preserve all old weak-context and constructor limitations.

Next exclusive read-only/diagnostic phases after reviewed results: resume_count retains Vehicle::Update0x00313b01 to compare native receiver/argument snapshots around the two glass visibility sites with the actual default3924 shared tail; the global no-crossjumping policy is rejected and may not be adopted or retuned. Resume_mission retains PlayerTest::Update0x00304ec9 for ONE unchanged-source tree/RTL compiler/as diagnostic on the scene-corrected2216 artifact, requiring raw0e2166e600fa184f50e23ad25596465efe98236c9981e4647cb26ffdb8a56b23 and all84 old raw/semantic payloads unchanged before tracing missing intermediate IEvent-vtable stores or duplicated die calls. No optimizer-policy/source experiment. Resume_string retains OptionGameSettings::Notify0x002eac65 for a read-only native1056-versus1048 structural census of code/literals/padding/calls/frame after the accepted negative join audit; no compilation. All historical budgets and strict matching gates remain.

Coordinator authorizes ONE source-only PlayerTest::Update single-dispatch control on latest scene-corrected2216, sole owner resume_mission. Actual frontend has two authored die calls; native captures slot168 before optional getVehicle, then forms a bool and dispatches once. Replace only the existing if/else die(false)/die(true) pair with one `character->die(!(((flags240 & 0x400u) && static_cast<SavePositionInterface*>(this)->getVehicle()) || updateState.hitFlag));`. Preserve the predicate short-circuit, full surrounding body, two accepted corrections, headers, flags and prerequisites. Compiler ordering is measured, not assumed from C++ guarantees. Freeze2216 baseline and preserve old payloads; strict2228 function/section before linking. No DSE flag, constructor repetition, precomputed bool alternative or second form authorized.

Latest Player single-dispatch source control emits2204/native2228, preserving84 old raw definitions and945 inputs; source shape and early virtual-callee capture are verified but no native link ran. Coordinator review of actual object is pending before accepting/releasing that result. No DSE flag or constructor experiment is authorized. Root separately ruled out an8-byte section-phase explanation for the old1100-byte setText object: actual inputsection1100, alignment4, no new compile justified.

Player single-dispatch2204 result reviewed as unmatched: coordinator independently extracted actual target/section/raw2a9cdc033c56ebc6da33b53343cafa7eafa01599d3b28cd9cbf69c5bb9b117b8 and all84 unchanged old raw definitions/945 stable inputs. Resume_mission retains sole ownership for a read-only comparison of original IEvent(int19) construction ordering with the actual default-base/late-ID model and prior rejected constructor proposals, using existing matched IEvent/Event source as reference. Identify genuinely new reusable source/type facts or precisely separate known model-order and optimizer effects; do not replay any constructor, flag, volatile/barrier or layout experiment. Preserve latest2204 source and all no-link limitations.

Coordinator persisted bounded analysis repairs for Vehicle::step (50 to4214 owned code bytes,11 proven internal BL overrides,14 actual false returning-helper overrides) and Script::executeCommand (4122 to12106 code bytes,387 proven internal BL overrides,12 actual false returning-helper overrides). Both complete original memory hashes equal retail. Script first rolled back on protected automatic caseD_4 at349cda, then on a DEFAULT four-byte fsub call-thunk boundary at34a176; narrowly verified source/name/instruction/body predicates resolved these metadata-only boundaries without changing calls or memory. Resume_count and resume_string retain their respective functions for independent byte/width/ownership, padding and ABI readback before new source conclusions. All native external calls are preserved; no source compile or matching credit from these metadata changes.

Coordinator persisted exact computed-switch metadata for Script execute at339cf6 (118 signed table entries/95 unique targets from42e848) and Player car interaction at30409a (17 entries/12 targets from41e2fc), using the verified Ghidra12 JumpTable API. Both complete function and table memories equal retail before/after; bodies remain12106 and1624 bytes. Script now decompiles96773 characters and car12422 rather than switch-as-call stubs. Resume_string and resume_mission retain those respective functions for independent switch/ABI/byte readback and narrow new source-join review. This metadata grants no matching credit.

Coordinator reactivation 2026-11-22 14:32 UTC: existing exclusive ownership remains unchanged. resume_string is authorized ONE source-only Script executeCommand wanted-bound predicate correction in cases64/105, using the reviewed combined violation condition and minimum-priority message selector. Preserve all other source, headers, compiler settings and prior corrections; require exact function/full-section extents before linking, preserve prior raw/semantic definitions, and report skipped gates honestly. No second form is authorized. resume_count retains Vehicle::CreateWheels for a read-only, exact-byte bounded Ghidra returning-helper/physical-ABI repair proposal; no project writes, compile or BL overrides. resume_mission retains PlayerTest::updateCarInteraction for recovery of its actual1684 candidate input closure and comparison with current canonical prerequisites, identifying precise obsolete inputs and a minimal replay plan only; no compile, canonical edits or metadata writes. All workers report results for coordinator review and may not commit, push, create PRs or spawn agents.

Coordinator accepts the car-interaction closure audit and authorizes ONE compatibility-only current-context replay for resume_mission, same exclusive30406d. Preserve current accepted TU prefix and all headers/layouts/profiles; append recovered v6 with only two address-preserving Player148 Character::unknown144 views, necessary GS3D include, and nonvirtual declaration. Freeze authentic current baseline. Require function/inputsection1684 and switch68 plus all old raw/semantic payload preservation before any LD. Retain current owner84/26 and all four dependency selectors/flags. Only genuinely undefined original Thumb imports may be added; never rebind compiled setAnim or getSpecificAnimation. Strict native target/table placements and exact authoritative comparisons, no output edits or retry. Private scope only, no commits/push/PR/metadata writes or matching credit until coordinator review.

Script wanted control reviewed: actual12396 function/12400 inputsection versus native12636,35 other raw definitions and842 inputs independently stable. No native link or matching credit. Preserve corrected selector as preferred semantic candidate. resume_string retains executeCommand for read-only targeted original/actual predicate/common-join and callback snapshot audit of cases30..63 only, excluding already settled repeated constructor/global/opcode forms; recover prior ledger and do not repeat negative proofs. No compiler/source/metadata writes. Root accepts wheels repair proposal for bounded offline execution with zero BL overrides and full1408 memory guards; resume_count retains ownership pending fresh independent readback.

Car current-context primary passes strict1684/68 extents and preservation but dependency launch failed WinError2 before compiler invocation because the private runner resolved relative toolchain inside scratch. Authorize one mechanical same-object continuation only: resolve each unchanged manifest toolchain path against actual BASE/toolchain, retain every per-profile flag/toolchain identity and frozen source/config hash. Preserve existing primary object hash, no primary recompile. Run current dependencies then strict native owner/target/table checks; do not modify canonical builder or relax gates. This repairs runner setup, not a new source form or match claim.

Root reviewed Character switchMoveAnimation complete548-instruction/1154B readback and206 signed relative switch entries at41c22c/23targets. Authorize metadata-only guarded JumpTable at native2f663e, with physical boolR0/selfR0 and unchanged fullfunction/table retail memory; no source compile or matching credit. resume_count retains exclusive ownership for independent postrepair readback.

Coordinator accepts reviewed Script case37 native saved-flags constraint and authorizes ONE source-only control on latest wanted-correct12396. Preserve initial flags store, exactly one lrand48 call and existing aiTarget tail; introduce only explicit savedFlags value across that call. All other inputs/flags/types/layouts unchanged. Strict native12636 function/fullsection before LD, preserve35 other definitions/imports/allocated payloads/842 inputs. No second form, compiler-policy change or claimed vehicle-mutating PRNG behavior.

Script savedFlags control reviewed: actual12396/12400 native12636 remainsunmatched, raw0ced24317462d66a332f5d41dd3c70f5d9232c76cc3ca1dbc05c6eb6a85afee9,35 old raw and842 inputs independently stable. Preserve wanted and savedvalue corrections. resume_string retains executeCommand for READ-ONLY previously unproved cases65..100, excluding already settled case87/known global, constructor and opcode forms. Focus concrete original/actual predicate association, snapshots and cleanup; no compile or metadata writes without new review.

Root reviewed complete Character combat505-instruction1050B and Player switchAnim491-instruction1028B readbacks, plus signed computed tables125/26 and213/12. Authorize metadata-only guarded jump tables at native2f51b4 and303c1a with boolself and voidself physical signatures respectively. Entire function/table memory must remainretail; no source matching credit. Owners retain functions for independent fresh normalizedcase readback.

Root reviews Player switchAnim two concrete native/actual operand errors. Authorize resume_mission ONE source-only driver-eject first-bool correction on authentic1088 baseline: setAnimation(id,1.0f,false,true,false), changing no other call or readyguard. Freeze original paired context and preserve all old definitions/raw/semantic/import/allocatedpayloads/inputs. Require exact1072 function/fullsection before any native link; stop failedgate and report oldGOM/currentclosure limits honestly. Second targetLocked354 correction is reviewed evidence but NOT authorized until firstcontrol reviewed. No flag/header/layout or constructor changes.

Root reviews combat shared-ready proof and explicit prior-negative erratum. Authorize resume_count ONE source-only correction on exactv4 fixture: after case54/58/63/71/80/96 existing setAnimation append exactcase66 conditional ready-and-clear, preserving freshpost-setAnimation and post-ready flag reads. Nootherbody/header/layout/flag/import change. Freezepaired1100baseline; strict1108function/inputsection beforeLD and preserveoldraw/semantic/import/allocatedpayloads/frozeninputs. Stopafterfailedgate; nativeextent alone notmatch/currentclosure. No secondform or renamedbudget.

Combat control provenance amendment: direct historical command/profile missing; two adjacent frozen snapshots corroborate14legacyflags without fno-short-enums, not exactrunproof. Root selects ONE explicit14flag reconstruction with archivedheaders/prefix and restoredv4suffix, comparing actualsurvivingv5object (v4/v5wholeELFidentical). Document inferredconfiguration and source-restoration limits, freezeexactselectedflags beforecompile; all oldraw/semantic/allocated/import gates remain mandatory. No baselinecompile, current15flag trial, secondvariant or historicalcontextclaim.

Player eject-only1088 control reviewed: native R3false emitted,79 otherraw/485inputs independentlystable, noLD/credit. Authorize resume_mission ONE separate source-only high-animation readyguard correction on that latestbody: combatMode||targetLocked (byte354), replacing only lockRequested353 there. Preserve freshpostanimation reads, ejectcorrection, othercases54/58/63/96, allheaders/flags/context. Strict1072function/inputsection beforeLD; preserveoldraw/semantic/import/allocatedpayloads/frozeninputs. Stopfailedgate, no secondform; report oldclosurelimits.

Combat shared-ready correction reviewed as unmatched1100/native1108, noLD; preserve nativecommon-tail behavior. resume_count retains function for read-only native/correctedactual structural and call-argument census: realcode/literals/padding/frame, directcallee multiset, virtualslots/physicalboolarguments and firstmeaningful unmatchedgroup. Reusecompletedjoinproofs; no compiler or speculative source/flag controls.

Root reviewed two case86 native/candidate discrepancies. Authorize resume_string ONE source-only initialization correction on latestwanted+savedFlags12396: remove ONLY drifting and wanted-accumulator zero assignments, retain Speed/Jumping resets and allcalls/scoring/else association. Freezeexactbaseline and preserve35otherdefs/imports/allocatedpayloads/842inputs; strictnativefunction12636 beforeLD. Second vehicle-else correction remainsunapplied until thiscontrolreviewed. No secondform/types/flags/context change.

Player targetLocked correction reviewed independently:1084/native1072,79oldraw/485inputs stable, noLD/credit. resume_mission retains switchAnim for READ-ONLY native1072 vs corrected1084 structural/call-argument census, separating code/literals/padding/frame, directcallee multisets, virtualslots/physicalboolargs perpath and firstmeaningful residualgroup. Reusejoinproofs; no source/flag/compiler controls.

Script INIT-only result reviewed12372/native12636,35oldraw/842inputs stable, noLD/credit. Authorize resume_string ONE separate case86 else-association source correction on that latestbody: outerfirstvehicleequality; immediatefalse return on secondvehicleinequality; originalscoringbody unchanged; reminderelse attachedonlytoouterfirstcomparison. Preservebothgettercalls, allwanted/savedflags/two-reset corrections and allothercontext. Strictnativefunction12636 beforeLD, preserveoldraw/semantic/import/allocated/frozeninputs. No secondvariant or combinedunreviewedchange.

Root accepts punch776 fullnative byte proof and boundedreturn repair prerequisite. Authorize metadata-only clearing actualfalseCALL_RETURN atprogram30738c/faddccf6e2ee, exactThumbdecodewithin345entrywhitelist, boolselfR0, full776retailmemoryguard. No BLbranch overrides, speculativecallee changes, sourcecompile or matchingcredit. resume_count retainsfunction for freshindependentpostrepairreadback.

Script second-vehicle guard control reviewed:12352function/section versusnative12636,35oldraw/842inputs independentlystable, noLD/credit. resume_string retains executeCommand READ-ONLY previously unproved cases101..117 excludingalreadysettled105/116 and allconstructor/global/opcode forms. Inspect exactnative/actual predicates, snapshots, fieldwidths and commoncleanup. No compiler/source/metadatawrites without new reviewed evidence.

Coordinator bounded compiler escalation for Player switchAnim: original six forms all use builtinmemcpy; new exact census localizes8 excessbytes to materialized copyaddresses versus nativeindexed32bitload/store. Authorize ONE raw32transport expression control on latesteject+targetLocked1084, replacing only Player148 builtinmemcpy with unsigned32 lvalue load/store at the SAME proven4bytealignedaddresses under unchanged fno-strict-aliasing. This is storage representation, NOT discovery of destinationsemantic type. Preservebytes, nofloatconversion/layout/header/API/otherjoin changes. Freeze1084baseline and79oldraw/485inputs; strict1072function/inputsection beforeLD, exactextentSTOPforrootreview. No secondform or genericcastmatrix.

Root accepts punched400-instruction844B/full884retail proof and55signedtableentries/6targets. Authorize metadata-only guardedJumpTable atnative2f6ca2, voidselfR0/animationR1/damageR2/attackerR3explicitABI, unchangedfullfunction/tablememory. No sourcecompile/credit; resume_count retains independentreadbackscope.

Player raw-word control independently reviewed1076/native1072, localcopy8bytes equalsretail,79oldraw/485inputs stable. Authorize ONE separate native-common-state3 join control on latest1076: case22/23 driverpresent sets12+break, driverabsent falls through existing26/28 sharedstate3+break. PreserveoneexistinggetDriver acquisition and allotherstate/call/source/context/flags. Confirm this exactform absentpriorledger beforecompile; freeze1076, oldpreservationgates, strict1072function/inputsection. IfexactSTOPforrootreview beforeLD; no secondform or inventedtypes.
Script case101 FindingA reviewed: authorize resume_string ONE source-only pointerpredicate correction on12352, replacingONLYtwooriginalsceneNode16references by existingunknown20 in null/visibilitytest. Preserveallbodies/othergettercounts/typesnapshots/previouscorrections/context. Strict12636function beforeLD andoldpreservationgates; otherthreefindingsremainunapplied.

Player state3 control independently reviewed1076/native1072, localsharedjoin achieved,79oldraw/485inputs stable. resume_mission retainsREADONLY final preferred1076 native/candidate census, updating residualrealcode/padding/literals/branches aftercommonjoin; no source/flag/compiler trial without newreview. Script node20 control independently reviewed12352native12636,35oldraw/842inputs stable, targetdiffonebyte. Authorize resume_string ONE separate INITIALhighlightvehicle-cache correction only: captureactor.getVehicle once, nulltestcachedcar thenuseSAMEcar forshowHighlight0 andsetActionFlag2. Preserveprecedingoriginalhighlight/allouterguards/commonminimap andallothergetter/typeacquisitions. Freeze12352field-correctbaseline andalloldpreservationgates, strict12636function beforeLD. Cleanupcache/typeguardremainunapplied.
Root acceptsupdateAnimation892whitelist/zeroBL evidence; authorize metadata-only actualfadd3034caCALL_RETURNclear andboundedThumbdecode, boolselfR0/elapsedfloatR1, full892retailmemoryguard; no sourcecompile/credit. Ownerretainsfreshreadbackscope.

updateAnimation initialmetadatarepairrolledback on unowned303572 aftersecondrealreturningfadd30356e. Narrowamendment permits clearingONLYactualCALL_RETURN on independentlyverifiednormal__aeabi floatmathcalls withinSAME384entrynativewhitelist; requirecalleeactualnotnoreturn, unchanged892memory, no globalcallee edits/BLbranch overrides. Alltransactionvalidationremains; no source attempt or matchingcredit.

Script initialcache control independentlyreviewed12340/12344/native12636,35oldraw/842inputs stable, noLD. AuthorizeONE separate CLEANUP cache correction forresume_string onlatestbody: originaltype5 test thenoneVehicle*const getter,nullguard,samecar showHighlight-1/unsetFlag2. Preserveoriginalhighlightremoval beforeblock andallcommontail after, allothergetters/eagertypesnapshot/priorcorrections/context. Strict12636function andoldpreservationgates; no secondform.

Script cleanupcache independentlyreviewed12320/native12636,35oldraw/842inputs stable, noLD/credit. AuthorizeONE separate case101 typeacquisitionguard control onlatestbody: targetisEnabled outerif, ONLYinside true acquiretype andretainexistingtype5/type3deathguard, !(distance>=minimum), skipshortcircuit andfalse-return. Preserveallcleanup outsidebothifs, exactNaNbehavior andallothergetters/corrections/context. No secondform or constructor/flag/type/layout change. Strict12636function andalloldpreservationgates beforeLD.

Root reviewed show600 function252realinstruction544B/56literal whitelist andtwoactualnativefaddfrontiers30476c/304836. Authorize metadata-only actualfalse normalmathCALL_RETURNclear withinverifiedtarget, boundedThumbdecode, voidselfR0, entire600memoryequalsretail. NoBLbranch/globalcallee edits/sourcecompile/credit; ownerretainsindependentreadback.

Script typeguard control independentlyreviewed12320/native12636,35oldraw/842inputs stable,noLD. resume_string retainsREADONLY previouslyunprovedcases0..29 onlatest8correctionbody, excludingsettledconstructor/global/opcode/repeatedproofs. Focusnative/actual guards/commonjoins/physicalargs/fieldwidths/freshsnapshots; no compiler/source/metadatawrites without newreview.

Root reviews switchContext complete393real862B proof andnormaldelete301b60nativec2f6a6eb returningto301b64commonbody. Authorize inspect/clearONLYactualfalseCALL_RETURN atprogram311b60ifpresent, no nativecallchange, voidselfR0/contextwordR1/forceboolR2explicitABI, full900memoryretailguard. No sourcecompile/credit; ownerretains independentfreshdecompile/readback.

Root reviews context preconstruction-index proof and freshdelete-continuation readback. AuthorizeONE source-only nodeIndex snapshot control forresume_mission onactualcurrent-layout884: captureconstintcontextWord afterresetWantedLevel/beforelookup, useonlypostconstruct nodecacheinsertion; preservefreshanimationindex afterbind andallothercontextreads, genuineenum/API/layout/header/flags. Freeze884andalloldraw/semantic/import/allocated/frozeninputs; strict900function/inputsection beforeLD, exactextentSTOPforrootreviewbeforeoldclosurelink. No secondform or globalcontextcache.

Root accepts initInVehicle456/186real404B/52literal proof andfadd3049acnativecff6d2eb missingcontinuation3049b0. Authorize metadata-onlyactualfalse normalmathreturn overrideswithinverifiedtarget, boundedThumbdecode, voidselfR0/vehicleR1, full456retailmemoryguard, zeroBLbranch/globalcallee edits. No sourcecompile/credit; ownerretainsfreshreadback.

Root accepts positionInVehicle640/268real588B/52literal proof andtwofaddfrontiers304b12/304c16. Authorize metadata-only actualfalse normalmathreturnclearwithinverifiedtarget, boundedThumbdecode, voidselfR0/boolR1, full640retailmemoryguard, zeroBLbranch/globalcallee changes. No sourcecompile/credit; ownerretainsfreshreadback.

After hourly PR771 cutoff, the coordinator requests a syntax-checked, unexecuted Python proposal for the owned Player attackable-target normal-return repair. Preserve its exact700-byte retail memory and real298-instruction whitelist, query only actual false float/delete CALL_RETURNs, keep original calls and zero internal BL overrides, and model static source/weapon/fallback pointers in R0/R1/R2 with pointer result R0. Workers must not execute project writes; main reviews and applies metadata.

Hourly PR771 merged after exact HEAD ab79c2a65f445543d55e62a227b54aa325071ff9, both successful CI checks and clean mergeability were verified. Merge45362776735c107b45101eb25fc7bf0b0c6ef820; main CI45038887986 succeeded. Entire android-arm report artifact14760563175 equals the retained local report, with353318 matched and114548 fully linked bytes. No new match or denominator change. Next hourly combined PR is due by16:31 UTC. Current branch match/hourly-decomp-after-771 carries only subsequent ownership/analysis preparation.

The coordinator reviewed the complete prepared ready and setState scripts. Authorize guarded metadata application only: ready9-entry computed switch with explicit self/float ABI, and setState actual local fsub/GetHeight return continuations with explicit self/state ABI. Require unchanged whole retail memories, all whitelisted bytes/widths/ownership, protected original calls and no arbitrary boundaries or BL overrides. Each transaction must roll back on any failed guard. No source compilation or matching credit follows.

setState preparation guards stopped before mutation: Ghidra namespace display includes a class suffix, so identity now uses getName(); the legacy shared State enum is not four bytes. Original R1-to-SL/fullword compare/store at33f1fc/204/218 proves a32-bit physical parameter. Root permits a local IntegerDataType state view without resizing any shared enum. Exact native memory and all transaction/call guards remain mandatory; no source or compiler change.

The coordinator reviewed the complete attackable-target repair proposal and its frozen packet. Authorize only verified actual float/delete return overrides and missing Thumb instructions within the700-byte original function, with unchanged runtime callees, entry boundaries, original calls and retail memory. Preserve static source/weapon/fallback R0/R1/R2 and pointer result R0; no implicit Player receiver. Every guard must pass before transaction commit. No C++ compilation or matching credit.

Heartbeat dispatch 2026-11-24 01:35 UTC: the worktree was clean and contained no
unpublished changes. PR772 is already merged at69456fff4e63ce60e62f53425fb594d49ca1a06d;
no duplicate PR was created. All102 unit tests, repository and progress checks
passed, reporting4288/4550 functions and354058/561716 bytes (63.03%). Main created
match/hourly-decomp-20261124-0135 from the fetched origin/main before dispatch.
The three reviews above use isolated private scratch inputs. Initial scope is
read-only evidence and historical-budget recovery; no compiler, canonical source,
shared header, Ghidra project, commit, push, PR or further delegation is authorized
for workers. New source controls require coordinator review of a concrete
constraint. Preserve every old candidate, marker and exact verification result.

Coordinator review 2026-11-24: accepted all three completed read-only audits as
negative results, with no matching credit. No old source-form budget is reset.
The same owners retain the explicitly narrowed evidence-planning scopes above.
Any current-context replay would be a separately bounded coordinator escalation,
not a repeated equality/hint/constructor grid. Workers must first identify exact
inputs, required compatibility edits, emitted support definitions and existing
verification gates. No compiler or canonical/shared/project writes are authorized.

Coordinator correction: the accepted Vehicle::explode implementation uses unsigned placement storage and explicit weak D1 calls, not named automatic events. The named-local transfer premise is withdrawn. Character worker must compare that actual placement pattern with recovered punched forms before proposing any control; no compiler is authorized for that function yet.
Coordinator authorizes ONE bounded OnDespawn current-context replay after full plan review. Freeze actual current canonical inputs; preserve the Vehicle.cpp prefix byte-for-byte, append only the original best body with unknown960 renamed unknown960Word. Use unchanged current compiler/assembler profiles and real toolchain. Preserve all old definitions, semantic relocations, imports and payloads; strict308 function/input section before native link, validated missing Thumb imports only, unchanged190/114 owner gates and native neighbors. Reproduce/verify an authentic current baseline first. Any failure stops the run; no comparison/hint/grid or second source form. Worker must not integrate, remove markers or use Git.

OnDespawn current baseline compiled and passed all190 functions/114 regions with old-object preservation. Candidate compiler has not run. Authorize one mechanical private linker-preparation newline fix (canonical linker is LF), preserving all source bytes, profile flags, native assertions and intended section insertion. The still-unused single candidate compile may then proceed under the original gates; this is not a new source form or retry budget. Preserve the original preparation failure evidence and stop on any subsequent failed gate.

Coordinator reactivation 2026-11-24: current runtime has three worker slots plus
the coordinator. Reactivate both explicitly bounded construction-context probes.
The third worker receives a read-only eligible-target and reuse-evidence survey,
with no function ownership, implementation edits or compiler authorization until
the coordinator records a distinct target. Historical attempt budgets remain
binding. No matched credit is added by these assignments.

Coordinator 2026-11-24: RenderFX evidence scope assigned after reviewing TARGET-SURVEY.md; earlier unassigned duplicate history rows do not confer ownership. No fresh source trial is authorized.

Coordinator 2026-11-24: reviewed Vehicle OBJECT-STAGE-REPORT.md, PRIVATE-LINK-PLAN.md and real generated support. Root proved188-byte table symbol plus genuine four zero padding bytes match native gap through0x4ab2b8. Authorize one ordinary private LD using immutable candidate object6eb255a994b22ce5c53a2533ecd857a31b7cebfb9066a2c800da5b7deb1fd0e2, validated Thumb metadata and complete192-byte table check, all190/114 existing gates, actual D0/D1/D2/native sections. No candidate source or frontend/assembler retry, relaxed assertions, output editing or matching credit before complete-byte comparison.

Coordinator 2026-11-24: accepted private Vehicle family exact proof and began canonical global gate. Character declaration-only escalation is bounded to one frozen-input candidate; native lifetime/storage hypotheses remain unapproved. RenderFX sibling negative accepted, no credit. Script cases30..59 assigned exclusively for new evidence, not another compiler/context trial.

Coordinator 2026-11-24: accepted weak-D1 control negative884/native884; real GOT calls restored, but frame40/sharedSP24 differs from native and genuine temporary-baseline frame56/SP28+SP44. Authorize ONE final lexical-lifetime control from that actual weak baseline: remove only the NPC storage inner braces, leaving real unsigned event storage in the containing type-test block so it overlaps the existing Player-storage lexical scope. Preserve explicit NPC destructor before category read, Player cleanup, both weak declarations and all statements/headers/flags. No dummy storage, padding, new field/type/attribute, constructor variation or further lifetime grid. Strict884 extent and all existing/native helper/GOT/switch checks remain mandatory; stop after this candidate whether matching or not.

Coordinator 2026-11-24: verified Vehicle family accepted and ownership released after full global gate. Final punched controls parked with nine differing bytes and public patch. Fresh three-slot family batch is read-only transfer analysis of the now exact event construction block; no source budget resets or automatic compiler authorization.
