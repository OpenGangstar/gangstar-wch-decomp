// Faithful pending parent supports actual compiler-generated ARM thunk only.
#include "../../src/game/rendering/CustomBillboardSceneNode.cpp"
#include "../../src/game/core/CameraManager.h"
#include "../../src/game/core/Matrix4.h"
#include "../../src/game/core/Quaternion.h"

void CustomBillboardSceneNode::OnAnimate(unsigned int time)
{
    if (!isVisible()) {
        unknown520 = time;
        return;
    }

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
    unknown520 = time;
}
