#ifndef GAME_CORE_POINT2D_H
#define GAME_CORE_POINT2D_H

template<class T>
struct Point2D {
    Point2D(T x = 0, T y = 0) : x(x), y(y) {}
    virtual ~Point2D();

    T x;
    T y;
};

template<class T>
inline Point2D<T>::~Point2D()
{
}

#endif
