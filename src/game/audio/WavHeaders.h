#ifndef WCH_AUDIO_WAV_HEADERS_H
#define WCH_AUDIO_WAV_HEADERS_H

struct __sFILE;
struct RiffHeader;

struct FormatHeader {
    char id[4];
    unsigned int size;
    unsigned short tag;
    unsigned short channels;
    unsigned int sampleRate;
    unsigned int bytesPerSecond;
    unsigned short blockAlignment;
    unsigned short bitsPerSample;
};

#endif
