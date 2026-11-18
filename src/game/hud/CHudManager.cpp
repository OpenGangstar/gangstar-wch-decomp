
#include "../core/ASprite.h"
#include "../core/PointerVector.h"
#include "../ui/VirtualButton.h"
#include "../ui/SlideControl.h"
#include "../ui/Cash.h"
#include "../ui/Background.h"
#include "../rendering/RetroEffect.h"
#include "MiniMap.h"
#include "../missions/WantedMeter.h"
#include "../audio/Radio.h"
#include "../ui/ToggleButton.h"
#include "../missions/Reward.h"
#include "../combat/HitWarning.h"

#include "CCameraHud.h"
#include "SniperHud.h"
#include "HealthBar.h"
#include "ArmorBar.h"
#include "CarBar.h"
#include "../vehicles/Wheel.h"
/*
 * CHudManager
 *
 * Original file: CHudManager.cpp
 * Area:          hud
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of CHudManager.cpp here, in the order they appear in the library.
 */

#include "CHudManager.h"
#include "CDrivingHud.h"
#include "CWalkingHud.h"
#include "SpyGauge.h"
#include "../input/AnalogStick.h"
#include "../ui/AnimatedButton.h"
#include "../ui/Message.h"
#include "../characters/PlayerTest.h"
#include "../combat/Weapon.h"
#include "../app/Application.h"
#include "../combat/Ammo.h"
#include "../combat/WeaponManager.h"

extern bool bIsInCutscene;

void CHudManager::init()
{
    defaultReceiver = 0;
    activeHud = initialHud;
}

void CHudManager::show()
{
    bIsInCutscene = false;
    activeHud->show();
}

bool CHudManager::isVisible() const { return activeHud->isVisible(); }

bool CHudManager::isMinimapVisible() { return minimap->isVisible(); }

bool CHudManager::isWeaponVisible() const { return weaponSelector->isVisible(); }

void CHudManager::lock() { locked = true; }

void CHudManager::unlock() { locked = false; }

bool CHudManager::isLocked() const { return locked; }

void CHudManager::toggleWeaponSelector(bool show)
{
    static_cast<CWalkingHud*>(initialHud)->toggleWeaponSelector(show);
    static_cast<CDrivingHud*>(drivingHud)->toggleWeaponSelector(show);
}

void CHudManager::switchWeapon()
{
    WeaponManager* manager = Application::GetInstance()->GetWeaponManager();
    Weapon* weapon = manager->nextWeapon(1);
    weaponSelector->setWeaponAnim(weapon->getWeaponType());
    manager->swapWeapon();
    ammoDisplay->setWeapon(weapon);
}

void CHudManager::switchWeapon(int id)
{
    WeaponManager* manager = Application::GetInstance()->GetWeaponManager();
    Weapon* weapon = manager->getWeaponInList(id, PlayerTest::AnyContext);
    weaponSelector->setWeaponAnim(weapon->getWeaponType());
    manager->swapWeapon(id);
    ammoDisplay->setWeapon(weapon);
}

void CHudManager::toggleRadioCB(bool enabled)
{
    if (enabled)
        radioButton->setAnim(43);
    else
        radioButton->setAnim(42);
}

void CHudManager::showCash(bool show)
{
    if (activeHud->isWalkingHud())
        static_cast<CWalkingHud*>(activeHud)->showCash(show);
    else if (activeHud)
        static_cast<CDrivingHud*>(activeHud)->showCash(show);
}

void CHudManager::useSpyBGInSpyGauge() { spyGauge->useSpyBG(); }

void CHudManager::useDriveBadBGInSpyGauge() { spyGauge->useDriveBadBG(); }

void CHudManager::useDriveWellBGInSpyGauge() { spyGauge->useDriveWellBG(); }

void CHudManager::showSpyGauge(bool show)
{
    static_cast<CWalkingHud*>(initialHud)->showSpyGauge(show);
    static_cast<CDrivingHud*>(drivingHud)->showSpyGauge(show);
}

bool CHudManager::isNearShop() const
{
    if (activeHud->isWalkingHud())
        return static_cast<const CWalkingHud*>(activeHud)->isNearShop();
    return false;
}

void CHudManager::notNearShop()
{
    if (activeHud->isWalkingHud())
        static_cast<CWalkingHud*>(activeHud)->notNearShop();
}

void CHudManager::nearShop()
{
    if (activeHud->isWalkingHud())
        static_cast<CWalkingHud*>(activeHud)->nearShop();
}

void CHudManager::notNearCar()
{
    if (activeHud->isWalkingHud())
        static_cast<CWalkingHud*>(activeHud)->notNearCar();
}

void CHudManager::nearCar()
{
    if (activeHud->isWalkingHud())
        static_cast<CWalkingHud*>(activeHud)->nearCar();
}

void CHudManager::sniping()
{
    const bool wasVisible = activeHud->isVisible();
    activeHud->hide();
    SavePrimaryInterface* player = PlayerTest::GetPlayer();
    if (player->getWeapon()->getWeaponType() == 9)
        activeHud = cameraHud;
    else
        activeHud = sniperHud;
    if (wasVisible)
        activeHud->show();
}

void CHudManager::walking()
{
    const bool wasVisible = activeHud->isVisible();
    activeHud->hide();
    activeHud = initialHud;
    analogStick->switchMode(AnalogStick::Mode2);
    if (wasVisible)
        activeHud->show();
}

void CHudManager::driving()
{
    const bool wasVisible = activeHud->isVisible();
    activeHud->hide();
    activeHud = drivingHud;
    analogStick->switchMode(AnalogStick::Mode0);
    if (wasVisible)
        activeHud->show();
}

void CHudManager::hide()
{
    for (unsigned int index = 0; index < static_cast<unsigned int>(resetElements.end() - resetElements.begin()); ++index)
        resetElements.begin()[index]->reset();
    activeHud->hide();
}

// Recovered module startup family; storage remains local to this TU.
#include "../core/LocalStartupStorage.h"

#include "../core/LocalStartupText.h"
void operator delete(void*) throw();
extern "C" {
static void __tcf_3() __attribute__((used));
}

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_chudmanager_transitions {
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
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_chudmanager_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_chudmanager_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_chudmanager_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_chudmanager_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_chudmanager_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_chudmanager_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_chudmanager_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_chudmanager_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_chudmanager_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_chudmanager_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN11CHudManagerC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN11CHudManagerC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

void CHudManager::retroEffect(bool enabled)
{
    if (enabled)
        retroOverlay->show();
    else
        retroOverlay->hide();
}

void CHudManager::limitToWeapon(int weaponId)
{
    Application::GetInstance()->GetWeaponManager()->limitToWeapon(weaponId, PlayerTest::AnyContext);
    switchWeapon();
    weaponSelector->grayOut(weaponId != -1);
    static_cast<AnimatedButton*>(weaponSelectorExtra)->grayOut(weaponId != -1);
}

bool CHudManager::isAnyMessageDisplayed()
{
    return static_cast<Message*>(message176)->isDisplayed() || static_cast<Message*>(message172)->isDisplayed();
}

#include "../missions/WantedMeter.h"
#include "../missions/Reward.h"
void CHudManager::unregUpdatableComponents()
{
    Application* app = Application::GetInstance();
    app->UnRegisterForUpdate(minimap);
    app->UnRegisterForUpdate(component140);
    app->UnRegisterForUpdate(component144);
    app->UnRegisterForUpdate(component148);
    app->UnRegisterForUpdate(ammoDisplay);
    app->UnRegisterForUpdate(component160);
    app->UnRegisterForUpdate(wantedMeter);
    app->UnRegisterForUpdate(spyGauge);
    app->UnRegisterForUpdate(component168);
    app->UnRegisterForUpdate(component120);
    app->UnRegisterForUpdate(component124);
    app->UnRegisterForUpdate(reinterpret_cast<IUpdatable*>(component116));
    app->UnRegisterForUpdate(radioButton);
    app->UnRegisterForUpdate(message172);
    app->UnRegisterForUpdate(message176);
    app->UnRegisterForUpdate(reward);
}

#include "../missions/WantedMeter.h"
#include "../missions/Reward.h"
void CHudManager::regUpdatableComponents()
{
    Application* app = Application::GetInstance();
    app->RegisterForUpdate(minimap);
    app->RegisterForUpdate(component140);
    app->RegisterForUpdate(component144);
    app->RegisterForUpdate(component148);
    app->RegisterForUpdate(ammoDisplay);
    app->RegisterForUpdate(component160);
    app->RegisterForUpdate(wantedMeter);
    app->RegisterForUpdate(spyGauge);
    app->RegisterForUpdate(component168);
    app->RegisterForUpdate(component120);
    app->RegisterForUpdate(component124);
    app->RegisterForUpdate(reinterpret_cast<IUpdatable*>(component116));
    app->RegisterForUpdate(radioButton);
    app->RegisterForUpdate(message172);
    app->RegisterForUpdate(message176);
    app->RegisterForUpdate(reward);
}

#include "../missions/WantedMeter.h"
#include "../missions/Reward.h"
void CHudManager::regDrawableComponents()
{
    Application* app = Application::GetInstance();
    for (unsigned int index = 0; index < static_cast<unsigned int>(resetElements.end() - resetElements.begin()); ++index)
        app->RegisterForDrawingOnHUD(resetElements.begin()[index]);
    app->RegisterForDrawingOnHUD(component140);
    app->RegisterForDrawingOnHUD(component144);
    app->RegisterForDrawingOnHUD(component148);
    app->RegisterForDrawingOnHUD(ammoDisplay);
    app->RegisterForDrawingOnHUD(component160);
    app->RegisterForDrawingOnHUD(wantedMeter);
    app->RegisterForDrawingOnHUD(spyGauge);
    app->RegisterForDrawingOnHUD(component168);
    app->RegisterForDrawingOnHUD(message172);
    app->RegisterForDrawingOnHUD(message176);
    app->RegisterForDrawingOnHUD(reward);
}

#include "../missions/WantedMeter.h"
#include "../missions/Reward.h"
void CHudManager::unregDrawableComponents()
{
    Application* app = Application::GetInstance();
    for (unsigned int index = 0; index < static_cast<unsigned int>(resetElements.end() - resetElements.begin()); ++index)
        app->UnRegisterForDrawingOnHUD(resetElements.begin()[index]);
    app->UnRegisterForDrawingOnHUD(component140);
    app->UnRegisterForDrawingOnHUD(component144);
    app->UnRegisterForDrawingOnHUD(component148);
    app->UnRegisterForDrawingOnHUD(ammoDisplay);
    app->UnRegisterForDrawingOnHUD(component160);
    app->UnRegisterForDrawingOnHUD(wantedMeter);
    app->UnRegisterForDrawingOnHUD(spyGauge);
    app->UnRegisterForDrawingOnHUD(component168);
    app->UnRegisterForDrawingOnHUD(message172);
    app->UnRegisterForDrawingOnHUD(message176);
    app->UnRegisterForDrawingOnHUD(reward);
}

void CHudManager::blink(int component)
{
    switch (component) {
    case 0:
        analogStick->blink(true, false);
        break;
    case 1:
        component84->blink(true, false);
        component40->blink(true, false);
        break;
    case 2:
        component80->blink(true, false);
        component52->blink(true, false);
        component60->blink(true, false);
        component56->blink(true, false);
        component64->blink(true, false);
        break;
    case 3:
        component76->blink(true, false);
        break;
    case 4:
        enterCarButton->blink(true, true);
        break;
    case 5:
        enterShopButton->blink(true, true);
        break;
    case 6:
        weaponSelector->blink(true, false);
        weaponSelectorExtra->blink(true, false);
        break;
    }
}

void CHudManager::setThrottleMode(ThrottleMode mode)
{
    throttleMode = mode;
    switch (mode) {
    case ObservedThrottleA:
        drivingHud->unknown8 |= mode;
        drivingHud->unknown8 &= 0xffbcfff3u;
        break;
    case ObservedThrottleB:
    case ObservedThrottleC:
        if (drivingHud->unknown8 & 0x00800000u) {
            drivingHud->unknown8 |= 0x00400008u;
            drivingHud->unknown8 &= 0xffe0fffbu;
        } else {
            drivingHud->unknown8 |= 0x00030004u;
            drivingHud->unknown8 &= 0xffa3fff7u;
        }
        break;
    }
    if (drivingHud->isVisible()) {
        drivingHud->hide();
        drivingHud->show();
    }
}

void CHudManager::setSteeringMode(SteeringMode mode)
{
    steeringMode = mode;
    switch (mode) {
    case ObservedSteering2:
        drivingHud->unknown8 |= 2;
        drivingHud->unknown8 &= ~0xa00001u;
        break;
    case ObservedSteering200000:
        drivingHud->unknown8 |= 0x200000;
        drivingHud->unknown8 &= ~0x800003u;
        break;
    case ObservedSteering800000:
        drivingHud->unknown8 |= 0x800000;
        drivingHud->unknown8 &= ~0x200003u;
        break;
    default:
        drivingHud->unknown8 |= 1;
        drivingHud->unknown8 &= ~0xa00002u;
        break;
    }
    if (mode == ObservedSteering800000) {
        if ((drivingHud->unknown8 & 0x30004u) == 0x30004u)
            setThrottleMode(ObservedThrottleB);
    } else {
        if ((drivingHud->unknown8 & 0x400008u) == 0x400008u)
            setThrottleMode(ObservedThrottleC);
    }
    if (drivingHud->isVisible()) {
        drivingHud->hide();
        drivingHud->show();
    }
}

#include "CCameraHud.h"
#include "SniperHud.h"
#include "HealthBar.h"
#include "ArmorBar.h"
#include "CarBar.h"
#include "../vehicles/Wheel.h"

#include "../input/AnalogStick.h"
#include "../core/ASprite.h"
#include "../core/PointerVector.h"
#include "../ui/VirtualButton.h"
#include "../ui/SlideControl.h"
#include "../ui/Cash.h"
#include "../ui/Background.h"
#include "../rendering/RetroEffect.h"
#include "MiniMap.h"
#include "../missions/WantedMeter.h"
#include "../audio/Radio.h"
#include "../ui/ToggleButton.h"
#include "../missions/Reward.h"
#include "../combat/HitWarning.h"

extern int sWindowWidth;
static const char hudSpriteHigh[] = "./huds.bsprite";
static const char hudSpriteLow[] = "./huds_2.bsprite";

CHudManager::CHudManager()
    : activeHud(0), initialHud(new CWalkingHud(this)), drivingHud(new CDrivingHud(this)),
      sniperHud(new CSniperHud(this)), cameraHud(new CCameraHud(this)),
      steeringMode(ObservedSteering800000), throttleMode(ObservedThrottleC),
      resetElements(), defaultReceiver(0), locked(false)
{
    if (sWindowWidth > 800)
        reviveSprite = new ASprite(hudSpriteHigh);
    else
        reviveSprite = new ASprite(hudSpriteLow);
    reviveSprite->MakeImage(0,0);
    reviveSprite->unknown33=false;
    analogStick=new AnalogStick(reviveSprite,0,1);
    component40=new Wheel(reviveSprite,115);
    component44=new VirtualButton(reviveSprite,105,static_cast<EvVButton::ButtonType::Type>(2),true);
    component48=new VirtualButton(reviveSprite,104,static_cast<EvVButton::ButtonType::Type>(0),true);
    component52=new VirtualButton(reviveSprite,106,static_cast<EvVButton::ButtonType::Type>(4),true);
    component56=new VirtualButton(reviveSprite,107,static_cast<EvVButton::ButtonType::Type>(5),true);
    component60=new VirtualButton(reviveSprite,175,static_cast<EvVButton::ButtonType::Type>(4),true);
    component64=new VirtualButton(reviveSprite,176,static_cast<EvVButton::ButtonType::Type>(5),true);
    component80=new SlideControl(reviveSprite,100,101,SlideControl::Vertical);
    component84=new SlideControl(reviveSprite,102,103,SlideControl::Horizontal);
    component88=new VirtualButton(reviveSprite,98,static_cast<EvVButton::ButtonType::Type>(2),true);
    component92=new VirtualButton(reviveSprite,99,static_cast<EvVButton::ButtonType::Type>(0),true);
    component96=new VirtualButton(reviveSprite,174,static_cast<EvVButton::ButtonType::Type>(2),true);
    component100=new VirtualButton(reviveSprite,173,static_cast<EvVButton::ButtonType::Type>(0),true);
    enterShopButton=new VirtualButton(reviveSprite,111,static_cast<EvVButton::ButtonType::Type>(3),true);
    enterCarButton=new VirtualButton(reviveSprite,2,static_cast<EvVButton::ButtonType::Type>(2),true);
    component76=new VirtualButton(reviveSprite,3,static_cast<EvVButton::ButtonType::Type>(0),true);
    weaponSelectorExtra=new AnimatedButton(reviveSprite,0,static_cast<EvVButton::ButtonType::Type>(6));
    radioButton=new AnimatedButton(reviveSprite,42,static_cast<EvVButton::ButtonType::Type>(11));
    retroOverlay=new RetroEffect;
    minimap=new MiniMap(reviveSprite,5,6,7,22);
    component140=new HealthBar(reviveSprite,23,24,25);
    component144=new ArmorBar(reviveSprite,26,27,28);
    component148=new CarBar(reviveSprite,112,113,114);
    spyGauge=new SpyGauge(reviveSprite,140,141,143,109,177);
    ammoDisplay=new Ammo(reviveSprite,38);
    component160=new Cash(reviveSprite,87,86,97,172,-1);
    wantedMeter=new WantedMeter(reviveSprite,1);
    radioToggle=new ToggleButton(reviveSprite,145,147);
    radio=new Radio(reviveSprite,144,26,32,37,146,31);
    weaponSelector=new AnimatedButton(reviveSprite,15,static_cast<EvVButton::ButtonType::Type>(-1));
    component168=new HitWarning(reviveSprite,116);
    component112=new HudElement(reviveSprite,130,false);
    component120=new VirtualButton(reviveSprite,133,static_cast<EvVButton::ButtonType::Type>(10),true);
    component124=new VirtualButton(reviveSprite,132,static_cast<EvVButton::ButtonType::Type>(0),true);
    component116=new Background(reviveSprite,131);
    message172=new Message(reviveSprite,static_cast<MenuManager::eText>(9),12,14);
    message176=new Message(reviveSprite,static_cast<MenuManager::eText>(10),-2,-3);
    reward=new Reward(reviveSprite,13);
    resetElements.push_back(minimap);
    resetElements.push_back(retroOverlay);
    resetElements.push_back(component112);
    resetElements.push_back(component116);
    resetElements.push_back(analogStick);
    resetElements.push_back(component40);
    resetElements.push_back(component44);
    resetElements.push_back(component48);
    resetElements.push_back(component52);
    resetElements.push_back(component56);
    resetElements.push_back(component60);
    resetElements.push_back(component64);
    resetElements.push_back(component80);
    resetElements.push_back(component84);
    resetElements.push_back(component88);
    resetElements.push_back(component92);
    resetElements.push_back(component96);
    resetElements.push_back(component100);
    resetElements.push_back(enterCarButton);
    resetElements.push_back(enterShopButton);
    resetElements.push_back(component76);
    resetElements.push_back(weaponSelectorExtra);
    resetElements.push_back(radioToggle);
    resetElements.push_back(radio);
    resetElements.push_back(weaponSelector);
    resetElements.push_back(component120);
    resetElements.push_back(component124);
    resetElements.push_back(radioButton);
    regDrawableComponents();
    regUpdatableComponents();
    activeHud=initialHud;
}

#include "../core/ASprite.h"
#include "../core/PointerVector.h"
#include "../missions/WantedMeter.h"
#include "../missions/Reward.h"
#include "../audio/Radio.h"
#include "../ui/ToggleButton.h"
class CSniperHud;
class CCameraHud;
template<class T> void SafeDelete(T*&) __attribute__((weak));
namespace {
template<class T> inline void destroyHudObject(T*& object)
{
    delete object;
    object = 0;
}
}
CHudManager::~CHudManager()
{
    unregDrawableComponents();
    unregUpdatableComponents();
    destroyHudObject(reviveSprite);
    destroyHudObject(analogStick);
    destroyHudObject(component40);
    destroyHudObject(component80);
    destroyHudObject(component84);
    destroyHudObject(component88);
    destroyHudObject(component92);
    destroyHudObject(component96);
    destroyHudObject(component100);
    destroyHudObject(enterCarButton);
    destroyHudObject(enterShopButton);
    destroyHudObject(component76);
    destroyHudObject(retroOverlay);
    destroyHudObject(minimap);
    destroyHudObject(component140);
    destroyHudObject(component144);
    destroyHudObject(component148);
    destroyHudObject(spyGauge);
    destroyHudObject(ammoDisplay);
    destroyHudObject(component160);
    destroyHudObject(weaponSelector);
    destroyHudObject(weaponSelectorExtra);
    destroyHudObject(component112);
    destroyHudObject(reinterpret_cast<HudElement*&>(component116));
    destroyHudObject(component120);
    destroyHudObject(component124);
    SafeDelete(reinterpret_cast<CDrivingHud*&>(drivingHud));
    SafeDelete(reinterpret_cast<CWalkingHud*&>(initialHud));
    SafeDelete(reinterpret_cast<CSniperHud*&>(sniperHud));
    SafeDelete(reinterpret_cast<CCameraHud*&>(cameraHud));
    destroyHudObject(wantedMeter);
    destroyHudObject(component168);
    destroyHudObject(message172);
    destroyHudObject(message176);
    destroyHudObject(reward);
    destroyHudObject(component44);
    destroyHudObject(component48);
    destroyHudObject(component52);
    destroyHudObject(component56);
    destroyHudObject(component60);
    destroyHudObject(component64);
    destroyHudObject(radio);
    destroyHudObject(radioToggle);
    destroyHudObject(radioButton);

}
