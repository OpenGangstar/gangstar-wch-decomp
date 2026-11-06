#ifndef WCH_SCRIPTING_SCRIPT_H
#define WCH_SCRIPTING_SCRIPT_H

#include "../characters/PlayerTest.h"

namespace Structs { struct ScriptCommand; }

// Partial layout. The script storage beyond the observed fields is unresolved.
class Script {
public:
    enum State { State0 = 0, State1 = 1, State2 = 2, StateForceWidth = 0x7fffffff };
    void addCommand(Structs::ScriptCommand* command);
    int getMissionId() const;
    bool isEnded() const;
    State getState() const;
    Structs::ScriptCommand* peekCommand(int offset) const;
    void* getSource() const;
    void setParent(Script* script);
    Script* getParent() const;
    void setState(State state, PlayerTest::eContext context);
    void unlockScript(int id);
    void freezeScript(int id);
    void rewind();
    void finalize();

private:
    unsigned char unknown0[24];
    int commandCapacity;
    int commandCount;
    int commandIndex;
    Structs::ScriptCommand** commands;
    unsigned char unknown40[12];
    State state;

public:
    union { PlayerTest::eContext context; int contextWord; };

private:
    Script* parent;
    int missionId;
    void* source;
};

#endif
