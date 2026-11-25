/*
 * CustomBillboardSceneNode
 *
 * Original file: CustomBillboardSceneNode.cpp
 * Area:          rendering
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CustomBillboardSceneNode.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "CustomBillboardSceneNode.h"
#include "../core/VideoDriver.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_2() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_2()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_2), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN24CustomBillboardSceneNodeC2ERKN3irr7collada16CColladaDatabaseEPNS1_5SNodeE() __attribute__((used));
static void _GLOBAL__I__ZN24CustomBillboardSceneNodeC2ERKN3irr7collada16CColladaDatabaseEPNS1_5SNodeE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

void CustomBillboardSceneNode::setParent(irr::scene::ISceneNode* parent)
{
    if (parent) {
        if (billboardParent != parent) {
            billboardParent = parent;
            activateAnimation();
            setVisible(true);
        }
    } else {
        billboardParent = 0;
        setVisible(false);
    }
}

void CustomBillboardSceneNode::setLength(unsigned int length)
{
    const irr::scene::SceneAnimatorList& animators = getAnimators();
    if (animators.getSize()) {
        irr::scene::ITimelineController* controller = (*animators.begin())->getTimelineCtrl();
        if (controller) {
            controller->setLoop(animationLoops);
            animationLength = controller->getCurrentClipLength();
            return;
        }
    }
    animationLength = length;
}

void CustomBillboardSceneNode::setChildrenMaterialType(
    irr::scene::ISceneNode* node, irr::video::E_MATERIAL_TYPE type)
{
    node->setMaterialType(type);
    for (irr::scene::SceneNodeList::Node* child = node->getChildren().begin();
         child != node->getChildren().end(); child = child->next) {
        setChildrenMaterialType(child->value, type);
    }
}

void CustomBillboardSceneNode::setChildrenMaterialFlag(
    irr::scene::ISceneNode* node, irr::video::E_MATERIAL_FLAG flag, bool enabled)
{
    node->setMaterialFlag(flag, enabled);
    for (irr::scene::SceneNodeList::Node* child = node->getChildren().begin();
         child != node->getChildren().end(); child = child->next) {
        setChildrenMaterialFlag(child->value, flag, enabled);
    }
}

void CustomBillboardSceneNode::render()
{
}

CustomBillboardSceneNode::~CustomBillboardSceneNode()
{
}

CustomBillboardSceneNode::CustomBillboardSceneNode(
    const irr::collada::CColladaDatabase& database, irr::collada::SNode* node)
    : CRootSceneNode(database), animationActive(false), animationLoops(false),
      animationTime(0), animationLength(0), unknown520(0), parentOffsetZ(0)
{
    sourceNode = node;
    setParent(0);
}

void CustomBillboardSceneNode::debug(irr::video::IVideoDriver* driver)
{
    if (billboardParent) {
        irr::core::matrix4 transform(getAbsoluteTransformation(), irr::core::matrix4::EM4CONST_COPY);
        const irr::core::vector3d<float> x(transform.mutableElement(0), transform.mutableElement(1), transform.mutableElement(2));
        const irr::core::vector3d<float> y(transform.mutableElement(4), transform.mutableElement(5), transform.mutableElement(6));
        const irr::core::vector3d<float> z(transform.mutableElement(8), transform.mutableElement(9), transform.mutableElement(10));
        const irr::core::vector3d<float> origin = getAbsolutePosition();
        irr::core::vector3d<float> endpoint = x * 300.0f;
        endpoint = endpoint + origin;
        driver->draw3DLine(origin, endpoint, irr::video::SColor(255, 0, 0, 255));
        endpoint = y * 300.0f;
        endpoint = endpoint + origin;
        driver->draw3DLine(origin, endpoint, irr::video::SColor(255, 0, 255, 0));
        endpoint = z * 300.0f;
        endpoint = endpoint + origin;
        driver->draw3DLine(origin, endpoint, irr::video::SColor(255, 255, 0, 0));
    }
}

#include "../core/CameraManager.h"
#include "../core/Matrix4.h"
#include "../core/Quaternion.h"

void CustomBillboardSceneNode::OnAnimate(unsigned int time)
{
    if (isVisible()) {
    const irr::core::vector3d<float> billboardPosition = getAbsolutePosition();
    const irr::core::vector3d<float> cameraPosition =
        CameraManager::getInstance()->getCamera()->getAbsolutePosition();
    const irr::core::vector3d<float> target =
        CameraManager::getInstance()->getCamera()->getTarget();

    irr::core::vector3d<float> up(0.0f, 0.0f, 1.0f);
    irr::core::vector3d<float> forward(target.X - cameraPosition.X,
                                      target.Y - cameraPosition.Y, 0.0f);
    forward.normalize();
    irr::core::vector3d<float> right = forward.crossProduct(up);
    right.normalize();
    up = right.crossProduct(forward);
    up.normalize();

    irr::core::matrix4 rotation(irr::core::matrix4::EM4CONST_NOTHING);
    memset(&rotation.mutableElement(0), 0, sizeof(float) * 16);
    rotation.mutableElement(0) = right.X;
    rotation.mutableElement(1) = right.Y;
    rotation.mutableElement(2) = right.Z;
    rotation.mutableElement(3) = 0.0f;
    rotation.mutableElement(4) = forward.X;
    rotation.mutableElement(5) = forward.Y;
    rotation.mutableElement(6) = forward.Z;
    rotation.mutableElement(7) = 0.0f;
    rotation.mutableElement(8) = up.X;
    rotation.mutableElement(9) = up.Y;
    rotation.mutableElement(10) = up.Z;
    rotation.mutableElement(11) = 0.0f;
    rotation.mutableElement(12) = 0.0f;
    rotation.mutableElement(13) = 0.0f;
    rotation.mutableElement(14) = 0.0f;
    rotation.mutableElement(15) = 1.0f;
    setRotation(irr::core::quaternion(rotation));

    if (billboardParent) {
        irr::core::vector3d<float> position(billboardParent->getPosition());
        position.Z += parentOffsetZ;
        setPosition(position);
        if (animationActive) {
            CRootSceneNode::OnAnimate(animationTime);
            animationTime += time - unknown520;
            if (animationTime > animationLength) {
                animationTime = 0;
                if (!animationLoops)
                    animationActive = false;
            }
        } else {
            CRootSceneNode::OnAnimate(0);
        }
    } else {
        CRootSceneNode::OnAnimate(time);
    }
    }
    unknown520 = time;
}
