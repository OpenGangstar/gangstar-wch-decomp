/*
 * Ammo
 *
 * Original file: Ammo.cpp
 * Area:          combat
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of Ammo.cpp here, in the order they appear in the library.
 */

#include "../core/LocalStartupText.h"
#include "Ammo.h"
#include "../core/ASprite.h"
#include "../core/VideoDriver.h"
#include "../core/SceneNode.h"
#include "../core/IrrlichtDevice.h"
#include "../app/Application.h"
#include "Weapon.h"
#include "WeaponManager.h"
#include "../core/NativeStdio.h"
#include "../core/LocalStartupStorage.h"

void Ammo::setWeapon(Weapon* value)
{
    weapon = value;
}

void Ammo::update(double)
{
}

static const char ammoNumberFormat[] __attribute__((section(".rodata.ammo_number_format"))) = "%i";

void Ammo::drawNumber(int value, const int* digits, int& x, int y, int spacing) const
{
    char number[5];
    sprintf(number, ammoNumberFormat, value);
    int length = 0;
    while (number[length] && length < 5) ++length;
    for (int i = length-1; i >= 0; --i) {
        int frame = digits[number[i]-'0'];
        x -= spacing + sprite->GetFrameWidth(frame);
        sprite->PaintFrame(digits[number[i]-'0'], x, y, 0);
    }
}

void Ammo::draw2d() const
{
    if (weapon && (flags & 1)) {
        Application* application = Application::GetInstance();
        irr::video::IVideoDriver* driver = application->GetDevice()->getVideoDriver();
        driver->setTransform(irr::video::ETS_WORLD, irr::core::matrix4());
        int ammoType = weapon->getAmmoType();
        if (ammoType > -1 && ammoType != 6) {
            int total = application->GetWeaponManager()->getAmmo(ammoType, static_cast<PlayerTest::eContext>(-1));
            int x = 470;
            int clip = weapon->getClip();
            drawNumber(total, largeDigits, x, 55, -7);
            x = x + 9 - sprite->GetFrameWidth(separatorFrame);
            sprite->PaintFrame(separatorFrame, x, 55, 0);
            x -= 3;
            drawNumber(clip, smallDigits, x, 55, -4);
        }
    }
}

typedef char HudElementExtent[sizeof(HudElement)==56?1:-1];
typedef char AmmoExtent[sizeof(Ammo)==148?1:-1];
Ammo::~Ammo() {}
Ammo::Ammo(ASprite* sprite, int firstFrame) : HudElement(sprite,firstFrame,false)
{
    unknown60=firstFrame;
    weapon=0;
    smallDigits[1]=firstFrame;
    smallDigits[2]=firstFrame+1;
    smallDigits[3]=firstFrame+2;
    smallDigits[4]=firstFrame+3;
    smallDigits[5]=firstFrame+4;
    smallDigits[6]=firstFrame+5;
    smallDigits[7]=firstFrame+6;
    smallDigits[8]=firstFrame+7;
    smallDigits[9]=firstFrame+8;
    smallDigits[0]=firstFrame+9;
    separatorFrame=firstFrame+10;
    largeDigits[1]=firstFrame+11;
    largeDigits[2]=firstFrame+12;
    largeDigits[3]=firstFrame+13;
    largeDigits[4]=firstFrame+14;
    largeDigits[5]=firstFrame+15;
    largeDigits[6]=firstFrame+16;
    largeDigits[7]=firstFrame+17;
    largeDigits[8]=firstFrame+18;
    largeDigits[9]=firstFrame+19;
    largeDigits[0]=firstFrame+20;
}

void operator delete(void*) throw();
extern "C" { static void __tcf_3(void*) __attribute__((used)); }

// Scoped imports distinguish the original TU-local transition tables.
namespace retail_ammo_transitions {
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
        __aeabi_atexit(0, __tcf_3, &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
        new (gameloft::ai::civ_passive) gameloft::ai::LocalTransitionList(retail_ammo_transitions::civPassive_trans, 75);
        new (gameloft::ai::npc_scripted) gameloft::ai::LocalTransitionList(retail_ammo_transitions::scriptedNpc_trans, 12);
        new (gameloft::ai::civ_agressive) gameloft::ai::LocalTransitionList(retail_ammo_transitions::civAggressive_trans, 57);
        new (gameloft::ai::gang_member) gameloft::ai::LocalTransitionList(retail_ammo_transitions::gangMember_trans, 3);
        new (gameloft::ai::cop) gameloft::ai::LocalTransitionList(retail_ammo_transitions::cop_trans, 78);
        new (gameloft::ai::swat) gameloft::ai::LocalTransitionList(retail_ammo_transitions::swat_trans, 3);
        new (gameloft::ai::civ_vehicle) gameloft::ai::LocalTransitionList(retail_ammo_transitions::civ_vehicle_trans, 36);
        new (gameloft::ai::cop_vehicle) gameloft::ai::LocalTransitionList(retail_ammo_transitions::cop_vehicle_trans, 45);
        new (gameloft::ai::guard) gameloft::ai::LocalTransitionList(retail_ammo_transitions::guard_trans, 42);
        new (gameloft::ai::scripted_vehicle) gameloft::ai::LocalTransitionList(retail_ammo_transitions::scripted_vehicle_trans, 21);
    }
}

extern "C" {
static void _GLOBAL__I__ZN4AmmoC2EP7ASpritei() __attribute__((used));
static void _GLOBAL__I__ZN4AmmoC2EP7ASpritei()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_3(void*)
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}
