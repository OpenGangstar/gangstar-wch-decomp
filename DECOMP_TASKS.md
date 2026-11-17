# Decompilation function registry

The main Codex agent records assignments and releases ownership after review
and acceptance. Use the binary, address, and function name to identify each
entry. Follow the workflow in [AGENTS.md](AGENTS.md).

| Binary/library | Address | Function name | Assigned agent | Status | Matching percentage | Relevant source files |
| --- | --- | --- | --- | --- | ---: | --- |
| libsanangeles.so | 0x00301091 | PlayerTest::setClosestShop(Shop*) | — | COMPLETED | 100% | src/game/ai/PlayerTest.cpp |
| libsanangeles.so | 0x00332f95 | CameraManager::tappedTarget | — | COMPLETED | 100% | src/game/core/CameraManager.cpp |
| libsanangeles.so | 0x00334a81 | LockCamera::init | lock_init | REVIEW | — | src/game/core/LockCamera.cpp |
| libsanangeles.so | 0x003351dd | VehicleCamera::goToSide | vehicle_side | REVIEW | — | src/game/vehicles/VehicleCamera.cpp |
| libsanangeles.so | 0x00333095 | CameraManager::processTouchRelease | camera_tap | ASSIGNED | — | src/game/core/CameraManager.cpp |
| libsanangeles.so | 0x003340c1 | FPSCamera::exit | lock_init | ASSIGNED | — | src/game/core/FPSCamera.cpp |
| libsanangeles.so | 0x0033530d | VehicleCamera::init | vehicle_side | ASSIGNED | — | src/game/vehicles/VehicleCamera.cpp |
| libsanangeles.so | 0x00305ccd | Shop::triggered | — | AVAILABLE | — | src/game/ui/Shop.cpp |
