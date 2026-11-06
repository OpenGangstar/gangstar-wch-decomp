#ifndef WCH_CHARACTERS_PLAYER_TEST_H
#define WCH_CHARACTERS_PLAYER_TEST_H

class Vehicle;
class Weapon;
class LevelObject;
namespace irr { namespace scene { class ISceneNode; } }

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
    virtual void unknown9(); virtual void unknown10(); virtual void unknown11();
    virtual SaveVector3 position() const;
    virtual void unknown13(); virtual void unknown14(); virtual void unknown15();
    virtual void position(const SaveVector3& value);
    virtual void unknown17();
    virtual void unknown18();
    virtual int getMaxHealth() const;
    virtual int getHealth() const;
    virtual void unknown21();
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
    virtual void unknown35();
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
    virtual void unknown51(); virtual void unknown52(); virtual void unknown53();
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
    // Reconstructed inline armor access; these names claim no retail symbols.
    int getContextArmor() const { return contextValues[contextWord]; }
    void setContextArmor(int amount) { contextValues[contextWord] = amount; }
    void addContextArmor(int amount)
    {
        setContextArmor(getContextArmor() + amount);
        if (getContextArmor() > 200)
            setContextArmor(200);
    }
    using SavePositionInterface::getVehicle;
    using SavePositionInterface::getWeapon;
    enum eContext { Context0 = 0, Context1 = 1, AnyContext = -1 };
    static PlayerTest* GetPlayer();
    void addPhotoTarget(LevelObject* target);
    void clearPhotoTargets();
    // Inline access to the observed target at offset 264; no standalone symbol claimed.
    LevelObject* getTarget() const { return target; }
    int getAmbientSound() const;
    void setCash(int value);
    void subCash(int amount);
    void addCash(int amount, int maximum);
    void switchContext(eContext context, bool flag);
    void Respawn();
    void Update();
    void UpdateSceneNode();
    unsigned char unknown8[12];
    irr::scene::ISceneNode* sceneNode;
    unsigned char unknown24[196];
    int maximumHealth;
    int health;
    unsigned char unknown228[12];
    unsigned int flags240;
    unsigned char unknown244[20];
    LevelObject* target;
    unsigned char unknown268[115];
    bool flag383;
    unsigned char unknown384[36];
    int cash;
    unsigned int unknown424;
    // Item::add reads the complete word at 428; existing enum users retain
    // their observed access width. Both views occupy the same storage.
    union { eContext context; int contextWord; };
    unsigned char unknown432[76];
    int contextValues[2];
};


#endif
