// UNMATCHED: native extent 2108 bytes; linked comparison has 1935 differing bytes.
// Historical private-fixture method fragment; not a standalone compilation unit.
bool NPC::attackTarget()
{
    Application* app=Application::GetInstance();
    EventManager* events=app->GetEventManager();
    if(!target){
        acquireTarget();
        if(!target){goToIdle();events->raise(EvNPC(EvNPC::TargetLost,this));flags356&=~0x40u;return false;}
    }
    if(faction==2 && LevelObject::s_type[target->getObjectType()]!=8 && target->getHealth()<=25){
        target=0;events->raise(EvNPC(EvNPC::TargetIncapacitated,this));return false;
    }
    if(target->isDead()){target=0;return false;}
    if((LevelObject::s_type[target->getObjectType()]==5 || LevelObject::s_type[target->getObjectType()]==8) && static_cast<Character*>(target)->isCurrentAnimation(164))return false;
    if(isCurrentAnimation(164)||isCurrentAnimation(86)||isCurrentAnimation(175)||(movementFlags&0x100000u))return false;
    if(LevelObject::s_type[target->getObjectType()]==3 && weapon->getWeaponType()==0){goToVehicle(static_cast<Vehicle*>(target),true,true,false,true);return false;}
    if((LevelObject::s_type[target->getObjectType()]==5||LevelObject::s_type[target->getObjectType()]==8) && (static_cast<Character*>(target)->movementFlags&0x400u) && static_cast<Character*>(target)->getVehicle()){
        if(weapon->getWeaponType()==0){goToVehicle(static_cast<Character*>(target)->getVehicle(),true,true,false,true);return false;}
        unknown316=reinterpret_cast<unsigned int>(target);SetTarget(static_cast<Character*>(target)->getVehicle());
    }
    else if(LevelObject::s_type[target->getObjectType()]==3 && !static_cast<Vehicle*>(target)->getDriver()){
        if(unknown316){SetTarget(reinterpret_cast<LevelObject*>(unknown316));unknown316=0;}else events->raise(EvNPC(EvNPC::TargetLost,this));
    }
    const irr::core::vector3d<float> position=GetPosition();
    const irr::core::vector3d<float> targetPosition=target->GetPosition();
    const float distance=position.getDistanceFrom(targetPosition);
    WeaponManager* weapons=app->GetWeaponManager();
    if(weapon->getWeaponType()==0 && weaponType!=0 && distance>weapons->getWeaponInList(0,static_cast<PlayerTest::eContext>(-1))->getRange() && !(flags356&0x80u)){
        equipWeapon(false,false);goToCombatIdle();
    }
    if(weapon->getWeaponType()==8){
        turnTowardTarget(unknown432);
        unsigned int now=app->GetDevice()->getTimer()->getRealTime();
        if(!isFacingTarget(target) || !(now>static_cast<unsigned int>(unknown340+unknown344)))return false;
        unknown432=5.0f;
        if(distance>=weapon->getRange()*40 && distance<=weapon->getRange()*60)unknown252=20;
        else if(distance>weapon->getRange()*40)unknown252=13;
        else if(distance<weapon->getRange()*60)unknown252=25;
        else unknown252=0;
        bool attacked=(flags356&0x800000u)?false:attack();
        unknown340=now;unknown344=lrand48()%1000+1500;return attacked;
    }
    if(distance>weapon->getRange()){
        if(!isOutsideSearchRadius())runToTarget(0);
        unknown436=true;unknown252=0;return false;
    }
    if(weapon->getWeaponType()!=0 && distance<=weapons->getWeaponInList(0,static_cast<PlayerTest::eContext>(-1))->getRange()){
        equipWeapon(true,false);goToCombatIdle();
    }
    weapon->getWeaponType();
    if(weapon->getWeaponType()!=0){
        if(distance>=static_cast<float>(weapon->getRange())*0.4f && distance<=static_cast<float>(weapon->getRange())*0.6f){
            unknown396=0;unknown400=lrand48()%5;unknown252=weapon->getWeaponType()==8?20:16;
        }
    }else {unknown396=0;unknown400=0;unknown252=16;}
    bool attacked=false;
    if(flags356&0x800000u){unknown396=0;unknown400=1;attacked=true;}
    if(unknown396>unknown400){
        if((movementFlags&0x10000000u) && !(movementFlags&0x20000000u))return attacked;
        if(distance>static_cast<float>(weapon->getRange())*0.4f){
            if(!isOutsideSearchRadius())runToTarget(0);
            unknown252=weapon->getWeaponType()==8?13:0;
            if(lrand48()%1000>990){unknown396=0;unknown400=1;}
            return attacked;
        }
        if(distance<static_cast<float>(weapon->getRange())*0.6f){
            if(!isOutsideSearchRadius()){weapon->getWeaponType();runToTarget(static_cast<int>(static_cast<float>(weapon->getRange())*0.5f));}
            unknown432=10.0f;
            if(lrand48()%1000>990){unknown396=0;unknown400=1;}
            unknown252=weapon->getWeaponType()==8?25:100;
        }
        return attacked;
    }
    if((movementFlags&0x4000000u) && !isCurrentAnimation(getSpecificAnimation(188)) && !isCurrentAnimation(getSpecificAnimation(202))){
        turnTowardTarget(unknown432);
        unsigned int now=app->GetDevice()->getTimer()->getRealTime();
        if(isFacingTarget(target) && now>static_cast<unsigned int>(unknown340+unknown344)){
            unknown432=5.0f;
            if(!(flags356&0x800000u))attacked=attack();
            unknown340=now;++unknown396;
            if(weapon->getWeaponType()==0)unknown344=lrand48()%(unknown408-unknown404)+unknown404;
            else unknown344=lrand48()%1000+1500;
        }
    }else goToCombatIdle();
    return attacked;
}
