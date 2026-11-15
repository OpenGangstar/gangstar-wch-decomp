#ifndef WCH_INPUT_CCONTROLMANAGER_H
#define WCH_INPUT_CCONTROLMANAGER_H

class IControlHandler;
class GS3DStuff;

// Partial retail layout. Do not instantiate.
class CControlManager {
public:
    ~CControlManager();
    void lock();
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
};

#endif
