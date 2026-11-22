void Vehicle::_processAIFlags()
{
    using irr::core::vector3d;
    typedef vector3d<float> vector3df;
    if (!(flags344 & 0x800u))
        return;
    EventManager* events = Application::GetInstance()->GetEventManager();
    if (flags344 & 0x08000000u)
        SoundManager::getInstance()->setSourcePos(241, sirenChannel, GetPosition());
    if (flags344 & 0x80u) {
        if (unknown132 == 1) {
            brake(1.0f);
        } else {
            Stop();
            {
                EvNPCVehicle event(23, this);
                events->raise(event);
            }
        }
        return;
    }
    if ((flags344 & 0x2000u) && aiTarget) {
        const float distanceSQ = aiTarget->GetPosition().getDistanceFromSQ(GetPosition());
        vector3df visiblePoint;
        if (distanceSQ < 9000000.0f && canSeeLevelObject(aiTarget, visiblePoint)) {
            if (!(flags344 & 0x4000u)) {
                flags344 |= 0x4000u;
                {
                    EvNPCVehicle event(18, this);
                    events->raise(event);
                }
                if (unknown240 == 3 && !(flags344 & 0x08000000u)) {
                    PlayerTest* player = PlayerTest::GetPlayer();
                    LevelObject* car = player->unknown312;
                    if (!car)
                        car = player->unknown368;
                    if (car != this || !PlayerTest::GetPlayer()->unknown372)
                        playSiren();
                }
            }
            if (flags344 & 0x100000u) {
                const vector3df targetPosition = aiTarget->GetPosition();
                const vector3df front = GetFront();
                const float offset = (irr::os::Randomizer::rand() & 1) ? -200.0f : 200.0f;
                destination.X = targetPosition.X + front.Y * offset;
                destination.Y = targetPosition.Y + front.X * offset;
                destination.Z = targetPosition.Z;
            } else if (flags344 & 0x200000u) {
                destination = aiTarget->GetPosition() + GetFront() * 300.0f;
            } else {
                destination = aiTarget->GetPosition();
            }
            if (distanceSQ < 2250000.0f && !(flags344 & 0x40000u) && aiTarget->GetSpeed() < 10.0f) {
                flags344 |= 0x40000u;
                {
                    EvNPCVehicle event(24, this);
                    events->raise(event);
                }
            } else if (flags344 & 0x40000u) {
                flags344 &= ~0x40000u;
                {
                    EvNPCVehicle event(25, this);
                    events->raise(event);
                }
            }
        } else if (flags344 & 0x4000u) {
            cleanupTargetDetection();
            if (flags344 & 0x40000u) {
                flags344 &= ~0x40000u;
                {
                    EvNPCVehicle event(25, this);
                    events->raise(event);
                }
            }
        }
    }
    if (aiTarget && !aiTarget->sceneNode)
        aiTarget = 0;

    vector3df steeringDirection;
    if ((((flags344 & 0x5000u) == 0x5000u) || (flags344 & 0x400000u)) && aiTarget) {
            if (flags344 & 0x400000u) {
                if (flags344 & 0x100000u) {
                    const vector3df targetPosition = aiTarget->GetPosition();
                    const vector3df front = GetFront();
                    const float offset = (irr::os::Randomizer::rand() & 1) ? -200.0f : 200.0f;
                    destination.X = targetPosition.X + front.Y * offset;
                    destination.Y = targetPosition.Y + front.X * offset;
                    destination.Z = targetPosition.Z;
                } else if (flags344 & 0x200000u) {
                    destination = aiTarget->GetPosition() + GetFront() * 300.0f;
                } else {
                    destination = aiTarget->GetPosition();
                }
            }
            if (flags344 & 0x80000u) {
                flags344 |= 8;
                brakeAmount = 1.0f;
            } else {
                accelerate(1.0f);
            }
            steeringDirection = destination - GetPosition();
            steeringDirection.getLength();
            if (steeringDirection.getLengthSQ() < 2250000.0f && aiTarget->GetSpeed() < 30.0f) {
                {
                    EvNPCVehicle event(24, this);
                    events->raise(event);
                }
            }
        } else if (flags344 & 0x100u) {
        Stop();
        if (static_cast<unsigned int>(waitElapsed) >= static_cast<unsigned int>(waitDuration)) {
            flags344 &= ~0x100u;
            {
                EvNPCVehicle event(5, this);
                events->raise(event);
            }
        }
    } else {
            steeringDirection = destination - GetPosition();
            const float distance = steeringDirection.getLength();
            if (unknown24->info->unknown84 && unknown240 == 0) {
                if (speed > 0.0f) {
                    if (distance < 500.0f) {
                        {
                            EvNPCVehicle event(1, this);
                            events->raise(event);
                        }
                        entryAnimationScale = 0.0f;
                        brake(1.0f);
                    } else if (distance < 1000.0f) {
                        brake((distance - 600.0f) / -400.0f + 1.0f);
                    } else {
                        if (flags344 & 0x400u)
                            accelerate(0.5f);
                        else if (flags344 & 0x200u)
                            accelerate(1.0f);
                    }
                } else {
                    if (flags344 & 0x400u)
                        accelerate(0.5f);
                    else if (flags344 & 0x200u)
                        accelerate(1.0f);
                    if (distance < 500.0f) {
                        {
                            EvNPCVehicle event(1, this);
                            events->raise(event);
                        }
                        entryAnimationScale = 0.0f;
                        brake(1.0f);
                    }
                    unknown24->info->unknown84 = false;
                }
            } else if (!(flags344 & 0x80000u)) {
                if (flags344 & 0x1000u)
                    accelerate(1.0f);
                else if (flags344 & 0x400u)
                    accelerate(0.5f);
                else if (flags344 & 0x200u)
                    accelerate(1.0f);
                if (distance < 500.0f) {
                    {
                        EvNPCVehicle event(1, this);
                        events->raise(event);
                    }
                    if (driveToLocationFlag) {
                        entryAnimationScale = 0.0f;
                        brake(1.0f);
                    }
                }
            }
            if (sensorContactCount && !(flags344 & 0x10001000u))
                brake(1.0f);
            if (flags344 & 0x80000u) {
                flags344 |= 8;
                brakeAmount = 1.0f;
            }
        }
    steeringDirection.rotateXYBy(90.0, vector3df());
    const float side = GetFront().dotProduct(steeringDirection);
    const vector3df adjustedSnapshot = adjustedDestination;
    const vector3df displacement = adjustedSnapshot - GetPosition();
    const float cosine = displacement.dotProduct(-GetFront()) /
        (displacement.getLength() * -GetFront().getLength());
    float angle = acosf(irr::core::clamp(cosine, -1.0f, 1.0f));
    if (static_cast<double>(displacement.getLengthSQ()) < 0.1)
        angle = 0.0f;
    if (flags344 & 0x80000u) {
        if (side > 0.0f)
            turn(false, 1.0f);
        else
            turn(true, 1.0f);
        if (vector3df(init372, init376, init380).dotProduct(GetFront()) < 0.0f || angle < 0.2f)
            flags344 &= ~0x80000u;
    } else if (!(flags344 & 2)) {
        const float amount = angle > 1.5707963705062866f ? 1.0f : angle / 1.5707963705062866f;
        if (side < 0.0f)
            turn(false, amount);
        else
            turn(true, amount);
    }
}
