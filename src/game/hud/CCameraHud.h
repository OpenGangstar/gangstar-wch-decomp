#ifndef WCH_HUD_C_CAMERA_HUD_H
#define WCH_HUD_C_CAMERA_HUD_H

#include "IHud.h"

class CCameraHud : public IHud {
public:
    explicit CCameraHud(CHudManager* manager);
    ~CCameraHud();
    virtual void show();
    virtual void hide();
};

#endif
