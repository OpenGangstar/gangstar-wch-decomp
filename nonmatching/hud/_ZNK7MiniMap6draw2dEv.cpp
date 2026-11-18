// Unmatched MiniMap::draw2d reconstruction. Its assembly remains pending.
// Compiled here to verify the genuine compiler-generated secondary-base thunk.
#include "../../src/game/hud/MiniMap.h"
#include "../../src/game/hud/TargetMarker.h"
#include "../../src/game/world/Map.h"
#include "../../src/game/missions/WantedLevelManager.h"
#include "../../src/game/characters/AnimObject.h"
#include "../../src/game/world/LevelObject.h"
#include "../../src/game/core/CameraManager.h"
#include "../../src/game/core/Material.h"
#include "../../src/game/core/ASprite.h"
#include "../../src/game/meta/Item.h"
extern "C" float acosf(float);
template<class T> inline const T& miniMax(const T& a,const T& b) { return a<b?b:a; }
template<class T> inline const T& miniMin(const T& a,const T& b) { return a<b?a:b; }
template<class T> inline const T miniClamp(const T& x,const T& low,const T& high) { return miniMin(miniMax(x,low),high); }

void MiniMap::draw2d() const
{
    if (!followedObject || !(flags & 1)) return;
    const float x = followedObject->GetPosition().X;
    const float y = followedObject->GetPosition().Y;
    Map* bounds = Map::getInstance();
    const float minX = bounds->minX;
    const float minY = bounds->minY;
    const float maxX = bounds->maxX;
    const float maxY = bounds->maxY;
    const float mapWidth=maxX-minX;
    const float mapX = (x-minX)/mapWidth;
    const float mapY = (-y-minY)/(maxY-minY);
    const irr::core::dimension2d<int>& textureSize = Map::getInstance()->texture->getSize();
    const int pixelX = static_cast<int>(mapX*textureSize.Width);
    const float pixelY = mapY*textureSize.Height;
    irr::core::vector3d<float> direction = CameraManager::getInstance()->getLookAt();
    const irr::core::vector3d<float> cameraPosition = CameraManager::getInstance()->getPosition();
    direction.X -= cameraPosition.X;
    direction.Y -= cameraPosition.Y;
    direction.Z = 0;
    direction.normalize();
    const irr::core::vector3d<float> north(0,1,0);
    float angle = acosf(miniClamp(direction.dotProduct(north)/direction.getLength(),-1.0f,1.0f));
    if (!(direction.X>0)) angle=-angle;
    Map::getInstance()->rotation=angle;
    Map* offsetMap=Map::getInstance();
    offsetMap->offsetX=mapX;
    offsetMap->offsetY=mapY;
    Map::getInstance()->scale=scale;
    const SpriteFrameModule* frameModule=sprite->GetFModule(sprite->GetFrame(frame)->firstModule);
    const SpriteModule* module=sprite->GetModule(frameModule->module);
    const int left=pixelX-(module->width>>1);
    const int top=static_cast<int>(pixelY)-(module->height>>1);
    irr::core::rect<int> clip(left+inset,top+inset,0,0);
    clip.LowerRightCorner.X=module->width-inset+left;
    clip.LowerRightCorner.Y=module->height-inset+top;
    const int offsetX=frameModule->x+inset;
    const int offsetY=frameModule->y+inset;
    Map* offsetPixelMap=Map::getInstance();
    offsetPixelMap->offsetPixelX=offsetX;
    offsetPixelMap->offsetPixelY=offsetY;
    Map::getInstance()->clip=clip;
    Map::getInstance()->draw();
    sprite->PaintFrame(frame,0,0,0);
    const irr::core::position2d<int> arrow=_calculateXYOffset(irr::core::vector3d<float>(0,1,0),clip,true,false);
    sprite->PaintFrame(unknown112,arrow.X,arrow.Y,0);
    for (TrackingLink* link=trackedObjects.next;link!=&trackedObjects;link=link->next) {
        TrackingNode* node=static_cast<TrackingNode*>(link);
        LevelObject* object=node->object;
        const int type=LevelObject::s_type[object->objectType];
        if (type==13) continue;
        bool special=false;
        if (type==15 && static_cast<Item*>(object)->itemType==3) {
            if (WantedLevelManager::getInstance()->unknown8<=0 || !static_cast<Item*>(object)->unlocked()) continue;
            special=true;
        }
        const irr::core::position2d<int> point=_calculateXYOffset(object->GetPosition(),clip,false,special);
        if (point.X>0 && point.Y>0) {
            AnimObject* marker=node->marker;
            marker->SetPosition(point.X,point.Y,0);
            marker->Draw();
        }
    }
    irr::core::vector3d<float> front=followedObject->GetFront();
    front.normalize();
    float targetAngle=acosf(miniClamp(direction.dotProduct(front)/(direction.getLength()*front.getLength()),-1.0f,1.0f));
    irr::core::vector3d<float> rotated=direction;
    rotated.rotateXYBy(90,irr::core::vector3d<float>(0,0,0));
    if(rotated.dotProduct(front)>0) targetAngle=-targetAngle;
    const int width=module->width, height=module->height;
    const int moduleX=frameModule->x,moduleY=frameModule->y;
    TargetMarker::getInstance()->depth=targetAngle;
    TargetMarker::getInstance()->offsetX=width/2+moduleX;
    TargetMarker::getInstance()->offsetY=height/2+moduleY;
    TargetMarker::getInstance()->draw();
}

