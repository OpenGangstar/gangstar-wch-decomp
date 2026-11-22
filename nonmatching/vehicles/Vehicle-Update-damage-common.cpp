void Vehicle::Update(int elapsed)
{
    using irr::core::vector3d;
    using irr::core::quaternion;
    using irr::core::clamp;
    if (explosionFinished) {
        if (!unknown28) {
            unknown960Word += elapsed;
            int alpha = clamp(static_cast<int>(255.0f + -255.0f * (static_cast<float>(unknown960Word) / 3000.0f)), 0, 255);
            if (alpha < 255) {
                if (enabledSceneNode) {
                    GS3DStuff::SetMaterialType(enabledSceneNode, static_cast<irr::video::E_MATERIAL_TYPE>(25));
                    GS3DStuff::SetAlpha(enabledSceneNode, alpha, static_cast<GS3DStuff::eColorType>(0));
                }
                GS3DStuff::SetMaterialType(sceneNode, static_cast<irr::video::E_MATERIAL_TYPE>(25));
                GS3DStuff::SetAlpha(sceneNode, alpha, static_cast<GS3DStuff::eColorType>(0));
                if (!alpha) {
                    unknown4 |= 0x800;
                    return;
                }
            }
    }
    if (explosionFinished) {
        if (flags344 & 0x2000000u) {
            tagForKill(false);
            ScriptManager::getInstance()->taggedKilled();
        }
        irr::scene::ITimelineController* timeline = (*repairGlassNode->getAnimators().begin())->getTimelineCtrl();
        if (timeline) {
            timeline->jumpTo(timeline->startTime);
            timeline->setScale(0);
        }
        timeline = (*repairLightNode->getAnimators().begin())->getTimelineCtrl();
        if (timeline) {
            timeline->jumpTo(timeline->startTime);
            timeline->setScale(0);
        }
        if (skidSoundPlaying) {
            SoundManager::getInstance()->stop(119, -1, false);
            skidSoundPlaying = false;
        }
        return;
    }
    }
    const PhysicInfo* information = unknown24->info;
    const int deathWater = PhysicAttributes::MATERIAL_TYPE_DEATH_WATER;
    if (information[0].unknown0 != deathWater && information[1].unknown0 != deathWater
        && information[2].unknown0 != deathWater && information[3].unknown0 != deathWater
        && information[4].unknown0 != deathWater) {
        if (repairLightNode && isDead()) {
            unknown924 += elapsed;
            if (unknown924 > 4999) {
                unknown924 = 0;
                if (Lock::getInstance()->target == this)
                    Lock::getInstance()->setTarget(0);
                explode();
            }
            repairLightNode->setVisible(true);
            GS3DStuff::SetMaterialFlag(repairLightNode, static_cast<irr::video::E_MATERIAL_FLAG>(2), true);
            irr::scene::ITimelineController* timeline = (*repairLightNode->getAnimators().begin())->getTimelineCtrl();
            if (timeline) {
                timeline->jumpTo(static_cast<int>((timeline->endTime + timeline->startTime) * 0.5f));
                timeline->setScale(1);
            }
            if (!skidSoundPlaying && !explosionFlag) {
                SoundManager* sounds = SoundManager::getInstance();
                sounds->unknown140 = true;
                int channel = sounds->playEx(119, 0, true, 1, 0, false, 1, 0);
                sounds->unknown140 = false;
                if (channel >= 0)
                    skidSoundPlaying = true;
            }
            repairGlassNode->setVisible(true);
            timeline = (*repairGlassNode->getAnimators().begin())->getTimelineCtrl();
            if (timeline) {
                timeline->jumpTo(static_cast<int>((timeline->endTime + timeline->startTime) * 0.5f));
                timeline->setScale(1);
            }
        } else {
            const float fraction = static_cast<float>(health) / static_cast<float>(maxHealth);
            if (repairGlassNode && fraction < 0.3 && fraction > 0.0f) {
                GS3DStuff::SetMaterialFlag(repairGlassNode, static_cast<irr::video::E_MATERIAL_FLAG>(2), false);
                repairGlassNode->setVisible(true);
                irr::scene::ITimelineController* timeline = (*repairGlassNode->getAnimators().begin())->getTimelineCtrl();
                if (timeline) {
                    timeline->jumpTo(static_cast<int>((timeline->endTime + timeline->startTime) * 0.5f));
                    timeline->setScale(1);
                }
            } else {
                irr::scene::ITimelineController* timeline = (*repairGlassNode->getAnimators().begin())->getTimelineCtrl();
                if (timeline) {
                    timeline->jumpTo(timeline->startTime);
                    timeline->setScale(0);
                }
                timeline = (*repairLightNode->getAnimators().begin())->getTimelineCtrl();
                if (timeline) {
                    timeline->jumpTo(timeline->startTime);
                    timeline->setScale(0);
                }
                if (skidSoundPlaying) {
                    SoundManager::getInstance()->stop(119, -1, false);
                    skidSoundPlaying = false;
                }
            }

        }
        if (repairMaterialNode && !repairFlag420
                && static_cast<float>(health) / static_cast<float>(maxHealth) < 0.3) {
                repairMaterialNode->getMaterial(0).setTexture(0, damageTexture);
                repairFlag420 = true;
            }
    }
    if (unknown506 && unknown507 && unknown508 && unknown509) {
        health = 0;
        explosionFinished = true;
        if (PlayerTest::GetPlayer()->getVehicle() == this)
            PlayerTest::GetPlayer()->health = 0;
        stopDriving();
        Stop();
        {
            EvVehicleDestroyed event(this);
            Application::GetInstance()->GetEventManager()->raise(event);
        }
        stopSiren();
        cleanupTargetDetection();
        explosionFlag = true;
        AchievementManager::s_achievementManager->recordDestroyedVehicle(*this);
    }
    CheckDestination();
    GetPosition();
    unknown132 = getVelDirec();
    unsigned int time = Application::GetInstance()->GetDevice()->getTimer()->getRealTime();
    if (flags344 & 0x20000u) {
        if (*reinterpret_cast<const float*>(unknown128) < vector3d<float>(unknown116, unknown120, unknown124).getLength() / 1000.0f * 3600.0f)
            flags344 &= ~0x20000u;
    }
    if (!(flags344 & 0x800u) && skidAmount <= 0) {
        if ((unknown132 != 1 && unknown132 != 2) && init136 == 1
            && (unknown509 || unknown508 || unknown507 || unknown506) && !(flags344 & 0x20000u)) {
            Stop();
            flags344 |= 96;
            init348 = time;
        }
        if ((flags344 & 32u) && time - init348 > 199)
            flags344 &= ~96u;
    }
    _processAIFlags();
    waitElapsed += elapsed;
    if (unknown984 > 0) accelerate(unknown984);
    else if (unknown984 < 0) brake(-unknown984);
    if (unknown988 > 0) turn(true, unknown988);
    else if (unknown988 < 0) turn(false, -unknown988);
    if (unknown992 > 0) turn(true, unknown992);
    else if (unknown992 < 0) turn(false, -unknown992);
    const float elapsedFloat = static_cast<float>(elapsed);
    init389 = false;
    init392 = 0;
    if (flags344 & 1) {
        if (unknown132 == 3) {
            init392 = init164 * accelerationAmount;
        } else {
            const gameloft::vehicle::gear_profiles::GearProfile& profile = gameloft::vehicle::gear_profiles::profiles[gearProfile];
            float low = profile.accelerationFactors[gear - 1] * init156;
            float high = profile.accelerationFactors[gear] * init156;
            float fraction;
            if (gear == 1)
                fraction = (speed / 1000.0f * 3600.0f) / static_cast<float>(profile.shiftSpeeds[gear - 1]);
            else
                fraction = ((speed / 1000.0f * 3600.0f) - static_cast<float>(profile.shiftSpeeds[gear - 2]))
                    / static_cast<float>(profile.shiftSpeeds[gear - 1] - profile.shiftSpeeds[gear - 2]);
            fraction = clamp(fraction, 0.0f, 1.0f);
            init392 = ((high - low) * fraction + low) * accelerationAmount;
        }
        init396 += elapsedFloat / -100.0f;
        if (init396 < 0) init396 = 0;
        wakeVehicleUpdateBody(collisionBody);
    } else if (flags344 & 2) {
        if (init396 < 80) init396 = 80;
        if (unknown132 == 1) {
            init392 = -init164 * brakeAmount;
        } else if (flags344 & 0x800u) {
            if (!(unknown511 & 1)) Stop();
            flags344 |= 2;
        } else if (!(flags344 & 0x40u)) {
            init392 = -init160 * brakeAmount;
            wakeVehicleUpdateBody(collisionBody);
        }
    } else if (flags344 & 8) {
        init392 = -init160 * brakeAmount;
    } else {
        init389 = true;
    }
    float magnitude = vector3d<float>(unknown116, unknown120, unknown124).getLength();
    if (!(flags344 & 4)) {
        float drag = magnitude * 100.0f / 200.0f;
        unknown56 += (-basisY.X * drag) * elapsedFloat;
        unknown60 += (-basisY.Y * drag) * elapsedFloat;
        unknown64 += (-basisY.Z * drag) * elapsedFloat;
        reinterpret_cast<vector3d<float>*>(&unknown56)->normalize();
    }
    speed = magnitude;
    float kph = magnitude / 1000.0f * 3600.0f;
    if (PlayerTest::GetPlayer()->getVehicle() == this)
        AchievementManager::s_achievementManager->recordVehicleSpeed(static_cast<int>(kph));
    if (!(unknown511 & 1) && leftCollisionBody && rightCollisionBody) {
        if (speed < 0.1f && init389) {
            rightCollisionBody->linearVelocity.y = rightCollisionBody->linearVelocity.x = 0;
            rightCollisionBody->angularVelocity = 0;
            leftCollisionBody->linearVelocity.y = leftCollisionBody->linearVelocity.x = 0;
            leftCollisionBody->angularVelocity = 0;
            collisionBody->linearVelocity.y = collisionBody->linearVelocity.x = 0;
            collisionBody->angularVelocity = 0;
        }
    }
    if (leftCollisionBody && rightCollisionBody) {
        float squared = vector3d<float>(unknown116, unknown120, unknown124).getLengthSQ();
        unknown752 += squared;
        unknown756 += squared - vector3d<float>(init104, init108, init112).getLengthSQ();
        vector3d<float> angles;
        wheelNodes[2]->getRotation().toEulerDegree(angles);
        angles *= 0.01745329238474369f;
        float sign = unknown132 == 3 ? 1.0f : -1.0f;
        float roll = (sign * static_cast<float>(__builtin_sqrtf(rightCollisionBody->linearVelocity.x * rightCollisionBody->linearVelocity.x + rightCollisionBody->linearVelocity.y * rightCollisionBody->linearVelocity.y)) / 25.0f)
            * elapsedFloat / 16.66666603088379f;
        wheelNodes[2]->setRotation(quaternion(angles.X + roll, angles.Y + 0.0f, angles.Z + 0.0f));
        wheelNodes[3]->getRotation().toEulerDegree(angles);
        angles *= 0.01745329238474369f;
        sign = unknown132 == 3 ? 1.0f : -1.0f;
        roll = (sign * static_cast<float>(__builtin_sqrtf(rightCollisionBody->linearVelocity.x * rightCollisionBody->linearVelocity.x + rightCollisionBody->linearVelocity.y * rightCollisionBody->linearVelocity.y)) / 25.0f)
            * elapsedFloat / 16.66666603088379f;
        wheelNodes[3]->setRotation(quaternion(angles.X + roll, angles.Y + 0.0f, angles.Z + 0.0f));
        sign = unknown132 == 3 ? 1.0f : -1.0f;
        init980 += (sign * static_cast<float>(__builtin_sqrtf(leftCollisionBody->linearVelocity.x * leftCollisionBody->linearVelocity.x + leftCollisionBody->linearVelocity.y * leftCollisionBody->linearVelocity.y)) / 25.0f)
            * elapsedFloat / 16.66666603088379f;
        quaternion steering;
        quaternion wheel;
        steering.fromAngleAxis(-reinterpret_cast<b2RevoluteJoint*>(init644)->GetJointAngle(), vector3d<float>(0, 0, 1));
        wheel.fromAngleAxis(init980, vector3d<float>(1, 0, 0));
        wheelNodes[0]->setRotation(steering * wheel);
        wheelNodes[1]->setRotation(steering * wheel);
    }
    init136 = unknown132;
    unsigned int displayedSpeed = static_cast<unsigned int>(kph);
    _shiftGears(displayedSpeed);
    playDriveSfx(displayedSpeed);
    if (kph > 10) {
        if (isDoorOpened(true) && !leftDoorTransition) closeDoor(true);
        if (isDoorOpened(false) && !rightDoorTransition) closeDoor(false);
    }
    if (carSoundMode)
        UpdateCarSounds();
}
