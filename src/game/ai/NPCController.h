#ifndef WCH_AI_NPC_CONTROLLER_H
#define WCH_AI_NPC_CONTROLLER_H

#include "AIManager.h"

namespace gameloft { namespace ai {
struct Transition;
enum TransitionCondition { UnknownTransitionCondition = 0 };
} }

class NPCController : public IEventReceiver {
public:
    NPCController(gameloft::ai::StateID state, NPC* npc,
        const gameloft::ai::Transition& transition);
    virtual ~NPCController();
    virtual void onEvent(const IEvent*, const EventManager*);
    virtual void switchState(gameloft::ai::StateID, gameloft::ai::TransitionCondition) __attribute__((weak));

private:
    unsigned int state;
    NPC* npc;
    const gameloft::ai::Transition& transition;
};

#endif
