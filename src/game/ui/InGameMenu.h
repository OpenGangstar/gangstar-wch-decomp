#ifndef WCH_UI_IN_GAME_MENU_H
#define WCH_UI_IN_GAME_MENU_H
#include "MenuState.h"
namespace Menus {
class InGameMenu : public MenuState {
public:
    explicit InGameMenu(const char* name);
    virtual inline ~InGameMenu() __attribute__((used));
    virtual void GotFocus();
    virtual void LostFocus();
    virtual bool Notify(const MenuWidget* widget, int event);
};
}
#endif
