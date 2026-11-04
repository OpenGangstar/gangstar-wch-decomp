#ifndef WCH_AI_RADIO_STATION_CONTROLLER_H
#define WCH_AI_RADIO_STATION_CONTROLLER_H

class DataStream;

namespace Structs {
struct RadioStation {
    void Read(DataStream& stream) __attribute__((weak));

    int jingleCount;
    int* jingles;
    int songCount;
    int* songs;
    int unknown16;
};
}

class RadioStationController {
public:
    ~RadioStationController();
    int selectRandomAd();
    int selectRandomSong(int station);
    int selectRandomJingle(int station);

private:
    struct StationQueue {
        int* songs;
        int songsRemaining;
        int* jingles;
        int jinglesRemaining;
    };
    int unknown0;
    int* availableAds;
    int* ads;
    int adsRemaining;
    int adCount;
    StationQueue** queues;
    Structs::RadioStation** stations;

public:
    int stationCount;
};
#endif
