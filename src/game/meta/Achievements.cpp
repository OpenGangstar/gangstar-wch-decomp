/*
 * Achievements
 *
 * Original file: Achievements.cpp
 * Area:          meta
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Achievements.cpp here, in the order they appear in the library.
 */

#include "Achievements.h"
#include "AchievementListSupport.h"
#include "Item.h"
#include "../ai/NPC.h"
#include "../persistence/DataStream.h"
#include "../world/ResStream.h"
#include "../core/PlacementNew.h"
#include "../core/LocalStartupStorage.h"
#include "../persistence/StringManager.h"
#include "../app/Application.h"

extern "C" char* strcpy(char*, const char*);
extern "C" int sprintf(char*, const char*, ...);
// Preserve the retail weak destructor boundary; the SDK's inline destructor
// would otherwise be expanded here by this partial translation unit.
extern "C" void _ZN10DataStreamD1Ev(void*) __attribute__((weak));

namespace AchievementStartup {
static const char empty[] __attribute__((section(".rodata.achievement_empty"))) = "";
}
namespace retail_achievement_transitions {
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
static void __tcf_3(void*) __attribute__((used));
static void __tcf_4(void*) __attribute__((used));
}

class GSLoading { public: static bool isGameLoaded(); };

AchievementManager* AchievementManager::s_achievementManager;
int AchievementManager::s_statCount;
int AchievementManager::s_ruleCount;
AchievementManager::CompletedNodeBase AchievementManager::s_completedAchievements;
int AchievementManager::s_achievementCount;
AchievementManager::Stat* AchievementManager::s_stats;
AchievementManager::AchievementRule* AchievementManager::s_rules;
AchievementManager::Achievement* AchievementManager::s_achievements;

int AchievementManager::Stat::getValue() const
{
    return value;
}

AchievementManager::Achievement* AchievementManager::getAchievementFromID(int id) const
{
    return &s_achievements[id];
}

AchievementManager::AchievementRule* AchievementManager::getAchievementRuleFromID(int id) const
{
    return &s_rules[id];
}

AchievementManager::Stat* AchievementManager::getStatFromID(int id) const
{
    return &s_stats[id];
}

// Read-only ABI view of the native four-byte getter. Keep the conservative
// member declaration for its other existing call sites.
extern "C" int _ZNK18AchievementManager4Stat8getValueEv(const AchievementManager::Stat*) __attribute__((pure));

bool AchievementManager::evaluateRule(AchievementRule& rule) const
{
    if (rule.flags & 2)
        return true;
    Stat* stat = getStatFromID(rule.statID);
    switch (rule.operation) {
    case 1:
        if (__builtin_expect(rule.threshold == _ZNK18AchievementManager4Stat8getValueEv(stat), 0)) break;
        return false;
    case 2:
        if (__builtin_expect(rule.threshold < _ZNK18AchievementManager4Stat8getValueEv(stat), 0)) break;
        return false;
    case 3:
        if (__builtin_expect(rule.threshold <= _ZNK18AchievementManager4Stat8getValueEv(stat), 0)) break;
        return false;
    case 4:
        if (__builtin_expect(rule.threshold > _ZNK18AchievementManager4Stat8getValueEv(stat), 0)) break;
        return false;
    case 5:
        if (__builtin_expect(rule.threshold >= _ZNK18AchievementManager4Stat8getValueEv(stat), 0)) break;
        return false;
    case 8: {
        int value = stat->getValue();
        int mask = rule.threshold;
        value &= mask;
        if (__builtin_expect(value == mask, 0)) break;
        return false;
    }
    default:
        return false;
    }
    rule.flags |= 2;
    return true;
}

bool AchievementManager::evaluate(Achievement& achievement) const
{
    for (int i = 0; i < achievement.ruleCount; ++i) {
        if (!evaluateRule(s_rules[achievement.rules[i]]))
            return false;
    }
    achievement.flags |= 2;
    return true;
}

bool AchievementManager::IsAchievementCompleted(int id)
{
    return (s_achievements[id].flags & 2) != 0;
}

int AchievementManager::GetNumAchievementCompleted()
{
    int completed = 0;
    for (int i = 0; i < s_achievementCount; ++i) {
        if (s_achievements[i].flags & 2)
            ++completed;
    }
    return completed;
}

AchievementManager* AchievementManager::setup()
{
    static AchievementManager man;
    return &man;
}

void AchievementManager::updateProgressStat()
{
    int missions = s_stats[49].value;
    int completed = GetNumAchievementCompleted();
    Stat& progress = s_stats[0];
    if (missions > 63)
        missions = 63;
    float missionProgress = missions * 90 / 63.0;
    float achievementProgress = completed * 10 / double(s_achievementCount);
    progress.value = missionProgress + achievementProgress;
}

void AchievementManager::resetNumMissionStat()
{
    s_stats[24].value = 0;
    s_stats[49].value = 0;
    s_achievements[0].flags &= ~2;
    s_achievements[1].flags &= ~2;
    s_achievements[2].flags &= ~2;
    s_achievements[3].flags &= ~2;
    s_achievements[4].flags &= ~2;
    s_achievements[5].flags &= ~2;
    updateProgressStat();
}

bool AchievementManager::hasNewCompletedAchievements()
{
    unsigned int count = 0;
    for (CompletedNodeBase* node = s_completedAchievements.next; node != &s_completedAchievements; node = node->next)
        ++count;
    return count != 0;
}

extern "C" {
static void __tcf_4(void*)
{
    typedef stlp_priv::_List_base<const AchievementManager::Achievement*, std::allocator<const AchievementManager::Achievement*> > ListBase;
    reinterpret_cast<ListBase*>(&AchievementManager::s_completedAchievements)->clear();
}

}

#include "../core/Array.h"

void AchievementManager::init()
{
    for (int i = 0; i < s_ruleCount; ++i) {
        Stat& stat = s_stats[s_rules[i].statID];
        const int id = i;
        reinterpret_cast<irr::core::array<int>*>(&stat.rules)->push_back(id);
    }
    for (int i = 0; i < s_achievementCount; ++i) {
        Achievement& achievement = s_achievements[i];
        for (int j = 0; j < achievement.ruleCount; ++j) {
            AchievementRule& rule = s_rules[achievement.rules[j]];
            const int id = i;
            reinterpret_cast<irr::core::array<int>*>(&rule.achievements)->push_back(id);
        }
    }
}

void AchievementManager::addCompletedAchievement(Achievement* achievement)
{
    typedef stlp_priv::_List_node<const Achievement*> Node;
    std::allocator<Node>& allocator = *reinterpret_cast<std::allocator<Node>*>(&s_completedAchievements);
    Node* node = allocator.allocate(1);
    node->_M_data = achievement;
    CompletedNodeBase* position = &s_completedAchievements;
    CompletedNodeBase* prev = position->prev;
    node->base.next = position;
    node->base.prev = prev;
    prev->next = &node->base;
    position->prev = &node->base;
    if (GSLoading::isGameLoaded())
        updateProgressStat();
}

void AchievementManager::completeAchievement(int id)
{
    Achievement& achievement = s_achievements[id];
    achievement.flags |= 2;
    addCompletedAchievement(&achievement);
}

void AchievementManager::setNextAchievementAsCompleted()
{
    for (int i = 0; i < s_achievementCount; ++i) {
        if (!(s_achievements[i].flags & 2)) {
            completeAchievement(i);
            return;
        }
    }
}

void AchievementManager::checkAchievement(int id)
{
    Achievement& achievement = s_achievements[id];
    if (!(achievement.flags & 2) && evaluate(achievement))
        addCompletedAchievement(&achievement);
}

void Structs::Stat::Read(DataStream& stream)
{
    fields[0] = stream.ReadInt();
    fields[1] = stream.ReadInt();
    fields[2] = stream.ReadInt();
}

void Structs::AchievementRule::Read(DataStream& stream)
{
    fields[0] = stream.ReadInt();
    fields[1] = stream.ReadInt();
    fields[2] = stream.ReadInt();
}

void Structs::Achievement::Read(DataStream& stream)
{
    id = stream.ReadInt();
    ruleCount = stream.ReadInt();
    rules = new int[ruleCount];
    for (int i=0; i<ruleCount; ++i)
        rules[i] = stream.ReadInt();
    unknown12 = stream.ReadInt();
    unknown16 = stream.ReadInt();
}

void AchievementManager::load(const char* name)
{
    ResStream resource(name, 1);
    unsigned int streamStorage[sizeof(DataStream) / sizeof(unsigned int)];
    DataStream& stream = *new (streamStorage) DataStream(resource, DataStream::BigEndian);
    s_ruleCount = stream.ReadInt();
    s_rules = new AchievementRule[s_ruleCount];
    for (int i = 0; i < s_ruleCount; ++i) {
        stream.ReadInt();
        reinterpret_cast<Structs::AchievementRule*>(&s_rules[i])->Read(stream);
    }
    s_achievementCount = stream.ReadInt();
    s_achievements = new Achievement[s_achievementCount];
    for (int i = 0; i < s_achievementCount; ++i) {
        stream.ReadInt();
        reinterpret_cast<Structs::Achievement*>(&s_achievements[i])->Read(stream);
    }
    s_statCount = stream.ReadInt();
    s_stats = new Stat[s_statCount];
    for (int i = 0; i < s_statCount; ++i) {
        stream.ReadInt();
        reinterpret_cast<Structs::Stat*>(&s_stats[i])->Read(stream);
    }
    _ZN10DataStreamD1Ev(&stream);
}

char* AchievementManager::Stat::formatString(char* buffer) const
{
    static const char percentFormat[] = "%i%";
    static const char timeFormat[] = "%02i:%02i:%02i";
    switch (format) {
    case 0: case 1: {
        StringManager* strings = Application::GetInstance()->GetStringManager();
        strcpy(buffer, strings->formatAmount(getValue(), true, format == 1));
        break;
    }
    case 2:
        sprintf(buffer, percentFormat, getValue() <= 0);
        break;
    case 3: {
        int total = getValue();
        int minutes = total / 60;
        int hours = minutes / 60;
        sprintf(buffer, timeFormat, hours, minutes % 60, total % 60);
        break;
    }
    }
    return buffer;
}

void AchievementManager::reset()
{
    for (int i = 0; i < s_statCount; ++i)
        s_stats[i].value = 0;
    for (int i = 0; i < s_ruleCount; ++i)
        s_rules[i].flags &= ~2;
    for (int i = 0; i < s_achievementCount; ++i)
        s_achievements[i].flags &= ~2;
    typedef stlp_priv::_List_base<const Achievement*, std::allocator<const Achievement*> > ListBase;
    reinterpret_cast<ListBase*>(&s_completedAchievements)->clear();
}

void AchievementManager::updateRule(int id)
{
    if (evaluateRule(s_rules[id])) {
        int count = s_rules[id].achievements.used;
        for (int i = 0; i < count; ++i)
            checkAchievement(s_rules[id].achievements.data[i]);
    }
}

void AchievementManager::updateStat(int id)
{
    int count = s_stats[id].rules.used;
    for (int i = 0; i < count; ++i)
        updateRule(s_stats[id].rules.data[i]);
}

void AchievementManager::setMaxStat(int id, int value)
{
    if (s_stats[id].getValue() < value) {
        s_stats[id].value = value;
        updateStat(id);
    }
}

void AchievementManager::recordJump(int value)
{
    setMaxStat(16, value);
}

void AchievementManager::recordDamage(int value)
{
    // Retail evaluates this accessor before and after updating the maximum.
    s_stats[18].getValue();
    setMaxStat(18, value);
    s_stats[18].getValue();
}

void AchievementManager::recordVehicleSpeed(int value)
{
    setMaxStat(14, value);
}

void AchievementManager::updateMaskStat(int id, int bit)
{
    s_stats[id].value |= 1 << bit;
    updateStat(id);
}

void AchievementManager::recordOnJump(int bit)
{
    updateMaskStat(41, bit);
}

void AchievementManager::recordShopCarRental(int bit)
{
    updateMaskStat(38, bit);
}

void AchievementManager::recordShopWeapon(int bit)
{
    updateMaskStat(37, bit);
}

void AchievementManager::recordWeapon(int type, bool locked)
{
    if (!locked)
        s_stats[28].value |= 1 << type;
    else
        s_stats[28].value &= ~(1 << type);
    updateStat(28);
}

void AchievementManager::recordWantedLevel(int value)
{
    s_stats[26].value = value;
    updateStat(26);
}

void AchievementManager::incrementStat(int id, int amount)
{
    s_stats[id].value += amount;
    updateStat(id);
}

void AchievementManager::recordMissionEnded()
{
    incrementStat(49, 1);
    updateProgressStat();
}

void AchievementManager::recordDeliverySideMission()
{
    incrementStat(48, 1);
}

void AchievementManager::recordAmbulanceSideMission()
{
    incrementStat(47, 1);
}

void AchievementManager::recordTaxiSideMission()
{
    incrementStat(46, 1);
}

void AchievementManager::recordEndChapter()
{
    incrementStat(24, 1);
}

void AchievementManager::recordDrift(int value)
{
    setMaxStat(15, value);
    incrementStat(43, 1);
}

void AchievementManager::recordRanOverPed()
{
    incrementStat(20, 1);
}

void AchievementManager::recordBadgesEscaped(int count)
{
    incrementStat(22, count);
}

void AchievementManager::recordNbArrests()
{
    incrementStat(23, 1);
}

void AchievementManager::recordCarStolen(int type)
{
    incrementStat(21, 1);
    s_stats[29].value |= 1 << type;
    updateStat(29);
}

void AchievementManager::recordKmDriven()
{
    incrementStat(17, 1);
}

void AchievementManager::recordRepair(int value)
{
    incrementStat(13, 1);
    setMaxStat(19, value);
}

void AchievementManager::recordDestroyedVehicle(const Vehicle&)
{
    incrementStat(12, 1);
    s_stats[12].getValue();
}

void AchievementManager::recordCashSpent(int amount)
{
    incrementStat(11, amount);
}

void AchievementManager::recordArmor(const Item& item)
{
    incrementStat(7, 1);
    updateMaskStat(40, item.getId());
}

void AchievementManager::recordHealthPack(const Item& item)
{
    incrementStat(6, 1);
    updateMaskStat(39, item.getId());
}

void AchievementManager::recordMissionCash(int amount)
{
    incrementStat(8, amount);
    incrementStat(9, amount);
}

void AchievementManager::recordDroppedCash(int amount)
{
    incrementStat(8, amount);
    incrementStat(10, amount);
}

void AchievementManager::recordDeath(Character& character)
{
    if (character.isPlayer()) {
        incrementStat(5, 1);
        return;
    }
    NPC& npc = static_cast<NPC&>(character);
    switch (npc.category428) {
    case 0: case 1:
        incrementStat(2, 1);
        break;
    case 2:
        incrementStat(3, 1);
        break;
    case 3:
        incrementStat(4, 1);
        break;
    case 5: case 6:
        if (npc.isCop())
            incrementStat(4, 1);
        else
            incrementStat(3, 1);
        break;
    }
    incrementStat(1, 1);
}

const AchievementManager::Achievement* AchievementManager::popCompletedAchievement()
{
    const Achievement* achievement = 0;
    CompletedNodeBase* node = s_completedAchievements.next;
    if (node != &s_completedAchievements) {
        achievement = static_cast<CompletedNode*>(node)->value;
        CompletedNodeBase* next = node->next;
        CompletedNodeBase* prev = node->prev;
        prev->next = next;
        next->prev = prev;
        ::operator delete(node);
    }
    return achievement;
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
        _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(&value, AchievementStartup::empty);
        __aeabi_atexit(0, __tcf_3, &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_achievement_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_achievement_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_achievement_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_achievement_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_achievement_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_achievement_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_achievement_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_achievement_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_achievement_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_achievement_transitions::scripted_vehicle_trans, 21);
        AchievementManager::s_completedAchievements.next = &AchievementManager::s_completedAchievements;
        AchievementManager::s_completedAchievements.prev = &AchievementManager::s_completedAchievements;
        __aeabi_atexit(0, __tcf_4, &__dso_handle);
        AchievementManager::s_achievementManager = AchievementManager::setup();
    }
}

extern "C" {
static void _GLOBAL__I__ZN18AchievementManager11s_statCountE() __attribute__((used));
static void _GLOBAL__I__ZN18AchievementManager11s_statCountE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}


extern "C" {
static void __tcf_3(void*)
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}

}

typedef char AchievementStatExtent[sizeof(AchievementManager::Stat) == 36 ? 1 : -1];
typedef char AchievementRuleExtent[sizeof(AchievementManager::AchievementRule) == 36 ? 1 : -1];
typedef char AchievementExtent[sizeof(AchievementManager::Achievement) == 24 ? 1 : -1];

typedef char AchievementCharacterExtent[sizeof(Character) == 296 ? 1 : -1];
typedef char AchievementNPCExtent[sizeof(NPC) == 456 ? 1 : -1];

typedef char AchievementLinkExtent[sizeof(AchievementManager::IDLinks) == 20 ? 1 : -1];

typedef char SerializedStatExtent[sizeof(Structs::Stat) == 12 ? 1 : -1];
typedef char SerializedRuleExtent[sizeof(Structs::AchievementRule) == 12 ? 1 : -1];
typedef char SerializedAchievementExtent[sizeof(Structs::Achievement) == 20 ? 1 : -1];

typedef char AchievementQueueRootExtent[sizeof(AchievementManager::CompletedNodeBase) == 8 ? 1 : -1];
typedef char AchievementQueueNodeExtent[sizeof(AchievementManager::CompletedNode) == 12 ? 1 : -1];

void AchievementManager::clear()
{
    delete[] s_stats;
    delete[] s_rules;
    delete[] s_achievements;
}
