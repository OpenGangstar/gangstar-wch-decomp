#ifndef WCH_UI_GSSIDEMISSIONMENU_H
#define WCH_UI_GSSIDEMISSIONMENU_H

#include "../core/StateBase.h"

// Observed allocation extent, StateBase interface and constructor stores.
// Remaining callback bodies and field meanings are provisional.
class Vehicle;

class GSSideMissionMenu : public StateBase {
public:
    GSSideMissionMenu();
    virtual ~GSSideMissionMenu();
    virtual void draw(const StateMachine*);
    virtual void draw2d(const StateMachine*);
    virtual void ctor(const StateMachine*);
    virtual void dtor(const StateMachine*);
    virtual void update(StateMachine*);
    virtual bool isKindOf(int kind) {
        if (kind == 20) return true;
        return StateBase::isKindOf(kind);
    }
private:
    unsigned int unknown4;
    unsigned int unknown8;
    unsigned int unknown12;
    unsigned int unknown16;
    Vehicle* stoppedVehicle;
};

#endif
