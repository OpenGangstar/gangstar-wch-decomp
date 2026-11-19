#ifndef WCH_RENDERING_RETAIL_SWF_VALUE_H
#define WCH_RENDERING_RETAIL_SWF_VALUE_H

// Existing retail value interface, shared without changing its implementation.
namespace gameswf {
class as_value {
public:
    as_value();
    explicit as_value(const char* value);
    explicit as_value(int value);
    ~as_value() __attribute__((long_call));
    double to_number() const;

private:
    unsigned char storage[40] __attribute__((aligned(8)));
};
} // namespace gameswf

#endif
