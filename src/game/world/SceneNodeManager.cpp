/*
 * SceneNodeManager
 *
 * Original file: SceneNodeManager.cpp
 * Area:          world
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of SceneNodeManager.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "SceneNodeManager.h"
#include "../core/NativeStdio.h"
#include "../app/Application.h"
#include "../core/SceneNode.h"
#include "../core/Collada.h"

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

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
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
