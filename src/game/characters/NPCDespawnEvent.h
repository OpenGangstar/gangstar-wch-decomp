#ifndef WCH_CHARACTERS_NPC_DESPAWN_EVENT_H
#define WCH_CHARACTERS_NPC_DESPAWN_EVENT_H

#include "../core/GameEventMethods.h"

class LevelObject;

class EvNPCDespawn : public IEvent {
public:
    explicit EvNPCDespawn(LevelObject* object) : object(object) { eventID = 18; }
    virtual ~EvNPCDespawn() {}

private:
    LevelObject* object;
};

#endif
