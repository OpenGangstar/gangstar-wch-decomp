#ifndef WCH_AUDIO_ISOUND_DECODER_H
#define WCH_AUDIO_ISOUND_DECODER_H

class ISoundDecoder {
public:
    virtual ~ISoundDecoder() {}
    virtual int Decode(short* output, int count, bool loop) = 0;
    virtual void GoTo(int position) = 0;
    virtual int GetNumSamplesPerDecode(int count);
    virtual int GetSamplingRate() const;
    virtual int GetChannel() const;
    virtual int GetPCMSize() const;
    virtual int GetNbEffectiveSamples() const;
    virtual int GetTotalSamples() const;
    virtual bool HasMoreData() const;
};

#endif
