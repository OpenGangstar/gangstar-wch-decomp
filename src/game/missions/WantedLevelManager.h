#ifndef WCH_MISSIONS_WANTED_LEVEL_MANAGER_H
#define WCH_MISSIONS_WANTED_LEVEL_MANAGER_H

// Partial virtual/call interface and fields observed by SaveGame and Item.
class WantedLevelManager {
public:
    static bool s_bTutoWantedLevel;
    static WantedLevelManager* getInstance() __attribute__((weak, used));
    // The complete and deleting destructor slots precede update at slot 3.
    virtual ~WantedLevelManager(); virtual void unknown2();
    virtual void update(double);
    void _processWantedLevel();
    void storeWantedLevel();
    void lock(int level);
    void unlock();
    void restoreWantedLevel();
    void resetWantedLevel();
    unsigned int unknown4;
    int unknown8;

private:
    WantedLevelManager();
    // The retail singleton occupies 80 bytes. The remaining members are pending.
    int lockedLevel;
    int unknown16, unknown20;
    int savedLevel, savedLockedLevel, savedUnknown16, savedUnknown20;
    unsigned char unknown40[36];
    bool unknown76;
    unsigned char unknown77[2];
    bool locked;
};

#endif
