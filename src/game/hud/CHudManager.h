#ifndef WCH_HUD_CHUD_MANAGER_H
#define WCH_HUD_CHUD_MANAGER_H

class HudElement;
class IHud;
class SpyGauge;

// Partial layout; total extent and component type/flag meaning are not established.
struct HudComponent116 {
    unsigned char unknown0[56];
    bool unknown56;
};
class CHudManager {
public:
    void useSpyBGInSpyGauge();
    void useDriveBadBGInSpyGauge();
    void useDriveWellBGInSpyGauge();
    void show();
    void hide();
    void init();
    void lock();
    void unlock();
    bool isLocked() const;
    void toggleWeaponSelector(bool visible);
    void switchWeapon(int type);
    unsigned char unknown0[4];
    IHud* activeHud;
    IHud* initialHud;
    IHud* drivingHud;
    unsigned char unknown16[52];
    HudElement* enterCarButton;
    HudElement* enterShopButton;
    unsigned char unknown76[40];
    HudComponent116* component116;
    unsigned char unknown120[32];
    SpyGauge* spyGauge;
    unsigned char unknown156[48];
    unsigned int unknown204;
    bool locked;

    void nearCar();
    void notNearCar();
    void nearShop();
    bool isNearShop() const;
    void notNearShop();
    void showSpyGauge(bool show);
    void showCash(bool show);
};

#endif
