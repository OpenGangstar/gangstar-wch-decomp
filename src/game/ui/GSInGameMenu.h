#ifndef WCH_UI_GSINGAMEMENU_H
#define WCH_UI_GSINGAMEMENU_H

#include "../core/StateBase.h"

// Observed allocation extent, StateBase interface and constructor stores.
// Remaining callback bodies and field meanings are provisional.
class GSInGameMenu : public StateBase {
public:
    GSInGameMenu();
    static void skipFadeIn();
    virtual ~GSInGameMenu();
    virtual void draw(const StateMachine*);
    virtual void ctor(const StateMachine*);
    virtual void dtor(const StateMachine*);
    virtual void update(StateMachine*);
    virtual void draw2d(const StateMachine*);
    virtual bool isKindOf(int kind) {
        if (kind == 16) return true;
        return StateBase::isKindOf(kind);
    }
private:
    static bool s_skipFadeIn;

    unsigned int unknown4;
    unsigned int unknown8;
    unsigned int unknown12;
    unsigned int unknown16;
};

#endif
