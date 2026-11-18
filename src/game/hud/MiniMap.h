#ifndef WCH_HUD_MINI_MAP_H
#define WCH_HUD_MINI_MAP_H

#include "../ui/VirtualButton.h"
#include "../core/Rect.h"
#include "../core/Vector3.h"

class LevelObject;
class AnimObject;

// Observed base and tracking calls. The remaining layout is unrecovered.
class MiniMap : public VirtualButton {
public:
    MiniMap(ASprite*, int, int, int, int);
    virtual ~MiniMap();
    virtual void update(double elapsed);
    virtual void draw2d() const;
    void registerForMapTracking(LevelObject* object, bool flag);
    void deregisterForMapTracking(LevelObject* object);
    void deregisterAllForMapTracking();
    void setFollowedObject(LevelObject* object) { followedObject = object; }

private:
    irr::core::position2d<int> _calculateXYOffset(const irr::core::vector3d<float>&, const irr::core::rect<int>&, bool, bool) const;
    struct TrackingLink {
        TrackingLink* next;
        TrackingLink* previous;
    };
    struct TrackingNode : TrackingLink {
        LevelObject* object;
        AnimObject* marker;
        bool flag;
    };

    TrackingLink trackedObjects;
    LevelObject* followedObject;
    int inset;
    float scale;
    int unknown80[4];
    float minimumSpeed, maximumSpeed;
    float minimumScale, maximumScale;
    // Observed constructor allocation is 116 bytes.
    int unknown112;
};

#endif
