#ifndef WCH_HUD_TARGET_MARKER_SINGLETON_H
#define WCH_HUD_TARGET_MARKER_SINGLETON_H

#include "TargetMarker.h"

// Included by translation units that emitted the retail singleton or its cleanup.
inline TargetMarker* TargetMarker::getInstance()
{
    static TargetMarker map;
    return &map;
}

#endif
