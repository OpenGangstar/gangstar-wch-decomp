#ifndef WCH_CHARACTERS_CHARACTER_H
#define WCH_CHARACTERS_CHARACTER_H

#include "../world/LevelObject.h"

class Vehicle;

// Character's constructor calls LevelObject and initializes storage through
// offset 295. NPC's first additional field is at 296. Other fields and virtual
// overrides remain unrecovered; keep their storage opaque.
class Character : public LevelObject {
public:
    Character(int type);
    void initInVehicle(Vehicle* vehicle);
    void goToIdle();
    bool isPlayer() const;
    using LevelObject::sceneNode;
private:
    unsigned char unknown52[244];
};

#endif
