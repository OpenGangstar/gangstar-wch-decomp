#ifndef WCH_SCRIPTING_SCRIPT_H
#define WCH_SCRIPTING_SCRIPT_H

#include "../characters/PlayerTest.h"

namespace Structs {
struct ScriptCommand {
    int opcode;
    int argument;
};
}

namespace stlp_priv {
struct _Rb_tree_node_base;
}

struct ScriptActionTree {
    ~ScriptActionTree();
    unsigned char headerColor;
    stlp_priv::_Rb_tree_node_base* root;
    stlp_priv::_Rb_tree_node_base* left;
    stlp_priv::_Rb_tree_node_base* right;
    unsigned int count;
    unsigned char allocator;
};

// Partial layout. The script storage beyond the observed fields is unresolved.
class Script {
    friend class ScriptManager;
public:
    Script(int commandCount);
    ~Script();
    enum State { State0 = 0, State1 = 1, State2 = 2, WaitingForChild = 3, StateForceWidth = 0x7fffffff };
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
    void lockScript(int id);
    void execute(int elapsed);
    void executeSubScript(int id, int command);
    void nextCommand(int index);
    bool executeCommand(const Structs::ScriptCommand* command, int elapsed, int argument);
    enum eScriptAction { ActiveObject = 1, MinimapObject = 4 };
    void unsetScriptObjectAction(LevelObject* object, eScriptAction action);

private:
    ScriptActionTree objectActions;
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
    LevelObject* source;
    int unknown72;
};

#endif
