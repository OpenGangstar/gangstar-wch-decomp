// Copyright (C) 2002-2008 Nikolaus Gebhardt
// Altered Irrlicht 1.4.2 interfaces for the observed fork hierarchy.
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software
// in a product, an acknowledgement in the product documentation would be
// appreciated but is not required.
// 2. Altered source versions must be clearly marked as such, and must not be
// misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
#ifndef WCH_CORE_SCENE_NODE_H
#define WCH_CORE_SCENE_NODE_H

#include "Vector3.h"
#include "Matrix4.h"
#include "Quaternion.h"
#include "SceneAnimatorList.h"

// Observed fork hierarchy and opaque scene-node storage. Unused return types
// remain provisional; engine implementations stay native unless inlined here.
namespace irr {
namespace core { template<class T> class aabbox3d; }
namespace video {
struct SMaterial;
class IVideoDriver;
class ITexture;
// Numeric values are observed; enumerator names are reconstruction labels.
enum E_MATERIAL_TYPE { MaterialType13 = 13, MaterialType15 = 15 };
enum E_MATERIAL_FLAG { MaterialFlag2 = 2, MaterialFlag4 = 4, MaterialFlag16 = 16, MaterialFlag128 = 128, MaterialFlag256 = 256, MaterialFlag512 = 512, MaterialFlag1024 = 1024 };
}
class IReferenceCounted {
public:
    IReferenceCounted() : references(1), debugName(0) {}
    virtual ~IReferenceCounted() {}
    bool drop() const __attribute__((weak));
    virtual void onDelete();
    int references;
    const char* debugName;
};
namespace io {
class IAttributes; struct SAttributeReadWriteOptions;
class IAttributeExchangingObject : public virtual IReferenceCounted {
public:
    virtual void serializeAttributes(IAttributes*, SAttributeReadWriteOptions*) const;
    virtual void deserializeAttributes(IAttributes*, SAttributeReadWriteOptions*);
};
}
namespace core { template<class T> class irrAllocator; template<class T, class A> class string; }
namespace scene {
enum E_CULLING_TYPE { EAC_OFF = 0, EAC_BOX = 1, EAC_FRUSTUM_BOX = 2 };
enum E_OPTION_FLAG { SceneOption1 = 1 };
enum ESCENE_NODE_TYPE { ESNT_ANY = 0x5f796e61 };
enum E_SCENE_NODE_RENDER_PASS { RenderPass6 = 6 };
class ITimelineController;
class ISceneNodeAnimator;
class ITriangleSelector;
class ISceneNode;
// Read-only view of the observed scene child list.
struct SceneNodeList {
    struct Node { Node* next; Node* previous; ISceneNode* value; };
    Node* first;
    Node* last;
    unsigned int size;
    Node* begin() const { return first; }
    Node* end() const { return 0; }
};
enum ESCENE_NODE_ANIMATION_FLAG { AnimationFlag0 = 0 };
class ISceneNode : public virtual io::IAttributeExchangingObject {
public:
    ISceneNode(int, const core::vector3d<float>&, const core::quaternion&, const core::vector3d<float>&);
    virtual void serializeAttributes(io::IAttributes*, io::SAttributeReadWriteOptions*) const;
    virtual void deserializeAttributes(io::IAttributes*, io::SAttributeReadWriteOptions*);
    virtual ~ISceneNode();
    virtual void OnRegisterSceneNode();
    virtual void OnAnimate(unsigned int);
    virtual void OnUpdateTime(unsigned int);
    virtual void render(void*) = 0;
    virtual unsigned int getRenderVertexCount(void*);
    virtual const char* getName() const;
    virtual void setName(const char*);
    virtual void setName(const core::string<char,core::irrAllocator<char> >&);
    virtual const core::aabbox3d<float>& getBoundingBox() const = 0;
    virtual const core::aabbox3d<float>& getTransformedBoundingBox() const;
    virtual const core::matrix4& getAbsoluteTransformation() const;
    virtual void setAbsoluteTransformation(core::matrix4&);
    virtual core::matrix4 getRelativeTransformation() const;
    virtual void setRelativeTransformation(const core::matrix4&);
    virtual bool isVisible() const;
    virtual float getVisibility();
    virtual void setVisible(bool);
    virtual bool isAnimated(ESCENE_NODE_ANIMATION_FLAG) const;
    virtual void setIsAnimated(ESCENE_NODE_ANIMATION_FLAG,bool);
    virtual int getID() const;
    virtual void setID(int);
    virtual const char* getUID() const;
    virtual unsigned int getScopeID() const;
    virtual void addChild(ISceneNode*);
    virtual bool removeChild(ISceneNode*);
    virtual void removeAll();
    virtual void remove();
    virtual void addAnimator(ISceneNodeAnimator*);
    virtual void removeAnimator(ISceneNodeAnimator*);
    virtual void removeAnimators();
    virtual void addBindedAnimator(ISceneNodeAnimator*);
    virtual void removeBindedAnimator(ISceneNodeAnimator*);
    virtual void removeBindedAnimators();
    virtual video::SMaterial& getMaterial(unsigned int);
    virtual unsigned int getMaterialCount() const;
    virtual void notifyMaterialChanged();
    virtual const core::vector3d<float>& getScale() const;
    virtual void setScale(const core::vector3d<float>&);
    virtual const core::quaternion& getRotation() const;
    virtual void setRotation(const core::quaternion&);
    virtual const core::vector3d<float>& getPosition() const;
    virtual void setPosition(const core::vector3d<float>&);
    virtual core::vector3d<float> getAbsolutePosition() const;
    virtual void setDebugDataVisible(int);
    virtual void* getUserProperty() const;
    virtual const char* getUserPropertyStr() const;
    virtual ITriangleSelector* getTriangleSelector() const;
    virtual void setTriangleSelector(ITriangleSelector*);
    virtual void updateAbsolutePosition(bool);
    virtual int getType() const;
    virtual ISceneNode* clone();
    virtual void setGameData(void*);
    virtual void* getGameData() const;
    virtual void setCameraOffset(float);
    virtual float getCameraOffset() const;
    virtual void setRenderingLayer(int);
    virtual int getRenderingLayer() const;
    virtual void onMaterialChanged();
    virtual void resetTransform(bool);
    virtual void onDelete();
    virtual void notifyVisibilityChanged(bool);
    virtual void onChangedSceneManager();
    E_CULLING_TYPE getAutomaticCulling() const;
    void setAutomaticCulling(E_CULLING_TYPE);
    ISceneNode* getSceneNodeFromUID(const char*);
    const SceneAnimatorList& getAnimators() const;
    const SceneNodeList& getChildren() const;
    void SetOption(E_OPTION_FLAG option, bool enabled);
    void setMaterialType(video::E_MATERIAL_TYPE type);
    void setMaterialFlag(video::E_MATERIAL_FLAG flag, bool enabled);
    void setMaterialTexture(unsigned int layer, video::ITexture* texture);
    ISceneNode* getParent() const;
private:
    unsigned char unknown4[324];
};
class SViewFrustum {
public:
    bool intersects(const core::aabbox3d<float>& box) const __attribute__((weak));
};
class ICameraSceneNode : public ISceneNode {
public:
    virtual void unknown66(); virtual void unknown67(); virtual void unknown68();
    virtual void unknown69(); virtual void unknown70(); virtual void unknown71();
    virtual void unknown72(); virtual void unknown73(); virtual void unknown74();
    virtual void unknown75(); virtual void unknown76(); virtual void unknown77();
    virtual void unknown78(); virtual void unknown79(); virtual void unknown80();
    virtual void unknown81(); virtual void unknown82(); virtual void unknown83();
    virtual const SViewFrustum* getViewFrustum() const;
};
class ITimelineController : public virtual IReferenceCounted {
public:
    virtual void unknown0();
    virtual ~ITimelineController();
    virtual void jumpTo(int time);
    virtual void unknown4(); virtual void unknown5();
    virtual int getClipIndex(const char* name) const;
    virtual void unknown7(); virtual void unknown8(); virtual void unknown9();
    virtual void unknown10(); virtual void unknown11(); virtual void unknown12();
    virtual void unknown13(); virtual int getCurrentClipIndex() const; virtual void unknown15();
    virtual void setLoop(bool loop);
    virtual bool getLoop() const;
    virtual void setScale(float scale);
    unsigned int unknown4Data;
    void (*callback)(ITimelineController*, void*);
    void* callbackData;
    int startTime;
    int endTime;
};
class ISceneNodeAnimator {
public:
    virtual void unknown0(); virtual void unknown1(); virtual void unknown2();
    virtual void unknown3(); virtual void unknown4(); virtual void unknown5();
    virtual void unknown6(); virtual void unknown7(); virtual void unknown8();
    virtual void unknown9(); virtual void unknown10(); virtual void unknown11();
    virtual void setAnimationClip(int clip); virtual void unknown13(); virtual int getAnimationClipIndex(const char* name);
    virtual void unknown15(); virtual void unknown16();
    virtual ITimelineController* getTimelineCtrl();
};
class ISceneManager {
public:
    virtual void unknown0(); virtual void unknown1(); virtual void unknown2();
    virtual void unknown3(); virtual void unknown4(); virtual void unknown5();
    virtual void unknown6(); virtual video::IVideoDriver* getVideoDriver(); virtual void unknown8();
    virtual void unknown9(); virtual void unknown10(); virtual void unknown11();
    virtual void unknown12(); virtual void unknown13(); virtual void unknown14();
    virtual void unknown15(); virtual void unknown16(); virtual void unknown17();
    virtual void unknown18(); virtual void unknown19(); virtual void unknown20();
    virtual void unknown21(); virtual void unknown22(); virtual void unknown23();
    virtual void unknown24(); virtual void unknown25(); virtual void unknown26();
    virtual void unknown27(); virtual void unknown28();
    virtual ISceneNode* addEmptySceneNode(ISceneNode* parent, int id);
    virtual void unknown30(); virtual void unknown31(); virtual void unknown32();
    virtual void unknown33(); virtual void unknown34(); virtual void unknown35();
    virtual void unknown36();
    virtual ISceneNode* getRootSceneNode();
    virtual void unknown38(); virtual void unknown39(); virtual void unknown40();
    virtual void unknown41(); virtual void unknown42(); virtual ICameraSceneNode* getActiveCamera();
    virtual void unknown44(); virtual void unknown45(); virtual void unknown46();
    virtual unsigned int registerNodeForRendering(ISceneNode*, const video::SMaterial*, void*, E_SCENE_NODE_RENDER_PASS);
};
}
class ITimer {
public:
    virtual void unknown0(); virtual void unknown1();
    virtual unsigned int getRealTime() const;
};
namespace video { class IVideoDriver; }
class IrrlichtDevice {
public:
    virtual void unknown0(); virtual void unknown1(); virtual void unknown2();
    virtual void unknown3(); virtual void unknown4(); virtual void unknown5();
    virtual video::IVideoDriver* getVideoDriver(); virtual void unknown7(); virtual void unknown8();
    virtual scene::ISceneManager* getSceneManager();
    virtual void unknown10(); virtual void unknown11();
    virtual void unknown12(); virtual void unknown13();
    virtual ITimer* getTimer();
};
}

#endif
