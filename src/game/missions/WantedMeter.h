#ifndef WCH_MISSIONS_WANTED_METER_H
#define WCH_MISSIONS_WANTED_METER_H

#include "../hud/HudElement.h"

class AnimObject;

class WantedMeter : public HudElement {
public:
    virtual ~WantedMeter();
    virtual void update(double elapsed);
    virtual void draw2d() const;
    void setWantedLevel(unsigned int value)
    {
        if (value <= 5)
            wantedLevel = value;
    }

    void resetTimer() { timer = 0; }

private:
    AnimObject* stars[5];
    unsigned int wantedLevel;
    unsigned int timer;
};

#endif
