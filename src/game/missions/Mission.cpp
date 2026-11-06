/*
 * Mission
 *
 * Original file: Mission.cpp
 * Area:          missions
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Mission.cpp here, in the order they appear in the library.
 */

#include "Mission.h"
#include "WantedLevelManagerSingleton.h"
#include "IMissionCondition.h"
#include "../persistence/DataStream.h"

int Mission::setTextToPrint(int id)
{
    return currentMessage = id;
}

Structs::Mission* Mission::mission(int index) const
{
    if (index < 0 || index >= missionCount)
        return 0;
    return missions[index];
}

int Mission::getLastObjectiveText() const
{
    if (state == 4)
        return lastObjectiveText;
    return -1;
}

int Mission::getCurrentMessage() const
{
    return currentMessage;
}

void Mission::registerCondition(IMissionCondition* condition)
{
    if (conditionCount < 8)
        conditions[conditionCount++] = condition;
}

void Mission::clearConditions()
{
    for (int i = 0; i < conditionCount; ++i) {
        delete conditions[i];
        conditions[i] = 0;
    }
    conditionCount = 0;
}

int Mission::getState() const
{
    return state;
}

int Mission::failureCause() const
{
    return lastFailureCause;
}

int Mission::failureCount() const
{
    return failures;
}

void Mission::skipFadeOut()
{
    skipFade = true;
}

void Mission::resumeFadeOut()
{
    skipFade = false;
}

void Mission::setFailureCount(int count)
{
    failures = count;
}

namespace Structs {

struct Mission {
    int unknown0;
    int unknown4;
    int unknown8;
    char* unknown12;
    int unknown16;
    int unknown20;
    char* unknown24;
    int unknown28;
    int unknown32;

    void Read(DataStream& stream) __attribute__((used));
};

inline void Mission::Read(DataStream& stream)
{
    unknown0 = stream.ReadInt();
    unknown4 = stream.ReadInt();
    unknown8 = stream.ReadInt();
    unknown12 = stream.ReadAndAllocateString();
    unknown16 = stream.ReadInt();
    unknown20 = stream.ReadInt();
    unknown24 = stream.ReadAndAllocateString();
    unknown28 = stream.ReadInt();
    unknown32 = stream.ReadInt();
}

} // namespace Structs

bool Mission::objective(int id, bool silent)
{
    lastObjectiveText = id;
    if (!silent)
        message(id);
    return true;
}

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../core/Rct.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_4() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_mission_transitions {
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

template struct Rct<int>;

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
        irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
        value.array = 0;
        value.allocated = 0;
        value.used = 0;
        value.reference = false;
        _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(&value, localStartupEmptyText);
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_4), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_mission_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_mission_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_mission_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_mission_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_mission_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_mission_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_mission_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_mission_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_mission_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_mission_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__Z18getFrameModuleRectP7ASpriteiii() __attribute__((used));
static void _GLOBAL__I__Z18getFrameModuleRectP7ASpriteiii()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
