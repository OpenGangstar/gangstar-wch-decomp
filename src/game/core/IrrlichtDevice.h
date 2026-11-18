// Copyright (C) 2002-2008 Nikolaus Gebhardt
// Altered Irrlicht 1.4.2 interfaces for the observed fork hierarchy.
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
#ifndef WCH_CORE_IRRLICHT_DEVICE_H
#define WCH_CORE_IRRLICHT_DEVICE_H
#include "SceneNode.h"
#include "ColorFormat.h"
namespace irr {
struct SEvent;
class IEventReceiver;
class IrrlichtDevice {
public:
    virtual void unknown0(); virtual void unknown1(); virtual void reinitDriver();
    virtual void unknown3(); virtual void unknown4(); virtual void unknown5();
    virtual video::IVideoDriver* getVideoDriver();
    virtual io::IFileSystem* getFileSystem(); virtual void* getGUIEnvironment();
    virtual scene::ISceneManager* getSceneManager();
    virtual void unknown10(); virtual void unknown11();
    virtual void unknown12(); virtual void unknown13();
    virtual ITimer* getTimer();
    virtual void setWindowCaption(const wchar_t* text);
    virtual bool isWindowActive() const;
    virtual bool isWindowFocused() const;
    virtual bool isWindowMinimized() const;
    virtual bool isFullscreen() const;
    virtual video::ECOLOR_FORMAT getColorFormat() const;
    virtual void closeDevice();
    virtual const char* getVersion() const;
    virtual void setEventReceiver(IEventReceiver* receiver);
    virtual IEventReceiver* getEventReceiver();
    virtual bool postEventFromUser(const SEvent& event);
};
}
#endif
