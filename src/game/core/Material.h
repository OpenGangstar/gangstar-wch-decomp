// Copyright (C) 2002-2008 Nikolaus Gebhardt
// Altered Irrlicht 1.4.2 material/texture interfaces for the observed fork.
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
#ifndef WCH_CORE_MATERIAL_H
#define WCH_CORE_MATERIAL_H

#include "SceneNode.h"
#include "Color.h"

// Observed 8-byte layer ownership and 92-byte material extent. Do not assume
// all material field names or the texture allocation extent are recovered.
// The inline material constructor is a semantic SDK reconstruction; its weak
// out-of-line copy is not byte-matched or credited as game code.
void operator delete(void*) throw();
namespace irr {
namespace core { template<class T> class dimension2d; }
namespace video {
class ITexture : public virtual IReferenceCounted {
public:
    virtual void* lock(bool readOnly) = 0;
    virtual void unlock() = 0;
    virtual const core::dimension2d<int>& getOriginalSize() const = 0;
    virtual const core::dimension2d<int>& getSize() const = 0;
};
struct SMaterialLayer {
    SMaterialLayer() : matrix(0) {}
    ITexture* texture;
    core::matrix4* matrix;
    ~SMaterialLayer() {
        if (matrix) ::operator delete(matrix);
        if (texture) texture->drop();
    }
};
enum E_MATERIAL_FLAG { MaterialFlag2 = 2, MaterialFlag4 = 4, MaterialFlag16 = 16, MaterialFlag256 = 256, MaterialFlag512 = 512, MaterialFlag1024 = 1024 };
struct SMaterial {
    SMaterial() : unknown0(1), type(0), flags40(0x387), mode44(3),
        color48(255,255,255,255), color52(0,0,0,0), color56(255,255,255,255),
        unknown60(0), unknown64(1), unknown68(0), unknown72(0), unknown76(0), unknown80(0),
        color84(255,255,255,255), dirtyFlags(0xfc) {
        layers[0].texture=0; layers[1].texture=0; layers[2].texture=0; layers[3].texture=0;
    }
    // Native leaves this in r0; fluent return type inferred, callers ignore it.
    SMaterial& setFlag(E_MATERIAL_FLAG, bool) __attribute__((weak));
    void setType(int value) { if(type!=value) {dirtyFlags|=1;type=value;} }
    unsigned int unknown0;
    int type;
    SMaterialLayer layers[4];
    unsigned int flags40,mode44;
    SColor color48,color52,color56;
    float unknown60,unknown64,unknown68,unknown72,unknown76,unknown80;
    SColor color84;
    unsigned int dirtyFlags;
};

} }

#endif
