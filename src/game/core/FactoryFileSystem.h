// Copyright (C) 2002-2008 Nikolaus Gebhardt
// Altered Irrlicht 1.4.2 interfaces for the observed fork hierarchy.
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software
// in a product, an acknowledgement in the product documentation would be
// appreciated but is not required.
// 2. Altered source versions must be clearly marked as such, and must not be
// misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
#ifndef WCH_CORE_FACTORY_FILE_SYSTEM_H
#define WCH_CORE_FACTORY_FILE_SYSTEM_H

#include "SceneNode.h"

// Observed fork's virtual interface and allocation extents. Engine bodies
// remain imports; unused return interfaces are forward declarations.
namespace irr { namespace io {
class IReadFile; class IWriteFile; class IFileList;
class IXMLReader; class IXMLReaderUTF8; class IXMLWriter;
typedef core::string<char,core::irrAllocator<char> > FilePath;
class IFileSystem : public virtual IReferenceCounted {
public:
    virtual IReadFile* createAndOpenFile(const char*) = 0;
    virtual IReadFile* createMemoryReadFile(void*, int, const char*, bool) = 0;
    virtual IWriteFile* createAndWriteFile(const char*, bool) = 0;
    virtual bool addZipFileArchive(const char*, bool, bool) = 0;
    virtual bool addFolderFileArchive(const char*, bool, bool) = 0;
    virtual bool addPakFileArchive(const char*, bool, bool) = 0;
    virtual const char* getWorkingDirectory() = 0;
    virtual bool changeWorkingDirectoryTo(const char*) = 0;
    virtual FilePath getAbsolutePath(const FilePath&) const = 0;
    virtual FilePath getFileDir(const FilePath&) const = 0;
    virtual FilePath getFileBasename(const FilePath&, bool) const = 0;
    virtual IFileList* createFileList() const = 0;
    virtual bool existFile(const char*) const = 0;
    virtual bool existFile(const FilePath&) const = 0;
    virtual IXMLReader* createXMLReader(const char*) = 0;
    virtual IXMLReader* createXMLReader(IReadFile*) = 0;
    virtual IXMLReaderUTF8* createXMLReaderUTF8(const char*) = 0;
    virtual IXMLReaderUTF8* createXMLReaderUTF8(IReadFile*) = 0;
    virtual IXMLWriter* createXMLWriter(const char*) = 0;
    virtual IXMLWriter* createXMLWriter(IWriteFile*) = 0;
    virtual IAttributes* createEmptyAttributes(video::IVideoDriver*) = 0;
    virtual ~IFileSystem();
};
class CFileSystem : public IFileSystem {
    unsigned char unknown4[60];
public:
    CFileSystem();
    virtual ~CFileSystem();
    virtual IReadFile* createAndOpenFile(const char*);
    virtual IReadFile* createMemoryReadFile(void*, int, const char*, bool);
    virtual IWriteFile* createAndWriteFile(const char*, bool);
    virtual bool addZipFileArchive(const char*, bool, bool);
    virtual bool addFolderFileArchive(const char*, bool, bool);
    virtual bool addPakFileArchive(const char*, bool, bool);
    virtual const char* getWorkingDirectory();
    virtual bool changeWorkingDirectoryTo(const char*);
    virtual FilePath getAbsolutePath(const FilePath&) const;
    virtual FilePath getFileDir(const FilePath&) const;
    virtual FilePath getFileBasename(const FilePath&, bool) const;
    virtual IFileList* createFileList() const;
    virtual bool existFile(const char*) const;
    virtual bool existFile(const FilePath&) const;
    virtual IXMLReader* createXMLReader(const char*);
    virtual IXMLReader* createXMLReader(IReadFile*);
    virtual IXMLReaderUTF8* createXMLReaderUTF8(const char*);
    virtual IXMLReaderUTF8* createXMLReaderUTF8(IReadFile*);
    virtual IXMLWriter* createXMLWriter(const char*);
    virtual IXMLWriter* createXMLWriter(IWriteFile*);
    virtual IAttributes* createEmptyAttributes(video::IVideoDriver*);
};
} }

#endif
