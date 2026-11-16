#ifndef WCH_UI_MESSAGE_H
#define WCH_UI_MESSAGE_H

#include "../hud/HudElement.h"
#include "../hud/MenuManager.h"

class AnimObject;

// Partial layout recovered from the message timer and animation methods.
class Message : public HudElement {
public:
    Message(ASprite* sprite, MenuManager::eText text, int messageAnimation, int defaultAnimation);
    virtual ~Message();
    virtual void draw2d() const;
    virtual void update(double elapsed);
    bool isDisplayed();
    void clearMessage(bool clearAnimation);
    void setTimer(int duration);
    void setMessage(const char* text, int duration);
    void setMessage(int textId, int duration, MenuManager::eText slot);
    void setAnim(int animation);

private:
    AnimObject* animationObject;
    int messageAnimation;
    int defaultAnimation;
    MenuManager::eText textSlot;
    int timer;
    int animationId;
    int unknown80;
    char messageText[32];
    bool timedDisplay;
    bool untimed;
    bool pendingMessage;
};

#endif
