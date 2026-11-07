#ifndef WCH_VEHICLES_VEHICLE_H
#define WCH_VEHICLES_VEHICLE_H
#include "../world/LevelObject.h"
namespace Structs { struct Car; }
class Character;
class Path;
namespace irr { namespace collada { class CSkinnedMeshSceneNode; } }
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
    void closeDoor(bool left);
    void startAnim(irr::scene::ISceneNodeAnimator* animator, bool loop);
    bool isCurrentAnim(const char* name);
    irr::scene::ITimelineController* getTimeline(irr::scene::ISceneNode* node);
    void playCurAnimFromStart();
    void setTransitionCallback(irr::scene::ISceneNode* node);
    void setAnim(const char* name, bool loop, float scale);
    bool isLowVehicle();
    int getSeatedAnimation();
    int getRightThrownAnimation();
    int getLeftThrownAnimation();
    int getRightThrowAnimation();
    int getLeftThrowAnimation();
    int getRightEjectAnimation();
    int getLeftEjectAnimation();
    int getRightExitAnimation();
    int getLeftExitAnimation();
    int getRightCloseDoorFromInsideAnimation();
    int getLeftCloseDoorFromInsideAnimation();
    int getRightEnterAnimation();
    int getLeftEnterAnimation();
    void enableSkinning(bool enabled);
    void enableBackfaceCulling(bool enabled);
    void showWheels();
    void hideWheels();
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
    void setWheelVisibility(bool visible);
    friend class Race;
    friend void doorTransitionCallback(irr::scene::ITimelineController*, void*);
    friend void VehicleCallBack(irr::scene::ITimelineController*, void*);
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
    unsigned char unknown320[4];
    irr::collada::CSkinnedMeshSceneNode* skinnedMesh;
    irr::scene::ISceneNode* interior;
    unsigned char unknown332[12];
    unsigned int flags344;
    unsigned char unknown348[73];
    unsigned char explosionFlag;
    unsigned char unknown422[2];
    int vehicleIndex;
    unsigned char unknown428[76];
    bool hasBeenStolen;
    unsigned char unknown505[171];
    irr::scene::ISceneNode* wheelNodes[4];
    irr::scene::ISceneNode* exterior;
    Character* driver;
    unsigned char unknown700[60];
    irr::scene::ISceneNodeAnimator* leftDoorAnimator;
    irr::scene::ISceneNodeAnimator* rightDoorAnimator;
    unsigned char unknown768[8];
    float unknown776;
    unsigned char unknown780[124];
    int doorSoundSuppression;
    unsigned char unknown908[56];
    int animationClipIndex;
    unsigned char unknown968[34];
    bool leftDoorClosed;
    bool rightDoorClosed;
    bool leftDoorTransition;
    bool rightDoorTransition;
    unsigned char unknown1006[6];
};
#endif
