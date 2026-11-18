#ifndef WCH_UI_MAIN_MENU_H
#define WCH_UI_MAIN_MENU_H
#include "MenuState.h"
namespace Menus {
class MainMenu : public MenuState {
public:
    MainMenu();
    bool GameContinue() const;
    virtual ~MainMenu();
    virtual void GotFocus();
    virtual void LostFocus();
    virtual void Update();
    virtual bool Notify(const MenuWidget* widget, int event);
    virtual void SetPause(bool paused);

protected:
    bool unknown104;
    bool unknown105;
    bool unknown106;
    bool paused;
};
}
#endif
