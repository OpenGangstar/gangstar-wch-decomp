#ifndef WCH_MISSIONS_SIDE_MISSION_MANAGER_H
#define WCH_MISSIONS_SIDE_MISSION_MANAGER_H

class SideMission;

class SideMissionManager {
public:
    static void debug();
    static void confirm();
    static void setNextMissionTimer();
    static bool isInSideMission();
    static bool isMissionAvailable();
    static void update(unsigned int elapsed);

    static SideMission* s_ambulanceSideMission;
    static SideMission* s_deliverySideMission;
    static SideMission* s_taxiSideMission;

private:
    static void initMission();
    static SideMission* s_currentMission;
    static int s_step;
    static int s_nextMissionTimer;
};

#endif
