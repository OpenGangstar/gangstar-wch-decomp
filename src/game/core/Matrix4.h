// Copyright (C) 2002-2008 Nikolaus Gebhardt
// Altered excerpt of Irrlicht 1.4.2 matrix4.h: identity construction, vector transform and partial inverse interface.
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
#ifndef WCH_CORE_MATRIX4_H
#define WCH_CORE_MATRIX4_H
#include "NativeStdio.h"
#include "Vector3.h"
namespace irr { namespace core {
template<class T> class aabbox3d;
template<class T> class CMatrix4 {
public:
    enum eConstructor {
        EM4CONST_NOTHING, EM4CONST_COPY, EM4CONST_IDENTITY,
        EM4CONST_TRANSPOSED, EM4CONST_INVERSE, EM4CONST_INVERSE_TRANSPOSED
    };
    CMatrix4(eConstructor constructor = EM4CONST_IDENTITY);
    inline CMatrix4<T>& makeIdentity();
    const T& operator[](unsigned int index) const { return M[index]; }
    void transformBoxEx(aabbox3d<T>& box) const __attribute__((weak));
    bool getInverse(CMatrix4<T>& out) const __attribute__((weak));
    void transformVect(vector3d<float>& vect) const {
        float vector[3];
        vector[0] = vect.X*M[0] + vect.Y*M[4] + vect.Z*M[8] + M[12];
        vector[1] = vect.X*M[1] + vect.Y*M[5] + vect.Z*M[9] + M[13];
        vector[2] = vect.X*M[2] + vect.Y*M[6] + vect.Z*M[10] + M[14];
        vect.X = vector[0]; vect.Y = vector[1]; vect.Z = vector[2];
    }
private:
    T M[16];
    mutable bool definitelyIdentityMatrix;
};
template<class T>
inline CMatrix4<T>::CMatrix4(eConstructor constructor) : definitelyIdentityMatrix(false)
{
    switch (constructor) {
    case EM4CONST_NOTHING: case EM4CONST_COPY: break;
    case EM4CONST_IDENTITY: case EM4CONST_INVERSE: default:
        makeIdentity(); break;
    }
}
template<class T>
inline CMatrix4<T>& CMatrix4<T>::makeIdentity()
{
    memset(M, 0, 16 * sizeof(T));
    M[0] = M[5] = M[10] = M[15] = (T)1;
    definitelyIdentityMatrix = true;
    return *this;
}
typedef CMatrix4<float> matrix4;
} }
#endif

