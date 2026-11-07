// Copyright (C) 2002-2008 Nikolaus Gebhardt
// Altered excerpt of Irrlicht 1.4.2 vector3d.h: partial three-component value interface only.
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
#ifndef WCH_CORE_VECTOR3_H
#define WCH_CORE_VECTOR3_H

extern "C" double sqrt(double);

namespace irr { namespace core {
// Observed three-component value type and nontrivial copy ABI.
template<class T> class vector3d {
public:
    T X, Y, Z;
    vector3d() : X(0), Y(0), Z(0) {}
    vector3d(T x, T y, T z) : X(x), Y(y), Z(z) {}
    vector3d<T> operator*(T scalar) const { return vector3d<T>(X * scalar, Y * scalar, Z * scalar); }
    vector3d<T> operator+(const vector3d<T>& other) const { return vector3d<T>(X + other.X, Y + other.Y, Z + other.Z); }
    vector3d<T> operator-(const vector3d<T>& other) const { return vector3d<T>(X - other.X, Y - other.Y, Z - other.Z); }
    vector3d<T> operator-() const { return vector3d<T>(-X, -Y, -Z); }
    vector3d(const vector3d& other) : X(other.X), Y(other.Y), Z(other.Z) {}
    vector3d<T>& operator=(const vector3d<T>& other) { X=other.X; Y=other.Y; Z=other.Z; return *this; }
    vector3d<T>& operator*=(T scalar) { X*=scalar; Y*=scalar; Z*=scalar; return *this; }
    vector3d<T>& normalize() __attribute__((weak));
    T getLength() const { return (T) sqrt((double)(X*X + Y*Y + Z*Z)); }
    T getLengthSQ() const { return X*X + Y*Y + Z*Z; }
    T dotProduct(const vector3d<T>& other) const
    {
        return X * other.X + Y * other.Y + Z * other.Z;
    }
    T getDistanceFromSQ(const vector3d<T>& other) const {
        return vector3d<T>(X - other.X, Y - other.Y, Z - other.Z).getLengthSQ();
    }
    T getDistanceFrom(const vector3d<T>& other) const {
        return vector3d<T>(X - other.X, Y - other.Y, Z - other.Z).getLength();
    }
};
template<class T> T lerp(const T&, const T&, float) __attribute__((weak));
} }

#endif
