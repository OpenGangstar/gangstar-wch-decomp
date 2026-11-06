#ifndef WCH_HUD_CHUD_MANAGER_H
#define WCH_HUD_CHUD_MANAGER_H

class AnalogStick;
class ASprite;
class AnimatedButton;
class HudElement;
class IHud;
class SpyGauge;
class WantedMeter;

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
    IHud* sniperHud;
    IHud* cameraHud;
    unsigned char unknown24[8];
    ASprite* reviveSprite;
    AnalogStick* analogStick;
    unsigned char unknown40[28];
    HudElement* enterCarButton;
    HudElement* enterShopButton;
    unsigned char unknown76[40];
    HudComponent116* component116;
    unsigned char unknown120[8];
    AnimatedButton* radioButton;
    unsigned char unknown132[4];
    HudElement* minimap;
    unsigned char unknown140[12];
    SpyGauge* spyGauge;
    HudElement* weaponSelectorControl;
    unsigned char unknown160[4];
    WantedMeter* wantedMeter;
    unsigned char unknown168[16];
    HudElement* weaponSelector;
    HudElement* weaponSelectorExtra;
    HudElement** resetElementsBegin;
    HudElement** resetElementsEnd;
    HudElement** resetElementsCapacity;
    unsigned int unknown204;
    bool locked;

    void nearCar();
    void notNearCar();
    void nearShop();
    bool isNearShop() const;
    void notNearShop();
    void showSpyGauge(bool show);
    void showCash(bool show);
    bool isVisible() const;
    bool isMinimapVisible();
    bool isWeaponVisible() const;
    void walking();
    void driving();
    void sniping();
    void toggleRadioCB(bool enabled);
};

#endif
