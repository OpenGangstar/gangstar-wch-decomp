/*
 * ScriptManager
 *
 * Original file: ScriptManager.cpp
 * Area:          scripting
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of ScriptManager.cpp here, in the order they appear in the library.
 */

#include "../characters/PhysicAttributes.h"
#include "../ui/Shop.h"
#include "../persistence/SaveGameInterfaces.h"
#include "../core/SceneNode.h"
#include "../core/IrrlichtDevice.h"
#include "../core/PointerVector.h"
#include "../world/ResStream.h"
#include "../core/ASprite.h"
#include "../core/Rct.h"
#include "../ui/VirtualButton.h"
#include "../vehicles/Vehicle.h"
#include "../core/VideoDriver.h"
#include "../core/NativeStdio.h"
#include "../core/NativeStrings.h"
#include "../world/GameObjectManager.h"
#include "../ui/WidgetDialog.h"
#include "ScriptManager.h"
#include "../input/TouchScreenBase.h"
#include "Script.h"
#include "../app/Application.h"
#include "../hud/CHudManager.h"
#include "../hud/MiniMap.h"
#include "../world/LevelObject.h"
#include "../hud/HudElement.h"
#include "../hud/MenuManager.h"
#include "../characters/AnimObject.h"
#include "../core/SafeDelete.h"
#include "../missions/Mission.h"
#include "../characters/PlayerTest.h"
#include "../meta/Race.h"
#include "../persistence/SaveGame.h"
#include "../missions/Revive.h"
#include "../persistence/DataStream.h"

extern bool bIsInCutscene;
void operator delete(void*) throw();

ScriptManager::ScriptManager()
{
    paused = false;
    cutsceneSkipped = false;
    unknown78 = true;
    scripts = 0;
    scriptCapacity = 0;
    scriptCount = 0;
    unknown12 = 0;
    cinematicState = 0;
    commandCursor = 0;
    mission = 0;
    revive = 0;
    race = 0;
    unknown84 = 1;
    unknown88 = 0;
    unknown92 = 0;
    unknown100 = -1;
    unknown104 = 0;
}

ScriptManager* ScriptManager::getInstance()
{
    static ScriptManager scrmgr;
    return &scrmgr;
}

#include "../missions/WantedLevelManagerSingleton.h"
#include "../ai/StateMachine.h"

void ScriptManager::resume() { paused = false; }

void ScriptManager::skipBlockingCommands() { ++commandCursor; }

void* ScriptManager::getMission() const { return mission; }

void* ScriptManager::getCinematicsHudSprite() const { return cinematicsHudSprite; }

void* ScriptManager::getRace() const { return race; }

void ScriptManager::taggedKilled()
{
    if (taggedCount > 0)
        --taggedCount;
}

void ScriptManager::printCommand(const Structs::ScriptCommand&) {}

void ScriptManager::addScript(Script* script)
{
    if (scriptCount < scriptCapacity)
        scripts[scriptCount++] = script;
}

Script* ScriptManager::findScript(int id) const
{
    if (id < scriptCount)
        return scripts[id];
    return 0;
}

bool ScriptManager::areBlockingCommandsSkipped() const
{
    return static_cast<int>(commandCursor) > 0;
}

bool ScriptManager::isInCinematic() const
{
    return cinematicState == 1 || cinematicState == 3 || cinematicState == 2 ||
           cinematicState == 4 || cinematicState == 6 || cinematicState == 5;
}

bool ScriptManager::isSkipButtonVisible() const
{
    return skipButton && skipButton->isVisible();
}

int ScriptManager::getFailureCause()
{
    return s_failure;
}

void ScriptManager::finishReviveAnims()
{
    if (revive)
        revive->finishCashLostAnims();
}

void ScriptManager::missionIdle()
{
    if (mission)
        mission->idle();
}

void ScriptManager::drawCinematicBars() const
{
    cinematicBars->Draw();
}

void ScriptManager::missionResumeFadeOut()
{
    if (mission)
        mission->resumeFadeOut();
}

void ScriptManager::missionSkipFadeOut()
{
    if (mission)
        mission->skipFadeOut();
}

void ScriptManager::missionSetFailureCount(int count)
{
    if (mission)
        mission->setFailureCount(count);
}

void ScriptManager::missionClearConditions()
{
    if (mission)
        mission->clearConditions();
}

void ScriptManager::missionFail()
{
    if (mission)
        mission->fail();
}

void ScriptManager::message(int id)
{
    if (mission)
        mission->message(id);
}

void ScriptManager::missionObjective(int id, bool silent)
{
    if (mission)
        mission->objective(id, silent);
}

void ScriptManager::missionStart(int id, int duration)
{
    if (mission)
        mission->start(id, duration);
}

void ScriptManager::missionOver()
{
    if (mission) {
        mission->end();
        bIsInCutscene = false;
    }
}

void ScriptManager::missionRegisterCondition(IMissionCondition* condition)
{
    if (mission)
        mission->registerCondition(condition);
    else if (condition)
        ::operator delete(condition);
}

void ScriptManager::resumeBlockingCommands()
{
    if (static_cast<int>(commandCursor) > 0) {
        if (commandCursor == 1)
            mission->update(0);
        --commandCursor;
    }
}

void ScriptManager::hideSkipButton()
{
    if (skipButton) {
        skipButton->hide();
        MenuManager::getInstance()->setText(MenuManager::SkipButtonText, -1, 0);
    }
}

void ScriptManager::showSkipButton()
{
    if (skipButton) {
        skipButton->show();
        MenuManager::getInstance()->setText(MenuManager::SkipButtonText, 4136, 0);
    }
}

void ScriptManager::skipCutscene()
{
    if (cutsceneSkipped || !isInCinematic())
        return;
    hideSkipButton();
    skipBlockingCommands();
    cutsceneSkipped = true;
    mission->update(0);
}

ScriptManager::~ScriptManager()
{
    SafeDelete(revive);
}

void ScriptManager::respawnFromBustedOrDie(bool busted)
{
    SafeDelete(revive);
    revive = new Revive(busted);
}

void ScriptManager::saveGame()
{
    SaveGame game;
    game.SampleAndSave(SaveGame::GetDefaultFilename());
}

bool ScriptManager::loadMissions(const char* filename)
{
    if (mission)
        return false;

    race = new Race;
    mission = new Mission;
    mission->load(filename);
    return true;
}

void ScriptManager::loadGame(bool reset)
{
    PlayerTest::GetPlayer()->setAnimation("move_idle", 1, false, false, false);
    SaveGame game;
    if (reset || !game.LoadAndApply(SaveGame::GetDefaultFilename()))
        getInstance()->resetGame(false, -1);
}


void ScriptManager::displayOnMinimap(LevelObject* object, bool visible, bool flag)
{
    CHudManager* hud = Application::GetInstance()->GetHudManager();
    const unsigned int trackedOnMinimap = 32;
    if (visible) {
        if (object->unknown4 & trackedOnMinimap)
            return;

        MiniMap* map = static_cast<MiniMap*>(hud->minimap);
        if (map)
            map->registerForMapTracking(object, flag);
        object->unknown4 |= trackedOnMinimap;
    } else {
        object->unknown4 &= ~trackedOnMinimap;
        MiniMap* map = static_cast<MiniMap*>(hud->minimap);
        if (map)
            map->deregisterForMapTracking(object);
    }
}

LevelObject* ScriptManager::getFirstAvailableCheckpoint() const
{
    for (int i = 0; i < scriptCount; ++i) {
        if (scripts[i]->getState() != Script::State2)
            continue;
        Structs::ScriptCommand* command = scripts[i]->peekCommand(0);
        if (command && (command->opcode == 64 || command->opcode == 105))
            return static_cast<LevelObject*>(scripts[i]->getSource());
    }
    return 0;
}

namespace Structs {

struct WaitWantedLevel {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void WaitWantedLevel::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct WaitStolen {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void WaitStolen::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct WaitShot {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void WaitShot::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct WaitPathEnded {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void WaitPathEnded::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct WaitKilled {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void WaitKilled::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct WaitForStop {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void WaitForStop::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct WaitForLock {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void WaitForLock::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct WaitCheckpoint {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

struct WaitCheckpointCar : WaitCheckpoint {
    char* argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void WaitCheckpointCar::Read(DataStream& stream)
{
    WaitCheckpoint::Read(stream);
    argument2 = stream.ReadAndAllocateString();
}

inline void WaitCheckpoint::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct Wait {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void Wait::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct UnlockShop {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void UnlockShop::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct UnlockScript {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void UnlockScript::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct TagForKill {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void TagForKill::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct StopSfx {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void StopSfx::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct StopObject {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void StopObject::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct StopMusic {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void StopMusic::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct StartRace {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void StartRace::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct SetWantedLevel {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void SetWantedLevel::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct SetPhotoTarget {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void SetPhotoTarget::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct SetMe {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void SetMe::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct SetDecal {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void SetDecal::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct Release {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void Release::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct RaiseWantedLevel {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void RaiseWantedLevel::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct PlaySfx {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void PlaySfx::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct PlayScript {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void PlayScript::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct PlayMusic {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void PlayMusic::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}


inline void MissionStart::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct MissionObjective {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void MissionObjective::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct LockShop {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void LockShop::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct LockScript {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void LockScript::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct LimitToWeapon {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void LimitToWeapon::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct KillNPC {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void KillNPC::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct HudHighlight {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void HudHighlight::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct GiveWeapon {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void GiveWeapon::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct FlagAsInRace {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void FlagAsInRace::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct FadeOut {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void FadeOut::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct FadeIn {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void FadeIn::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct DropWantedLevel {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void DropWantedLevel::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct Disable {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void Disable::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct DestroyCar {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void DestroyCar::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct DebugScript {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void DebugScript::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct CamDefault {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void CamDefault::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct BeQuick {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

struct SetUsUpTheBomb : BeQuick {
    char* argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void SetUsUpTheBomb::Read(DataStream& stream)
{
    BeQuick::Read(stream);
    argument2 = stream.ReadAndAllocateString();
}

inline void BeQuick::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadInt();
}

struct AttackAsGood {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void AttackAsGood::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct AttackAsBad {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void AttackAsBad::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct ActorStopFollow {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void ActorStopFollow::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct ActorLoopPath {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void ActorLoopPath::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

struct ActorGetOut {
    int opcode;
    char* argument;
    void Read(DataStream& stream) __attribute__((used));
};

inline void ActorGetOut::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument = stream.ReadAndAllocateString();
}

} // namespace Structs

namespace Structs {

struct WaitIfNotPhotographed {
    int opcode;
    char* argument1;
    int argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void WaitIfNotPhotographed::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadInt();
}

struct WaitEscape {
    int opcode;
    char* argument1;
    int argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void WaitEscape::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadInt();
}

struct VehicleChasePlayer {
    int opcode;
    char* argument1;
    char* argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void VehicleChasePlayer::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadAndAllocateString();
}

struct StayWithin {
    int opcode;
    char* argument1;
    int argument2;
    int argument3;
    void Read(DataStream& stream) __attribute__((used));
};

inline void StayWithin::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadInt();
    argument3 = stream.ReadInt();
}

struct SpyTarget {
    int opcode;
    char* argument1;
    int argument2;
    int argument3;
    void Read(DataStream& stream) __attribute__((used));
};

inline void SpyTarget::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadInt();
    argument3 = stream.ReadInt();
}

struct ShowTutorial {
    int opcode;
    int argument1;
    int argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void ShowTutorial::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadInt();
    argument2 = stream.ReadInt();
}

struct SetAnimSpeed {
    int opcode;
    char* argument1;
    int argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void SetAnimSpeed::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadInt();
}

struct SetAnim2 {
    int opcode;
    char* argument1;
    char* argument2;
    char* argument3;
    void Read(DataStream& stream) __attribute__((used));
};

inline void SetAnim2::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadAndAllocateString();
    argument3 = stream.ReadAndAllocateString();
}

struct SetAnim {
    int opcode;
    char* argument1;
    char* argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void SetAnim::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadAndAllocateString();
}

struct ProtectNPC {
    int opcode;
    int argument1;
    char* argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void ProtectNPC::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadInt();
    argument2 = stream.ReadAndAllocateString();
}

struct ProtectCar {
    int opcode;
    char* argument1;
    int argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void ProtectCar::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadInt();
}

struct PlaceItem {
    int opcode;
    int argument1;
    char* argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void PlaceItem::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadInt();
    argument2 = stream.ReadAndAllocateString();
}

struct PhotographQuickly {
    int opcode;
    char* argument1;
    int argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void PhotographQuickly::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadInt();
}

struct NPCWeapon {
    int opcode;
    char* argument1;
    int argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void NPCWeapon::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadInt();
}

struct MoveTo {
    int opcode;
    char* argument1;
    char* argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void MoveTo::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadAndAllocateString();
}

struct Enable {
    int opcode;
    char* argument1;
    char* argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void Enable::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadAndAllocateString();
}

struct Dialog {
    int opcode;
    int argument1;
    int argument2;
    int argument3;
    void Read(DataStream& stream) __attribute__((used));
};

inline void Dialog::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadInt();
    argument2 = stream.ReadInt();
    argument3 = stream.ReadInt();
}

struct CarSetSpeed {
    int opcode;
    char* argument1;
    int argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void CarSetSpeed::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadInt();
}

struct CarSetPath {
    int opcode;
    char* argument1;
    char* argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void CarSetPath::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadAndAllocateString();
}

struct CarDriveTo {
    int opcode;
    char* argument1;
    char* argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void CarDriveTo::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadAndAllocateString();
}

struct CamSet {
    int opcode;
    char* argument1;
    int argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void CamSet::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadInt();
}

struct AddRacer {
    int opcode;
    char* argument1;
    int argument2;
    char* argument3;
    void Read(DataStream& stream) __attribute__((used));
};

inline void AddRacer::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadInt();
    argument3 = stream.ReadAndAllocateString();
}

struct ActorWalkTo {
    int opcode;
    char* argument1;
    char* argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void ActorWalkTo::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadAndAllocateString();
}

struct ActorWalkPath {
    int opcode;
    char* argument1;
    char* argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void ActorWalkPath::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadAndAllocateString();
}

struct ActorRunTo {
    int opcode;
    char* argument1;
    char* argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void ActorRunTo::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadAndAllocateString();
}

struct ActorRunPath {
    int opcode;
    char* argument1;
    char* argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void ActorRunPath::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadAndAllocateString();
}

struct ActorGetIn {
    int opcode;
    char* argument1;
    char* argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void ActorGetIn::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadAndAllocateString();
}

struct ActorFollow {
    int opcode;
    char* argument1;
    char* argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void ActorFollow::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadAndAllocateString();
}

struct ActorAttack {
    int opcode;
    char* argument1;
    char* argument2;
    void Read(DataStream& stream) __attribute__((used));
};

inline void ActorAttack::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
    argument1 = stream.ReadAndAllocateString();
    argument2 = stream.ReadAndAllocateString();
}

} // namespace Structs

// Recovered module startup family; storage remains local to this TU.
#include "../core/LocalStartupStorage.h"

#include "../core/LocalStartupText.h"
void operator delete(void*) throw();
extern "C" {
static void __tcf_6() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_scriptmanager_transitions {
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
static void __tcf_6()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_6), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_scriptmanager_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_scriptmanager_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_scriptmanager_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_scriptmanager_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_scriptmanager_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_scriptmanager_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_scriptmanager_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_scriptmanager_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_scriptmanager_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_scriptmanager_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN13ScriptManager12s_playerTestE() __attribute__((used));
static void _GLOBAL__I__ZN13ScriptManager12s_playerTestE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

void ScriptManager::cleanCommand(Structs::ScriptCommand* command)
{
    switch (command->opcode) {
    case 0:
    case 5:
    case 8:
    case 9:
    case 12:
    case 22:
    case 23:
    case 33: {
        Structs::WaitCheckpoint* args = reinterpret_cast<Structs::WaitCheckpoint*>(command);
        delete[] args->argument;
        args->argument = 0;
        break;
    }
    case 6:
    case 21: {
        Structs::SetAnim* args = reinterpret_cast<Structs::SetAnim*>(command);
        delete[] args->argument2;
        args->argument2 = 0;
        delete[] args->argument1;
        args->argument1 = 0;
        break;
    }
    case 7: {
        Structs::SetAnim2* args = reinterpret_cast<Structs::SetAnim2*>(command);
        delete[] args->argument3;
        args->argument3 = 0;
        delete[] args->argument1;
        args->argument1 = 0;
        delete[] args->argument2;
        args->argument2 = 0;
        break;
    }
    case 24: {
        Structs::SetAnim* args = reinterpret_cast<Structs::SetAnim*>(command);
        delete[] args->argument2;
        args->argument2 = 0;
        delete[] args->argument1;
        args->argument1 = 0;
        break;
    }
    case 25: {
        Structs::SetAnim* args = reinterpret_cast<Structs::SetAnim*>(command);
        delete[] args->argument1;
        args->argument1 = 0;
        delete[] args->argument2;
        args->argument2 = 0;
        break;
    }
    case 26: {
        Structs::SetAnim* args = reinterpret_cast<Structs::SetAnim*>(command);
        delete[] args->argument1;
        args->argument1 = 0;
        delete[] args->argument2;
        args->argument2 = 0;
        break;
    }
    case 29:
    case 32:
    case 34:
    case 35:
    case 38:
    case 52: {
        Structs::SetAnim* args = reinterpret_cast<Structs::SetAnim*>(command);
        delete[] args->argument1;
        args->argument1 = 0;
        delete[] args->argument2;
        args->argument2 = 0;
        break;
    }
    case 36:
    case 39:
    case 44:
    case 45:
    case 49: {
        Structs::WaitCheckpoint* args = reinterpret_cast<Structs::WaitCheckpoint*>(command);
        delete[] args->argument;
        args->argument = 0;
        break;
    }
    case 53: {
        Structs::WaitCheckpoint* args = reinterpret_cast<Structs::WaitCheckpoint*>(command);
        delete[] args->argument;
        args->argument = 0;
        break;
    }
    case 55: {
        Structs::SetAnim* args = reinterpret_cast<Structs::SetAnim*>(command);
        delete[] args->argument1;
        args->argument1 = 0;
        delete[] args->argument2;
        args->argument2 = 0;
        break;
    }
    case 64: {
        Structs::WaitCheckpoint* args = reinterpret_cast<Structs::WaitCheckpoint*>(command);
        delete[] args->argument;
        args->argument = 0;
        break;
    }
    case 69: {
        Structs::ProtectNPC* args = reinterpret_cast<Structs::ProtectNPC*>(command);
        delete[] args->argument2;
        args->argument2 = 0;
        break;
    }
    case 70:
    case 71:
    case 76: {
        Structs::WaitCheckpoint* args = reinterpret_cast<Structs::WaitCheckpoint*>(command);
        delete[] args->argument;
        args->argument = 0;
        break;
    }
    case 74:
    case 83: {
        Structs::ProtectNPC* args = reinterpret_cast<Structs::ProtectNPC*>(command);
        delete[] args->argument2;
        args->argument2 = 0;
        break;
    }
    case 77:
    case 82:
    case 85:
    case 87: {
        Structs::WaitCheckpoint* args = reinterpret_cast<Structs::WaitCheckpoint*>(command);
        delete[] args->argument;
        args->argument = 0;
        break;
    }
    case 88: {
        Structs::WaitCheckpoint* args = reinterpret_cast<Structs::WaitCheckpoint*>(command);
        delete[] args->argument;
        args->argument = 0;
        break;
    }
    case 89: {
        Structs::WaitCheckpoint* args = reinterpret_cast<Structs::WaitCheckpoint*>(command);
        delete[] args->argument;
        args->argument = 0;
        break;
    }
    case 99: {
        Structs::WaitCheckpoint* args = reinterpret_cast<Structs::WaitCheckpoint*>(command);
        delete[] args->argument;
        args->argument = 0;
        break;
    }
    case 100: {
        Structs::WaitCheckpoint* args = reinterpret_cast<Structs::WaitCheckpoint*>(command);
        delete[] args->argument;
        args->argument = 0;
        break;
    }
    case 101: {
        Structs::WaitCheckpoint* args = reinterpret_cast<Structs::WaitCheckpoint*>(command);
        delete[] args->argument;
        args->argument = 0;
        break;
    }
    case 102: {
        Structs::WaitCheckpoint* args = reinterpret_cast<Structs::WaitCheckpoint*>(command);
        delete[] args->argument;
        args->argument = 0;
        break;
    }
    case 103: {
        Structs::AddRacer* args = reinterpret_cast<Structs::AddRacer*>(command);
        delete[] args->argument3;
        args->argument3 = 0;
        delete[] args->argument1;
        args->argument1 = 0;
        break;
    }
    case 105: {
        Structs::SetAnim* args = reinterpret_cast<Structs::SetAnim*>(command);
        delete[] args->argument1;
        args->argument1 = 0;
        delete[] args->argument2;
        args->argument2 = 0;
        break;
    }
    case 37: {
        Structs::VehicleChasePlayer* args = reinterpret_cast<Structs::VehicleChasePlayer*>(command);
        delete[] args->argument1;
        args->argument1 = 0;
        delete[] args->argument2;
        args->argument2 = 0;
        break;
    }
    case 106: {
        Structs::WaitCheckpoint* args = reinterpret_cast<Structs::WaitCheckpoint*>(command);
        delete[] args->argument;
        args->argument = 0;
        break;
    }
    case 107: {
        Structs::WaitCheckpoint* args = reinterpret_cast<Structs::WaitCheckpoint*>(command);
        delete[] args->argument;
        args->argument = 0;
        break;
    }
    case 108: {
        Structs::WaitCheckpoint* args = reinterpret_cast<Structs::WaitCheckpoint*>(command);
        delete[] args->argument;
        args->argument = 0;
        break;
    }
    case 114: {
        Structs::SetPhotoTarget* args = reinterpret_cast<Structs::SetPhotoTarget*>(command);
        delete[] args->argument;
        break;
    }
    case 115: {
        Structs::WaitCheckpoint* args = reinterpret_cast<Structs::WaitCheckpoint*>(command);
        delete[] args->argument;
        args->argument = 0;
        break;
    }
    case 116: {
        Structs::WaitCheckpoint* args = reinterpret_cast<Structs::WaitCheckpoint*>(command);
        delete[] args->argument;
        args->argument = 0;
        break;
    }
    case 117: {
        Structs::WaitCheckpoint* args = reinterpret_cast<Structs::WaitCheckpoint*>(command);
        delete[] args->argument;
        args->argument = 0;
        break;
    }

    }
}
void ScriptManager::freezeRunningScripts(const Script* script, PlayerTest::eContext context)
{
    unsigned int targetContext = context;
    if (targetContext == static_cast<unsigned int>(PlayerTest::AnyContext))
        targetContext = PlayerTest::GetPlayer()->contextWord;

    for (int i = 0; i < scriptCount; ++i) {
        if (scripts[i] != script && scripts[i]->getState() == Script::State2 &&
            scripts[i]->contextWord == targetContext) {
            const int opcode = scripts[i]->peekCommand(0)->opcode;
            if ((opcode == 64 || opcode == 105) && scripts[i]->source) {
                displayOnMinimap(scripts[i]->source, false, true);
                scripts[i]->unsetScriptObjectAction(scripts[i]->source, Script::MinimapObject);
                scripts[i]->source->disable();
                scripts[i]->unsetScriptObjectAction(scripts[i]->source, Script::ActiveObject);
                scripts[i]->source = 0;
                scripts[i]->unknown72 = 0;
            }
            scripts[i]->setState(Script::State1, PlayerTest::AnyContext);
        }
    }
}

void ScriptManager::unlockFrozenScripts()
{
    const int context = PlayerTest::GetPlayer()->contextWord;
    for (int i = 0; i < scriptCount; ++i) {
        if (scripts[i]->getState() == Script::State1 && scripts[i]->contextWord == context)
            scripts[i]->setState(Script::State2, PlayerTest::AnyContext);
    }
}

void ScriptManager::pause()
{
    paused = true;
    if (unknown104) {
        unknown104 = 0;
        MenuManager::getInstance()->getWidgetByIndex(10)->Hide(true);
    }
}

void ScriptManager::playerDrives(Vehicle* vehicle)
{
    if (!vehicle || isInCinematic()) {
        vehicleNameAnimation->SetAnim(-1);
        vehicleNameTimer = 0;
        MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(0), -1, 0);
    } else if (vehicle->vehicleIndex != -1) {
        vehicleNameAnimation->SetAnim(25);
        vehicleNameTimer = 3000;
    }
}

void ScriptManager::drawFade() const
{
    Application* app = Application::GetInstance();
    irr::video::IVideoDriver* driver = app->GetDevice()->getVideoDriver();
    int width, height;
    app->GetScreenDimensions(width, height);
    driver->draw2DRectangle(irr::video::SColor(static_cast<unsigned char>(s_fadeIntensity), 0, 0, 0),
        irr::core::rect<int>(0, 0, width, height));
}

template void SafeDelete<Script>(Script*&);

extern "C" int sWindowWidth;

static const char introSpriteFile[] __attribute__((section(".rodata.script_setup_intro"))) = "./intro.bsprite";
static const char cinematicHudFile[] __attribute__((section(".rodata.script_setup_hud"))) = "./cinematics_hud.bsprite";
static const char cinematicHudFile2[] __attribute__((section(".rodata.script_setup_hud2"))) = "./cinematics_hud_2.bsprite";
static const char cinematicCharacterFile[] __attribute__((section(".rodata.script_setup_character"))) = "./cinematics_char.bsprite";

void ScriptManager::setup()
{
    ASprite* intro = new ASprite(introSpriteFile);
    introSprite = intro;
    intro->MakeImage(0, 0);
    introSprite->unknown33 = false;

    AnimObject* introAnim = new AnimObject();
    introAnimation = introAnim;
    introAnim->sprite = introSprite;
    introAnimation->SetPosition(0.0f, 0.0f, 0.0f);

    AnimObject* vehicleName = new AnimObject();
    vehicleNameAnimation = vehicleName;
    vehicleName->sprite = Application::GetInstance()->GetHudManager()->reviveSprite;
    vehicleNameAnimation->SetPosition(0.0f, 0.0f, 0.0f);

    if (sWindowWidth > 800)
        cinematicsHudSprite = new ASprite(cinematicHudFile);
    else
        cinematicsHudSprite = new ASprite(cinematicHudFile2);
    cinematicsHudSprite->MakeImage(0, 0);
    cinematicsHudSprite->unknown33 = false;

    ASprite* character = new ASprite(cinematicCharacterFile);
    cinematicCharacterSprite = character;
    character->MakeImage(0, 0);
    cinematicCharacterSprite->unknown33 = false;

    AnimObject* firstHud = new AnimObject();
    cinematicBars = firstHud;
    firstHud->sprite = cinematicsHudSprite;
    cinematicBars->SetPosition(0.0f, 0.0f, 0.0f);

    AnimObject* secondHud = new AnimObject();
    cinematicHudAnimation2 = secondHud;
    secondHud->sprite = cinematicsHudSprite;
    cinematicHudAnimation2->SetPosition(0.0f, 0.0f, 0.0f);

    AnimObject* characterAnimation = new AnimObject();
    cinematicCharacterAnimation = characterAnimation;
    characterAnimation->sprite = cinematicCharacterSprite;
    cinematicCharacterAnimation->SetPosition(0.0f, 0.0f, 0.0f);

    VirtualButton* button = new VirtualButton(cinematicsHudSprite, 1, static_cast<EvVButton::ButtonType::Type>(18), false);
    skipButton = button;
    button->hide();
}

void ScriptManager::rewindRunningScripts()
{
    s_fadeTime = -999;
    s_fadeIntensity = -999;
    const int targetContext = s_playerTest->contextWord;

    for (int i = 0; i < scriptCount; ++i) {
        if (scripts[i]->contextWord != targetContext)
            continue;

        switch (scripts[i]->getState()) {
        case Script::State2:
            scripts[i]->rewind();
            if (scripts[i]->getParent())
                scripts[i]->setState(Script::State0, PlayerTest::AnyContext);
            break;
        case Script::WaitingForChild:
        case Script::State1:
            scripts[i]->rewind();
            scripts[i]->setState(Script::State2, PlayerTest::AnyContext);
            break;
        default:
            break;
        }
    }
    mission->idle();
}

static const char scriptFindPlayer[] __attribute__((section(".rodata.script_find_player"))) = "Player";
static const char scriptFindMe[] __attribute__((section(".rodata.script_find_me"))) = "Me";
static const char scriptFindWarning[] __attribute__((section(".rodata.script_find_warning"))) =
    "!!! WARNING: Object does not exist: %s !!!\n";

LevelObject* ScriptManager::findObject(const char* name, bool respawnDead)
{
    if (strcmp(name, scriptFindPlayer) == 0)
        return reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(s_playerTest));
    if (strcmp(name, scriptFindMe) == 0)
        return s_me;

    LevelObject* object = GameObjectManager::s_gom->GetGameObjectByName(name, respawnDead);
    if (!object)
        printf(scriptFindWarning, name);
    return object;
}

void ScriptManager::loadScript(const char* filename, bool loadSave)
{
    ResStream resource(filename, 1);
    DataStream stream(resource, DataStream::BigEndian);
    scriptCapacity = stream.ReadInt();
    if (scriptCapacity > 0) {
        scripts = new Script*[scriptCapacity];
        memset(scripts, 0, scriptCapacity * sizeof(*scripts));
    }

    unknown92 = 0;
    for (int i = 0; i < scriptCapacity; ++i) {
        const int commandCount = stream.ReadInt();
        Script* script = new Script(commandCount);
        for (int j = 0; j < commandCount; ++j) {
            const int size = stream.ReadInt();
            const int next = stream.Tell() + size;
            Structs::ScriptCommand* command = loadCommand(stream);
            if (stream.Tell() != next)
                stream.Seek(next, 0);
            if (command)
                script->addCommand(command);
        }
        if (script->peekCommand(0)->opcode == 4) {
            ++unknown92;
            script->setState(Script::State2, PlayerTest::AnyContext);
        }
        addScript(script);
    }
    loadGame(!loadSave);
}

int ScriptManager::getAvailableMissionScripts(std::vector<Script*>& output) const
{
    for (int i = 0; i < scriptCount; ++i) {
        if (scripts[i]->getState() != Script::State2)
            continue;
        const Structs::ScriptCommand* command = scripts[i]->peekCommand(0);
        const int missionId = scripts[i]->getMissionId();
        if (missionId != -1 && missionId != mission->currentMissionId &&
            command && command->opcode == 64) {
            output.push_back(scripts[i]);
        }
    }
    return output.size();
}

void ScriptManager::resetGame(bool skipAutomaticScripts, int scriptId)
{
    missionIdle();
    for (LevelObject* object = GameObjectManager::s_gom->GetFirst(0); object; object = object->next) {
        const int type = LevelObject::s_type[object->getObjectType()];
        switch (type) {
        case 6:
            displayOnMinimap(object, false, true);
            object->sceneNode->setVisible(false);
            break;
        case 13:
            static_cast<Shop*>(object)->lock();
            break;
        }
    }

    PlayerTest* player = PlayerTest::GetPlayer();
    player->health = player->getMaxHealth();
    player->setCash(0);
    player->switchWeapon(true);
    player->setContextArmor(0);
    WantedLevelManager* wanted = WantedLevelManager::getInstance();
    wanted->unknown8 = 0;
    wanted->_processWantedLevel();
    WantedLevelManager::s_bTutoWantedLevel = false;
    Application::GetInstance()->GetWeaponManager()->lockAllWeapons();
    GSFailure::s_bCutsceneDie = false;
    GSFailure::s_bCutsceneBusted = false;
    GSFailure::s_bCutsceneMissionFailed = false;
    AchievementManager::s_achievementManager->resetNumMissionStat();
    Checkpoint::s_bTutoCallContact = false;
    CControlManager::s_cameraTutorial = false;
    CControlManager::s_sniperTutorial = false;

    unknown92 = 0;
    for (int id = 0; id < scriptCount; ++id) {
        Script* script = findScript(id);
        if (!script)
            continue;
        script->rewind();
        script->setState(Script::State0, PlayerTest::AnyContext);
        if (id == scriptId) {
            script->setState(Script::State2, PlayerTest::AnyContext);
        } else if (!skipAutomaticScripts && script->peekCommand(0)->opcode == 4 && scriptId == -1) {
            script->setState(Script::State2, PlayerTest::AnyContext);
            ++unknown92;
        }
    }
}

void ScriptManager::moveObject(LevelObject* object, LevelObject* target)
{
    if (!object->isEnabled())
        return;
    if (reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer())) == object) {
        PlayerTest* player = PlayerTest::GetPlayer();
        if (LevelObject::s_type[target->objectType] == 3) {
            if ((player->flags240 & 0x400u) && static_cast<SavePositionInterface*>(player)->getVehicle()) {
                player->stopDriving(playertest::PlayerCarState::MovingOut, true);
                player->finishedStopDriving();
            }
            player->setVehicle(static_cast<Vehicle*>(target));
            player->unknown312 = target;
            player->unknown372 = 5;
        } else {
            player->teleportTo(target);
        }
    } else {
        object->SetRotation(target->GetRotation());
        object->SetPosition(target->GetPosition());
    }
    object->getPhysicAttributes()->Init(target->GetMatID(), target->GetTriID(), object->GetPosition());
}

void ScriptManager::unload()
{
    vehicleNameAnimation->SetAnim(-1);
    cinematicBars->SetAnim(-1);
    cinematicCharacterAnimation->SetAnim(-1);
    cinematicHudAnimation2->SetAnim(-1);
    delete s_playerTest;
    s_playerTest = 0;
    delete race;
    race = 0;
    delete mission;
    mission = 0;
    if (scripts) {
        for (int i = 0; i < scriptCount; ++i)
            SafeDelete(scripts[i]);
        delete[] scripts;
        scripts = 0;
    }
    scriptCount = 0;
    s_me = 0;
    s_fadeIntensity = -999;
    s_fadeTime = -999;
    s_failure = 0;
    s_failureTime = 0;
    s_raceTimer = 0;
    s_raceTimeSeconds = 0;
}

extern template void SafeDelete<AnimObject>(AnimObject*&);

void ScriptManager::tearDown()
{
    delete skipButton;
    skipButton = 0;
    SafeDelete(vehicleNameAnimation);
    SafeDelete(cinematicBars);
    SafeDelete(cinematicHudAnimation2);
    SafeDelete(introAnimation);
    delete cinematicsHudSprite;
    cinematicsHudSprite = 0;
    delete cinematicCharacterSprite;
    cinematicCharacterSprite = 0;
    delete introSprite;
    introSprite = 0;
    SafeDelete(cinematicCharacterAnimation);
    delete race;
    race = 0;
    delete mission;
    mission = 0;

    if (scripts) {
        for (int i = 0; i < scriptCount; ++i)
            SafeDelete(scripts[i]);
        delete[] scripts;
        scripts = 0;
    }
}

extern template struct Rct<int>;

void ScriptManager::draw()
{
    if (paused)
        return;
    int width, height;
    Application::GetInstance()->GetScreenDimensions(width, height);
    Rct<int> region;
    if (isInCinematic()) {
        drawCinematicBars();
        region = Rct<int>(110, height - 75, width, height);
    } else {
        region = Rct<int>(0, 0, width, 50);
    }

    if (introAnimation->animation != -1)
        introAnimation->Draw();
    if (cinematicCharacterAnimation->animation != -1) {
        cinematicHudAnimation2->SetAnim(3, 1);
        cinematicHudAnimation2->Draw();
        cinematicCharacterAnimation->Draw();
    }
    if (s_fadeIntensity != -999) {
        if (s_fadeIntensity > 255)
            s_fadeIntensity = 255;
        else if (s_fadeIntensity < 0)
            s_fadeIntensity = 0;
        drawFade();
    }
    if (vehicleNameAnimation->animation != -1)
        vehicleNameAnimation->Draw();
    if (mission)
        mission->draw();
    if (skipButton->isVisible())
        skipButton->draw2d();
    if (revive)
        revive->draw2d();
}

namespace Structs {

struct NoPayloadCommand {
    int opcode;
    void Read(DataStream& stream);
};

inline void NoPayloadCommand::Read(DataStream& stream)
{
    opcode = stream.ReadInt();
}

}

Structs::ScriptCommand* ScriptManager::loadCommand(DataStream& stream)
{
    Structs::ScriptCommand* command = 0;
    switch (stream.Peek4()) {
    case 0:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::SetMe());
        reinterpret_cast<Structs::SetMe*>(command)->Read(stream);
        break;
    }
    case 1:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::PlayScript());
        reinterpret_cast<Structs::PlayScript*>(command)->Read(stream);
        break;
    }
    case 2:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::LockScript());
        reinterpret_cast<Structs::LockScript*>(command)->Read(stream);
        break;
    }
    case 3:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::UnlockScript());
        reinterpret_cast<Structs::UnlockScript*>(command)->Read(stream);
        break;
    }
    case 4:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NoPayloadCommand());
        reinterpret_cast<Structs::NoPayloadCommand*>(command)->Read(stream);
        break;
    }
    case 5:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::WaitForStop());
        reinterpret_cast<Structs::WaitForStop*>(command)->Read(stream);
        break;
    }
    case 6:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::SetAnim());
        reinterpret_cast<Structs::SetAnim*>(command)->Read(stream);
        break;
    }
    case 7:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::SetAnim2());
        reinterpret_cast<Structs::SetAnim2*>(command)->Read(stream);
        break;
    }
    case 8:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::SetAnimSpeed());
        reinterpret_cast<Structs::SetAnimSpeed*>(command)->Read(stream);
        break;
    }
    case 9:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::DebugScript());
        reinterpret_cast<Structs::DebugScript*>(command)->Read(stream);
        break;
    }
    case 12:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::CamSet());
        reinterpret_cast<Structs::CamSet*>(command)->Read(stream);
        break;
    }
    case 13:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::CamDefault());
        reinterpret_cast<Structs::CamDefault*>(command)->Read(stream);
        break;
    }
    case 15:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NoPayloadCommand());
        reinterpret_cast<Structs::NoPayloadCommand*>(command)->Read(stream);
        break;
    }
    case 16:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NoPayloadCommand());
        reinterpret_cast<Structs::NoPayloadCommand*>(command)->Read(stream);
        break;
    }
    case 17:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NoPayloadCommand());
        reinterpret_cast<Structs::NoPayloadCommand*>(command)->Read(stream);
        break;
    }
    case 18:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NoPayloadCommand());
        reinterpret_cast<Structs::NoPayloadCommand*>(command)->Read(stream);
        break;
    }
    case 21:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::Enable());
        reinterpret_cast<Structs::Enable*>(command)->Read(stream);
        break;
    }
    case 22:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::Disable());
        reinterpret_cast<Structs::Disable*>(command)->Read(stream);
        break;
    }
    case 23:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::Release());
        reinterpret_cast<Structs::Release*>(command)->Read(stream);
        break;
    }
    case 24:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::MoveTo());
        reinterpret_cast<Structs::MoveTo*>(command)->Read(stream);
        break;
    }
    case 25:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::ActorWalkTo());
        reinterpret_cast<Structs::ActorWalkTo*>(command)->Read(stream);
        break;
    }
    case 26:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::ActorRunTo());
        reinterpret_cast<Structs::ActorRunTo*>(command)->Read(stream);
        break;
    }
    case 29:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::ActorAttack());
        reinterpret_cast<Structs::ActorAttack*>(command)->Read(stream);
        break;
    }
    case 32:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::ActorFollow());
        reinterpret_cast<Structs::ActorFollow*>(command)->Read(stream);
        break;
    }
    case 33:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::ActorStopFollow());
        reinterpret_cast<Structs::ActorStopFollow*>(command)->Read(stream);
        break;
    }
    case 34:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::ActorWalkPath());
        reinterpret_cast<Structs::ActorWalkPath*>(command)->Read(stream);
        break;
    }
    case 35:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::ActorRunPath());
        reinterpret_cast<Structs::ActorRunPath*>(command)->Read(stream);
        break;
    }
    case 36:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::ActorLoopPath());
        reinterpret_cast<Structs::ActorLoopPath*>(command)->Read(stream);
        break;
    }
    case 37:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::VehicleChasePlayer());
        reinterpret_cast<Structs::VehicleChasePlayer*>(command)->Read(stream);
        break;
    }
    case 38:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::ActorGetIn());
        reinterpret_cast<Structs::ActorGetIn*>(command)->Read(stream);
        break;
    }
    case 39:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::ActorGetOut());
        reinterpret_cast<Structs::ActorGetOut*>(command)->Read(stream);
        break;
    }
    case 41:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::FadeIn());
        reinterpret_cast<Structs::FadeIn*>(command)->Read(stream);
        break;
    }
    case 42:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::FadeOut());
        reinterpret_cast<Structs::FadeOut*>(command)->Read(stream);
        break;
    }
    case 43:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::SetDecal());
        reinterpret_cast<Structs::SetDecal*>(command)->Read(stream);
        break;
    }
    case 44:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::AttackAsGood());
        reinterpret_cast<Structs::AttackAsGood*>(command)->Read(stream);
        break;
    }
    case 45:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::AttackAsBad());
        reinterpret_cast<Structs::AttackAsBad*>(command)->Read(stream);
        break;
    }
    case 46:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NoPayloadCommand());
        reinterpret_cast<Structs::NoPayloadCommand*>(command)->Read(stream);
        break;
    }
    case 47:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::ShowTutorial());
        reinterpret_cast<Structs::ShowTutorial*>(command)->Read(stream);
        break;
    }
    case 48:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NoPayloadCommand());
        reinterpret_cast<Structs::NoPayloadCommand*>(command)->Read(stream);
        break;
    }
    case 49:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::WaitPathEnded());
        reinterpret_cast<Structs::WaitPathEnded*>(command)->Read(stream);
        break;
    }
    case 52:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::CarDriveTo());
        reinterpret_cast<Structs::CarDriveTo*>(command)->Read(stream);
        break;
    }
    case 53:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::CarSetSpeed());
        reinterpret_cast<Structs::CarSetSpeed*>(command)->Read(stream);
        break;
    }
    case 55:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::CarSetPath());
        reinterpret_cast<Structs::CarSetPath*>(command)->Read(stream);
        break;
    }
    case 56:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::Dialog());
        reinterpret_cast<Structs::Dialog*>(command)->Read(stream);
        break;
    }
    case 57:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::Wait());
        reinterpret_cast<Structs::Wait*>(command)->Read(stream);
        break;
    }
    case 60:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::PlaySfx());
        reinterpret_cast<Structs::PlaySfx*>(command)->Read(stream);
        break;
    }
    case 61:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::StopSfx());
        reinterpret_cast<Structs::StopSfx*>(command)->Read(stream);
        break;
    }
    case 62:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::PlayMusic());
        reinterpret_cast<Structs::PlayMusic*>(command)->Read(stream);
        break;
    }
    case 63:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::StopMusic());
        reinterpret_cast<Structs::StopMusic*>(command)->Read(stream);
        break;
    }
    case 64:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::WaitCheckpoint());
        reinterpret_cast<Structs::WaitCheckpoint*>(command)->Read(stream);
        break;
    }
    case 65:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::MissionStart());
        reinterpret_cast<Structs::MissionStart*>(command)->Read(stream);
        break;
    }
    case 66:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::MissionObjective());
        reinterpret_cast<Structs::MissionObjective*>(command)->Read(stream);
        break;
    }
    case 67:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NoPayloadCommand());
        reinterpret_cast<Structs::NoPayloadCommand*>(command)->Read(stream);
        break;
    }
    case 68:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NoPayloadCommand());
        reinterpret_cast<Structs::NoPayloadCommand*>(command)->Read(stream);
        break;
    }
    case 69:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::ProtectNPC());
        reinterpret_cast<Structs::ProtectNPC*>(command)->Read(stream);
        break;
    }
    case 70:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::ProtectCar());
        reinterpret_cast<Structs::ProtectCar*>(command)->Read(stream);
        break;
    }
    case 71:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::StayWithin());
        reinterpret_cast<Structs::StayWithin*>(command)->Read(stream);
        break;
    }
    case 72:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NoPayloadCommand());
        reinterpret_cast<Structs::NoPayloadCommand*>(command)->Read(stream);
        break;
    }
    case 73:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::BeQuick());
        reinterpret_cast<Structs::BeQuick*>(command)->Read(stream);
        break;
    }
    case 74:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::SetUsUpTheBomb());
        reinterpret_cast<Structs::SetUsUpTheBomb*>(command)->Read(stream);
        break;
    }
    case 76:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::LockShop());
        reinterpret_cast<Structs::LockShop*>(command)->Read(stream);
        break;
    }
    case 77:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::UnlockShop());
        reinterpret_cast<Structs::UnlockShop*>(command)->Read(stream);
        break;
    }
    case 79:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::GiveWeapon());
        reinterpret_cast<Structs::GiveWeapon*>(command)->Read(stream);
        break;
    }
    case 80:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::LimitToWeapon());
        reinterpret_cast<Structs::LimitToWeapon*>(command)->Read(stream);
        break;
    }
    case 81:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NoPayloadCommand());
        reinterpret_cast<Structs::NoPayloadCommand*>(command)->Read(stream);
        break;
    }
    case 82:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NPCWeapon());
        reinterpret_cast<Structs::NPCWeapon*>(command)->Read(stream);
        break;
    }
    case 83:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::PlaceItem());
        reinterpret_cast<Structs::PlaceItem*>(command)->Read(stream);
        break;
    }
    case 84:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NoPayloadCommand());
        reinterpret_cast<Structs::NoPayloadCommand*>(command)->Read(stream);
        break;
    }
    case 85:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::TagForKill());
        reinterpret_cast<Structs::TagForKill*>(command)->Read(stream);
        break;
    }
    case 86:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NoPayloadCommand());
        reinterpret_cast<Structs::NoPayloadCommand*>(command)->Read(stream);
        break;
    }
    case 87:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::WaitKilled());
        reinterpret_cast<Structs::WaitKilled*>(command)->Read(stream);
        break;
    }
    case 88:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::WaitShot());
        reinterpret_cast<Structs::WaitShot*>(command)->Read(stream);
        break;
    }
    case 89:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::WaitStolen());
        reinterpret_cast<Structs::WaitStolen*>(command)->Read(stream);
        break;
    }
    case 90:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::WaitWantedLevel());
        reinterpret_cast<Structs::WaitWantedLevel*>(command)->Read(stream);
        break;
    }
    case 91:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NoPayloadCommand());
        reinterpret_cast<Structs::NoPayloadCommand*>(command)->Read(stream);
        break;
    }
    case 96:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::SetWantedLevel());
        reinterpret_cast<Structs::SetWantedLevel*>(command)->Read(stream);
        break;
    }
    case 97:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::RaiseWantedLevel());
        reinterpret_cast<Structs::RaiseWantedLevel*>(command)->Read(stream);
        break;
    }
    case 98:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::DropWantedLevel());
        reinterpret_cast<Structs::DropWantedLevel*>(command)->Read(stream);
        break;
    }
    case 99:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::StopObject());
        reinterpret_cast<Structs::StopObject*>(command)->Read(stream);
        break;
    }
    case 100:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::SpyTarget());
        reinterpret_cast<Structs::SpyTarget*>(command)->Read(stream);
        break;
    }
    case 101:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::WaitEscape());
        reinterpret_cast<Structs::WaitEscape*>(command)->Read(stream);
        break;
    }
    case 102:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::StartRace());
        reinterpret_cast<Structs::StartRace*>(command)->Read(stream);
        break;
    }
    case 103:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::AddRacer());
        reinterpret_cast<Structs::AddRacer*>(command)->Read(stream);
        break;
    }
    case 104:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NoPayloadCommand());
        reinterpret_cast<Structs::NoPayloadCommand*>(command)->Read(stream);
        break;
    }
    case 105:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::WaitCheckpointCar());
        reinterpret_cast<Structs::WaitCheckpointCar*>(command)->Read(stream);
        break;
    }
    case 106:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::DestroyCar());
        reinterpret_cast<Structs::DestroyCar*>(command)->Read(stream);
        break;
    }
    case 107:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::KillNPC());
        reinterpret_cast<Structs::KillNPC*>(command)->Read(stream);
        break;
    }
    case 108:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::WaitForLock());
        reinterpret_cast<Structs::WaitForLock*>(command)->Read(stream);
        break;
    }
    case 113:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NoPayloadCommand());
        reinterpret_cast<Structs::NoPayloadCommand*>(command)->Read(stream);
        break;
    }
    case 109:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NoPayloadCommand());
        reinterpret_cast<Structs::NoPayloadCommand*>(command)->Read(stream);
        break;
    }
    case 110:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::NoPayloadCommand());
        reinterpret_cast<Structs::NoPayloadCommand*>(command)->Read(stream);
        break;
    }
    case 111:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::HudHighlight());
        reinterpret_cast<Structs::HudHighlight*>(command)->Read(stream);
        break;
    }
    case 112:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::ShowTutorial());
        reinterpret_cast<Structs::ShowTutorial*>(command)->Read(stream);
        break;
    }
    case 114:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::SetPhotoTarget());
        reinterpret_cast<Structs::SetPhotoTarget*>(command)->Read(stream);
        break;
    }
    case 115:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::FlagAsInRace());
        reinterpret_cast<Structs::FlagAsInRace*>(command)->Read(stream);
        break;
    }
    case 116:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::WaitIfNotPhotographed());
        reinterpret_cast<Structs::WaitIfNotPhotographed*>(command)->Read(stream);
        break;
    }
    case 117:
    {
        command = reinterpret_cast<Structs::ScriptCommand*>(new Structs::PhotographQuickly());
        reinterpret_cast<Structs::PhotographQuickly*>(command)->Read(stream);
        break;
    }
    default:
        break;
    }
    if (command) printCommand(*command);
    return command;
}

static inline bool isScriptRunning(const Script* script)
{
    return script->getState() == Script::State2;
}

void ScriptManager::reachRunningCommand(int command)
{
    Script** runningScripts = new Script*[scriptCount];
    int runningCount = 0;
    for (int i = 0; i < scriptCount; ++i) {
        if (isScriptRunning(scripts[i]))
            runningScripts[runningCount++] = scripts[i];
    }
    for (int i = 0; i < runningCount; ++i)
        runningScripts[i]->nextCommand(command);
    ::operator delete(runningScripts);
}

bool ScriptManager::checkScreenPress()
{
    Application* application = Application::GetInstance();
    TouchScreenBase* touch = application->GetTouchScreen();
    int width, height;
    application->GetScreenDimensions(width, height);
    const irr::core::rect<float> region(irr::core::position2d<float>(0, 0),
                                        irr::core::position2d<float>(width, height));
    screenPressed = touch->isRegionPressed(region);
    touch->clear();
    return screenPressed;
}
