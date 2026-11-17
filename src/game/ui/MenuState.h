#ifndef WCH_UI_MENU_STATE_H
#define WCH_UI_MENU_STATE_H

#include "../rendering/RenderFX.h"

class MenuWidget;

namespace gameswf {
template <typename T>
class smart_ptr {
public:
    smart_ptr() : value(0) {}
    void set_ref(T* value) __attribute__((weak));

private:
    T* value;
};
}

namespace MenuFX {
class State {
public:
    explicit inline State(const char* name);
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
    unsigned char unknown4[4];
    char name[64];
    gameswf::smart_ptr<gameswf::character> firstCharacter;
    gameswf::smart_ptr<gameswf::character> secondCharacter;
    int unknown80;
};
}

class MenuState : public MenuFX::State {
public:
    explicit MenuState(const char* name);
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

protected:
    gameswf::array<int> widgetIds;

private:
    bool unknown96;
    int depth;
    unsigned char afterDepth[4];
};

#endif
