#ifndef WCH_WORLD_SCENE_NODE_MANAGER_H
#define WCH_WORLD_SCENE_NODE_MANAGER_H

class LevelObject;
namespace irr { namespace scene { class ISceneNode; } namespace collada { class CColladaFactory; } }

// Partial layout through the CRC table and update timer.
class SceneNodeManager {
public:
    static SceneNodeManager* getInstance();
    void setup();
    void update(int);
    void manage(int poolID, LevelObject* owner, int count);
    int findOrCreatePool(const char* name, int size, irr::collada::CColladaFactory* factory);
    irr::scene::ISceneNode* grab(int poolID, LevelObject* owner, int id, void*** parameters);
    bool drop(int poolID, const irr::scene::ISceneNode* node);
private:
    SceneNodeManager();
    struct Node;
    struct Pool {
        Pool(const char* name, irr::collada::CColladaFactory* factory, int size);
        char* name;
        irr::collada::CColladaFactory* factory;
        int size;
        int unknown12;
        int unknown16;
        int unknown20;
        Node** nodesBegin;
        Node** nodesEnd;
        Node** nodesCapacity;
    };
    struct PoolIndexLink {
        PoolIndexLink() : color(false), parent(0), left(this), right(this) {}
        bool color;
        PoolIndexLink* parent;
        PoolIndexLink* left;
        PoolIndexLink* right;
    };
    PoolIndexLink poolIndex;
    unsigned int poolIndexSize;
    bool poolIndexCompareState;
    Pool** poolsBegin;
    Pool** poolsEnd;
    Pool** poolsCapacity;
    unsigned int crcTable[256];
    int updateTimeRemaining;
    int updateInterval;
};

#endif
