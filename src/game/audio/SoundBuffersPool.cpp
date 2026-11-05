/*
 * SoundBuffersPool
 *
 * Original file: SoundBuffersPool.cpp
 * Area:          audio
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of SoundBuffersPool.cpp here, in the order they appear in the library.
 */

#include "SoundBuffersPool.h"

void CSoundBuffers::ReleaseSoundBuffer(char* buffer)
{
    if (!buffer)
        return;
    int index = -1;
    for (int i = 0; i <= lastUsed && index < 0; ++i)
        if (slots[i] == buffer)
            index = i;
    if (index < 0)
        return;
    if (firstFree > index)
        firstFree = index;
    if (index == lastUsed) {
        --lastUsed;
        while (lastUsed >= 0 && state[lastUsed] != 1)
            --lastUsed;
    }
    state[index] = 0;
}

char* CSoundBuffers::GetSoundBuffer()
{
    if (firstFree >= capacity)
        return 0;
    if (state[firstFree] == -1)
        slots[firstFree] = new char[bufferSize];
    char* buffer = slots[firstFree];
    state[firstFree] = 1;
    if (firstFree > lastUsed)
        lastUsed = firstFree;
    int i = firstFree + 1;
    while (i < capacity && state[i] == 1)
        ++i;
    firstFree = i;
    return buffer;
}

CSoundBuffers::CSoundBuffers(int maxCount, int preallocate, int size)
{
    capacity = maxCount;
    bufferSize = size;
    initialCount = preallocate;
    slots = new char*[maxCount];
    state = new int[maxCount];
    int i = 0;
    for (; i < preallocate; ++i) {
        state[i] = 0;
        slots[i] = new char[size];
    }
    for (int i = preallocate; i < maxCount; ++i) {
        state[i] = -1;
        slots[i] = 0;
    }
    firstFree = 0;
    lastUsed = -1;
}

CSoundBuffers::~CSoundBuffers()
{
    for (int i = 0; i < capacity; ++i)
        delete[] slots[i];
    delete[] slots;
    slots = 0;
    delete[] state;
}
