#ifndef WCH_PERSISTENCE_FILE_MANAGER_H
#define WCH_PERSISTENCE_FILE_MANAGER_H

#include "DataStream.h"

namespace Structs {
struct FileEntry {
    char* dvdName;
    char* name;
    void Read(DataStream& stream)
    {
        dvdName = stream.ReadAndAllocateString();
        name = stream.ReadAndAllocateString();
    }
};
}

class FileManager {
public:
    FileManager(bool argumentMapping);
    ~FileManager();
    int _GetNumMappings();
    Structs::FileEntry* _GetMapping(int id);
    int _GetFileSize(int id);
    const char* _GetDvdName(int id);
    const char* _GetName(int id);
    static void StringToShortName(char* text, int length);
    static void StringToBaseName(char* text, int length);
    void _Debug_ClearLoadedRessources();
    int _Debug_GetLoadedRessourcesCount();
    int _Debug_GetLoadedRessources(int* ids);
    int _Debug_GetMaxFileCount();
    static void StringToBaseName(char* text);
    static void StringToShortName(char* text);
    int _GetIdFromDvdName(const char* name);
    int _GetResIdsFromDvdFolder(const char* folder, int* ids, int capacity);
    int _GetNamesFromPrefix(const char* prefix, char (*names)[256]);
    void* _Load(int id, int* size);
    void _Unload(void* memory);
    void _Unload(int id);
    int _GetFirstIdFromPrefix(const char* prefix);
    int _GetId(const char* name);
    static void Destroy();
    static void InitArgMapping();
    static void Init();
    static const char* GetDvdName(const char* name);

private:
    friend class StreamingSound;

    struct MappingIndex { int count; Structs::FileEntry* entries; };
    struct ResourceState {
        ResourceState() : references(0), data(0), size(0), loaded(false) {}
        int references;
        void* data;
        int size;
        bool loaded;
    };
    MappingIndex* index;
    void* unknown4;
    ResourceState* resources;
    static FileManager* s_mgr;
};

#endif
