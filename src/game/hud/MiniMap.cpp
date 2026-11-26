/*
 * MiniMap
 *
 * Original file: MiniMap.cpp
 * Area:          hud
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of MiniMap.cpp here, in the order they appear in the library.
 */

#include "MiniMap.h"
#include "../core/NativeStdio.h"
#include "TargetMarkerSingleton.h"
#include "../world/MapSingleton.h"
#include "../missions/WantedLevelManagerSingleton.h"
#include "../characters/AnimObject.h"
#include "../world/LevelObject.h"

// Imported STLport list operation for the retail TrackableObject specialization.
extern "C" void clearTrackedObjects(void*)
    __asm__("_ZN9stlp_priv10_List_baseIN7MiniMap15TrackableObjectESaIS2_EE5clearEv")
    __attribute__((weak));

void MiniMap::deregisterAllForMapTracking()
{
    TrackingLink* const end = &trackedObjects;
    TrackingLink* link = trackedObjects.next;
    if (end != link) {
        do {
            delete static_cast<TrackingNode*>(link)->marker;
            link = link->next;
        } while (end != link);
    }
    clearTrackedObjects(&trackedObjects);
}

// Imported STLport allocator for the retail tracking node specialization.
extern "C" void* allocateTrackingNode(void*, unsigned int, const void*)
    __asm__("_ZNSaIN9stlp_priv10_List_nodeIN7MiniMap15TrackableObjectEEEE8allocateEjPKv")
    __attribute__((weak));

void MiniMap::registerForMapTracking(LevelObject* object, bool flag)
{
    if (object->unknown44 == -1)
        return;

    TrackingLink* const end = &trackedObjects;
    for (TrackingLink* link = trackedObjects.next; end != link; link = link->next) {
        if (__builtin_expect(static_cast<TrackingNode*>(link)->object == object, 0))
            return;
    }

    AnimObject* marker = new AnimObject;
    marker->sprite = sprite;
    marker->SetAnim(object->unknown44);

    TrackingNode* node = static_cast<TrackingNode*>(allocateTrackingNode(end, 1, 0));
    node->flag = flag;
    node->marker = marker;
    node->object = object;
    TrackingLink* previous = trackedObjects.previous;
    node->next = end;
    node->previous = previous;
    previous->next = node;
    trackedObjects.previous = node;
}

void MiniMap::deregisterForMapTracking(LevelObject* object)
{
    if (object->unknown44 == -1)
        return;

    for (TrackingLink* link = trackedObjects.next; link != &trackedObjects; link = link->next) {
        TrackingNode* node = static_cast<TrackingNode*>(link);
        if (__builtin_expect(node->object == object, 0)) {
            delete node->marker;
            TrackingLink* next = node->next;
            TrackingLink* previous = node->previous;
            previous->next = next;
            next->previous = previous;
            delete node;
            return;
        }
    }
}

MiniMap::~MiniMap()
{
    TrackingLink* link = trackedObjects.next;
    TrackingLink* const end = &trackedObjects;
    if (link != end) {
        do {
            delete static_cast<TrackingNode*>(link)->marker;
            link = link->next;
        } while (link != end);
    }
    clearTrackedObjects(link);
}

void MiniMap::update(double)
{
    if (!followedObject || !(flags & 1))
        return;

    const float speed = followedObject->GetSpeed();
    if (speed <= minimumSpeed)
        scale = minimumScale;
    else if (speed < maximumSpeed)
        scale = minimumScale + (maximumScale - minimumScale)
            * ((speed - minimumSpeed) / (maximumSpeed - minimumSpeed));
    else
        scale = maximumScale;

    TrackingLink* const end = &trackedObjects;
    for (TrackingLink* link = trackedObjects.next; link != end; link = link->next) {
        TrackingNode* node = static_cast<TrackingNode*>(link);
        if (node->flag)
            node->marker->UpdateFrame();
    }
}

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_5() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

static void __static_initialization_and_destruction_0(int initialize, int priority) __attribute__((used));
static void __static_initialization_and_destruction_0(int initialize, int priority)
{
    if (initialize == 1 && priority == 65535) {
        irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
        value.array = 0;
        value.allocated = 0;
        value.used = 0;
        value.reference = false;
        _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(&value, localStartupEmptyText);
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_5), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN7MiniMapC2EP7ASpriteiiii() __attribute__((used));
static void _GLOBAL__I__ZN7MiniMapC2EP7ASpriteiiii()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_5()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

MiniMap::MiniMap(ASprite* spriteValue, int frame, int markerFrame, int targetFrame, int value112)
    : VirtualButton(spriteValue, frame, static_cast<EvVButton::ButtonType::Type>(7), true),
      followedObject(0), inset(18), scale(1.0f), minimumSpeed(30.0f), maximumSpeed(100.0f),
      minimumScale(1.5f), maximumScale(2.5f), unknown112(value112)
{
    memset(unknown80, 0, sizeof unknown80);
    TargetMarker::getInstance()->init(spriteValue, markerFrame, targetFrame);
    float amount = static_cast<float>(inset);
    float left = touchRegion.coordinates[0];
    float top = touchRegion.coordinates[1];
    float right = touchRegion.coordinates[2];
    float bottom = touchRegion.coordinates[3];
    left = amount + left;
    touchRegion.coordinates[0] = left;
    top = amount + top;
    touchRegion.coordinates[1] = top;
    right -= amount;
    touchRegion.coordinates[2] = right;
    bottom -= amount;
    touchRegion.coordinates[3] = bottom;
}

// --- candidate: MiniMap::_calculateXYOffset ---
#include "../core/CameraManager.h"
#include "../core/ASprite.h"
extern "C" float acosf(float);
template<class T> inline const T& miniMax(const T& a,const T& b) { return a<b?b:a; }
template<class T> inline const T& miniMin(const T& a,const T& b) { return a<b?a:b; }
template<class T> inline const T miniClamp(const T& x,const T& low,const T& high) { return miniMin(miniMax(x,low),high); }
extern "C" float sqrtf(float);
// Irrlicht vector2d<float>::rotateBy, imported weak (see clearTrackedObjects in MiniMap.cpp).
extern "C" void rotateVector2d(irr::core::vector2d<float>*, double, const irr::core::vector2d<float>&)
    __asm__("_ZN3irr4core8vector2dIfE8rotateByEdRKS2_")
    __attribute__((weak));

irr::core::position2d<int> MiniMap::_calculateXYOffset(const irr::core::vector3d<float>& position, const irr::core::rect<int>& clip, bool north, bool special) const
{
    int width, height;
    const float ratio = Map::getInstance()->pixelsPerUnit/scale;
    irr::core::position2d<int> result(0,0);
    const SpriteFrame* spriteFrame=sprite->GetFrame(frame);
    const SpriteFrameModule* frameModule=sprite->GetFModule(spriteFrame->firstModule);
    const SpriteModule* module=sprite->GetModule(frameModule->module);
    width=module->width;
    height=module->height;
    irr::core::vector3d<float> direction = CameraManager::getInstance()->getLookAt();
    const irr::core::vector3d<float> cameraPosition = CameraManager::getInstance()->getPosition();
    direction.X -= cameraPosition.X;
    direction.Y -= cameraPosition.Y;
    direction.Z = 0;
    direction.normalize();
    float angle;
    if (!north) {
        const irr::core::vector3d<float> offset(position.X-followedObject->GetPosition().X,position.Y-followedObject->GetPosition().Y,0);
        const float length=offset.getLength();
        const bool zero=length==0;
        if (zero) {
        zeroLength:
            result.X=static_cast<int>(ratio*followedObject->GetPosition().X);
            result.Y=static_cast<int>(ratio*followedObject->GetPosition().Y);
            return result;
        }
        angle = acosf(miniClamp(offset.dotProduct(direction)/(direction.getLength()*offset.getLength()),-1.0f,1.0f));
        irr::core::vector3d<float> rotated=direction;
        rotated.rotateXYBy(90,irr::core::vector3d<float>(0,0,0));
        if (offset.dotProduct(rotated)>0) {
            angle=-angle;
            // No-code hint: repeats the zero-length test (false here); predicted 21%
            // (opcode positive) at profile time it raises the zero-length arm's
            // estimated frequency, then DOM removes it (retail block order).
            if (({ struct L { int k; } u = { !zero }; L t = u; t.k<=0; })) goto zeroLength;
        }
        const float distance=ratio*length;
        // One half-extent variable reused for both axes: its redefinition keeps the
        // width square as its own statement ahead of the height (retail order).
        float half=(clip.LowerRightCorner.X-clip.UpperLeftCorner.X)*0.5f;
        float radiusSq=half*half;
        half=(clip.LowerRightCorner.Y-clip.UpperLeftCorner.Y)*0.5f;
        half*=half;
        radiusSq+=half;
        const int radius=static_cast<int>(sqrtf(radiusSq));
        if (distance<radius) {
            irr::core::vector2d<float> point(0,distance);
            rotateVector2d(&point,(angle+3.14159265f)*(180.0f/3.14159265f),irr::core::vector2d<float>(0,0));
            result.X=width/2+static_cast<int>(point.X);
            result.Y=height/2+static_cast<int>(point.Y);
            if (result.X>inset && result.X<width-inset && result.Y>inset && result.Y<height-inset) {
                result.X+=frameModule->x;
                result.Y+=frameModule->y;
                return result;
            }
        }
        if (special) {
            result.X=-1;
            result.Y=-1;
            goto placed;
        }
    } else {
        angle = acosf(miniClamp(direction.dotProduct(position)/(direction.getLength()*position.getLength()),-1.0f,1.0f));
        if (direction.X>0) angle=-angle;
    }
    {
    const float PI=3.14159265f;
    const float HALF_PI=1.57079633f;
    const float QUARTER_PI=0.785398163f;
    const float THREE_QUARTER_PI=2.35619449f;
    // No-code hint: the second, integer-typed spelling of the same zero test is
    // predicted 29% (opcode nonequal) at profile time and removed by DOM afterwards;
    // it only raises the zero arm's estimated frequency (retail block order).
    if (angle==0 || ({ struct Z { unsigned k; } u = { angle==0 }; Z t = u; t.k==1u; })) {
        // No-code hint: PRED_CALL lowers the zero-angle arm (retail block order).
        __builtin_prefetch(frameModule);
        result.X=width/2;
        result.Y=inset;
    } else if (angle==QUARTER_PI) {
        result.X=width-inset;
        result.Y=inset;
    } else {
    // No-code hint: PRED_CALL lowers the not-quarter edge (retail block order).
    __builtin_prefetch(frameModule);
    if (angle==HALF_PI) {
        result.X=width-inset;
        result.Y=height/2;
    } else if (angle==THREE_QUARTER_PI) {
        result.X=width-inset;
        result.Y=height-inset;
    } else {
    // No-code hint: PRED_CALL lowers the not-three-quarter edge (retail block order).
    __builtin_prefetch(frameModule);
    if (angle==PI || angle==-PI) {
        result.X=width/2;
        result.Y=height-inset;
    } else if (angle==-THREE_QUARTER_PI) {
        result.X=inset;
        result.Y=height-inset;
    } else if (angle==-HALF_PI) {
        result.X=inset;
        result.Y=height/2;
    } else if (angle==-QUARTER_PI) {
        result.X=inset;
        result.Y=inset;
    } else if (angle>-QUARTER_PI && angle<QUARTER_PI) {
        result.X=static_cast<int>((width-inset*2)*((angle+QUARTER_PI)/HALF_PI)+inset);
        result.Y=inset;
    } else if (angle>QUARTER_PI && angle<THREE_QUARTER_PI) {
        result.X=width-inset;
        result.Y=static_cast<int>((height-inset*2)*((angle-QUARTER_PI)/HALF_PI)+inset);
    } else if (angle>THREE_QUARTER_PI || angle<-THREE_QUARTER_PI) {
        if (angle<0) {
            // Separate negation: keeps fold from rewriting -a-c as -c-a.
            angle=-angle;
            angle-=THREE_QUARTER_PI;
        }
        else angle=-(angle-PI-QUARTER_PI);
        result.X=static_cast<int>((width-inset*2)*(angle/HALF_PI)+inset);
        result.Y=height-inset;
    } else {
        result.X=inset;
        // Negation as its own statement keeps fold from rewriting -a-c as -c-a.
        angle=-angle;
        result.Y=static_cast<int>((height-inset*2)*((angle-QUARTER_PI)/HALF_PI)+inset);
    }
    }
    }
    }
placed:
    result.X+=frameModule->x;
    result.Y+=frameModule->y;
    return result;
}
