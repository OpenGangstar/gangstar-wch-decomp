#ifndef WCH_MISSIONS_CHECKPOINT_H
#define WCH_MISSIONS_CHECKPOINT_H
#include "../characters/Transformation.h"
namespace Structs { struct Checkpoint; }
class Checkpoint : public Transformation {
public:
    Checkpoint(int type);
    void Load(const Structs::Checkpoint&);
    // Observed integer radius at 84, also used by Race's distance test.
    int getRadius() const { return radius; }
protected:
    int radius;
private:
    unsigned char unknown88[12];
};
#endif
