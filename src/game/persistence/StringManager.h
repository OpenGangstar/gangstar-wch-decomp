#ifndef WCH_PERSISTENCE_STRING_MANAGER_H
#define WCH_PERSISTENCE_STRING_MANAGER_H

#include "../core/PointerVector.h"

namespace Structs { struct TextStyle; }

// Partial interface observed by achievement stat formatting.
class StringManager {
public:
    StringManager();
    virtual ~StringManager();
    int loadPack(unsigned int pack);
    int loadPackSheet(unsigned int pack, unsigned int sheet);
    bool isPackLoaded(unsigned int pack) const __attribute__((noinline));
    bool isPackSheetLoaded(unsigned int pack, unsigned int sheet) const __attribute__((noinline));
    int getNumberOfLoadedPack() const;
    bool switchPack(unsigned int pack);
    void loadStyles(const char* name);
    void unloadPack(unsigned int pack);
    void unloadPackSheet(unsigned int pack, unsigned int sheet);
    const char* getString(int id) const;
    const char* formatAmount(int value, bool option1, bool option2) const;
private:
    unsigned int currentPack;
    void* packSheets[6][12];
    int unknown296;
    std::vector<Structs::TextStyle*> styles;
};

#endif
