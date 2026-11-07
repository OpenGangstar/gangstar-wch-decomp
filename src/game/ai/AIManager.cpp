/*
 * AIManager
 *
 * Original file: AIManager.cpp
 * Area:          ai
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of AIManager.cpp here, in the order they appear in the library.
 */

#include "AIManager.h"
#include "../app/Application.h"
#include "../core/EventManager.h"
#include "../core/GameEventMethods.h"

extern "C" void clearReceivers(void*)
    __asm__("_ZN9stlp_priv10_List_baseIP14IEventReceiverSaIS2_EE5clearEv")
    __attribute__((weak));

inline AIManager::ReceiverList::~ReceiverList()
{
    clearReceivers(this);
}

class EvWantedLevelChanged : public IEvent {
public:
    virtual ~EvWantedLevelChanged() __attribute__((used)) {}
};

AIManager::AIManager() : unknown20(0)
{
    EventManager* events = Application::GetInstance()->GetEventManager();
    events->attach(17, this);
    events->attach(18, this);
    events->attach(20, this);
    events->attach(21, this);
}

AIManager::~AIManager()
{
}

// Observed prefix shared by the controllers stored in both lists.
struct AIControllerPrefix : IEventReceiver {
    unsigned int unknown4;
    void* target;
};

struct AIManager::ReceiverNode : ReceiverList {
    IEventReceiver* receiver;
};

inline __attribute__((always_inline)) void AIManager::ReceiverList::removeForTarget(const void* target)
{
    ReceiverList* link = next;
    while (this != link) {
        ReceiverNode* node = static_cast<ReceiverNode*>(link);
        if (static_cast<AIControllerPrefix*>(node->receiver)->target == target) {
            delete node->receiver;
            node->receiver = 0;
            ReceiverList* nextNode = node->next;
            ReceiverList* previousNode = node->previous;
            previousNode->next = nextNode;
            nextNode->previous = previousNode;
            ::operator delete(node);
            return;
        }
        link = link->next;
    }
}

void AIManager::removeAI(Vehicle* vehicle)
{
    secondList.removeForTarget(vehicle);
}

void AIManager::removeAI(NPC* npc)
{
    firstList.removeForTarget(npc);
}

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_4() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_aimanager_transitions {
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
static void __tcf_4()
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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_aimanager_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_aimanager_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_aimanager_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_aimanager_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_aimanager_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_aimanager_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_aimanager_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_aimanager_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_aimanager_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_aimanager_transitions::scripted_vehicle_trans, 21);
        irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
        value.array = 0;
        value.allocated = 0;
        value.used = 0;
        value.reference = false;
        _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(&value, localStartupEmptyText);
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_4), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN9AIManagerC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN9AIManagerC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
