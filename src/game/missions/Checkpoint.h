#ifndef WCH_MISSIONS_CHECKPOINT_H
#define WCH_MISSIONS_CHECKPOINT_H
#include "../characters/Transformation.h"
namespace Structs { struct Checkpoint; }
class Checkpoint : public Transformation {
public:
    Checkpoint(int type);
    virtual ~Checkpoint();
    virtual void Update(int elapsed);
    virtual irr::scene::ISceneNode* grabSceneNode(int id, void*** parameters);
    virtual void SetPosition(const irr::core::vector3d<float>& value);
    virtual void enable();
    virtual void show();
    virtual void hide();
    void Load(const Structs::Checkpoint&);
    // Observed integer radius at 84, also used by Race's distance test.
    int getRadius() const { return radius; }
protected:
    int radius;
private:
    int unknown88;
    int unknown92;
    bool unknown96;
    unsigned char unknown97[3];
};
#endif
