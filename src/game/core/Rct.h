#ifndef GAME_CORE_RCT_H
#define GAME_CORE_RCT_H

template<class T>
struct Rct {
    Rct(T left, T top, T right, T bottom);
    virtual ~Rct();
    void _validate();
    bool isIntersecting(T x, T y) const;

    T left;
    T top;
    T right;
    T bottom;
};

template<class T>
Rct<T>::~Rct()
{
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
