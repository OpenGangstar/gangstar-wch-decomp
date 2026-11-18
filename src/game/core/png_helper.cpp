/*
 * png_helper
 *
 * Original file: png_helper.cpp
 * Area:          core
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of png_helper.cpp here, in the order they appear in the library.
 */

extern "C" void* memset(void*, int, unsigned int);
extern "C" void* memcpy(void*, const void*, unsigned int);
extern "C" int memcmp(const void*, const void*, unsigned int);
extern "C" unsigned int strlen(const char*);

void* png_memset(void* destination, unsigned char value, int length)
{
    memset(destination, value, length);
    return destination;
}

void* png_memcpy(void* destination, const void* source, int length)
{
    memcpy(destination, source, length);
    return destination;
}

int png_memcmp(const void* first, const void* second, int length)
{
    return memcmp(first, second, length);
}

int png_strlen(const char* text)
{
    return strlen(text);
}
