// Unmatched parent remains pending; verifies actual compiler-generated ARM thunk.
#include "../../src/game/missions/WantedLevelManager.cpp"
#include "../../src/game/meta/Achievements.h"

void WantedLevelManager::update(double elapsed)
{
    Application* application = Application::GetInstance();
    if (unknown72 > 0) {
        application->GetHudManager()->wantedMeter->resetTimer();
        unknown77 = false;
        unknown78 = false;
        return;
    }
    const bool restart = unknown76;
    if (restart) {
        unknown56 = 0.0;
        unknown77 = true;
        unknown76 = false;
        return;
    }
    const bool firstTimerActive = unknown77;
    if (firstTimerActive) {
        const double current = unknown56;
        if (current >= unknown40) {
            application->GetHudManager()->wantedMeter->timer = 1;
            unknown77 = restart;
            unknown78 = true;
            unknown64 = 0.0;
        } else {
            unknown56 = current + elapsed;
        }
        return;
    }
    if (unknown78) {
        const double current = unknown64;
        if (current >= unknown48) {
            application->GetHudManager()->wantedMeter->timer = firstTimerActive;
            if (!locked)
                lockedLevel = unknown8;
            if (--unknown8 > 0) {
                unknown76 = true;
            } else {
                EvWantedEscaped event;
                application->GetEventManager()->raise(event);
            }
            if (unknown8 < 0)
                unknown8 = 0;
            else
                AchievementManager::s_achievementManager->recordBadgesEscaped(1);
            _processWantedLevel();
            unknown78 = false;
        } else {
            unknown64 = elapsed + current;
        }
    }
}
