#ifndef WCH_AI_COP_CONTROLLER_H
#define WCH_AI_COP_CONTROLLER_H

#include "NPCController.h"

class CopController : public NPCController {
public:
    CopController(NPC*, gameloft::ai::StateID);
    virtual ~CopController();
    virtual void onEvent(const IEvent*,const EventManager*);
    virtual void switchState(gameloft::ai::StateID,gameloft::ai::TransitionCondition);
    static bool s_hasAttemptedArrest;
private:
    unsigned int unknown16;
    bool unknown20;
};

#endif
