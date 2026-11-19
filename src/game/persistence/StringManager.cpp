/*
 * StringManager
 *
 * Original file: StringManager.cpp
 * Area:          persistence
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of StringManager.cpp here, in the order they appear in the library.
 */

// Recovered translation-unit SDK startup callbacks.
#include "../core/LocalSdkStartupStorage.h"
#include "../core/LocalStartupText.h"

void operator delete(void*) throw();
extern "C" {
static void __tcf_2() __attribute__((used));
}

extern void* __dso_handle;
extern "C" {
int __aeabi_atexit(void*, void (*)(void*), void*);
void* _ZN3irr4core6stringIcNS0_12irrAllocatorIcEEEaSIcEERS4_PKT_(void*, const char*) __attribute__((weak));
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
        __aeabi_atexit(0, reinterpret_cast<void (*)(void*)>(__tcf_2), &__dso_handle);
        new (irr::ps::vHalf) irr::ps::LocalVector3(0.5f, 0.5f, 0.5f);
    }
}

extern "C" {
static void _GLOBAL__I__ZN13StringManager9LANGUAGESE() __attribute__((used));
static void _GLOBAL__I__ZN13StringManager9LANGUAGESE()
{
    __static_initialization_and_destruction_0(1, 65535);
}
}

extern "C" {
static void __tcf_2()
{
    irr::scene::quake3::LocalStringStorage& value = irr::scene::quake3::irrEmptyStringc;
    if (!value.reference && value.array && value.array != value.inlineBuffer)
        ::operator delete(value.array);
}
}

#include "StringManager.h"

bool StringManager::isPackLoaded(unsigned int pack) const
{
    return packSheets[pack][0] != 0;
}

bool StringManager::isPackSheetLoaded(unsigned int pack, unsigned int sheet) const
{
    return packSheets[pack][sheet] != 0;
}

bool StringManager::switchPack(unsigned int pack)
{
    if (isPackLoaded(pack)) {
        currentPack = pack;
        return true;
    }
    return false;
}

int StringManager::getNumberOfLoadedPack() const
{
    int count = 0;
    for (unsigned int pack = 0; pack < 6; ++pack)
        count += isPackLoaded(pack);
    return count;
}

void StringManager::unloadPack(unsigned int pack)
{
    if (isPackLoaded(pack)) {
        for (unsigned int sheet = 0; sheet < 12; ++sheet)
            unloadPackSheet(pack, sheet);
    }
}

#include "../core/NativeStdio.h"

StringManager::StringManager() : currentPack(-1), unknown296(-1)
{
    memset(packSheets, 0, sizeof(packSheets));
}

int StringManager::loadPack(unsigned int pack)
{
    if (!isPackLoaded(pack))
        loadPackSheet(pack, 0);
    return 0;
}

extern "C" unsigned int nativeStrlen(const char* text);

void strRev(char* text)
{
    char* end = text + nativeStrlen(text) - 1;
    char* start = text;
    while (start < end) {
        const char value = *start;
        *start++ = *end;
        *end-- = value;
    }
}

#include "../core/NativeStdio.h"

char* strchrs(char* text, const char* characters)
{
    const int textLength = strlen(text);
    const int characterCount = strlen(characters);
    for (int i = 0; i < textLength; ++i) {
        for (int j = 0; j < characterCount; ++j) {
            if (text[i] == characters[j])
                return text + i;
        }
    }
    return 0;
}

const char* StringManager::getString(int id) const
{
    const unsigned int sheet = (static_cast<unsigned int>(id) >> 12) & 15u;
    if (!isPackSheetLoaded(currentPack, sheet))
        const_cast<StringManager*>(this)->loadPackSheet(currentPack, sheet);
    return static_cast<const char* const*>(packSheets[currentPack][sheet])[id & 0xfff];
}

#include "DataStream.h"
#include "TextStyle.h"

void Structs::TextStyle::Read(DataStream& stream)
{
    unknown0 = stream.ReadInt();
    fontName = stream.ReadAndAllocateString();
    fontSize = stream.ReadInt();
    unknown12 = stream.ReadBoolean();
    unknown16 = stream.ReadInt();
    unknown20 = stream.ReadInt();
    unknown24 = stream.ReadInt();
    unknown28 = stream.ReadInt();
    unknown32 = stream.ReadInt();
    unknown36 = stream.ReadBoolean();
    unknown37 = stream.ReadBoolean();
}

#include "../core/NativeStdio.h"
extern "C" void abort(void) __attribute__((noreturn));
namespace std {
void __stl_throw_out_of_range(const char* message) __attribute__((weak));
void __stl_throw_out_of_range(const char* message)
{
    puts(message);
    abort();
}
}

StringManager::~StringManager()
{
    for (unsigned int pack = 0; pack < 6; ++pack)
        unloadPack(pack);
    for (int index = 0; index < styles.size(); ++index) {
        delete[] styles.at(index)->fontName;
        delete styles.at(index);
    }
    styles.erase(styles.begin(), styles.end());
}
