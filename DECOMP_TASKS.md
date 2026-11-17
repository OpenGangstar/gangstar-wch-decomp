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
