#ifndef WCH_SCRIPTING_SCRIPT_MANAGER_H
#define WCH_SCRIPTING_SCRIPT_MANAGER_H

class AnimObject;
class IMissionCondition;
class Mission;
class Revive;
class Script;
class LevelObject;
class HudElement;
namespace Structs { struct ScriptCommand; }

// Partial storage/call interface observed by SaveGame and Item.
class ScriptManager {
public:
    static void displayOnMinimap(LevelObject* object, bool visible, bool flag);
    static LevelObject* findObject(const char* name, bool flag);
    static ScriptManager* getInstance();
    Script* findScript(int id) const;
    void resetGame(bool flag, int id);
    void update(int);
    void resume();
    void pause();
    void skipBlockingCommands();
    void* getMission() const;
    void* getCinematicsHudSprite() const;
    void* getRace() const;
    Script** scripts;
    int scriptCapacity;
    int scriptCount;
    unsigned char unknown12[4];
    int cinematicState;
    unsigned int commandCursor;
    unsigned char unknown24[8];
    void* cinematicsHudSprite;
    unsigned char unknown36[8];
    AnimObject* cinematicBars;
    unsigned char unknown48[12];
    Mission* mission;
    Revive* revive;
    void* race;
    HudElement* skipButton;
    bool paused;
    bool cutsceneSkipped;
    unsigned char unknown78[18];
    int taggedCount;

    void taggedKilled();
    void printCommand(const Structs::ScriptCommand& command);
    void addScript(Script* script);
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
};

#endif
