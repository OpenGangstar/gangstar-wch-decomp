#ifndef WCH_WORLD_MAP_SINGLETON_H
#define WCH_WORLD_MAP_SINGLETON_H

#include "Map.h"

inline Map* Map::getInstance()
{
    static Map map;
    return &map;
}

#endif
