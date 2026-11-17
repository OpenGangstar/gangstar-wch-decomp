#ifndef WCH_CORE_FACTORY_PRODUCTS_H
#define WCH_CORE_FACTORY_PRODUCTS_H

namespace irr {
namespace video { class IVideoDriver; }
namespace io { class IFileSystem; }
namespace gui { class ICursorControl; class IGUIEnvironment; }
namespace scene { class IMeshCache; class ISceneNode; }
}

// The allocation extent and imported entry points are known here.
// The factory returns the same address as the native scene-manager interface.
class CCustomSceneManager {
    unsigned char opaque[1040];
public:
    CCustomSceneManager(irr::video::IVideoDriver*, irr::io::IFileSystem*,
        irr::gui::ICursorControl*, irr::scene::IMeshCache*, irr::gui::IGUIEnvironment*);
    void clean();
    static void CleanParents(irr::scene::ISceneNode* node);
};

#endif
