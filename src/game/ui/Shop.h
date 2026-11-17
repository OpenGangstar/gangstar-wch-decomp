#ifndef WCH_UI_SHOP_H
#define WCH_UI_SHOP_H
#include "../missions/Checkpoint.h"
namespace Structs { struct CheckpointShop; }
class Shop : public Checkpoint {
public:
    Shop(int type);
    void trigger(bool enabled);
    bool triggered() const;
    void Load(const Structs::CheckpointShop&);
private:
    unsigned char unknown100[4];
    bool triggerActive;
    unsigned char unknown105[3];
};
#endif
