#ifndef WCH_APP_APPLICATION_H
#define WCH_APP_APPLICATION_H

class StringManager;
class ASprite;
class StateMachine;
class IUpdatable;
class IDrawable;
class CCustomMaterialRenderer;
class FileSystemBase;
class WeaponManager;
class CHudManager;
class CControlManager;
class TouchScreenBase;
class EventManager;
namespace irr { class IrrlichtDevice; class IEventReceiver; }

// Partial layout. Members at offsets 36, 40, 44, 68, 72, 76 and 80 are currently recovered.
// Do not instantiate or use sizeof until the complete class is recovered.
class Application {
public:
    static Application* GetInstance();
    void SetIsDemoVersion(bool enabled);
    bool GetIsDemoVersion();
    static CCustomMaterialRenderer* GetMaterialRenderer();
    void SetDefaultLanguage(int language);
    void ReInitWin32(irr::IrrlichtDevice* newDevice);
    void ReInit(irr::IrrlichtDevice* newDevice);
    void InitIPhoneFileSystem();
    void dumpMonitoredPointers();
    void SetDrawAll(bool enabled);
    void Pause();
    void StartGlobalResuming();
    void startSoundThread();
    void stopSoundThread();
    void UnRegisterForIrrlichtEvents(irr::IEventReceiver* receiver);
    void UnRegisterForDrawingOnHUD(IDrawable* drawable);
    void UnRegisterForDrawingInScene(IDrawable* drawable);
    void RegisterForIrrlichtEvents(irr::IEventReceiver* receiver);
    void RegisterForDrawingOnHUD(IDrawable* drawable);
    void RegisterForUpdate(IUpdatable* object);
    void GetScreenDimensions(int& width, int& height) const;
    inline irr::IrrlichtDevice* GetDevice() const { return device; }
    inline StringManager* GetStringManager() const { return stringManager; }
    inline FileSystemBase* GetFileSystem() const { return fileSystem; }
    inline CControlManager* GetControlManager() const { return controlManager; }
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
    unsigned char unknown60[4];
    StateMachine* stateMachine;
    StringManager* stringManager;
    CControlManager* controlManager;
    CHudManager* hudManager;
    WeaponManager* weaponManager;
    static CCustomMaterialRenderer* s_materialRenderer;
    int defaultLanguage;
    unsigned char unknown88[16];
    bool drawAll;
    bool soundNeedsInit;
    bool demoVersion;
    unsigned char unknown107;
    int resumeElapsed;
    int resumeFrame;
    unsigned int resumeInitialTextureCount;
    unsigned int resumeTextureCount;
    unsigned char unknown124[12];
    ASprite* resumeSprite;
    unsigned char unknown140[12];
    bool soundThreadPlaying;
};

#endif
