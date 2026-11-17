#ifndef WCH_CORE_CUSTOM_FILE_SYSTEM_H
#define WCH_CORE_CUSTOM_FILE_SYSTEM_H

#include "FactoryFileSystem.h"

class CCustomFileSystem : public irr::io::CFileSystem {
public:
    CCustomFileSystem() {}
    virtual irr::io::FilePath getAbsolutePath(const irr::io::FilePath&) const;
    virtual ~CCustomFileSystem() __attribute__((used)) {}
};

#endif
