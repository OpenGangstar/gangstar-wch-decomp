#ifndef WCH_PERSISTENCE_SAVE_GAME_INTERFACES_H
#define WCH_PERSISTENCE_SAVE_GAME_INTERFACES_H

#include "../combat/Weapon.h"
#include "../combat/WeaponManager.h"
#include "../meta/Achievements.h"
#include "../world/LevelObject.h"
#include "../world/GameObjectManager.h"
#include "../scripting/ScriptManager.h"
#include "../scripting/Script.h"
#include "../missions/WantedLevelManager.h"

// Partial interfaces and layouts observed by the SaveGame routines.
// They describe accessed offsets only. Do not instantiate these classes or
// assume these declarations establish their complete layouts or original names.
class GSLoading { public: static bool isGameLoaded(); };
class Checkpoint { public: static bool s_bTutoCallContact; };

class GSFailure { public: static bool s_bCutsceneDie, s_bCutsceneBusted, s_bCutsceneMissionFailed; };
class CControlManager { public: static bool s_cameraTutorial, s_sniperTutorial; };

#endif
