#ifndef GAME_CORE_RCT_H
#define GAME_CORE_RCT_H

template<class T>
struct Rct {
    Rct() : left(0), top(0), right(0), bottom(0) {}
    Rct(T left, T top, T right, T bottom);
    Rct& operator=(const Rct& other)
    {
        left = other.left;
        top = other.top;
        right = other.right;
        bottom = other.bottom;
        _validate();
        return *this;
    }
    virtual ~Rct() {}
    void _validate() __attribute__((weak));
    bool isIntersecting(T x, T y) const;

    T left;
    T top;
    T right;
    T bottom;
};

template<class T>
inline Rct<T>::Rct(T left, T top, T right, T bottom)
    : left(left), top(top), right(right), bottom(bottom)
{
    _validate();
}

namespace rct_detail {

template<class T>
inline const T& minimum(const T& first, const T& second)
{
    return second < first ? second : first;
}

template<class T>
inline const T& maximum(const T& first, const T& second)
{
    return first < second ? second : first;
}

} // namespace rct_detail

template<class T>
void Rct<T>::_validate()
{
    const T orderedLeft = rct_detail::minimum(left, right);
    const T orderedRight = rct_detail::maximum(left, right);
    const T orderedTop = rct_detail::minimum(top, bottom);
    const T orderedBottom = rct_detail::maximum(top, bottom);
    left = orderedLeft;
    top = orderedTop;
    right = orderedRight;
    bottom = orderedBottom;
}

#endif
