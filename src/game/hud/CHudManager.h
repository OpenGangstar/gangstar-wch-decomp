#ifndef WCH_HUD_CHUD_MANAGER_H
#define WCH_HUD_CHUD_MANAGER_H

#include "../core/FrameInterfaces.h"
#include "../core/PointerVector.h"

class AnalogStick;
class Wheel;
class VirtualButton;
class SlideControl;
class MiniMap;
class HealthBar;
class ArmorBar;
class CarBar;
class Cash;
class HitWarning;
class Background;
class Message;
class RetroEffect;
class Ammo;
class ASprite;
class AnimatedButton;
class CameraManager;
class HudElement;
class IHud;
class ITouchable;
class SpyGauge;
class Radio;
class Reward;
class ToggleButton;
class WantedMeter;

// Partial layout; total extent and component type/flag meaning are not established.
struct HudComponent116 {
    unsigned char unknown0[56];
    bool unknown56;
};
class CHudManager : public IUpdatable {
public:
    CHudManager();
    virtual ~CHudManager();
    virtual void update(double elapsed);
    enum SteeringMode { ObservedSteering2 = 2, ObservedSteering200000 = 0x200000, ObservedSteering800000 = 0x800000 };
    enum ThrottleMode { ObservedThrottleA = 0x001c0000, ObservedThrottleB = 0x00400008, ObservedThrottleC = 0x00030004 };
    void setSteeringMode(SteeringMode mode) __attribute__((weak));
    void setThrottleMode(ThrottleMode mode) __attribute__((weak));
    void regUpdatableComponents();
    void unregUpdatableComponents();
    void regDrawableComponents();
    void unregDrawableComponents();
    void blink(int component);
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
    void switchWeapon();
    IHud* activeHud;
    IHud* initialHud;
    IHud* drivingHud;
    IHud* sniperHud;
    IHud* cameraHud;
    SteeringMode steeringMode;
    ThrottleMode throttleMode;
    ASprite* reviveSprite;
    AnalogStick* analogStick;
    Wheel* component40;
    VirtualButton* component44;
    VirtualButton* component48;
    VirtualButton* component52;
    VirtualButton* component56;
    VirtualButton* component60;
    VirtualButton* component64;
    VirtualButton* enterCarButton;
    VirtualButton* enterShopButton;
    VirtualButton* component76;
    SlideControl* component80;
    SlideControl* component84;
    VirtualButton* component88;
    VirtualButton* component92;
    VirtualButton* component96;
    VirtualButton* component100;
    ToggleButton* radioToggle;
    Radio* radio;
    HudElement* component112;
    Background* component116;
    VirtualButton* component120;
    VirtualButton* component124;
    AnimatedButton* radioButton;
    RetroEffect* retroOverlay;
    MiniMap* minimap;
    HealthBar* component140;
    ArmorBar* component144;
    CarBar* component148;
    SpyGauge* spyGauge;
    Ammo* ammoDisplay;
    Cash* component160;
    WantedMeter* wantedMeter;
    HitWarning* component168;
    Message* message172;
    Message* message176;
    Reward* reward;
    AnimatedButton* weaponSelector;
    AnimatedButton* weaponSelectorExtra;
    std::vector<HudElement*> resetElements;
    ITouchable* defaultReceiver;
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
    void retroEffect(bool enabled);
    bool isAnyMessageDisplayed() __attribute__((weak));
    void limitToWeapon(int weaponId);
};

#endif
