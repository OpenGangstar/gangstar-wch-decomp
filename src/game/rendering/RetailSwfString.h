#ifndef WCH_RENDERING_RETAIL_SWF_STRING_H
#define WCH_RENDERING_RETAIL_SWF_STRING_H

// Observed retail 16-byte gameswf string interface, shared by native callers.
// Method bodies and storage are preserved from menufx.cpp.
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

    const char* c_str() const
    {
        return storage[0] == 255 ? static_cast<const char*>(heap)
                                 : reinterpret_cast<const char*>(storage + 1);
    }

private:
    unsigned char storage[12];
    void* heap;
};
} // namespace gameswf

#endif
