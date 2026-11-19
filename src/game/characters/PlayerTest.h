#ifndef WCH_CHARACTERS_PLAYER_TEST_H
#define WCH_CHARACTERS_PLAYER_TEST_H

#include "../core/Array.h"
#include "Character.h"

class Vehicle;
class PhysicAttributes;
class b2Body;
class Weapon;
class LevelObject;
class Shop;
namespace irr { namespace scene { class ISceneNode; } namespace video { class IVideoDriver; } }
namespace irr { namespace core { class quaternion; template<class T> class vector3d; } }

// Partial observed layout and call interfaces, not the complete original class.
class PlayerTest;
typedef PlayerTest SavePrimaryInterface;
typedef Character SavePositionInterface;

namespace playertest { struct PlayerCarState { enum ePlayerCarState { MovingOut = 7 }; }; }

#include "../core/IMapTrackable.h"

class PlayerTest : public IMapTrackable, public Character {
public:
    // The retail destructor is pending. Its declaration keeps vtable emission with its definition.
    virtual ~PlayerTest();
    virtual void Stop();
    virtual void setVehicle(Vehicle* value);
    virtual bool shoot(float elapsed, bool pressed);
    virtual void applyDamage(int amount, LevelObject* source, bool bypassArmor);
    virtual Vehicle* getVehicle() const;
    virtual Weapon* getWeapon() const;
    virtual void walkToLocation(const irr::core::vector3d<float>& point);
    virtual void runToLocation(const irr::core::vector3d<float>& point);

    void stopMoving(bool fast);
    void move(float direction, float magnitude);
    void setAnim(int animation, bool first, bool second, bool third, float speed);

    // Reconstructed inline armor access; these names claim no retail symbols.
    int getContextArmor() const { return contextValues[contextWord]; }
    void setContextArmor(int amount) { contextValues[contextWord] = amount; }
    void addContextArmor(int amount)
    {
        setContextArmor(getContextArmor() + amount);
        if (getContextArmor() > 200)
            setContextArmor(200);
    }
    enum eContext { Context0 = 0, Context1 = 1, AnyContext = -1 };
    static PlayerTest* GetPlayer();
    void acquireTarget();
    static LevelObject* getAttackableTarget(LevelObject*, Weapon*, LevelObject*);
    void addPhotoTarget(LevelObject* target);
    void clearPhotoTargets();
    // Inline access to the observed target at offset 264; no standalone symbol claimed.
    LevelObject* getTarget() const { return target; }
    LevelObject* _GetTarget();
    int getMarkerType();
    void hideAllAnims();
    void hideMesh();
    void showMesh();
    void playCurAnimFromStart();
    void initMoveTo(const Vehicle* vehicle);
    void setClosestShop(Shop* shop);
    void justStoleCar(Vehicle* car);
    void _SetTarget(LevelObject* target, bool changeCamera);
    void toggleLock();
    bool attack(bool pressed);
    void initDriving(bool);
    void onTargetCancelled();
    void resumeAttacking();
    void richAsCroesus(bool enabled);
    bool isRichAsCroesus() const;
    int getAmbientSound() const;
    void setCash(int value);
    void subCash(int amount);
    void addCash(int amount, int maximum);
    void addCurrentDriftDistance(float distance);
    void addCurrentJumpDistance(float distance);
    void jumpFinished();
    void driftFinished();
    void addDistanceDriven(float distance);
    void setLastUsedVehicle(Vehicle* replacement);
    void switchContext(eContext context, bool flag);
    void switchWeapon(bool unarmed);
    void lockSwitchWeapon();
    void unlockSwitchWeapon();
    void Respawn();
    bool photo(Weapon* weapon);
    bool snipe(Weapon* weapon);
    void onObjectKilled(LevelObject* object);
    void startDriving();
    void SetSpeed() __attribute__((weak));
    void ResetPlayerTest(bool);
    void teleportTo(const LevelObject* object);
    void stopDriving(playertest::PlayerCarState::ePlayerCarState state, bool instant);
    void finishedStopDriving();
    int getCarAnimName(const char* name, bool left);
    void Update();
    void UpdateSceneNode();
    bool isFacingTarget();
    bool orientTowards(irr::core::vector3d<float> direction);
    void debug(irr::video::IVideoDriver* driver);
    using Character::facing;
    using Character::shadowNode;
    using Character::collisionBody;
    using Character::vehicle;
    using Character::lastHitVehicle;
    using Character::maximumHealth;
    using Character::health;
    using Character::flags240;
    using Character::unknown260;
    using Character::target;
    using LevelObject::physicAttributes;
    unsigned char unknown300[12];
    LevelObject* unknown312;
    LevelObject* unknown316;
    Shop* closestShop;
    int unknown324;
    int attackState;
    unsigned char unknown332[4];
    float unknown336;
    unsigned char unknown340[13];
    bool lockRequested;
    bool targetLocked;
    bool lockUpdatePending;
    bool combatMode;
    unsigned char unknown357[11];
    LevelObject* unknown368;
    int unknown372;
    bool vehicleVisibleInCinematic;
    unsigned char unknown377;
    bool movementKeys[4];
    bool damageDisabled;
    bool flag383;
    unsigned char unknown384[28];
    float speed;
    bool richAsCroesusEnabled;
    bool unknown417;
    unsigned char unknown418[2];
    int cash;
    bool unknown424;
    unsigned char unknown425[3];
    // Item::add reads the complete word at 428; existing enum users retain
    // their observed access width. Both views occupy the same storage.
    union { eContext context; int contextWord; };
    irr::scene::ISceneNode* inactiveContextNodes[2];
    unsigned char unknown440[12];
    struct ContextRecord {
        irr::scene::ISceneNode* node;
        int data0, data1, data2;
    };
    ContextRecord contextRecords[2];
    irr::core::array<LevelObject*> photoTargets;
    bool weaponSwitchLocked;
    unsigned char unknown505[3];
    int contextValues[2];
private:
    static PlayerTest* s_player;
};


#endif
