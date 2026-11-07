#ifndef WCH_AI_AI_MANAGER_H
#define WCH_AI_AI_MANAGER_H

#include "../core/GameEvents.h"

class Vehicle;
class NPC;
namespace gameloft { namespace ai {
// Only the state value observed by Race is named here.
enum StateID { RaceDriving = 1 };
} }

// Partial call interface and observed 24-byte singleton layout.
class AIManager : public IEventReceiver {
public:
    virtual ~AIManager();
    virtual void onEvent(const IEvent*, const EventManager*);
    static AIManager* getInstance() __attribute__((weak, used));
    void removeAI(Vehicle* vehicle);
    void removeAI(NPC* npc);
    void addAI(Vehicle* vehicle, gameloft::ai::StateID state);
    void addAI(NPC* npc, gameloft::ai::StateID state);

private:
    AIManager();
    struct ReceiverList {
        ReceiverList() : next(this), previous(this) {}
        ~ReceiverList();
        void removeForTarget(const void* target);

        ReceiverList* next;
        ReceiverList* previous;
    };
    struct ReceiverNode;
    ReceiverList firstList;
    ReceiverList secondList;
    int unknown20;
};

#endif
