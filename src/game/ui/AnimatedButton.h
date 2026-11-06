#ifndef WCH_UI_ANIMATED_BUTTON_H
#define WCH_UI_ANIMATED_BUTTON_H

#include "VirtualButton.h"

class AnimObject;

class AnimatedButton : public VirtualButton {
public:
    virtual ~AnimatedButton();
    virtual void update(double elapsed);
    virtual void draw2d() const;
    void setAnim(int animation);
    void grayOut(bool gray);

private:
    AnimObject* animationObject;
};

#endif
