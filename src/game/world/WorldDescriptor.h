#ifndef WCH_WORLD_WORLD_DESCRIPTOR_H
#define WCH_WORLD_WORLD_DESCRIPTOR_H

class DataStream;

namespace Structs {
struct WorldDescriptor {
    void Read(DataStream& stream) __attribute__((weak));

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
    WorldDescriptor();
    explicit WorldDescriptor(const char* path);
    explicit WorldDescriptor(int resourceId);
    ~WorldDescriptor();
};

#endif
