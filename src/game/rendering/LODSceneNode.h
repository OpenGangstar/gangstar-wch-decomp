#ifndef WCH_LOD_SCENE_NODE_H
#define WCH_LOD_SCENE_NODE_H

#include "../core/Array.h"
#include "../core/SceneNode.h"

class LODSceneNode : public irr::scene::ISceneNode {
public:
    LODSceneNode(int id, const irr::core::vector3d<float>& position,
        const irr::core::quaternion& rotation, const irr::core::vector3d<float>& scale);
    virtual ~LODSceneNode();
    virtual void addAnimator(irr::scene::ISceneNodeAnimator* animator);
    virtual void removeAnimators();
    void addLOD(irr::scene::ISceneNode* node, float distance);
    virtual void OnAnimate(unsigned int time);
    virtual void render(void* context);
    virtual int getType() const;
    virtual void OnRegisterSceneNode();
    virtual const irr::core::aabbox3d<float>& getTransformedBoundingBox() const;
    const irr::core::aabbox3d<float>& GetMeshTransformedBoundingBox(const irr::scene::ISceneNode*) const;
    void computeLODLevel();
    void setLODNodesRotation(const irr::core::quaternion& rotation);
    void setLODNodesPosition(const irr::core::vector3d<float>& position);
    virtual const irr::core::aabbox3d<float>& getBoundingBox() const;
    const irr::core::aabbox3d<float>& GetMeshBoundingBox(const irr::scene::ISceneNode*) const;
    int getLODLevel() const;
    void ComputeLOD(unsigned int time);
    void setMaxDistance(int distance);

private:
    template<class T, void (irr::scene::ISceneNode::*SetTransform)(const T&)>
    inline __attribute__((always_inline)) void setLODNodesTransform(const T& transform)
    {
        for (int index = 0; static_cast<unsigned int>(index) < levels.used; ++index)
            (levels.data[index].sceneNode->*SetTransform)(transform);
    }

    struct SLODLevel {
        float distanceSquared;
        irr::scene::ISceneNode* sceneNode;
    };
    irr::core::array<SLODLevel> levels;
    irr::scene::ISceneNode* getLODNode(int level) { return levels[level].sceneNode; }
    void setLODVisible(int level, bool visible) { getLODNode(level)->setVisible(visible); }
    float maxDistanceSquared;
    float animationTime;
    int lodLevel;
};

#endif
