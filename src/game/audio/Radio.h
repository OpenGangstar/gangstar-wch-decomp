#ifndef WCH_AUDIO_RADIO_H
#define WCH_AUDIO_RADIO_H

#include "../ui/SwipeButton.h"

class AnimObject;

class Radio : public SwipeButton {
public:
    Radio(ASprite* sprite, int frame, int stationAnimation, int value1,
          int value2, int disabledFrame, int mutedAnimation);
    virtual inline ~Radio();
    virtual inline void show();
    virtual void draw2d() const;
    virtual void processTouch(long touch);

private:
    friend class CControlManager;
    AnimObject* animation;
    int stationAnimation;
    int unknown68;
    int unknown72;
    int disabledFrame;
    int mutedAnimation;
    unsigned int radioFlags;
};

#endif
