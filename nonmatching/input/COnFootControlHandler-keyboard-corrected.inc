struct OnFootKeyboardEvent : public IEvent {
    unsigned int character;
    int key;
    bool pressed;
};

extern Vehicle* car;

void COnFootControlHandler::onKeyboardEvent(const IEvent* event)
{
    PlayerTest* player = PlayerTest::GetPlayer();
    if (!player)
        return;

    const OnFootKeyboardEvent* keyboard = static_cast<const OnFootKeyboardEvent*>(event);
    if (!keyboard->pressed) {
        switch (keyboard->key) {
        case 'G':
        case 'J':
            car->unknown988 = 0.0f;
            break;
        case 'H':
        case 'Y':
            car->unknown984 = 0.0f;
            break;
        case 'F':
            handleAttackReleased();
            break;
        case 37:
        case 'A':
            player->movementKeys[1] = false;
            player->stopMoving(false);
            break;
        case 38:
        case 'W':
            player->movementKeys[0] = false;
            player->stopMoving(false);
            break;
        case 39:
        case 'D':
            player->movementKeys[3] = false;
            player->stopMoving(false);
            break;
        case 40:
        case 'S':
            player->movementKeys[2] = false;
            player->stopMoving(false);
            break;
        }
    } else {
        switch (keyboard->key) {
        case 'L': {
            static Vehicle* v = static_cast<Vehicle*>(player->getTarget());
            static int next = v->getCurrentWaypoint();
            static const Path* path = v->getPathToFollow();
            irr::core::vector3d<float> waypoint(0.0f, 0.0f, 0.0f);
            path->getWaypoint(next++, waypoint);
            v->SetPosition(waypoint);
            path->getWaypoint(next - 1, waypoint);
            reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(player))->SetPosition(waypoint);
            break;
        }
        case 37:
        case 'A':
            if (unknown12)
                player->movementKeys[1] = true;
            else
                player->movementKeys[1] = false;
            break;
        case 38:
        case 'W':
            if (unknown12)
                player->movementKeys[0] = true;
            else
                player->movementKeys[0] = false;
            break;
        case 39:
        case 'D':
            if (unknown12)
                player->movementKeys[3] = true;
            else
                player->movementKeys[3] = false;
            break;
        case '2':
            reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(player))->setAnimationSpeedMultiplier(1);
            break;
        case 'P':
            if (Lock::getInstance()->target)
                player->addPhotoTarget(Lock::getInstance()->target);
            break;
        case 'T':
            car = static_cast<Vehicle*>(SpawnPoint::spawn(153));
            break;
        case 'U':
            AchievementManager::s_achievementManager->setNextAchievementAsCompleted();
            break;
        case 'V':
            car->immobilize();
            if (car->immobilized)
                car->mobilize();
            car->unknown984 = 1.0f;
            break;
        case 'X':
            static_cast<Character*>(player->getTarget())->setAnimation(162, 1.0f, false, false, false);
            break;
        case 122:
            CameraManager::getInstance()->getCamera()->setFarValue(
                CameraManager::getInstance()->getCamera()->getFarValue() - 100.0f);
            break;
        case 125: {
            const irr::core::vector3d<float> position = static_cast<SavePositionInterface*>(player)->position();
            Item::place(9, irr::core::vector3d<float>(position.X + 300.0f, position.Y, position.Z));
            break;
        }
        case 'Z':
            reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(player))->setAnimation(162, 1.0f, false, false, false);
            break;
        case 126:
            Item::removeAllPlacedItems();
            break;
        case 128:
            CameraManager::getInstance()->getCamera()->setFarValue(
                CameraManager::getInstance()->getCamera()->getFarValue() + 100.0f);
            break;
        case 133: {
            const int health = static_cast<SavePositionInterface*>(player)->getHealth() - 5;
            player->health = health >= 0 ? health : 0;
            break;
        }
        case 134: {
            SavePositionInterface* character = static_cast<SavePositionInterface*>(player);
            const int health = character->getHealth() + 5;
            player->health = health <= character->getMaxHealth() ? health : character->getMaxHealth();
            break;
        }
        case '0':
            player->clearPhotoTargets();
            break;
        case 40:
        case 'S':
            if (unknown12)
                player->movementKeys[2] = true;
            else
                player->movementKeys[2] = false;
            break;
        case '1':
            reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(player))->setAnimationSpeedMultiplier(10);
            break;
        case 'B':
            car = static_cast<Vehicle*>(SpawnPoint::spawn(39));
            break;
        case 'C':
            player->addCash(10000, 3000);
            break;
        case 'F':
            if (unknown16 != 0)
                handleAttackHeld();
            else
                handleAttackPressed();
            break;
        case 'G':
            car->unknown988 = -1.0f;
            break;
        case '6':
            if (car)
                car->resetDriver();
            break;
        case '7':
            if (car && car->getDriver()) {
                car->getDriver()->positionInVehicle(true);
                car->getDriver()->show();
            }
            break;
        case '8':
            if (car) {
                car->immobilize();
                car->resetDriver();
                if (car->getDriver()) {
                    car->getDriver()->positionInVehicle(true);
                    car->getDriver()->show();
                }
                car->openDoor(true);
            }
            break;
        case '9':
            GameObjectManager::s_gom->RemoveAndDestroy(car);
            car = 0;
            break;
        case '4':
            car = static_cast<Vehicle*>(SpawnPoint::spawn(112));
            break;
        case '5':
            if (car)
                car->openDoor(true);
            break;
        case '3':
            car = static_cast<Vehicle*>(Lock::getInstance()->target);
            break;
        case 'H':
            if (car->immobilized)
                car->mobilize();
            car->unknown984 = -1.0f;
            break;
        case 'J':
            car->unknown988 = 1.0f;
            break;
        case 'M':
            car = static_cast<Vehicle*>(SpawnPoint::spawn(5));
            break;
        case 'Y':
            if (car->immobilized)
                car->mobilize();
            car->unknown984 = 1.0f;
            break;
        }
    }
}
