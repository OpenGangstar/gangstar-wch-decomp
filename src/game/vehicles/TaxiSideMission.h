#ifndef WCH_VEHICLES_TAXISIDEMISSION_H
#define WCH_VEHICLES_TAXISIDEMISSION_H

#include "../missions/SideMission.h"

class TaxiSideMission : public SideMission {
public:
    TaxiSideMission();
    ~TaxiSideMission();
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
    int pickupDelay;
};

#endif
