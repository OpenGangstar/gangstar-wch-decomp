#ifndef WCH_WORLD_WORLD_DESCRIPTOR_H
#define WCH_WORLD_WORLD_DESCRIPTOR_H

class DataStream;

namespace Structs {
struct WorldDescriptor {
    void Read(DataStream& stream);

    int flags;
    char* objectsPath;
    char* scenePath;
    char* unknown12;
    int unknown16;
    char* unknown20;
};
}

class WorldDescriptor : public Structs::WorldDescriptor {
public:
    explicit WorldDescriptor(const char* path);
    ~WorldDescriptor();
};

#endif
