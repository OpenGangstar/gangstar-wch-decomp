#ifndef WCH_COMBAT_WEAPON_H
#define WCH_COMBAT_WEAPON_H

#include "../world/LevelObject.h"
namespace Structs { struct Weapon; }

// Observed layout; the complete hierarchy and runtime integration remain
// unverified. Do not treat this declaration as a fully recovered game type.
class Weapon : public LevelObject {
public:
    // Observed inline scene access used by projectile attachment; no symbol claimed.
    irr::scene::ISceneNode* projectileSceneNode() const { return sceneNode; }
    Weapon(int id);
    void Load(const Structs::Weapon& data);
    void loadWeaponFlash(const char* name, irr::scene::ISceneNode* parent,
                         irr::scene::ISceneNode*& node, irr::scene::ITimelineController*& controller);
    void drawMuzzleFlash(irr::scene::ISceneNode* node, irr::scene::ITimelineController* controller);
    virtual ~Weapon();
    int getWeaponType() const;
    int getAmmoType() const;
    int getClipSize() const;
    int getClip() const;
    int getRange() const;
    int getCone() const;
    int getDamage() const;
    int getShootfrequency() const;
    int getDryShootfrequency() const;
    bool isLocked() const;
    void setClipSize(int value);
    void setClip(int value);
    bool isDouble() const;
    bool isTwoHanded() const;
    bool isGun() const;
    bool isProjectile() const;
    bool dropsOnNPCDeath() const { return (unknown4 & 8u) != 0; }
    void show();
    void hide();
    void reloadRocket();
    void lock();
    void unlock();
    void photo();
    void playShootSound();
    void playDrySound();
    void playReloadSound();
    bool isReady(bool ignoreClip);
    void reload(bool unlimited);
    void snipe(bool flag, const irr::core::vector3d<float>& start,
               const irr::core::vector3d<float>& direction, irr::core::vector3d<float>& result);
    void shootFromCar(bool flag, const irr::core::vector3d<float>& start,
                      const irr::core::vector3d<float>& direction, irr::core::vector3d<float>& result);
    void shootProjectile(const irr::core::vector3d<float>& direction);
    void shootProjectileFromCar(const irr::core::vector3d<float>& direction);
    void shoot(bool flag, const irr::core::vector3d<float>& direction,
               irr::core::vector3d<float>& result);

private:
    friend class WeaponManager;
    int weaponType;
    int clipSize;
    int clip;
    int range;
    int cone;
    int damage;
    int shootFrequency;
    int dryShootFrequency;
    int ammoType;
    unsigned int flags;
    unsigned int lastShot;
    LevelObject* projectile;
    irr::scene::ISceneNode* muzzle;
    irr::scene::ITimelineController* timeline;
    irr::scene::ISceneNode* secondSceneNode;
    irr::scene::ISceneNode* secondMuzzle;
    irr::scene::ITimelineController* secondTimeline;
    unsigned char unknown120;
    bool locked;
};

#endif
