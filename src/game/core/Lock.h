#ifndef WCH_CORE_LOCK_H
#define WCH_CORE_LOCK_H

class LevelObject;
class CustomBillboardSceneNode;
namespace irr { namespace scene { class ISceneNode; } }
// Observed call interface and target prefix, not a complete class layout.
class Lock {
public:
    Lock(const char* resource, irr::scene::ISceneNode* parent, bool enabled);
    static Lock* getInstance();
    static void clean();
    void render();
    void setTarget(LevelObject* object);
    unsigned int unknown0;
    LevelObject* target;
    CustomBillboardSceneNode* billboard;
private:
    static Lock* s_lock;
};

#endif
