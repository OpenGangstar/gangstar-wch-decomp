#ifndef WCH_AI_CIV_PASSIVE_CONTROLLER_H
#define WCH_AI_CIV_PASSIVE_CONTROLLER_H

#include "NPCController.h"

class CivPassiveController : public NPCController {
public:
    CivPassiveController(NPC*, const gameloft::ai::Transition&, gameloft::ai::StateID);
    virtual ~CivPassiveController();
    virtual void onEvent(const IEvent*, const EventManager*);
    virtual void switchState(gameloft::ai::StateID, gameloft::ai::TransitionCondition);
};

#endif
