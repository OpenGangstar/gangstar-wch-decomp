#ifndef WCH_VEHICLES_VEHICLE_H
#define WCH_VEHICLES_VEHICLE_H
#include "../world/LevelObject.h"
namespace Structs { struct Car; }
class Character;
class Path;
// Primary base and 1012-byte allocation extent; secondary interfaces and fields
// remain opaque pending recovery of the constructor and vehicle methods.
class Vehicle : public LevelObject {
public:
    void explode();
    bool hasExplosionFlag() const { return explosionFlag != 0; }
    Vehicle(int type);
    void Load(const Structs::Car&);
    void initializeDriver();
    void UpdatePhysic(float);
    void stepPhysic();
    void step();
    void immobilize();
    void mobilize();
    void UpdateCarSounds();
    void repair();
    void setPathToFollow(const Path* path);
    const Path* getPathToFollow() const;
    int getCurrentWaypoint() const;
    void setCurrentWaypoint(int waypoint);
    bool isLoopingOnPathToFollow() const;
    void setSpeed();
    void loopPathToFollow(bool loop);
    void _shiftWeight(irr::core::vector3d<float>&, float);
    const char* getEnterAnim() const;
    const char* getExitAnim() const;
    const char* getCloseDoorAnim() const;
    void toggleInterior(bool visible);
    bool isLeftDoor(const irr::scene::ISceneNode* door) const;
    bool isDoorOpened(bool left) const;
    bool isDoorClosed(bool left) const;
    bool isDoorAnim(const char* name, bool left) const;
    void setDoorAnim(const char* name, bool left);
    void onDoorClosed();
    void openDoor(bool left);
    void openDoorFromInside(bool left);
    void enableSkinning(bool enabled);
    void enableBackfaceCulling(bool enabled);
    void _notifyTargeted(bool targeted, Character* source);
    void AddTurboSounds();
    void Init4CylTurboSounds();
    void InitSuperbikeSounds();
    void InitV12LamborghiniSounds();
    void setHasBeenStolen();
    bool getHasBeenStolen();
    int getUniqueId();
    // Observed driver pointer at 696; inline accessor claims no separate symbol.
    Character* getDriver() const { return driver; }
private:
    void openDoorWithClip(const char* clip, bool left);
    friend class Race;
    friend void doorTransitionCallback(irr::scene::ITimelineController*, void*);
    unsigned char unknown52[192];
    Character* targetingCharacter;
    unsigned char unknown248[36];
    const char* enterAnim;
    const char* exitAnim;
    const char* closeDoorAnim;
    unsigned char unknown296[4];
    const Path* pathToFollow;
    int currentWaypoint;
    unsigned char unknown308[4];
    float doorAnimationScale;
    irr::scene::ISceneNode* leftDoor;
    unsigned char unknown320[8];
    irr::scene::ISceneNode* interior;
    unsigned char unknown332[12];
    unsigned int flags344;
    unsigned char unknown348[73];
    unsigned char explosionFlag;
    unsigned char unknown422[2];
    int vehicleIndex;
    unsigned char unknown428[76];
    bool hasBeenStolen;
    unsigned char unknown505[191];
    Character* driver;
    unsigned char unknown700[60];
    irr::scene::ISceneNodeAnimator* leftDoorAnimator;
    irr::scene::ISceneNodeAnimator* rightDoorAnimator;
    unsigned char unknown768[8];
    float unknown776;
    unsigned char unknown780[124];
    int doorSoundSuppression;
    unsigned char unknown908[56];
    int doorAnimationClip;
    unsigned char unknown968[34];
    bool leftDoorClosed;
    bool rightDoorClosed;
    bool leftDoorTransition;
    bool rightDoorTransition;
    unsigned char unknown1006[6];
};
#endif
