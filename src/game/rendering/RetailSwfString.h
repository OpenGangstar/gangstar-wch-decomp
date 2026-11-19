#ifndef WCH_RENDERING_RETAIL_SWF_STRING_H
#define WCH_RENDERING_RETAIL_SWF_STRING_H

// Observed retail 16-byte gameswf string interface, shared by native callers.
// Method bodies and storage were initially preserved from menufx.cpp.
// The accessors below now follow the documented SDK helper chain; storage,
// constructor declarations and destructor behavior remain unchanged.
void SwfFree(void* buffer);

namespace gameswf {
class tu_string {
public:
    // The retail call resolves the constructor through the GOT.
    explicit tu_string(const char* text) __attribute__((long_call));
    tu_string(const tu_string& other) __attribute__((long_call));
    tu_string(const char* text, int length) __attribute__((long_call));
    ~tu_string()
    {
        if (using_heap())
            SwfFree(m_heap.m_buffer);
    }

    // Adapted public-domain tu-testbed container.h accessor chain, retaining
    // the real retail tag-first 16-byte storage (upstream union differs).
    // Authentic container.h length()/size() API adapted to the retail
    // tag/heap-buffer-size encoding, which includes its terminating byte.
    int length() const
    {
        if (using_heap() == false)
            return static_cast<int>(m_local.m_size) - 1;
        else
            return m_heap.m_size - 1;
    }
    int size() const { return length(); }

    static int utf8_char_count(const char* buffer, int byteLength);
    int utf8_length() const { return utf8_char_count(get_buffer(), length()); }
    tu_string utf8_substring(int start, int end) const;

    operator const char*() const { return get_buffer(); }
    const char* c_str() const { return static_cast<const char*>(*this); }

private:
    char* get_buffer()
    {
        if (using_heap() == false)
            return m_local.m_buffer;
        return m_heap.m_buffer;
    }
    const char* get_buffer() const
    {
        return const_cast<tu_string*>(this)->get_buffer();
    }
    bool using_heap() const
    {
        // Compile-time proof over the actual class, not an assumed padding view.
        typedef char SizeIs16[sizeof(tu_string) == 16 ? 1 : -1];
        typedef char AlignmentIs4[__alignof__(tu_string) == 4 ? 1 : -1];
        typedef char LocalTagAt0[__builtin_offsetof(tu_string, m_local.m_size) == 0 ? 1 : -1];
        typedef char LocalBufferAt1[__builtin_offsetof(tu_string, m_local.m_buffer) == 1 ? 1 : -1];
        typedef char HeapTagAt0[__builtin_offsetof(tu_string, m_heap.m_all_ones) == 0 ? 1 : -1];
        typedef char HeapSizeAt4[__builtin_offsetof(tu_string, m_heap.m_size) == 4 ? 1 : -1];
        typedef char HeapCapacityAt8[__builtin_offsetof(tu_string, m_heap.m_capacity) == 8 ? 1 : -1];
        typedef char HeapPointerAt12[__builtin_offsetof(tu_string, m_heap.m_buffer) == 12 ? 1 : -1];
        bool result = m_heap.m_all_ones == static_cast<char>(~0);
        return result;
    }
    // Public-domain tu-testbed/container.h, b29f4cc842244eb8e1daf3b7c4d8ce2693c04853.
    // Natural 2008 tag-first union; 32-bit ARM offsets independently match retail.
    struct Local {
        char m_size;
        char m_buffer[15];
    };
    struct Heap {
        char m_all_ones;
        int m_size;
        int m_capacity;
        char* m_buffer;
    };
    union {
        Local m_local;
        Heap m_heap;
    };
};
// container.h -- Thatcher Ulrich <tu@tulrich.com> 31 July 2001.
// This source code has been donated to the Public Domain.
// Authentic tu_stringi composition; measured retail tu_string storage retained.
class tu_stringi {
public:
    tu_stringi(const char* str) : m_string(str) {}
    tu_stringi(const tu_string& str) : m_string(str) {}
    ~tu_stringi() {}
private:
    tu_string m_string;
};
} // namespace gameswf

#endif
