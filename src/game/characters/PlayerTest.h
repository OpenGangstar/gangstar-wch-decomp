#ifndef WCH_CHARACTERS_PLAYER_TEST_H
#define WCH_CHARACTERS_PLAYER_TEST_H

#include "../core/Array.h"

class Vehicle;
class b2Body;
class Weapon;
class LevelObject;
class Shop;
namespace irr { namespace scene { class ISceneNode; } }
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
    virtual void unknown28();
    virtual void unknown29();
    virtual void unknown30();
    virtual void unknown31();
    virtual void unknown32();
    virtual void unknown33();
    virtual void unknown34();
    virtual void setAnimation(const char* name, int speed, bool a, bool b, bool c);
    virtual void unknown36();
    virtual void unknown37();
    virtual void unknown38();
    virtual void unknown39();
    virtual void unknown40();
    virtual void unknown41();
    virtual void unknown42();
    virtual void unknown43();
    virtual void unknown44();
    virtual void unknown45();
    virtual void unknown46();
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
    virtual void unknownPrimary1(); virtual void unknownPrimary2();
    virtual void Stop(); virtual void unknownPrimary4();
    virtual void unknownPrimary5(); virtual void unknownPrimary6();
    virtual Vehicle* getVehicle() const;
    virtual Weapon* getWeapon() const;
};
class PlayerTest : public SavePrimaryInterface, public SavePositionInterface {
public:
    // The retail destructor is pending. Its declaration keeps vtable emission with its definition.
    virtual ~PlayerTest();
    virtual void Stop();

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
    void startDriving();
    void Update();
    void UpdateSceneNode();
    unsigned char unknown8[12];
    irr::scene::ISceneNode* sceneNode;
    unsigned char unknown24[156];
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
    unsigned char unknown244[20];
    LevelObject* target;
    unsigned char unknown268[44];
    LevelObject* unknown312;
    LevelObject* unknown316;
    Shop* closestShop;
    unsigned char unknown324[4];
    int attackState;
    unsigned char unknown332[21];
    bool lockRequested;
    bool targetLocked;
    bool lockUpdatePending;
    bool combatMode;
    unsigned char unknown357[11];
    LevelObject* unknown368;
    unsigned char unknown372[4];
    bool vehicleVisibleInCinematic;
    unsigned char unknown377;
    bool movementKeys[4];
    unsigned char unknown382;
    bool flag383;
    unsigned char unknown384[32];
    bool richAsCroesusEnabled;
    unsigned char unknown417[3];
    int cash;
    unsigned int unknown424;
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
