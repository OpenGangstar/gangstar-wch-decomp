#ifndef WCH_APP_APPLICATION_H
#define WCH_APP_APPLICATION_H
#include "../input/TouchScreenMouseEvent.h"
#include "ApplicationStorage.h"

class AccelerometerBase;
class StringManager;
class ASprite;
class StateMachine;
class IUpdatable;
class IDrawable;
class CCustomMaterialRenderer_VERTEX_COLOR_ALPHA;
typedef CCustomMaterialRenderer_VERTEX_COLOR_ALPHA CCustomMaterialRenderer;
class FileSystemBase;
class WeaponManager;
class CHudManager;
class CControlManager;
class TouchScreenBase;
class EventManager;
namespace irr { class IrrlichtDevice; class IEventReceiver; }

// Historical partial-layout guidance, superseded by the recovered native extent below.
// Partial layout. Members at offsets 36, 40, 44, 68, 72, 76 and 80 are currently recovered.
// Do not instantiate or use sizeof until the complete class is recovered.
// Native extent 180 bytes; original constructor/destructor remain imports.
class Application : public irr::IEventReceiver {
public:
    Application();
    virtual ~Application();
    virtual bool OnEvent(const irr::SEvent& event);
    void Update();
    void _Update(int elapsed);
    void _Draw();
    void ProcessKeyEvent(bool pressed, int type);
    void appKeyReleased(int key);
    void appKeyPressed(int key);
    void displayNumberWithHUDSprite(int number, int horizontalAlign, int verticalAlign, const char* format);
    bool IsLogoOver();
    bool IsGlobalResumingOver();
    static Application* GetInstance();
    void SetIsDemoVersion(bool enabled);
    bool GetIsDemoVersion();
    static CCustomMaterialRenderer* GetMaterialRenderer();
    void SetDefaultLanguage(int language);
    void InitWin32(irr::IrrlichtDevice* device);
    void Init(irr::IrrlichtDevice* device);
    void ReInitWin32(irr::IrrlichtDevice* newDevice);
    void ReInit(irr::IrrlichtDevice* newDevice);
    void InitIPhoneFileSystem();
    void dumpMonitoredPointers();
    void startMonitoring(void* pointer, const char* name);
    void stopMonitoring(void* pointer);
    void SetDrawAll(bool enabled);
    void Pause();
    void Resume();
    void Quit();
    void StartGlobalResuming();
    void GlobalResumingDraw();
    void GlobalResumingUpdate();
    void StartLogo();
    void LogoDraw();
    void LogoUpdate();
    void startSoundThread();
    void stopSoundThread();
    void UnRegisterForIrrlichtEvents(irr::IEventReceiver* receiver);
    void UnRegisterForDrawingOnHUD(IDrawable* drawable);
    void UnRegisterForDrawingInScene(IDrawable* drawable);
    void RegisterForIrrlichtEvents(irr::IEventReceiver* receiver);
    void RegisterForDrawingInScene(IDrawable* drawable);
    void RegisterForDrawingOnHUD(IDrawable* drawable);
    void RegisterForUpdate(IUpdatable* object);
    void UnRegisterForUpdate(IUpdatable* object);
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
    stlp_priv::_List_base<IUpdatable*, std::allocator<IUpdatable*> > updatables;
    stlp_priv::_List_base<IDrawable*, std::allocator<IDrawable*> > sceneDrawables;
    stlp_priv::_List_base<IDrawable*, std::allocator<IDrawable*> > hudDrawables;
    stlp_priv::_List_base<irr::IEventReceiver*, std::allocator<irr::IEventReceiver*> > eventReceivers;
    irr::IrrlichtDevice* device;
    FileSystemBase* fileSystem;
    TouchScreenBase* touchScreen;
public:
    // Recovered native pointer accessed by the platform bridge.
    AccelerometerBase* accelerometer;
private:
    void* unknown52;
    EventManager* eventManager;
    void* unknown60;
    StateMachine* stateMachine;
    StringManager* stringManager;
    CControlManager* controlManager;
    CHudManager* hudManager;
    WeaponManager* weaponManager;
    static CCustomMaterialRenderer* s_materialRenderer;
    int defaultLanguage;
    int targetFrameRate;
    unsigned int lastUpdateTime;
    float unknown96;
    int unknown100;
    bool drawAll;
    bool soundNeedsInit;
    bool demoVersion;
    unsigned char unknown107;
    int resumeElapsed;
    int resumeFrame;
    unsigned int resumeInitialTextureCount;
    int resumeTextureCount;
    int logoFrame;
    int logoFrameCount;
    unsigned char unknown132[4];
    ASprite* resumeSprite;
    ASprite* logoSprite;
    unsigned char unknown144[4];
    int lastPressedKey;
    bool soundThreadPlaying;
    unsigned char unknown153[3];
    ApplicationMonitoredPointerStorage monitoredPointers;
public:
    // Return type inferred from platform API; original declaration is unproven.
    void InitIPhone(irr::IrrlichtDevice*, float, float, float, float);

};

#endif
