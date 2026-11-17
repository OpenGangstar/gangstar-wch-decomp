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
#include "../missions/WantedLevelEvents.h"

extern "C" void clearReceivers(void*)
    __asm__("_ZN9stlp_priv10_List_baseIP14IEventReceiverSaIS2_EE5clearEv")
    __attribute__((weak));

inline AIManager::ReceiverList::~ReceiverList()
{
    clearReceivers(this);
}

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

inline __attribute__((always_inline)) void AIManager::ReceiverList::clearOwnedReceivers()
{
    ReceiverList* link = next;
    while (this != link) {
        ReceiverNode* node = static_cast<ReceiverNode*>(link);
        ReceiverList* saved = link->next;
        delete node->receiver;
        node->receiver = 0;
        ReceiverList* nextNode = link->next;
        ReceiverList* previousNode = link->previous;
        previousNode->next = nextNode;
        nextNode->previous = previousNode;
        ::operator delete(link);
        link = saved;
    }
}
void AIManager::clean()
{
    firstList.clearOwnedReceivers();
    secondList.clearOwnedReceivers();
    EventManager* events = Application::GetInstance()->GetEventManager();
    events->detach(17, this);
    events->detach(18, this);
    events->detach(20, this);
    events->detach(21, this);
}

#include "../characters/NPCEvent.h"
#include "../characters/NPCDespawnEvent.h"
#include "../vehicles/VehicleEvents.h"
void AIManager::onEvent(const IEvent* event, const EventManager*)
{
    switch (event->getEventID()) {
    case 17: {
        ReceiverList* link = firstList.next;
        while (&firstList != link) {
            ReceiverNode* node = static_cast<ReceiverNode*>(link);
            if (static_cast<AIControllerPrefix*>(node->receiver)->target == static_cast<const EvNPCDeath*>(event)->getTarget()) {
                delete node->receiver;
                node->receiver = 0;
                ReceiverList* nextNode = node->next;
                ReceiverList* previousNode = node->previous;
                previousNode->next = nextNode;
                nextNode->previous = previousNode;
                ::operator delete(node);
                break;
            }
            link = link->next;
        }
        break;
    }
    case 18: {
        ReceiverList* link = firstList.next;
        while (&firstList != link) {
            ReceiverNode* node = static_cast<ReceiverNode*>(link);
            if (static_cast<AIControllerPrefix*>(node->receiver)->target == static_cast<const EvNPCDespawn*>(event)->getTarget()) {
                delete node->receiver;
                node->receiver = 0;
                ReceiverList* nextNode = node->next;
                ReceiverList* previousNode = node->previous;
                previousNode->next = nextNode;
                nextNode->previous = previousNode;
                ::operator delete(node);
                break;
            }
            link = link->next;
        }
        break;
    }
    case 20: {
        ReceiverList* link = secondList.next;
        while (&secondList != link) {
            ReceiverNode* node = static_cast<ReceiverNode*>(link);
            if (static_cast<AIControllerPrefix*>(node->receiver)->target == static_cast<const EvVehicleDestroyed*>(event)->getTarget()) {
                delete node->receiver;
                node->receiver = 0;
                ReceiverList* nextNode = node->next;
                ReceiverList* previousNode = node->previous;
                previousNode->next = nextNode;
                nextNode->previous = previousNode;
                ::operator delete(node);
                break;
            }
            link = link->next;
        }
        break;
    }
    case 21: {
        ReceiverList* link = secondList.next;
        while (&secondList != link) {
            ReceiverNode* node = static_cast<ReceiverNode*>(link);
            if (static_cast<AIControllerPrefix*>(node->receiver)->target == static_cast<const EvVehicleDeactivated*>(event)->getTarget()) {
                delete node->receiver;
                node->receiver = 0;
                ReceiverList* nextNode = node->next;
                ReceiverList* previousNode = node->previous;
                previousNode->next = nextNode;
                nextNode->previous = previousNode;
                ::operator delete(node);
                break;
            }
            link = link->next;
        }
        break;
    }
    }
}

#include "NPC.h"
#include "NPCController.h"
#include "../core/NativeAllocator.h"
#include "../core/NativeStdio.h"
namespace stlp_priv { template<class T> struct _List_node; }
namespace std {
template<> stlp_priv::_List_node<IEventReceiver*>* allocator<stlp_priv::_List_node<IEventReceiver*> >::allocate(unsigned int, const void*) __attribute__((weak));
}
#include "CivPassiveController.h"
#include "CivAgressiveController.h"
#include "CopController.h"
#include "GuardController.h"
static const char aiInvalidType[] = "AIManager was asked to addAI on an invalid AI Type: %i\n";
void AIManager::addAI(NPC* npc,gameloft::ai::StateID initial)
{
    NPCController* controller;
    switch(npc->category428) {
    case 0: {
        if (initial == 0)
            controller = new CivPassiveController(npc, reinterpret_cast<const gameloft::ai::Transition&>(gameloft::ai::civ_passive), static_cast<gameloft::ai::StateID>(1));
        else
            controller = new CivPassiveController(npc, reinterpret_cast<const gameloft::ai::Transition&>(gameloft::ai::civ_passive), initial);
        break;
    }
    case 1: case 2: {
        if (initial == 0)
            controller = new CivAgressiveController(npc, static_cast<gameloft::ai::StateID>(1));
        else
            controller = new CivAgressiveController(npc, initial);
        break;
    }
    case 3: {
        CopController* cop;
        if (initial == 0)
            cop = new CopController(npc, static_cast<gameloft::ai::StateID>(1));
        else
            cop = new CopController(npc, initial);
        EvWantedLevelChanged event;
        cop->onEvent(&event,Application::GetInstance()->GetEventManager());
        controller = cop;
        break;
    }
    case 5: {
        if (initial == 0)
            controller = new GuardController(npc, static_cast<gameloft::ai::StateID>(3));
        else
            controller = new GuardController(npc, initial);
        break;
    }
    case 6: {
        if (initial == 0)
            controller = new CivPassiveController(npc, reinterpret_cast<const gameloft::ai::Transition&>(gameloft::ai::npc_scripted), static_cast<gameloft::ai::StateID>(1));
        else
            controller = new CivPassiveController(npc, reinterpret_cast<const gameloft::ai::Transition&>(gameloft::ai::npc_scripted), initial);
        break;
    }
    default:
        printf(aiInvalidType,npc->category428);
        return;
    }
    typedef std::allocator<stlp_priv::_List_node<IEventReceiver*> > Allocator;
    ReceiverNode* node = reinterpret_cast<ReceiverNode*>(reinterpret_cast<Allocator*>(&firstList)->allocate(1,0));
    node->receiver = controller;
    node->next = &firstList;
    ReceiverList* previous = firstList.previous;
    node->previous = previous;
    previous->next = node;
    firstList.previous = node;
}
