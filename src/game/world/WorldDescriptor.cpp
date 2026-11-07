/*
 * WorldDescriptor
 *
 * Original file: WorldDescriptor.cpp
 * Area:          world
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of WorldDescriptor.cpp here, in the order they appear in the library.
 */

#include "WorldDescriptor.h"
#include "ResStream.h"
#include "../persistence/DataStream.h"

WorldDescriptor::WorldDescriptor() {}

WorldDescriptor::~WorldDescriptor()
{
    delete[] scenePath;
    delete[] objectsPath;
    delete[] unknown12;
    delete[] unknown20;
}

void Structs::WorldDescriptor::Read(DataStream& stream)
{
    flags = stream.ReadInt();
    objectsPath = stream.ReadAndAllocateString();
    scenePath = stream.ReadAndAllocateString();
    unknown12 = stream.ReadAndAllocateString();
    unknown16 = stream.ReadInt();
    unknown20 = stream.ReadAndAllocateString();
}

WorldDescriptor::WorldDescriptor(const char* path)
{
    ResStream resource(path, 1);
    DataStream stream(resource, DataStream::BigEndian);
    Read(stream);
}

WorldDescriptor::WorldDescriptor(int resourceId)
{
    ResStream resource(resourceId);
    DataStream stream(resource, DataStream::BigEndian);
    Read(stream);
}
