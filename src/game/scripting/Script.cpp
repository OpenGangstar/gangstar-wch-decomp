/*
 * Script
 *
 * Original file: Script.cpp
 * Area:          scripting
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Script.cpp here, in the order they appear in the library.
 */

#include "Script.h"
#include "ScriptManager.h"

namespace Structs {
struct ScriptCommand {
    int opcode;
    int argument;
};
}

void Script::addCommand(Structs::ScriptCommand* command)
{
    if (commandCount < commandCapacity) {
        commands[commandCount++] = command;
        if (command->opcode == 65)
            missionId = command->argument;
    }
}

int Script::getMissionId() const { return missionId; }

bool Script::isEnded() const { return commandIndex == commandCount; }

Script::State Script::getState() const { return state; }

Structs::ScriptCommand* Script::peekCommand(int offset) const
{
    const int index = commandIndex + offset;
    if (index >= 0 && index < commandCount)
        return commands[index];
    return 0;
}

void* Script::getSource() const { return source; }

void Script::setParent(Script* script) { parent = script; }

Script* Script::getParent() const { return parent; }

void Script::unlockScript(int id)
{
    ScriptManager::getInstance()->findScript(id)->setState(State2, PlayerTest::AnyContext);
}

void Script::freezeScript(int id)
{
    ScriptManager::getInstance()->findScript(id)->setState(State1, PlayerTest::AnyContext);
}

void Script::finalize()
{
    rewind();
    setState(State0, PlayerTest::AnyContext);
    Script* parentScript = getParent();
    if (parentScript)
        parentScript->setState(State2, PlayerTest::AnyContext);
    else
        ScriptManager::getInstance()->saveGame();
}

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_6() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_script_transitions {
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
static void __tcf_6()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_6), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_script_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_script_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_script_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_script_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_script_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_script_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_script_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_script_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_script_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_script_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN6Script16s_driveBadPointsE() __attribute__((used));
static void _GLOBAL__I__ZN6Script16s_driveBadPointsE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
