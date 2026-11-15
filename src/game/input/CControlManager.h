#ifndef WCH_INPUT_CCONTROLMANAGER_H
#define WCH_INPUT_CCONTROLMANAGER_H

class IControlHandler;

// Partial retail layout. Do not instantiate.
class CControlManager {
public:
    ~CControlManager();
    void lock();
    static bool s_cameraTutorial, s_sniperTutorial;

private:
    IControlHandler* activeHandler;
    IControlHandler* onFootHandler;
    IControlHandler* drivingHandler;
    IControlHandler* sniperHandler;
};

#endif
