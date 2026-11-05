#ifndef WCH_HUD_C_WALKING_HUD_H
#define WCH_HUD_C_WALKING_HUD_H

#include "IHud.h"

class CWalkingHud : public IHud {
public:
    explicit CWalkingHud(CHudManager* manager);
    ~CWalkingHud();
    virtual void show();
    virtual void hide();
    virtual bool isWalkingHud() const __attribute__((used));
    void nearCar();
    void notNearCar();
    void nearShop();
    bool isNearShop() const;
    void notNearShop();
};

#endif
