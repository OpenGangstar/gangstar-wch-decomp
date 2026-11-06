#ifndef WCH_AI_AI_MANAGER_SINGLETON_H
#define WCH_AI_AI_MANAGER_SINGLETON_H

#include "AIManager.h"

inline AIManager* AIManager::getInstance()
{
    static AIManager aim;
    return &aim;
}

#endif
