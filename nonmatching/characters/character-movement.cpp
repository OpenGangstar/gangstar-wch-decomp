// Unmatched Character walk/run candidate. Keep the retail assembly in the queue.
// To reproduce, append the code below to Character.cpp and add these private
// members in Character.h:
//   void turnToward(const irr::core::vector3d<float>& point);
//   int movementFlags; // Offset 236, inside the current unknown192 array.
// Place run at 0x002f3fa4 and walk at 0x002f400c in CharacterStateSections.ld.
// Add both to the ai-startup-character function list and bind the Thumb
// turnToward overload taking a const vector reference. Build ai-startup-character.
//
// First differences: run +0x2c and walk +0x18. Each has five differing bytes.
// GCC emits BIC with an immediate mask loaded into a register. Retail uses
// ASR followed by LSL. The mask, explicit shifts, and bitfield all emitted
// the same code under the configured GCC 4.2.1 flags.
namespace {
union MovementState {
    int word;
    struct {
        unsigned int mode : 8;
        int otherFlags : 24;
    } bits;
};

inline int setMovementMode(int word, unsigned int mode)
{
    MovementState state;
    state.word = word;
    state.bits.mode = mode;
    return state.word;
}
}

void Character::runToLocation(const irr::core::vector3d<float>& point)
{
    if (isDead() || isDown())
        return;
    movementFlags = setMovementMode(movementFlags, 4);
    turnToward(point);
    setAnimation(getSpecificAnimation(188), 1.0f, true, true, false);
}

void Character::walkToLocation(const irr::core::vector3d<float>& point)
{
    if (isDead())
        return;
    movementFlags = setMovementMode(movementFlags, 2);
    turnToward(point);
    setAnimation(getSpecificAnimation(202), 1.0f, true, true, false);
}
