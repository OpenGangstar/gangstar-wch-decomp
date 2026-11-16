#ifndef WCH_UI_WIDGET_DIALOG_H
#define WCH_UI_WIDGET_DIALOG_H

class MenuState;
class RenderFX {
public:
    class Event;
};
namespace gameswf { class character; }

class MenuWidget {
public:
    bool IsVisible() const;
    virtual bool AutoHide() const;
    bool IsEnabled() const;
    virtual void Show();
    virtual void Hide(bool);
    virtual void Enable();
    virtual void Disable();
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();

private:
    gameswf::character* character;
    RenderFX* renderFX;
    MenuState* listener;
    bool visible;
    bool enabled;
};

namespace Widgets {
class Dialog : public MenuWidget {
public:
    void SetMessage(int id);
    int GetPressedButton() const;
    virtual void Show();

    virtual void OnEvent(RenderFX::Event&);

private:
    int messageId;
    int pressedButton;
};

class Confirm : public Dialog {
};

class ConfirmPayment : public Confirm {
public:
    void SetPrice(int amount);

private:
    int price;
};
}

#endif
