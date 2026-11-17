#ifndef WCH_MISSIONS_AMBULANCESIDEMISSION_H
#define WCH_MISSIONS_AMBULANCESIDEMISSION_H

#include "SideMission.h"

class AmbulanceSideMission : public SideMission {
public:
    AmbulanceSideMission();
    ~AmbulanceSideMission();
    virtual void begin(irr::core::vector3d<float>, int, int&, float&);
    virtual bool pickUp(irr::core::vector3d<float>, int&, float&, int);
    virtual bool dropOff(irr::core::vector3d<float>);
    virtual void end();
    virtual void clean();
    virtual int getMoneyReward();
    virtual int getGoalMessage();
    virtual int getStartMessage();
    virtual int getEndMessage();
    virtual int getObj1Message();
    virtual int getObj2Message();

private:
    Checkpoint* checkpoint;
    irr::core::array<Checkpoint*> dropOffCheckpoints;
};

#endif
