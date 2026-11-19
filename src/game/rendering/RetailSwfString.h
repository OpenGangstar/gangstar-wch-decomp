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
    tu_string(const char* text, int length) __attribute__((long_call));
    ~tu_string()
    {
        if (__builtin_expect(storage[0] == 255, 1))
            SwfFree(heap);
    }

    // Adapted public-domain tu-testbed container.h accessor chain, retaining
    // the real retail tag-first 16-byte storage (upstream union differs).
    // Authentic container.h length()/size() API adapted to the retail
    // tag/heap-buffer-size encoding, which includes its terminating byte.
    int length() const
    {
        if (using_heap() == false)
            return static_cast<int>(storage[0]) - 1;
        else
            return *reinterpret_cast<const int*>(storage + 4) - 1;
    }
    int size() const { return length(); }

    operator const char*() const { return get_buffer(); }
    const char* c_str() const { return static_cast<const char*>(*this); }

private:
    char* get_buffer()
    {
        if (using_heap() == false)
            return reinterpret_cast<char*>(storage + 1);
        return static_cast<char*>(heap);
    }
    const char* get_buffer() const
    {
        return const_cast<tu_string*>(this)->get_buffer();
    }
    bool using_heap() const
    {
        bool result = storage[0] == static_cast<unsigned char>(~0);
        return result;
    }
    unsigned char storage[12];
    void* heap;
};
} // namespace gameswf

#endif
