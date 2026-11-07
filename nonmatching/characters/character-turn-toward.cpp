// Pending Character::turnToward(const irr::core::vector3d<float>&).
// Append this definition to Character.cpp. Add weak quaternion declarations
// for rotationFromTo, fromAngleAxis and normalize. Map the function to
// 0x002f3e98 in CharacterStateSections.ld and add it to the Character manifest.
// Remove its external Thumb binding. Bind __aeabi_fsub (0x001c4328),
// __aeabi_fmul (0x001c4724) and __aeabi_fcmple (0x001c43ac).
// Run python tools/build.py ai-startup-character.
//
// The candidate has the retail 268-byte size. GCC moves the X load before
// saving the quaternion address and the Y load before three quaternion
// stores. First mismatch is +0x48. The rest of the function matches.
void Character::turnToward(const irr::core::vector3d<float>& point)
{
    using irr::core::quaternion;
    using irr::core::vector3d;

    vector3d<float> relative = point - GetPosition();
    relative.Z = 0.0f;
    vector3d<float> direction(relative);
    direction.normalize();

    const float mirroredX = -direction.X;
    const float oppositeY = -direction.Y;
    const float xProjection = mirroredX * 0.0f;
    const float zProjection = direction.Z * 0.0f;
    const float dot = (xProjection + oppositeY) + zProjection;
    quaternion rotation;
    if (dot <= -1.0f)
        rotation.fromAngleAxis(3.14159265358979323846f, vector3d<float>(0.0f, 0.0f, 1.0f));
    else
        rotation.rotationFromTo(vector3d<float>(0.0f, -1.0f, 0.0f), vector3d<float>(-relative.X, relative.Y, 0.0f));
    rotation.normalize();
    sceneNode->setRotation(rotation);
}
