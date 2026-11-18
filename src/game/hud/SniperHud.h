#ifndef WCH_HUD_C_SNIPER_HUD_H
#define WCH_HUD_C_SNIPER_HUD_H

#include "IHud.h"

class CSniperHud : public IHud {
public:
    explicit CSniperHud(CHudManager*);
    ~CSniperHud();
    virtual void show();
    virtual void hide();
};

#endif
