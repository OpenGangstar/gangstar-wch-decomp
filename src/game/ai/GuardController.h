#ifndef WCH_AI_GUARD_CONTROLLER_H
#define WCH_AI_GUARD_CONTROLLER_H

#include "NPCController.h"

class GuardController : public NPCController {
public:
    GuardController(NPC*, gameloft::ai::StateID);
    virtual ~GuardController();
    virtual void onEvent(const IEvent*, const EventManager*);
    virtual void switchState(gameloft::ai::StateID, gameloft::ai::TransitionCondition);
};

#endif
