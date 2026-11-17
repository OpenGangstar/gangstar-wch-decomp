#ifndef WCH_AI_CIV_AGRESSIVE_CONTROLLER_H
#define WCH_AI_CIV_AGRESSIVE_CONTROLLER_H

#include "NPCController.h"

class CivAgressiveController : public NPCController {
public:
    CivAgressiveController(NPC*, gameloft::ai::StateID);
    virtual ~CivAgressiveController();
    virtual void onEvent(const IEvent*, const EventManager*);
    virtual void switchState(gameloft::ai::StateID, gameloft::ai::TransitionCondition);
};

#endif
