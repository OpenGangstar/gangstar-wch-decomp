/*
 * MediaPlayerIPhone
 *
 * Original file: MediaPlayerIPhone.cpp
 * Area:          app
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of MediaPlayerIPhone.cpp here, in the order they appear in the library.
 */

// Observed call interface only; no payload or base layout is asserted.
class MediaPlayerIPhone {
public:
    MediaPlayerIPhone();
    void playMovie(const char* filename);
    void stopMovie();
    void _trace(const char* text) const;
};
namespace {
const char enterText[] __attribute__((section(".rodata.media_player_enter"))) = "->MediaPlayerIPhone()";
const char leaveText[] __attribute__((section(".rodata.media_player_leave"))) = "<-MediaPlayerIPhone()";
}
MediaPlayerIPhone::MediaPlayerIPhone()
{
    _trace(enterText);
    _trace(leaveText);
}

#include "../core/Logs.h"
namespace {
const char traceCategory[] __attribute__((section(".rodata.media_player_category"))) = "MediaPlayerIPhone";
}
void MediaPlayerIPhone::_trace(const char* text) const
{
    Logs::trace(traceCategory, text);
}


void MediaPlayerIPhone::playMovie(const char*) {}
void MediaPlayerIPhone::stopMovie() {}
