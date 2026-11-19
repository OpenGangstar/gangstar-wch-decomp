/*
 * SaveGame
 *
 * Original file: SaveGame.cpp
 * Area:          persistence
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of SaveGame.cpp here, in the order they appear in the library.
 */

#include "../core/LocalStartupText.h"
#include "SaveGame.h"
#include "../core/LocalStartupStorage.h"
#include "DataStream.h"
#include "FileSystemBase.h"
#include "FileStream.h"
#include "SaveGameInterfaces.h"
#include "../app/Application.h"
#include "../core/NativeStdio.h"

static const char filenameFormat[] __attribute__((section(".rodata.filename_format"))) = "%s%s";
static const char filename[] __attribute__((section(".rodata.save_filename"))) = "Gangstar2.sav";

void SaveGame::SampleObject(LevelObject*) {}

int SaveGame::BlockV3D::Size() const { return Block::Size() + 12; }
int SaveGame::BlockAmmo::Size() const { return Block::Size() + 12; }
int SaveGame::BlockWeapon::Size() const { return Block::Size() + 17; }

void SaveGame::BlockV3D::Write(DataStream* stream) const
{
    Block::Write(stream);
    stream->WriteFloat(x);
    stream->WriteFloat(y);
    stream->WriteFloat(z);
}

void SaveGame::BlockV3D::Read(DataStream* stream)
{
    Block::Read(stream);
    x = stream->ReadFloat();
    y = stream->ReadFloat();
    z = stream->ReadFloat();
}

void SaveGame::BlockAmmo::Write(DataStream* stream) const
{
    Block::Write(stream);
    stream->WriteInt(type);
    stream->WriteInt(context);
    stream->WriteInt(count);
}

void SaveGame::BlockAmmo::Read(DataStream* stream)
{
    Block::Read(stream);
    type = stream->ReadInt();
    context = stream->ReadInt();
    count = stream->ReadInt();
}

void SaveGame::BlockWeapon::Write(DataStream* stream) const
{
    Block::Write(stream);
    stream->WriteInt(weaponId);
    stream->WriteInt(clipSize);
    stream->WriteInt(clip);
    stream->WriteInt(context);
    stream->WriteByte(locked);
}

void SaveGame::BlockWeapon::Read(DataStream* stream)
{
    Block::Read(stream);
    weaponId = stream->ReadInt();
    clipSize = stream->ReadInt();
    clip = stream->ReadInt();
    context = stream->ReadInt();
    locked = stream->ReadByte();
}

const char* SaveGame::GetDefaultFilename()
{
    static char saveGameFile[256];
    if (!saveGameFile[0]) {
        sprintf(saveGameFile, filenameFormat, Application::GetInstance()->GetFileSystem()->getSaveFilesPath(), filename);
    }
    return saveGameFile;
}

SaveGame::~SaveGame() {}
SaveGame::SaveGame() {}

bool SaveGame::LoadAndApply(const char* name)
{
    FileStream file(name, 1);
    if (!file.IsValid()) return false;
    DataStream stream(file, DataStream::LittleEndian);
    SetDataStream(&stream);
    WeaponManager* weapons = 0;
    if (GSLoading::isGameLoaded()) weapons = Application::GetInstance()->GetWeaponManager();
    AchievementManager* achievements = AchievementManager::s_achievementManager;
    bool result = false;
    if (file.Size() > 0) {
        if (GSLoading::isGameLoaded()) {
            ScriptManager::getInstance()->resetGame(true, -1);
            weapons->lockAllWeapons();
        }
        Block header;
        result = true;
        while (result && PeekBlock(header)) {
            switch (header.id) {
            default: result = true; break;
            case -1: {
                BlockInt block;
                result = ReadBlock(block);
                break;
            }
            case 0: {
                BlockInt block;
                result = ReadBlock(block);
                if (result && GSLoading::isGameLoaded()) {
                    Script* script = ScriptManager::getInstance()->findScript(block.value);
                    if (script) script->setState(Script::State2, PlayerTest::AnyContext);
                }
                break;
            }
            case 1: {
                BlockInt block;
                result = ReadBlock(block);
                if (result && GSLoading::isGameLoaded()) PlayerTest::GetPlayer()->setCash(block.value);
                break;
            }
            case 2: {
                BlockWeapon block;
                result = ReadBlock(block);
                if (result && GSLoading::isGameLoaded()) {
                    Weapon* weapon = weapons->getWeaponInList(block.weaponId, static_cast<PlayerTest::eContext>(block.context));
                    weapon->setClip(block.clip);
                    weapon->setClipSize(block.clipSize);
                    if (!block.locked) weapon->unlock();
                }
                break;
            }
            case 3: {
                BlockAmmo block;
                result = ReadBlock(block);
                if (result && GSLoading::isGameLoaded()) weapons->setAmmo(block.type, block.count, static_cast<PlayerTest::eContext>(block.context));
                break;
            }
            case 4: {
                BlockV3D block;
                result = ReadBlock(block);
                if (result && GSLoading::isGameLoaded()) {
                    SaveVector3 position(block.x, block.y, block.z);
                    PlayerTest::GetPlayer()->SetPosition(reinterpret_cast<const irr::core::vector3d<float>&>(position));
                    PlayerTest::GetPlayer()->Respawn();
                }
                break;
            }
            case 5: {
                BlockString block;
                result = ReadBlock(block);
                break;
            }
            case 6: {
                BlockInt block;
                result = ReadBlock(block);
                if (result && GSLoading::isGameLoaded()) {
                    Checkpoint::s_bTutoCallContact = false;
                    if (block.value > 0) Checkpoint::s_bTutoCallContact = true;
                }
                break;
            }
            case 7: {
                BlockInt block;
                result = ReadBlock(block);
                if (result && GSLoading::isGameLoaded()) {
                    WantedLevelManager::s_bTutoWantedLevel = false;
                    if (block.value > 0) WantedLevelManager::s_bTutoWantedLevel = true;
                }
                break;
            }
            case 8: {
                BlockIntPair block;
                result = ReadBlock(block);
                if (result && block.first < AchievementManager::s_statCount) {
                    AchievementManager::s_stats[block.first].value = block.second;
                    AchievementManager::s_achievementManager->updateStat(block.first);
                }
                break;
            }
            case 9: {
                BlockInt block;
                result = ReadBlock(block);
                if (result && GSLoading::isGameLoaded()) {
                    GSFailure::s_bCutsceneDie = false;
                    if (block.value > 0) GSFailure::s_bCutsceneDie = true;
                }
                break;
            }
            case 10: {
                BlockInt block;
                result = ReadBlock(block);
                if (result && GSLoading::isGameLoaded()) {
                    GSFailure::s_bCutsceneBusted = false;
                    if (block.value > 0) GSFailure::s_bCutsceneBusted = true;
                }
                break;
            }
            case 11: {
                BlockInt block;
                result = ReadBlock(block);
                if (result && GSLoading::isGameLoaded()) {
                    GSFailure::s_bCutsceneMissionFailed = false;
                    if (block.value > 0) GSFailure::s_bCutsceneMissionFailed = true;
                }
                break;
            }
            case 12: {
                BlockInt block;
                result = ReadBlock(block);
                if (result && GSLoading::isGameLoaded()) PlayerTest::GetPlayer()->switchContext(static_cast<PlayerTest::eContext>(block.value), false);
                break;
            }
            case 13: {
                BlockInt block;
                result = ReadBlock(block);
                if (result && GSLoading::isGameLoaded()) weapons->limitToWeapon(block.value, PlayerTest::AnyContext);
                break;
            }
            case 14: {
                BlockInt block;
                result = ReadBlock(block);
                if (result && GSLoading::isGameLoaded()) PlayerTest::GetPlayer()->flag383 = true;
                break;
            }
            case 15: {
                BlockIntPair block;
                result = ReadBlock(block);
                if (result && GSLoading::isGameLoaded()) {
                    Script* script = ScriptManager::getInstance()->findScript(block.first);
                    if (script) script->setState(Script::State2, static_cast<PlayerTest::eContext>(block.second));
                }
                break;
            }
            case 16: {
                BlockInt block;
                result = ReadBlock(block);
                if (result) achievements->completeAchievement(block.value);
                break;
            }
            case 17: {
                BlockIntPair block;
                result = ReadBlock(block);
                if (result && GSLoading::isGameLoaded()) {
                    PlayerTest* player = PlayerTest::GetPlayer();
                    int& value = player->contextValues[player->context];
                    value = block.second;
                    if (value > 200) value = 200;
                }
                break;
            }
            case 18: {
                BlockInt block;
                result = ReadBlock(block);
                if (result && GSLoading::isGameLoaded()) {
                    CControlManager::s_cameraTutorial = false;
                    if (block.value > 0) CControlManager::s_cameraTutorial = true;
                }
                break;
            }
            case 19: {
                BlockInt block;
                result = ReadBlock(block);
                if (result && GSLoading::isGameLoaded()) {
                    CControlManager::s_sniperTutorial = false;
                    if (block.value > 0) CControlManager::s_sniperTutorial = true;
                }
                break;
            }
            }
        }
        AchievementManager* completed = AchievementManager::s_achievementManager;
        while (completed->hasNewCompletedAchievements()) completed->popCompletedAchievement();
    }
    SetDataStream(0);
    file.Close();
    return result;
}

void operator delete(void*) throw();
extern "C" {
static void __tcf_4() __attribute__((used));
static void __tcf_4()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_savegame_transitions {
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_4), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_savegame_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_savegame_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_savegame_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_savegame_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_savegame_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_savegame_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_savegame_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_savegame_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_savegame_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_savegame_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN8SaveGameC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN8SaveGameC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}
