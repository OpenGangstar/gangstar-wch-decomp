#ifndef WCH_MISSIONS_MISSION_CONDITION_BE_QUICK_H
#define WCH_MISSIONS_MISSION_CONDITION_BE_QUICK_H

#include "IMissionCondition.h"

class MissionConditionBeQuick : public IMissionCondition {
public:
    explicit MissionConditionBeQuick(int duration);
    virtual ~MissionConditionBeQuick();
    virtual bool evaluate(int elapsed);
    virtual void draw();

protected:
    int duration;
};

#endif
