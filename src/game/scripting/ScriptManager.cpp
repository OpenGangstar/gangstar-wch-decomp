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
#include "../core/PointerVector.h"
#include "../world/ResStream.h"
#include "../core/ASprite.h"
#include "../ui/VirtualButton.h"
#include "../vehicles/Vehicle.h"
#include "../core/VideoDriver.h"
#include "../core/NativeStdio.h"
#include "../core/NativeStrings.h"
#include "../world/GameObjectManager.h"
#include "../ui/WidgetDialog.h"
#include "ScriptManager.h"
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

struct MissionStart {
    int opcode;
    int argument;
    void Read(DataStream& stream) __attribute__((used));
};

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
