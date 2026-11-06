#ifndef WCH_MISSIONS_REVIVE_H
#define WCH_MISSIONS_REVIVE_H

class AnimObject;
class Cash;

class Revive {
public:
    explicit Revive(bool busted);
    ~Revive();
    void finishCashLostAnims();
    void draw2d();

private:
    int state;
    AnimObject* cashLost;
    AnimObject* cashRemaining;
    int unknown12;
    bool busted;
    int cashAnimationTime;
    Cash* cash;
};

#endif
