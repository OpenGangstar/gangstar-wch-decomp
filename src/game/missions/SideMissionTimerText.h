#ifndef WCH_MISSIONS_SIDE_MISSION_TIMER_TEXT_H
#define WCH_MISSIONS_SIDE_MISSION_TIMER_TEXT_H

#include "../core/NativeStdio.h"

inline __attribute__((always_inline)) void formatSideMissionTime(char* text, const char* format, int time)
{
    sprintf(text, format, time / 60000, time / 1000 % 60, time % 1000 / 100);
}

#endif
