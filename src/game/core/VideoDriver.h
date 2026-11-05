#ifndef WCH_CORE_VIDEO_DRIVER_H
#define WCH_CORE_VIDEO_DRIVER_H

#include "Matrix4.h"
#include "Color.h"
#include "Rect.h"

namespace irr { namespace scene {
enum E_PRIMITIVE_TYPE { EPT_TRIANGLES = 6 };
} }
namespace irr { namespace video {
// Observed fork vtable prefix. Do not instantiate as a complete engine object.
enum E_TRANSFORMATION_STATE { ETS_VIEW, ETS_WORLD, ETS_PROJECTION };
enum E_VERTEX_TYPE { EVT_STANDARD = 0 };
enum E_INDEX_TYPE { EIT_16BIT = 0 };
struct SMaterial;
class IDriverBinding;
class ITexture;
class IVideoDriver {
public:
    virtual void unknown0(); virtual void unknown1(); virtual void unknown2();
    virtual void unknown3(); virtual void unknown4(); virtual void unknown5();
    virtual void unknown6(); virtual void unknown7(); virtual void unknown8();
    virtual void unknown9(); virtual void unknown10(); virtual void unknown11();
    virtual void unknown12(); virtual void unknown13(); virtual void unknown14();
    virtual void setTransform(E_TRANSFORMATION_STATE state, const core::matrix4& transform);
    virtual void unknown16();
    virtual void setMaterial(const SMaterial&);
    virtual void unknown18(); virtual void unknown19(); virtual void unknown20();
    virtual ITexture* getTexture(const char* filename); virtual void unknown22(); virtual void unknown23();
    virtual void unknown24(); virtual void unknown25(); virtual void unknown26();
    virtual void unknown27(); virtual void unknown28(); virtual void unknown29();
    virtual void unknown30(); virtual void removeTexture(ITexture* texture); virtual void unknown32();
    virtual void unknown33(); virtual void unknown34(); virtual void unknown35();
    virtual void unknown36(); virtual void unknown37(); virtual void unknown38();
    virtual void unknown39(); virtual void unknown40(); virtual void unknown41();
    virtual void drawVertexPrimitiveList(const void* vertices, const void* indices,
        unsigned int firstVertex, unsigned int vertexCount, unsigned int primitiveCount,
        E_VERTEX_TYPE, scene::E_PRIMITIVE_TYPE, E_INDEX_TYPE, IDriverBinding**);
    virtual void unknown43(); virtual void unknown44(); virtual void unknown45();
    virtual void unknown46(); virtual void unknown47(); virtual void unknown48();
    virtual void unknown49();
    virtual void draw2DRectangle(SColor color, const core::rect<int>& position,
        const core::rect<int>* clip = 0);
    virtual void unknown51(); virtual void unknown52(); virtual void unknown53();
    virtual void unknown54(); virtual void unknown55(); virtual void unknown56();
    virtual void unknown57(); virtual void unknown58(); virtual void unknown59();
    virtual const core::dimension2d<unsigned int>& getScreenSize() const;
};
} }

#endif
