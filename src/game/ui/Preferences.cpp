/*
 * Preferences
 *
 * Original file: Preferences.cpp
 * Area:          ui
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Preferences.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_preferences_transitions {
extern const unsigned int civPassive_trans[] __attribute__((visibility("hidden")));
extern const unsigned int scriptedNpc_trans[] __attribute__((visibility("hidden")));
extern const unsigned int civAggressive_trans[] __attribute__((visibility("hidden")));
extern const unsigned int gangMember_trans[] __attribute__((visibility("hidden")));
extern const unsigned int cop_trans[] __attribute__((visibility("hidden")));
extern const unsigned int swat_trans[] __attribute__((visibility("hidden")));
extern const unsigned int civ_vehicle_trans[] __attribute__((visibility("hidden")));
extern const unsigned int cop_vehicle_trans[] __attribute__((visibility("hidden")));
extern const unsigned int guard_trans[] __attribute__((visibility("hidden")));
extern const unsigned int scripted_vehicle_trans[] __attribute__((visibility("hidden")));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_3()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_preferences_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_preferences_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_preferences_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_preferences_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_preferences_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_preferences_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_preferences_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_preferences_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_preferences_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_preferences_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN11PreferencesC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN11PreferencesC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

#include "../persistence/Persistence.h"
#include "../persistence/FileStream.h"

#include "Preferences.h"

bool Preferences::Exist(const char* name)
{
    FileStream file;
    return file.Exist(name);
}

Preferences::Preferences()
{
}

#include "../app/Application.h"
#include "../persistence/FileSystemBase.h"
#include "../core/NativeStdio.h"

static const char preferenceFilenameFormat[] = "%s%s";
static const char preferenceFilename[] = "Gangstar2.preferences";

const char* Preferences::GetDefaultFilename()
{
    static char preferenceFile[256];
    if (!preferenceFile[0])
        sprintf(preferenceFile, preferenceFilenameFormat,
            Application::GetInstance()->GetFileSystem()->getSaveFilesPath(), preferenceFilename);
    return preferenceFile;
}

Preferences::~Preferences()
{
}


#include "../persistence/DataStream.h"
#include "OptionGameSettings.h"
#include "../app/Application.h"
#include "../audio/SoundManager.h"
#include "../hud/CHudManager.h"
#include "../scripting/ScriptManager.h"

extern "C" void _ZN10DataStreamD1Ev(void*) __attribute__((weak));
extern "C" void _ZN11Persistence8BlockIntD1Ev(void*) __attribute__((weak));

namespace {
struct StringPreferenceFields {
    unsigned char unknown0[4];
    int observed4;
};
}

bool Preferences::SampleAndSave(const char* name)
{
    FileStream file(name, 32);
    if (!file.IsValid())
        return false;
    unsigned int dataStorage[sizeof(DataStream) / sizeof(unsigned int)];
    DataStream& data = *new (dataStorage) DataStream(file, DataStream::LittleEndian);
    SetDataStream(&data);
    unsigned int blockStorage[sizeof(BlockInt) / sizeof(unsigned int)];
    BlockInt& block = *new (blockStorage) BlockInt;
    CHudManager* hud = Application::GetInstance()->GetHudManager();
    block.id = -1;
    block.value = 0x30500;
    WriteBlock(block);
    block.id = 0;
    block.value = hud->steeringMode;
    WriteBlock(block);
    block.id = 1;
    block.value = hud->throttleMode;
    WriteBlock(block);
    block.id = 2;
    block.value = reinterpret_cast<StringPreferenceFields*>(Application::GetInstance()->GetStringManager())->observed4;
    WriteBlock(block);
    block.id = 3;
    block.value = ScriptManager::getInstance()->unknown78;
    WriteBlock(block);
    block.id = 4;
    block.value = static_cast<int>(100.0f * SoundManager::getInstance()->effectsPlaybackVolume);
    WriteBlock(block);
    block.id = 5;
    block.value = static_cast<int>(100.0f * SoundManager::getInstance()->playbackVolume);
    WriteBlock(block);
    block.id = 6;
    block.value = Menus::OptionGameSettings::GetOrientation();
    WriteBlock(block);
    SetDataStream(0);
    file.Close();
    _ZN11Persistence8BlockIntD1Ev(&block);
    _ZN10DataStreamD1Ev(&data);
    return true;
}

int Preferences::GetOrientation(const char* name)
{
    FileStream file(name, 1);
    if (!file.IsValid())
        return -1;
    DataStream data(file, DataStream::LittleEndian);
    SetDataStream(&data);
    if (file.Size() > 0) {
        BlockInt block;
        for (int i = 0; i < 8; ++i) {
            ReadBlock(block);
            if (block.id == 6)
                return block.value;
        }
    }
    return -1;
}
