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
    unsigned char unknown0[36];
    unsigned int crcTable[256];
    int updateTimeRemaining;
    int updateInterval;
};

#endif
