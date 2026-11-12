#ifndef WCH_CHARACTERS_TRANSFORMATION_H
#define WCH_CHARACTERS_TRANSFORMATION_H
#include "../world/LevelObject.h"
namespace Structs { struct Marker; }
// Observed LevelObject base and 84-byte allocation extent.
class Transformation : public LevelObject {
public:
    Transformation(int type);
    // Retail vtable overrides; their implementations remain external here.
    virtual irr::scene::ISceneNode* grabSceneNode(int id, void*** parameters);
    virtual void dropSceneNode();
    virtual ~Transformation();
    virtual unsigned short GetMatID() const;
    virtual unsigned short GetTriID() const;
    virtual irr::core::vector3d<float> GetPosition() const;
    virtual const irr::core::quaternion& GetRotation() const;
    virtual irr::core::vector3d<float> GetRight() const;
    virtual irr::core::vector3d<float> GetFront() const;
    virtual void SetPosition(const irr::core::vector3d<float>& value);
    virtual void SetRotation(const irr::core::vector3d<float>& value);
    virtual void SetRotation(const irr::core::quaternion& value);
    void Load(const Structs::Marker&, irr::collada::CColladaFactory*);
private:
    irr::core::vector3d<float> position;
    irr::core::quaternion rotation;
    unsigned short materialID;
    unsigned short triangleID;
};
#endif
