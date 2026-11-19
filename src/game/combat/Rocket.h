#ifndef WCH_COMBAT_ROCKET_H
#define WCH_COMBAT_ROCKET_H

#include "../world/LevelObject.h"
#include "../core/Vector3.h"

namespace Structs { struct Rocket; }
namespace irr { namespace video { class IVideoDriver; } }
class b2Body;
class Weapon;
class Character;
typedef Character SavePositionInterface;

// Observed primary base and 120-byte allocation extent; unresolved fields
// retain their offsets. The owner uses the observed secondary-base view.
class Rocket : public LevelObject {
public:
    Rocket(int type);
    virtual ~Rocket();
    virtual void Update(int elapsed);
    void debug(irr::video::IVideoDriver* driver);
    void Load(const Structs::Rocket&);
    void launch(irr::core::vector3d<float> direction);
    void explode(bool drawEffect);
private:
    b2Body* body;
    Weapon* weapon;
    SavePositionInterface* owner;
    int unknown64;
    int unknown68;
    int unknown72;
    int unknown76;
    int unknown80;
    int unknown84;
    int unknown88;
    bool unknown92;
    bool launched;
    irr::core::vector3d<float> unknown96;
    irr::core::vector3d<float> unknown108;
};

#endif
