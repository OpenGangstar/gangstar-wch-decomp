#ifndef WCH_HUD_I_HUD_H
#define WCH_HUD_I_HUD_H

class CHudManager;

class IHud {
public:
    virtual void show() = 0;
    virtual void hide() = 0;
    virtual bool isVisible() const;
    virtual bool isWalkingHud() const;

protected:
    explicit IHud(CHudManager* hudManager) : visible(false), manager(hudManager) {}

    bool visible;
    unsigned int unknown8;
    CHudManager* manager;
};

#endif
