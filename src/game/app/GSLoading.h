#ifndef WCH_APP_GSLOADING_H
#define WCH_APP_GSLOADING_H

#include "../core/StateBase.h"

// Observed allocation extent, StateBase interface and constructor stores.
// Remaining callback bodies and field meanings are provisional.
class GSLoading : public StateBase {
public:
    static bool isGameLoaded();
    static void setGameLoaded(bool);
    GSLoading();
    virtual ~GSLoading();
    virtual void ctor(const StateMachine*);
    virtual void dtor(const StateMachine*);
    virtual void update(StateMachine*);
    virtual void draw(const StateMachine*);
    virtual bool isKindOf(int kind) {
        if (kind == 17) return true;
        return StateBase::isKindOf(kind);
    }
private:
    static bool s_bGameLoaded;
    unsigned char unknown4[8];
};

#endif
