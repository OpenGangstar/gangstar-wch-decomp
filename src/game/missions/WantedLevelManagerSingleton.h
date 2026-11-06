#ifndef WCH_MISSIONS_WANTED_LEVEL_MANAGER_SINGLETON_H
#define WCH_MISSIONS_WANTED_LEVEL_MANAGER_SINGLETON_H

#include "WantedLevelManager.h"

inline WantedLevelManager* WantedLevelManager::getInstance()
{
    static WantedLevelManager wlm;
    return &wlm;
}

#endif
