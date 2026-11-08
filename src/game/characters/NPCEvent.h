#ifndef WCH_CHARACTERS_NPC_EVENT_H
#define WCH_CHARACTERS_NPC_EVENT_H

#include "../core/GameEventMethods.h"

class NPC;

class EvNPC : public IEvent {
public:
    enum State { Targeted = 3, Untargeted = 4, Death = 14, DeathFlag512 = 19 };

    EvNPC(State state, NPC* npc) : state(state), npc(npc) { eventID = 16; }
    virtual ~EvNPC() {}

private:
    int state;
    NPC* npc;
};

class EvNPCDeath : public IEvent {
public:
    explicit EvNPCDeath(NPC* npc) : npc(npc) { eventID = 17; }
    virtual ~EvNPCDeath() {}

private:
    NPC* npc;
};

#endif
