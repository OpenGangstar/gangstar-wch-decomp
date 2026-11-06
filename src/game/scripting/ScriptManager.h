#ifndef WCH_SCRIPTING_SCRIPT_MANAGER_H
#define WCH_SCRIPTING_SCRIPT_MANAGER_H

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
    unsigned char unknown36[24];
    void* mission;
    unsigned char unknown64[4];
    void* race;
    HudElement* skipButton;
    bool paused;
    unsigned char unknown77[19];
    int taggedCount;

    void taggedKilled();
    void printCommand(const Structs::ScriptCommand& command);
    void addScript(Script* script);
    bool areBlockingCommandsSkipped() const;
    bool isInCinematic() const;
    bool isSkipButtonVisible() const;
    int getFailureCause();
    static int s_failure;
};

#endif
