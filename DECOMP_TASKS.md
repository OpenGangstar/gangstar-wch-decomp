# Decompilation function registry

The main Codex agent records assignments and releases ownership after review
and acceptance. Use the binary, address, and function name to identify each
entry. Follow the workflow in [AGENTS.md](AGENTS.md).

| Binary/library | Address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | ---: | --- |
| libsanangeles.so | 0x00301091 | PlayerTest::setClosestShop(Shop*) | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00332f95 | CameraManager::tappedTarget | — | COMPLETED | 100% | src/game/core/CameraManager.cpp |
| libsanangeles.so | 0x00334a81 | LockCamera::init | lock_init | BLOCKED | — | src/game/core/LockCamera.cpp |
| libsanangeles.so | 0x003351dd | VehicleCamera::goToSide | vehicle_side | BLOCKED | — | src/game/vehicles/VehicleCamera.cpp |
| libsanangeles.so | 0x00333095 | CameraManager::processTouchRelease | — | COMPLETED | 100% | src/game/core/CameraManager.cpp |
| libsanangeles.so | 0x003340c1 | FPSCamera::exit | — | COMPLETED | 100% | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x0033530d | VehicleCamera::init | — | COMPLETED | 100% | src/game/vehicles/VehicleCamera.cpp |
| libsanangeles.so | 0x00305ccd | Shop::triggered | — | COMPLETED | 100% | src/game/ui/Shop.cpp |
| libsanangeles.so | 0x00301759 | PlayerTest::justStoleCar | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00332cf5 | CameraManager::getClickedTarget | camera_tap | REVIEW | — | src/game/core/CameraManager.cpp |
| libsanangeles.so | 0x003336ad | FollowCamera::getFacing | vehicle_side | BLOCKED | — | src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x00335769 | VehicleCamera::getFacing | vehicle_side | BLOCKED | — | src/game/vehicles/VehicleCamera.cpp |
| libsanangeles.so | 0x00333f71 | FPSCamera::enter | — | COMPLETED | 100% | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x00333fed | FPSCamera::init | — | COMPLETED | 100% | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x00305e29 | Shop::trigger | — | COMPLETED | 100% | src/game/ui/Shop.cpp |
| libsanangeles.so | 0x003344f5 | FPSCamera::update | — | COMPLETED | 100% | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x003339bd | FollowCamera::goBehind | — | COMPLETED | 100% | src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x00305cd5 | Shop::getId | — | COMPLETED | 100% | src/game/ui/Shop.cpp |
| libsanangeles.so | 0x003342ad | FPSCamera::zoom (touch list) | — | COMPLETED | 100% | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x0033560d | VehicleCamera::updatePosition | — | COMPLETED | 100% | src/game/vehicles/VehicleCamera.cpp |
| libsanangeles.so | 0x00333e41 | FPSCamera::scroll (touch list) | camera_tap | BLOCKED | — | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x002e3c1d | GSWeaponShopMenu::dtor | — | COMPLETED | 100% | src/game/ui/GSWeaponShopMenu.cpp |
| libsanangeles.so | 0x00335849 | VehicleCamera::update | vehicle_side | REVIEW | — | src/game/vehicles/VehicleCamera.cpp |
| libsanangeles.so | 0x00334389 | FPSCamera::updateTouchInputs | camera_tap | REVIEW | — | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x002e3c49 | GSWeaponShopMenu::ctor | — | COMPLETED | 100% | src/game/ui/GSWeaponShopMenu.cpp |
| libsanangeles.so | 0x00333451 | FollowCamera::updatePosition | — | COMPLETED | 100% | src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x00332771 | CameraManager::update | camera_tap | REVIEW | — | src/game/core/CameraManager.cpp |
| libsanangeles.so | 0x00301a3d | PlayerTest::Stop | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00333789 | FollowCamera::init | — | COMPLETED | 100% | src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x00333ab1 | FollowCamera::update | vehicle_side | REVIEW | — | src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x002e1571 | GSCarRepairMenu::draw2d | lock_init | BLOCKED | — | src/game/ui/GSCarRepairMenu.cpp |
| libsanangeles.so | 0x00334c25 | LockCamera::update | camera_tap | BLOCKED | — | src/game/core/LockCamera.cpp |
| libsanangeles.so | 0x003017ed | PlayerTest::jumpFinished | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301821 | PlayerTest::driftFinished | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301855 | PlayerTest::addDistanceDriven | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301ebd | PlayerTest::setLastUsedVehicle | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003017b1 | PlayerTest::onTargetReached | camera_tap | BLOCKED | — | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003018d1 | PlayerTest::setAnim | camera_tap | BLOCKED | — | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301f69 | PlayerTest::SetSpeed | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003019c9 | PlayerTest::stopMoving | vehicle_side | REVIEW | — | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00302685 | PlayerTest::UpdateSceneNode | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003013bd | PlayerTest::ResetPlayerTest | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301f01 | PlayerTest::setVehicle | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003025cd | PlayerTest::isFacingTarget | camera_tap | BLOCKED | — | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x002f42cd | Character::updatePosition | lock_init | REVIEW | — | src/game/characters/Character.cpp |
| libsanangeles.so | 0x00301911 | PlayerTest::initDriving | vehicle_side | BLOCKED | — | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00334fe9 | SceneCamera::Load | camera_tap | BLOCKED | — | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x0031ff49 | PhysicAttributes::GetHeight (position overload) | lock_init | BLOCKED | — | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x00334fa1 | SceneCamera::SceneCamera (C1/C2 aliases) | — | COMPLETED | 100% | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x00334f71 | SceneCamera::~SceneCamera (D1/D2 aliases) | — | COMPLETED | 100% | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x0031a67d | PhysicAttributes::IsPositionOnJump | lock_init | BLOCKED | — | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x00334f29 | SceneCamera::~SceneCamera (D0) | — | COMPLETED | 100% | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x00334f5c | SceneCamera::~SceneCamera (D1 thunk) | — | COMPLETED | 100% | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x00334f14 | SceneCamera::~SceneCamera (D0 thunk) | — | COMPLETED | 100% | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x00334ee5 | SceneCamera::init | — | COMPLETED | 100% | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x00334ee9 | SceneCamera::debug | — | COMPLETED | 100% | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x00334eed | SceneCamera::update | — | COMPLETED | 100% | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x0031ccf1 | PhysicAttributes::SetCurrentJumpShape | lock_init | REVIEW | — | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x00301df9 | PlayerTest::finishedStopDriving | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301261 | PlayerTest::_SetTarget | camera_tap | REVIEW | — | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x0030142d | PlayerTest::applyDamage | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301eec | PlayerTest::setVehicle (secondary thunk) | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301a28 | PlayerTest::Stop (secondary thunk) | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301418 | PlayerTest::applyDamage (secondary thunk) | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301101 | PlayerTest::getCarAnimName | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003015e5 | PlayerTest::~PlayerTest (D1/D2 aliases) | lock_init | BLOCKED | — | src/game/ai/PlayerTest.cpp |
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
| libsanangeles.so | 0x00349271 | TrailMgr::Render | vehicle_side | BLOCKED | — | src/game/world/TrailMgr.cpp |
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
| libsanangeles.so | 0x00348a61 | Trail::AddPoint | camera_tap | REVIEW | — | src/game/world/Trail.cpp |
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
| libsanangeles.so | 0x0034f555 | CarSounds::UpdateOffEngineSounds | lock_init | BLOCKED | — | src/game/vehicles/CarSounds.cpp |
| libsanangeles.so | 0x0034f785 | CarSounds::UpdateOnEngineSounds | vehicle_side | BLOCKED | — | src/game/vehicles/CarSounds.cpp |
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
| libsanangeles.so | 0x0030b68d | Vehicle::ResetBodyPosition | lock_init | BLOCKED | — | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00311fb5 | CustomSkinnedMeshSceneNode::~CustomSkinnedMeshSceneNode (D1) | camera_tap | BLOCKED | — | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030bccd | Vehicle::setSpeed | lock_init | BLOCKED | — | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00310499 | Vehicle::grabSceneNode | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030fac9 | Vehicle::CreateBody | lock_init | BLOCKED | — | src/game/vehicles/Vehicle.cpp |
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
| libsanangeles.so | 0x0032cf95 | EvWheelTurn::~EvWheelTurn (D1) | — | COMPLETED | 100% | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x0032cfcd | Wheel::processTouch | vehicle_side | BLOCKED | — | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x0032ccf5 | Wheel::draw2d | — | COMPLETED | 100% | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x0032cf69 | EvWheelReleased::~EvWheelReleased (D0) | — | COMPLETED | 100% | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x0032d18d | EvWheelTurn::~EvWheelTurn (D0) | — | COMPLETED | 100% | src/game/vehicles/Wheel.cpp |
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
| libsanangeles.so | 0x00305f5d | Shop::Update | lock_init | BLOCKED | — | src/game/ui/Shop.cpp |
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
| libsanangeles.so | 0x002ea479 | Menus::MainMenu::Notify | vehicle_side | BLOCKED | — | src/game/ui/MenuState.cpp |
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
| libsanangeles.so | 0x002e8655 | MenuState::Hide | camera_tap | BLOCKED | — | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e7cfd | MenuState::UpdateLocalization | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e79d5 | Menus::InfoStatistics::OnFSCommand | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e7a25 | Menus::InfoAchievements::OnFSCommand | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e7a75 | Menus::InfoAbout::OnFSCommand | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002eab21 | Menus::Infos::Update | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e8639 | Menus::Map::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e90cd | Menus::Map::GotFocus | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002ebb31 | Menus::Map::Update | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e8551 | MenuState::OnEvent | vehicle_side | BLOCKED | — | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e7659 | Menus::Achievement::Update | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e7d51 | Menus::Achievement::SetAchievement | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002ea2e5 | Menus::Achievement::Show | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e7815 | Menus::InGameMenu::Notify | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002eb085 | Menus::OptionVolumes::Notify | lock_init | BLOCKED | — | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002eb6a9 | Menus::ServiceCorruption::Notify | vehicle_side | BLOCKED | — | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e78ad | Menus::Map::Notify | camera_tap | BLOCKED | — | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002eb921 | Menus::ServiceWeaponShop::Notify | lock_init | BLOCKED | — | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e76e9 | RenderFX::Event::GetCharacterPath | vehicle_side | ASSIGNED | — | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002ea7f5 | Menus::Infos::Notify | camera_tap | ASSIGNED | — | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002eb9dd | Menus::ServiceMissions::Notify | lock_init | ASSIGNED | — | src/game/ui/MenuState.cpp |
