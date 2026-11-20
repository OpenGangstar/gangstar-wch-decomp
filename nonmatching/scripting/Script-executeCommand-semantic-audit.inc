#include "../ai/NPC.h"
#include "../vehicles/Vehicle.h"
#include "../audio/SoundManager.h"
#include "../meta/Item.h"
#include "../combat/WeaponManager.h"
#include "../meta/Race.h"
#include "../meta/Factions.h"
#include "../meta/Achievements.h"
#include "../persistence/StringManager.h"
#include "../world/GameObjectManager.h"
#include "../world/Path.h"
#include "../ui/Shop.h"
#include "../ui/MenuState.h"
#include "../core/CameraManager.h"
#include "../core/SceneCamera.h"
#include "../core/Lock.h"
#include "../rendering/GS3DStuff.h"
#include "../hud/CHudManager.h"
#include "../hud/MenuManager.h"
#include "../hud/SpyGauge.h"
#include "../hud/Gauge.h"
#include "../missions/Mission.h"
#include "../missions/Checkpoint.h"
#include "../characters/PhysicAttributes.h"
#include "../characters/NPCDespawnEvent.h"
#include "../input/CControlManager.h"
extern "C" int strcmp(const char*,const char*);
extern "C" long lrand48();
extern "C" void _ZN12EvNPCDespawnD1Ev(void*) __attribute__((weak));
class GSBlockingTutorial;
template<> GSBlockingTutorial* StateMachine::pushState<GSBlockingTutorial>() __attribute__((weak));
static const char scriptCountdownFormat[] __attribute__((section(".rodata.script_execute_literal1"))) = "%d";
static const char scriptTutorial[] __attribute__((section(".rodata.script_execute_literal2"))) = "Tutorial";
static const char scriptCreditDance[] __attribute__((section(".rodata.script_execute_literal3"))) = "credit_dance";
static const char scriptLiteral3[] __attribute__((section(".rodata.script_execute_literal4"))) = "Health penalty: %.02f)\n";
static const char scriptLiteral4[] __attribute__((section(".rodata.script_execute_literal5"))) = "Run-over pedestrian penalty: %.02f)\n";
static const char scriptLiteral5[] __attribute__((section(".rodata.script_execute_literal6"))) = "Wanted level penalty (gain): %.02f\n";
static const char scriptLiteral6[] __attribute__((section(".rodata.script_execute_literal7"))) = "Jump penalty: %.02f\n";
static const char scriptLiteral7[] __attribute__((section(".rodata.script_execute_literal8"))) = "Speed penalty: %.02f\n";
static const char scriptLiteral8[] __attribute__((section(".rodata.script_execute_literal9"))) = "Wanted level penalty (OT): %.02f\n";
static const char scriptLiteral9[] __attribute__((section(".rodata.script_execute_literal10"))) = "Drift penalty: %.02f\n";

bool Script::executeCommand(const Structs::ScriptCommand* command,int elapsed,int argument)
{
    typedef irr::core::vector3d<float> V;
    switch(command->opcode) {
    case 0: {
        const Structs::SetMe& cmd=*reinterpret_cast<const Structs::SetMe*>(command);
ScriptManager::s_me=ScriptManager::findObject(cmd.argument,false); return true;
    }
    case 1: {
        const Structs::PlayScript& cmd=*reinterpret_cast<const Structs::PlayScript*>(command);
executeSubScript(cmd.argument,argument); return true;
    }
    case 2: {
        const Structs::LockScript& cmd=*reinterpret_cast<const Structs::LockScript*>(command);
lockScript(cmd.argument); return true;
    }
    case 3: {
        const Structs::UnlockScript& cmd=*reinterpret_cast<const Structs::UnlockScript*>(command);
unlockScript(cmd.argument); return true;
    }
    case 5: {
        const Structs::WaitForStop& cmd=*reinterpret_cast<const Structs::WaitForStop*>(command);
if(!source) source=ScriptManager::findObject(cmd.argument,false);
if(source==reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer()))) {
 if(!(ScriptManager::s_playerTest->flags240&0xfe)) return true;
 return ScriptManager::getInstance()->areBlockingCommandsSkipped();
}
int type=LevelObject::s_type[source->getObjectType()];
if(type==2 || type==3) {if(source->GetSpeed()==0.0f) return true;return ScriptManager::getInstance()->areBlockingCommandsSkipped();}
if(type==1) {if(!(static_cast<Character*>(source)->movementFlags&0xfe)) return true;return ScriptManager::getInstance()->areBlockingCommandsSkipped();}
if(type==5) {if(static_cast<NPC*>(source)->flags356&0x4000) return true;return ScriptManager::getInstance()->areBlockingCommandsSkipped();}
return true;
    }
    case 6: {
        const Structs::SetAnim& cmd=*reinterpret_cast<const Structs::SetAnim*>(command);
LevelObject* object=ScriptManager::findObject(cmd.argument2,false);
const char* name=cmd.argument1;
if (strcmp(name,scriptCreditDance)==0) object->setAnimation(name,1,true,true,false);
else object->setAnimation(name,1,true,false,false);
return true;
    }
    case 7: {
        const Structs::SetAnim2& cmd=*reinterpret_cast<const Structs::SetAnim2*>(command);
LevelObject* object=ScriptManager::findObject(cmd.argument3,false);
object->setAnimation(cmd.argument1,1,false,false,false);
object->setNextAnimation(cmd.argument2,1,false,false,false);
return true;
    }
    case 8: {
        const Structs::SetAnimSpeed& cmd=*reinterpret_cast<const Structs::SetAnimSpeed*>(command);
ScriptManager::findObject(cmd.argument1,false)->setAnimationSpeedMultiplier(cmd.argument2); return true;
    }
    case 12: {
        const Structs::CamSet& cmd=*reinterpret_cast<const Structs::CamSet*>(command);
LevelObject* object=ScriptManager::findObject(cmd.argument1,false);
CameraManager::getInstance()->setSceneCamera(static_cast<SceneCamera*>(object));
CameraManager::getInstance()->enterMode(3,0,ScriptManager::getInstance()->areBlockingCommandsSkipped()?0.0f:cmd.argument2/1000.0f,0);
CameraManager::getInstance()->setTouchScreenInputs(false); return true;
    }
    case 13: {
        const Structs::CamDefault& cmd=*reinterpret_cast<const Structs::CamDefault*>(command);
CameraManager::getInstance()->setSceneCamera(0);
Vehicle* car=ScriptManager::s_playerTest->getVehicle();
if (!car || !car->isEnabled())
 CameraManager::getInstance()->enterMode(0,reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(ScriptManager::s_playerTest)),cmd.argument/1000.0f,0);
else CameraManager::getInstance()->enterMode(2,ScriptManager::s_playerTest->getVehicle(),0.1f,0);
CameraManager::getInstance()->setTouchScreenInputs(true); return true;
    }
    case 15: {
bool skip=ScriptManager::getInstance()->areBlockingCommandsSkipped();
if(!ScriptManager::getInstance()->isInCinematic()) {MenuManager::getInstance()->popTo(scriptTutorial,true,true);ScriptManager::getInstance()->setState(static_cast<ScriptManager::State>(skip?2:1));setScriptObjectAction(0,Flag512);}
return ScriptManager::getInstance()->cinematicState==2;
    }
    case 16: {
if(ScriptManager::getInstance()->cinematicState==2) {bool skip=ScriptManager::getInstance()->areBlockingCommandsSkipped();ScriptManager::getInstance()->setState(static_cast<ScriptManager::State>(3));if(skip)ScriptManager::getInstance()->setState(ScriptManager::State0);
PlayerTest* player=PlayerTest::GetPlayer();player->flags240&=0xffff7fff;Vehicle* car=player->getVehicle();if(car)car->startDriving();unsetScriptObjectAction(0,Flag512);}
return ScriptManager::getInstance()->cinematicState==0;
    }
    case 17: {
bool skip=ScriptManager::getInstance()->areBlockingCommandsSkipped();
if(!ScriptManager::getInstance()->isInCinematic()) {MenuManager::getInstance()->popTo(scriptTutorial,true,true);ScriptManager::getInstance()->setState(static_cast<ScriptManager::State>(skip?5:4));setScriptObjectAction(0,Flag1024);}
return ScriptManager::getInstance()->cinematicState==5;
    }
    case 18: {
if(ScriptManager::getInstance()->cinematicState==5) {bool skip=ScriptManager::getInstance()->areBlockingCommandsSkipped();ScriptManager::getInstance()->setState(static_cast<ScriptManager::State>(6));if(skip)ScriptManager::getInstance()->setState(ScriptManager::State0);
PlayerTest* player=PlayerTest::GetPlayer();player->flags240&=0xffff7fff;Vehicle* car=player->getVehicle();if(car)car->startDriving();unsetScriptObjectAction(0,Flag1024);}
return ScriptManager::getInstance()->cinematicState==0;
    }
    case 21: {
        const Structs::Enable& cmd=*reinterpret_cast<const Structs::Enable*>(command);
LevelObject* object=ScriptManager::findObject(cmd.argument2,false);
LevelObject* marker=ScriptManager::findObject(cmd.argument1,false);
if(object->isEnabled() && (object->unknown4&0x400)) object->disable();object->enable();
object->SetRotation(marker->GetRotation());object->SetPosition(marker->GetPosition());
object->getPhysicAttributes()->Init(marker->GetMatID(),marker->GetTriID(),object->GetPosition());
int type=LevelObject::s_type[object->getObjectType()];
if(type==5) {NPC* npc=static_cast<NPC*>(object);if(npc->category428!=0xffffffffu && npc->category428!=6) AIManager::getInstance()->addAI(npc,static_cast<gameloft::ai::StateID>(0));}
else if(type==3 && static_cast<Vehicle*>(object)->unknown240!=-1) AIManager::getInstance()->addAI(static_cast<Vehicle*>(object),static_cast<gameloft::ai::StateID>(0));
if(LevelObject::s_type[object->getObjectType()]==5 && static_cast<NPC*>(object)->category428==5) static_cast<NPC*>(object)->searchOrigin=object->GetPosition();
setScriptObjectAction(object,ActiveObject);return true;
    }
    case 22: {
        const Structs::Disable& cmd=*reinterpret_cast<const Structs::Disable*>(command);
LevelObject* object=ScriptManager::findObject(cmd.argument,false); object->disable(); unsetScriptObjectAction(object,ActiveObject); return true;
    }
    case 23: {
        const Structs::Release& cmd=*reinterpret_cast<const Structs::Release*>(command);
LevelObject* object=ScriptManager::findObject(cmd.argument,false);
if (!ScriptManager::getInstance()->areBlockingCommandsSkipped()) object->unknown4|=0x400;
else object->disable(); return true;
    }
    case 24: {
        const Structs::MoveTo& cmd=*reinterpret_cast<const Structs::MoveTo*>(command);
LevelObject* target=ScriptManager::findObject(cmd.argument2,false);
LevelObject* object=ScriptManager::findObject(cmd.argument1,false);
if(LevelObject::s_type[target->getObjectType()]==5 && LevelObject::s_type[object->getObjectType()]==3) {
 EventManager* events = Application::GetInstance()->GetEventManager();
 unsigned int storage[sizeof(EvNPCDespawn)/sizeof(unsigned int)];
 EvNPCDespawn* event=new(storage) EvNPCDespawn(target);
 events->raise(*event);_ZN12EvNPCDespawnD1Ev(event);
 static_cast<Character*>(target)->initInVehicle(static_cast<Vehicle*>(object));
} else {
 const V& first=target->GetPosition();const V& second=object->GetPosition();
 const float distance=V(first.X-second.X,first.Y-second.Y,0.0f).getLength();
 int type=LevelObject::s_type[target->getObjectType()];
 if((type==5 || type==8) && distance<=10.0f && (!(static_cast<Character*>(target)->movementFlags&0x400) || !static_cast<Character*>(target)->getVehicle())) {
  static_cast<Character*>(target)->setTurnDirection(-object->GetFront());static_cast<Character*>(target)->startTurn(8.0f);
 }else ScriptManager::moveObject(target,object);
}return true;
    }
    case 25: {
        const Structs::ActorWalkTo& cmd=*reinterpret_cast<const Structs::ActorWalkTo*>(command);
Character* actor=static_cast<Character*>(ScriptManager::findObject(cmd.argument1,false));LevelObject* target=ScriptManager::findObject(cmd.argument2,false);
if(!ScriptManager::getInstance()->areBlockingCommandsSkipped()) {actor->setTurnDirection(-target->GetFront());actor->walkToLocation(target->GetPosition());}else ScriptManager::moveObject(actor,target);return true;
    }
    case 26: {
        const Structs::ActorRunTo& cmd=*reinterpret_cast<const Structs::ActorRunTo*>(command);
Character* actor=static_cast<Character*>(ScriptManager::findObject(cmd.argument1,false));LevelObject* target=ScriptManager::findObject(cmd.argument2,false);
if(!ScriptManager::getInstance()->areBlockingCommandsSkipped()) {actor->setTurnDirection(-target->GetFront());actor->runToLocation(target->GetPosition());}else ScriptManager::moveObject(actor,target);return true;
    }
    case 29: {
        const Structs::ActorAttack& cmd=*reinterpret_cast<const Structs::ActorAttack*>(command);
NPC* actor=static_cast<NPC*>(ScriptManager::findObject(cmd.argument1,false));
LevelObject* target=ScriptManager::findObject(cmd.argument2,false);
if(actor==reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer()))) {
 static_cast<SavePositionInterface*>(PlayerTest::GetPlayer())->SetTarget(target);PlayerTest::GetPlayer()->attack(false);
}else {
 if(target==reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer()))) Factions::setFactionAsEnemy(actor->faction);
 actor->setNextAnimation(-1,1,false,false,false);actor->attackTarget(target);
}return true;
    }
    case 32: {
        const Structs::ActorFollow& cmd=*reinterpret_cast<const Structs::ActorFollow*>(command);
static_cast<Character*>(ScriptManager::findObject(cmd.argument1,false))->unknown264=ScriptManager::findObject(cmd.argument2,false); return true;
    }
    case 33: {
        const Structs::ActorStopFollow& cmd=*reinterpret_cast<const Structs::ActorStopFollow*>(command);
static_cast<Character*>(ScriptManager::findObject(cmd.argument,false))->unknown264=0; return true;
    }
    case 34: {
        const Structs::ActorWalkPath& cmd=*reinterpret_cast<const Structs::ActorWalkPath*>(command);
NPC* actor=static_cast<NPC*>(ScriptManager::findObject(cmd.argument1,false));const Path* path=static_cast<Path*>(ScriptManager::findObject(cmd.argument2,false));
actor->setNextAnimation(-1,1,false,false,false);actor->flags356&=~0x40;actor->setPathToFollow(path);AIManager::getInstance()->removeAI(actor);
actor->flags356&=~0x8000;
AIManager::getInstance()->addAI(actor,static_cast<gameloft::ai::StateID>(1));return true;
    }
    case 35: {
        const Structs::ActorRunPath& cmd=*reinterpret_cast<const Structs::ActorRunPath*>(command);
NPC* actor=static_cast<NPC*>(ScriptManager::findObject(cmd.argument1,false));const Path* path=static_cast<Path*>(ScriptManager::findObject(cmd.argument2,false));
actor->setNextAnimation(-1,1,false,false,false);actor->flags356&=~0x40;actor->setPathToFollow(path);AIManager::getInstance()->removeAI(actor);
actor->flags356|=0x8000;
AIManager::getInstance()->addAI(actor,static_cast<gameloft::ai::StateID>(1));return true;
    }
    case 36: {
        const Structs::ActorLoopPath& cmd=*reinterpret_cast<const Structs::ActorLoopPath*>(command);
LevelObject* object=ScriptManager::findObject(cmd.argument,false);
int type=LevelObject::s_type[object->getObjectType()];
if(type==3) static_cast<Vehicle*>(object)->loopPathToFollow(true);
else if(type==5) static_cast<NPC*>(object)->loopPathToFollow(true); return true;
    }
    case 37: {
        const Structs::VehicleChasePlayer& cmd=*reinterpret_cast<const Structs::VehicleChasePlayer*>(command);
Vehicle* car=static_cast<Vehicle*>(ScriptManager::findObject(cmd.argument2,false));
LevelObject* object=ScriptManager::findObject(cmd.argument1,false);
if(!object->isEnabled()) {
 object->enable();if(LevelObject::s_type[object->getObjectType()]==5 && static_cast<NPC*>(object)->category428!=0xffffffffu && static_cast<NPC*>(object)->category428!=6)
 AIManager::getInstance()->addAI(static_cast<NPC*>(object),static_cast<gameloft::ai::StateID>(0));setScriptObjectAction(object,ActiveObject);
}
static_cast<Character*>(object)->initInVehicle(car);static_cast<NPC*>(object)->unknown320=reinterpret_cast<unsigned int>(car);
AIManager::getInstance()->removeAI(car);AIManager::getInstance()->addAI(car,static_cast<gameloft::ai::StateID>(8));
PlayerTest* player=PlayerTest::GetPlayer();
if((player->flags240&0x400) && static_cast<SavePositionInterface*>(player)->getVehicle()) car->aiTarget=player->getVehicle();
else car->aiTarget=reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(player));
car->flags344|=0x400800;
unsigned int flag=(lrand48()&1)?0x100000:0x200000;car->flags344|=flag;
if(car->aiTarget) {car->unknown776=car->unknown188;car->flags344|=0x1000;}return true;
    }
    case 38: {
        const Structs::ActorGetIn& cmd=*reinterpret_cast<const Structs::ActorGetIn*>(command);
Character* actor=static_cast<Character*>(ScriptManager::findObject(cmd.argument1,false));
Vehicle* car=static_cast<Vehicle*>(ScriptManager::findObject(cmd.argument2,false));
if(reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer()))==actor) {
 PlayerTest::GetPlayer()->unknown312=car; PlayerTest::GetPlayer()->initDriving(false);
} else actor->goToVehicle(car,true,true,false,false); return true;
    }
    case 39: {
        const Structs::ActorGetOut& cmd=*reinterpret_cast<const Structs::ActorGetOut*>(command);
Character* actor=static_cast<Character*>(ScriptManager::findObject(cmd.argument,false));
if(reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer()))==actor) {
 if(!ScriptManager::getInstance()->areBlockingCommandsSkipped()) PlayerTest::GetPlayer()->stopDriving(static_cast<playertest::PlayerCarState::ePlayerCarState>(6),true);
 else {ScriptManager::s_playerTest->stopDriving(playertest::PlayerCarState::MovingOut,true); ScriptManager::s_playerTest->finishedStopDriving();}
} else actor->getOutOfVehicle(true,false); return true;
    }
    case 41: {
        const Structs::FadeIn& cmd=*reinterpret_cast<const Structs::FadeIn*>(command);
if(cmd.argument>0 && !ScriptManager::getInstance()->areBlockingCommandsSkipped()) {
 if(ScriptManager::s_fadeTime==-999) {Application::GetInstance()->GetControlManager()->lock();ScriptManager::s_fadeIntensity=255;ScriptManager::s_fadeTime=cmd.argument;return false;}
 if(ScriptManager::s_fadeTime>0) {Application::GetInstance()->GetControlManager()->lock();ScriptManager::s_fadeTime-=elapsed;ScriptManager::s_fadeIntensity=ScriptManager::s_fadeTime*255/cmd.argument;return false;}
}
if(!ScriptManager::getInstance()->isInCinematic())Application::GetInstance()->GetControlManager()->unlock();ScriptManager::s_fadeTime=-999;ScriptManager::s_fadeIntensity=-999;ScriptManager::getInstance()->missionResumeFadeOut();return true;
    }
    case 42: {
        const Structs::FadeOut& cmd=*reinterpret_cast<const Structs::FadeOut*>(command);
if(cmd.argument>0 && !ScriptManager::getInstance()->areBlockingCommandsSkipped()) {
 if(ScriptManager::s_fadeIntensity==-999) {Application::GetInstance()->GetControlManager()->lock();ScriptManager::s_fadeIntensity=0;ScriptManager::s_fadeTime=cmd.argument;return false;}
 if(ScriptManager::s_fadeTime>0) {Application::GetInstance()->GetControlManager()->lock();ScriptManager::s_fadeTime-=elapsed;ScriptManager::s_fadeIntensity=255-ScriptManager::s_fadeTime*255/cmd.argument;return false;}
}
if(!ScriptManager::getInstance()->isInCinematic())Application::GetInstance()->GetControlManager()->unlock();ScriptManager::s_fadeIntensity=255;ScriptManager::s_fadeTime=-999;ScriptManager::getInstance()->missionSkipFadeOut();return true;
    }
    case 43: {
        const Structs::SetDecal& cmd=*reinterpret_cast<const Structs::SetDecal*>(command);
ScriptManager::getInstance()->introAnimation->SetAnim(cmd.argument); return true;
    }
    case 44: {
        const Structs::AttackAsGood& cmd=*reinterpret_cast<const Structs::AttackAsGood*>(command);
LevelObject* object=ScriptManager::findObject(cmd.argument,false);
if(LevelObject::s_type[object->getObjectType()]==5) static_cast<NPC*>(object)->faction=1; return true;
    }
    case 45: {
        const Structs::AttackAsBad& cmd=*reinterpret_cast<const Structs::AttackAsBad*>(command);
LevelObject* object=ScriptManager::findObject(cmd.argument,false);
if(LevelObject::s_type[object->getObjectType()]==5) static_cast<NPC*>(object)->faction=2; return true;
    }
    case 46: {
for(LevelObject* object=GameObjectManager::s_gom->GetFirst(0);object;object=object->next) {
 if(LevelObject::s_type[object->getObjectType()]==5) {
  NPC* npc=static_cast<NPC*>(object);
  if(npc->faction==2 || npc->faction==1) {npc->setNextAnimation(-1,1,false,false,false);npc->attackTarget(0);}
 }
} return true;
    }
    case 47: {
        const Structs::ShowTutorial& cmd=*reinterpret_cast<const Structs::ShowTutorial*>(command);
if(ScriptManager::getInstance()->unknown78) {
 MenuManager* menu=MenuManager::getInstance();menu->setTutorialIds(cmd.argument2,cmd.argument1);
 if(static_cast<MenuState*>(menu->getState(scriptTutorial))->GetDepth()!=0) menu->popAll(true);
 MenuManager::getInstance()->push(scriptTutorial,true);
} return true;
    }
    case 48: {
if(MenuManager::getInstance()->getDepth()>0) MenuManager::getInstance()->popTo(scriptTutorial,true,true); return true;
    }
    case 49: {
        const Structs::WaitPathEnded& cmd=*reinterpret_cast<const Structs::WaitPathEnded*>(command);
if(ScriptManager::getInstance()->areBlockingCommandsSkipped()) return true;
if(!source) {source=ScriptManager::findObject(cmd.argument,false);if(!source)return true;}
const Path* path;int waypoint;
int type=LevelObject::s_type[source->getObjectType()];
if(type==3) {Vehicle* car=static_cast<Vehicle*>(source);path=car->getPathToFollow();waypoint=car->getCurrentWaypoint();if(path->getSize()<=waypoint) car->setPathToFollow(0);}
else if(type==5) {NPC* npc=static_cast<NPC*>(source);path=npc->getPathToFollow();waypoint=npc->getCurrentWaypoint();}else return true;
if(!path)return true;return path->getSize()<=waypoint;
    }
    case 52: {
        const Structs::CarDriveTo& cmd=*reinterpret_cast<const Structs::CarDriveTo*>(command);
Vehicle* car=static_cast<Vehicle*>(ScriptManager::findObject(cmd.argument1,false));
LevelObject* target=ScriptManager::findObject(cmd.argument2,false);
if(!ScriptManager::getInstance()->areBlockingCommandsSkipped()) {car->setSpeed();car->driveToLocation(target->GetPosition(),true);}
else ScriptManager::moveObject(car,target);return true;
    }
    case 53: {
        const Structs::CarSetSpeed& cmd=*reinterpret_cast<const Structs::CarSetSpeed*>(command);
static_cast<Vehicle*>(ScriptManager::findObject(cmd.argument1,false))->unknown776=cmd.argument2*1000.0f/3600.0f; return true;
    }
    case 55: {
        const Structs::CarSetPath& cmd=*reinterpret_cast<const Structs::CarSetPath*>(command);
Vehicle* car=static_cast<Vehicle*>(ScriptManager::findObject(cmd.argument1,false));
const Path* path=static_cast<Path*>(ScriptManager::findObject(cmd.argument2,false));car->setPathToFollow(path);
AIManager::getInstance()->removeAI(car);AIManager::getInstance()->addAI(car,static_cast<gameloft::ai::StateID>(1));car->setSpeed();return true;
    }
    case 56: {
        const Structs::Dialog& cmd=*reinterpret_cast<const Structs::Dialog*>(command);
Application* app=Application::GetInstance();if(ScriptManager::debugOn) app->GetStringManager()->getString(cmd.argument3);
MenuManager* menu=MenuManager::getInstance();
if(ScriptManager::getInstance()->areBlockingCommandsSkipped()) {
 unknown40=-1;menu->setText(static_cast<MenuManager::eText>(2),-1,0);menu->hideDialogArrow();ScriptManager::getInstance()->cinematicCharacterAnimation->SetAnim(-1);return true;
}
if(cmd.argument3!=MenuManager::getInstance()->getTextId(static_cast<MenuManager::eText>(2))) {
 int layout=-1;menu->setText(static_cast<MenuManager::eText>(2),cmd.argument3,&layout);
 ScriptManager::getInstance()->unknown88=0;ScriptManager::getInstance()->unknown84=1;
 int width,height;Application::GetInstance()->GetScreenDimensions(width,height);
 if(height-layout<MenuManager::getInstance()->unknown416) {ScriptManager::getInstance()->unknown88=7;ScriptManager::getInstance()->unknown84=8;}
 ScriptManager::getInstance()->cinematicCharacterAnimation->SetAnim(cmd.argument2);unknown40=cmd.argument1;unknown44=unknown40==0;menu->showDialogArrow();return false;
}
if(unknown40>=0) {unknown40-=elapsed;return false;}
if(!unknown44 || ScriptManager::getInstance()->unknown24[0]) {
 ScriptManager::getInstance()->unknown88=0;ScriptManager::getInstance()->unknown84=1;unknown40=-1;
 menu->setText(static_cast<MenuManager::eText>(2),-1,0);menu->hideDialogArrow();ScriptManager::getInstance()->cinematicCharacterAnimation->SetAnim(-1);return true;
}return false;
    }
    case 57: {
        const Structs::Wait& cmd=*reinterpret_cast<const Structs::Wait*>(command);
if(unknown40==-1) unknown40=ScriptManager::getInstance()->areBlockingCommandsSkipped()?-1:cmd.argument;
else unknown40-=elapsed;
if(unknown40<0 || ScriptManager::getInstance()->areBlockingCommandsSkipped()) unknown40=-1;
return unknown40==-1;
    }
    case 60: {
        const Structs::PlaySfx& cmd=*reinterpret_cast<const Structs::PlaySfx*>(command);
if(!ScriptManager::getInstance()->areBlockingCommandsSkipped()) {
 SoundManager* sound=SoundManager::getInstance();sound->unknown140=true;
 sound->playEx(cmd.argument,0,false,1.0f,0,true,1.0f,0);sound->unknown140=false;
}return true;
    }
    case 61: {
        const Structs::StopSfx& cmd=*reinterpret_cast<const Structs::StopSfx*>(command);
SoundManager::getInstance()->stop(cmd.argument,-1,0);return true;
    }
    case 62: {
        const Structs::PlayMusic& cmd=*reinterpret_cast<const Structs::PlayMusic*>(command);
if(!ScriptManager::getInstance()->areBlockingCommandsSkipped()) {
 SoundManager::getInstance()->stop(25,-1,0);SoundManager::getInstance()->stop(14,-1,0);
 SoundManager::getInstance()->playPriorityAudio(cmd.argument,true);
}return true;
    }
    case 63: {
        const Structs::StopMusic& cmd=*reinterpret_cast<const Structs::StopMusic*>(command);
SoundManager::getInstance()->stop(cmd.argument,-1,0);return true;
    }
    case 105:
    case 64: {
        const Structs::WaitCheckpoint& cmd=*reinterpret_cast<const Structs::WaitCheckpoint*>(command);
if(!source) {
 source=ScriptManager::findObject(cmd.argument,false);
 if(!ScriptManager::getInstance()->areBlockingCommandsSkipped()) {
  source->enable();int type=LevelObject::s_type[source->getObjectType()];
  if(type==5) {NPC* npc=static_cast<NPC*>(source);if(npc->category428!=0xffffffffu && npc->category428!=6)AIManager::getInstance()->addAI(npc,static_cast<gameloft::ai::StateID>(0));}
  else if(type==3) {Vehicle* car=static_cast<Vehicle*>(source);if(car->unknown240!=-1)AIManager::getInstance()->addAI(car,static_cast<gameloft::ai::StateID>(0));}
  else if(type==13)static_cast<Shop*>(source)->trigger(false);
  setScriptObjectAction(source,ActiveObject);
 }
}
if(ScriptManager::getInstance()->areBlockingCommandsSkipped()) {
 if(static_cast<Mission*>(ScriptManager::getInstance()->getMission())->getState()!=0 && !ScriptManager::getInstance()->isInCinematic()) {
  if(source->isEnabled() && LevelObject::s_type[source->getObjectType()]!=13) {source->disable();ScriptManager::displayOnMinimap(source,false,true);unsetScriptObjectAction(source,MinimapObject);unsetScriptObjectAction(source,ActiveObject);}
  ScriptManager::moveObject(reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer())),source);ScriptManager::getInstance()->unknown100=-1;return true;
 }return false;
}
LevelObject* playerObject=reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(ScriptManager::s_playerTest));
if((ScriptManager::s_playerTest->flags240&0x400) && static_cast<SavePositionInterface*>(ScriptManager::s_playerTest)->getVehicle())playerObject=ScriptManager::s_playerTest->getVehicle();
const V& playerPosition=playerObject->GetPosition();
const V& checkpointPosition=source->GetPosition();
float distance=(playerPosition-checkpointPosition).getLength();
bool done;
if(LevelObject::s_type[source->getObjectType()]==13) {
 static_cast<Shop*>(source)->unlock();setScriptObjectAction(source,Flag16);done=static_cast<Shop*>(source)->triggered() || ScriptManager::getInstance()->areBlockingCommandsSkipped();
} else {
 int metatype=source->GetMetatype();bool outside=!(distance<static_cast<Checkpoint*>(source)->getRadius());bool requirements=true;int message=-1;
 if(metatype==23) {
  bool inVehicle=(ScriptManager::s_playerTest->flags240&0x400) && static_cast<SavePositionInterface*>(ScriptManager::s_playerTest)->getVehicle();
  if(command->opcode==105) {
   if(!unknown72)unknown72=ScriptManager::findObject(reinterpret_cast<const Structs::WaitCheckpointCar*>(command)->argument2,false);
   if(unknown72) {
    if(!inVehicle || playerObject!=unknown72) {
     unknown72->showHighlight(1);ScriptManager::displayOnMinimap(unknown72,true,true);setScriptObjectAction(unknown72,Flag2);setScriptObjectAction(unknown72,MinimapObject);if(source->isEnabled())source->disable();requirements=false;
    } else {
     unknown72->showHighlight(-1);ScriptManager::displayOnMinimap(unknown72,false,true);unsetScriptObjectAction(unknown72,Flag2);unsetScriptObjectAction(unknown72,MinimapObject);
     if(!source->isEnabled()) {
      source->enable();int type=LevelObject::s_type[source->getObjectType()];
      if(type==5) {NPC* npc=static_cast<NPC*>(source);if(npc->category428!=0xffffffffu && npc->category428!=6)AIManager::getInstance()->addAI(npc,static_cast<gameloft::ai::StateID>(0));}
      else if(type==3 && static_cast<Vehicle*>(source)->unknown240!=-1)AIManager::getInstance()->addAI(static_cast<Vehicle*>(source),static_cast<gameloft::ai::StateID>(0));
     }
    }
   }
  }
  if(!inVehicle)requirements=false;
  if(!requirements) {
   message=0x3023;
   if(outside) {
    if(command->opcode==105 && !ScriptManager::s_playerTest->getVehicle() && static_cast<Mission*>(ScriptManager::getInstance()->getMission())->getLastObjectiveText()!=0x3059) {
     ScriptManager::getInstance()->unknown100=static_cast<Mission*>(ScriptManager::getInstance()->getMission())->getLastObjectiveText();ScriptManager::getInstance()->missionObjective(0x3059,false);
    }message=-1;
   }
  } else if(command->opcode==105 && ScriptManager::getInstance()->unknown100!=-1 && static_cast<Mission*>(ScriptManager::getInstance()->getMission())->getLastObjectiveText()!=ScriptManager::getInstance()->unknown100) ScriptManager::getInstance()->missionObjective(ScriptManager::getInstance()->unknown100,false);
 } else if(metatype==34 && (ScriptManager::s_playerTest->flags240&0x400) && static_cast<SavePositionInterface*>(ScriptManager::s_playerTest)->getVehicle()) {requirements=false;message=outside?-1:0x3024;}
 done=ScriptManager::getInstance()->areBlockingCommandsSkipped() || (!outside && requirements);
 bool showMarker=false;
 if(!ScriptManager::getInstance()->areBlockingCommandsSkipped()) {
  if(!done)showMarker=true;
  else {
   int minimum=static_cast<Checkpoint*>(source)->unknown88;int maximum=static_cast<Checkpoint*>(source)->unknown92;int wanted=WantedLevelManager::getInstance()->unknown8;
   if(maximum!=-1 && maximum<wanted) {message=0x3021;done=false;showMarker=true;}
   else if(minimum!=-1 && wanted<minimum) {message=0x3022;done=false;showMarker=true;}
   else ScriptManager::displayOnMinimap(source,false,true);
  }
 } else showMarker=!done;
 if(!done) {
  if(command->opcode==105 && !requirements) {unsetScriptObjectAction(source,MinimapObject);ScriptManager::displayOnMinimap(source,false,true);}
  else {if(showMarker)setScriptObjectAction(source,MinimapObject);ScriptManager::displayOnMinimap(source,showMarker,true);}
  if(message!=-1)ScriptManager::getInstance()->message(message);return false;
 }
 if(static_cast<Checkpoint*>(source)->unknown96)ScriptManager::s_playerTest->Stop();
 if(LevelObject::s_type[source->getObjectType()]!=13) {source->disable();unsetScriptObjectAction(source,ActiveObject);}
 ScriptManager::getInstance()->message(-1);
}
if(!done)return false;
ScriptManager::getInstance()->unknown100=-1;ScriptManager::s_playerTest->unknown368=0;ScriptManager::s_playerTest->unknown312=0;ScriptManager::s_playerTest->flags240&=~0x1000;
if(ScriptManager::s_playerTest->unknown372<5) {ScriptManager::s_playerTest->unknown372=0;return true;}
if(ScriptManager::s_playerTest->unknown372!=5)ScriptManager::s_playerTest->stopDriving(playertest::PlayerCarState::MovingOut,true);return true;
    }
    case 65: {
        const Structs::MissionStart& cmd=*reinterpret_cast<const Structs::MissionStart*>(command);
MenuManager::getInstance()->popTo(scriptTutorial,true,true);
int missionState=static_cast<Mission*>(ScriptManager::getInstance()->getMission())->getState();
if(missionState==0) {
 ScriptManager* manager=ScriptManager::getInstance();int id=cmd.argument;
 int duration=ScriptManager::getInstance()->areBlockingCommandsSkipped()?0:-1;
 manager->missionStart(id,duration);ScriptManager::getInstance()->freezeRunningScripts(this,PlayerTest::AnyContext);
} else if(missionState==3 || missionState==4) return true;
return ScriptManager::getInstance()->areBlockingCommandsSkipped();
    }
    case 66: {
        const Structs::MissionObjective& cmd=*reinterpret_cast<const Structs::MissionObjective*>(command);
ScriptManager::getInstance()->missionObjective(cmd.argument,false);return true;
    }
    case 67: {
ScriptManager::getInstance()->missionOver();ScriptManager::getInstance()->unlockFrozenScripts();return true;
    }
    case 68: {
ScriptManager::getInstance()->missionClearConditions();return true;
    }
    case 69: {
        const Structs::ProtectNPC& cmd=*reinterpret_cast<const Structs::ProtectNPC*>(command);
LevelObject* object=ScriptManager::findObject(cmd.argument2,false);
if(LevelObject::s_type[object->getObjectType()]==5) ScriptManager::getInstance()->missionRegisterCondition(new MissionConditionProtectNPC(static_cast<NPC*>(object),cmd.argument1));return true;
    }
    case 70: {
        const Structs::ProtectCar& cmd=*reinterpret_cast<const Structs::ProtectCar*>(command);
LevelObject* object=ScriptManager::findObject(cmd.argument1,false);
if(LevelObject::s_type[object->getObjectType()]==3) ScriptManager::getInstance()->missionRegisterCondition(new MissionConditionProtectCar(static_cast<Vehicle*>(object),cmd.argument2));return true;
    }
    case 71: {
        const Structs::StayWithin& cmd=*reinterpret_cast<const Structs::StayWithin*>(command);
LevelObject* object=ScriptManager::findObject(cmd.argument1,false);ScriptManager::getInstance()->missionRegisterCondition(new MissionConditionStayWithin(object,cmd.argument2,cmd.argument3));return true;
    }
    case 72: {
if(PlayerTest::GetPlayer()->getVehicle()) ScriptManager::getInstance()->missionRegisterCondition(new MissionConditionDriveWell(PlayerTest::GetPlayer()->getVehicle()));return true;
    }
    case 73: {
        const Structs::BeQuick& cmd=*reinterpret_cast<const Structs::BeQuick*>(command);
ScriptManager::getInstance()->missionRegisterCondition(new MissionConditionBeQuick(cmd.argument));return true;
    }
    case 74: {
        const Structs::SetUsUpTheBomb& cmd=*reinterpret_cast<const Structs::SetUsUpTheBomb*>(command);
LevelObject* object=ScriptManager::findObject(cmd.argument2,false);
if(LevelObject::s_type[object->getObjectType()]==3) ScriptManager::getInstance()->missionRegisterCondition(new MissionConditionSetUsUpTheBomb(cmd.argument,static_cast<Vehicle*>(object)));return true;
    }
    case 76: {
        const Structs::LockShop& cmd=*reinterpret_cast<const Structs::LockShop*>(command);
Shop* shop=static_cast<Shop*>(ScriptManager::findObject(cmd.argument,false));shop->lock();setScriptObjectAction(shop,Flag8);return true;
    }
    case 77: {
        const Structs::UnlockShop& cmd=*reinterpret_cast<const Structs::UnlockShop*>(command);
Shop* shop=static_cast<Shop*>(ScriptManager::findObject(cmd.argument,false));shop->unlock();setScriptObjectAction(shop,Flag16);return true;
    }
    case 79: {
        const Structs::GiveWeapon& cmd=*reinterpret_cast<const Structs::GiveWeapon*>(command);
Application* app=Application::GetInstance();int weapon=app->GetWeaponManager()->unlockWeapon(cmd.argument);app->GetHudManager()->switchWeapon(weapon);return true;
    }
    case 80: {
        const Structs::LimitToWeapon& cmd=*reinterpret_cast<const Structs::LimitToWeapon*>(command);
Application::GetInstance()->GetHudManager()->limitToWeapon(cmd.argument);setScriptObjectAction(0,Flag128);return true;
    }
    case 81: {
Application* app=Application::GetInstance();if(app->GetWeaponManager()->getWeaponLimitedTo(PlayerTest::AnyContext)!=-1) Application::GetInstance()->GetHudManager()->limitToWeapon(-1);unsetScriptObjectAction(0,Flag128);return true;
    }
    case 82: {
        const Structs::NPCWeapon& cmd=*reinterpret_cast<const Structs::NPCWeapon*>(command);
LevelObject* object=ScriptManager::findObject(cmd.argument1,false);if(LevelObject::s_type[object->getObjectType()]==5) {NPC* npc=static_cast<NPC*>(object);npc->SetWeapon(cmd.argument2);npc->equipWeapon(false,false);}return true;
    }
    case 83: {
        const Structs::PlaceItem& cmd=*reinterpret_cast<const Structs::PlaceItem*>(command);
LevelObject* object=ScriptManager::findObject(cmd.argument2,false);Item::place(cmd.argument1,object->GetPosition());setScriptObjectAction(0,Flag256);return true;
    }
    case 84: {
Item::removeAllPlacedItems();unsetScriptObjectAction(0,Flag256);return true;
    }
    case 85: {
        const Structs::TagForKill& cmd=*reinterpret_cast<const Structs::TagForKill*>(command);
LevelObject* object=ScriptManager::findObject(cmd.argument,false);int type=LevelObject::s_type[object->getObjectType()];
if(type==3) static_cast<Vehicle*>(object)->tagForKill(true);else if(type==5) static_cast<NPC*>(object)->tagForKill(true);else return true;
++ScriptManager::getInstance()->taggedCount;setScriptObjectAction(object,Flag32);return true;
    }
    case 86: {
if(!source) {
 s_driveBadPoints=1000.0f;s_driveBadVehicle=PlayerTest::GetPlayer()->getVehicle();source=s_driveBadVehicle;if(!s_driveBadVehicle)return false;
 s_driveBadLastHealth=s_driveBadVehicle->getHealth();s_driveBadPointsSpeed=0.0f;s_driveBadPointsJumping=0.0f;s_driveBadPointsDrifting=0.0f;s_driveBadPointsWantedLevel=0.0f;
 s_driveBadLastWantedLevel=WantedLevelManager::getInstance()->unknown8;Application::GetInstance()->GetHudManager()->showSpyGauge(true);
 ScriptManager::getInstance()->unknown100=static_cast<Mission*>(ScriptManager::getInstance()->getMission())->getLastObjectiveText();
}
if(s_driveBadVehicle) {
 CHudManager* hud=Application::GetInstance()->GetHudManager();
 if(ScriptManager::s_playerTest->getVehicle()==s_driveBadVehicle && ScriptManager::s_playerTest->getVehicle()==s_driveBadVehicle) {
  if(static_cast<Mission*>(ScriptManager::getInstance()->getMission())->getLastObjectiveText()!=ScriptManager::getInstance()->unknown100) {
   ScriptManager::getInstance()->missionObjective(ScriptManager::getInstance()->unknown100,false);s_driveBadVehicle->showHighlight(-1);ScriptManager::displayOnMinimap(s_driveBadVehicle,false,true);unsetScriptObjectAction(s_driveBadVehicle,MinimapObject);hud->showSpyGauge(true);s_driveBadLastHealth=s_driveBadVehicle->getHealth();
  }
    const float health = s_driveBadVehicle->getHealth();
    if (health != s_driveBadLastHealth) {
        if (health < s_driveBadLastHealth) {
            const float penalty = (s_driveBadLastHealth - health) * 5;
            if (penalty > 0.0f) {
                printf(scriptLiteral3, penalty);
                s_driveBadPoints -= penalty;
            }
        }
        s_driveBadLastHealth = health;
    }

    if (s_driveBadVehicle->unknown511 & 2) {
        s_driveBadVehicle->unknown511 &= ~2;
        printf(scriptLiteral4, 20.0);
        s_driveBadPoints -= 20.0f;
    }

    if (s_driveBadVehicle->GetSpeed() > 75.0f) {
        const float penalty = (elapsed * 25) / 1000.0f;
        if (penalty > 0.0f) {
            s_driveBadPointsSpeed += penalty;
            s_driveBadPoints -= penalty;
        }
    } else if (s_driveBadPointsSpeed > 0.0f) {
        printf(scriptLiteral7, s_driveBadPointsSpeed);
        s_driveBadPointsSpeed = 0.0f;
    }

    bool airborne=!s_driveBadVehicle->unknown506 && !s_driveBadVehicle->unknown507 && !s_driveBadVehicle->unknown508 && !s_driveBadVehicle->unknown509;
    if(airborne) {
        const float penalty = (elapsed * 50) / 1000.0f;
        if (penalty > 0.0f) {
            s_driveBadPointsJumping += penalty;
            s_driveBadPoints -= penalty;
        }
    } else if (s_driveBadPointsJumping > 0.0f) {
        printf(scriptLiteral6, s_driveBadPointsJumping);
        s_driveBadPointsJumping = 0.0f;
    }

    if (s_driveBadVehicle->skidAmount > 0.0f) {
        const float penalty = (elapsed * 50) / 1000.0f;
        if (penalty > 0.0f) {
            s_driveBadPointsDrifting += penalty;
            s_driveBadPoints -= penalty;
        }
    } else if (s_driveBadPointsDrifting > 0.0f) {
        printf(scriptLiteral9, s_driveBadPointsDrifting);
        s_driveBadPointsDrifting = 0.0f;
    }

    const int currentWantedLevel = WantedLevelManager::getInstance()->unknown8;
    if (currentWantedLevel) {
        const float scaledElapsed = elapsed * 10;
        const float penalty = scaledElapsed / 1000.0f;
        if (penalty > 0.0f) {
            s_driveBadPointsWantedLevel += penalty;
            s_driveBadPoints += scaledElapsed / -1000.0f;
        }
    } else if (s_driveBadPointsWantedLevel > 0.0f) {
        printf(scriptLiteral8, s_driveBadPointsWantedLevel);
        s_driveBadPointsWantedLevel = 0.0f;
    }

    const int previousWantedLevel = s_driveBadLastWantedLevel;
    if (currentWantedLevel != previousWantedLevel) {
        if (currentWantedLevel > previousWantedLevel) {
            const float penalty = (currentWantedLevel - previousWantedLevel) * 100;
            if (penalty > 0.0f) {
                printf(scriptLiteral5, penalty);
                s_driveBadPoints -= penalty;
            }
        }
        s_driveBadLastWantedLevel = currentWantedLevel;
    }


  if(s_driveBadPoints<0.0f)s_driveBadPoints=0.0f;hud->spyGauge->setPercentage(s_driveBadPoints/1000.0f);
  if((!airborne && s_driveBadPoints<=0.0f) || ScriptManager::getInstance()->areBlockingCommandsSkipped()) {hud->showSpyGauge(false);ScriptManager::getInstance()->unknown100=-1;return true;}
 } else if(static_cast<Mission*>(ScriptManager::getInstance()->getMission())->getLastObjectiveText()!=0x3059) {
  ScriptManager::getInstance()->unknown100=static_cast<Mission*>(ScriptManager::getInstance()->getMission())->getLastObjectiveText();ScriptManager::getInstance()->missionObjective(0x3059,false);
  ScriptManager::displayOnMinimap(s_driveBadVehicle,true,true);s_driveBadVehicle->showHighlight(1);ScriptManager::displayOnMinimap(s_driveBadVehicle,true,true);setScriptObjectAction(s_driveBadVehicle,MinimapObject);hud->showSpyGauge(false);
 }
}return false;
    }
    case 87: {
        const Structs::WaitKilled& cmd=*reinterpret_cast<const Structs::WaitKilled*>(command);
if(!source)source=ScriptManager::findObject(cmd.argument,false);
bool flag=LevelObject::s_type[source->getObjectType()]!=3 || static_cast<Vehicle*>(source)->explosionFinished;
if((!source->isDead() || !flag) && !ScriptManager::getInstance()->areBlockingCommandsSkipped()) {
 source->showHighlight(0);ScriptManager::displayOnMinimap(source,true,true);setScriptObjectAction(source,Flag2);setScriptObjectAction(source,MinimapObject);return false;
}
source->showHighlight(-1);ScriptManager::displayOnMinimap(source,false,true);unsetScriptObjectAction(source,Flag2);unsetScriptObjectAction(source,MinimapObject);return true;
    }
    case 88: {
        const Structs::WaitShot& cmd=*reinterpret_cast<const Structs::WaitShot*>(command);
if(!source)source=ScriptManager::findObject(cmd.argument,false);
if(!source->isPhotographed() && !ScriptManager::getInstance()->areBlockingCommandsSkipped()) return false;
source->showHighlight(-1);ScriptManager::displayOnMinimap(source,false,true);unsetScriptObjectAction(source,Flag2);unsetScriptObjectAction(source,MinimapObject);return true;
    }
    case 89: {
        const Structs::WaitStolen& cmd=*reinterpret_cast<const Structs::WaitStolen*>(command);
bool done=(ScriptManager::s_playerTest->getVehicle() && ScriptManager::s_playerTest->getVehicle()->getName() && !strcmp(ScriptManager::s_playerTest->getVehicle()->getName(),cmd.argument)) || ScriptManager::getInstance()->areBlockingCommandsSkipped();
if(!source) {source=ScriptManager::findObject(cmd.argument,false);if(ScriptManager::getInstance()->areBlockingCommandsSkipped()) ScriptManager::moveObject(reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer())),source);}
source->showHighlight(done?-1:1);ScriptManager::displayOnMinimap(source,!done,true);
if(LevelObject::s_type[source->getObjectType()]==3 && static_cast<Vehicle*>(source)->explosionFlag) ScriptManager::getInstance()->missionFail();
if(done) {unsetScriptObjectAction(source,Flag2);unsetScriptObjectAction(source,MinimapObject);}else{setScriptObjectAction(source,Flag2);setScriptObjectAction(source,MinimapObject);}return done;
    }
    case 90: {
        const Structs::WaitWantedLevel& cmd=*reinterpret_cast<const Structs::WaitWantedLevel*>(command);
return WantedLevelManager::getInstance()->unknown8==cmd.argument || ScriptManager::getInstance()->areBlockingCommandsSkipped();
    }
    case 91: {
return ScriptManager::getInstance()->taggedCount==0 || ScriptManager::getInstance()->areBlockingCommandsSkipped();
    }
    case 96: {
        const Structs::SetWantedLevel& cmd=*reinterpret_cast<const Structs::SetWantedLevel*>(command);
WantedLevelManager* wanted=WantedLevelManager::getInstance();int level=cmd.argument;if(level>5)level=5;else if(level<0)level=0;wanted->unknown8=level;wanted->_processWantedLevel();return true;
    }
    case 97: {
        const Structs::RaiseWantedLevel& cmd=*reinterpret_cast<const Structs::RaiseWantedLevel*>(command);
if(WantedLevelManager::getInstance()->unknown8<cmd.argument) {WantedLevelManager* wanted=WantedLevelManager::getInstance();int level=cmd.argument;if(level>5)level=5;else if(level<0)level=0;wanted->unknown8=level;wanted->_processWantedLevel();}return true;
    }
    case 98: {
        const Structs::DropWantedLevel& cmd=*reinterpret_cast<const Structs::DropWantedLevel*>(command);
if(cmd.argument<WantedLevelManager::getInstance()->unknown8) {WantedLevelManager* wanted=WantedLevelManager::getInstance();int level=cmd.argument;if(level>5)level=5;else if(level<0)level=0;wanted->unknown8=level;wanted->_processWantedLevel();}return true;
    }
    case 99: {
        const Structs::StopObject& cmd=*reinterpret_cast<const Structs::StopObject*>(command);
ScriptManager::findObject(cmd.argument,false)->Stop();return true;
    }
    case 100: {
        const Structs::SpyTarget& cmd=*reinterpret_cast<const Structs::SpyTarget*>(command);
LevelObject* object=ScriptManager::findObject(cmd.argument1,false);ScriptManager::getInstance()->missionRegisterCondition(new MissionConditionStayBetween(object,cmd.argument2,cmd.argument3));return true;
    }
    case 101: {
        const Structs::WaitEscape& cmd=*reinterpret_cast<const Structs::WaitEscape*>(command);
LevelObject* original=ScriptManager::findObject(cmd.argument1,false);int minimum=cmd.argument2;LevelObject* target=original;
if(LevelObject::s_type[original->getObjectType()]==5 && (!original->isEnabled() || ((static_cast<Character*>(original)->movementFlags&0x400) && static_cast<Character*>(original)->getVehicle()))) target=static_cast<Character*>(original)->getVehicle();
if(!original->sceneNode || !original->sceneNode->isVisible()) {
 if(LevelObject::s_type[original->getObjectType()]==5) {original->showHighlight(0);Character* actor=static_cast<Character*>(original);if(actor->getVehicle()){actor->getVehicle()->showHighlight(0);setScriptObjectAction(actor->getVehicle(),Flag2);}}
 else original->showHighlight(-1);
 ScriptManager::displayOnMinimap(original,true,true);setScriptObjectAction(original,Flag2);setScriptObjectAction(original,MinimapObject);
}
float distance;PlayerTest* player=PlayerTest::GetPlayer();
if((player->flags240&0x400) && static_cast<SavePositionInterface*>(player)->getVehicle()) {
 const V& playerPosition=PlayerTest::GetPlayer()->getVehicle()->GetPosition();const V& targetPosition=target->GetPosition();distance=(playerPosition-targetPosition).getLength();
}else {
 const V& playerPosition=reinterpret_cast<LevelObject*>(static_cast<SavePositionInterface*>(PlayerTest::GetPlayer()))->GetPosition();const V& targetPosition=target->GetPosition();distance=(playerPosition-targetPosition).getLength();
}
int type=LevelObject::s_type[target->getObjectType()];
if(target->isEnabled() && ((type!=5 && type!=3) || !target->isDead()) && !(distance>=minimum) && !ScriptManager::getInstance()->areBlockingCommandsSkipped()) return false;
original->showHighlight(-1);
if(LevelObject::s_type[original->getObjectType()]==5 && static_cast<Character*>(original)->getVehicle()) {Vehicle* car=static_cast<Character*>(original)->getVehicle();car->showHighlight(-1);unsetScriptObjectAction(car,Flag2);}
ScriptManager::displayOnMinimap(original,false,true);unsetScriptObjectAction(original,ActiveObject);unsetScriptObjectAction(original,Flag2);unsetScriptObjectAction(original,MinimapObject);return true;
    }
    case 102: {
        const Structs::StartRace& cmd=*reinterpret_cast<const Structs::StartRace*>(command);
if(!source) {
 source=ScriptManager::findObject(cmd.argument,false);ScriptManager::s_raceTimer=3000;
 static_cast<Race*>(ScriptManager::getInstance()->getRace())->ready();setScriptObjectAction(0,Flag64);
 WantedLevelManager::getInstance()->storeWantedLevel();WantedLevelManager::getInstance()->resetWantedLevel();WantedLevelManager::getInstance()->lock(0);ScriptManager::getInstance()->missionObjective(0x60b0,true);
}
if(!ScriptManager::getInstance()->areBlockingCommandsSkipped() && ScriptManager::s_raceTimer>0) {
 ScriptManager::s_raceTimer-=elapsed;if(ScriptManager::s_raceTimer<0)ScriptManager::s_raceTimer=0;
 int seconds=(ScriptManager::s_raceTimer+1000)/1000;
 if(seconds!=ScriptManager::s_raceTimeSeconds) {
  ScriptManager::s_raceTimeSeconds=seconds;static char buffer[12];sprintf(buffer,scriptCountdownFormat,seconds);
  MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(12),buffer,0);
  SoundManager* sound=SoundManager::getInstance();sound->unknown140=true;sound->playEx(221,0,false,1.0f,0,true,1.0f,0);sound->unknown140=false;
 }return false;
}
SoundManager* sound=SoundManager::getInstance();sound->unknown140=true;sound->playEx(216,0,false,1.0f,0,true,1.0f,0);sound->unknown140=false;
static_cast<Race*>(ScriptManager::getInstance()->getRace())->setPlayerPath(static_cast<Path*>(source));static_cast<Race*>(ScriptManager::getInstance()->getRace())->go();
MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(12),0x30f7,0);Application::GetInstance()->GetHudManager()->show();ScriptManager::s_raceTimer=2000;return true;
    }
    case 103: {
        const Structs::AddRacer& cmd=*reinterpret_cast<const Structs::AddRacer*>(command);
const Path* path=static_cast<Path*>(ScriptManager::findObject(cmd.argument3,false));Vehicle* car=static_cast<Vehicle*>(ScriptManager::findObject(cmd.argument1,false));static_cast<Race*>(ScriptManager::getInstance()->getRace())->addOpponent(car,path,cmd.argument2);return true;
    }
    case 104: {
if(static_cast<Race*>(ScriptManager::getInstance()->getRace())->evaluate() && !ScriptManager::getInstance()->areBlockingCommandsSkipped()) {
 if(ScriptManager::s_raceTimer<0)MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(12),-1,0);ScriptManager::s_raceTimer-=elapsed;return false;
}
if(!static_cast<Race*>(ScriptManager::getInstance()->getRace())->isPlayerWinner() && !ScriptManager::getInstance()->areBlockingCommandsSkipped()) {
 MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(12),-1,0);static_cast<Race*>(ScriptManager::getInstance()->getRace())->reset();ScriptManager::getInstance()->missionFail();return false;
}
MenuManager::getInstance()->setText(static_cast<MenuManager::eText>(12),-1,0);static_cast<Race*>(ScriptManager::getInstance()->getRace())->reset();unsetScriptObjectAction(0,Flag64);WantedLevelManager::getInstance()->unlock();WantedLevelManager::getInstance()->restoreWantedLevel();return true;
    }
    case 106: {
        const Structs::DestroyCar& cmd=*reinterpret_cast<const Structs::DestroyCar*>(command);
static_cast<Vehicle*>(ScriptManager::findObject(cmd.argument,false))->explode();return true;
    }
    case 107: {
        const Structs::KillNPC& cmd=*reinterpret_cast<const Structs::KillNPC*>(command);
static_cast<Character*>(ScriptManager::findObject(cmd.argument,false))->health=0;return true;
    }
    case 108: {
        const Structs::WaitForLock& cmd=*reinterpret_cast<const Structs::WaitForLock*>(command);
if(!source)source=ScriptManager::findObject(cmd.argument,false);
if(Lock::getInstance()->target!=source && !ScriptManager::getInstance()->areBlockingCommandsSkipped() && !source->isDead()) {
 source->showHighlight(0);ScriptManager::displayOnMinimap(source,true,true);setScriptObjectAction(source,Flag2);setScriptObjectAction(source,MinimapObject);return false;
}
source->showHighlight(-1);ScriptManager::displayOnMinimap(source,false,true);unsetScriptObjectAction(source,Flag2);unsetScriptObjectAction(source,MinimapObject);return true;
    }
    case 109: {
PlayerTest* player=PlayerTest::GetPlayer();SoundManager::getInstance()->stop(player->getAmbientSound(),-1,1000);
contextWord=0;PlayerTest::GetPlayer()->switchContext(context,true);
SoundManager* sound=SoundManager::getInstance();int ambient=player->getAmbientSound();sound->unknown140=true;sound->playEx(ambient,0,true,1.0f,1000,true,1.0f,0);sound->unknown140=false;return true;
    }
    case 110: {
PlayerTest* player=PlayerTest::GetPlayer();SoundManager::getInstance()->stop(player->getAmbientSound(),-1,1000);
contextWord=1;PlayerTest::GetPlayer()->switchContext(context,true);
SoundManager* sound=SoundManager::getInstance();int ambient=player->getAmbientSound();sound->unknown140=true;sound->playEx(ambient,0,true,1.0f,1000,true,1.0f,0);sound->unknown140=false;return true;
    }
    case 111: {
        const Structs::HudHighlight& cmd=*reinterpret_cast<const Structs::HudHighlight*>(command);
if(ScriptManager::getInstance()->unknown78) Application::GetInstance()->GetHudManager()->blink(cmd.argument);return true;
    }
    case 112: {
        const Structs::ShowTutorial& cmd=*reinterpret_cast<const Structs::ShowTutorial*>(command);
if(ScriptManager::getInstance()->unknown78) {MenuManager::getInstance()->setTutorialIds(cmd.argument2,cmd.argument1);StateMachine::getInstance()->pushState<GSBlockingTutorial>();}return true;
    }
    case 113: {
AchievementManager::s_achievementManager->recordEndChapter();return true;
    }
    case 114: {
        const Structs::SetPhotoTarget& cmd=*reinterpret_cast<const Structs::SetPhotoTarget*>(command);
if(!source) source=ScriptManager::findObject(cmd.argument,false);source->showHighlight(0);ScriptManager::displayOnMinimap(source,true,true);setScriptObjectAction(source,Flag2);setScriptObjectAction(source,MinimapObject);PlayerTest::GetPlayer()->addPhotoTarget(source);return true;
    }
    case 115: {
        const Structs::FlagAsInRace& cmd=*reinterpret_cast<const Structs::FlagAsInRace*>(command);
source=ScriptManager::findObject(cmd.argument,false);static_cast<Vehicle*>(source)->flags344|=0x10000000;return true;
    }
    case 116: {
        const Structs::WaitIfNotPhotographed& cmd=*reinterpret_cast<const Structs::WaitIfNotPhotographed*>(command);
if(!source) {source=ScriptManager::findObject(cmd.argument1,false);unknown40=ScriptManager::getInstance()->areBlockingCommandsSkipped()?-1:cmd.argument2;}
unknown40-=elapsed;
if(unknown40<=0 || source->isPhotographed() || ScriptManager::getInstance()->areBlockingCommandsSkipped()) unknown40=-1;
return unknown40==-1;
    }
    case 117: {
        const Structs::PhotographQuickly& cmd=*reinterpret_cast<const Structs::PhotographQuickly*>(command);
source=ScriptManager::findObject(cmd.argument1,false);ScriptManager::getInstance()->missionRegisterCondition(new MissionConditionPhotographQuickly(source,cmd.argument2));return true;
    }
    default:return true;
    }
}
