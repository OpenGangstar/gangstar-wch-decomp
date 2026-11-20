# Decompilation function registry

The main Codex agent records assignments and releases ownership after review
and acceptance. Use the binary, address, and function name to identify each
entry. Follow the workflow in [AGENTS.md](AGENTS.md).

| Binary/library | Address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | ---: | --- |
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
| libsanangeles.so | 0x00334a81 | LockCamera::init | lock_init | BLOCKED | — | src/game/core/LockCamera.cpp |
| libsanangeles.so | 0x003351dd | VehicleCamera::goToSide | vehicle_side | BLOCKED | — | src/game/vehicles/VehicleCamera.cpp |
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
| libsanangeles.so | 0x00334389 | FPSCamera::updateTouchInputs | camera_tap | BLOCKED | — | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x002e3c49 | GSWeaponShopMenu::ctor | — | COMPLETED | 100% | src/game/ui/GSWeaponShopMenu.cpp |
| libsanangeles.so | 0x00333451 | FollowCamera::updatePosition | — | COMPLETED | 100% | src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x00332771 | CameraManager::update | camera_tap | BLOCKED | — | src/game/core/CameraManager.cpp |
| libsanangeles.so | 0x00301a3d | PlayerTest::Stop | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00333789 | FollowCamera::init | — | COMPLETED | 100% | src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x00333ab1 | FollowCamera::update | — | BLOCKED | Real-hierarchy adaptation784/native776; one recovered crossProduct reuse restores776extent but frame196/native204 fails0xe. Owner13functions6sections1GOT exact. Reviewed unapplied patch retained; no credit or further lifetime/ordering forms without new evidence. Ownership released. | src/game/core/FollowCamera.cpp; nonmatching/core/FollowCamera-update.patch |
| libsanangeles.so | 0x002e1571 | GSCarRepairMenu::draw2d | lock_init | BLOCKED | — | src/game/ui/GSCarRepairMenu.cpp |
| libsanangeles.so | 0x00334c25 | LockCamera::update | camera_tap | BLOCKED | — | src/game/core/LockCamera.cpp |
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
| libsanangeles.so | 0x003025cd | PlayerTest::isFacingTarget | camera_tap | BLOCKED | — | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x002f42cd | Character::updatePosition | — | COMPLETED | 100% | src/game/characters/Character.cpp |
| libsanangeles.so | 0x00301911 | PlayerTest::initDriving | vehicle_side | BLOCKED | — | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00334fe9 | SceneCamera::Load | — | COMPLETED | 100%; all96 native bytes independently verified in root. Full190/10,917 pass; actual GS3D COMDAT provider and generatedcleanup36 preserved. Completes original15-entry/646-byte source group. | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x0031ff49 | PhysicAttributes::GetHeight (position overload) | lock_init | BLOCKED | — | src/game/characters/PhysicAttributes.cpp |
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
| libsanangeles.so | 0x00348fb5 | TrailMgr::AllocTrailList | lock_init | BLOCKED | — | src/game/world/TrailMgr.cpp |
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
| libsanangeles.so | 0x003485f1 | Trail::Update (no arguments) | vehicle_side | BLOCKED | — | src/game/world/Trail.cpp |
| libsanangeles.so | 0x00348a61 | Trail::AddPoint | — | COMPLETED | 100% | src/game/world/Trail.cpp |
| libsanangeles.so | 0x00348ba5 | Trail::Update (point overload) | — | COMPLETED | 100% | src/game/world/Trail.cpp |
| libsanangeles.so | 0x00348cfd | Trail::CreateMeshSceneNode | vehicle_side | BLOCKED | — | src/game/world/Trail.cpp |
| libsanangeles.so | 0x00348735 | Trail::BuildPoint | camera_tap | BLOCKED | — | src/game/world/Trail.cpp |
| libsanangeles.so | 0x0030a731 | Vehicle::isDoorClear | lock_init | BLOCKED | — | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030ae3d | Vehicle::getCollisionRect | vehicle_side | BLOCKED | — | src/game/vehicles/Vehicle.cpp |
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
| libsanangeles.so | 0x0034fbf9 | CarSounds::UpdateTurboSounds | camera_tap | BLOCKED | — | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x00350019 | CarSounds::AddTurboSounds | lock_init | BLOCKED | — | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0035047d | CarSounds::Init | vehicle_side | BLOCKED | — | src/game/vehicles/CarSounds.cpp |
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
| libsanangeles.so | 0x00310e75 | Vehicle::OnDespawn | camera_tap | BLOCKED | — | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00309f0d | Vehicle::dropSceneNode | camera_tap | BLOCKED | — | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x003092b5 | CCarFactory::createMorph | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00311eb1 | CCarMorphingMesh::~CCarMorphingMesh (D1) | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030b12d | Vehicle::debug | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00309231 | CustomSkinnedMeshSceneNode::CustomSkinnedMeshSceneNode (C1) | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00310fa9 | Vehicle::disable | lock_init | BLOCKED | — | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00309601 | Vehicle::UpdateCarTireTrails | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030b9a5 | Vehicle::repair | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00312d19 | Vehicle::playDriveSfx | lock_init | BLOCKED | — | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x003130a1 | Vehicle::explode | camera_tap | BLOCKED | — | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00309a4d | Vehicle::setupSceneNode | vehicle_side | BLOCKED | — | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00311e41 | CCarMorphingMesh::~CCarMorphingMesh (virtual D0 thunk) | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00311e55 | CCarMorphingMesh::~CCarMorphingMesh (D0) | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00311e9d | CCarMorphingMesh::~CCarMorphingMesh (virtual D1 thunk) | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030b68d | Vehicle::ResetBodyPosition | — | BLOCKED | Fourth candidate is 784 versus 792 native bytes. All 188 existing functions and 112 section/region checks pass. No helper emissions or further source trials; parked without credit. | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00311fb5 | CustomSkinnedMeshSceneNode::~CustomSkinnedMeshSceneNode (D1) | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030bccd | Vehicle::setSpeed | lock_init | BLOCKED | — | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00310499 | Vehicle::grabSceneNode | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030fac9 | Vehicle::CreateBody | — | BLOCKED | Reviewed SDK-source/word-enum model1040/native1044; real weak SDK destructors and436B frame, four-byte pre-wheel size deficit. Current-main/getter replays identical; no link, helper/header closure or credit. Reject1050B strong-binding pragma form. | nonmatching/vehicles/Vehicle-CreateBody-sdk-reuse.patch; src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00310909 | Vehicle::shoot | vehicle_side | BLOCKED | — | src/game/vehicles/Vehicle.cpp |
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
| libsanangeles.so | 0x0032cbe1 | Wheel::Wheel (C1/C2 aliases) | camera_tap | BLOCKED | — | src/game/vehicles/Wheel.cpp |
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
| libsanangeles.so | 0x002faab9 | CustomSkyBoxSceneNode::CustomSkyBoxSceneNode (C2) | lock_init | BLOCKED | — | src/game/rendering/CustomSkyBoxSceneNode.cpp |
| libsanangeles.so | 0x002f84c9 | CustomSkyBoxSceneNode::setSkyColor | lock_init | BLOCKED | — | src/game/rendering/CustomSkyBoxSceneNode.cpp |
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
| libsanangeles.so | 0x002f7ce9 | CustomBillboardSceneNode::setColor | camera_tap | BLOCKED | — | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002f7b3d | CustomBillboardSceneNode::CustomBillboardSceneNode (C1) | — | COMPLETED | 100% | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002f7bf1 | CustomBillboardSceneNode::CustomBillboardSceneNode (C2) | — | COMPLETED | 100% | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002f7e51 | CustomBillboardSceneNode::debug | — | COMPLETED | 100% | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002d30d1 | virtual thunk to LODSceneNode::~LODSceneNode (D0) | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d30e5 | virtual thunk to LODSceneNode::~LODSceneNode (D0) | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d30f9 | LODSceneNode::~LODSceneNode (D0) | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d31ad | virtual thunk to LODSceneNode::~LODSceneNode (D1) | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d31c1 | virtual thunk to LODSceneNode::~LODSceneNode (D1) | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d31d5 | LODSceneNode::~LODSceneNode (D1) | — | COMPLETED | 100% | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002f96e9 | CustomSkyBoxSceneNode::CustomSkyBoxSceneNode (C1) | lock_init | BLOCKED | — | src/game/rendering/CustomSkyBoxSceneNode.cpp |
| libsanangeles.so | 0x002dc591 | GS3DStuff::parseSceneNodeForLOD | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002df34d | GS3DStuff::SetAlpha | — | BLOCKED | One owning-context replay is byte-identical to archived v6: 168 bytes, 34 differences first0x56. Strict current closure preserved; no credit. Historical profile already had word-sized enums. | nonmatching/rendering/GS3DStuff-SetAlpha-owning-context.patch; src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002de5a5 | GS3DStuff::AddToSceneMgr | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002db549 | GS3DStuff::loadPerformanceProfile | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002dbde5 | GS3DStuff::setPerformanceType | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002de919 | GS3DStuff::unload | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002dc715 | GS3DStuff::checkVehicleProximity | camera_tap | BLOCKED | — | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002deba1 | GS3DStuff::checkPickableProximity | — | BLOCKED | Six archived forms reviewed. One bounded named-position/full-delta value capture emits 360 bytes versus native 356 and an extra Character::position() helper. Stopped before owner linking; no native match or owner closure claimed. Private candidate rejected, production inputs unchanged; ownership released after review. | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002dd0c1 | GS3DStuff::checkForDespawn | lock_init | BLOCKED | — | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002de6dd | GS3DStuff::PrintNodeProperties | camera_tap | BLOCKED | — | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002df419 | GS3DStuff::tearDown | vehicle_side | BLOCKED | — | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002df995 | OctTreeAABB::OctTreeAABB | lock_init | BLOCKED | — | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002dce9d | std::string::append(const char*) | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002deebd | GS3DStuff::AddXRef | vehicle_side | BLOCKED | — | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002dcd29 | std::string::_M_append(const char*, const char*) | camera_tap | BLOCKED | — | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002df655 | OctTreeAABB::OctTreeAABBNode::OctTreeAABBNode | lock_init | BLOCKED | — | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002dad71 | GS3DStuff.cpp::__tcf_8 | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002dc959 | GS3DStuff::DrawBody | vehicle_side | BLOCKED | — | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002dada9 | GS3DStuff.cpp::__tcf_7 | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x00328df9 | Message::isDisplayed | — | COMPLETED | 100% | src/game/ui/Message.cpp |
| libsanangeles.so | 0x00334ef1 | SceneCamera.cpp::__tcf_1 | — | COMPLETED | 100%; handwritten wrapper replaced by real generated__tcf_0 with explicit native/compiled selector, all36 bytes exact. Both native cleanupaddresses retained; root190/10,917 pass. | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x0034934d | AnimObject::Reset | — | COMPLETED | 100% | src/game/characters/AnimObject.cpp |
| libsanangeles.so | 0x00349445 | AnimObject::IsAnimOver | — | BLOCKED | Six forms plus one bounded negative-speed hint fail; own21/22 and independent callers46/23 exact, no relevant ABI drift, no credit | src/game/characters/AnimObject.cpp |
| libsanangeles.so | 0x003f01d1 | MenuFX::GetStateHandler | — | BLOCKED | Authentic ownership source gives 124/142 bytes at limit 70; measured limit-80 probe inlines the checker but emits 168 bytes and fails strict overlap. No profile change adopted. | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x0032cfb8 | _ZThn8_N5Wheel12processTouchEl | — | COMPLETED | 100%; full 190-profile, 10,501-comparison native gate exact; existing event destructor bodies preserved; unmatched parents receive no credit | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x00300bc5 | Path::Load | — | BLOCKED | Genuine SDK whole-vector assignment retains native200extent, four bytes differ at68/6a/72/78 in source/Z registers. All18 existing checks pass; one bounded family trial stopped, no credit or further forms. | src/game/world/Path.cpp |
| libsanangeles.so | 0x0034228d | NPCController::onEvent | — | BLOCKED | One bounded switch trial remains 94/96 bytes; no linked credit. Full-word TransitionCondition prerequisite independently preserves all six affected profiles (137 comparisons); candidate in nonmatching/ai/NPCController-onEvent.md. | src/game/ai/NPCController.cpp; src/game/ai/NPCController.h |
| libsanangeles.so | 0x003511b9 | CSoundDecoderMSADPCM::Init | — | BLOCKED | Six constructor-reuse forms:138/132/132/130/132/132B versus native134; forms2/5/6 exact same raw code and relocations. Retained native placement fails target; old22functions/19regions exact. Reviewed unapplied candidate; no credit or more forms without new evidence. | src/game/audio/CSoundDecoderMSADPCM.cpp; nonmatching/audio/CSoundDecoderMSADPCM-Init.patch |
| libsanangeles.so | 0x0032d72d | CControlManager::update | vehicle_side | BLOCKED | — | src/game/input/CControlManager.cpp |
| libsanangeles.so | 0x00354665 | EventManager::_attach | camera_tap | BLOCKED | — | src/game/scripting/EventManager.cpp |
| libsanangeles.so | 0x00354725 | EventManager::_detach | camera_tap | BLOCKED | — | src/game/scripting/EventManager.cpp |
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
| libsanangeles.so | 0x0033d271 | ScriptManager::reachRunningCommand | lock_init | BLOCKED | — | src/game/scripting/ScriptManager.cpp |
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
| libsanangeles.so | 0x0033f1ed | ScriptManager::setState(State) | — | BLOCKED | One verified NDK enum-width replay is byte-identical to archived unmatched732B; target/section/table fail, existing143functions133sections1GOT pass. See nonmatching/scripting/ScriptManager-setState.md. | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033f511 | ScriptManager::update | camera_tap | BLOCKED | — | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x00339385 | Script destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x003392a1 | Script constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x003399c5 | Script::clearScriptObjectAction | — | COMPLETED | 100% | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x0033999d | Script::setScriptObjectAction | — | COMPLETED | 100% | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x0033922d | Script::setState(State, PlayerTest::eContext) | — | COMPLETED | 100%; exact 58-byte executable and full 60-byte section under original NDK enum-width baseline. Full root190/10951 proof passes; no existing body changes. | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x003398b5 | Script::unsetScriptObjectAction | camera_tap | BLOCKED | — | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x0033ce19 | Script::nextCommand | lock_init | BLOCKED | — | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x003399f1 | Script::rewind | vehicle_side | BLOCKED | — | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x003365a5 | Mission::idle | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x00335d8d | Mission::fail | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x00336345 | Mission::message | — | BLOCKED | Reviewed six forms124/120B; extra same-ID timer tail and scheduling remain, current APIs already correct; no new replay evidence | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x003360c1 | Mission constructor (C1/C2 aliases) | vehicle_side | BLOCKED | — | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x0033602d | Mission destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x00336141 | getFrameModuleRect | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x00335f91 | Mission deleting destructor (D0) | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x00336961 | Mission::end | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x00335e61 | Mission::load | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x0033620d | Mission::draw | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x003363d1 | Mission::start | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x003365f1 | Mission::update | vehicle_side | BLOCKED | — | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x00338c41 | Revive::update | — | COMPLETED | 100% | src/game/missions/Revive.cpp |
| libsanangeles.so | 0x0033820d | MissionConditionStayWithin::evaluate | vehicle_side | BLOCKED | — | src/game/missions/MissionConditionStayWithin.cpp |
| libsanangeles.so | 0x0032c7fd | WantedMeter::draw2d | — | COMPLETED | 100% | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032c7e8 | WantedMeter::draw2d non-virtual thunk | — | COMPLETED | 100% | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032addd | Reward::update | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032c919 | WantedMeter destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032c851 | WantedMeter::update | — | COMPLETED | 100%; indexed-loop reuse plus permitted likelihood hint, exact80 and full190/10937 preservation | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032ae69 | Reward constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032c8b5 | WantedMeter deleting destructor (D0) | — | COMPLETED | 100% | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032c8a0 | WantedMeter deleting destructor thunk (D0) | — | COMPLETED | 100% | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032c904 | WantedMeter complete destructor thunk (D1) | — | COMPLETED | 100% | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032c961 | WantedMeter constructor (C1/C2 aliases) | — | BLOCKED | Two real SDK-value forms emit268/native272; prerequisite20checks preserved, no link or credit | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032b0e1 | Reward destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032ad65 | Reward::setAnim | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032b07d | Reward deleting destructor (D0) | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032b068 | Reward deleting destructor thunk (D0) | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032b0cc | Reward complete destructor thunk (D1) | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032ad75 | Reward::setMessage | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032adb1 | Reward::draw2d | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032ad9c | Reward::draw2d non-virtual thunk | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x00342b09 | WantedLevelManager constructor (C1/C2 aliases) | vehicle_side | BLOCKED | — | src/game/missions/WantedLevelManager.cpp |
| libsanangeles.so | 0x00342e05 | WantedLevelManager::_processWantedLevel | — | COMPLETED | 100% | src/game/missions/WantedLevelManager.cpp |
| libsanangeles.so | 0x00343141 | WantedLevelManager::onEvent | camera_tap | BLOCKED | — | src/game/missions/WantedLevelManager.cpp |
| libsanangeles.so | 0x00342fc9 | WantedLevelManager::update | vehicle_side | BLOCKED | — | src/game/missions/WantedLevelManager.cpp |
| libsanangeles.so | 0x00342fb4 | WantedLevelManager::update non-virtual thunk | — | COMPLETED | 100%; real 20-byte ARM thunk; full 187-profile, 10,400-comparison native gate exact; parent remains unmatched | src/game/missions/WantedLevelManager.cpp |
| libsanangeles.so | 0x003ed9a9 | RenderFX fscommand_callback_handler regression | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x00352cad | SoundManager::getNumberOfPlayingSounds | — | BLOCKED | 78/80 bytes; measured VRP2 address-operand commutation, ordinary/dump outputs identical, old71 functions/75 regions pass; no new form justified | src/game/audio/SoundManager.cpp |
| libsanangeles.so | 0x0030b59d | Vehicle translation-unit initializer wrapper | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x003ee801 | RenderFX deleting destructor (D0) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ee885 | RenderFX destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ec961 | RenderFX::Initialize | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x0030b311 | Vehicle translation-unit initializer | vehicle_side | BLOCKED | — | src/game/vehicles/Vehicle.cpp |
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
| libsanangeles.so | 0x00327be9 | Cash::draw2d | vehicle_side | BLOCKED | — | src/game/ui/Cash.cpp |
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
| libsanangeles.so | 0x0032abe9 | RetroEffect::draw2d | camera_tap | BLOCKED | — | src/game/rendering/RetroEffect.cpp |
| libsanangeles.so | 0x0032abd4 | RetroEffect::draw2d non-virtual thunk | — | COMPLETED | 100%; real 20-byte ARM thunk; combined 186-profile native gate exact; parent remains unmatched and uncredited | src/game/rendering/RetroEffect.cpp |
| libsanangeles.so | 0x0032b158 | SlideControl deleting destructor thunk | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b16d | SlideControl deleting destructor (D0) | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b19c | SlideControl complete destructor thunk | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b1b1 | SlideControl complete destructor (D1) | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b1dd | SlideControl::reset | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b1f5 | SlideControl constructor (C1/C2 aliases) | vehicle_side | BLOCKED | — | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b3e1 | SlideControl::update | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b42d | SlideControl::draw2d | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b418 | SlideControl::draw2d non-virtual thunk | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b5ad | SlideControl::processTouchRelease | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b598 | SlideControl::processTouchRelease non-virtual thunk | — | COMPLETED | 100% | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b665 | SlideControl::processTouch | — | BLOCKED | Unmatched. Bounded diagnostics/source tests frozen; all existing matches preserved; no new credit | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b650 | _ZThn8_N12SlideControl12processTouchEl | — | COMPLETED | 100%; full 190-profile, 10,501-comparison native gate exact; existing event destructor bodies preserved; unmatched parents receive no credit | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x00326581 | AnalogStick constructor (C1/C2 aliases) | lock_init | BLOCKED | — | src/game/input/AnalogStick.cpp |
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
| libsanangeles.so | 0x0034ccf1 | TouchScreenBase::touchBegan | — | BLOCKED | Reviewed ordinary inline reference helper: 140 bytes, same seven differences beginning at 0x32 as the retained unhinted candidate. Existing 35 functions, 44 sections and GOT preserved; new 28-byte message passes. Helper fully inlined; no credit. | nonmatching/input/TouchScreenBase-touchBegan-initializer-helper.patch; src/game/input/TouchScreenBase.cpp |
| libsanangeles.so | 0x0034d989 | AccelerometerWin32 OnEvent | — | COMPLETED | 100%; actual bool ABI and original missing return preserved; full 186-profile, 10,358-comparison native gate exact | src/game/input/AccelerometerWin32.cpp |
| libsanangeles.so | 0x0034d974 | AccelerometerWin32 OnEvent non-virtual thunk | — | COMPLETED | 100%; actual bool ABI and original missing return preserved; full 186-profile, 10,358-comparison native gate exact | src/game/input/AccelerometerWin32.cpp |
| libsanangeles.so | 0x0034da8d | AccelerometerWin32 deleting destructor (D0) | — | COMPLETED | 100% | src/game/input/AccelerometerWin32.cpp |
| libsanangeles.so | 0x0034dad9 | AccelerometerWin32 complete destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/input/AccelerometerWin32.cpp |
| libsanangeles.so | 0x0034da78 | AccelerometerWin32 deleting destructor thunk | — | COMPLETED | 100% | src/game/input/AccelerometerWin32.cpp |
| libsanangeles.so | 0x0034dac4 | AccelerometerWin32 complete destructor thunk | — | COMPLETED | 100% | src/game/input/AccelerometerWin32.cpp |
| libsanangeles.so | 0x0034d9bd | AccelerometerWin32 constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/input/AccelerometerWin32.cpp |
| libsanangeles.so | 0x0034d941 | AccelerometerWin32::setWide | — | COMPLETED | 100% | src/game/input/AccelerometerWin32.cpp |
| libsanangeles.so | 0x0034d479 | AccelerometerBase::_calcAngles | camera_tap | BLOCKED | — | src/game/input/AccelerometerBase.cpp |
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
| libsanangeles.so | 0x002e2725 | GSInGameMenu::update | lock_init | BLOCKED | — | src/game/ui/GSInGameMenu.cpp |
| libsanangeles.so | 0x0032e6f9 | COnFootControlHandler::handleAttackHeld | — | COMPLETED | 100% | src/game/input/COnFootControlHandler.cpp |
| libsanangeles.so | 0x0032e76d | COnFootControlHandler::handleAttackPressed | — | COMPLETED | 100% | src/game/input/COnFootControlHandler.cpp |
| libsanangeles.so | 0x002ed215 | Widgets::Mission::OnEvent | lock_init | BLOCKED | — | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x0032ed5d | COnFootControlHandler::onEvent | — | COMPLETED | 100% | src/game/input/COnFootControlHandler.cpp |
| libsanangeles.so | 0x0032e835 | COnFootControlHandler::onKeyboardEvent | vehicle_side | BLOCKED | — | src/game/input/COnFootControlHandler.cpp |
| libsanangeles.so | 0x0032d945 | CDrivingControlHandler::disableAccelerometer | — | COMPLETED | 100% | src/game/input/CDrivingControlHandler.cpp |
| libsanangeles.so | 0x0032da91 | CDrivingControlHandler::onEvent | camera_tap | BLOCKED | — | src/game/input/CDrivingControlHandler.cpp |
| libsanangeles.so | 0x002ed11d | Widgets::About::Enable | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ef041 | Widgets::About::Disable | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ebf35 | Widgets::About::Update | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ecb01 | Widgets::Help::SetIcon | — | BLOCKED | Three forms same6 scheduling bytes; actual original MenuWidget ownership and current flags confirmed, no API or literal correction; no replay | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ecbbd | Widgets::Achievement::SetIcon | coordinator | BLOCKED | — | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ecb9d | Widgets::IGMenu::GoToFrame | — | BLOCKED | Bool forwarding is byte-identical to the mismatching void model; disabling sched2 regresses 140 old functions and two sections; all experiments rejected | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ece95 | Widgets::About::Show | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ec565 | Widgets::About constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ed459 | Widgets::About::UpdateLocalization | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee811 | Widgets::About::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ec821 | Widgets::MapLegend constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ecf0d | Widgets::MapLegend::Show | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ed299 | Widgets::MapLegend::OnEvent | vehicle_side | BLOCKED | — | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002edb61 | Widgets::MapLegend::UpdateLocalization | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ed139 | Widgets::Corruption::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ed1c5 | Widgets::DemoBuy::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002eebc5 | Widgets::BlockingTutorial::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ed809 | Widgets::DemoBuy::UpdateLocalization | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002edd6d | Widgets::IGMenu::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee979 | Widgets::Tutorial::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ef6f5 | Widgets::Tutorial::UpdateLocalization | — | COMPLETED | 100%; native464 exact in owner and consumer. Combined190-profile10656-check root gate passes with previous matches retained; shared value/string interfaces and genuine name chain reused. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ecd99 | Widgets::Volumes::Hide | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee409 | Widgets::Statistics::Show | lock_init | BLOCKED | — | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ef0b1 | Widgets::Corruption::UpdateLocalization | — | BLOCKED | Coordinator source audit finds only static paths and no borrowedname/string/value construction. Real name chain irrelevant; prior three identical forms and typed SetText forwarding supply no new correction. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ef415 | Widgets::Volumes::UpdateLocalization | — | COMPLETED | 100%; ordinary truth-value mute selections and authentic UTF8 interfaces match736 in both images, no hints. Full190-profile10656-comparison coordinator gate passes; no Fully Linked credit. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee67d | Widgets::Achievements::SetCategory | lock_init | BLOCKED | — | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002edfbd | Widgets::ConfirmPayment::UpdateLocalization | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002edec1 | Widgets::Confirm::UpdateLocalization | — | COMPLETED | 100%;252 nativecode bytes and compiler-generated vtable36-symbol/40-section match bothimages. Full190-profile10656-comparison coordinator gate passes; no Fully Linked credit. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002eec15 | Widgets::Statistics::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee2c1 | Widgets::Statistics::UpdateLocalization | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee489 | Widgets::Achievements::UpdateLocalization | — | BLOCKED | Saved candidate is500/native500 with only8 spill-slot bytes different, not492-byte size. No borrowedname/string/value dataflow; SDK name chain irrelevant. No replay. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee6ed | Widgets::Controls::UpdateLocalization | — | BLOCKED | Six old292-byte forms; no borrowedname/string/value flow and current HUD fields agree with native widths/choice data. New name chain irrelevant; no replay. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ef901 | Widgets::Objective::OnEvent | — | BLOCKED | Actual Thumb/GOT modes already correct; native duplicates a call that old248 candidate merges, with frame/register differences. Event name is already a pointer; no relevant SDK correction. No replay. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002eeda1 | Widgets::Achievements::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002efda5 | Widgets::Controls::OnEvent | vehicle_side | BLOCKED | — | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ef9fd | Widgets::MainMenu::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002efafd | Widgets::GameSetting::OnEvent | — | BLOCKED | Two historical six-form waves exhausted; event-name pointer and native singleton/playback call modes already correct. Relocated320-byte diagnostics are not native proof; no new ABI/helper gap. | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002efc31 | Widgets::Language::OnEvent | vehicle_side | BLOCKED | — | src/game/ui/MenuWidget.cpp |
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
| libsanangeles.so | 0x002e6149 | MenuManager::tearDown | camera_tap | BLOCKED | pending | src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x0034c089 | DataReloaderManager::monitorFiles | — | COMPLETED | 100% | src/game/world/DataReloaderManager.cpp |
| libsanangeles.so | 0x0034c211 | DataReloaderManager constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/world/DataReloaderManager.cpp |
| libsanangeles.so | 0x002e6731 | MenuManager::_positionMapOnPoint | vehicle_side | BLOCKED | pending | src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x0034c0a1 | DataReloaderManager::_MonitoredFiles destructor | — | COMPLETED | 100% | src/game/world/DataReloaderManager.cpp |
| libsanangeles.so | 0x002e6949 | MenuManager::updateMarkers | camera_tap | BLOCKED | pending | src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x0034c0c5 | DataReloaderManager destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/world/DataReloaderManager.cpp |
| libsanangeles.so | 0x002e6865 | MenuManager::_scrollMap | vehicle_side | BLOCKED | pending | src/game/ui/MenuManager.cpp |
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
| libsanangeles.so | 0x002fe0e9 | NPC::isHostileTo | camera_tap | BLOCKED | pending | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002febc9 | NPC::clearOnAlert | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fef75 | NPC::setHitByCar | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fe999 | NPC::freeze | — | BLOCKED | One true-voice likelihood hint worsens3 to19 byte differences; current unhinted control exactly reproduces saved224B/3-byte miss. Owner71functions14sections1GOT plus dependencies preserved. No credit; private frozen-bit support unapplied. | nonmatching/ai/NPC-freeze-current.patch; src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fdb79 | NPC destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fdb29 | NPC deleting destructor (D0) | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fd565 | NPC::isOutsideSearchRadius | vehicle_side | BLOCKED | pending | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fd611 | NPC.cpp::__tcf_1 | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fec29 | NPC::disable | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fee69 | NPC::OnDespawn | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fe3c9 | NPC constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fdcfd | NPC::Load | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fe169 | NPC::goToVehicle | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x003009d1 | NPC::SetTarget | vehicle_side | BLOCKED | pending | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fe615 | NPC::triggerCombatSFX | camera_tap | BLOCKED | pending | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fdbed | NPC::debug | — | COMPLETED | 100% | src/game/ai/NPC.cpp |
| libsanangeles.so | 0x002fde51 | NPC::isUnderCar | vehicle_side | BLOCKED | pending | src/game/ai/NPC.cpp |
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
| libsanangeles.so | 0x002f3489 | Character::updateAnimation | camera_tap | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f661d | Character::switchMoveAnimation | lock_init | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f55d1 | Character::shoot | vehicle_side | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x00303b6d | PlayerTest::shoot | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00303b58 | PlayerTest::shoot non-virtual thunk | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003035d1 | PlayerTest::acquireTarget | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00303315 | PlayerTest::getAttackableTarget | lock_init | BLOCKED | pending | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00303fe9 | PlayerTest::updateAnim | — | BLOCKED | Authentic licensed SDK nonmember plus/Set prerequisite passed 190/10,687 with approved private InfoHelp compatibility edit; one canonical replay116/native132. Stopped pre-link; no credit or further forms. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00303ab9 | PlayerTest::startDriving | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00304701 | PlayerTest::stopDriving | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00302241 | PlayerTest::orientTowards | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00304895 | PlayerTest::teleportTo | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00305a1d | PlayerTest::attack | camera_tap | BLOCKED | pending | src/game/ai/PlayerTest.cpp |
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
| libsanangeles.so | 0x00302361 | PlayerTest::moveTo | camera_tap | BLOCKED | pending | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003049e5 | PlayerTest::Respawn | — | BLOCKED | One recovered-hierarchy adaptation retains544B extent and all37 native call modes/destinations, but fails at0x46; owner83functions24sections1region preserved. Reviewed unapplied reproduction patch; no credit. Ownership released; no further ordering/zero-allocation forms without new evidence. | src/game/ai/PlayerTest.cpp; nonmatching/ai/PlayerTest-Respawn.patch |
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
| libsanangeles.so | 0x00341f31 | GuardController::onEvent | lock_init | BLOCKED | pending | src/game/ai/GuardController.cpp |
| libsanangeles.so | 0x003420cd | GuardController::switchState | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/GuardController.cpp |
| libsanangeles.so | 0x00342585 | VehicleController::onEvent | lock_init | BLOCKED | pending | src/game/ai/VehicleController.cpp |
| libsanangeles.so | 0x0034171d | CopVehicleController::switchState | — | COMPLETED | 100%; current coherent Player hierarchy preserves this definition under full 190-profile/10,687-comparison gate. Existing-body compatibility edits and all native bytes reviewed by coordinator. | src/game/ai/CopVehicleController.cpp |
| libsanangeles.so | 0x00341381 | CopController::onEvent | vehicle_side | BLOCKED | pending | src/game/ai/CopController.cpp |
| libsanangeles.so | 0x003406a9 | AIManager::clean | — | COMPLETED | 100% | src/game/ai/AIManager.cpp |
| libsanangeles.so | 0x003426b5 | VehicleController::switchState | — | COMPLETED | 100% | src/game/ai/VehicleController.cpp |
| libsanangeles.so | 0x00340741 | AIManager::onEvent | — | COMPLETED | 100% | src/game/ai/AIManager.cpp |
| libsanangeles.so | 0x00340305 | AIManager::addAI(Vehicle*, StateID) | — | BLOCKED | Unmatched: one bounded NPC common-tail reuse emits 244/336 bytes; prelink guard exit 3, no linked comparison. See nonmatching/ai/AIManager-addAI-Vehicle.md. | src/game/ai/AIManager.cpp |
| libsanangeles.so | 0x00340455 | AIManager::addAI(NPC*, StateID) | — | COMPLETED | 100% | src/game/ai/AIManager.cpp |
| libsanangeles.so | 0x003520c1 | RadioStationController::selectRandomJingle | — | COMPLETED | 100% | src/game/ai/RadioStationController.cpp |
| libsanangeles.so | 0x003522b1 | RadioStationController::selectRandomSong | — | COMPLETED | 100% | src/game/ai/RadioStationController.cpp |
| libsanangeles.so | 0x00352335 | RadioStationController constructor (C1/C2 aliases) | vehicle_side | BLOCKED | pending | src/game/ai/RadioStationController.cpp |
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
| libsanangeles.so | 0x00352a55 | SoundManager::endCutscene | lock_init | BLOCKED | pending | src/game/audio/SoundManager.cpp |
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
| libsanangeles.so | 0x0032a0f9 | MiniMap::draw2d | hud_show | BLOCKED | pending | src/game/hud/MiniMap.cpp |
| libsanangeles.so | 0x00329901 | MiniMap::_calculateXYOffset | hud_drawables | BLOCKED | pending | src/game/hud/MiniMap.cpp |
| libsanangeles.so | 0x002eb45d | Menus::ServiceWeaponShop::Update | hud_registration | BLOCKED | pending | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e6fe1 | MenuManager::updateMap | hud_registration | BLOCKED | pending | src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x002e6ab1 | MenuManager::_drawMap | hud_show | BLOCKED | pending | src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x002e7165 | MenuManager::initMap | hud_drawables | BLOCKED | pending | src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x002e7ac5 | Menus::ServiceWeaponShop::Refresh | hud_registration | BLOCKED | pending | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e5e4d | MenuManager::preloadGlyphs | hud_glyphs | BLOCKED | 452/460 bytes (unmatched) | src/game/ui/MenuManager.cpp |

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

| libsanangeles.so | 0x002e1e15 | GSFailure::draw2d(StateMachine const*) | — | BLOCKED | One bounded early-byte-alpha capture and unchanged-form control emit identical 284-byte targets versus native 308; stopped prelink, no owner closure or credit. Private static failure getter and device include only; no shared change integrated. Historical 98/308 means same-offset byte equality, not function extent. Ownership released after review. | src/game/app/GSFailure.cpp |

| libsanangeles.so | 0x002e20dd | GSFailure::update(StateMachine*) | — | COMPLETED | 100% | src/game/app/GSFailure.cpp |
| libsanangeles.so | 0x002d3be1 | MediaPlayerIPhone::playMovie(char const*) | — | COMPLETED | 100% | src/game/app/MediaPlayerIPhone.cpp |
| libsanangeles.so | 0x002d3be5 | MediaPlayerIPhone::stopMovie() | — | COMPLETED | 100% | src/game/app/MediaPlayerIPhone.cpp |

| libsanangeles.so | 0x00321699 | SceneNodeManager::manage(int, LevelObject*, int) | — | COMPLETED | 100% | src/game/world/SceneNodeManager.cpp |
| libsanangeles.so | 0x00306d2d | SpawnPoint::hasCloseNeighbors() const | — | COMPLETED | 100% | src/game/world/SpawnPoint.cpp |
| libsanangeles.so | 0x00328b41 | Map::setMap(Map::eMapType) | — | COMPLETED | 100% | src/game/world/Map.cpp |

| libsanangeles.so | 0x003219cd | SceneNodeManager::drop(int, irr::scene::ISceneNode const*) | — | BLOCKED | One unchanged current-context replay reproduces the historical bytes; strict target fails, all old checks retained; no further forms | src/game/world/SceneNodeManager.cpp |
| libsanangeles.so | 0x003065e5 | SpawnPoint::CreateAllSpawnInstances() | hud_glyphs | BLOCKED | 327/336 bytes (unmatched) | src/game/world/SpawnPoint.cpp |

| libsanangeles.so | 0x003160d9 | GameObjectManager::getAttackableTarget(Character*) | hud_glyphs | BLOCKED | canonical context unchanged; no credit | src/game/world/GameObjectManager.cpp |
| libsanangeles.so | 0x00328c49 | Map::draw() const | lock_init | BLOCKED | 294/304 bytes; original-order trial unchanged | src/game/world/Map.cpp |
| libsanangeles.so | 0x003218d9 | SceneNodeManager::reclaimGarbage() | — | BLOCKED | One unchanged current-context replay reproduces the historical bytes; strict target fails, all old checks retained; no further forms | src/game/world/SceneNodeManager.cpp |

Coordinator authorizes one unchanged-best integrated-context replay for each parked SceneNodeManager getPoolID, drop and reclaimGarbage after the exact bool manage implementation/header refinement. If needed, one combined original-address method-order trial is allowed with every existing function byte check. No further source search. Map::draw receives only one original-address method-order comparison using its proven typed layout and exact setMap. These are bounded context escalations, not reopened unbounded searches.

| libsanangeles.so | 0x00315f39 | GameObjectManager::getDistanceFromAttackableTarget(Character*, int, LevelObject*, bool) | hud_glyphs | BLOCKED | canonical context unchanged; no credit | src/game/world/GameObjectManager.cpp |

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

| libsanangeles.so | 0x002ff181 | NPC::_detect() | hud_glyphs | BLOCKED | 1100/1104-byte candidate; three distinct forms identical | src/game/ai/NPC.cpp |

| libsanangeles.so | 0x0031dc7d | ContactFilter::ShouldCollide(b2Shape*, b2Shape*) | — | BLOCKED | Six old forms reviewed; faithful unhinted candidate is 1,084 versus 1,100 bytes. Corrected forms already model actual APIs and native custom filtering; no new source gap found. | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x003179d5 | LevelObject::CastRay(vector3df const&, vector3df const&, vector3df&, vector3df&, LevelObject*&, bool) | hud_glyphs | BLOCKED | 1484/1504 bytes; unchanged-context replay stopped | src/game/world/LevelObject.cpp |

| libsanangeles.so | 0x0034b6f5 | std::__stl_throw_out_of_range(char const*) | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0031ad31 | PhysicAttributes::SetHeightAttributes(vector3df const&, PhysicInfo*) | lock_init | BLOCKED | 1400/1388-byte candidate; six forms exhausted | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x0030d149 | Vehicle::CreateWheels(Box2DUserInfo*) | hud_glyphs | BLOCKED | 1440/1408-byte candidate; six forms exhausted | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x00319ed5 | PhysicAttributes::LoadArrays(char*) | — | COMPLETED | 100% | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x00313385 | Vehicle::collision(vector3df, int) | — | BLOCKED | 1354/1360 bytes; six forms exhausted, no credit | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x0030ff41 | Vehicle::Load(Structs::Car const&) | — | BLOCKED | All7 conversions scalar; SceneCamera boundary inapplicable. Sixforms/threeequivalent outputs1380/native1368 confirmed; currentprivateprereqs absent but no new authentic API cause. No replay. | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x00320ca1 | PhysicAttributes::ComputeShortestPath(int, int, vector3df, vector3df, float) | — | BLOCKED | One quotient-width follow-up worsens 1688 to 1692/native1668 bytes and retains extension/scaling sequences; constructor96 weak unchanged, no link or credit. Preserve original best; see nonmatching/characters/ComputeShortestPath.md. | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x003116dd | Vehicle::stepPhysic() | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x0031cf75 | PhysicAttributes::GetNextRandomPos(int, int, vector3df) | lock_init | BLOCKED | 1732/1748-byte candidate; six forms exhausted | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x00301a75 | PlayerTest::switchContext(eContext, bool) | — | BLOCKED | One current-layout/NDK-enum replay emits884/native900 bytes; only target newly emitted, prelink3, no owner linked proof. See nonmatching/ai/PlayerTest-switchContext.md. | src/game/ai/PlayerTest.cpp |

| libsanangeles.so | 0x0031e285 | PhysicAttributes::AddCollisionShapes(int, unsigned short) | — | BLOCKED | Native-order/reference corrections materialize, but the candidate remains 1,820 versus 1,816 native bytes. Strict linking fails; all artifacts retained, no further variant authorized. | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x00303bb9 | PlayerTest::switchAnim() | — | BLOCKED | Six forms exhausted; best 1088/1072. Historical gate terminal with 66 successful profiles and one unresolved GameObjectManager fresh-link failure. Current canonical fields add no new ABI/helper evidence; no replay. | src/game/ai/PlayerTest.cpp |

| libsanangeles.so | 0x0030406d | PlayerTest::updateCarInteraction() | — | BLOCKED | 1684-byte candidate not matched; six forms; full 74-profile old gate passed | src/game/ai/PlayerTest.cpp |

| libsanangeles.so | 0x002ff5d1 | NPC::attackTarget() | — | BLOCKED | 2088/2108-byte candidate; six forms exhausted | src/game/ai/NPC.cpp |

| libsanangeles.so | 0x0034bf8d | StringManager::~StringManager() | — | COMPLETED | 100%; real240/240/248B family, authentic erase and whole-profile inline80; full190-profile gate and66-build helper closure exact | src/game/persistence/StringManager.cpp |

| libsanangeles.so | 0x002ed8ad | Widgets::Mission::UpdateLocalization() | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |

| libsanangeles.so | 0x002eb12d | Menus::ServiceCarRental::Update() | lock_init | BLOCKED | 816-byte candidate unmatched; six forms; one private baseline link incomplete | src/game/ui/MenuState.cpp |

| libsanangeles.so | 0x002eac65 | Menus::OptionGameSettings::Notify | — | BLOCKED | Map follow-up finds only one eligible pair of localization tails, with native type-body order already preserved. The unproven upstream receiver allocation R1/R1 versus native R2/R1 remains; no measured alternative peer ordering or new source proposal. | src/game/ui/MenuState.cpp (private) |

| libsanangeles.so | 0x002e4e7d | MenuManager::update(StateMachine*) | — | BLOCKED | 872-byte candidate unmatched; six forms; rejected two old MenuState regressions | src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x002e51fd | MenuManager::setText(eText, char const*, int*) | — | BLOCKED | Read-only typed switch recovery confirms SP80 is destroyed before SP40 construction; no missing lifetime or ABI operation. Candidate remains 1100/native 1104. Project metadata rolled back; no sixth source form justified. | src/game/ui/MenuManager.cpp |

| libsanangeles.so | 0x00344821 | SaveGame::SampleAndSave(char const*) | lock_init | BLOCKED | 1384/1388 bytes; swapped independent STR/MOV pair; five forms parked | src/game/persistence/SaveGame.cpp |

| libsanangeles.so | 0x002e574d | MenuManager::setup(bool) | — | BLOCKED | Native-size1792 retains50 differing bytes in spills/initialization; all previous owning/data checks pass. Dump-only compilation proves unchanged bytes and locates differences at global reload/final scheduling; no missing helper identified. Reproducible source preserved. | src/game/ui/MenuManager.cpp |

| libsanangeles.so | 0x0033ddd5 | ScriptManager::loadCommand(DataStream&) | — | BLOCKED | three hint forms2440/2436; strict overlap4B; corrected aggregate selectors, no credit | src/game/scripting/ScriptManager.cpp |

| libsanangeles.so | 0x003026b9 | PlayerTest::move(float, float) | hud_registration | BLOCKED | final 2512/2496 bytes; six forms, strict photo overlap; old header/photo graph exact | src/game/ai/PlayerTest.cpp |

| libsanangeles.so | 0x002ffe0d | NPC::Update(int) | — | BLOCKED | Six forms exhausted; best3024/3012. Current audit finds all51 function bindings and92 external calls/modes already native. Separate36-profile header gate does not prove candidate; combined link terminal/discarded NPC definition. No new replay justified. | src/game/ai/NPC.cpp |

| libsanangeles.so | 0x00320351 | ContactListener::Add(b2ContactPoint const*) | lock_init | BLOCKED | best extent 2364/2384 bytes; six forms; header sweep 43/44, known fixture incomplete | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x0039c751 | dump_memory_stats(char const*, int, char const*) | — | COMPLETED | 100% | src/game/core/utility.cpp |

| libsanangeles.so | 0x003935bd | png_memset(void*, unsigned char, int) | — | COMPLETED | 100% | src/game/core/png_helper.cpp |

| libsanangeles.so | 0x003935c9 | png_memcpy(void*, void const*, int) | — | COMPLETED | 100% | src/game/core/png_helper.cpp |

| libsanangeles.so | 0x003935d5 | png_memcmp(void const*, void const*, int) | — | COMPLETED | 100% | src/game/core/png_helper.cpp |

| libsanangeles.so | 0x003935e1 | png_strlen(char const*) | — | COMPLETED | 100% | src/game/core/png_helper.cpp |

| libsanangeles.so | 0x002fd291 | Lock::render() | coordinator | BLOCKED | 304-byte candidate unmatched; six forms; old 8 functions and 10 section/region checks exact | src/game/core/Lock.cpp |

| libsanangeles.so | 0x0034a015 | ASprite::PaintFModule(int, int, int, int, int) const | — | BLOCKED | bounded canonical record trial remains unmatched; frozen private proof reviewed; no credit | src/game/rendering/ASprite.cpp |

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

| libsanangeles.so | 0x00349315 | FSelect(float, float, float) | — | BLOCKED | two hints and one crossjumping-pass diagnostic failed; original32B still differs2bytes; oldcaller21/22 exact, no credit | src/game/app/IPhone.cpp |

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
| libsanangeles.so | 0x00317fb5 | LevelObject::canGoToPoint(vector3df const&, vector3df&, vector3df&) | hud_registration | BLOCKED | bounded3forms identical3120B,3032equal; current sibling/callers pass; no credit | src/game/world/LevelObject.cpp |
| libsanangeles.so | 0x00330015 | Rocket::launch(vector3df) | — | BLOCKED | one current-interface unchanged replay744B,125bytes differ; old39checks pass; no credit | src/game/combat/Rocket.cpp |
| libsanangeles.so | 0x00304ec9 | PlayerTest::Update() | — | BLOCKED | Prerequisite-only current gate passed all 190 profiles/10,687 comparisons with 11 layout assertions. Unchanged safe-v4 current-context body compiled to 2192/2228 bytes; strict extent failed, stopped before linking. Native SetSpeed weak/default versus current global/default is new independently verified ABI evidence. Weak-declaration gate passed 190/10,687; unchanged replay emits 2200/2228 bytes, with actual GOT relocation restored. Stopped pre-link; no source variations or shared event constructor edits. | src/game/ai/PlayerTest.cpp (private) |
| libsanangeles.so | 0x00312081 | Vehicle::_processAIFlags() | — | BLOCKED | Current unchanged safe3060/3220 identical archive; old188/112 and complete76-build header closure2587 functions/2821 regions exact; fixture failures resolved, no credit | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00313b01 | Vehicle::Update(int) | — | BLOCKED | six forms; best4040/4020; old188/112 and 48-profile header gate pass; no credit | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x003215b5 | SceneNodeManager::crc(char const*) const (existing-match regression) | — | COMPLETED | 100% (independent initialization order restored under renderer alias; no new credit) | src/game/world/SceneNodeManager.cpp |

| libsanangeles.so | 0x002dd33d | OctTreeAABB::OctTreeAABBNode::getPolysIter (const box and three output arrays) | — | BLOCKED | Const-SDK context also identical616/native620; both accessor trials parked without integration or credit | src/game/rendering/GS3DStuff.cpp |

| libsanangeles.so | 0x002e078d | GS3DStuff::update(StateMachine*) | — | BLOCKED | one unchanged context replay; 4 instruction/21 GOT differences in GC diagnostic; old destructor overlap blocks integration | src/game/rendering/GS3DStuff.cpp |

| libsanangeles.so | 0x002ddf79 | GS3DStuff::CreateStaticBodies | — | BLOCKED | Prerequisite190/10917 pass. One canonical compoundposition trial1568/native1580, frame180/native172, realordinaryquaternionC1helper28 emitted. Stopped pre-link; no helperoverride/forcedinline/credit. | src/game/rendering/GS3DStuff.cpp |

| libsanangeles.so | 0x002dd7e1 | GS3DStuff::updateVisibility(unsigned int) | — | BLOCKED | six forms; native-size1944 still differs; accessor header regresses Cash; no credit | src/game/rendering/GS3DStuff.cpp |

| libsanangeles.so | 0x002dfb15 | GS3DStuff::load(int, int&) | — | BLOCKED | six forms; best2568/2576; target/switch differ; Cash header regression and LevelObject link overlap; no credit | src/game/rendering/GS3DStuff.cpp |

| libsanangeles.so | 0x0030c035 | Vehicle::step() | — | BLOCKED | five forms; best4320/4372 frame612/620; old188/112 exact; no credit | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x0031eb99 | PhysicAttributes::GetHeight(int, vector3df const&, bool, bool) | — | BLOCKED | six forms; nearest4992/5038; old37/9 and all30 baseline header profiles pass; no credit | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x0030d6c9 | Vehicle::UpdatePhysic(float) | — | BLOCKED | six forms; best9116/9212, native412B frame; old188/112 and all95 header profiles exact; no credit | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x00339cb9 | Script::executeCommand(Structs::ScriptCommand const*, int, int) | — | BLOCKED | five forms;12384/12636, frame324/332; old/support exact and93 baseline header profiles pass; buffer extent provisional; no credit | src/game/scripting/Script.cpp |

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
| libsanangeles.so | 0x00349445 | `_ZN10AnimObject10IsAnimOverEv` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/animobject-over-negative-likelihood-current/src/game/characters/AnimObject.cpp |
| libsanangeles.so | 0x00300bc5 | `_ZN4Path4LoadERKN7Structs4PathEPN3irr7collada15CColladaFactoryE` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/path-load-vector-assignment-current/src/game/world/Path.cpp |
| libsanangeles.so | 0x0033ffc1 | `_ZN13ScriptManager12cleanCommandEPN7Structs13ScriptCommandE` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/script-clean-command-separate-cases-current/src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0034a015 | `_ZNK7ASprite12PaintFModuleEiiiii` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/asprite-paint-fmodule-canonical-current/src/game/rendering/ASprite.cpp |
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
| libsanangeles.so | 0x0034228d | `_ZN13NPCController7onEventEPK6IEventPK12EventManager` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/npc-controller-event-switch-current/src/game/ai/NPCController.cpp |
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
| libsanangeles.so | 0x0030b68d | `_ZN7Vehicle17ResetBodyPositionEv` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/vehicle-reset-body-position-box2d-current/src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x002eac65 | `_ZN5Menus18OptionGameSettings6NotifyEPK10MenuWidgeti` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/option-game-settings-member-getter-current/src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002eb6a9 | `_ZN5Menus17ServiceCorruption6NotifyEPK10MenuWidgeti` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/service-corruption-full-typed-current/src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x00349e15 | `_ZNK7ASprite11PaintModuleEiiii` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/asprite-paint-module/src/game/rendering/ASprite.cpp |
| libsanangeles.so | 0x003efced | `_ZN8RenderFX11UpdateInputEii` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/renderfx-update-input-typed-current/src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x0034b3c5 | `_ZNK13StringManager12formatAmountEibb` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/stringmanager-format-amount-separate-cases-current/src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x00341a3d | `_ZN20CopVehicleController7onEventEPK6IEventPK12EventManager` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/cop-vehicle-on-event/src/game/ai/CopVehicleController.cpp |
| libsanangeles.so | 0x0030fac9 | `_ZN7Vehicle10CreateBodyEv` | — | BLOCKED | Corrected 1060 / native 1044 bytes; unlinked, no credit | _scratch/vehicle-create-body-sixth-current/src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x003f01d1 | `_ZN6MenuFX15GetStateHandlerEPN7gameswf9characterE` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/menufx-state-handler-typed-current/src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x00320ca1 | `_ZN16PhysicAttributes19ComputeShortestPathEiiN3irr4core8vector3dIfEES3_f` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/physics-shortest-current-replay/src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x002ff5d1 | `_ZN3NPC12attackTargetEv` | — | BLOCKED | Paired target bytes/relocations unchanged; unlinked, no credit | _scratch/npc-attack-target/src/game/ai/NPC.cpp |
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
