#ifndef WCH_META_ACHIEVEMENTS_H
#define WCH_META_ACHIEVEMENTS_H

void operator delete(void*);

class DataStream;
namespace Structs {
struct Stat {
    int fields[3];
    void Read(DataStream&) __attribute__((weak));
};
struct AchievementRule {
    int fields[3];
    void Read(DataStream&) __attribute__((weak));
};
struct Achievement {
    int id;
    int ruleCount;
    int* rules;
    int unknown12;
    int unknown16;
    void Read(DataStream&) __attribute__((weak));
};
}

class Item;
class Character;
class Vehicle;

// Partial declarations and observed record layouts. Not a complete manager.
class AchievementManager {
public:
    struct IDLinks {
        inline IDLinks() : data(0), allocated(0), used(0), free_when_destroyed(true), is_sorted(true), unknown16(1) {}
        inline ~IDLinks() {
            if (free_when_destroyed)
                ::operator delete(data);
        }
        inline void clear() {
            ::operator delete(data);
            data = 0;
            used = 0;
            allocated = 0;
            is_sorted = true;
        }
        int* data;
        unsigned int allocated;
        unsigned int used;
        bool free_when_destroyed;
        bool is_sorted;
        unsigned int unknown16;
    };
    struct Stat {
        inline Stat() : value(0) {}
        ~Stat() { rules.clear(); }
        int getValue() const;
        char* formatString(char* buffer) const;
        unsigned char unknown0[4];
        int format;
        unsigned char unknown8[4];
        int value;
        IDLinks rules;
    };
    struct Achievement {
        inline Achievement() { flags = 0; rules = 0; }
        inline ~Achievement() { delete[] rules; }
        unsigned int unknown0;
        int ruleCount;
        int* rules;
        unsigned char unknown12[4];
        int titleId;
        unsigned int flags;
    };
    // Storage view of the native STLport list's sentinel and value nodes.
    struct CompletedNodeBase {
        CompletedNodeBase* next;
        CompletedNodeBase* prev;
    };
    struct CompletedNode : CompletedNodeBase {
        const Achievement* value;
    };
    static CompletedNodeBase s_completedAchievements;
    struct AchievementRule {
        inline AchievementRule() : flags(0) {}
        ~AchievementRule() { achievements.clear(); }
        unsigned int operation;
        int statID;
        int threshold;
        unsigned int flags;
        IDLinks achievements;
    };
    static AchievementManager* setup();
    void resetNumMissionStat();
    Achievement* getAchievementFromID(int id) const;
    AchievementRule* getAchievementRuleFromID(int id) const;
    Stat* getStatFromID(int id) const;
    bool evaluateRule(AchievementRule& rule) const;
    bool evaluate(Achievement& achievement) const;
    bool IsAchievementCompleted(int id);
    int GetNumAchievementCompleted();
    void checkAchievement(int id);
    void addCompletedAchievement(Achievement* achievement);
    void updateRule(int id);
    void setNextAchievementAsCompleted();
    void completeAchievement(int id);
    bool hasNewCompletedAchievements();
    const Achievement* popCompletedAchievement();
    void init();
    void clear();
    void load(const char*);
    void reset();
    void updateStat(int id);
    void updateProgressStat();
    void setMaxStat(int id, int value);
    void updateMaskStat(int id, int bit);
    void incrementStat(int id, int amount);
    void recordJump(int value);
    void recordDamage(int value);
    void recordVehicleSpeed(int value);
    void recordOnJump(int bit);
    void recordShopCarRental(int bit);
    void recordShopWeapon(int bit);
    void recordWantedLevel(int value);
    void recordWeapon(int type, bool locked);
    void recordMissionEnded();
    void recordDeliverySideMission();
    void recordAmbulanceSideMission();
    void recordTaxiSideMission();
    void recordEndChapter();
    void recordDrift(int value);
    void recordRanOverPed();
    void recordNbArrests();
    void recordCarStolen(int type);
    void recordKmDriven();
    void recordRepair(int value);
    void recordDestroyedVehicle(const Vehicle& vehicle);
    void recordCashSpent(int amount);
    void recordMissionCash(int amount);
    void recordDeath(Character& character);
    void recordBadgesEscaped(int count);
    void recordDroppedCash(int count);
    void recordArmor(const Item& item);
    void recordHealthPack(const Item& item);
    static AchievementManager* s_achievementManager;
    static int s_statCount;
    static int s_ruleCount;
    static Stat* s_stats;
    static AchievementRule* s_rules;
    static Achievement* s_achievements;
    static int s_achievementCount;
};

#endif
