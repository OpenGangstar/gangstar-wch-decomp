#ifndef WCH_MISSIONS_SIDE_MISSION_H
#define WCH_MISSIONS_SIDE_MISSION_H

#include "../core/Vector3.h"

// Recovered virtual interface. The member layout remains pending.
class SideMission {
public:
    virtual void begin(irr::core::vector3d<float>, int, int&, float&) = 0;
    virtual bool pickUp(irr::core::vector3d<float>, int&, float&, int) = 0;
    virtual bool dropOff(irr::core::vector3d<float>) = 0;
    virtual void end() = 0;
    virtual void clean() = 0;
    virtual int getMoneyReward() = 0;
    virtual int getGoalMessage() = 0;
    virtual int getStartMessage() = 0;
    virtual int getEndMessage() = 0;
    virtual int getObj1Message() = 0;
    virtual int getObj2Message() = 0;
};

#endif
