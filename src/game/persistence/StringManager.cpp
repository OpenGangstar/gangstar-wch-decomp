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

void StringManager::unloadPackSheet(unsigned int pack, unsigned int sheet)
{
    if (isPackSheetLoaded(pack, sheet)) {
        char** strings = static_cast<char**>(packSheets[pack][sheet]);
        for (int i = 0; strings[i]; ++i) {
            delete strings[i];
            strings[i] = 0;
        }
        strings = static_cast<char**>(packSheets[pack][sheet]);
        delete[] strings;
        packSheets[pack][sheet] = 0;
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

#include "IFileStream.h"
#include "FileSystemBase.h"
#include "StreamReader.h"
#include "../app/Application.h"

extern "C" const char* _ZN13StringManager6SHEETSE[];
extern "C" const char* _ZN13StringManager9LANGUAGESE[];
extern "C" void _ZN12StreamReader6readAsItEEvP11IStreamBasePT_(IStreamBase*, unsigned short*) __attribute__((weak));
extern "C" int _ZN11MenuManager19getCharAutoLineFeedEv();
extern "C" char* strcat(char* destination, const char* source);

int StringManager::loadPackSheet(unsigned int pack, unsigned int sheet)
{
    static const char fontOpenText[] = "<font color=\"#FFFF33\">";
    static const char fontCloseText[] = "</font>";
    static const char nbspText[] = "&nbsp;";
    static const char needlesText[] = "\\?!;|";
    static const char* fontOpen = fontOpenText;
    static const char* fontClose = fontCloseText;
    static const char* nbsp = nbspText;
    static const char* strEmpty = localStartupEmptyText;
    static const char* needles = needlesText;
    static char source[1024];
    static char destination[1024];
    Application* application = Application::GetInstance();
    char path[100];
    sprintf(path, "%s.%s", _ZN13StringManager6SHEETSE[sheet], _ZN13StringManager9LANGUAGESE[pack]);
    IFileStream* stream = application->GetFileSystem()->openResource(path);
    if (!stream)
        return 0;
    unsigned short count;
    unsigned short length;
    _ZN12StreamReader6readAsItEEvP11IStreamBasePT_(stream, &count);
    {
        int endian = 1;
        if (*reinterpret_cast<char*>(&endian) == 0) {
            char* first = reinterpret_cast<char*>(&count);
            char* last = first + sizeof(count) - 1;
            while (first < last) {
                *first = *last ^ *first;
                *last ^= *first;
                *first ^= *last;
                ++first;
                --last;
            }
        }
    }
    char** strings = new char*[count + 1];
    memset(strings, 0, count * sizeof(char*) + 1);
    for (unsigned short i = 0; i < count; ++i) {
        _ZN12StreamReader6readAsItEEvP11IStreamBasePT_(stream, &length);
        {
            int endian = 1;
            if (*reinterpret_cast<char*>(&endian) == 0) {
                char* first = reinterpret_cast<char*>(&length);
                char* last = first + sizeof(length) - 1;
                while (first < last) {
                    *first = *last ^ *first;
                    *last ^= *first;
                    *first ^= *last;
                    ++first;
                    --last;
                }
            }
        }
        static int fontOpenSize = strlen(fontOpen);
        static int fontCloseSize = strlen(fontClose);
        static int nbspSize = strlen(nbsp);
        source[0] = 0;
        destination[0] = 0;
        StreamReader::readStringEx(stream, source, length);
        source[length] = 0;
        char* last = source;
        int size = 0;
        char* found = strchrs(source, needles);
        while (found) {
            memcpy(destination + size, last, found - last);
            size += found - last;
            destination[size] = 0;
            switch (*found) {
            case '\\':
                ++found;
                switch (*found) {
                case '0':
                    memcpy(destination + size, fontOpen, fontOpenSize);
                    size += fontOpenSize;
                    break;
                case '1':
                    memcpy(destination + size, fontClose, fontCloseSize);
                    size += fontCloseSize;
                    break;
                case '\\':
                    destination[size++] = *found;
                    break;
                }
                break;
            case '?':
            case '!':
            case ';':
                if (size != 0 && destination[size - 1] == ' ') {
                    --size;
                    memcpy(destination + size, nbsp, nbspSize);
                    size += nbspSize;
                }
                destination[size++] = *found;
                break;
            case '|':
                destination[size++] = _ZN11MenuManager19getCharAutoLineFeedEv();
                break;
            }
            last = ++found;
            found = strchrs(found, needles);
        }
        destination[size] = 0;
        strcat(destination + size, last);
        const int textLength = strlen(destination);
        strings[i] = const_cast<char*>(strEmpty);
        if (length != 0) {
            strings[i] = new char[textLength + 1];
            strcpy(strings[i], destination);
        }
    }
    strings[count] = 0;
    packSheets[pack][sheet] = strings;
    application->GetFileSystem()->closeFile(stream);
    return 1;
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

#include "../world/ResStream.h"
void* operator new(unsigned int);

extern "C" void _ZN10DataStreamD1Ev(void*) __attribute__((weak));

void StringManager::loadStyles(const char* name)
{
    struct DataStreamOwner {
        unsigned int storage[sizeof(DataStream) / sizeof(unsigned int)];
        DataStreamOwner(Stream& source, DataStream::endian order) {
            new (storage) DataStream(source, order);
        }
        ~DataStreamOwner() { _ZN10DataStreamD1Ev(storage); }
        DataStream& object() { return *reinterpret_cast<DataStream*>(storage); }
    };
    ResStream resource(name, 1);
    DataStreamOwner dataOwner(resource, DataStream::BigEndian);
    DataStream& data = dataOwner.object();
    const int count = data.ReadInt();
    for (int i = 0; i < count; ++i) {
        int size = data.ReadInt();
        int end = data.DataStream::Tell() + size;
        Structs::TextStyle* style = new Structs::TextStyle();
        style->Read(data);
        if (data.DataStream::Tell() != end)
            data.DataStream::Seek(end, 0);
        styles.push_back(style);
    }
}

extern const char amountReversedNbsp[] __attribute__((visibility("hidden")));
static const char amountHtmlSuffix[] = "&nbsp;$";
static const char amountSpaceSuffix[] = " $";
extern "C" char* strcat(char*, const char*);
void strRev(char*) __attribute__((noinline));

const char* StringManager::formatAmount(int amount, bool html, bool currency) const
{
    static const char* nbsp = amountReversedNbsp;
    static int nbspSize = strlen(nbsp);
    static char szBuffer[64];
    memset(szBuffer, 0, sizeof(szBuffer));
    char* output = szBuffer;
    int remaining = amount;
    if (!amount)
        *output++ = '0';
    else {
        int digits = 0;
        while (remaining) {
            const int quotient = remaining / 10;
            *output++ = remaining - quotient * 10 + '0';
            remaining = quotient;
            if (++digits == 3) {
                if (remaining) switch (currentPack) {
                case 4:
                    if (html) {
                        strcat(output, nbsp);
                        output += nbspSize;
                    } else
                        *output++ = ' ';
                    break;
                case 2:
                case 5:
                    *output++ = '.';
                    break;
                case 1:
                case 3:
                    if (amount > 9999) {
                        // No-code prediction hint: folds back to "html" after SRA.
                        struct { unsigned int k; } htmlHint = {static_cast<unsigned int>(html) + 1u};
                        if (htmlHint.k == 2u) {
                            strcat(output, nbsp);
                            output += nbspSize;
                        } else
                            *output++ = ' ';
                    }
                    break;
                case 0:
                    *output++ = ',';
                    break;
                }
                digits = 0;
            }
        }
    }
    // No-code prediction hints: the one-field aggregates keep these
    // tests opaque until SRA; both fold back to "currency" afterwards.
    struct { unsigned int k; } currencyHint = {static_cast<unsigned int>(currency) + 1u};
    struct { unsigned int k; } currencyHint2 = {static_cast<unsigned int>(currency) + 2u};
    if (currencyHint.k != 1u && currencyHint2.k != 2u) {
        if (currentPack == 0 || currentPack == 3) {
            *output = '$';
            output[1] = 0;
            strRev(szBuffer);
        } else {
            // Byte-neutral allocation hint: both arms are identical, so the
            // post-reload crossjump merges them and the test is deleted.  The
            // test adds a reference to the szBuffer GOT offset so its global
            // priority beats `this` (szBuffer takes r9 and `this` fp, as in retail).
            if (output == szBuffer)
                *output = 0;
            else
                *output = 0;
            strRev(szBuffer);
        }
        switch (currentPack) {
        case 1:
        case 2:
            strcat(szBuffer, html ? amountHtmlSuffix : (__builtin_prefetch(output), amountSpaceSuffix));
            break;
        case 4:
            strcat(szBuffer, "$");
            break;
        case 5:
            strcat(szBuffer, html ? amountHtmlSuffix : (__builtin_prefetch(output), amountSpaceSuffix));
            break;
        }
    } else {
        *output = currency;
        strRev(szBuffer);
    }
    return szBuffer;
}
