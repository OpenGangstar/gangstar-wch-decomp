#ifndef WCH_PERSISTENCE_STRING_MANAGER_H
#define WCH_PERSISTENCE_STRING_MANAGER_H

// Partial interface observed by achievement stat formatting.
class StringManager {
public:
    const char* formatAmount(int value, bool option1, bool option2) const;
};

#endif
