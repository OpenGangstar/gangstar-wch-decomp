#ifndef WCH_MISSIONS_REWARD_H
#define WCH_MISSIONS_REWARD_H

#include "../hud/HudElement.h"

class AnimObject;
class Cash;

class Reward : public HudElement {
public:
    Reward(ASprite* sprite, int animation);
    virtual ~Reward();
    virtual void update(double elapsed);
    virtual void draw2d() const;
    void setAnim(int animation);
    void setMessage(int amount, int duration);

private:
    AnimObject* animation;
    int rewardAnimation;
    int timer;
    int currentAnimation;
    bool countingDown;
    Cash* cash;
    bool active;
};

#endif
