#ifndef WCH_HUD_CHUD_MANAGER_H
#define WCH_HUD_CHUD_MANAGER_H

// Partial layout; total extent and component type/flag meaning are not established.
struct HudComponent116 {
    unsigned char unknown0[56];
    bool unknown56;
};
class CHudManager {
public:
    void show();
    void hide();
    void init();
    void lock();
    void unlock();
    bool isLocked() const;
    void toggleWeaponSelector(bool visible);
    void switchWeapon(int type);
    unsigned char unknown0[4];
    void* activeHud;
    void* initialHud;
    void* unknownHud12;
    unsigned char unknown16[100];
    HudComponent116* component116;
    unsigned char unknown120[84];
    unsigned int unknown204;
    bool locked;
};

#endif
