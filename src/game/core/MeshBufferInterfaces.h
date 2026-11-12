#ifndef WCH_CORE_MESH_BUFFER_INTERFACES_H
#define WCH_CORE_MESH_BUFFER_INTERFACES_H
#include "Geometry.h"
// Partial engine interfaces recovered from retail vtables; do not instantiate meshes.
// Component-array accessors are a Gameloft extension, not upstream Irrlicht 1.4.2.
// The observed 36-byte accessor has type, byte stride, data, scale and offset.
namespace irr { namespace video {
class S3DVertexComponentArrays {
public:
    template<template<class> class Vector, class T> struct SAccessorEx {
        int type;
        unsigned int stride;
        const unsigned char* data;
        Vector<float> scale, offset;
        const Vector<T>& operator[](unsigned int index) const {
            return *reinterpret_cast<const Vector<T>*>(data + index * stride);
        }
        void get(unsigned int index, Vector<float>& out) const {
            const Vector<T>& value = (*this)[index];
            out.X = value.X * scale.X + offset.X;
            out.Y = value.Y * scale.Y + offset.Y;
            out.Z = value.Z * scale.Z + offset.Z;
        }
    };
    int getPositionAccessor(SAccessorEx<core::vector3d, float>&) const;
    int getPositionAccessor(SAccessorEx<core::vector3d, short>&) const;
};
} namespace scene {
class IMeshBuffer {
public:
    virtual void unknown0(); virtual void unknown1(); virtual void unknown2();
    virtual void unknown3(); virtual void unknown4(); virtual void unknown5();
    virtual int getVertexType() const;
    virtual const void* getVertices() const;
    virtual void unknown8(); virtual void unknown9(); virtual void unknown10();
    virtual void unknown11(); virtual void unknown12();
    virtual const unsigned short* getIndices() const;
    virtual unsigned short* getIndices();
    virtual unsigned int getIndexCount() const;
    virtual void unknown16(); virtual void unknown17(); virtual void unknown18();
    virtual const core::vector3d<float>& getPosition(unsigned int) const;
    virtual core::vector3d<float>& getPosition(unsigned int);
};
class IMesh {
public:
    virtual unsigned int getMeshBufferCount() const;
    virtual IMeshBuffer* getMeshBuffer(unsigned int) const;
};
} }
#endif
