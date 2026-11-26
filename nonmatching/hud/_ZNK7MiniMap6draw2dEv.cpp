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
    irr::core::vector2d<float> position;
    irr::core::vector2d<float> mapPos;
    if (!followedObject || !(flags & 1)) return;
    position.X = followedObject->GetPosition().X;
    position.Y = followedObject->GetPosition().Y;
    Map* bounds = Map::getInstance();
    const float minX = bounds->minX;
    const float minY = bounds->minY;
    float mapX = bounds->maxX;
    float mapHeight = bounds->maxY;
    mapX-=minX;
    mapX = (position.X-minX)/mapX;
    mapHeight-=minY;
    mapPos.Y = (-position.Y-minY)/mapHeight;
    const float mapY = mapPos.Y;
    const irr::core::dimension2d<int>& textureSize = Map::getInstance()->texture->getSize();
    const float textureWidth = textureSize.Width;
    const float textureHeight = textureSize.Height;
    const int pixelX = static_cast<int>(mapX*textureWidth);
    const irr::core::position2d<int> pixel(pixelX,static_cast<int>(mapY*textureHeight));
    irr::core::vector3d<float> direction = CameraManager::getInstance()->getLookAt();
    const irr::core::vector3d<float> cameraPosition = CameraManager::getInstance()->getPosition();
    direction.X -= cameraPosition.X;
    direction.Y -= cameraPosition.Y;
    direction.Z = 0;
    direction.normalize();
    const irr::core::vector3d<float> north(0,1,0);
    float cosine = direction.dotProduct(north);
    cosine /= direction.getLength();
    float angle = acosf(miniClamp(static_cast<float>(cosine),-1.0f,1.0f));
    angle = direction.X>0 ? angle : -angle;
    Map::getInstance()->rotation=angle;
    Map* offsetMap=Map::getInstance();
    offsetMap->offset.X=mapX;
    offsetMap->offset.Y=mapY;
    Map::getInstance()->scale=scale;
    const SpriteFrame* spriteFrame=sprite->GetFrame(frame);
    const SpriteFrameModule* frameModule=sprite->GetFModule(spriteFrame->firstModule);
    const SpriteModule* module=sprite->GetModule(frameModule->module);
    const int left=pixel.X-(module->width>>1);
    const int top=pixel.Y-(module->height>>1);
    irr::core::rect<int> clip(0,0,0,0);
    const int border=inset;
    clip.UpperLeftCorner.X=left+border;
    clip.UpperLeftCorner.Y=top+border;
    clip.LowerRightCorner.X=module->width-border+left;
    clip.LowerRightCorner.Y=module->height-border+top;
    const int frameX=frameModule->x;
    const int frameY=frameModule->y;
    Map* offsetPixelMap=Map::getInstance();
    offsetPixelMap->offsetPixelX=frameX+border;
    offsetPixelMap->offsetPixelY=frameY+border;
    Map* clipMap=Map::getInstance();
    clipMap->clip.UpperLeftCorner.X=clip.UpperLeftCorner.X;
    clipMap->clip.UpperLeftCorner.Y=clip.UpperLeftCorner.Y;
    clipMap->clip.LowerRightCorner.X=clip.LowerRightCorner.X;
    clipMap->clip.LowerRightCorner.Y=clip.LowerRightCorner.Y;
    Map::getInstance()->draw();
    sprite->PaintFrame(frame,0,0,0);
    const irr::core::position2d<int> arrow=_calculateXYOffset(irr::core::vector3d<float>(0,1,0),clip,true,false);
    sprite->PaintFrame(unknown112,arrow.X,arrow.Y,0);
    TrackingLink* link=trackedObjects.next;
    const TrackingLink* const end=&trackedObjects;
    for (;link!=end;link=link->next) {
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
        const int pointX=point.X, pointY=point.Y;
        if (pointX>0 && pointY>0) {
            AnimObject* marker=node->marker;
            marker->SetPosition(pointX,pointY,0);
            marker->Draw();
        }
    }
    irr::core::vector3d<float> front=followedObject->GetFront();
    front.normalize();
    float targetCosine=direction.dotProduct(front);
    targetCosine/=direction.getLength()*front.getLength();
    float targetAngle=acosf(miniClamp(static_cast<float>(targetCosine),-1.0f,1.0f));
    irr::core::vector3d<float> rotated=direction;
    rotated.rotateXYBy(90,irr::core::vector3d<float>(0,0,0));
    if(rotated.dotProduct(front)>0) targetAngle=-targetAngle;
    const short moduleX=frameModule->x;
    const short width=module->width;
    const short moduleY=frameModule->y;
    const short height=module->height;
    TargetMarker::getInstance()->depth=targetAngle;
    TargetMarker* marker=TargetMarker::getInstance();
    marker->offsetX=width/2+moduleX;
    marker->offsetY=height/2+moduleY;
    TargetMarker::getInstance()->draw();
}

