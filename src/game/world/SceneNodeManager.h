#ifndef WCH_WORLD_SCENE_NODE_MANAGER_H
#define WCH_WORLD_SCENE_NODE_MANAGER_H

#include "../core/PointerVector.h"

class LevelObject;
namespace irr { namespace scene { class ISceneNode; } namespace collada { class CColladaFactory; } }

// Partial layout through the CRC table and update timer.
class SceneNodeManager {
public:
    static SceneNodeManager* getInstance();
    void setup();
    void tearDown();
    void update(int);
    void manage(int poolID, LevelObject* owner, int count);
    int findOrCreatePool(const char* name, int size, irr::collada::CColladaFactory* factory);
    irr::scene::ISceneNode* grab(int poolID, LevelObject* owner, int id, void*** parameters);
    bool drop(int poolID, const irr::scene::ISceneNode* node);
private:
    SceneNodeManager();
    ~SceneNodeManager();
    struct Node {
        explicit Node(irr::scene::ISceneNode* sceneNode);
        ~Node();
        void setupUnmanaged(int parameterCount);
        bool available;
        irr::scene::ISceneNode* sceneNode;
        void** parameters;
        int unknown12;
    };
    struct Pool;
    struct PoolIndexLink {
        PoolIndexLink() : color(false), parent(0), left(this), right(this) {}
        bool color;
        PoolIndexLink* parent;
        PoolIndexLink* left;
        PoolIndexLink* right;
    };
    struct PoolIndex {
        PoolIndex() : size(0), compareState(false) {}
        ~PoolIndex();
        void clear();
        PoolIndexLink header;
        unsigned int size;
        bool compareState;
    };
    PoolIndex poolIndex;
    std::vector<Pool*> pools;
    unsigned int crcTable[256];
    int updateTimeRemaining;
    int updateInterval;
};

#endif
