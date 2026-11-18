#ifndef WCH_META_ITEM_H
#define WCH_META_ITEM_H
#include "../characters/Transformation.h"
namespace Structs { struct Item; }
namespace irr { namespace video { class IVideoDriver; } }
namespace irr { namespace core {
template<class T> class irrAllocator;
template<class T, class Alloc> class array;
} }
class CustomBillboardSceneNode;
class Item : public Transformation {
    friend class MiniMap;
public:
    Item(int type);
    virtual irr::scene::ISceneNode* grabSceneNode(int id, void*** parameters);
    virtual void dropSceneNode();
    virtual void setupSceneNode(int id, irr::scene::ISceneNode* node, int count, void** parameters);
    virtual ~Item();
    virtual void WarmUp();
    virtual void SetPosition(const irr::core::vector3d<float>& value);
    virtual void Update(int elapsed);
    void Load(const Structs::Item&);
    static void resetAchievementCounters();
    static void removeAllPlacedItems();
    static void place(int type, irr::core::vector3d<float> position);
    static void drop(int type, irr::core::vector3d<float> position, int amount);
    void debug(irr::video::IVideoDriver* driver);
    void unlock();
    void hide();
    void show();
    void lock();
    void animate(bool start, bool loop, bool flag);
    void addAmmo(int type, int amount);
    void addWeapon(int type);
    int isUsable();
    void pickup();
    void add();
    void playPickupSound();
    bool unlocked() const;
    int getId() const;
    static int s_numHealthCrate;
    static int s_numArmorVest;
    static irr::core::array<Item*, irr::core::irrAllocator<Item*> > s_placedItems;
private:
    // Observed 112-byte extent; the two unlock fields use unsigned comparison.
    CustomBillboardSceneNode* billboard;
    int itemType;
    unsigned int unknown92;
    unsigned int unknown96;
    irr::scene::ISceneNode* attachedNode;
    short unknown104;
    short billboardPool;
    int id;
};
#endif
