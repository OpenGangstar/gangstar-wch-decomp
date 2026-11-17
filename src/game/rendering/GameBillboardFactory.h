#ifndef WCH_RENDERING_GAME_BILLBOARD_FACTORY_H
#define WCH_RENDERING_GAME_BILLBOARD_FACTORY_H

#include "CustomBillboardSceneNode.h"

// The retail factory derives directly from the engine factory, not CGameFactory.
class CGameBillboardFactory : public irr::collada::CColladaFactory {
public:
    virtual ~CGameBillboardFactory() {}
    virtual void* createScene(const irr::collada::CColladaDatabase& database)
    {
        return new CustomBillboardSceneNode(database, 0);
    }
};

#endif
