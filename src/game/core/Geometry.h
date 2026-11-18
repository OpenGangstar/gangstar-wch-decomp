// Copyright (C) 2002-2008 Nikolaus Gebhardt
// Altered excerpts of Irrlicht 1.4.2 line3d.h/aabbox3d.h/triangle3d.h/irrMath.h: partial value interfaces, point-box and triangle construction.
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
#ifndef WCH_CORE_GEOMETRY_H
#define WCH_CORE_GEOMETRY_H
#include "Vector3.h"
namespace irr { namespace core {
// Irrlicht irrMath.h reference-returning extrema preserve retail float selection.
template<class T> inline const T& min_(const T& a, const T& b) { return a < b ? a : b; }
template<class T> inline const T& max_(const T& a, const T& b) { return a < b ? b : a; }
// Irrlicht 1.4.2 irrMath.h clamp, returned by value.
template<class T> inline const T clamp(const T& value, const T& low, const T& high)
{ return min_(max_(value, low), high); }
template<class T> class aabbox3d {
public:
    aabbox3d(const vector3d<T>& init) : MinEdge(init), MaxEdge(init) {}
    vector3d<T> MinEdge, MaxEdge;
private:
    aabbox3d(); // The default constructor remains unrecovered.
};
template<class T> class line3d {
public:
    line3d(const vector3d<T>& start, const vector3d<T>& end) : start(start), end(end) {}
    vector3d<T> start, end;
};
template<class T> class triangle3d {
public:
    triangle3d() {}
    triangle3d(vector3d<T> a, vector3d<T> b, vector3d<T> c)
        : pointA(a), pointB(b), pointC(c) {}
    vector3d<T> pointA, pointB, pointC;
    bool getIntersectionWithLine(const vector3d<T>&, const vector3d<T>&,
        vector3d<T>&) const __attribute__((weak));
};
} }
#endif
