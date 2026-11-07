#ifndef WCH_CORE_MEM_HINT_H
#define WCH_CORE_MEM_HINT_H

namespace irr {
enum MemHint { DefaultMemHint = 0 };
}

void* operator new(unsigned int size, irr::MemHint hint);

#endif
