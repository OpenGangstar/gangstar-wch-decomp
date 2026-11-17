#ifndef WCH_UI_MENU_STATE_H
#define WCH_UI_MENU_STATE_H

#include "../rendering/RenderFX.h"

class MenuWidget;


class MenuFX : public RenderFX, public RenderFX::EventListener {
public:
    class State;
    virtual ~MenuFX();
    virtual void OnEvent(RenderFX::Event& event);
    virtual void OnFSCommand(const char* command, const char* args);
    State* GetCurrentState();
    State* GetStateHandler(gameswf::character* character);
    bool IsStateInStack(State* state);

private:
    unsigned char beforeStack[16];
    gameswf::array<State*> stateStack;
};

class MenuFX::State {
public:
    explicit inline State(const char* name);
    virtual inline ~State();
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
};

#endif
