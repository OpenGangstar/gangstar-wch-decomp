// Copyright (C) 2002-2008 Nikolaus Gebhardt
// Subset of Irrlicht 1.4.2 geometry interfaces for the observed drawing ABI.
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
#ifndef WCH_CORE_RECT_H
#define WCH_CORE_RECT_H
namespace irr { namespace core {
template<class T> class dimension2d {
public:
    T Width, Height;
};
template<class T> class position2d {
public:
    position2d(T x, T y) : X(x), Y(y) {}
    position2d(const position2d& other) : X(other.X), Y(other.Y) {}
    T X, Y;
};
template<class T> class rect {
public:
    rect(T x, T y, T x2, T y2)
        : UpperLeftCorner(x, y), LowerRightCorner(x2, y2) {}
    position2d<T> UpperLeftCorner;
    position2d<T> LowerRightCorner;
};
} }
#endif
