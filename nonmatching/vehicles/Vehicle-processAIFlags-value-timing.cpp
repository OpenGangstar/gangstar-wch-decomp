// UNMATCHED: 3192 function bytes versus 3220 native; no native-address link.
// Historical private-fixture method fragment; not a standalone compilation unit.
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
                events->raise(EvNPCVehicle(23, this));
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
                    events->raise(EvNPCVehicle(18, this));
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
                const float targetY = targetPosition.Y;
                const float targetX = targetPosition.X;
                const vector3df front = GetFront();
                const float frontX = front.X;
                const float frontY = front.Y;
                float resultX;
                float productY;
                if ((irr::os::Randomizer::rand() & 1) == 0) {
                    const float productX = frontY * 200.0f;
                    resultX = targetX + productX;
                    productY = frontX * 200.0f;
                } else {
                    const float productX = frontY * -200.0f;
                    resultX = targetX + productX;
                    productY = frontX * -200.0f;
                }
                destination.X = resultX;
                destination.Y = productY + targetY;
                destination.Z = targetPosition.Z;
            } else if (flags344 & 0x200000u) {
                destination = aiTarget->GetPosition() + GetFront() * 300.0f;
            } else {
                destination = aiTarget->GetPosition();
            }
            if (distanceSQ < 2250000.0f && !(flags344 & 0x40000u) && aiTarget->GetSpeed() < 10.0f) {
                flags344 |= 0x40000u;
                {
                    events->raise(EvNPCVehicle(24, this));
                }
            } else if (flags344 & 0x40000u) {
                flags344 &= ~0x40000u;
                {
                    events->raise(EvNPCVehicle(25, this));
                }
            }
        } else if (flags344 & 0x4000u) {
            cleanupTargetDetection();
            if (flags344 & 0x40000u) {
                flags344 &= ~0x40000u;
                {
                    events->raise(EvNPCVehicle(25, this));
                }
            }
        }
    }
    if (aiTarget && !aiTarget->sceneNode)
        aiTarget = 0;

    float steeringX = 0.0f;
    float steeringY = 0.0f;
    float steeringZ = 0.0f;
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
            const vector3df pursuitDirection = destination - GetPosition();
            steeringX = pursuitDirection.X;
            steeringY = pursuitDirection.Y;
            steeringZ = pursuitDirection.Z;
            pursuitDirection.getLength();
            if (pursuitDirection.getLengthSQ() < 2250000.0f && aiTarget->GetSpeed() < 30.0f) {
                {
                    events->raise(EvNPCVehicle(24, this));
                }
            }
        } else if (flags344 & 0x100u) {
        Stop();
        if (static_cast<unsigned int>(waitElapsed) >= static_cast<unsigned int>(waitDuration)) {
            flags344 &= ~0x100u;
            {
                events->raise(EvNPCVehicle(5, this));
            }
        }
    } else {
            const vector3df destinationDirection = destination - GetPosition();
            steeringX = destinationDirection.X;
            steeringY = destinationDirection.Y;
            steeringZ = destinationDirection.Z;
            const float distance = destinationDirection.getLength();
            if (unknown24->info->unknown84 && unknown240 == 0) {
                if (speed > 0.0f) {
                    if (distance < 500.0f) {
                        {
                            events->raise(EvNPCVehicle(1, this));
                        }
                        pathToFollow = 0;
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
                            events->raise(EvNPCVehicle(1, this));
                        }
                        pathToFollow = 0;
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
                        events->raise(EvNPCVehicle(1, this));
                    }
                    if (driveToLocationFlag) {
                        pathToFollow = 0;
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
    vector3df steeringDirection(steeringX, steeringY, steeringZ);
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
        const vector3df& turnFrontSnapshot = GetFront();
        if (((init372 * turnFrontSnapshot.X + init376 * turnFrontSnapshot.Y) + init380 * turnFrontSnapshot.Z) < 0.0f || angle < 0.2f)
            flags344 &= ~0x80000u;
    } else if (!(flags344 & 2)) {
        const float amount = angle > 1.5707963705062866f ? 1.0f : angle / 1.5707963705062866f;
        if (side < 0.0f)
            turn(false, amount);
        else
            turn(true, amount);
    }
}
