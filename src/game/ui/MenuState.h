#ifndef WCH_UI_MENU_STATE_H
#define WCH_UI_MENU_STATE_H

#include "../rendering/RenderFX.h"

class MenuWidget;

namespace MenuFX {
class State {
public:
    virtual ~State();
    virtual void Create();
    virtual void Show();
    virtual void Hide();
    virtual void GotFocus();
    virtual void LostFocus();
    virtual void Update();
    virtual void Update(int elapsed);
    virtual void OnEvent(RenderFX::Event& event);
    virtual void OnFSCommand(const char* command, const char* args);
    virtual bool CanHandleEvent(RenderFX::Event& event);

private:
    unsigned char storage[0x50];
};
}

class MenuState : public MenuFX::State {
public:
    virtual ~MenuState();
    virtual void Create();
    virtual void Show();
    virtual void Hide();
    virtual void GotFocus();
    virtual void LostFocus();
    virtual void Update();
    virtual void OnEvent(RenderFX::Event& event);
    virtual void UpdateLocalization();
    virtual bool Notify(const MenuWidget* widget, int event);
    virtual bool IsModal() const;
    int GetDepth() const;

private:
    unsigned char beforeDepth[0x10];
    int depth;
    unsigned char afterDepth[4];
};

#endif
