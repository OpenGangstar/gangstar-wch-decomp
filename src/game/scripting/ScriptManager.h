#ifndef WCH_SCRIPTING_SCRIPT_MANAGER_H
#define WCH_SCRIPTING_SCRIPT_MANAGER_H

#include "../characters/PlayerTest.h"
namespace std {
template<class T> class allocator;
template<class T, class Alloc> class vector;
}

class AnimObject;
class DataStream;
class ASprite;
class Vehicle;
class IMissionCondition;
class Mission;
class Race;
class Revive;
class Script;
class LevelObject;
class HudElement;
namespace Structs { struct ScriptCommand; }

// Partial storage/call interface observed by SaveGame and Item.
class ScriptManager {
public:
    bool checkScreenPress();
    ScriptManager();
    ~ScriptManager();
    void respawnFromBustedOrDie(bool busted);
    void saveGame();
    void loadGame(bool reset);
    bool loadMissions(const char* filename);
    LevelObject* getFirstAvailableCheckpoint() const;
    static void displayOnMinimap(LevelObject* object, bool visible, bool flag);
    static LevelObject* findObject(const char* name, bool flag);
    static ScriptManager* getInstance();
    Script* findScript(int id) const;
    void resetGame(bool skipAutomaticScripts, int scriptId);
    static void moveObject(LevelObject* object, LevelObject* target);
    void update(int);
    void resume();
    void pause();
    void setup();
    void playerDrives(Vehicle* vehicle);
    void drawFade() const;
    void rewindRunningScripts();
    void skipBlockingCommands();
    void* getMission() const;
    void* getCinematicsHudSprite() const;
    void* getRace() const;
    void unload();
    void tearDown();
    void draw();
    void unlockFrozenScripts();
    void freezeRunningScripts(const Script* script, PlayerTest::eContext context);
    Script** scripts;
    int scriptCapacity;
    int scriptCount;
    int unknown12;
    int cinematicState;
    unsigned int commandCursor;
    bool screenPressed;
    unsigned char unknown25[3];
    ASprite* introSprite;
    ASprite* cinematicsHudSprite;
    ASprite* cinematicCharacterSprite;
    AnimObject* introAnimation;
    AnimObject* cinematicBars;
    AnimObject* cinematicHudAnimation2;
    AnimObject* vehicleNameAnimation;
    AnimObject* cinematicCharacterAnimation;
    Mission* mission;
    Revive* revive;
    Race* race;
    HudElement* skipButton;
    bool paused;
    bool cutsceneSkipped;
    bool unknown78;
    unsigned char unknown79;
    int vehicleNameTimer;
    int unknown84;
    int unknown88;
    int unknown92;
    int taggedCount;
    int unknown100;
    int unknown104;

    void taggedKilled();
    static void printCommand(const Structs::ScriptCommand& command);
    void addScript(Script* script);
    Structs::ScriptCommand* loadCommand(DataStream& stream);
    static void cleanCommand(Structs::ScriptCommand* command);
    void loadScript(const char* filename, bool loadSave);
    int getAvailableMissionScripts(std::vector<Script*, std::allocator<Script*> >& output) const;
    bool areBlockingCommandsSkipped() const;
    bool isInCinematic() const;
    bool isSkipButtonVisible() const;
    int getFailureCause();
    void finishReviveAnims();
    void missionIdle();
    void drawCinematicBars() const;
    void missionResumeFadeOut();
    void missionSkipFadeOut();
    void missionSetFailureCount(int count);
    void missionClearConditions();
    void missionFail();
    void message(int id);
    void missionObjective(int id, bool silent);
    void missionStart(int id, int duration);
    void missionOver();
    void missionRegisterCondition(IMissionCondition* condition);
    void resumeBlockingCommands();
    void hideSkipButton();
    void showSkipButton();
    void skipCutscene();
    static int s_failure;
    static int s_failureTime;
    static int s_raceTimer;
    static int s_raceTimeSeconds;
    static int s_fadeTime;
    static int s_fadeIntensity;
    static PlayerTest* s_playerTest;
    static LevelObject* s_me;
};

#endif
