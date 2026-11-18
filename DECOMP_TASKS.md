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
| libsanangeles.so | 0x00334389 | FPSCamera::updateTouchInputs | camera_tap | BLOCKED | — | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x002e3c49 | GSWeaponShopMenu::ctor | — | COMPLETED | 100% | src/game/ui/GSWeaponShopMenu.cpp |
| libsanangeles.so | 0x00333451 | FollowCamera::updatePosition | — | COMPLETED | 100% | src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x00332771 | CameraManager::update | camera_tap | BLOCKED | — | src/game/core/CameraManager.cpp |
| libsanangeles.so | 0x00301a3d | PlayerTest::Stop | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00333789 | FollowCamera::init | — | COMPLETED | 100% | src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x00333ab1 | FollowCamera::update | vehicle_side | BLOCKED | — | src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x002e1571 | GSCarRepairMenu::draw2d | lock_init | BLOCKED | — | src/game/ui/GSCarRepairMenu.cpp |
| libsanangeles.so | 0x00334c25 | LockCamera::update | camera_tap | BLOCKED | — | src/game/core/LockCamera.cpp |
| libsanangeles.so | 0x003017ed | PlayerTest::jumpFinished | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301821 | PlayerTest::driftFinished | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301855 | PlayerTest::addDistanceDriven | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301ebd | PlayerTest::setLastUsedVehicle | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003017b1 | PlayerTest::onTargetReached | camera_tap | BLOCKED | — | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003018d1 | PlayerTest::setAnim | camera_tap | BLOCKED | — | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301f69 | PlayerTest::SetSpeed | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003019c9 | PlayerTest::stopMoving | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00302685 | PlayerTest::UpdateSceneNode | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003013bd | PlayerTest::ResetPlayerTest | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301f01 | PlayerTest::setVehicle | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003025cd | PlayerTest::isFacingTarget | camera_tap | BLOCKED | — | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x002f42cd | Character::updatePosition | — | COMPLETED | 100% | src/game/characters/Character.cpp |
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
| libsanangeles.so | 0x0031ccf1 | PhysicAttributes::SetCurrentJumpShape | — | COMPLETED | 100% | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x00301df9 | PlayerTest::finishedStopDriving | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301261 | PlayerTest::_SetTarget | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x0030142d | PlayerTest::applyDamage | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301eec | PlayerTest::setVehicle (secondary thunk) | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301a28 | PlayerTest::Stop (secondary thunk) | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301418 | PlayerTest::applyDamage (secondary thunk) | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301101 | PlayerTest::getCarAnimName | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003015e5 | PlayerTest::~PlayerTest (D1/D2 aliases) | lock_init | BLOCKED | private family exact; coherent photo regression blocks integration | src/game/ai/PlayerTest.cpp |
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
| libsanangeles.so | 0x00311fb5 | CustomSkinnedMeshSceneNode::~CustomSkinnedMeshSceneNode (D1) | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
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
| libsanangeles.so | 0x002e76e9 | RenderFX::Event::GetCharacterPath | vehicle_side | BLOCKED | — | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002ea7f5 | Menus::Infos::Notify | camera_tap | BLOCKED | — | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002eb9dd | Menus::ServiceMissions::Notify | lock_init | BLOCKED | — | src/game/ui/MenuState.cpp |
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
| libsanangeles.so | 0x002d2edd | LODSceneNode::GetMeshTransformedBoundingBox | camera_tap | BLOCKED | — | src/game/rendering/LODSceneNode.cpp |
| libsanangeles.so | 0x002d2d61 | LODSceneNode::computeLODLevel | lock_init | BLOCKED | — | src/game/rendering/LODSceneNode.cpp |
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
| libsanangeles.so | 0x002f800d | CustomBillboardSceneNode::OnAnimate | vehicle_side | BLOCKED | — | src/game/rendering/CustomBillboardSceneNode.cpp |
| libsanangeles.so | 0x002f7ff8 | CustomBillboardSceneNode::OnAnimate (thunk) | vehicle_side | REVIEW | — | src/game/rendering/CustomBillboardSceneNode.cpp |
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
| libsanangeles.so | 0x002df34d | GS3DStuff::SetAlpha | camera_tap | BLOCKED | — | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002de5a5 | GS3DStuff::AddToSceneMgr | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002db549 | GS3DStuff::loadPerformanceProfile | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002dbde5 | GS3DStuff::setPerformanceType | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002de919 | GS3DStuff::unload | — | COMPLETED | 100% | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002dc715 | GS3DStuff::checkVehicleProximity | camera_tap | BLOCKED | — | src/game/rendering/GS3DStuff.cpp |
| libsanangeles.so | 0x002deba1 | GS3DStuff::checkPickableProximity | lock_init | BLOCKED | — | src/game/rendering/GS3DStuff.cpp |
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
| libsanangeles.so | 0x00334ef1 | SceneCamera.cpp::__tcf_1 | — | COMPLETED | 100% | src/game/core/SceneCamera.cpp |
| libsanangeles.so | 0x0034934d | AnimObject::Reset | — | COMPLETED | 100% | src/game/characters/AnimObject.cpp |
| libsanangeles.so | 0x00349445 | AnimObject::IsAnimOver | vehicle_side | BLOCKED | — | src/game/characters/AnimObject.cpp |
| libsanangeles.so | 0x003f01d1 | MenuFX::GetStateHandler | lock_init | BLOCKED | — | src/game/ui/menufx.cpp |
| libsanangeles.so | 0x0032cfb8 | Wheel::processTouch secondary thunk | camera_tap | REVIEW | — | src/game/vehicles/Wheel.cpp |
| libsanangeles.so | 0x00300bc5 | Path::Load | vehicle_side | BLOCKED | — | src/game/world/Path.cpp |
| libsanangeles.so | 0x0034228d | NPCController::onEvent | camera_tap | BLOCKED | — | src/game/ai/NPCController.cpp |
| libsanangeles.so | 0x003511b9 | CSoundDecoderMSADPCM::Init | lock_init | BLOCKED | — | src/game/audio/CSoundDecoderMSADPCM.cpp |
| libsanangeles.so | 0x0032d72d | CControlManager::update | vehicle_side | BLOCKED | — | src/game/input/CControlManager.cpp |
| libsanangeles.so | 0x00354665 | EventManager::_attach | camera_tap | BLOCKED | — | src/game/scripting/EventManager.cpp |
| libsanangeles.so | 0x00354725 | EventManager::_detach | camera_tap | BLOCKED | — | src/game/scripting/EventManager.cpp |
| libsanangeles.so | 0x0031b29d | PhysicAttributes::PhysicAttributes (C1/C2 aliases) | lock_init | BLOCKED | — | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x002f2581 | Character::goToCombatIdle | lock_init | BLOCKED | — | src/game/characters/Character.cpp |
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
| libsanangeles.so | 0x00346f55 | SideMission::isInCheckpointsRange | vehicle_side | BLOCKED | — | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00346d1d | SideMission::start | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00346b8d | SideMission::finished | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00346e55 | SideMission::getCheckpoints | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x00346f9d | SideMission::disableCheckpoints | — | COMPLETED | 100% | src/game/missions/SideMission.cpp |
| libsanangeles.so | 0x003470f9 | SideMission::enableCheckpoints | lock_init | BLOCKED | — | src/game/missions/SideMission.cpp |
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
| libsanangeles.so | 0x0033f4c9 | ScriptManager::checkScreenPress | camera_tap | BLOCKED | — | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033fc01 | ScriptManager::getAvailableMissionScripts | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033ef8d | ScriptManager::loadScript | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033f0f9 | ScriptManager::moveObject | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033ed95 | ScriptManager::resetGame | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033fcb1 | ScriptManager::unload | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033fda9 | ScriptManager::tearDown | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033ffc1 | ScriptManager::cleanCommand | vehicle_side | BLOCKED | — | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033fe71 | ScriptManager::draw | — | COMPLETED | 100% | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033f1ed | ScriptManager::setState | vehicle_side | BLOCKED | — | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x0033f511 | ScriptManager::update | camera_tap | BLOCKED | — | src/game/scripting/ScriptManager.cpp |
| libsanangeles.so | 0x00339385 | Script destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x003392a1 | Script constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x003399c5 | Script::clearScriptObjectAction | — | COMPLETED | 100% | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x0033999d | Script::setScriptObjectAction | — | COMPLETED | 100% | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x0033922d | Script::setState | vehicle_side | BLOCKED | — | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x003398b5 | Script::unsetScriptObjectAction | camera_tap | BLOCKED | — | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x0033ce19 | Script::nextCommand | lock_init | BLOCKED | — | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x003399f1 | Script::rewind | vehicle_side | BLOCKED | — | src/game/scripting/Script.cpp |
| libsanangeles.so | 0x003365a5 | Mission::idle | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x00335d8d | Mission::fail | — | COMPLETED | 100% | src/game/missions/Mission.cpp |
| libsanangeles.so | 0x00336345 | Mission::message | camera_tap | BLOCKED | — | src/game/missions/Mission.cpp |
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
| libsanangeles.so | 0x0032c851 | WantedMeter::update | vehicle_side | BLOCKED | — | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032ae69 | Reward constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/missions/Reward.cpp |
| libsanangeles.so | 0x0032c8b5 | WantedMeter deleting destructor (D0) | — | COMPLETED | 100% | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032c8a0 | WantedMeter deleting destructor thunk (D0) | — | COMPLETED | 100% | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032c904 | WantedMeter complete destructor thunk (D1) | — | COMPLETED | 100% | src/game/missions/WantedMeter.cpp |
| libsanangeles.so | 0x0032c961 | WantedMeter constructor (C1/C2 aliases) | lock_init | BLOCKED | — | src/game/missions/WantedMeter.cpp |
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
| libsanangeles.so | 0x00342fb4 | WantedLevelManager::update non-virtual thunk | vehicle_side | REVIEW | — | src/game/missions/WantedLevelManager.cpp |
| libsanangeles.so | 0x003ed9a9 | RenderFX fscommand_callback_handler regression | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x00352cad | SoundManager::getNumberOfPlayingSounds | vehicle_side | BLOCKED | — | src/game/audio/SoundManager.cpp |
| libsanangeles.so | 0x0030b59d | Vehicle translation-unit initializer wrapper | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x003ee801 | RenderFX deleting destructor (D0) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ee885 | RenderFX destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ec961 | RenderFX::Initialize | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x0030b311 | Vehicle translation-unit initializer | vehicle_side | BLOCKED | — | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x003ee1ed | RenderFX::SetTexture | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ee721 | RenderFX::SearchIndex::Clear | lock_init | BLOCKED | — | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003edbd9 | RenderFX::PreloadGlyphs(char const*, char const*, int, bool, bool, gameswf::filter*) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003edc7d | RenderFX::PreloadGlyphs() | vehicle_side | BLOCKED | — | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ed9ed | RenderFX::PreloadGlyphs(unsigned short*, int, char const*, int, bool, bool, gameswf::filter*) | lock_init | BLOCKED | — | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003edde5 | RenderFX::Load | camera_tap | BLOCKED | — | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003eeb11 | RenderFX::SetMember(char const*, char const*, int) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003eea49 | RenderFX::SetMember(char const*, char const*, gameswf::as_value&) | vehicle_side | BLOCKED | — | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ed2f5 | RenderFX::DBG_TraceContextInformation | camera_tap | BLOCKED | — | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ece05 | RenderFX::ForceTexturesToVRAM | lock_init | BLOCKED | — | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ee98d | RenderFX::SetLocalVariable | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ed1bd | RenderFX::CollectCharacters | camera_tap | BLOCKED | — | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ecb09 | RenderFX::TraceHierarchy | camera_tap | BLOCKED | — | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x00327d85 | Cash destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327d41 | Cash deleting destructor (D0) | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327d2c | Cash deleting destructor thunk (D0) | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327d70 | Cash complete destructor thunk (D1) | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327bbd | Cash::update | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327db1 | Cash constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327a71 | Cash::drawCash | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327a29 | Cash::AlignRight | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327a4d | Cash::AlignLeft | — | COMPLETED | 100% | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327be9 | Cash::draw2d | vehicle_side | BLOCKED | — | src/game/ui/Cash.cpp |
| libsanangeles.so | 0x00327bd4 | Cash::draw2d non-virtual thunk | vehicle_side | REVIEW | — | src/game/ui/Cash.cpp |
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
| libsanangeles.so | 0x0032abd4 | RetroEffect::draw2d non-virtual thunk | camera_tap | REVIEW | — | src/game/rendering/RetroEffect.cpp |
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
| libsanangeles.so | 0x0032b665 | SlideControl::processTouch | vehicle_side | BLOCKED | — | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x0032b650 | SlideControl::processTouch non-virtual thunk | vehicle_side | REVIEW | — | src/game/ui/SlideControl.cpp |
| libsanangeles.so | 0x00326581 | AnalogStick constructor (C1/C2 aliases) | lock_init | BLOCKED | — | src/game/input/AnalogStick.cpp |
| libsanangeles.so | 0x00326d3d | AnalogStick::processTouchRelease | — | COMPLETED | 100% | src/game/input/AnalogStick.cpp |
| libsanangeles.so | 0x00326d28 | AnalogStick::processTouchRelease non-virtual thunk | — | COMPLETED | 100% | src/game/input/AnalogStick.cpp |
| libsanangeles.so | 0x003268e1 | AnalogStick::processTouch | camera_tap | BLOCKED | â€” | src/game/input/AnalogStick.cpp |
| libsanangeles.so | 0x003268cc | AnalogStick::processTouch non-virtual thunk | camera_tap | REVIEW | â€” | src/game/input/AnalogStick.cpp |
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
| libsanangeles.so | 0x0034cbc1 | TouchScreenBase::getTouchIDList | lock_init | BLOCKED | — | src/game/input/TouchScreenBase.cpp |
| libsanangeles.so | 0x0034c8c5 | TouchScreenBase::getTouchDisplacement | — | COMPLETED | 100% | src/game/input/TouchScreenBase.cpp |
| libsanangeles.so | 0x0034ccf1 | TouchScreenBase::touchBegan | vehicle_side | BLOCKED | — | src/game/input/TouchScreenBase.cpp |
| libsanangeles.so | 0x0034d989 | AccelerometerWin32 OnEvent | camera_tap | BLOCKED | — | src/game/input/AccelerometerWin32.cpp |
| libsanangeles.so | 0x0034d974 | AccelerometerWin32 OnEvent non-virtual thunk | camera_tap | BLOCKED | — | src/game/input/AccelerometerWin32.cpp |
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
| libsanangeles.so | 0x0032f201 | SniperControlHandler::onKeyboardEvent | camera_tap | BLOCKED | — | src/game/input/SniperControlHandler.cpp |
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
| libsanangeles.so | 0x002ecb01 | Widgets::Help::SetIcon | coordinator | BLOCKED | — | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ecbbd | Widgets::Achievement::SetIcon | coordinator | BLOCKED | — | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ecb9d | Widgets::IGMenu::GoToFrame | coordinator | BLOCKED | — | src/game/ui/MenuWidget.cpp |
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
| libsanangeles.so | 0x002ef6f5 | Widgets::Tutorial::UpdateLocalization | vehicle_side | BLOCKED | — | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ecd99 | Widgets::Volumes::Hide | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee409 | Widgets::Statistics::Show | lock_init | BLOCKED | — | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ef0b1 | Widgets::Corruption::UpdateLocalization | vehicle_side | BLOCKED | — | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ef415 | Widgets::Volumes::UpdateLocalization | camera_tap | BLOCKED | — | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee67d | Widgets::Achievements::SetCategory | lock_init | BLOCKED | — | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002edfbd | Widgets::ConfirmPayment::UpdateLocalization | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002edec1 | Widgets::Confirm::UpdateLocalization | vehicle_side | BLOCKED | — | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002eec15 | Widgets::Statistics::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee2c1 | Widgets::Statistics::UpdateLocalization | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee489 | Widgets::Achievements::UpdateLocalization | camera_tap | BLOCKED | — | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ee6ed | Widgets::Controls::UpdateLocalization | vehicle_side | BLOCKED | — | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ef901 | Widgets::Objective::OnEvent | lock_init | BLOCKED | — | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002eeda1 | Widgets::Achievements::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002efda5 | Widgets::Controls::OnEvent | vehicle_side | BLOCKED | — | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002ef9fd | Widgets::MainMenu::OnEvent | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002efafd | Widgets::GameSetting::OnEvent | camera_tap | BLOCKED | — | src/game/ui/MenuWidget.cpp |
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
| libsanangeles.so | 0x00343835 | Preferences::GetOrientation | lock_init | REVIEW | pending | src/game/ui/Preferences.cpp |
| libsanangeles.so | 0x002ee061 | Widgets::Dialog::OnEvent | vehicle_side | BLOCKED | pending | src/game/ui/MenuWidget.cpp |
| libsanangeles.so | 0x002e56b1 | MenuManager::updateLocalization | — | COMPLETED | 100% | src/game/hud/MenuManager.cpp |
| libsanangeles.so | 0x003437f1 | Preferences destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/ui/Preferences.cpp |
| libsanangeles.so | 0x002eab95 | Menus::Options::Notify | camera_tap | BLOCKED | pending | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x003437c9 | Preferences deleting destructor (D0) | — | COMPLETED | 100% | src/game/ui/Preferences.cpp |
| libsanangeles.so | 0x003438e5 | Preferences::SampleAndSave | lock_init | REVIEW | pending | src/game/ui/Preferences.cpp |
| libsanangeles.so | 0x002eb5d9 | Menus::Services::Notify | vehicle_side | BLOCKED | pending | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x00343a39 | Preferences::LoadAndApply | lock_init | BLOCKED | pending | src/game/ui/Preferences.cpp |
| libsanangeles.so | 0x002ea925 | Menus::InfoAchievements::Notify | camera_tap | BLOCKED | pending | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e8fe9 | Menus::ServiceMissions::GotFocus | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002eaa05 | Menus::InfoHelp::Notify | — | COMPLETED | 100% | src/game/ui/MenuState.cpp |
| libsanangeles.so | 0x002e86fd | MenuState::GotFocus | camera_tap | BLOCKED | pending | src/game/ui/MenuState.cpp |
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
| libsanangeles.so | 0x0034c119 | DataReloaderManager::checkFiles | vehicle_side | BLOCKED | pending | src/game/world/DataReloaderManager.cpp |
| libsanangeles.so | 0x002e2b19 | GSLoading::isGameLoaded | — | COMPLETED | 100% | src/game/app/GSLoading.cpp |
| libsanangeles.so | 0x002e2b2d | GSLoading::setGameLoaded | — | COMPLETED | 100% | src/game/app/GSLoading.cpp |
| libsanangeles.so | 0x0034b2c5 | StringManager::isPackLoaded | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b2d9 | StringManager::isPackSheetLoaded | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b315 | StringManager::switchPack | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b2f1 | StringManager::getNumberOfLoadedPack | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b619 | StringManager::unloadPack | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b351 | strRev | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b375 | strchrs | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b5a5 | StringManager::unloadPackSheet | vehicle_side | BLOCKED | pending | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b745 | StringManager constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034bb9d | StringManager::loadPack | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034bb5d | StringManager::getString | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b649 | Structs::TextStyle::Read | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b3c5 | StringManager::formatAmount | camera_tap | BLOCKED | pending | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034be9d | StringManager destructor (D1/D2 aliases) | lock_init | BLOCKED | pending | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034bd51 | StringManager::loadStyles | vehicle_side | BLOCKED | pending | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0034b78d | StringManager::loadPackSheet | lock_init | BLOCKED | pending | src/game/persistence/StringManager.cpp |
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
| libsanangeles.so | 0x002fe999 | NPC::freeze | camera_tap | BLOCKED | pending | src/game/ai/NPC.cpp |
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
| libsanangeles.so | 0x002f3231 | Character constructor (C1/C2 aliases) | — | COMPLETED | 100% tracked; private migration remains unintegrated | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f26ad | Character::ready | camera_tap | BLOCKED | pending | src/game/characters/Character.cpp |
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
| libsanangeles.so | 0x002f4465 | Character::initPhysic | lock_init | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f4a79 | Character::positionInVehicle | vehicle_side | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f1a31 | Character::getSpecificAnimation | camera_tap | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f517d | Character::switchCombatAnimation | lock_init | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f3489 | Character::updateAnimation | camera_tap | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f661d | Character::switchMoveAnimation | lock_init | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f55d1 | Character::shoot | vehicle_side | BLOCKED | pending | src/game/characters/Character.cpp |
| libsanangeles.so | 0x00303b6d | PlayerTest::shoot | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00303b58 | PlayerTest::shoot non-virtual thunk | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003035d1 | PlayerTest::acquireTarget | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00303315 | PlayerTest::getAttackableTarget | lock_init | BLOCKED | pending | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00303fe9 | PlayerTest::updateAnim | vehicle_side | BLOCKED | pending | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00303ab9 | PlayerTest::startDriving | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00304701 | PlayerTest::stopDriving | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00302241 | PlayerTest::orientTowards | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00304895 | PlayerTest::teleportTo | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00305a1d | PlayerTest::attack | camera_tap | BLOCKED | pending | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003020f1 | PlayerTest::debug | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00340945 | CivAgressiveController destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/ai/CivAgressiveController.cpp |
| libsanangeles.so | 0x00303079 | PlayerTest::photo | lock_init | ASSIGNED | private true-hierarchy ABI regression only; tracked match remains exact | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00340901 | CivAgressiveController deleting destructor (D0) | — | COMPLETED | 100% | src/game/ai/CivAgressiveController.cpp |
| libsanangeles.so | 0x0030577d | PlayerTest::snipe | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00340c35 | CivPassiveController destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/ai/CivPassiveController.cpp |
| libsanangeles.so | 0x00304c05 | PlayerTest::onObjectKilled | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00340bf1 | CivPassiveController deleting destructor (D0) | — | COMPLETED | 100% | src/game/ai/CivPassiveController.cpp |
| libsanangeles.so | 0x00341d25 | GuardController destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/ai/GuardController.cpp |
| libsanangeles.so | 0x00341d65 | GuardController deleting destructor (D0) | — | COMPLETED | 100% | src/game/ai/GuardController.cpp |
| libsanangeles.so | 0x00302361 | PlayerTest::moveTo | camera_tap | BLOCKED | pending | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003049e5 | PlayerTest::Respawn | vehicle_side | BLOCKED | pending | src/game/ai/PlayerTest.cpp |
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
| libsanangeles.so | 0x00341139 | CopController::switchState | — | COMPLETED | 100% | src/game/ai/CopController.cpp |
| libsanangeles.so | 0x00341f31 | GuardController::onEvent | lock_init | BLOCKED | pending | src/game/ai/GuardController.cpp |
| libsanangeles.so | 0x003420cd | GuardController::switchState | — | COMPLETED | 100% | src/game/ai/GuardController.cpp |
| libsanangeles.so | 0x00342585 | VehicleController::onEvent | lock_init | BLOCKED | pending | src/game/ai/VehicleController.cpp |
| libsanangeles.so | 0x0034171d | CopVehicleController::switchState | — | COMPLETED | 100% | src/game/ai/CopVehicleController.cpp |
| libsanangeles.so | 0x00341381 | CopController::onEvent | vehicle_side | BLOCKED | pending | src/game/ai/CopController.cpp |
| libsanangeles.so | 0x003406a9 | AIManager::clean | — | COMPLETED | 100% | src/game/ai/AIManager.cpp |
| libsanangeles.so | 0x003426b5 | VehicleController::switchState | — | COMPLETED | 100% | src/game/ai/VehicleController.cpp |
| libsanangeles.so | 0x00340741 | AIManager::onEvent | — | COMPLETED | 100% | src/game/ai/AIManager.cpp |
| libsanangeles.so | 0x00340305 | AIManager::addAI(Vehicle*, StateID) | lock_init | BLOCKED | pending | src/game/ai/AIManager.cpp |
| libsanangeles.so | 0x00340455 | AIManager::addAI(NPC*, StateID) | — | COMPLETED | 100% | src/game/ai/AIManager.cpp |
| libsanangeles.so | 0x003520c1 | RadioStationController::selectRandomJingle | — | COMPLETED | 100% | src/game/ai/RadioStationController.cpp |
| libsanangeles.so | 0x003522b1 | RadioStationController::selectRandomSong | — | COMPLETED | 100% | src/game/ai/RadioStationController.cpp |
| libsanangeles.so | 0x00352335 | RadioStationController constructor (C1/C2 aliases) | vehicle_side | BLOCKED | pending | src/game/ai/RadioStationController.cpp |
| libsanangeles.so | 0x00319cd5 | PhysicInfo::Reset | — | COMPLETED | 100% | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x00319c21 | SafeDeleteArray<array<unsigned short> > | — | COMPLETED | 100% | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x0031a40d | PhysicAttributes::FindLowerCostNode | lock_init | BLOCKED | pending | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x003196fd | PhysicAttributes::SegmentsIntersect | — | COMPLETED | 100% | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x0031e0c9 | PhysicAttributes::Clean | — | COMPLETED | 100% | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x0031e99d | PhysicAttributes::UpdateEdgesCollisions | — | COMPLETED | 100% | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x003497e5 | ASprite::GetAnim | camera_tap | BLOCKED | pending | src/game/rendering/ASprite.cpp |
| libsanangeles.so | 0x0031a6fd | PhysicAttributes::GetJumpHeight | lock_init | BLOCKED | pending | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x003497f5 | ASprite::GetFrame | camera_tap | BLOCKED | pending | src/game/rendering/ASprite.cpp |
| libsanangeles.so | 0x003200f9 | PhysicAttributes::Init | — | COMPLETED | 100% | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x00353095 | SoundManager::_getReadySound | camera_tap | BLOCKED | pending | src/game/audio/SoundManager.cpp |
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
| libsanangeles.so | 0x002d4015 | Application::UnRegisterForUpdate | lock_init | BLOCKED | pending | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d3cb9 | Application::IsLogoOver | — | COMPLETED | 100% | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d3c9d | Application::IsGlobalResumingOver | — | COMPLETED | 100% | src/game/app/Application.cpp |
| libsanangeles.so | 0x002d3c7d | Application::InitIPhone | camera_tap | BLOCKED | pending | src/game/app/Application.cpp |
| libsanangeles.so | 0x00325b0d | CSniperHud destructor (D1/D2 aliases) | — | COMPLETED | 100% | src/game/hud/SniperHud.cpp |
| libsanangeles.so | 0x0034a3b5 | ASpriteData constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/rendering/ASpriteData.cpp |
| libsanangeles.so | 0x003499b9 | ASprite::GetAFrameTime | — | COMPLETED | 100% | src/game/rendering/ASprite.cpp |
| libsanangeles.so | 0x00349815 | ASprite::GetModule | camera_tap | BLOCKED | pending | src/game/rendering/ASprite.cpp |
| libsanangeles.so | 0x00349c85 | ASprite::GetFModule | lock_init | BLOCKED | pending | src/game/rendering/ASprite.cpp |
| libsanangeles.so | 0x00325add | CSniperHud constructor (C1/C2 aliases) | — | COMPLETED | 100% | src/game/hud/SniperHud.cpp |
| libsanangeles.so | 0x00349825 | ASprite::GetFrameRect | camera_tap | BLOCKED | pending | src/game/rendering/ASprite.cpp |
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
| libsanangeles.so | 0x00324399 | CHudManager::update | hud_drawables | BLOCKED | pending | src/game/hud/CHudManager.cpp |
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
| libsanangeles.so | 0x002eb761 | Menus::ServiceCarRental::Notify | lock_init | BLOCKED | 196/448 bytes (unmatched) | src/game/ui/MenuState.cpp |

Coordinator reviewed the six-pass preloadGlyphs and ServiceWeaponShop::Refresh reports: neither is an exact match; both remain parked without credit. The undelivered _zoomMap assignment is released.

| libsanangeles.so | 0x00349a81 | ASprite::GetFrameIdx(char const*) | — | COMPLETED | 100% | src/game/rendering/ASprite.cpp |
| libsanangeles.so | 0x00349dd5 | ASprite::GetAnimIdx(char const*) | hud_registration | BLOCKED | 62/64 bytes (unmatched) | src/game/rendering/ASprite.cpp |

| libsanangeles.so | 0x00327a71 | Cash::drawCash(int, int const*, int&, int) const (existing-match regression) | — | COMPLETED | 100% (no new credit) | src/game/ui/Cash.cpp |

| libsanangeles.so | 0x002e3791 | GSSplash::dtor(StateMachine const*) | — | COMPLETED | 100% | src/game/app/GSSplash.cpp |

| libsanangeles.so | 0x00321445 | SceneNodeManager::getPoolID(int) const | hud_registration | BLOCKED | 72-byte candidate; context/order unchanged | src/game/world/SceneNodeManager.cpp |

Coordinator reviewed _zoomMap: three materially different forms emitted identical complete bytes; parked under the early-stop rule without credit.

| libsanangeles.so | 0x0034eed9 | ResStream::~ResStream() (deleting D0) | hud_glyphs | BLOCKED | 54/60 bytes (unmatched) | src/game/world/ResStream.cpp |

| libsanangeles.so | 0x0034ef15 | ResStream::~ResStream() (complete/base D1/D2 aliases) | hud_glyphs | BLOCKED | 50/56 bytes (unmatched) | src/game/world/ResStream.cpp |

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

| libsanangeles.so | 0x002e1e15 | GSFailure::draw2d(StateMachine const*) | hud_registration | BLOCKED | 98/308 bytes (unmatched) | src/game/app/GSFailure.cpp |

| libsanangeles.so | 0x002e20dd | GSFailure::update(StateMachine*) | — | COMPLETED | 100% | src/game/app/GSFailure.cpp |
| libsanangeles.so | 0x002d3be1 | MediaPlayerIPhone::playMovie(char const*) | — | COMPLETED | 100% | src/game/app/MediaPlayerIPhone.cpp |
| libsanangeles.so | 0x002d3be5 | MediaPlayerIPhone::stopMovie() | — | COMPLETED | 100% | src/game/app/MediaPlayerIPhone.cpp |

| libsanangeles.so | 0x00321699 | SceneNodeManager::manage(int, LevelObject*, int) | — | COMPLETED | 100% | src/game/world/SceneNodeManager.cpp |
| libsanangeles.so | 0x00306d2d | SpawnPoint::hasCloseNeighbors() const | — | COMPLETED | 100% | src/game/world/SpawnPoint.cpp |
| libsanangeles.so | 0x00328b41 | Map::setMap(Map::eMapType) | — | COMPLETED | 100% | src/game/world/Map.cpp |

| libsanangeles.so | 0x003219cd | SceneNodeManager::drop(int, irr::scene::ISceneNode const*) | hud_registration | BLOCKED | 208/210-byte size; context/order unchanged | src/game/world/SceneNodeManager.cpp |
| libsanangeles.so | 0x003065e5 | SpawnPoint::CreateAllSpawnInstances() | hud_glyphs | BLOCKED | 327/336 bytes (unmatched) | src/game/world/SpawnPoint.cpp |

| libsanangeles.so | 0x003160d9 | GameObjectManager::getAttackableTarget(Character*) | hud_glyphs | BLOCKED | canonical context unchanged; no credit | src/game/world/GameObjectManager.cpp |
| libsanangeles.so | 0x00328c49 | Map::draw() const | lock_init | BLOCKED | 294/304 bytes; original-order trial unchanged | src/game/world/Map.cpp |
| libsanangeles.so | 0x003218d9 | SceneNodeManager::reclaimGarbage() | hud_registration | BLOCKED | 238/244 bytes; context/order unchanged | src/game/world/SceneNodeManager.cpp |

Coordinator authorizes one unchanged-best integrated-context replay for each parked SceneNodeManager getPoolID, drop and reclaimGarbage after the exact bool manage implementation/header refinement. If needed, one combined original-address method-order trial is allowed with every existing function byte check. No further source search. Map::draw receives only one original-address method-order comparison using its proven typed layout and exact setMap. These are bounded context escalations, not reopened unbounded searches.

| libsanangeles.so | 0x00315f39 | GameObjectManager::getDistanceFromAttackableTarget(Character*, int, LevelObject*, bool) | hud_glyphs | BLOCKED | canonical context unchanged; no credit | src/game/world/GameObjectManager.cpp |

| libsanangeles.so | 0x00321721 | SceneNodeManager::report() const | lock_init | BLOCKED | 392/384-byte size (unmatched) | src/game/world/SceneNodeManager.cpp |

| libsanangeles.so | 0x003015d0 | _ZThn4_N10PlayerTestD1Ev | lock_init | BLOCKED | private family exact; coherent photo regression blocks integration | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00303618 | _ZThn4_N10PlayerTestD0Ev | lock_init | BLOCKED | private family exact; coherent photo regression blocks integration | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x0030362d | _ZN10PlayerTestD0Ev | lock_init | BLOCKED | private family exact; coherent photo regression blocks integration | src/game/ai/PlayerTest.cpp |
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


| libsanangeles.so | 0x00303701 | PlayerTest::PlayerTest(b2World*) (C1/C2 aliases) | lock_init | BLOCKED | 864/872-byte candidate; private old photo regression remains | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x0030a955 | Vehicle::Vehicle(int) (C1/C2 aliases) | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00306b11 | SpawnPoint::Load(Structs::SpawnPoint const&) | hud_glyphs | BLOCKED | post-constructor replay unchanged; 539/540 bytes | src/game/world/SpawnPoint.cpp |

Coordinator approves private Vehicle-constructor layout refinement of the four native vector members at 512/524/536/548, replacing only constant-index references mechanically in preserved Vehicle/NPC bodies. Storage extent and offsets must remain unchanged. All old Vehicle and NPC/dependency checks plus accepted custom/support/table checks must pass before readiness; no other algorithm changes or additional overlapping storage.
| libsanangeles.so | 0x00307451 | SpawnPoint::canSpawn() const | hud_glyphs | BLOCKED | post-constructor replay unchanged; candidate 820/816 bytes | src/game/world/SpawnPoint.cpp |
| libsanangeles.so | 0x0031da29 | PhysicAttributes::IntersectSegmentWithHeightMap | lock_init | BLOCKED | unmatched plane/cross-product code generation | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x0031aa5d | PhysicAttributes::GetRandomDestination | hud_registration | BLOCKED | 713/724 bytes; stack-slot operands | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x00307101 | SpawnPoint::UpdateSpawnCenters() | hud_glyphs | BLOCKED | 872/848-byte candidate; repeated compiler CSE output | src/game/world/SpawnPoint.cpp |
| libsanangeles.so | 0x0031d7a1 | ContactListener::Persist(b2ContactPoint const*) | hud_registration | BLOCKED | 341/604 bytes after six candidates; branch layout | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x0031b9a9 | PhysicAttributes::IntersectSegmentWithHeightMap(PhysicInfo&, plane3df const&, vector3df const&, vector3df const&, vector3df&, vector3df&) | lock_init | BLOCKED | 4848/4800-byte candidate; six forms exhausted | src/game/characters/PhysicAttributes.cpp |

Coordinator authorizes one unchanged-source replay each for SpawnPoint Load/canSpawn against the newly integrated authentic Vehicle constructor header (real IMapTrackable, scalar wheel members, accurate initialization fields). Preserve all existing unit checks; stop unchanged targets without source search, then proceed to the newly assigned centers function.

| libsanangeles.so | 0x00323b69 | SafeDelete<CDrivingHud>(CDrivingHud*&) | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |

| libsanangeles.so | 0x00323b89 | SafeDelete<CWalkingHud>(CWalkingHud*&) | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |
| libsanangeles.so | 0x00323ba9 | SafeDelete<CSniperHud>(CSniperHud*&) | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |

| libsanangeles.so | 0x00323bc9 | SafeDelete<CCameraHud>(CCameraHud*&) | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |

| libsanangeles.so | 0x00341a3d | CopVehicleController::onEvent(IEvent const*, EventManager const*) | hud_registration | BLOCKED | 728/744 bytes; authentic event initialization regresses old caller | src/game/ai/CopVehicleController.cpp |

| libsanangeles.so | 0x003238a1 | std::__stl_throw_overflow_error(char const*) | — | COMPLETED | 100% | src/game/hud/CHudManager.cpp |

| libsanangeles.so | 0x002f4441 | b2CircleDef::~b2CircleDef() (D1) | — | COMPLETED | 100% | src/game/characters/Character.cpp |
| libsanangeles.so | 0x002f462d | b2CircleDef::~b2CircleDef() (D0) | — | COMPLETED | 100% | src/game/characters/Character.cpp |

| libsanangeles.so | 0x00318be5 | LevelObject::canGoToPoint(vector3df const&) | — | COMPLETED | 100% | src/game/world/LevelObject.cpp |

| libsanangeles.so | 0x0031b3e9 | PhysicAttributes::SetHeightAttributes(ISceneNode*, vector3df const&, PhysicInfo&) | lock_init | BLOCKED | 1036/1040 bytes; six forms exhausted | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x002ff181 | NPC::_detect() | hud_glyphs | BLOCKED | 1100/1104-byte candidate; three distinct forms identical | src/game/ai/NPC.cpp |

| libsanangeles.so | 0x0031dc7d | ContactFilter::ShouldCollide(b2Shape*, b2Shape*) | hud_registration | BLOCKED | six forms exhausted; best 106/1100 bytes, no credit | src/game/characters/PhysicAttributes.cpp |
| libsanangeles.so | 0x003179d5 | LevelObject::CastRay(vector3df const&, vector3df const&, vector3df&, vector3df&, LevelObject*&, bool) | hud_glyphs | BLOCKED | 1484/1504 bytes; unchanged-context replay stopped | src/game/world/LevelObject.cpp |

| libsanangeles.so | 0x0034b6f5 | std::__stl_throw_out_of_range(char const*) | — | COMPLETED | 100% | src/game/persistence/StringManager.cpp |
| libsanangeles.so | 0x0031ad31 | PhysicAttributes::SetHeightAttributes(vector3df const&, PhysicInfo*) | lock_init | BLOCKED | 1400/1388-byte candidate; six forms exhausted | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x0030d149 | Vehicle::CreateWheels(Box2DUserInfo*) | hud_glyphs | BLOCKED | 1440/1408-byte candidate; six forms exhausted | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x00319ed5 | PhysicAttributes::LoadArrays(char*) | — | COMPLETED | 100% | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x00313385 | Vehicle::collision(vector3df, int) | hud_registration | BLOCKED | 1354/1360 bytes; six forms exhausted, no credit | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x0030ff41 | Vehicle::Load(Structs::Car const&) | hud_glyphs | BLOCKED | 1380/1368-byte candidate; three equivalent forms identical | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x00320ca1 | PhysicAttributes::ComputeShortestPath(int, int, vector3df, vector3df, float) | lock_init | BLOCKED | 1688/1668-byte supported candidate; six forms exhausted | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x003116dd | Vehicle::stepPhysic() | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |

| libsanangeles.so | 0x0031cf75 | PhysicAttributes::GetNextRandomPos(int, int, vector3df) | lock_init | BLOCKED | 1732/1748-byte candidate; six forms exhausted | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x00301a75 | PlayerTest::switchContext(eContext, bool) | hud_glyphs | BLOCKED | 892/900-byte candidate; six forms, full 74-profile old gate passed | src/game/ai/PlayerTest.cpp |

| libsanangeles.so | 0x0031e285 | PhysicAttributes::AddCollisionShapes(int, unsigned short) | hud_registration | BLOCKED | faithful 1836/1816-byte candidate; six forms exhausted | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x00303bb9 | PlayerTest::switchAnim() | lock_init | BLOCKED | 1088/1072 bytes; six forms; one private baseline link gate incomplete | src/game/ai/PlayerTest.cpp |

| libsanangeles.so | 0x0030406d | PlayerTest::updateCarInteraction() | hud_glyphs | BLOCKED | 1684-byte candidate not matched; six forms; full 74-profile old gate passed | src/game/ai/PlayerTest.cpp |

| libsanangeles.so | 0x002ff5d1 | NPC::attackTarget() | hud_registration | BLOCKED | 2088/2108-byte candidate; six forms exhausted | src/game/ai/NPC.cpp |

| libsanangeles.so | 0x0034bf8d | StringManager::~StringManager() | hud_registration | BLOCKED | unchanged one-shot context replay; 212/248 bytes, no new forms | src/game/persistence/StringManager.cpp |

| libsanangeles.so | 0x002ed8ad | Widgets::Mission::UpdateLocalization() | — | COMPLETED | 100% | src/game/ui/MenuWidget.cpp |

| libsanangeles.so | 0x002eb12d | Menus::ServiceCarRental::Update() | lock_init | BLOCKED | 816-byte candidate unmatched; six forms; one private baseline link incomplete | src/game/ui/MenuState.cpp |

| libsanangeles.so | 0x002eac65 | Menus::OptionGameSettings::Notify(MenuWidget const*, int) | hud_registration | BLOCKED | 1064/1056-byte candidate; six forms, old full graph exact | src/game/ui/MenuState.cpp |

| libsanangeles.so | 0x002e4e7d | MenuManager::update(StateMachine*) | hud_registration | BLOCKED | 872-byte candidate unmatched; six forms; rejected two old MenuState regressions | src/game/ui/MenuManager.cpp |
| libsanangeles.so | 0x002e51fd | MenuManager::setText(eText, char const*, int*) | hud_glyphs | BLOCKED | 1088/1104 bytes; four forms, no grounded next lead | src/game/ui/MenuManager.cpp |

| libsanangeles.so | 0x00344821 | SaveGame::SampleAndSave(char const*) | lock_init | BLOCKED | 1384/1388 bytes; swapped independent STR/MOV pair; five forms parked | src/game/persistence/SaveGame.cpp |

| libsanangeles.so | 0x002e574d | MenuManager::setup(bool) | hud_glyphs | BLOCKED | 1788/1792 bytes; first form parked on old visibility regression | src/game/ui/MenuManager.cpp |

| libsanangeles.so | 0x0033ddd5 | ScriptManager::loadCommand(DataStream&) | lock_init | BLOCKED | 2440/2436 bytes; six forms; 34 header-only profiles exact, no credit | src/game/scripting/ScriptManager.cpp |

| libsanangeles.so | 0x003026b9 | PlayerTest::move(float, float) | hud_registration | BLOCKED | final 2512/2496 bytes; six forms, strict photo overlap; old header/photo graph exact | src/game/ai/PlayerTest.cpp |

| libsanangeles.so | 0x002ffe0d | NPC::Update(int) | hud_glyphs | BLOCKED | 3024/3012 bytes; six forms; header-only 36 profiles exact, combined dependent link incomplete | src/game/ai/NPC.cpp |

| libsanangeles.so | 0x00320351 | ContactListener::Add(b2ContactPoint const*) | lock_init | BLOCKED | best extent 2364/2384 bytes; six forms; header sweep 43/44, known fixture incomplete | src/game/characters/PhysicAttributes.cpp |

| libsanangeles.so | 0x0039c751 | dump_memory_stats(char const*, int, char const*) | — | COMPLETED | 100% | src/game/core/utility.cpp |

| libsanangeles.so | 0x003935bd | png_memset(void*, unsigned char, int) | — | COMPLETED | 100% | src/game/core/png_helper.cpp |

| libsanangeles.so | 0x003935c9 | png_memcpy(void*, void const*, int) | — | COMPLETED | 100% | src/game/core/png_helper.cpp |

| libsanangeles.so | 0x003935d5 | png_memcmp(void const*, void const*, int) | — | COMPLETED | 100% | src/game/core/png_helper.cpp |

| libsanangeles.so | 0x003935e1 | png_strlen(char const*) | — | COMPLETED | 100% | src/game/core/png_helper.cpp |

| libsanangeles.so | 0x002fd291 | Lock::render() | coordinator | BLOCKED | 304-byte candidate unmatched; six forms; old 8 functions and 10 section/region checks exact | src/game/core/Lock.cpp |

| libsanangeles.so | 0x0034a015 | ASprite::PaintFModule(int, int, int, int, int) const | hud_registration | BLOCKED | 222/220 bytes; three forms identical; strict link overlap, old graph exact | src/game/rendering/ASprite.cpp |

| libsanangeles.so | 0x0034ad9d | ASpriteData::AFrame::Swap() | — | COMPLETED | 100% | src/game/rendering/ASpriteData.cpp |

| libsanangeles.so | 0x0034ac39 | ASpriteData::FModule::Swap() | — | COMPLETED | 100% | src/game/rendering/ASpriteData.cpp |

| libsanangeles.so | 0x0034a3c9 | ASpriteData::Anim::Swap() | — | COMPLETED | 100% | src/game/rendering/ASpriteData.cpp |

| libsanangeles.so | 0x0034acd1 | ASpriteData::Image::Swap() | — | COMPLETED | 100% | src/game/rendering/ASpriteData.cpp |

| libsanangeles.so | 0x0034a231 | ASpriteData::__rect::isIntersecting(int, int) | — | COMPLETED | 100% | src/game/rendering/ASpriteData.cpp |

| libsanangeles.so | 0x0034a655 | ASpriteData::Module::Swap() | — | COMPLETED | 100% | src/game/rendering/ASpriteData.cpp |

| libsanangeles.so | 0x0034a491 | ASpriteData::Frame::Swap() | — | COMPLETED | 100% | src/game/rendering/ASpriteData.cpp |

| libsanangeles.so | 0x0034ae61 | ASpriteData::Swap() | — | COMPLETED | 100% | src/game/rendering/ASpriteData.cpp |

| libsanangeles.so | 0x0034a729 | ASpriteData::Debug() | coordinator | BLOCKED | shared-header replay unchanged 1294/1296 bytes; no credit | src/game/rendering/ASpriteData.cpp |

| libsanangeles.so | 0x00349e15 | ASprite::PaintModule(int, int, int, int) const | hud_glyphs | BLOCKED | 500/512 bytes; six forms; rejected two old header regressions | src/game/rendering/ASprite.cpp |

| libsanangeles.so | 0x0034a28d | ASprite::GetPixelInfoInFrame(int, int, int, int&, int&) | hud_registration | BLOCKED | 292/296 bytes; six forms; shared declaration extraction and old graph exact | src/game/rendering/ASprite.cpp |

| libsanangeles.so | 0x00349315 | FSelect(float, float, float) | coordinator | BLOCKED | 30/32 bytes; four comparisons, return-register tail differs, no credit | src/game/app/IPhone.cpp |

| libsanangeles.so | 0x00349d81 | ASprite::GetAnimDuration(int) | coordinator | BLOCKED | 80/82-byte candidate; five forms, all old 36 functions and 32 section/regions exact | src/game/rendering/ASprite.cpp |

| libsanangeles.so | 0x002d4a01 | Application::_Update(int) | lock_init | BLOCKED | 108/106 bytes; six forms; old45/15 exact, header110/111 known fixture incomplete | src/game/app/Application.cpp |

| libsanangeles.so | 0x003499dd | ASprite::GetAFrame(int, int) | hud_glyphs | BLOCKED | 106-byte candidate unmatched; six forms; 57 old functions and 54 section/regions exact | src/game/rendering/ASprite.cpp |

| libsanangeles.so | 0x002d40fd | Application::ProcessKeyEvent(bool, int) | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d4709 | Application::appKeyPressed(int) | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d4bc1 | Application::GlobalResumingUpdate() | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x0034c599 | TouchScreenBase::getID(long) header integration | — | COMPLETED | 100%; native 68-byte function preserved after interface integration | src/game/input/TouchScreenBase.cpp |

| libsanangeles.so | 0x002d45ad | Application::appKeyReleased(int) | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d4fe1 | Application::_Draw() | hud_registration | BLOCKED | 276/272 bytes; three identical forms; oldTouch header context differs | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d50f1 | Application::Update() | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d4861 | Application::displayNumberWithHUDSprite(int, int, int, char const*) | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d4e89 | Application::Resume() | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d5821 | Application::InitWin32(irr::IrrlichtDevice*) | hud_glyphs | REVIEW | exact 118-byte candidate; 95-profile old/support proof passed | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d51f9 | Application::Application() C1/C2 aliases | hud_registration | BLOCKED | native148B aliases unmatched; three forms; authentic180B header and old123-profile proof pass | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d4cd1 | Application::Quit() | lock_init | REVIEW | exact 368-byte candidate; genuine alias hierarchy proof passed except known fixture | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d5cf9 | Application::~Application() D1/D2 | hud_glyphs | REVIEW | exact destructor aliases; canonical RAII and old90-profile proof pass | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d5c65 | Application::~Application() D0 | hud_glyphs | REVIEW | exact destructor aliases; canonical RAII and old90-profile proof pass | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d5591 | Application::Init(irr::IrrlichtDevice*) | lock_init | REVIEW | exact 656-byte candidate; oldCash header context difference and link limitations pending | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d528d | Application::GetInstance() | — | COMPLETED | 100% | src/game/app/Application.cpp |

| libsanangeles.so | 0x002d5eb9 | Application::OnEvent(irr::SEvent const&) | hud_glyphs | BLOCKED | GCC weak destructor alias assembly failure after two forms; no credit | src/game/app/Application.cpp |

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
| libsanangeles.so | 0x002d2759 | appInit | lock_init | BLOCKED | exact 192-byte candidate; InitWin32 declaration regresses existing Cash332 by five bytes; no credit | src/game/core/wrapper.cpp |
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
| libsanangeles.so | 0x003eca0d | CanHandleMouseEvent(gameswf::character*) | hud_glyphs | BLOCKED | six candidates, 80/92 bytes; old matches preserved, no credit | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003eccd9 | GetLocalPosition(gameswf::character*, float, float) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003eca69 | sprite_can_handle_mouse_event_callback(gameswf::character*) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x002d1835 | nativeNotifyPause | — | COMPLETED | 100% | src/game/app/jni_Gangstar.c |
| libsanangeles.so | 0x003eed69 | RenderFX::SearchIndex::Find(char const*) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ecf05 | RenderFX::SetColorTransform(gameswf::character*, unsigned int, unsigned int) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x002d18c5 | nativeExit | — | COMPLETED | 100% | src/game/app/jni_Gangstar.c |
| libsanangeles.so | 0x003ed6e5 | RenderFX::Find(char const*, gameswf::character*) | hud_glyphs | BLOCKED | six candidates; best 400/416 bytes with native frame, no credit | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003f02c5 | RenderFX::SearchIndex::Init(RenderFX&) | lock_init | BLOCKED | six candidates; best 476/488 bytes, old 108 functions and headers exact; no credit | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x002d18f9 | nativedetectPhoneLang | — | COMPLETED | 100% | src/game/app/jni_Gangstar.c |
| libsanangeles.so | 0x002d192d | nativeUnlockDemo | — | COMPLETED | 100% | src/game/app/jni_Gangstar.c |
| libsanangeles.so | 0x002d1961 | nativeGetVersionMode | — | COMPLETED | 100% | src/game/app/jni_Gangstar.c |
| libsanangeles.so | 0x003ef139 | RenderFX::SendEvent(RenderFX::Event&) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x002d1995 | nativeGetNumLaunch | — | COMPLETED | 100% | src/game/app/jni_Gangstar.c |
| libsanangeles.so | 0x002d16f5 | Java_com_gameloft_android_GAND_GloftGANG_Gangstar_nativeInit | — | COMPLETED | 100% | src/game/app/jni_Gangstar.c |
| libsanangeles.so | 0x003eee95 | RenderFX::ClearFonts(gameswf::player_context*) | — | COMPLETED | 100% | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003eefad | RenderFX::InvokeASCallback(gameswf::character*, char const*) | hud_glyphs | BLOCKED | source344/368; two flag diagnostics fail old strict linking, no flag adopted | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003f0041 | RenderFX::Update(int, bool) | lock_init | BLOCKED | five source forms; native-size248 but 12 bytes differ in cold-tail order, no credit | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ef201 | RenderFX::SetFocus(gameswf::character*, int) | hud_registration | BLOCKED | six source forms; native-size356 but branch/register differences, no credit | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003efced | RenderFX::UpdateInput(int, int) | lock_init | BLOCKED | five forms; best852 differs, current110 old functions and headers preserved; no credit | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x003ef511 | RenderFX::UpdateCursor(RenderFX::Cursor&, int) | hud_registration | BLOCKED | six forms; best1996/2012, inline-functions diagnostic unchanged; no credit | src/game/rendering/menufx.cpp |
| libsanangeles.so | 0x002f064d | BulletTraceManager::OnAnimate(unsigned int) | hud_glyphs | BLOCKED | current-header unchanged replay492/496, old50checks pass; no credit | src/game/combat/BulletTraceManager.cpp |
| libsanangeles.so | 0x003514b9 | CSoundDecoderMSADPCM::Decode(short*, int, bool) | lock_init | BLOCKED | five forms; best656/652 overlaps native neighbor, old baseline proof retained; no credit | src/game/audio/CSoundDecoderMSADPCM.cpp |
| libsanangeles.so | 0x00317fb5 | LevelObject::canGoToPoint(vector3df const&, vector3df&, vector3df&) | hud_registration | BLOCKED | bounded3forms identical3120B,3032equal; current sibling/callers pass; no credit | src/game/world/LevelObject.cpp |
| libsanangeles.so | 0x00330015 | Rocket::launch(vector3df) | hud_glyphs | BLOCKED | one current-interface unchanged replay744B,125bytes differ; old39checks pass; no credit | src/game/combat/Rocket.cpp |
| libsanangeles.so | 0x00304ec9 | PlayerTest::Update() | hud_registration | ASSIGNED | pending | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00312081 | Vehicle::_processAIFlags() | lock_init | ASSIGNED | pending | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00313b01 | Vehicle::Update(int) | hud_glyphs | ASSIGNED | pending | src/game/vehicles/Vehicle.cpp |
