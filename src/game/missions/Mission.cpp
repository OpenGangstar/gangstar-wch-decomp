/*
 * Mission
 *
 * Original file: Mission.cpp
 * Area:          missions
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Mission.cpp here, in the order they appear in the library.
 */

#include "Mission.h"
#include "WantedLevelManagerSingleton.h"
#include "IMissionCondition.h"
#include "../characters/PlayerTest.h"
#include "../persistence/DataStream.h"
#include "../app/Application.h"
#include "../hud/CHudManager.h"
#include "../hud/MenuManager.h"
#include "../ui/Message.h"
#include "../core/ASprite.h"
#include "../world/ResStream.h"
#include "../core/NativeStdio.h"
#include "../audio/SoundManager.h"
#include "../meta/Achievements.h"
#include "../core/SceneNode.h"
#include "../core/VideoDriver.h"
#include "../core/CameraManager.h"
#include "../core/NativeStrings.h"
#include "../persistence/SaveGame.h"

int Mission::setTextToPrint(int id)
{
    return currentMessage = id;
}

Structs::Mission* Mission::mission(int index) const
{
    if (index < 0 || index >= missionCount)
        return 0;
    return missions[index];
}

int Mission::getLastObjectiveText() const
{
    if (state == 4)
        return lastObjectiveText;
    return -1;
}

int Mission::getCurrentMessage() const
{
    return currentMessage;
}

void Mission::registerCondition(IMissionCondition* condition)
{
    if (conditionCount < 8)
        conditions[conditionCount++] = condition;
}

void Mission::clearConditions()
{
    for (int i = 0; i < conditionCount; ++i) {
        delete conditions[i];
        conditions[i] = 0;
    }
    conditionCount = 0;
}

int Mission::getState() const
{
    return state;
}

int Mission::failureCause() const
{
    return lastFailureCause;
}

int Mission::failureCount() const
{
    return failures;
}

void Mission::skipFadeOut()
{
    skipFade = true;
}

void Mission::resumeFadeOut()
{
    skipFade = false;
}

void Mission::setFailureCount(int count)
{
    failures = count;
}

namespace Structs {

struct Mission {
    int unknown0;
    int unknown4;
    int unknown8;
    char* unknown12;
    int unknown16;
    int unknown20;
    char* unknown24;
    int unknown28;
    int unknown32;

    void Read(DataStream& stream) __attribute__((used));
};

inline void Mission::Read(DataStream& stream)
{
    unknown0 = stream.ReadInt();
    unknown4 = stream.ReadInt();
    unknown8 = stream.ReadInt();
    unknown12 = stream.ReadAndAllocateString();
    unknown16 = stream.ReadInt();
    unknown20 = stream.ReadInt();
    unknown24 = stream.ReadAndAllocateString();
    unknown28 = stream.ReadInt();
    unknown32 = stream.ReadInt();
}

} // namespace Structs

bool Mission::objective(int id, bool silent)
{
    lastObjectiveText = id;
    if (!silent)
        message(id);
    return true;
}

// Recovered translation-unit SDK and AI startup callbacks.
#include "../core/LocalStartupStorage.h"
#include "../core/LocalStartupText.h"
#include "../core/Rct.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_4() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_mission_transitions {
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

template struct Rct<int>;

extern "C" {
static void __tcf_4()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_4), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_mission_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_mission_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_mission_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_mission_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_mission_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_mission_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_mission_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_mission_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_mission_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_mission_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__Z18getFrameModuleRectP7ASpriteiii() __attribute__((used));
static void _GLOBAL__I__Z18getFrameModuleRectP7ASpriteiii()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

void Mission::idle()
{
    currentMissionId = -1;
    unknown8 = 0;
    unknown12 = 0;
    setTextToPrint(-1);
    clearConditions();
    MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(10), -1, 0);
    MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(9), -1, 0);
    static_cast<Message*>(Application::GetInstance()->GetHudManager()->message172)->clearMessage(true);
    state = 0;
}

extern bool bIsInCutscene;
extern "C" void nativeUnloadAllSounds();

void Mission::fail()
{
    bIsInCutscene = false;
    if (currentMissionId >= 0 && state == 4) {
        const int previousFailures = failures;
        unknown8 = 0;
        unknown12 = 0;
        failures = previousFailures + 1;
        state = 6;
        setTextToPrint(-1);
        clearConditions();
        PlayerTest::GetPlayer()->clearPhotoTargets();
        WantedLevelManager::getInstance()->resetWantedLevel();
    }
    nativeUnloadAllSounds();
}

void Mission::load(const char* filename)
{
    ResStream resource(filename, 1);
    DataStream stream(resource, DataStream::BigEndian);
    missionCount = stream.ReadInt();
    if (missionCount > 0) {
        missions = new Structs::Mission*[missionCount];
        memset(missions, 0, missionCount * sizeof(*missions));
        for (int i = 0; i < missionCount; ++i) {
            const int length = stream.ReadInt();
            const int next = stream.Tell() + length;
            Structs::Mission* record = new Structs::Mission();
            record->Read(stream);
            if (stream.Tell() != next)
                stream.Seek(next, 0);
            missions[i] = record;
        }
    }
}

Mission::~Mission()
{
    clearConditions();
    if (missions) {
        for (int i = 0; i < missionCount; ++i) {
            delete[] missions[i]->unknown24;
            delete[] missions[i]->unknown12;
            delete missions[i];
        }
        delete[] missions;
    }
    delete introSprite;
}

Rct<int> getFrameModuleRect(ASprite* sprite, int frameIndex, int moduleIndex, int occurrence)
{
    Rct<int> result(0, 0, 0, 0);
    const SpriteFrame* frame = sprite->GetFrame(frameIndex);
    for (int i = frame->firstModule; i < frame->firstModule + frame->moduleCount; ++i) {
        const SpriteFrameModule* placement = sprite->GetFModule(i);
        if (placement->module == moduleIndex) {
            if (occurrence > 0) {
                --occurrence;
            } else {
                const SpriteModule* module = sprite->GetModule(moduleIndex);
                const int x = placement->x;
                const int y = placement->y;
                const int right = x + module->width;
                const int bottom = y + module->height;
                result.left = x;
                result.top = y;
                result.right = right;
                result.bottom = bottom;
                break;
            }
        }
    }
    return result;
}

bool Mission::end()
{
    bIsInCutscene = false;
    if (currentMissionId < 0)
        return false;

    nativeUnloadAllSounds();
    clearConditions();
    unknown8 = 3000;
    unknown12 = 3000;
    setTextToPrint(missions[currentMissionId]->unknown8);
    static_cast<Message*>(Application::GetInstance()->GetHudManager()->message172)
        ->setMessage(currentMessage, unknown12, static_cast<MenuManager::eText>(9));
    PlayerTest::GetPlayer()->addCash(missions[currentMissionId]->unknown4, unknown12);
    AchievementManager* achievements = AchievementManager::s_achievementManager;
    achievements->recordMissionCash(missions[currentMissionId]->unknown4);
    PlayerTest::GetPlayer()->clearPhotoTargets();
    state = 5;
    SoundManager::getInstance()->stop(14, -1, 0);
    SoundManager::getInstance()->playPriorityAudio(25, false);
    SoundManager* sound = SoundManager::getInstance();
    const int ambientSound = PlayerTest::GetPlayer()->getAmbientSound();
    sound->unknown140 = true;
    sound->playEx(ambientSound, 0, true, 1.0f, 0, true, 1.0f, 0);
    sound->unknown140 = false;
    achievements->recordMissionEnded();
    WantedLevelManager::getInstance()->resetWantedLevel();
    return true;
}

extern "C" char* strcpy(char*, const char*);

void Mission::draw()
{
    Application* app = Application::GetInstance();
    int width, height;
    app->GetScreenDimensions(width, height);
    irr::video::IVideoDriver* driver = app->GetDevice()->getVideoDriver();

    switch (state) {
    case 1: {
        int alpha = unknown12 > 0 ? unknown8 * 255 / unknown12 : 255;
        if (unknown16 == 1)
            alpha = 255 - alpha;
        driver->draw2DRectangle(irr::video::SColor(alpha, 0, 0, 0),
            irr::core::rect<int>(0, 0, width, height));
        break;
    }
    case 3: {
        int alpha = unknown8 * 255 / unknown12;
        if (unknown16 == 1)
            alpha = 255 - alpha;
        driver->draw2DRectangle(irr::video::SColor(alpha, 0, 0, 0),
            irr::core::rect<int>(0, 0, width, height));
        break;
    }
    case 2:
        if (introAnimation.animation != -1) {
            driver->draw2DRectangle(irr::video::SColor(255, 0, 0, 0),
                irr::core::rect<int>(0, 0, width, height));
            introAnimation.Draw();
        }
        break;
    case 5:
        MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(10), 0x3049, 0);
        break;
    default:
        for (int i = 0; i < conditionCount; ++i)
            conditions[i]->draw();
        break;
    }
}

bool Mission::start(int id, int duration)
{
    if (id < 0 || id >= missionCount)
        return false;

    bIsInCutscene = false;
    SaveGame game;
    game.SampleAndSave(SaveGame::GetDefaultFilename());
    MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(9), -1, 0);
    lastFailureCause = -1;
    state = 1;
    currentMissionId = id;
    lastObjectiveText = -1;
    CameraManager::getInstance()->setTouchScreenInputs(false);

    if (strcmp(introSpriteName, missions[currentMissionId]->unknown24) != 0) {
        delete introSprite;
        strcpy(introSpriteName, missions[currentMissionId]->unknown24);
        introSprite = new ASprite(introSpriteName);
        introSprite->MakeImage(0, 0);
        introSprite->unknown33 = false;
        introAnimation.sprite = introSprite;
        introAnimation.Reset();
        introAnimation.SetPosition(0.0f, 0.0f, 0.0f);
    }
    introAnimation.SetAnim(missions[currentMissionId]->unknown0);
    unknown8 = duration;
    unknown12 = duration;
    if (duration == -1) {
        setTextToPrint(missions[currentMissionId]->unknown28);
        if (!skipFade) {
            unknown8 = 500;
            unknown12 = 500;
            unknown16 = 1;
        } else {
            skipFade = false;
            unknown8 = 3000;
            unknown12 = 3000;
            static_cast<Message*>(Application::GetInstance()->GetHudManager()->message172)
                ->setMessage(currentMessage, -1, static_cast<MenuManager::eText>(11));
            state = 2;
        }
    }
    introAnimation.Restart();
    SoundManager::getInstance()->stop(25, -1, 0);
    SoundManager::getInstance()->playPriorityAudio(14, false);
    unknown240 = Application::GetInstance()->GetHudManager()->isVisible();
    if (unknown240)
        Application::GetInstance()->GetHudManager()->hide();
    WantedLevelManager::getInstance()->resetWantedLevel();
    return true;
}
