#ifndef WCH_UI_SHOP_H
#define WCH_UI_SHOP_H
#include "../missions/Checkpoint.h"
namespace Structs { struct CheckpointShop; }
class Shop : public Checkpoint {
public:
    Shop(int type);
    void trigger(bool enabled);
    bool unlocked() const;
    bool triggered() const;
    int getId();
    void Load(const Structs::CheckpointShop&);
private:
    static int s_numShopWeapon;
    static int s_numShopRental;
    int shopId;
    bool triggerActive;
    unsigned char unknown105[3];
};
#endif
