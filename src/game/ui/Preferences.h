#ifndef WCH_UI_PREFERENCES_H
#define WCH_UI_PREFERENCES_H

#include "../persistence/Persistence.h"

class Preferences : public Persistence {
public:
    Preferences();
    virtual ~Preferences();
    bool Exist(const char* name);
    bool SampleAndSave(const char* name);
    static const char* GetDefaultFilename();
};

#endif
