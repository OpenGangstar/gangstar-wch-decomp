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
| libsanangeles.so | 0x00305e29 | Shop::trigger | lock_init | REVIEW | — | src/game/ui/Shop.cpp |
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
| libsanangeles.so | 0x003018d1 | PlayerTest::setAnim | camera_tap | REVIEW | — | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301f69 | PlayerTest::SetSpeed | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003019c9 | PlayerTest::stopMoving | vehicle_side | REVIEW | — | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00302685 | PlayerTest::UpdateSceneNode | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003013bd | PlayerTest::ResetPlayerTest | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301f01 | PlayerTest::setVehicle | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003025cd | PlayerTest::isFacingTarget | camera_tap | BLOCKED | — | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x002f42cd | Character::updatePosition | lock_init | REVIEW | — | src/game/characters/Character.cpp |
| libsanangeles.so | 0x00301911 | PlayerTest::initDriving | vehicle_side | REVIEW | — | src/game/ai/PlayerTest.cpp |
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
| libsanangeles.so | 0x00309189 | Vehicle::stopDriving | vehicle_side | REVIEW | — | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030a491 | Vehicle::cleanTargets | lock_init | REVIEW | — | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x0030b22d | Vehicle::getNearestDoorDummy | — | COMPLETED | 100% | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x00307b88 | Vehicle::getMarkerType (secondary thunk) | vehicle_side | REVIEW | — | src/game/vehicles/Vehicle.cpp |
| libsanangeles.so | 0x003090e9 | Vehicle::_cleanupSounds | lock_init | REVIEW | — | src/game/vehicles/Vehicle.cpp |
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
