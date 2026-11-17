#ifndef WCH_MISSIONS_DELIVERYSIDEMISSION_H
#define WCH_MISSIONS_DELIVERYSIDEMISSION_H

#include "SideMission.h"

class DeliverySideMission : public SideMission {
public:
    DeliverySideMission();
    ~DeliverySideMission();
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
    irr::core::array<Checkpoint*> pickupCheckpoints;
    Checkpoint* dropOffCheckpoint;
};

#endif
