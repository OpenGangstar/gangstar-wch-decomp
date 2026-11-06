/*
 * ScriptManager
 *
 * Original file: ScriptManager.cpp
 * Area:          scripting
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of ScriptManager.cpp here, in the order they appear in the library.
 */

#include "ScriptManager.h"
#include "Script.h"
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
