// Copyright (C) 2002-2008 Nikolaus Gebhardt
// Altered Irrlicht 1.4.2 irrList.h excerpt: read-only list/ConstIterator ABI bridge.
// This software is provided 'as-is', without any express or implied
// warranty. In no event will the authors be held liable for any damages
// arising from the use of this software.
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it
// freely, subject to the following restrictions:
// 1. The origin of this software must not be misrepresented; you must not
// claim that you wrote the original software. If you use this software
// in a product, an acknowledgement in the product documentation would be
// appreciated but is not required.
// 2. Altered source versions must be clearly marked as such, and must not be
// misrepresented as being the original software.
// 3. This notice may not be removed or altered from any source distribution.
#ifndef WCH_NATIVE_SCENE_CHILD_LIST_H
#define WCH_NATIVE_SCENE_CHILD_LIST_H
namespace irr { namespace core {
// Adapted read-only subset. SDK u32 Size is spelled unsigned int here.
template<class T> class list {
private:
    struct SKListNode {
        SKListNode() : Next(0), Prev(0) {}
        SKListNode* Next;
        SKListNode* Prev;
        T Element;
    };
public:
    class ConstIterator {
    public:
        ConstIterator() : Current(0) {}
        ConstIterator& operator ++() { Current = Current->Next; return *this; }
        bool operator !=(const ConstIterator& other) const { return Current != other.Current; }
        const T& operator *() { return Current->Element; }
    private:
        ConstIterator(SKListNode* begin) : Current(begin) {}
        SKListNode* Current;
        friend class list<T>;
    };
    ConstIterator begin() const { return ConstIterator(First); }
    ConstIterator end() const { return ConstIterator(0); }
private:
    SKListNode* First;
    SKListNode* Last;
    unsigned int Size;
};
} }
#endif
