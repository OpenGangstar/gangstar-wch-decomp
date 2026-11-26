/*
 * DataReloaderManager
 *
 * Original file: DataReloaderManager.cpp
 * Area:          world
 *
 * This file mirrors the layout of the retail build.  Add the decompiled
 * functions of DataReloaderManager.cpp here, in the order they appear in the library.
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
static void _GLOBAL__I__ZN19DataReloaderManagerC2Ev() __attribute__((used));
static void _GLOBAL__I__ZN19DataReloaderManagerC2Ev()
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

#include "../core/PointerVector.h"
#include "../app/Application.h"
#include "../persistence/FileSystemBase.h"
#include "../persistence/IFileStream.h"
#include "../core/Logs.h"

class IDataReloader;

class DataReloaderManager {
public:
    DataReloaderManager();
    virtual ~DataReloaderManager();
    void checkFiles() const;
    void monitorFiles(const char*, const char*, IDataReloader*);
private:
    struct _MonitoredFiles;
    std::vector<_MonitoredFiles*> monitoredFiles;
    void _trace(const char* message) const;
};

void DataReloaderManager::_trace(const char*) const
{
}

void DataReloaderManager::monitorFiles(const char*, const char*, IDataReloader*)
{
}

DataReloaderManager::DataReloaderManager()
{
}

/*
 * Copyright (c) 1997-1999
 * Silicon Graphics Computer Systems, Inc.
 *
 * Copyright (c) 1999
 * Boris Fomitchev
 *
 * Copyright (c) 2003
 * Francois Dumont
 *
 * This material is provided "as is", with absolutely no warranty expressed
 * or implied. Any use is at your own risk.
 *
 * Permission to use or copy this software for any purpose is hereby granted
 * without fee, provided the above notices are retained on all copies.
 * Permission to modify the code and to distribute modified code is granted,
 * provided the above notices are retained, and a notice that the code was
 * modified is included with the above copyright notice.
 *
 */

// Modified: restricted observed 24-byte char-string ABI and original accessor path.
// Allocation, construction and destruction remain external native operations.
namespace stlp_priv {
template<class T, class Alloc> class _String_base {
protected:
    enum { _DEFAULT_SIZE = 16 };
    union _Buffers { T* _M_dynamic_buf; T _M_static_buf[_DEFAULT_SIZE]; } _M_buffers;
    T* _M_finish;
    _STLP_alloc_proxy<T*, T, Alloc> _M_end_of_storage;
    bool _M_using_static_buf() const {
        return _M_end_of_storage._M_data == _M_buffers._M_static_buf + _DEFAULT_SIZE;
    }
    const T* _M_Start() const {
        return _M_using_static_buf() ? _M_buffers._M_static_buf : _M_buffers._M_dynamic_buf;
    }
};
}
namespace std {
template<class T> struct char_traits;
template<class T, class Traits = char_traits<T>, class Alloc = allocator<T> >
class basic_string : protected stlp_priv::_String_base<T, Alloc> {
public:
    ~basic_string() __attribute__((weak));
    const T* c_str() const { return this->_M_Start(); }
};
typedef basic_string<char> string;
}

class IDataReloader;

struct DataReloaderManager::_MonitoredFiles {
    IDataReloader* reloader;
    std::string path;
    std::string filename;
    bool changed;
    ~_MonitoredFiles() __attribute__((used, noinline)) {}
};

DataReloaderManager::~DataReloaderManager()
{
    for (std::vector<_MonitoredFiles*>::iterator it = monitoredFiles.begin(); it != monitoredFiles.end(); ++it)
        delete *it;
}

class IDataReloader {
public:
    virtual ~IDataReloader() {}
    virtual void reload(IFileStream* file, const char* filename) = 0;
};
static const char reloaderReloadedMessage[] = "File reloaded:";
static const char reloaderOpenError[] = "Can't open file for reloading the data:";

void DataReloaderManager::checkFiles() const
{
    Application* app = Application::GetInstance();
    typedef std::vector<_MonitoredFiles*>::iterator Iterator;
    for (Iterator it = const_cast<std::vector<_MonitoredFiles*>&>(monitoredFiles).begin(); it != const_cast<std::vector<_MonitoredFiles*>&>(monitoredFiles).end(); ++it)
        (*it)->changed = true;
    for (Iterator it = const_cast<std::vector<_MonitoredFiles*>&>(monitoredFiles).begin(); it != const_cast<std::vector<_MonitoredFiles*>&>(monitoredFiles).end(); ++it) {
        _MonitoredFiles* item = *it;
        if (!item->changed) {
            // No-code builtin call (no Thumb pld): block-frequency hint via
            // the guarded-call heuristic, unchanged files are the rare case.
            __builtin_prefetch(item);
            continue;
        }
        IFileStream* file = app->GetFileSystem()->openResource(item->filename.c_str());
        if (file) {
            // No-code builtin call: balances the guarded-call heuristic of
            // the error arm so only the pointer heuristic predicts this test.
            __builtin_prefetch(file);
            item->reloader->reload(file, item->filename.c_str());
            app->GetFileSystem()->closeFile(file);
            // Byte-neutral allocation hint: both arms are identical, so the
            // post-reload crossjump merges them and the test is deleted.  The
            // test adds references to `this` and the iterator and lengthens the
            // static-buffer pointer's live range, so the reload function pointer
            // outranks it in global allocation (r7 vs r8, as in retail).
            if (it == const_cast<std::vector<_MonitoredFiles*>&>(monitoredFiles).end())
                item->changed = false;
            else
                item->changed = false;
            _trace(reloaderReloadedMessage);
            _trace(item->filename.c_str());
        } else {
            Logs::error(reloaderOpenError);
            Logs::error(item->filename.c_str());
        }
    }
}
