#ifndef WCH_APP_APPLICATION_H
#define WCH_APP_APPLICATION_H

class StringManager;
class FileSystemBase;
class WeaponManager;
class CHudManager;
class TouchScreenBase;
class EventManager;
namespace irr { class IrrlichtDevice; }

// Partial layout. Members at offsets 36, 40, 44, 68, 76 and 80 are currently recovered.
// Do not instantiate or use sizeof until the complete class is recovered.
class Application {
public:
    static Application* GetInstance();
    void startSoundThread();
    void stopSoundThread();
    void GetScreenDimensions(int& width, int& height) const;
    inline irr::IrrlichtDevice* GetDevice() const { return device; }
    inline StringManager* GetStringManager() const { return stringManager; }
    inline FileSystemBase* GetFileSystem() const { return fileSystem; }
    inline CHudManager* GetHudManager() const { return hudManager; }
    inline WeaponManager* GetWeaponManager() const { return weaponManager; }
    inline TouchScreenBase* GetTouchScreen() const { return touchScreen; }
    inline EventManager* GetEventManager() const { return eventManager; }
private:
    unsigned char unknownPrefix[36];
    irr::IrrlichtDevice* device;
    FileSystemBase* fileSystem;
    TouchScreenBase* touchScreen;
    unsigned char unknown48[8];
    EventManager* eventManager;
    unsigned char unknown60[8];
    StringManager* stringManager;
    unsigned char unknown72[4];
    CHudManager* hudManager;
    WeaponManager* weaponManager;
};

#endif
