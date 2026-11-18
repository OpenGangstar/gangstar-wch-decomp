#ifndef WCH_MISSIONS_MISSION_DATA_H
#define WCH_MISSIONS_MISSION_DATA_H

class DataStream;

namespace Structs {

struct Mission {
    int unknown0;
    int unknown4;
    int unknown8;
    char* unknown12;
    int unknown16;
    int unknown20;
    char* unknown24;
    int unknown28;
    int unknown32;

    void Read(DataStream& stream) __attribute__((used));
};

} // namespace Structs

#endif
