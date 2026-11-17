#ifndef WCH_PERSISTENCE_STRING_MANAGER_H
#define WCH_PERSISTENCE_STRING_MANAGER_H

// Partial interface and language field observed by the menu widgets.
class StringManager {
public:
    const char* formatAmount(int value, bool option1, bool option2) const;
    int getLanguage() const { return language; }

private:
    unsigned char unknown0[4];
    int language;
};

#endif
