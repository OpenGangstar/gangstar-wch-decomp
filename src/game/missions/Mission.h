#ifndef WCH_MISSIONS_MISSION_H
#define WCH_MISSIONS_MISSION_H

#include "../characters/AnimObject.h"

class IMissionCondition;
namespace Structs { struct Mission; }

class Mission {
public:
    virtual ~Mission();
    int setTextToPrint(int id);
    Structs::Mission* mission(int index) const;
    int getLastObjectiveText() const;
    int getCurrentMessage() const;
    void registerCondition(IMissionCondition* condition);
    int getState() const;
    int failureCause() const;
    int failureCount() const;
    void idle();
    void resumeFadeOut();
    void skipFadeOut();
    void setFailureCount(int count);
    void clearConditions();
    void fail();
    void message(int id);
    bool objective(int id, bool silent);
    bool start(int id, int duration);
private:
    unsigned char unknown4[16];
    int currentMessage;
    int lastObjectiveText;
    int state;
    AnimObject introAnimation;
    AnimObject outroAnimation;
    unsigned char unknown120[68];
    Structs::Mission** missions;
    int missionCount;
    IMissionCondition* conditions[8];
    int conditionCount;
    int lastFailureCause;
    int failures;
    bool unknown240;
    bool skipFade;
};

#endif
