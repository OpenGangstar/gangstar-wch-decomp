#ifndef WCH_HUD_MENU_MANAGER_H
#define WCH_HUD_MENU_MANAGER_H

// Observed prefix of the object returned by getMenuFX; its actual type is unknown.
struct MenuFXPrefix {
    unsigned char unknown0[228];
    int depth;
};

// Partial member layout and shop-record stride. Do not instantiate or use sizeof.
// Word-valued flag/map accessors retain provisional return types.
struct MenuCheatZone {
    float left;
    float top;
    float right;
    float bottom;
};

class MenuManager {
public:
    static MenuManager* getInstance();
    enum eText { SkipButtonText = 3, MissionTimerText = 15 };
    void setText(eText slot, int textId, int* arguments);
    void setText(eText slot, const char* text, int* arguments);
    const char* getText(eText slot) const;
    static MenuCheatZone s_cheatActivationZones[2];
    int getDepth() const;
    void showTexts();
    void hideTexts();
    void popAll(bool);
    void* getState(const char*) const;
    void push(const char*, bool);
    void resetWidgetVisibility();
    void MenuPause();
    void MenuResume();
    void setTutorialIds(int, int);
    void setRepairCost(int);
    int getRepairCost() const;
    bool areCheatsUnlocked() const;
    bool isCheatsUnlockAllowed() const;
    bool isClearingFocus() const;
    MenuFXPrefix* getMenuFX();
    int isInGameMenu() const;
    unsigned int consumedCursors() const;
    void consumeCursor();
    int getCharAutoLineFeed();
    void enableAnims(bool);
    bool areAnimsEnabled() const;
    int getMapMode() const;
    struct WeaponShopData {
        int price;
        union { int code; unsigned short category; };
        unsigned char unknown8[12];
    };
    static int s_WeaponShopDataCount;
    static WeaponShopData s_WeaponShopData[];
private:
    unsigned char unknown0[60];
    int mapMode;
    unsigned char unknown64[4];
    int inGameMenu;
    int tutorialId;
    int tutorialTextId;
    int repairCost;
    unsigned char unknown84[104];
    MenuFXPrefix* menuFX;
    unsigned char unknown192[4];
    bool widgetVisibility;
    bool clearingFocus;
    unsigned char unknown198[211];
    bool animsEnabled;
    bool cheatsUnlocked;
    bool cheatsUnlockAllowed;
    unsigned int consumedCursorCount;
};

#endif
