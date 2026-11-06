#ifndef WCH_MISSIONS_MISSION_H
#define WCH_MISSIONS_MISSION_H

class Mission {
public:
    void idle();
    void resumeFadeOut();
    void skipFadeOut();
    void setFailureCount(int count);
    void clearConditions();
    void fail();
    void message(int id);
    bool objective(int id, bool silent);
    bool start(int id, int duration);
};

#endif
