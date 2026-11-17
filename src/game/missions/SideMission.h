#ifndef WCH_MISSIONS_SIDE_MISSION_H
#define WCH_MISSIONS_SIDE_MISSION_H

#include "../core/Vector3.h"
#include "../core/Array.h"

class Checkpoint;
class NPC;
class SideMission {
public:
    virtual void begin(irr::core::vector3d<float>, int, int&, float&) = 0;
    virtual bool pickUp(irr::core::vector3d<float>, int&, float&, int) = 0;
    virtual bool dropOff(irr::core::vector3d<float>) = 0;
    virtual void end() = 0;
    virtual void clean() = 0;
    virtual int getMoneyReward() = 0;
    virtual int getGoalMessage() = 0;
    virtual int getStartMessage() = 0;
    virtual int getEndMessage() = 0;
    virtual int getObj1Message() = 0;
    virtual int getObj2Message() = 0;
    void init();
    bool inProgress();
    bool finished();
    void start();
    int getTimer();
    int getReward();
    void updateTimer(int elapsed);
    void update(int elapsed);

protected:
    void fadeInFadeOut();
    void removeNPC();
    static void getCheckpoints(int metatype, irr::core::array<Checkpoint*>& checkpoints);
    static void disableCheckpoints(irr::core::array<Checkpoint*>& checkpoints);
    static void getRange(float&, float&, int, int, int, int, int);
    static Checkpoint* addCheckpoint(int, irr::core::vector3d<float>, float, float, unsigned short, unsigned short&);
    void addNPC(int, int, irr::core::vector3d<float>, unsigned short, unsigned short);
    static int calculateTime(irr::core::vector3d<float>, irr::core::vector3d<float>, int, int);
    static float calculateMoney(irr::core::vector3d<float>, irr::core::vector3d<float>, int, int);
    static void removeCheckpoint(Checkpoint*& checkpoint);
    static bool isInCheckpointRange(irr::core::vector3d<float> position, Checkpoint* checkpoint);

private:
    int activeState;

protected:
    int difficulty;

private:
    int timer;
    float reward;
    int stopReason;
    void stop(bool showMessage);

protected:
    NPC* passenger;
};

#endif
