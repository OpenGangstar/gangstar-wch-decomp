#ifndef WCH_CORE_CUSTOM_IRR_FACTORY_H
#define WCH_CORE_CUSTOM_IRR_FACTORY_H

namespace irr {
class IOSOperator;
namespace io { class IFileSystem; }
namespace video { class IVideoDriver; class CNullDriver; class CTextureManager; typedef CTextureManager ITextureManager; }
namespace gui { class ICursorControl; class IGUIEnvironment; }
namespace scene { class ISceneManager; }

// Four-byte factory interface; implementations remain engine imports.
class CIrrFactory {
public:
    CIrrFactory();
    virtual ~CIrrFactory();
    virtual io::IFileSystem* createFileSystem();
    virtual scene::ISceneManager* createSceneManager(video::IVideoDriver*, io::IFileSystem*, gui::ICursorControl*, gui::IGUIEnvironment*);
    virtual gui::IGUIEnvironment* createGUIEnvironment(io::IFileSystem*, video::IVideoDriver*, IOSOperator*);
    virtual video::ITextureManager* createTextureManager(video::CNullDriver*);
};
}

class CCustomIrrFactor : public irr::CIrrFactory {
public:
    virtual ~CCustomIrrFactor() __attribute__((used)) {}
    virtual irr::io::IFileSystem* createFileSystem() __attribute__((used));
    virtual irr::scene::ISceneManager* createSceneManager(irr::video::IVideoDriver*, irr::io::IFileSystem*, irr::gui::ICursorControl*, irr::gui::IGUIEnvironment*) __attribute__((used));
};

extern CCustomIrrFactor customFactory;

#endif
