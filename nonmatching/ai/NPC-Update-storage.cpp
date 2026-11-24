// UNMATCHED: 3044 function/input bytes versus 3012 native.
// Reconstructs mapped storage and the post-getVehicle category reload.
// Requires the documented historical private fixture, not a standalone TU.
#include "../characters/PhysicInfo.h"
#include "../core/Physics.h"
void operator delete(void*) throw();
void NPC::Update(int elapsed)
{
    unknown296=irr::core::vector3d<float>(0.0f,0.0f,0.0f);
    if(flags356&0x2000u) {
        bool lost=!target;
        if(target) {
            LevelObject* initialTarget=target;
            PlayerTest* player=PlayerTest::GetPlayer();
            if(player && initialTarget==reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(player))) {
                player=PlayerTest::GetPlayer();
                if(!(player->flags240&0x400u) || !static_cast<SavePositionInterface*>(player)->getVehicle()) lost=true;
            }
            if(!lost) {
                int type=LevelObject::s_type[target->getObjectType()];
                if(type==5 && (!(static_cast<Character*>(target)->movementFlags&0x400u) || !static_cast<Character*>(target)->getVehicle())) lost=true;
                else if(LevelObject::s_type[target->getObjectType()]==3 && !static_cast<Vehicle*>(target)->getDriver()) lost=true;
            }
        }
        if(lost) {
            flags356&=~0x2000u;
            Application::GetInstance()->GetEventManager()->raise(EvNPC(static_cast<EvNPC::State>(13),this));
        }
    }
    if(ScriptManager::getInstance()->isInCinematic() && !unknown28 && faction!=3 && (flags356&0x40u)) {
        flags356&=~0x40u;
        Application::GetInstance()->GetEventManager()->raise(EvNPC(static_cast<EvNPC::State>(13),this));
    }
    if(isOutsideSearchRadius()) {
        Weapon* current=getWeapon();
        if(current && current->getWeaponType()!=0) {
            int range=current->getRange()*2;
            int cone=current->getCone();
            if(!isTargetInRange(static_cast<float>(range),static_cast<float>(cone)))
                Application::GetInstance()->GetEventManager()->raise(EvNPC(static_cast<EvNPC::State>(26),this));
        }
    }
    if(ScriptManager::getInstance()->isInCinematic() && !(flags356&0x2800u))
        adjustedDestination=destination;
    else CheckDestination();
    Character::Update(elapsed);
    PlayerTest* player=PlayerTest::GetPlayer();
    if(!isDead()) {
        if(flags356&0x80u) _detect();
        collisionBody->angularVelocity=0.0f;
        collisionBody->linearVelocity.y=0.0f;
        collisionBody->linearVelocity.x=0.0f;
        if(isDown() && health>0) {
            UpdateCarPosIfUnderWheel();
            unknown448+=elapsed;
            if(isUnderCar()) {
                if(unknown448>999) {
                    applyDamage(static_cast<int>(static_cast<float>(getMaxHealth())*0.29999998211860657f),lastHitVehicle,true);
                    unknown448=0;
                }
            } else if(!isCurrentAnimation(164)) {
                lastHitVehicle=0;
                if(unknown448>2999) {
                    setAnimation(164,1.0f,false,false,false);
                    unknown448=0;
                }
            }
        }
    } else {
        if(collisionBody && isCurrentAnimation(-1)) {
            if(collisionBody->data) {
                ::operator delete(collisionBody->data);
                collisionBody->data=0;
            }
            PhysicAttributes::s_world->DestroyBody(collisionBody);
            collisionBody=0;
        }
        if(flags356&0x100000u) {
            tagForKill(false);
            ScriptManager::getInstance()->taggedKilled();
        }
    }
    if(currentAnimation!=-1 && unknown164Pointer) {
        if(updateAnimation(static_cast<float>(elapsed))) switchAnim();
        if(!(unknown4&2u)) return;
    }
    if(!unknown28 && isDead() && isDown()) {
        cleanTimer+=elapsed;
        int alpha=irr::core::clamp(static_cast<int>(static_cast<float>(cleanTimer)/3000.0f*-255.0f+255.0f),0,255);
        if(alpha<255) {
            GS3DStuff::SetMaterialType(sceneNode,static_cast<irr::video::E_MATERIAL_TYPE>(25));
            GS3DStuff::SetAlpha(sceneNode,static_cast<unsigned char>(alpha),GS3DStuff::Color0);
            if(alpha==0) {
                GS3DStuff::forceDespawn(this);
                return;
            }
        }
    }
    if(isDown()) {
        UpdateSceneNode();
        if(lastHitVehicle) unknown448=0;
        return;
    }
    if(unknown24->info->unknown0==PhysicAttributes::MATERIAL_TYPE_CLIFF) {
        collisionBody->linearVelocity.y+=unknown24->info->vector48.Y*5.0f;
        collisionBody->linearVelocity.x+=unknown24->info->vector48.X*5.0f;
    }
    float y,x;
    {
        const irr::core::vector3d<float>& position=GetPosition();
        y=position.Y;
        x=position.X;
    }
    shadowBaseHeight=unknown24->GetHeight(GetPosition(),0,false);
    sceneNode->setPosition(irr::core::vector3d<float>(x,y,shadowBaseHeight+unknown156));
    sceneNode->updateAbsolutePosition(false);
    if(isDead()) { UpdateSceneNode(); return; }
    Vehicle* avoidVehicle=reinterpret_cast<Vehicle*>(unknown320);
    if(avoidVehicle && avoidVehicle->isEnabled()) {
        if(avoidVehicle->explosionFlag || avoidVehicle->explosionFinished) flags356|=2u;
        else if(!(movementFlags&0x10000u) && !(flags356&0x800u)) {
            float distance=(GetPosition()-reinterpret_cast<Vehicle*>(unknown320)->GetPosition()).getLengthSQ();
            if(distance>=2250000.0f || (target && target->GetSpeed()>30.0f))
                goToVehicle(reinterpret_cast<Vehicle*>(unknown320),true,true,true,false);
        }
    }
    if(unknown264 && (unknown264==reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(player)) ||
        LevelObject::s_type[unknown264->getObjectType()]==1 || LevelObject::s_type[unknown264->getObjectType()]==5)) {
        if((static_cast<Character*>(unknown264)->movementFlags&0x10000000u) && static_cast<Character*>(unknown264)->target!=target)
            attackTarget(static_cast<Character*>(unknown264)->target);
        else {
            SetTarget(0);
            if(unknown264==reinterpret_cast<Character*>(static_cast<SavePositionInterface*>(player))) {
                if(static_cast<SavePrimaryInterface*>(player)->getVehicle()) {
                    if((player->flags240&0x400u) && static_cast<SavePositionInterface*>(player)->getVehicle())
                        goToVehicle(static_cast<SavePrimaryInterface*>(player)->getVehicle(),false,true,true,false);
                } else if(getVehicle() && !(unknown4&2u)) getOutOfVehicle(true,false);
            }
        }
    }
    if(flags356&0x800u) {
        Vehicle* previous=vehicle;
        if(previous) {
            vehicle=0;
            goToVehicle(previous,entryDoor==previous->leftDoor,(flags356&2u)!=0,true,false);
        } else flags356&=~0x800u;
    }
    if(flags356&0x2000u) {
        Vehicle* previous=vehicle;
        if(previous) {
            vehicle=0;
            goToVehicle(previous,entryDoor==previous->leftDoor,(flags356&2u)!=0,false,true);
        } else flags356&=~0x2000u;
    }
    if(!(flags356&0x400u)) {
        if((flags356&0x840u)==0x40u && !(movementFlags&0x30000u) && !(flags356&0x2000u)) {
            if(!attackState452 && !isDown()) triggerCombatSFX(unknown412);
            attackTarget();
        } else if((flags356&1u) || (flags356&2u)) {
            turnToward(irr::core::vector3d<float>(adjustedDestination));
            unknown149[0]=true;
            float dx=destination.X-x;
            float dy=destination.Y-y;
            if(dx*dx+dy*dy<static_cast<float>(destinationLimitSquared)) {
                flags356&=~3u;
                if(!(flags356&0x400000u)) Stop();
                if(flags356&0x800u) {
                    if(vehicle && !vehicle->explosionFlag && !vehicle->explosionFinished) {
                        if(vehicle->GetSpeed()<=10.0f) {
                            if(vehicle) {
                                irr::scene::ISceneNode* door=vehicle->getNearestDoorDummy(GetPosition());
                                irr::core::vector3d<float> entryPosition(door->getAbsolutePosition().X,door->getAbsolutePosition().Y,GetPosition().Z);
                                SetPosition(entryPosition);
                                enterVehicle(door==vehicle->leftDoor,true,false);
                            }
                            flags356&=~0x800u;
                        } else if(!vehicle) flags356&=~0x800u;
                    } else flags356&=~0x800u;
                } else if(flags356&0x2000u) {
                    if(vehicle) {
                        if(vehicle->GetSpeed()<=10.0f) {
                            if(vehicle) {
                                irr::scene::ISceneNode* door=vehicle->getNearestDoorDummy(GetPosition());
                                irr::core::vector3d<float> entryPosition(door->getAbsolutePosition().X,door->getAbsolutePosition().Y,GetPosition().Z);
                                SetPosition(entryPosition);
                                enterVehicle(door==vehicle->leftDoor,false,true);
                            }
                            flags356&=~0x2000u;
                        } else if(!vehicle) flags356&=~0x2000u;
                    } else flags356&=~0x2000u;
                } else {
                    flags356|=0x4000u;
                    EvNPC event(static_cast<EvNPC::State>(1),this);
                    Application::GetInstance()->GetEventManager()->raise(event);
                    startTurn(8.0f);
                }
            }
        } else if(flags356&8u) {
            collisionBody->linearVelocity.y=0.0f;
            collisionBody->linearVelocity.x=0.0f;
            waitElapsed+=elapsed;
            if(waitElapsed/1000>waitDuration) {
                Application::GetInstance()->GetEventManager()->raise(EvNPC(static_cast<EvNPC::State>(5),this));
                flags356&=~8u;
            }
        } else if(flags356&16u) {
            collisionBody->linearVelocity.y=0.0f;
            collisionBody->linearVelocity.x=0.0f;
        }
    }
    if((flags356&4u) && isCurrentAnimation(getSpecificAnimation(165))) {
        flags356|=0x8000u;
        goToNextPoint(false);
    }
    UpdateSceneNode();
}
