/*
 * UNMATCHED: 2622 function bytes / 2624 input-section bytes, native 2608.
 * Fragment for the retained body6 Character.cpp context, not a standalone TU.
 * Its private type/access prerequisites are not installed in production.
 * See Character-shoot-blocked-hud.md. No matching credit.
 */
#include "../core/CameraManager.h"
#include "../meta/Factions.h"
#include "../hud/CHudManager.h"
#include "../combat/HitWarning.h"

bool Character::shoot(float speed, bool pressed)
{
    struct ShootingGuard { unsigned int& flags; ShootingGuard(unsigned int& flags): flags(flags) {} ~ShootingGuard() { flags &= ~0x20000000u; } } guard(movementFlags);
    {
        Application* app = Application::GetInstance();
        app->GetDevice()->getTimer()->getRealTime();
        Weapon* weapon = getWeapon();
        int type = weapon->getWeaponType();
        if (!weapon->isReady(s_type[objectType] == 5))
            return false;
        movementFlags &= ~0x10000000u;
        if (pressed) {
            movementFlags &= ~0x200000u;
            goToIdle();
            ready(1.0f);
            movementFlags |= 0x4000000u;
            switchCombatAnimation();
        }
        if (movementFlags & 0x200000u) {
            switch (currentAnimation) {
            case 138:
                movementFlags |= 0x10000000u;
                setAnimation(69,speed,false,false,false);
                break;
            case 140:
                movementFlags |= 0x10000000u;
                if (type == 1) setAnimation(53,speed,false,false,false);
                else if (type == 5) setAnimation(52,speed,false,false,false);
                break;
            case 141:
                movementFlags |= 0x10000000u;
                setAnimation(57,speed,false,false,false);
                break;
            case 142:
                movementFlags |= 0x10000000u;
                if (type == 2) setAnimation(62,speed,false,false,false);
                else if (type == 6) setAnimation(61,speed,false,false,false);
                break;
            case 145:
                movementFlags |= 0x10000000u;
                if (type == 7) setAnimation(69,speed,false,false,false);
                else if (type == 8) setAnimation(70,speed,false,false,false);
                break;
            case 146:
                movementFlags |= 0x10000000u;
                if (type == 3) setAnimation(78,speed,false,false,false);
                else if (type == 4) setAnimation(77,speed,false,false,false);
                break;
            }
            movementFlags &= ~0x200000u;
            return false;
        }
        switch (currentAnimation) {
        case 36: case 42: case 165: case 166: case 169:
            movementFlags |= 0x200000u;
            ready(1.0f);
            return false;
        case 50:
            movementFlags |= 0x10000000u;
            if (type == 1) setAnimation(53,speed,false,false,false);
            else if (type == 5) setAnimation(52,speed,false,false,false);
            return false;
        case 55:
            movementFlags |= 0x10000000u;
            setAnimation(57,speed,false,false,false);
            return false;
        case 59:
            movementFlags |= 0x10000000u;
            if (type == 2) setAnimation(62,speed,false,false,false);
            else if (type == 6) setAnimation(61,speed,false,false,false);
            return false;
        case 64:
            movementFlags |= 0x10000000u;
            if (type == 7) setAnimation(69,speed,false,false,false);
            else if (type == 8) setAnimation(70,speed,false,false,false);
            return false;
        case 73:
            movementFlags |= 0x10000000u;
            if (type == 3) setAnimation(78,speed,false,false,false);
            else if (type == 4) setAnimation(77,speed,false,false,false);
            return false;
        case 52: case 53: case 57: case 61: case 62: case 69: case 70: case 77: case 78:
            break;
        default:
            return false;
        }
        LevelObject* hit = 0;
        if (weapon->isGun()) {
            irr::core::vector3d<float> point, direction, rayDirection, normal;
            irr::core::vector3d<float> source = GetPosition();
            source.Z = weapon->GetPosition().Z;
            if (target) {
                float randomX=(float(lrand48()%100)-50.0f)/50.0f;
                float randomY=(float(lrand48()%100)-50.0f)/50.0f;
                float randomZ=(float(lrand48()%100)-50.0f)/50.0f;
                irr::core::vector3d<float> noise(randomX,randomY,randomZ);
                direction = target->GetPosition()+noise*(200.0f-float(unknown252*2))-weapon->GetPosition();
                rayDirection = target->GetPosition()+noise*(200.0f-float(unknown252*2))-source;
                if (s_type[target->getObjectType()] == 3) {
                    direction.Z += 100.0f;
                    rayDirection.Z += 100.0f;
                }
                direction.normalize(); rayDirection.normalize();
            } else {
                direction=GetFront(); rayDirection=GetFront();
            }
            bool blocked=CastRay(source,rayDirection*float(weapon->getRange()),point,normal,hit,false);
            if (hit) {
                if (s_type[hit->getObjectType()]!=8 && hit!=PlayerTest::GetPlayer()->getVehicle() && !(hit->unknown4&4u)) {
                    blocked=true;
                } else if (s_type[hit->getObjectType()]==5) {
                    if (s_type[objectType]==5) {
                        if (static_cast<NPC*>(this)->faction!=0 && static_cast<NPC*>(hit)->faction==static_cast<NPC*>(this)->faction)
                            blocked=true;
                    } else if (s_type[objectType]==8 && Factions::isFactionFriendly(static_cast<NPC*>(hit)->faction)) {
                        blocked=true;
                    }
                }
            }
            if (hit && (s_type[hit->getObjectType()]==8 || s_type[hit->getObjectType()]==5)) {
                showBloodSplash(point,normal);
                weapon->shoot(true,weapon->GetPosition()+direction*7500.0f,normal);
            } else {
                irr::core::vector3d<float> endpoint = point;
                if (blocked)
                    endpoint = weapon->GetPosition()+direction*7500.0f;
                weapon->shoot(blocked,endpoint,normal);
            }
            if (!blocked && hit) {
                if (s_type[hit->getObjectType()]==8) {
                    if (PlayerTest::GetPlayer()->unknown372==0)
                        hit->shooted(weapon->getDamage(),this);
                } else if (s_type[hit->getObjectType()]==5 || s_type[hit->getObjectType()]==3) {
                    hit->shooted(weapon->getDamage(),this);
                }
                if (hit && s_type[hit->getObjectType()]==8) {
                    irr::core::vector3d<float> incoming=weapon->GetPosition()-point;
                    incoming.normalize();
                    irr::core::vector3d<float> camera=CameraManager::getInstance()->getPosition()-CameraManager::getInstance()->getLookAt();
                    camera.normalize();
                    float dot=incoming.X*camera.X+incoming.Y*camera.Y+incoming.Z*camera.Z;
                    CHudManager* hud=app->GetHudManager();
                    if (dot>0.5f) hud->hitWarning->timers[1]=255;
                    else if (dot< -0.5f) hud->hitWarning->timers[0]=255;
                    else if (incoming.Z*camera.Z+(incoming.X*-camera.Y+camera.X*incoming.Y)<0.0f) hud->hitWarning->timers[2]=255;
                    else hud->hitWarning->timers[3]=255;
                }
            }
        } else if (weapon->isProjectile()) {
            irr::core::vector3d<float> direction;
            if (target) {
                const irr::core::vector3d<float> targetPosition = target->GetPosition();
                const irr::core::vector3d<float> ownPosition = GetPosition();
                direction.X=targetPosition.X-ownPosition.X;
                direction.Y=targetPosition.Y-ownPosition.Y;
                direction.Z=targetPosition.Z-ownPosition.Z-25.0f;
            } else direction=GetFront();
            direction.normalize();
            weapon->shootProjectile(direction);
        }
        return true;
    }
}
