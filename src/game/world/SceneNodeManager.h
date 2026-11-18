/*
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Copyright (c) 1996,1997
 * Silicon Graphics Computer Systems, Inc.
 *
 * Copyright (c) 1997
 * Moscow Center for SPARC Technology
 *
 * Copyright (c) 1999
 * Boris Fomitchev
 *
 * This material is provided "as is", with absolutely no warranty expressed
 * or implied. Any use is at your own risk.
 *
 * Permission to use or copy this software for any purpose is hereby granted
 * without fee, provided the above notices are retained on all copies.
 * Permission to modify the code and to distribute modified code is granted,
 * provided the above notices are retained, and a notice that the code was
 * modified is included with the above copyright notice.
 *
 */

// Modified: restricted native PoolIndex read-only iterator and lookup interfaces.
#ifndef WCH_WORLD_SCENE_NODE_MANAGER_H
#define WCH_WORLD_SCENE_NODE_MANAGER_H

#include "../core/PointerVector.h"

class LevelObject;
namespace irr { namespace scene { class ISceneNode; } namespace collada { class CColladaFactory; } }

// Partial layout through the CRC table and update timer.
class SceneNodeManager {
public:
    static SceneNodeManager* getInstance();
    void setup();
    void tearDown();
    void update(int);
    bool manage(int poolID, LevelObject* owner, int count);
    int findOrCreatePool(const char* name, int size, irr::collada::CColladaFactory* factory);
    irr::scene::ISceneNode* grab(int poolID, LevelObject* owner, int id, void*** parameters);
    bool drop(int poolID, const irr::scene::ISceneNode* node);
private:
    SceneNodeManager();
    ~SceneNodeManager();
    unsigned int crc(const char* name) const;
    int getPoolID(int key) const;
    int getPoolID(const char* path) const;
    struct Node {
        explicit Node(irr::scene::ISceneNode* sceneNode);
        ~Node();
        void setupUnmanaged(int parameterCount);
        bool available;
        irr::scene::ISceneNode* sceneNode;
        void** parameters;
        int unknown12;
    };
    struct Pool;
    struct PoolIndexLink {
        PoolIndexLink() : color(false), parent(0), left(this), right(this) {}
        bool color;
        PoolIndexLink* parent;
        PoolIndexLink* left;
        PoolIndexLink* right;
    };
    struct PoolIndexValue { const int first; int second; };
    struct PoolIndexNode : PoolIndexLink { PoolIndexValue value; };
    struct PoolIndexBaseIterator {
        PoolIndexLink* node;
        PoolIndexBaseIterator() {}
        PoolIndexBaseIterator(PoolIndexLink* pointer) : node(pointer) {}
    };
    struct PoolIndex {
        PoolIndex() : size(0), compareState(false) {}
        ~PoolIndex();
        void clear();
        struct Iterator : PoolIndexBaseIterator {
            Iterator() {}
            explicit Iterator(PoolIndexLink* pointer) : PoolIndexBaseIterator(pointer) {}
            const PoolIndexValue& operator*() const {
                return static_cast<PoolIndexNode*>(node)->value;
            }
            const PoolIndexValue* operator->() const { return &operator*(); }
            bool operator==(Iterator other) const { return node == other.node; }
            bool operator!=(Iterator other) const { return node != other.node; }
        };
        PoolIndexLink* _M_find(const int& key) const;
        Iterator find(const int& key) const { return Iterator(_M_find(key)); }
        Iterator end() const { return Iterator(const_cast<PoolIndexLink*>(&header)); }
        PoolIndexLink header;
        unsigned int size;
        bool compareState;
    };
    PoolIndex poolIndex;
    std::vector<Pool*> pools;
    unsigned int crcTable[256];
    int updateTimeRemaining;
    int updateInterval;
};

#endif
