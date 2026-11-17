#ifndef WCH_CORE_OBSERVED_STRING_H
#define WCH_CORE_OBSERVED_STRING_H

namespace irr { namespace core {
template<class T> class irrAllocator;
template<class T, class A> class string;

// Only the observed 32-byte char-string prefix and copy path are recovered.
// Assignment and destruction remain native imports.
template<class A> class string<char,A> {
    char* array;
    unsigned int allocated;
    unsigned int used;
    unsigned char unknown12;
    char inlineBuffer[16];
    bool reference;
    unsigned char unknown30[2];
public:
    string(const char* source);
    const char* c_str() const { return array; }
    string(const string& source)
        : array(0), allocated(0), used(0), reference(false)
    {
        *this = source;
    }
    ~string() __attribute__((weak));
    string& operator=(const string&) __attribute__((weak));
};
} }

#endif
