#ifndef WCH_MISSIONS_SIDE_MISSION_MANAGER_H
#define WCH_MISSIONS_SIDE_MISSION_MANAGER_H

class SideMission;
class AmbulanceSideMission;
class DeliverySideMission;
class TaxiSideMission;

class SideMissionManager {
public:
    static void debug();
    static void confirm();
    static void init();
    static void clean();
    static void start();
    static void draw();
    static void setNextMissionTimer();
    static bool isInSideMission();
    static bool isMissionAvailable();
    static void update(unsigned int elapsed);
    static void stop(bool showMessage);

    static AmbulanceSideMission* s_ambulanceSideMission;
    static DeliverySideMission* s_deliverySideMission;
    static TaxiSideMission* s_taxiSideMission;

private:
    static void initMission();
    static SideMission* s_currentMission;
    static int s_step;
    static int s_nextMissionTimer;
};

#endif
