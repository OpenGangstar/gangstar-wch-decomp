/*
 * SceneNodeManager
 *
 * Original file: SceneNodeManager.cpp
 * Area:          world
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of SceneNodeManager.cpp here, in the order they appear in the library.
 */

unsigned int crcReflect(unsigned int value, char bits)
{
    unsigned int result = 0;
    for (int index = 1; index <= bits; ++index) {
        if (value & 1u)
            result |= 1u << (bits - index);
        value >>= 1;
    }
    return result;
}

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "SceneNodeManager.h"
#include "../core/NativeStdio.h"
#include "../app/Application.h"
#include "../core/SceneNode.h"
#include "../core/IrrlichtDevice.h"
#include "../core/Collada.h"
#include "../core/FactoryFileSystem.h"
#include "../core/ObservedString.h"
#include "LevelObject.h"

extern "C" void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(
    void*, const char*) __attribute__((weak));

template<class A> inline irr::core::string<char, A>::string(const char* source)
{
    array = 0;
    allocated = 0;
    used = 0;
    reference = false;
    _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(this, source);
}

template<class A> inline irr::core::string<char, A>::~string()
{
    if (!reference && array && inlineBuffer != array)
        ::operator delete(array);
}

struct SceneNodeManager::Pool {
    Pool(const char* name, irr::collada::CColladaFactory* factory, int size);
    ~Pool();
    void extend(int requested);
    char* name;
    irr::collada::CColladaFactory* factory;
    int size;
    unsigned int lastResizeTime;
    int activeCount;
    int constructedCount;
    std::vector<Node*> nodes;
};

void SceneNodeManager::setup()
{
}

void SceneNodeManager::update(int elapsed)
{
    if (updateInterval > 0) {
        updateTimeRemaining -= elapsed;
        if (updateTimeRemaining < 0)
            updateTimeRemaining = updateInterval;
    }
}

unsigned int SceneNodeManager::crc(const char* name) const
{
    const unsigned int length = strlen(name);
    if (static_cast<int>(length) <= 0)
        return 0;
    unsigned int value = ~0u;
    unsigned int index = 0;
    do {
        value = (value >> 8) ^ crcTable[(value & 0xffu) ^ static_cast<unsigned char>(name[index])];
    } while (++index < length);
    return ~value;
}

SceneNodeManager::Node::~Node()
{
    if (sceneNode) {
        sceneNode->remove();
        sceneNode->drop();
    }
    delete[] parameters;
}

void SceneNodeManager::Node::setupUnmanaged(int parameterCount)
{
    if (!parameters && parameterCount > 0) {
        parameters = new void*[parameterCount];
        memset(parameters, 0, parameterCount * sizeof(*parameters));
    }
}

SceneNodeManager::Node::Node(irr::scene::ISceneNode* node)
    : available(true), sceneNode(node), parameters(0), unknown12(0)
{
    node->setVisible(false);
    Application::GetInstance()->GetDevice()->getSceneManager()->getRootSceneNode()->addChild(node);
}

SceneNodeManager::Pool::Pool(const char* poolName, irr::collada::CColladaFactory* poolFactory, int poolSize)
    : name(0), factory(poolFactory), size(poolSize), lastResizeTime(0), activeCount(0),
      constructedCount(0)
{
    name = new char[strlen(poolName) + 1];
    strcpy(name, poolName);
}

SceneNodeManager::Pool::~Pool()
{
    delete[] name;
    for (Node** entry = nodes.begin(); entry != nodes.end(); ++entry)
        delete *entry;
    nodes.clear();
}

SceneNodeManager::SceneNodeManager()
{
    updateInterval = 10000;
    updateTimeRemaining = 10000;
    for (unsigned int index = 0; index < 256; ++index) {
        crcTable[index] = crcReflect(index, 8) << 24;
        for (int bit = 0; bit < 8; ++bit)
            crcTable[index] = (crcTable[index] << 1) ^
                ((crcTable[index] & 0x80000000u) ? 0x04c11db7u : 0);
        crcTable[index] = crcReflect(crcTable[index], 32);
    }
}

SceneNodeManager* SceneNodeManager::getInstance()
{
    static SceneNodeManager sceneNodeManager;
    return &sceneNodeManager;
}

extern "C" void _ZN9stlp_priv8_Rb_treeIiSt4lessIiESt4pairIKiiENS_10_Select1stIS5_EENS_11_MapTraitsTIS5_EESaIS5_EE8_M_eraseEPNS_18_Rb_tree_node_baseE(
    void* tree, void* root) __attribute__((weak));

inline void SceneNodeManager::PoolIndex::clear()
{
    if (size) {
        _ZN9stlp_priv8_Rb_treeIiSt4lessIiESt4pairIKiiENS_10_Select1stIS5_EENS_11_MapTraitsTIS5_EESaIS5_EE8_M_eraseEPNS_18_Rb_tree_node_baseE(
            this, header.parent);
        header.left = &header;
        header.parent = 0;
        header.right = &header;
        size = 0;
    }
}

void SceneNodeManager::tearDown()
{
    for (Pool** entry = pools.begin(); entry != pools.end(); ++entry)
        delete *entry;
    pools.clear();
    poolIndex.clear();
}

inline SceneNodeManager::PoolIndex::~PoolIndex()
{
    clear();
}

SceneNodeManager::~SceneNodeManager()
{
    tearDown();
}

int SceneNodeManager::getPoolID(const char* path) const
{
    irr::io::IFileSystem* fileSystem = Application::GetInstance()->GetDevice()->getFileSystem();
    const int key = crc(fileSystem->getAbsolutePath(path).c_str());
    return getPoolID(key);
}

irr::scene::ISceneNode* SceneNodeManager::grab(int poolID, LevelObject* owner,
    int parameterCount, void*** parameters)
{
    if (poolID < 0 || static_cast<unsigned int>(poolID) >= pools.size())
        return 0;
    Node* entry = 0;
    Pool* pool = pools[poolID];
    const int size = pool->nodes.size();
    if (size > 0 && pool->nodes[0]->available) {
        entry = pool->nodes[0];
        if (size - 1 > pool->activeCount) {
            pool->nodes[0] = pool->nodes[size - pool->activeCount - 1];
            pool->nodes[size - pool->activeCount - 1] = entry;
        }
        if (!entry->parameters && parameterCount)
            entry->setupUnmanaged(parameterCount);
    }
    if (!entry) {
        entry = new Node(irr::collada::CColladaDatabase::constructScene(pool->name, pool->factory));
        entry->setupUnmanaged(parameterCount);
        if (owner)
            owner->setupSceneNode(poolID, entry->sceneNode, parameterCount, entry->parameters);
        pool->nodes.push_back(entry);
    }
    entry->available = false;
    ++pool->activeCount;
    if (parameters)
        *parameters = entry->parameters;
    return entry->sceneNode;
}

void SceneNodeManager::Pool::extend(int requested)
{
    if (requested - constructedCount <= 0)
        return;
    const int previousSize = nodes.size();
    if (requested > previousSize) {
        Node* const empty = 0;
        nodes.resize(requested, empty);
        lastResizeTime = Application::GetInstance()->GetDevice()->getTimer()->getRealTime();
        while (constructedCount < requested) {
            Node*& slot = nodes[constructedCount++];
            slot = new Node(irr::collada::CColladaDatabase::constructScene(name, factory));
        }
        for (int index = 0; index < activeCount; ++index) {
            Node* previous = nodes[previousSize - index - 1];
            nodes[previousSize - index - 1] = nodes[constructedCount - index - 1];
            nodes[constructedCount - index - 1] = previous;
        }
    } else {
        constructedCount = requested;
    }
}

extern "C" int& _ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEixIiEERiRKT_(
    void* map, const int& key) __attribute__((weak));

int SceneNodeManager::findOrCreatePool(const char* name, int size,
    irr::collada::CColladaFactory* factory)
{
    irr::io::IFileSystem* fileSystem = Application::GetInstance()->GetDevice()->getFileSystem();
    irr::io::FilePath path = fileSystem->getAbsolutePath(name);
    const int key = crc(path.c_str());
    int poolID = getPoolID(key);
    Pool* pool = 0;
    if (poolID == -1) {
        poolID = pools.size();
        pool = new Pool(path.c_str(), factory, 0);
        pools.push_back(pool);
        _ZNSt3mapIiiSt4lessIiESaISt4pairIKiiEEEixIiEERiRKT_(&poolIndex, key) = poolID;
    } else {
        pool = pools[poolID];
    }
    if (pool->constructedCount < size)
        pool->extend(size);
    return poolID;
}

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
}

static void __static_initialization_and_destruction_0(int initialize, int priority) __attribute__((used));
static void __static_initialization_and_destruction_0(int initialize, int priority)
{
    if (initialize == 1 && priority == 65535) {
        irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
        value.array = 0;
        value.allocated = 0;
        value.used = 0;
        value.reference = false;
        _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(&value, localStartupEmptyText);
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_3), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__Z10crcReflectjc() __attribute__((used));
static void _GLOBAL__I__Z10crcReflectjc()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_3()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

bool SceneNodeManager::manage(int poolID, LevelObject* owner, int count)
{
    if (poolID < 0 || static_cast<unsigned int>(poolID) >= pools.size() || !owner)
        return false;
    if (count > 0) {
        Pool* pool=pools[poolID];
        const int size=pool->nodes.size();
        for (int i=0;i<size;++i) {
            if (!pool->nodes[i]->parameters) {
                pool->nodes[i]->setupUnmanaged(count);
                owner->setupSceneNode(poolID,pool->nodes[i]->sceneNode,count,pool->nodes[i]->parameters);
            }
        }
    }
    return true;
}

// Modified restricted adaptation of licensed STLport _tree.h _M_find.
// Original cached Android source commit: e64e7c849b0b659d3e198e4efaed563601e554be.
// PoolIndex uses observed native storage; this is not a full STL implementation.
inline SceneNodeManager::PoolIndexLink*
SceneNodeManager::PoolIndex::_M_find(const int& key) const
{
    PoolIndexLink* result = const_cast<PoolIndexLink*>(&header);
    PoolIndexLink* node = header.parent;
    while (node != 0) {
        if (!std::less<int>()(static_cast<PoolIndexNode*>(node)->value.first, key)) {
            result = node;
            node = node->left;
        } else {
            node = node->right;
        }
    }
    if (result != &header) {
        if (std::less<int>()(key, static_cast<PoolIndexNode*>(result)->value.first)) {
            result = const_cast<PoolIndexLink*>(&header);
        }
    }
    return result;
}

int SceneNodeManager::getPoolID(int key) const
{
    PoolIndex::Iterator result = poolIndex.find(key);
    return result == poolIndex.end() ? -1 : result->second;
}

// File-local layout views for the report: the class keeps its pools, pool
// and node types private and the report method is not declared in the header.
struct SceneNodeReportNode {
    bool available;
};
struct SceneNodeReportPool {
    const char* name;
    void* factory;
    int size;
    unsigned int lastResizeTime;
    int activeCount;
    int constructedCount;
    SceneNodeReportNode* const* nodesFirst;
    SceneNodeReportNode* const* nodesLast;
    SceneNodeReportNode* const* nodesLimit;
};
struct SceneNodeReportManager {
    unsigned char poolIndex[24];
    SceneNodeReportPool* const* poolsFirst;
    SceneNodeReportPool* const* poolsLast;
};

extern "C" void _ZNK16SceneNodeManager6reportEv(const SceneNodeReportManager* self)
{
    printf("+-- SceneNodeManager Report - BEGIN --------------------------------------------\n");
    printf("| Pool    Nodes   Minimum Usage   Idle    Mesh\n");
    int poolCount = 0;
    SceneNodeReportPool* const* it = self->poolsFirst;
    const unsigned int now = Application::GetInstance()->GetDevice()->getTimer()->getRealTime();
    int totalIdle = 0;
    int totalUsed = 0;
    int totalNodes = 0;
    int averageUsage;
    int totalMinimum = 0;
    for (; it != self->poolsLast; ++it) {
        const SceneNodeReportPool* pool = *it;
        const SceneNodeReportNode* const* node = pool->nodesFirst;
        SceneNodeReportNode* const* const end = pool->nodesLast;
        unsigned int used = 0;
        for (; node != end; ++node) {
            if (!(*node)->available)
                ++used;
        }
        const int size = pool->nodesLast - pool->nodesFirst;
        totalNodes += size;
        totalMinimum += pool->constructedCount;
        unsigned int usage = 0;
        if (size) {
            totalUsed += used;
            usage = used * 100 / size;
        }
        unsigned int idle = 0;
        if (pool->activeCount < size) {
            idle = (now - pool->lastResizeTime) / 1000;
            totalIdle += idle;
        }
        printf("| %04d    %04d    %04d    %3d%%    %3ds    %s\n", poolCount, size,
            pool->constructedCount, usage, idle, pool->name);
        ++poolCount;
    }
    averageUsage = 0;
    // Branch-likelihood hint: restores retail's block order after the call
    // heuristic below would otherwise mark this branch as less likely.
    if (__builtin_expect(totalNodes > 0, 1)) {
        averageUsage = totalUsed * 100 / totalNodes;
        totalIdle /= totalNodes;
        // Always adds 0 (folded after jump threading). It gives totalMinimum its
        // own merge here, so the zero-pools path stores the totals in retail's order.
        totalMinimum += __builtin_constant_p(totalNodes);
    }
    printf("+---- TOTALS -------------------------------------------------------------------\n");
    printf("| Pools   Nodes   Minimum Usage   IdleAVG\n");
    printf("| %04d    %04d    %04d    %3d%%    %3ds\n", poolCount, totalNodes, totalMinimum,
        averageUsage, totalIdle);
    printf("+-- SceneNodeManager Report - END ----------------------------------------------\n\n");
}

struct RGNode {
    bool available;
    void* sceneNode;
    void** parameters;
    unsigned int unknown12;
};
struct RGPool {
    const char* name;
    void* factory;
    int requestedSize;
    unsigned int lastResizeTime;
    int activeCount;
    int constructedCount;
    RGNode** nodesFirst;
    RGNode** nodesLast;
    RGNode** nodesLimit;
    RGNode** begin() { return nodesFirst; }
    unsigned int size() const { return unsigned(nodesLast - nodesFirst); }
    void pop_back() { --nodesLast; }
    RGNode*& operator[](unsigned int index) { return *(begin() + index); }
};
struct RGManager {
    unsigned char poolIndex[24];
    RGPool* const* poolsFirst;
    RGPool* const* poolsLast;
    RGPool* const* begin() const { return poolsFirst; }
    RGPool* const* end() const { return poolsLast; }
};
extern "C" void _ZN16SceneNodeManager4NodeD1Ev(RGNode* node);

// Header-free view of SceneNodeManager::reclaimGarbage. The control flow is
// rearranged without changing behaviour (all tests are side-effect free):
// the inner loop is laid out before the time test so its poolsLast exit
// splits come in retail order, and the size test is hoisted to the loop head.
extern "C" void _ZN16SceneNodeManager14reclaimGarbageEv(RGManager* self)
{
    const unsigned int now = Application::GetInstance()->GetDevice()->getTimer()->getRealTime();
    for (RGPool* const* it = self->begin(); it != self->end(); ++it) {
        RGPool* pool = *it;
        int size = pool->size();
        if (!(size > pool->constructedCount))
            continue;
        goto tests;
    inner:
        {
            int i = 0;
            goto check;
            for (;;) {
                {
                    RGNode* node = (*pool)[i];
                    if (now - node->unknown12 > 60000) {
                    _ZN16SceneNodeManager4NodeD1Ev(node);
                    ::operator delete(node);
                    (*pool)[i] = (*pool)[size - pool->activeCount - 1];
                    (*pool)[size - pool->activeCount - 1] = (*pool)[size - 1];
                    --size;
                    // No-code hint: identical arms (crossjumped after reload) whose
                    // test takes one reload, setting reload's register rotation.
                    if ((int)now < 0) pool->pop_back(); else pool->pop_back();
                    --i;
                    }
                }
                ++i;
            check:
                if (!(i < size && (*pool)[i]->available && size > pool->constructedCount))
                    break;
            }
            continue;
        }
    tests:
        if (now - pool->lastResizeTime > 60000) {
            // No-code hint: identical arms (crossjumped, selector deleted); the
            // compare takes one reload, one rotation step as in retail. The
            // `0 < size` test repeats the loop's first `i < size` check.
            if ((int)now < 0) { if (!(0 < size)) continue; } else { if (!(0 < size)) continue; }
            goto inner;
        }
    }
}
