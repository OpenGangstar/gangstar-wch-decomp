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
enum E_ORTHO_ORIENTATION { OrthoOrientation0, OrthoOrientation1, OrthoOrientation2, OrthoOrientation3 };
enum E_VERTEX_TYPE { EVT_STANDARD = 0 };
enum E_INDEX_TYPE { EIT_16BIT = 0 };
struct SMaterial;
class IDriverBinding;
class IMaterialRenderer;
class ITexture;
class CTextureManager {
public:
    virtual void unknown0();
    virtual void unknown1();
    virtual void unknown2();
    virtual void unknown3();
    virtual void unknown4();
    virtual unsigned int getTextureCount() const;
    void reloadTexture(int index);
    void reloadAllTextures();
    void unloadAllTextures();
};
typedef CTextureManager ITextureManager;
class IVideoDriver {
public:
    virtual bool beginScene();
    virtual bool endScene();
    virtual void swapBuffers(int mode);
    virtual void clearBuffers(int mask);
    virtual void setClearColor(const SColor& color);
    virtual void unknown5(); virtual void unknown6(); virtual void unknown7();
    virtual void unknown8(); virtual void unknown9();
    virtual void beginScene2D(); virtual void endScene2D();
    virtual void unknown12(); virtual void unknown13(); virtual void unknown14();
    virtual void setTransform(E_TRANSFORMATION_STATE state, const core::matrix4& transform);
    virtual void unknown16();
    virtual void setMaterial(const SMaterial&);
    virtual void set2DMaterial(SMaterial&); virtual void unknown19(); virtual void unknown20();
    virtual ITexture* getTexture(const char* filename); virtual void unknown22(); virtual void unknown23();
    virtual void unknown24(); virtual void unknown25(); virtual void unknown26();
    virtual void unknown27(); virtual void unknown28(); virtual void unknown29();
    virtual void unknown30(); virtual void removeTexture(ITexture* texture); virtual void unknown32();
    virtual void unknown33(); virtual void unknown34(); virtual void unknown35();
    virtual void unknown36(); virtual void unknown37(); virtual void unknown38();
    virtual void unknown39(); virtual void unknown40(); virtual const core::rect<int>& getViewPort() const;
    virtual void drawVertexPrimitiveList(const void* vertices, const void* indices,
        unsigned int firstVertex, unsigned int vertexCount, unsigned int primitiveCount,
        E_VERTEX_TYPE, scene::E_PRIMITIVE_TYPE, E_INDEX_TYPE, IDriverBinding**);
    virtual void draw3DLine(const core::vector3d<float>& start,
        const core::vector3d<float>& end, SColor color);
    virtual void unknown44(); virtual void unknown45();
    virtual void unknown46(); virtual void draw2DImage(const ITexture*, const core::position2d<int>&, const core::rect<int>&, const core::rect<int>*, SColor, bool); virtual void unknown48();
    virtual void unknown49();
    virtual void draw2DRectangle(SColor color, const core::rect<int>& position,
        const core::rect<int>* clip = 0);
    virtual void unknown51(); virtual void unknown52(); virtual void unknown53();
    virtual void unknown54(); virtual void unknown55(); virtual void unknown56();
    virtual void unknown57();
    virtual void setFog(SColor, bool, float, float, float, bool, bool);
    virtual void unknown59();
    virtual const core::dimension2d<unsigned int>& getScreenSize() const;
    virtual void unknown61();
    virtual void unknown62();
    virtual void unknown63();
    virtual void unknown64();
    virtual void unknown65();
    virtual void unknown66();
    virtual void unknown67();
    virtual void unknown68();
    virtual void unknown69();
    virtual void unknown70();
    virtual void unknown71();
    virtual void unknown72();
    virtual void unknown73();
    virtual void unknown74();
    virtual void unknown75();
    virtual void unknown76();
    virtual void unknown77();
    virtual void unknown78();
    virtual void unknown79();
    virtual void unknown80();
    virtual void unknown81();
    virtual void unknown82();
    virtual void unknown83();
    virtual int addMaterialRenderer(IMaterialRenderer*, const char*);
    virtual void unknown85();
    virtual void unknown86();
    virtual void unknown87();
    virtual void unknown88();
    virtual void unknown89();
    virtual void unknown90();
    virtual void unknown91();
    virtual void unknown92();
    virtual void unknown93();
    virtual void unknown94();
    virtual void unknown95();
    virtual void unknown96();
    virtual void unknown97();
    virtual void unknown98();
    virtual void unknown99();
    virtual void unknown100();
    virtual void unknown101();
    virtual void unknown102();
    virtual void setOrthoOrientation(E_ORTHO_ORIENTATION orientation);
    virtual void unknown104();
    virtual void setOrientation3D(E_ORTHO_ORIENTATION orientation);
    virtual void unknown106();
    virtual void unknown107();
    virtual void unknown108();
    virtual void unknown109();
    virtual void unknown110();
    virtual void unknown111();
    virtual void unknown112();
    virtual void unknown113();
    virtual void unknown114();
    virtual void unknown115();
    virtual void unknown116();
    virtual void setOption(unsigned int, bool);
    virtual void flush();
    virtual void unknown119();
    virtual void unknown120();
    virtual void unknown121();
    virtual void unknown122();
    virtual void unknown123();
    virtual void unknown124();
    virtual ITextureManager* getTextureManager();
};
} }

#endif
