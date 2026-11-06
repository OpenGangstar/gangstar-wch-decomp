#ifndef WCH_AI_AI_MANAGER_H
#define WCH_AI_AI_MANAGER_H

class Vehicle;
namespace gameloft { namespace ai {
// Only the state value observed by Race is named here.
enum StateID { RaceDriving = 1 };
} }

// Partial call interface; the 24-byte singleton's fields remain unrecovered.
class AIManager {
public:
    virtual ~AIManager();
    static AIManager* getInstance() __attribute__((weak, used));
    void removeAI(Vehicle* vehicle);
    void addAI(Vehicle* vehicle, gameloft::ai::StateID state);

private:
    AIManager();
    unsigned char unknown4[20];
};

#endif
