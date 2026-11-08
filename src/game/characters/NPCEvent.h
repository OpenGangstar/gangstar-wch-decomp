#ifndef WCH_CHARACTERS_NPC_EVENT_H
#define WCH_CHARACTERS_NPC_EVENT_H

#include "../core/GameEventMethods.h"

class NPC;

class EvNPC : public IEvent {
public:
    enum TargetState { Targeted = 3, Untargeted = 4 };

    EvNPC(TargetState state, NPC* npc) : state(state), npc(npc) { eventID = 16; }
    virtual ~EvNPC() {}

private:
    int state;
    NPC* npc;
};

#endif
