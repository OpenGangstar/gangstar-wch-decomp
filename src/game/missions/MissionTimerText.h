#ifndef WCH_MISSIONS_MISSION_TIMER_TEXT_H
#define WCH_MISSIONS_MISSION_TIMER_TEXT_H

#include "../hud/MenuManager.h"

extern "C" int sprintf(char*, const char*, ...);

// Retail emits this formatting and HUD update in each countdown.
inline __attribute__((always_inline)) void showMissionTimer(char* text, int duration)
{
    int minutes = duration / 60000;
    int seconds = (duration / 1000) % 60;
    int tenths = (duration % 1000) / 100;
    sprintf(text, "%02d:%02d:%01d", minutes, seconds, tenths);
    MenuManager::getInstance()->setText(MenuManager::MissionTimerText, text, 0);
}

#endif
