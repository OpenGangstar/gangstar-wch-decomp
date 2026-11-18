/*
 * Explosion
 *
 * Original file: Explosion.cpp
 * Area:          combat
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Explosion.cpp here, in the order they appear in the library.
 */

#include "Explosion.h"
#include "../core/SceneNode.h"
#include "../core/IrrlichtDevice.h"
#include "../core/LocalStartupStorage.h"
#include "../core/Collada.h"
#include "../app/Application.h"
#include "../rendering/GS3DStuff.h"
#include "../core/Physics.h"
#include "../characters/PhysicAttributes.h"
#include "../characters/Character.h"
#include "../core/Lock.h"

void operator delete(void*) throw();

irr::scene::ISceneNode* Explosion::s_explosion;
float Explosion::s_cameraShakeTimer;

void ExplosionAnimCallback(irr::scene::ITimelineController*, void* data)
{
    static_cast<irr::scene::ISceneNode*>(data)->setVisible(false);
}

irr::scene::ISceneNode* Explosion::getExplosionNode()
{
    return s_explosion;
}

extern "C" {
static void __tcf_2(void*) __attribute__((used));
static void __tcf_2(void*)
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

static const char explosionScene[] __attribute__((section(".rodata.explosion_scene"))) = "./p_explosion_00.bdae";
void Explosion::loadExplosion()
{
    if (!s_explosion) {
        s_explosion = irr::collada::CColladaDatabase::constructScene(explosionScene, true, &irr::collada::CColladaDatabase::DefaultFactory);
        GS3DStuff::SetMaterialFlag(s_explosion, irr::video::MaterialFlag2, false);
        GS3DStuff::SetMaterialFlag(s_explosion, irr::video::MaterialFlag16, true);
        GS3DStuff::SetMaterialType(s_explosion, irr::video::MaterialType13);
        s_explosion->setVisible(false);
        Application::GetInstance()->GetDevice()->getSceneManager()->getRootSceneNode()->addChild(s_explosion);
    }
}

void Explosion::drawExplosion(irr::core::vector3d<float> position, irr::core::vector3d<float>)
{
    loadExplosion();
    s_explosion->setVisible(true);
    s_explosion->setPosition(position);
    s_explosion->updateAbsolutePosition(true);
    GS3DStuff::SetMaterialFlag(s_explosion, irr::video::MaterialFlag2, false);
    irr::scene::ITimelineController* controller = s_explosion->getAnimators().first->animator->getTimelineCtrl();
    if (controller) {
        controller->setLoop(false);
        controller->jumpTo(controller->startTime);
        void (*callback)(irr::scene::ITimelineController*, void*) = ExplosionAnimCallback;
        void* data = s_explosion;
        controller->callback = callback;
        controller->callbackData = data;
    }
    s_cameraShakeTimer = 1000.0f;
}

// Observed prefixes used only for damage cleanup, not complete class layouts.
struct ExplosionObjectPrefix {
    unsigned int vtable, flags;
    unsigned char unknown8[8];
    irr::scene::ISceneNode* sceneNode;
};
struct ExplosionCharacterPrefix {
    unsigned char unknown0[176];
    irr::scene::ISceneNode* secondNode;
    unsigned char unknown180[56];
    unsigned int flags;
};
static const float& explosionClamp(const float& value, const float& low, const float& high)
{
    const float& maximum = value < low ? low : value;
    return maximum < high ? maximum : high;
}
void Explosion::applyExplosionDamage(LevelObject* source, irr::core::vector3d<float> position, float radius, int damage)
{
    b2World* world = PhysicAttributes::s_world;
    b2Shape* shapes[100] = {0};
    b2AABB bounds;
    bounds.lowerBound.x = (position.X-radius)/100.0f;
    bounds.lowerBound.y = (position.Y-radius)/100.0f;
    bounds.upperBound.x = (radius+position.X)/100.0f;
    bounds.upperBound.y = (radius+position.Y)/100.0f;
    world->Query(bounds, shapes, 100);
    for (int i=0; i<100; ++i) {
        if (!shapes[i]) break;
        PhysicsBodyData* data = static_cast<PhysicsBodyData*>(shapes[i]->GetBody()->GetUserData());
        if (!data || !data->owner || data->owner == source) continue;
        LevelObject* object = data->owner;
        float factor = (radius - (object->GetPosition()-source->GetPosition()).getLength()) / radius;
        int amount = static_cast<int>(damage * explosionClamp(factor,0.0f,1.0f));
        object->applyDamage(amount,0,true);
        if (LevelObject::s_type[object->getObjectType()] == 5) {
            ExplosionCharacterPrefix* character = reinterpret_cast<ExplosionCharacterPrefix*>(object);
            if ((character->flags & 0x10000) && object->getHealth() <= 0) {
                ExplosionObjectPrefix* prefix = reinterpret_cast<ExplosionObjectPrefix*>(object);
                prefix->flags &= ~2;
                if (prefix->sceneNode) {
                    prefix->sceneNode->setVisible(false);
                    character->secondNode->setVisible(false);
                }
                if (!static_cast<Character*>(object)->isPlayer() && Lock::getInstance()->target == object)
                    Lock::getInstance()->setTarget(0);
            }
        }
    }
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_explosion_transitions {
extern const unsigned int civPassive_trans[] __attribute__((visibility("hidden")));
extern const unsigned int scriptedNpc_trans[] __attribute__((visibility("hidden")));
extern const unsigned int civAggressive_trans[] __attribute__((visibility("hidden")));
extern const unsigned int gangMember_trans[] __attribute__((visibility("hidden")));
extern const unsigned int cop_trans[] __attribute__((visibility("hidden")));
extern const unsigned int swat_trans[] __attribute__((visibility("hidden")));
extern const unsigned int civ_vehicle_trans[] __attribute__((visibility("hidden")));
extern const unsigned int cop_vehicle_trans[] __attribute__((visibility("hidden")));
extern const unsigned int guard_trans[] __attribute__((visibility("hidden")));
extern const unsigned int scripted_vehicle_trans[] __attribute__((visibility("hidden")));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

static void __static_initialization_and_destruction_0(int initialize, int priority) __attribute__((used));
static void __static_initialization_and_destruction_0(int initialize, int priority)
{
    if (initialize == 1 && priority == 65535) {
        irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
        value.array = 0;
        value.allocated = 0;
        value.used = 0;
        value.reference = false;
        _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(&value, "");
        __aeabi_atexit(0, __tcf_2, &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_explosion_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_explosion_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_explosion_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_explosion_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_explosion_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_explosion_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_explosion_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_explosion_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_explosion_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_explosion_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__Z21ExplosionAnimCallbackPN3irr5scene19ITimelineControllerEPv() __attribute__((used));
static void _GLOBAL__I__Z21ExplosionAnimCallbackPN3irr5scene19ITimelineControllerEPv()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
