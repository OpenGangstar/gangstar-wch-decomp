#ifndef WCH_WORLD_MAP_H
#define WCH_WORLD_MAP_H

namespace irr {
namespace core { template<class T> class dimension2d; }
namespace video { class ITexture; }
}

class Map {
public:
    static Map* getInstance() __attribute__((weak, used));

    void clean();
    void getScaledSize(irr::core::dimension2d<int>& size) const __attribute__((weak));

private:
    enum eMapType { DefaultMap = 1 };
    void setMap(eMapType type);
    Map();
    ~Map();

    // Retail singleton storage. Member types are still being recovered.
    irr::video::ITexture* texture;
    unsigned int unknown4;
    float scale;
    float offsetX, offsetY;
    unsigned int unknown20, unknown24, unknown28, unknown32, unknown36, unknown40;
    float minX, minY, maxX, maxY, unknown60, unknown64;
    float pixelsPerUnit, unitsPerPixel;
};

#endif
