void PlayerTest::Update()
{
    using irr::core::vector3d;
    Application* application = Application::GetInstance();
    irr::IrrlichtDevice* device = application->GetDevice();
    Character* character = reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(this));
    if (character->turning && character->turnToward(character->turnDirection, character->turnSpeed)) {
        character->setAnimation(character->getSpecificAnimation(165), 1.0f, false, false, false);
        character->turnDirection = vector3d<float>(0.0f, 0.0f, 0.0f);
        character->turning = false;
    }
    int now = device->getTimer()->getRealTime();
    int previousTime = updateState.previousTime;
    if (!ScriptManager::getInstance()->isInCinematic() || (flags240 & 0x1000u))
        character->CheckDestination();
    else
        character->adjustedDestination = character->destination;
    if (physicAttributes->info->unknown0 == PhysicAttributes::MATERIAL_TYPE_DEATH_WATER)
        health = 0;
    if (!(flags240 & 0x4000u)) {
        if (!(flags240 & 0x2000u) && health <= 0) {
            if (!character->isInHitByCarAnimation()) {
                character->die(!(((flags240 & 0x400u) && static_cast<SavePositionInterface*>(this)->getVehicle()) || updateState.hitFlag));
                int soundChoice = lrand48() % 2;
                if (soundChoice == 0) {
                    SoundManager* sound = SoundManager::getInstance();
                    sound->unknown140 = true;
                    sound->playEx(138, 0, false, 1.0f, 0, true, 1.0f, 0);
                    sound->unknown140 = false;
                } else if (soundChoice == 1) {
                    SoundManager* sound = SoundManager::getInstance();
                    sound->unknown140 = true;
                    sound->playEx(127, 0, false, 1.0f, 0, true, 1.0f, 0);
                    sound->unknown140 = false;
                }
                goto afterWanted;
            }
            if ((flags240 & 0x4000u) == 0x4000u)
                goto checkWanted;
        }
    } else {
checkWanted:
        if (!(flags240 & 0x2000u)) {
            WantedLevelManager* wanted = WantedLevelManager::getInstance();
            wanted->unknown8 = 0;
            wanted->_processWantedLevel();
        }
    }
afterWanted:
    collisionBody->angularVelocity = 0.0f;
    if (flags240 & 0x800u) {
        if (vehicle) {
            if (sceneNode->isVisible())
                sceneNode->setVisible(false);
            if (shadowNode->isVisible())
                shadowNode->setVisible(false);
        }
    } else {
        character->checkForWeaponReload();
        if (flags240 & 0x8000u) {
            character->turnToward(vector3d<float>(character->adjustedDestination));
            character->unknown149Value = true;
            vector3d<float> position = character->GetPosition();
            position.Z = character->destination.Z;
            if (character->destination.getDistanceFromSQ(position) < character->destinationLimitSquared) {
                flags240 &= ~0x8000u;
                static_cast<SavePrimaryInterface*>(this)->Stop();
                character->startTurn(8.0f);
            }
        }
        unknown336 = (device->getTimer()->getRealTime() - unknown332) / 1000.0f;
        if (movementKeys[0] && unknown336 >= -0.001f)
            move(0.0f, 1.0f);
        if (movementKeys[1])
            move(1.5707964f, 1.0f);
        if (movementKeys[2])
            move(3.1415927f, 1.0f);
        if (movementKeys[3])
            move(-1.5707964f, 1.0f);
        if (targetLocked && target) {
            if (target->isDead()) {
                onObjectKilled(target);
                _SetTarget(0, !ScriptManager::getInstance()->isInCinematic());
            } else if (target->sceneNode && target->sceneNode->isVisible()) {
                if (!(flags240 & 0xfeu))
                    lockUpdatePending = orientTowards(character->GetPosition() - target->GetPosition());
            } else {
                _SetTarget(0, !ScriptManager::getInstance()->isInCinematic());
            }
            if (target) {
                vector3d<float> direction = target->GetPosition() - character->GetPosition();
                const float dot = direction.normalize().dotProduct(vector3d<float>(0.0f, 0.0f, 1.0f));
                if (__builtin_fabsf(dot) > cosf(0.2617994f))
                    _SetTarget(0, true);
            }
        }
        if (unknown368) {
            if (ScriptManager::getInstance()->isInCinematic() && unknown377) {
                unknown368 = 0;
            } else {
                if (!(flags240 & 0x1000u)) {
                    application->GetEventManager()->raise(EvNPCVehicle(10, static_cast<Vehicle*>(unknown312)));
                    flags240 |= 0x1000u;
                }
                if (unknown312 && !unknown368->isDead()) {
                    if (moveTo(*static_cast<Vehicle*>(unknown368)))
                        onTargetReached();
                } else {
                    onTargetCancelled();
                }
            }
        }
        if (unknown372)
            updateCarInteraction();
        else if (!vehicleVisibleInCinematic)
            finishedStopDriving();
        if (!sceneNode->isVisible())
            sceneNode->setVisible(true);
        if (!shadowNode->isVisible())
            shadowNode->setVisible(true);
        updateAnim(static_cast<float>(now - previousTime));
        vector3d<float> position = character->GetPosition();
        character->shadowBaseHeight = physicAttributes->GetHeight(character->GetPosition(), 0, false);
        sceneNode->setPosition(vector3d<float>(position.X, position.Y,
            character->shadowBaseHeight + character->unknown156));
        sceneNode->updateAbsolutePosition(false);
        if (character->isCurrentAnimation(-1) && health > 0)
            character->setAnimation(164, 1.0f, false, false, false);
        if (unknown260 && !character->isCurrentAnimation(15) &&
            !character->isCurrentAnimation(13) && !character->isCurrentAnimation(16) &&
            !character->isCurrentAnimation(14) && !character->isCurrentAnimation(30) &&
            !character->isCurrentAnimation(31) && !character->isCurrentAnimation(32) &&
            !character->isCurrentAnimation(33) && !character->isCurrentAnimation(7) &&
            !character->isCurrentAnimation(8)) {
            character->resetCollisions();
            unknown260 = false;
        }
        unknown332 = device->getTimer()->getRealTime();
    }
    application->GetControlManager()->update();
    if (character->unknown4 & 16u)
        vehicle->GetSpeed();
    else
        SetSpeed();
    CHudManager* hud = application->GetHudManager();
    if (closestShop && !unknown312) {
        int radius = closestShop->getRadius();
        float radiusSquared = radius * radius;
        float distance = (closestShop->GetPosition() - character->GetPosition()).getLengthSQ();
        if (radiusSquared > distance) {
            if (!hud->isNearShop())
                hud->nearShop();
        } else if (hud->isNearShop()) {
            hud->notNearShop();
            closestShop = 0;
        }
    } else if (hud->isNearShop()) {
        hud->notNearShop();
        closestShop = 0;
    }
    updateState.previousTime = now;
}
