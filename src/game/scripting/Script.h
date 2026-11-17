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
    struct Allocator {};
    ScriptActionTree(const Allocator& storage = Allocator())
        : headerColor(0), root(0),
          left(reinterpret_cast<stlp_priv::_Rb_tree_node_base*>(this)),
          right(reinterpret_cast<stlp_priv::_Rb_tree_node_base*>(this)),
          count(0), allocator(storage) {}
    ~ScriptActionTree();
    void clear();
    int& operator[](LevelObject* const& object)
        __asm__("_ZNSt3mapIP11LevelObjectiSt4lessIS1_ESaISt4pairIKS1_iEEEixIS1_EERiRKT_")
        __attribute__((weak));
    unsigned char headerColor;
    stlp_priv::_Rb_tree_node_base* root;
    stlp_priv::_Rb_tree_node_base* left;
    stlp_priv::_Rb_tree_node_base* right;
    unsigned int count;
    Allocator allocator;
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
    void clearScriptObjectAction();
    void setScriptObjectAction(LevelObject* object, eScriptAction action);
    void unsetScriptObjectAction(LevelObject* object, eScriptAction action);

private:
    ScriptActionTree objectActions;
    int commandCapacity;
    int commandCount;
    int commandIndex;
    Structs::ScriptCommand** commands;
    int unknown40;
    bool unknown44;
    unsigned char unknown45[7];
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
