#ifndef WCH_HUD_C_DRIVING_HUD_H
#define WCH_HUD_C_DRIVING_HUD_H

#include "IHud.h"

class CDrivingHud : public IHud {
public:
    explicit CDrivingHud(CHudManager* manager);
    ~CDrivingHud();
    virtual void show();
    virtual void hide();
    void showSpyGauge(bool show);
    void showCash(bool show);
    void toggleWeaponSelector(bool show);
};

#endif
