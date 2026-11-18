#ifndef WCH_UI_OPTION_GAME_SETTINGS_H
#define WCH_UI_OPTION_GAME_SETTINGS_H
#include "InGameMenu.h"
namespace Menus {
class Options : public InGameMenu {
public:
    explicit Options(const char* name);
    virtual inline ~Options() __attribute__((used));
    virtual void GotFocus();
    virtual bool Notify(const MenuWidget* widget, int event);
};

class OptionGameSettings : public Options {
public:
    struct stGameSetting {
        enum eOrientation { Orientation0, Orientation1, OrientationAuto, OrientationForce32Bit = 0x7fffffff };
    };
    static stGameSetting::eOrientation GetOrientation();
    static void SetOrientation(stGameSetting::eOrientation orientation);
    static void SetOrientation(int orientation);
    OptionGameSettings();
    void Refresh();
    virtual ~OptionGameSettings();
    virtual void GotFocus();
    virtual void LostFocus();
    virtual bool Notify(const MenuWidget* widget, int event);

private:
    int selections[8];
    int chapterStartup[6];
};
}
#endif
