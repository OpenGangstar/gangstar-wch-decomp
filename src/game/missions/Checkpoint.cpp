/*
 * Checkpoint
 *
 * Original file: Checkpoint.cpp
 * Area:          missions
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Checkpoint.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_checkpoint_transitions {
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
        _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(&value, localStartupEmptyText);
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_3), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_checkpoint_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_checkpoint_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_checkpoint_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_checkpoint_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_checkpoint_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_checkpoint_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_checkpoint_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_checkpoint_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_checkpoint_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_checkpoint_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN10Checkpoint18s_bTutoCallContactE() __attribute__((used));
static void _GLOBAL__I__ZN10Checkpoint18s_bTutoCallContactE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_3()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

#include "Checkpoint.h"
#include "../core/SceneNode.h"
#include "../world/ObjectData.h"

Checkpoint::~Checkpoint()
{
}

Checkpoint::Checkpoint(int type) : Transformation(type)
{
    unknown88 = -1;
    unknown92 = -1;
    radius = 0;
    unknown96 = false;
}


irr::scene::ISceneNode* Checkpoint::grabSceneNode(int id, void*** parameters)
{
    irr::scene::ISceneNode* node = Transformation::grabSceneNode(id, parameters);
    const irr::scene::SceneAnimatorList& animators = node->getAnimators();
    if (animators.getSize() != 0) {
        irr::scene::ISceneNodeAnimator* animator = *animators.begin();
        animator->setAnimationClip(0);
        animator->getTimelineCtrl()->setLoop(true);
    }
    return node;
}

extern "C" irr::collada::CColladaFactory* _ZN12CGameFactory11getInstanceEv() __attribute__((weak));

void Checkpoint::Load(const Structs::Checkpoint& data)
{
    Transformation::Load(data, _ZN12CGameFactory11getInstanceEv());
    radius = data.unknown88;
    unknown88 = data.unknown84;
    unknown92 = data.unknown80;
    unknown96 = data.unknown92;
}

void Checkpoint::SetPosition(const irr::core::vector3d<float>& position)
{
    Transformation::SetPosition(position);
    irr::scene::ISceneNode* node = sceneNode;
    if (node) {
        node->setPosition(position);
        node->updateAbsolutePosition(false);
    }
}

#include "../core/CameraManager.h"
#include "../hud/MenuManager.h"
#include "../scripting/ScriptManager.h"
#include "../world/GameObjectManager.h"
#include "Mission.h"

bool Checkpoint::s_bTutoCallContact;

namespace {
const char tutorialMenu[] __attribute__((section(".rodata.checkpoint_tutorial"))) = "Tutorial";
}

void Checkpoint::enable()
{
    LevelObject::enable();
    if (ScriptManager::getInstance()->unknown78 &&
        GetMetatype() == 26 &&
        static_cast<Mission*>(ScriptManager::getInstance()->getMission())->failureCount() > 0 &&
        !s_bTutoCallContact &&
        !ScriptManager::getInstance()->isInCinematic()) {
        s_bTutoCallContact = true;
        MenuManager::getInstance()->setTutorialIds(0x307e, 0x307f);
        if (MenuManager::getInstance()->getDepth() > 0)
            MenuManager::getInstance()->popAll(false);
        MenuManager::getInstance()->push(tutorialMenu, true);
    }
}

void Checkpoint::show()
{
    if (hasSceneNodePool()) {
        grabSceneNode(0, 0);
    }
    unknown4 |= 2;
    objectList->Remove(this);
    GameObjectManager::s_gom->Add(this, 0);
}

void Checkpoint::hide()
{
    if (hasSceneNodePool()) {
        dropSceneNode();
    }
    unknown4 &= ~2u;
    objectList->Remove(this);
    GameObjectManager::s_gom->Add(this, 1);
}

void Checkpoint::Update(int elapsed)
{
    // The retail code calls GetPosition twice and uses only the second result.
    const irr::core::vector3d<float> unusedPosition = GetPosition();
    const irr::core::vector3d<float> position = GetPosition();
    const float distanceSquared = position.getDistanceFromSQ(
        CameraManager::getInstance()->getCamera()->getPosition());
    const float visibilityDistanceSquared = 100000000.0f;
    if (unknown4 & 2u) {
        if (distanceSquared > visibilityDistanceSquared)
            hide();
    } else if (distanceSquared <= visibilityDistanceSquared) {
        show();
    }
    LevelObject::Update(elapsed);
}

extern "C" {
extern irr::collada::CColladaFactory _ZZN12CGameFactory11getInstanceEvE2gf __attribute__((weak));
void _ZN12CGameFactoryD1Ev(irr::collada::CColladaFactory*) __attribute__((weak));

static void __tcf_1() __attribute__((used));
static void __tcf_1()
{
    _ZN12CGameFactoryD1Ev(&_ZZN12CGameFactory11getInstanceEvE2gf);
}
}
