/*
 * Rocket
 *
 * Original file: Rocket.cpp
 * Area:          combat
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Rocket.cpp here, in the order they appear in the library.
 */

#include "Rocket.h"
#include "../core/LocalStartupStorage.h"
#include "Explosion.h"
#include "Weapon.h"
#include "../characters/PlayerTest.h"
#include "../characters/PhysicAttributes.h"
#include "../core/Physics.h"
#include "../world/ObjectData.h"
#include "../audio/SoundManager.h"
#include "../app/Application.h"
#include "../core/IrrlichtDevice.h"
#include "../vehicles/VehicleBodyShapes.h"
#include "../rendering/GS3DStuff.h"
#include "../world/GameObjectManager.h"

void* operator new(unsigned int);
void operator delete(void*) throw();
void operator delete[](void*) throw();
// The stored owner is Character's observed address, represented by the partial
// secondary-base interface. Bind its native method without inventing the full
// Character hierarchy; the implementation remains a retail import.
extern "C" void _ZN9Character16onRocketLaunchedEv(SavePositionInterface* owner);
// The factory's primary base has the native return address; import its weak
// getter without emitting an unrelated copy of its factory implementation.
extern "C" irr::collada::CColladaFactory* _ZN12CGameFactory11getInstanceEv() __attribute__((weak));

typedef char RocketExtent[sizeof(Rocket) == 120 ? 1 : -1];
typedef char RocketPhysicExtent[sizeof(PhysicAttributes) == 120 ? 1 : -1];

static const char rocketAttachmentUid[] __attribute__((section(".rodata.rocket_attach_uid"))) = "rocket_dummy_gun-node";

// Observed inline reference count and owner-physics prefixes, not complete
// engine/Character layouts. References preserve the native non-null grab ABI.
struct RocketReferenceView { unsigned int unknown0; int references; };
struct RocketOwnerPhysicsView { unsigned char unknown0[24]; PhysicAttributes* attributes; };
// Observed body state written by the inlined sleep operation; the shared
// call-only Box2D interface keeps its existing extent and declarations.
struct RocketSleepingBodyView {
    unsigned short flags;
    unsigned char unknown2[62];
    float unknown64, unknown68, unknown72, unknown76, unknown80, unknown84;
    unsigned char unknown88[52];
    float unknown140;
};

void Rocket::debug(irr::video::IVideoDriver*)
{
}

extern "C" {
static void __tcf_3(void*) __attribute__((used));
static void __tcf_3(void*)
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
// Import the existing singleton and its weak destructor without emitting a
// second factory implementation in this partial translation unit.
extern unsigned char _ZZN12CGameFactory11getInstanceEvE2gf[];
void _ZN12CGameFactoryD1Ev(void*) __attribute__((weak));
static void __tcf_1(void*) __attribute__((used));
static void __tcf_1(void*)
{
    _ZN12CGameFactoryD1Ev(_ZZN12CGameFactory11getInstanceEvE2gf);
}
}

void Rocket::Load(const Structs::Rocket& data)
{
    LevelObject::Load(data, _ZN12CGameFactory11getInstanceEv());
    delete[] unknown28;
    unknown28 = 0;
    unknown64 = data.unknown76;
    unknown68 = data.unknown80;
    unknown72 = data.unknown92;
    unknown76 = data.unknown84;
    unknown80 = data.unknown72;
    unknown84 = data.unknown88;
    unknown24 = new PhysicAttributes(1, 0);
    weapon = owner->getWeapon();
    if (weapon->getWeaponType() != 7) {
        weapon = 0;
    } else {
        irr::scene::ISceneNode* node = weapon->projectileSceneNode()->getSceneNodeFromUID(rocketAttachmentUid);
        if (node) {
            node->addChild(sceneNode);
            ++reinterpret_cast<RocketReferenceView*>(&static_cast<irr::IReferenceCounted&>(*sceneNode))->references;
            sceneNode->setVisible(true);
            unknown24->SetPhysicInfo(*reinterpret_cast<RocketOwnerPhysicsView*>(owner)->attributes->info, 0);
        }
    }
}

void Rocket::explode(bool drawEffect)
{
    RocketSleepingBodyView* state = reinterpret_cast<RocketSleepingBodyView*>(body);
    state->flags |= 8;
    state->unknown140 = 0.0f;
    state->unknown64 = 0.0f;
    state->unknown68 = 0.0f;
    state->unknown72 = 0.0f;
    state->unknown76 = 0.0f;
    state->unknown80 = 0.0f;
    state->unknown84 = 0.0f;
    unknown92 = true;
    SoundManager* sound = SoundManager::getInstance();
    sound->unknown140 = true;
    sound->playEx(260, 0, false, 1.0f, 0, true, 1.0f, 0);
    sound->unknown140 = false;
    if (drawEffect)
        Explosion::drawExplosion(GetPosition(), irr::core::vector3d<float>(unknown80, unknown80, unknown80));
    Explosion::applyExplosionDamage(this, GetPosition(), static_cast<float>(unknown68), unknown64);
}

Rocket::~Rocket()
{
    if (body) {
        if (body->data) {
            delete static_cast<PhysicsBodyData*>(body->data);
            body->data = 0;
        }
        PhysicAttributes::s_world->DestroyBody(body);
        body = 0;
    }
    if (unknown24) {
        delete unknown24;
        unknown24 = 0;
    }
    if (launched) {
        _ZN9Character16onRocketLaunchedEv(owner);
        unknown88 = 0;
        launched = false;
    }
}

Rocket::Rocket(int type)
    : LevelObject(type), body(0), weapon(0), owner(PlayerTest::GetPlayer()),
      unknown88(0), unknown92(false), launched(false)
{
    Explosion::loadExplosion();
}

void Rocket::Update(int elapsed)
{
    if (body) {
        float y = body->GetXForm().position.y * 100.0f;
        float z = (y - unknown108.Y) / unknown96.Y * unknown96.Z + unknown108.Z;
        SetPosition(irr::core::vector3d<float>(body->GetXForm().position.x * 100.0f, y, z));
    }
    if (launched) {
        unknown88 += elapsed;
        if (unknown88 >= unknown84) {
            _ZN9Character16onRocketLaunchedEv(owner);
            unknown88 = 0;
            launched = false;
        }
    }
    if (GetPosition().Z <= unknown24->GetHeight(GetPosition(), 0, false))
        explode(true);
    if (unknown92) {
        unknown4 |= 16;
        unknown92 = false;
    }
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_rocket_transitions {
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
        __aeabi_atexit(0, __tcf_3, &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_rocket_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_rocket_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_rocket_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_rocket_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_rocket_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_rocket_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_rocket_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_rocket_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_rocket_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_rocket_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN6RocketC2Ei() __attribute__((used));
static void _GLOBAL__I__ZN6RocketC2Ei()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

void Rocket::launch(irr::core::vector3d<float> direction)
{
    unknown96 = direction;
    unknown24->SetPhysicInfo(*reinterpret_cast<RocketOwnerPhysicsView*>(owner)->attributes->info, 0);
    unknown108 = GetPosition();
    launched = true;
    unknown88 = 0;
    irr::core::matrix4 transformation(sceneNode->getAbsoluteTransformation(), irr::core::matrix4::EM4CONST_COPY);
    Application::GetInstance()->GetDevice()->getSceneManager()->getRootSceneNode()->addChild(sceneNode);
    sceneNode->setRelativeTransformation(transformation);
    if (direction.getLengthSQ() == 0.0f) {
        direction = -GetRight();
    } else {
        irr::core::quaternion rotation;
        rotation.rotationFromTo(direction, irr::core::vector3d<float>(1, 0, 0));
        sceneNode->setRotation(rotation);
    }
    sceneNode->updateAbsolutePosition(false);
    sceneNode->setVisible(true);
    b2BodyDef bodyDefinition;
    bodyDefinition.linearDamping = 0.0f;
    bodyDefinition.angularDamping = 0.0f;
    bodyDefinition.isBullet = false;
    bodyDefinition.position = b2Vec2(GetPosition().X / 100.0f, GetPosition().Y / 100.0f);
    bodyDefinition.allowSleep = true;
    body = PhysicAttributes::s_world->CreateBody(&bodyDefinition);
    b2CircleDef circle;
    circle.radius = static_cast<float>(unknown76) / 100.0f;
    circle.density = 1.0f;
    circle.restitution = 0.0f;
    circle.friction = 0.3f;
    circle.filter.categoryBits = 2;
    circle.filter.maskBits = 0xffff;
    circle.filter.groupIndex = unknown24->getIndex() + 1;
    circle.isSensor = true;
    body->CreateShape(&circle);
    body->SetMassFromShapes();
    body->data = new PhysicsBodyData(this, GS3DStuff::FindAMesh(sceneNode));
    GameObjectManager::s_gom->Add(this, 0);
    body->linearVelocity = b2Vec2(static_cast<float>(unknown72) * direction.X, static_cast<float>(unknown72) * direction.Y);
    RocketSleepingBodyView* state = reinterpret_cast<RocketSleepingBodyView*>(body);
    state->flags &= ~8;
    state->unknown140 = 0.0f;
    unknown24->SetIsOnGround(0, false);
}
