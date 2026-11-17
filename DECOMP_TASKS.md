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
| libsanangeles.so | 0x003339bd | FollowCamera::goBehind | vehicle_side | REVIEW | — | src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x00305cd5 | Shop::getId | — | COMPLETED | 100% | src/game/ui/Shop.cpp |
| libsanangeles.so | 0x003342ad | FPSCamera::zoom (touch list) | camera_tap | REVIEW | — | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x0033560d | VehicleCamera::updatePosition | — | COMPLETED | 100% | src/game/vehicles/VehicleCamera.cpp |
| libsanangeles.so | 0x00333e41 | FPSCamera::scroll (touch list) | camera_tap | REVIEW | — | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x002e3c1d | GSWeaponShopMenu::dtor | — | COMPLETED | 100% | src/game/ui/GSWeaponShopMenu.cpp |
| libsanangeles.so | 0x00335849 | VehicleCamera::update | vehicle_side | REVIEW | — | src/game/vehicles/VehicleCamera.cpp |
| libsanangeles.so | 0x00334389 | FPSCamera::updateTouchInputs | camera_tap | REVIEW | — | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x002e3c49 | GSWeaponShopMenu::ctor | — | COMPLETED | 100% | src/game/ui/GSWeaponShopMenu.cpp |
| libsanangeles.so | 0x00333451 | FollowCamera::updatePosition | — | COMPLETED | 100% | src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x00332771 | CameraManager::update | camera_tap | REVIEW | — | src/game/core/CameraManager.cpp |
| libsanangeles.so | 0x00301a3d | PlayerTest::Stop | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00333789 | FollowCamera::init | vehicle_side | REVIEW | — | src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x00333ab1 | FollowCamera::update | vehicle_side | REVIEW | — | src/game/core/FollowCamera.cpp |
| libsanangeles.so | 0x002e1571 | GSCarRepairMenu::draw2d | lock_init | BLOCKED | — | src/game/ui/GSCarRepairMenu.cpp |
| libsanangeles.so | 0x00334c25 | LockCamera::update | camera_tap | REVIEW | — | src/game/core/LockCamera.cpp |
| libsanangeles.so | 0x003017ed | PlayerTest::jumpFinished | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301821 | PlayerTest::driftFinished | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301855 | PlayerTest::addDistanceDriven | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00301ebd | PlayerTest::setLastUsedVehicle | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x003017b1 | PlayerTest::onTargetReached | camera_tap | BLOCKED | — | src/game/ai/PlayerTest.cpp |
