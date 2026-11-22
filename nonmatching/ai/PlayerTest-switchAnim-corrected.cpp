void PlayerTest::switchAnim()
{
    if(pendingAnimation248!=-1) {
        static_cast<SavePositionInterface*>(this)->setAnimation(pendingAnimation248,1.0f,true,true,false);
        pendingAnimation248=-1;
        return;
    }
    Character* character=reinterpret_cast<Character*>(&static_cast<SavePositionInterface&>(*this));
    if(character->switchCombatAnimation()) return;
    switch(currentAnimation128) {
    case 1: case 2: case 3: case 4:
        if(static_cast<int>(flags240<<12)<0) {
            switch(lrand48()%3) {
            case 0: {
                SoundManager* sound=SoundManager::getInstance();
                sound->unknown140=true;
                sound->playEx(89,0,false,1.0f,0,true,1.0f,0);
                sound->unknown140=false;
                break;
            }
            case 1: {
                SoundManager* sound=SoundManager::getInstance();
                sound->unknown140=true;
                sound->playEx(81,0,false,1.0f,0,true,1.0f,0);
                sound->unknown140=false;
                break;
            }
            case 2: {
                SoundManager* sound=SoundManager::getInstance();
                sound->unknown140=true;
                sound->playEx(70,0,false,1.0f,0,true,1.0f,0);
                sound->unknown140=false;
                break;
            }
            }
            Vehicle* car=static_cast<Vehicle*>(unknown312);
            car->openDoorFromInside(true);
            car=static_cast<Vehicle*>(unknown312);
            car->getDriver()->setAnimation(car->getLeftEjectAnimation(),1.0f,false,true,false);
            flags240&=~0x80000u;
            unknown372=13;
        } else {
            unknown372=5;
            static_cast<SavePositionInterface*>(this)->setAnimation(static_cast<Vehicle*>(unknown312)->getSeatedAnimation(),1.0f,false,false,false);
        }
        break;
    case 7: case 8: {
        irr::core::quaternion rotation;
        const irr::core::vector3d<float>& up=irr::core::vector3d<float>(0,0,1);
        const irr::core::matrix4& matrix=sceneNode->getAbsoluteTransformation();
        rotation.rotationFromTo(up,irr::core::vector3d<float>(matrix[8],matrix[9],matrix[10]));
        static_cast<SavePositionInterface*>(this)->SetRotation(rotation*static_cast<SavePositionInterface*>(this)->GetRotation());
        unknown372=11;
        static_cast<SavePositionInterface*>(this)->setAnimation(-1,1.0f,false,false,false);
        break;
    }
    case 9: case 10: case 11: case 12: {
        Vehicle* car=static_cast<Vehicle*>(unknown312);
        if(car) {
            bool left=car->isLeftDoor(reinterpret_cast<irr::scene::ISceneNode*>(unknown324));
            car=static_cast<Vehicle*>(unknown312);
            if(!car->isDoorClosed(left)) static_cast<Vehicle*>(unknown312)->closeDoor(left);
            setAnim(getCarAnimName(static_cast<Vehicle*>(unknown312)->getCloseDoorAnim(),left),false,false,false,1.0f);
            car=static_cast<Vehicle*>(unknown312);
            *reinterpret_cast<unsigned int*>(unknown132+16) = *reinterpret_cast<const unsigned int*>(&car->doorAnimationScale);
            if(!ScriptManager::getInstance()->isInCinematic()) {
                left=!left;
                if(static_cast<Vehicle*>(unknown312)->isDoorOpened(left)) static_cast<Vehicle*>(unknown312)->closeDoor(left);
            }
        }
        break;
    }
    case 13: case 15: {
        unknown372=7;
        irr::core::quaternion rotation;
        const irr::core::vector3d<float>& up=irr::core::vector3d<float>(0,0,1);
        const irr::core::matrix4& matrix=sceneNode->getAbsoluteTransformation();
        rotation.rotationFromTo(up,irr::core::vector3d<float>(matrix[8],matrix[9],matrix[10]));
        static_cast<SavePositionInterface*>(this)->SetRotation(rotation*static_cast<SavePositionInterface*>(this)->GetRotation());
        static_cast<SavePositionInterface*>(this)->setAnimation(character->getSpecificAnimation(165),1.0f,true,false,false);
        break;
    }
    case 14: case 16: {
        unknown372=7;
        irr::core::quaternion rotation;
        const irr::core::vector3d<float>& up=irr::core::vector3d<float>(0,0,1);
        const irr::core::matrix4& matrix=sceneNode->getAbsoluteTransformation();
        rotation.rotationFromTo(up,irr::core::vector3d<float>(matrix[8],matrix[9],matrix[10]));
        static_cast<SavePositionInterface*>(this)->SetRotation(rotation*static_cast<SavePositionInterface*>(this)->GetRotation());
        static_cast<SavePositionInterface*>(this)->setAnimation(character->getSpecificAnimation(165),1.0f,true,false,false);
        break;
    }
    case 30: case 31: case 32: case 33:
        unknown372=16;
    case 17: case 18: case 19: case 20: case 21:
        static_cast<SavePositionInterface*>(this)->setAnimation(-1,1.0f,false,false,false);
        break;
    case 22: case 23:
        if(static_cast<Vehicle*>(unknown312)->getDriver()) {unknown372=12;break;}
    case 26: case 28:
        unknown372=3;
        break;
    case 54: case 58: case 63: case 96:
        if(combatMode) character->ready(1.0f);
        else static_cast<SavePositionInterface*>(this)->setAnimation(character->getSpecificAnimation(165),1.0f,true,false,false);
        break;
    case 190: case 193: case 198: case 204: case 207: case 212:
        static_cast<SavePositionInterface*>(this)->setAnimation(character->getSpecificAnimation(165),1.0f,true,false,false);
        if(combatMode || targetLocked) character->ready(1.0f);
        break;
    }
    flags240&=~0x200u;
}
