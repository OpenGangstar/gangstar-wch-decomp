// Pending Character::getSpecificAnimation(int).
// Insert this definition in Character.cpp before goToIdle and include Weapon.h.
// In Character.h, split unknown192 at offset 212 for int animationStance.
// Place the function at 0x002f1a30 in CharacterStateSections.ld, add it to the
// ai-startup-character manifest, and replace the external getSpecificAnimation
// binding with Thumb bindings for Weapon::getWeaponType and Weapon::isTwoHanded.
// Run python tools/build.py ai-startup-character.
//
// Candidate length: 714 bytes. Return block order changes their branch targets.
// First difference, +0x74: retail 0b e1, candidate 01 e1.
int Character::getSpecificAnimation(int id)
{
    switch (id) {
    case 0:
        switch (animationStance) {
        case 0:
            if (getWeapon()->getWeaponType() == 7)
                return 208;
            if (getWeapon()->isTwoHanded())
                return 205;
        case 1:
        case 2:
            break;
        default:
            return -1;
        }
        return 0;
    case 165:
        switch (animationStance) {
        case 0:
            if (getWeapon()->getWeaponType() == 7)
                return 169;
            if (getWeapon()->isTwoHanded())
                return 166;
            return 165;
        case 1:
            return 36;
        case 2:
            return 42;
        }
        break;
    case 179:
        switch (animationStance) {
        case 0:
            if (getWeapon()->getWeaponType() == 7)
                return 170;
            if (getWeapon()->isTwoHanded())
                return 167;
        case 1:
        case 2:
            break;
        default:
            return -1;
        }
        return 179;
    case 180:
        switch (animationStance) {
        case 0:
            if (getWeapon()->getWeaponType() == 7)
                return 171;
            if (getWeapon()->isTwoHanded())
                return 168;
            return 180;
        case 1:
            return 38;
        case 2:
            return 43;
        }
        break;
    case 188:
        switch (animationStance) {
        case 0:
            if (getWeapon()->getWeaponType() == 7)
                return 192;
            if (getWeapon()->isTwoHanded())
                return 189;
            return 188;
        case 1:
            return 39;
        case 2:
            return 44;
        }
        break;
    case 198:
        switch (animationStance) {
        case 0:
            if (getWeapon()->getWeaponType() == 7)
                return 193;
            if (getWeapon()->isTwoHanded())
                return 190;
        case 1:
        case 2:
            break;
        default:
            return -1;
        }
        return 198;
    case 200:
        switch (animationStance) {
        case 0:
            if (getWeapon()->getWeaponType() == 7)
                return 194;
            if (getWeapon()->isTwoHanded())
                return 191;
        case 1:
        case 2:
            break;
        default:
            return -1;
        }
        return 200;
    case 202:
        switch (animationStance) {
        case 0:
            if (getWeapon()->getWeaponType() == 7)
                return 206;
            if (getWeapon()->isTwoHanded())
                return 203;
            return 202;
        case 1:
            return 40;
        case 2:
            return 48;
        }
        break;
    case 212:
        switch (animationStance) {
        case 0:
            if (getWeapon()->getWeaponType() == 7)
                return 207;
            if (getWeapon()->isTwoHanded())
                return 204;
            return 212;
        case 1:
            return 41;
        case 2:
            return 49;
        }
        break;
    }
    return -1;
}
