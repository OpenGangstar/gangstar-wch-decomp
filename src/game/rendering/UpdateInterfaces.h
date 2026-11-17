#ifndef WCH_RENDERING_UPDATE_INTERFACES_H
#define WCH_RENDERING_UPDATE_INTERFACES_H

#include "../world/LevelObject.h"
#include "../core/CameraManager.h"
#include "../core/Physics.h"
#include "../vehicles/Vehicle.h"
#include "../meta/Item.h"
#include "../world/SpawnPoint.h"
#include "../characters/PhysicAttributes.h"
#include "../world/SceneNodeManager.h"
#include "../persistence/SaveGameInterfaces.h"

// Partial call interfaces for the update loop. No complete layouts are asserted.
#include "../ai/StateMachine.h"

class TrailMgr { public: void Update(); };

struct UpdateApplicationView {
    unsigned char unknown0[96];
    float accumulatedTime;
    int stepCount;
};
struct UpdateObjectView {
    unsigned int unknown0;
    unsigned int flags;
    unsigned int unknown8;
    LevelObject* next;
    irr::scene::ISceneNode* node;
};
struct UpdatePlayerBody {
    unsigned char unknown0[64];
    float value64;
    float value68;
};
struct UpdatePlayerView {
    unsigned char unknown0[184];
    UpdatePlayerBody* body;
    unsigned char unknown188[184];
    int value372;
};

inline bool updatePlayerInVehicle(const PlayerTest* player) {
    return (player->flags240 & 1024) && static_cast<const SavePositionInterface*>(player)->getVehicle();
}

namespace UpdateMath {
template<class T> inline const T& min(const T& a, const T& b) { return a < b ? a : b; }
template<class T> inline const T& max(const T& a, const T& b) { return a < b ? b : a; }
template<class T> inline const T clamp(const T& value, const T& low, const T& high) {
    return min(max(value, low), high);
}
}

#endif
