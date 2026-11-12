// Copyright (C) 2002-2008 Nikolaus Gebhardt
// Altered excerpt of Irrlicht 1.4.2 quaternion.h: partial Euler-conversion interface only.
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software
// in a product, an acknowledgement in the product documentation would be
// appreciated but is not required.
// 2. Altered source versions must be clearly marked as such, and must not be
// misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
#ifndef WCH_CORE_QUATERNION_H
#define WCH_CORE_QUATERNION_H
#include "Vector3.h"

namespace irr { namespace core {
// Observed four-float value and external Euler conversion interface.
template<class T> class CMatrix4;

class quaternion {
public:
    float X, Y, Z, W;
    quaternion() : X(0),Y(0),Z(0),W(1) {}
    quaternion(float x, float y, float z) { set(x, y, z); }
    quaternion(const CMatrix4<float>& matrix) { *this = matrix; }
    quaternion(const vector3d<float>& v) { set(v.X, v.Y, v.Z); }
    quaternion& operator=(const quaternion& other)
    {
        X = other.X;
        Y = other.Y;
        Z = other.Z;
        W = other.W;
        return *this;
    }
    quaternion& operator=(const CMatrix4<float>& matrix) __attribute__((weak));
    void toEulerDegree(vector3d<float>& angles) const __attribute__((weak));
    quaternion& normalize() __attribute__((weak));
    quaternion& rotationFromTo(const vector3d<float>& from, const vector3d<float>& to) __attribute__((weak));
    quaternion& fromAngleAxis(float angle, const vector3d<float>& axis) __attribute__((weak));
    quaternion& set(float x, float y, float z) __attribute__((weak));
    quaternion operator*(const quaternion& other) const __attribute__((weak));
};
} }

#endif
