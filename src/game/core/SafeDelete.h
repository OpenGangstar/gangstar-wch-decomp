#ifndef WCH_CORE_SAFE_DELETE_H
#define WCH_CORE_SAFE_DELETE_H

template<class T>
void SafeDelete(T*& object) __attribute__((weak));

template<class T>
void SafeDelete(T*& object)
{
    delete object;
    object = 0;
}

#endif
