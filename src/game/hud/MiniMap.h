#ifndef WCH_HUD_MINI_MAP_H
#define WCH_HUD_MINI_MAP_H

#include "../ui/VirtualButton.h"

class LevelObject;
class AnimObject;

// Observed base and tracking calls. The remaining layout is unrecovered.
class MiniMap : public VirtualButton {
public:
    void registerForMapTracking(LevelObject* object, bool flag);
    void deregisterForMapTracking(LevelObject* object);
    void deregisterAllForMapTracking();

private:
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
};

#endif
