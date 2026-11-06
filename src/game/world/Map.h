#ifndef WCH_WORLD_MAP_H
#define WCH_WORLD_MAP_H

class Map {
public:
    static Map* getInstance() __attribute__((weak, used));

private:
    Map();
    ~Map();

    // Retail singleton storage. Member types are still being recovered.
    unsigned int storage[19];
};

inline Map* Map::getInstance()
{
    static Map map;
    return &map;
}

#endif
