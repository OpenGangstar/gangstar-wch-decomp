#ifndef WCH_INPUT_CCONTROLMANAGER_H
#define WCH_INPUT_CCONTROLMANAGER_H

class CControlManager {
public:
    void lock();
    static bool s_cameraTutorial, s_sniperTutorial;
};

#endif
