#ifndef WCH_WORLD_MAP_H
#define WCH_WORLD_MAP_H
#include "../core/Rect.h"
#include "../core/Geometry.h"

namespace irr {
namespace core { template<class T> class dimension2d; }
namespace video { class ITexture; }
}

class Map {
    friend class MiniMap;
    friend class PlayerTest;
public:
    static Map* getInstance() __attribute__((weak, used));

    void clean();
    void draw() const;
    void getScaledSize(irr::core::dimension2d<int>& size) const __attribute__((weak));

private:
    enum eMapType { DefaultMap = 1 };
    void setMap(eMapType type);
    Map();
    ~Map();

    // Retail singleton storage. Member types are still being recovered.
    irr::video::ITexture* texture;
    float rotation;
    float scale;
    irr::core::vector2d<float> offset;
    int offsetPixelX, offsetPixelY;
    irr::core::rect<int> clip;
    float minX, minY, maxX, maxY, unknown60, unknown64;
    float pixelsPerUnit, unitsPerPixel;
};

#endif
