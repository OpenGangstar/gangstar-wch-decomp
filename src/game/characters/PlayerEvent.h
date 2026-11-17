#ifndef WCH_CHARACTERS_PLAYER_EVENT_H
#define WCH_CHARACTERS_PLAYER_EVENT_H

#include "../core/GameEventMethods.h"
class EvPlayer : public IEvent {
public:
    explicit EvPlayer(int value) : IEvent(22), state(value) {}
    int getState() const { return state; }
    virtual ~EvPlayer() __attribute__((used)) {}
private:
    int state;
};

#endif
