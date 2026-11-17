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

class MenuWidget;

class MenuManager {
public:
    MenuManager();
    virtual ~MenuManager();
    static MenuManager* getInstance();
    MenuWidget* getWidgetByIndex(int index) const
    {
        return index < widgets.size ? widgets.elements[index] : 0;
    }
    enum eText { SkipButtonText = 3, MissionTimerText = 15, StayWithinText = 16, TextForceWidth = 0x7fffffff };
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
    void initMap();
    void updateMap();
    void updateMarkers();
    void consumeCursor();
    int getCharAutoLineFeed();
    void enableAnims(bool);
    bool areAnimsEnabled() const;
    int getMapMode() const;
    void cleanupMap();
    struct WeaponShopData {
        int price;
        union { int code; unsigned short category; };
        unsigned char unknown8[12];
    };
    static int s_WeaponShopDataCount;
    static WeaponShopData s_WeaponShopData[];
private:
    int unknown4;
    int unknown8;
    int unknown12;
    int unknown16;
    int unknown20;
    int unknown24;
    unsigned char unknown28[12];
    float unknown40;
    int unknown44;
    int unknown48;
    int unknown52;
    int unknown56;
    int mapMode;
    float unknown64;
    int inGameMenu;
    int tutorialId;
    int tutorialTextId;
    int repairCost;
    struct OwnedBuffer {
        void* data;
        int unknown4;
        int unknown8;
        bool ownsData;
        bool unknown13;
        OwnedBuffer();
        ~OwnedBuffer();
    };
    OwnedBuffer buffer;
    int unknown100;
    struct Entry {
        float unknown0;
        float unknown4;
        float unknown8;
        int unknown12;
        Entry();
    };
    Entry entries[4];
    int unknown168[4];
    int unknown184;
    MenuFXPrefix* menuFX;
    int unknown192;
    bool widgetVisibility;
    bool clearingFocus;
    unsigned char unknown198[2];
    int textIds[17];
    const char* texts[17];
    int unknown336[17];
    int charAutoLineFeed;
    bool asianFont;
    bool animsEnabled;
    bool cheatsUnlocked;
    bool cheatsUnlockAllowed;
    unsigned int consumedCursorCount;
    int unknown416;
    struct WidgetStorage {
        MenuWidget** elements;
        int size;
        int capacity;
        WidgetStorage();
        ~WidgetStorage();
    };
    WidgetStorage widgets;
    bool unknown432;
};

#endif
