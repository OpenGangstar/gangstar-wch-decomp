#ifndef WCH_INPUT_CCONTROLMANAGER_H
#define WCH_INPUT_CCONTROLMANAGER_H

class IControlHandler;
class GS3DStuff;

// Partial retail layout. Do not instantiate.
class CControlManager {
public:
    CControlManager();
    ~CControlManager();
    void init() __attribute__((noinline));
    void lock();
    void unlock();
    void exitCombat();
    bool isLocked() const;
    void setCameraProxy(GS3DStuff* proxy);
    static bool s_cameraTutorial, s_sniperTutorial;

private:
    IControlHandler* activeHandler;
    IControlHandler* onFootHandler;
    IControlHandler* drivingHandler;
    IControlHandler* sniperHandler;
    GS3DStuff* cameraProxy;
    bool locked;
    int unknown24[5];
    bool unknown44;
    bool unknown45;
    bool unknown46;
};

#endif
