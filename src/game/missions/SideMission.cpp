#include "AmbulanceSideMission.h"
#include "DeliverySideMission.h"
#include "../vehicles/TaxiSideMission.h"
/*
 * SideMission
 *
 * Original file: SideMission.cpp
 * Area:          missions
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of SideMission.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "SideMissionManager.h"
#include "../characters/PlayerTest.h"
#include "../vehicles/Vehicle.h"
#include "../persistence/StringManager.h"
#include "../meta/Achievements.h"
#include "../core/NativeStdio.h"
#include "../app/GSFade.h"
#include "../characters/PhysicAttributes.h"
#include "Checkpoint.h"
#include "../ai/NPC.h"
#include "../world/GameObjectManager.h"
#include "../app/Application.h"
#include "../hud/CHudManager.h"
#include "../ui/Message.h"
#include "../scripting/ScriptManager.h"
#include "SideMission.h"
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../ai/StateMachine.h"
#include "../ai/AIManagerSingleton.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_5() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_sidemission_transitions {
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

extern "C" {
static void __tcf_5()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_5), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_sidemission_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_sidemission_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_sidemission_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_sidemission_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_sidemission_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_sidemission_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_sidemission_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_sidemission_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_sidemission_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_sidemission_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN11SideMission13addCheckpointEiN3irr4core8vector3dIfEEfftRt() __attribute__((used));
static void _GLOBAL__I__ZN11SideMission13addCheckpointEiN3irr4core8vector3dIfEEfftRt()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

int SideMission::getTimer()
{
    return timer;
}

int SideMission::getReward()
{
    return static_cast<int>(reward);
}

void SideMission::updateTimer(int elapsed)
{
    if (timer != -9999) {
        timer -= elapsed;
        if (timer <= 0) {
            stopReason = 2;
            stop(true);
        }
    }
}

void SideMission::init()
{
    activeState = 0;
    difficulty = 1;
    timer = -9999;
    reward = 0.0f;
    stopReason = 0;
    passenger = 0;
}

bool SideMission::inProgress()
{
    return activeState != 0;
}

void SideMission::stop(bool showMessage)
{
    if (!inProgress())
        return;

    if (showMessage) {
        static_cast<Message*>(Application::GetInstance()->GetHudManager()->message172)
            ->setMessage(0x304e, 3000, static_cast<MenuManager::eText>(9));
    }
    ScriptManager::getInstance()->unlockFrozenScripts();

    if (passenger) {
        passenger->unknown4 |= 0x80u;
        GameObjectManager::s_gom->Remove(passenger);
        GameObjectManager::s_gom->Add(passenger, 0);
        if (passenger->isCurrentAnimation(163)) {
            passenger->setAnimation(-1, 1.0f, false, false, false);
            passenger->die(false);
        } else {
            passenger->goToIdle();
            AIManager::getInstance()->removeAI(passenger);
            AIManager::getInstance()->addAI(passenger, static_cast<gameloft::ai::StateID>(1));
        }
    }

    reward = 0.0f;
    timer = -9999;
    activeState = 0;
    clean();
    MenuManager::getInstance()->setText(MenuManager::MissionTimerText, static_cast<const char*>(0), 0);
}

void SideMission::getRange(float& minimum, float& maximum, int level,
                           int baseMin, int baseMax, int finalMin, int finalMax)
{
    minimum = (baseMin + level * ((finalMin - baseMin) / 10)) * 100;
    maximum = (baseMax + level * ((finalMax - baseMax) / 10)) * 100;
}

float SideMission::calculateMoney(irr::core::vector3d<float> start,
    irr::core::vector3d<float> destination, int baseRate, int multiplier)
{
    const float distance = (start - destination).getLength();
    return baseRate * (distance / 100000.0f) * multiplier;
}

int SideMission::calculateTime(irr::core::vector3d<float> from,
    irr::core::vector3d<float> to, int timePerKilometer, int level)
{
    const float distance = from.getDistanceFrom(to) / 100000.0f;
    const float time = timePerKilometer * distance;
    const float levelFactor = (level * -2.5f + 100.0f) * 0.01f;
    const int seconds = static_cast<int>(time * levelFactor);
    return seconds >= 30 ? seconds * 1000 : 30000;
}

bool SideMission::isInCheckpointRange(irr::core::vector3d<float> position, Checkpoint* checkpoint)
{
    const float distance = position.getDistanceFrom(checkpoint->GetPosition());
    return distance <= checkpoint->getRadius();
}

void SideMission::removeCheckpoint(Checkpoint*& checkpoint)
{
    if (checkpoint) {
        ScriptManager::displayOnMinimap(checkpoint, false, true);
        checkpoint->disable();
        GameObjectManager::s_gom->RemoveAndDestroy(checkpoint);
    }
    checkpoint = 0;
}

void SideMission::addNPC(int metatype, int behavior, irr::core::vector3d<float> position,
    unsigned short region, unsigned short surface)
{
    passenger = GameObjectManager::s_gom->spawnNPC(metatype, behavior, position, region, surface);
    passenger->unknown4 &= ~0x80u;
}

Checkpoint* SideMission::addCheckpoint(int metatype, irr::core::vector3d<float> origin,
    float minDistance, float maxDistance, unsigned short material, unsigned short& surface)
{
    const irr::core::vector3d<float> destination =
        PhysicAttributes::GetRandomDestination(material, surface, origin, minDistance, maxDistance);
    Checkpoint* checkpoint = static_cast<Checkpoint*>(
        GameObjectManager::s_gom->CreateGameObjectFromMetatype(metatype));
    checkpoint->SetPosition(destination);
    checkpoint->enable();
    ScriptManager::displayOnMinimap(checkpoint, true, true);
    return checkpoint;
}

void SideMission::start()
{
    stopReason = 0;
    activeState = 1;
    ScriptManager::getInstance()->freezeRunningScripts(0, PlayerTest::AnyContext);
}

void SideMission::removeNPC()
{
    GameObjectManager::s_gom->RemoveAndDestroy(passenger);
    passenger = 0;
}

void SideMission::fadeInFadeOut()
{
    StateMachine::getInstance()->pushState<GSFade>();
}

bool SideMission::finished()
{
    return stopReason == 1 || stopReason == 2;
}

void SideMission::getCheckpoints(int metatype, irr::core::array<Checkpoint*>& checkpoints)
{
    for (LevelObject* object = GameObjectManager::s_gom->GetFirst(2); object; object = object->next) {
        if (LevelObject::s_type[object->getObjectType()] == 6 && object->GetMetatype() == metatype)
            checkpoints.push_back(static_cast<Checkpoint*>(object));
    }
}

void SideMission::disableCheckpoints(irr::core::array<Checkpoint*>& checkpoints)
{
    for (int i = 0; static_cast<unsigned int>(i) < checkpoints.used; ++i) {
        ScriptManager::displayOnMinimap(checkpoints.data[i], false, true);
        checkpoints.data[i]->disable();
    }
}

static const char sideMissionGoalFormat[] __attribute__((section(".rodata.side_mission_goal_format"))) = "%s %i/%i";

void SideMission::update(int elapsed)
{
    updateTimer(elapsed);
    Vehicle* vehicle = PlayerTest::GetPlayer()->getVehicle();
    if (!vehicle)
        return;

    const irr::core::vector3d<float> position = vehicle->GetPosition();
    switch (activeState) {
    case 1: {
        char label[32];
        const char* goal = Application::GetInstance()->GetStringManager()->getString(getGoalMessage());
        sprintf(label, sideMissionGoalFormat, goal, difficulty, 10);
        static_cast<Message*>(Application::GetInstance()->GetHudManager()->message176)
            ->setMessage(label, 3000);
        {
            CHudManager* hud = Application::GetInstance()->GetHudManager();
            const int message = getObj1Message();
            static_cast<Message*>(hud->message172)->setMessage(message, 3000, static_cast<MenuManager::eText>(9));
        }
        if (reward > 0.0f)
            reward = 0.0f;
        else
            timer = 0;
        begin(position, difficulty, timer, reward);
        activeState = 2;
        break;
    }
    case 2:
        if (pickUp(position, timer, reward, elapsed))
            activeState = 3;
        break;
    case 3:
        {
            CHudManager* hud = Application::GetInstance()->GetHudManager();
            const int message = getObj2Message();
            static_cast<Message*>(hud->message172)->setMessage(message, 3000, static_cast<MenuManager::eText>(9));
        }
        activeState = 4;
        break;
    case 4:
        if (dropOff(position))
            activeState = 5;
        break;
    case 5:
        activeState = 6;
        break;
    case 6:
        if (++difficulty > 10) {
            reward += getMoneyReward();
            static_cast<Message*>(Application::GetInstance()->GetHudManager()->message176)
                ->setMessage(0x3049, 3000, static_cast<MenuManager::eText>(9));
            {
                CHudManager* hud = Application::GetInstance()->GetHudManager();
                const int message = getEndMessage();
                static_cast<Message*>(hud->message172)->setMessage(message, 3000, static_cast<MenuManager::eText>(9));
            }
            stopReason = 1;
            if (this == SideMissionManager::s_taxiSideMission)
                AchievementManager::s_achievementManager->recordTaxiSideMission();
            else if (this == SideMissionManager::s_deliverySideMission)
                AchievementManager::s_achievementManager->recordDeliverySideMission();
            else if (this == SideMissionManager::s_ambulanceSideMission)
                AchievementManager::s_achievementManager->recordAmbulanceSideMission();
        }
        activeState = 0;
        break;
    }

    if (passenger && passenger->isCurrentAnimation(181))
        passenger->turnToward(vehicle->GetPosition());
}

bool SideMission::isInCheckpointsRange(irr::core::vector3d<float> position,
    irr::core::array<Checkpoint*>& checkpoints)
{
    for (int i = 0; checkpoints.size() > static_cast<unsigned int>(i); ++i) {
        if (isInCheckpointRange(position, checkpoints[i]))
            return true;
    }
    return false;
}
