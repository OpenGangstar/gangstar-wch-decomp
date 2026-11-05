#ifndef GAME_CORE_RCT_H
#define GAME_CORE_RCT_H

template<class T>
struct Rct {
    virtual ~Rct();
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

#endif
