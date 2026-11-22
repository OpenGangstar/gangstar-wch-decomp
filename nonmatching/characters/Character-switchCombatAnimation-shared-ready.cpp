bool Character::switchCombatAnimation()
{
    switch (currentAnimation) {
    case 86: case 175:
        if (movementFlags & 0x2000u) { movementFlags &= ~0x2000u; movementFlags |= 0x4000u; }
    case 87: case 88: case 162:
        setAnimation(-1,1.0f,false,false,false); return true;
    case 67:
        if (getWeapon()->getWeaponType()==7) getWeapon()->reloadRocket();
    case 51: case 56: case 60: case 68: case 75: case 76:
        goToCombatIdle(); return true;
    case 164:
        setAnimation(getSpecificAnimation(165),1.0f,true,false,false);
        movementFlags &= ~0x80000000u;
        if (isPlayer()) {
            PlayerTest::GetPlayer()->lastHitVehicle=0;
            PlayerTest::GetPlayer()->unknown384[0]=0;
            Application::GetInstance()->GetControlManager()->unlock();
            return true;
        }
            resetCollisions();
            static_cast<NPC*>(this)->setHitByCar(false);
            if (static_cast<int>(movementFlags << 1) < 0) {
                AIManager::getInstance()->addAI(static_cast<NPC*>(this),static_cast<gameloft::ai::StateID>(9));
                Application::GetInstance()->GetEventManager()->raise(EvNPC(static_cast<EvNPC::State>(22),static_cast<NPC*>(this)));
                movementFlags &= ~0x40000000u;
            }
        return true;
    case 83: case 84: case 85:
        if (isPlayer()) goToCombatIdle(); return true;
    case 81: case 82:
        setAnimation(89,1.0f,true,false,false); return true;
    case 78:
        shoot(1.0f,false); movementFlags &= ~0x10000000u; movementFlags |= 0x20000000u;
        setAnimation(73,1.0f,true,false,false); return true;
    case 77:
        shoot(1.0f,false); movementFlags &= ~0x10000000u; movementFlags |= 0x20000000u;
        setAnimation(73,1.0f,true,false,false); return true;
    case 70:
        shoot(1.0f,false); movementFlags &= ~0x10000000u; movementFlags |= 0x20000000u;
        setAnimation(64,1.0f,true,false,false); return true;
    case 69:
        shoot(1.0f,false); if (getWeapon()->getClip()<=0) setAnimation(138,1.0f,false,false,false); return true;
    case 146:
        movementFlags |= 0x4000000u;
        if (static_cast<int>(movementFlags << 10) < 0) shoot(1.0f,false);
        else setAnimation(73,1.0f,true,false,false); return true;
    case 145:
        movementFlags |= 0x4000000u;
        if (static_cast<int>(movementFlags << 10) < 0) shoot(1.0f,false);
        else setAnimation(64,1.0f,true,false,false); return true;
    case 143:
        movementFlags |= 0x4000000u; setAnimation(89,1.0f,true,false,false); return true;
    case 142:
        movementFlags |= 0x4000000u;
        if (static_cast<int>(movementFlags << 10) < 0) shoot(1.0f,false);
        else setAnimation(59,1.0f,true,false,false); return true;
    case 141:
        movementFlags |= 0x4000000u;
        if (static_cast<int>(movementFlags << 10) < 0) shoot(1.0f,false);
        else setAnimation(55,1.0f,true,false,false); return true;
    case 140:
        movementFlags |= 0x4000000u;
        if (static_cast<int>(movementFlags << 10) < 0) shoot(1.0f,false);
        else setAnimation(50,1.0f,true,false,false); return true;
    case 138:
        setAnimation(64,1.0f,true,false,false); return true;
    case 90: case 91: case 92: case 93: case 94: case 95: case 144:
        movementFlags &= ~0x10000000u; movementFlags |= 0x20000000u;
        setAnimation(89,1.0f,true,false,false); return true;
    case 66:
        setAnimation(169,1.0f,true,false,false);
        if (static_cast<int>(movementFlags << 9) < 0) { ready(1.0f); movementFlags &= ~0x400000u; } return true;
    case 64:
        if (getWeapon()->getWeaponType()==7) {
            movementFlags |= 0x4000000u;
            if (static_cast<int>(movementFlags << 10) < 0) shoot(1.0f,false);
        } return true;
    case 61: case 62:
        shoot(1.0f,false); movementFlags &= ~0x10000000u; movementFlags |= 0x20000000u;
        setAnimation(59,1.0f,true,false,false); return true;
    case 57:
        shoot(1.0f,false); movementFlags &= ~0x10000000u; movementFlags |= 0x20000000u;
        setAnimation(55,1.0f,true,false,false); return true;
    case 54: case 58: case 63: case 71: case 80: case 96:
        setAnimation(getSpecificAnimation(165),1.0f,true,false,false);
        if (static_cast<int>(movementFlags << 9) < 0) { ready(1.0f); movementFlags &= ~0x400000u; } return true;
    case 52: case 53:
        shoot(1.0f,false); movementFlags &= ~0x10000000u; movementFlags |= 0x20000000u;
        setAnimation(50,1.0f,true,false,false); return true;
    default:
        movementFlags &= ~0x10000000u; return false;
    }
}
