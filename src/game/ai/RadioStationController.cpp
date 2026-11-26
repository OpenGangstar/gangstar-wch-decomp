/*
 * RadioStationController
 *
 * Original file: RadioStationController.cpp
 * Area:          ai
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of RadioStationController.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK string startup callbacks.
#include "RadioStationController.h"
#include "../core/Randomizer.h"
#include "../persistence/DataStream.h"

int RadioStationController::selectRandomAd()
{
    if (!adsRemaining) {
        for (int i = 0; i < adCount; ++i)
            availableAds[i] = ads[i];
        adsRemaining = adCount;
    }
    int index = irr::os::Randomizer::rand() % adsRemaining;
    int ad = availableAds[index];
    --adsRemaining;
    for (int i = index; i < adsRemaining; ++i)
        availableAds[i] = availableAds[i + 1];
    return ad;
}

RadioStationController::~RadioStationController()
{
    for (int i = 0; i < stationCount; ++i) {
        delete[] stations[i]->songs;
        delete[] stations[i]->jingles;
        delete stations[i];
        delete[] queues[i]->songs;
        delete[] queues[i]->jingles;
        delete queues[i];
    }
    delete[] stations;
    delete[] queues;
    delete[] availableAds;
    delete[] ads;
}

void Structs::RadioStation::Read(DataStream& stream)
{
    jingleCount = stream.ReadInt();
    jingles = new int[jingleCount];
    for (int i = 0; i < jingleCount; ++i)
        jingles[i] = stream.ReadInt();
    songCount = stream.ReadInt();
    songs = new int[songCount];
    for (int i = 0; i < songCount; ++i)
        songs[i] = stream.ReadInt();
    unknown16 = stream.ReadInt();
}

#include "../core/LocalStringStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_0() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
}

extern "C" {
static void __tcf_0()
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_0), &__dso_handle);
    }
}

extern "C" {
static void _GLOBAL__I__ZN22RadioStationControllerC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN22RadioStationControllerC2Ev()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

#include "../world/ResStream.h"

RadioStationController::RadioStationController()
{
    unknown0 = 0;
    ResStream stationResource("./RadioStation.gmap", 1);
    DataStream stationData(stationResource, DataStream::BigEndian);
    stationCount = stationData.ReadInt();
    stations = new Structs::RadioStation*[stationCount];
    queues = new StationQueue*[stationCount];
    for (int i = 0; i < stationCount; ++i) {
        int size = stationData.ReadInt();
        int end = stationData.DataStream::Tell() + size;
        Structs::RadioStation* station = new Structs::RadioStation();
        station->Read(stationData);
        if (stationData.DataStream::Tell() != end)
            stationData.DataStream::Seek(end, 0);
        stations[i] = station;
        queues[i] = new StationQueue();
        queues[i]->songs = new int[stations[i]->songCount];
        queues[i]->jingles = new int[stations[i]->jingleCount];
        for (int j = 0; j < stations[i]->songCount; ++j)
            queues[i]->songs[j] = stations[i]->songs[j];
        queues[i]->songsRemaining = stations[i]->songCount;
        for (int j = 0; j < stations[i]->jingleCount; ++j)
            queues[i]->jingles[j] = stations[i]->jingles[j];
        queues[i]->jinglesRemaining = stations[i]->jingleCount;
    }
    stationData.Stream::Close();
    stationResource.BufferStream::Close();

    ResStream adResource("./RadioAds.array", 1);
    DataStream adData(adResource, DataStream::BigEndian);
    adsRemaining = adCount = adData.ReadInt();
    ads = new int[adCount];
    availableAds = new int[adCount];
    for (int i = 0; i < adCount; ++i)
        availableAds[i] = ads[i] = adData.ReadInt();
    adData.Stream::Close();
    adResource.BufferStream::Close();
}

int RadioStationController::selectRandomJingle(int station)
{
    if (!queues[station]->jinglesRemaining) {
        Structs::RadioStation* source=stations[station];
        int count=source->jingleCount;
        for (int i=0; i<count; ++i) {
            queues[station]->jingles[i]=source->jingles[i];
            source=*(station + stations);
            count=source->jingleCount;
        }
        queues[station]->jinglesRemaining=count;
    }
    int index=irr::os::Randomizer::rand()%queues[station]->jinglesRemaining;
    int jingle=queues[station]->jingles[index];
    --queues[station]->jinglesRemaining;
    for (int i=index; i<queues[station]->jinglesRemaining; ++i)
        queues[station]->jingles[i]=queues[station]->jingles[i+1];
    return jingle;
}

int RadioStationController::selectRandomSong(int station)
{
    if (!queues[station]->songsRemaining) {
        Structs::RadioStation* source=stations[station];
        int count=source->songCount;
        for (int i=0; i<count; ++i) {
            queues[station]->songs[i]=source->songs[i];
            source=*(station + stations);
            count=source->songCount;
        }
        queues[station]->songsRemaining=count;
    }
    int index=irr::os::Randomizer::rand()%queues[station]->songsRemaining;
    int song=queues[station]->songs[index];
    --queues[station]->songsRemaining;
    for (int i=index; i<queues[station]->songsRemaining; ++i)
        queues[station]->songs[i]=queues[station]->songs[i+1];
    return song;
}
