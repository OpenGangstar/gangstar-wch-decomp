// Pending Character::setAnimation(int, float, bool, bool, bool).
// Reproduction: insert this definition into Character.cpp before setNextAnimation
// and include Weapon.h and ScriptManager.h. Recover these Character fields:
//   int animationStartFrame and animationEndFrame at 128 and 132
//   float animationSpeed at 144
//   bool animationFlag149 and animationFlag150 at 149 and 150
// In ITimelineController, declare const int-returning methods getClipStart(int),
// getClipEnd(int), and getClipLength(int) in slots 8, 9, and 10.
// Add this symbol at 0x002f1d90 to CharacterStateSections.ld and the Character
// manifest, and bind ARM helpers __aeabi_fmul (0x001c4724) and __aeabi_fcmplt
// (0x001c479c). Add the four Thumb Weapon and ScriptManager callees.
// Run python tools/build.py ai-startup-character.
//
// The signed flag shift produces a 396-byte candidate. Its first difference
// is +0x2c, where GCC emits BPL plus a long B instead of BMI to the shared
// false return. The unshifted mask produces different register allocation.
bool Character::setAnimation(int id, float speed, bool loop, bool flag149, bool flag150)
{
    if (static_cast<int>(movementFlags << 20) < 0)
        return false;

    if (id == -1) {
        currentAnimation = -1;
        animationStartFrame = 0;
        animationEndFrame = 0;
        animationFrameCount = 0;
        animationSpeed = 0.0f;
        animationLoops = false;
        animationFlag149 = false;
        animationFlag150 = false;
        animationFrame = 0.0f;
        return false;
    }

    if (currentAnimation == id)
        return false;
    if (!animationLoops && animationFrame < static_cast<float>(animationFrameCount)
        && !canAnimationBeInterrupted(currentAnimation)
        && !ScriptManager::getInstance()->isInCinematic()) {
        if (!canAnimationBeInterrupted(id))
            setNextAnimation(id, static_cast<int>(speed), loop, flag149, flag150);
        return false;
    }

    if (currentAnimation == 67 && getWeapon()->getWeaponType() == 7)
        getWeapon()->reloadRocket();
    if (id == 164)
        movementFlags |= 0x80000000u;

    nextAnimation = -1;
    currentAnimation = id;
    animationStartFrame = s_timelineController->getClipStart(currentAnimation);
    animationEndFrame = s_timelineController->getClipEnd(currentAnimation);
    animationFrameCount = s_timelineController->getClipLength(currentAnimation);
    animationSpeed = static_cast<float>(animationSpeedMultiplier) * speed;
    animationLoops = loop;
    animationFlag149 = flag149;
    animationFlag150 = flag150;
    animationFrame = 0.0f;
    return true;
}
