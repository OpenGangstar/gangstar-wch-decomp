#ifndef WCH_CHARACTERS_PLAYER_TEST_H
#define WCH_CHARACTERS_PLAYER_TEST_H

#include "../core/Array.h"

class Vehicle;
class PhysicAttributes;
class b2Body;
class Weapon;
class LevelObject;
class Shop;
namespace irr { namespace scene { class ISceneNode; } namespace video { class IVideoDriver; } }
namespace irr { namespace core { class quaternion; template<class T> class vector3d; } }

// Partial observed layout and call interfaces, not the complete original class.
struct SaveVector3 {
    float x, y, z;
    SaveVector3() {}
    SaveVector3(float a, float b, float c) : x(a), y(b), z(c) {}
};
class SavePositionInterface {
public:
    virtual void unknown0(); virtual void unknown1(); virtual void unknown2();
    virtual void unknown3(); virtual void unknown4(); virtual void unknown5();
    virtual void unknown6(); virtual void unknown7(); virtual void unknown8();
    virtual void unknown9();
    virtual unsigned short GetMatID() const;
    virtual unsigned short GetTriID() const;
    virtual irr::core::vector3d<float> position() const;
    virtual const irr::core::quaternion& GetRotation() const;
    virtual void unknown14(); virtual void unknown15();
    virtual void position(const SaveVector3& value);
    virtual void unknown17();
    virtual void unknown18();
    virtual int getMaxHealth() const;
    virtual int getHealth() const;
    virtual bool isDead();
    virtual void unknown22();
    virtual void unknown23();
    virtual void unknown24();
    virtual void unknown25();
    virtual void unknown26();
    virtual void unknown27();
    virtual void Stop();
    virtual void unknown29();
    virtual void unknown30();
    virtual void unknown31();
    virtual void unknown32();
    virtual void applyDamage(int amount, LevelObject* source, bool bypassArmor);
    virtual void unknown34();
    virtual bool setAnimation(const char* name, int speed, bool a, bool b, bool c);
    virtual void unknown36();
    virtual void unknown37();
    virtual void setNextAnimation(int, int, bool, bool, bool);
    virtual void unknown39();
    virtual bool setAnimation(int, float, bool, bool, bool);
    virtual bool shoot(float, bool);
    virtual void unknown42();
    virtual void unknown43();
    virtual void unknown44();
    virtual void unknown45();
    virtual void setVehicle(Vehicle* value);
    virtual Vehicle* getVehicle() const;
    virtual void unknown48(); virtual void unknown49(); virtual void unknown50();
    virtual void unknown51();
    virtual void walkToLocation(const irr::core::vector3d<float>& point);
    virtual void runToLocation(const irr::core::vector3d<float>& point);
    virtual Weapon* getWeapon() const;
    virtual void SetTarget(LevelObject* target);
};

class SavePrimaryInterface {
public:
    virtual void unknownPrimary();
    virtual ~SavePrimaryInterface();
    virtual void Stop();
    virtual void setVehicle(Vehicle* value);
    virtual void unknownPrimary5();
    virtual void applyDamage(int amount, LevelObject* source, bool bypassArmor);
    virtual Vehicle* getVehicle() const;
    virtual Weapon* getWeapon() const;
};
namespace playertest { struct PlayerCarState { enum ePlayerCarState { MovingOut = 7 }; }; }

class PlayerTest : public SavePrimaryInterface, public SavePositionInterface {
public:
    // The retail destructor is pending. Its declaration keeps vtable emission with its definition.
    virtual ~PlayerTest();
    virtual bool shoot(float elapsed, bool pressed);
    void stopMoving(bool fast);
    void move(float direction, float magnitude);
    void setAnim(int animation, bool first, bool second, bool third, float speed);
    virtual void Stop();
    virtual void applyDamage(int amount, LevelObject* source, bool bypassArmor);

    // Reconstructed inline armor access; these names claim no retail symbols.
    int getContextArmor() const { return contextValues[contextWord]; }
    void setContextArmor(int amount) { contextValues[contextWord] = amount; }
    void addContextArmor(int amount)
    {
        setContextArmor(getContextArmor() + amount);
        if (getContextArmor() > 200)
            setContextArmor(200);
    }
    virtual Vehicle* getVehicle() const;
    virtual Weapon* getWeapon() const;
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
    virtual void walkToLocation(const irr::core::vector3d<float>& point);
    virtual void runToLocation(const irr::core::vector3d<float>& point);
    void lockSwitchWeapon();
    void unlockSwitchWeapon();
    void Respawn();
    bool photo(Weapon* weapon);
    void startDriving();
    void SetSpeed();
    void ResetPlayerTest(bool);
    void setVehicle(Vehicle* value);
    void teleportTo(const LevelObject* object);
    void stopDriving(playertest::PlayerCarState::ePlayerCarState state, bool instant);
    void finishedStopDriving();
    int getCarAnimName(const char* name, bool left);
    void Update();
    void UpdateSceneNode();
    bool isFacingTarget();
    bool orientTowards(irr::core::vector3d<float> direction);
    void debug(irr::video::IVideoDriver* driver);
    unsigned char unknown8[12];
    irr::scene::ISceneNode* sceneNode;
    unsigned char unknown24[4];
    PhysicAttributes* physicAttributes;
    unsigned char unknown32[28];
    SaveVector3 facing;
    unsigned char unknown72[108];
    irr::scene::ISceneNode* shadowNode;
    b2Body* collisionBody;
    unsigned char unknown188[4];
    Vehicle* vehicle;
    unsigned char unknown196[4];
    Vehicle* lastHitVehicle;
    unsigned char unknown204[16];
    int maximumHealth;
    int health;
    unsigned char unknown228[12];
    unsigned int flags240;
    unsigned char unknown244[16];
    bool unknown260;
    unsigned char unknown261[3];
    LevelObject* target;
    unsigned char unknown268[44];
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
    unsigned char unknown432[40];
    int currentDistanceDriven;
    int currentDriftDistance;
    int currentJumpDistance;
    irr::core::array<LevelObject*> photoTargets;
    bool weaponSwitchLocked;
    unsigned char unknown505[3];
    int contextValues[2];
private:
    static PlayerTest* s_player;
};


#endif
