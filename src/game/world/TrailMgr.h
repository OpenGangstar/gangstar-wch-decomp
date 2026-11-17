#ifndef WCH_WORLD_TRAIL_MGR_H
#define WCH_WORLD_TRAIL_MGR_H

class Trail;

class TrailMgr {
public:
    TrailMgr();
    virtual ~TrailMgr();
    void Update();
    void SetSegmentWidth(float width);
    void CleanUp();
    void FreeTrail(Trail* trail);
    Trail* AllocTrail();

private:
    Trail** trails;
    bool* allocated;
    int trailCount;
};

#endif
