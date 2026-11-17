#ifndef WCH_RENDERING_RETRO_EFFECT_H
#define WCH_RENDERING_RETRO_EFFECT_H

#include "../hud/HudElement.h"
#include "../core/Material.h"

class RetroEffect : public HudElement {
public:
    RetroEffect();
    virtual ~RetroEffect();
    virtual void draw2d() const;

private:
    irr::video::ITexture* texture;
    irr::video::SMaterial material;
};

#endif
