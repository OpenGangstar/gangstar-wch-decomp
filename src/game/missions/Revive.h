#ifndef WCH_MISSIONS_REVIVE_H
#define WCH_MISSIONS_REVIVE_H

class AnimObject;
class HudElement;

class Revive {
public:
    ~Revive();
    void finishCashLostAnims();
    void draw2d();

private:
    int state;
    AnimObject* cashLost;
    AnimObject* cashRemaining;
    unsigned char unknown12[8];
    int cashAnimationTime;
    HudElement* cash;
};

#endif
