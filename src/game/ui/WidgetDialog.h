#ifndef WCH_UI_WIDGET_DIALOG_H
#define WCH_UI_WIDGET_DIALOG_H

#include "../rendering/RenderFX.h"

class MenuState;

class MenuWidget {
public:
    explicit MenuWidget(const char* name);
    ~MenuWidget();
    bool IsVisible() const;
    gameswf::character* getCharacter() const { return character; }
    virtual bool AutoHide() const;
    bool IsEnabled() const;
    void SetListener(MenuState* state);
    virtual void Show();
    virtual void Hide(bool);
    virtual void Enable();
    virtual void Disable();
    virtual void OnEvent(RenderFX::Event&);
    virtual void UpdateLocalization();

protected:
    gameswf::character* character;
    RenderFX* renderFX;
    MenuState* listener;

private:
    bool visible;
    bool enabled;
};

namespace Widgets {
class Dialog : public MenuWidget {
public:
    int GetMessageId() const { return messageId; }
    explicit Dialog(const char* name);
    void SetMessage(int id);
    int GetPressedButton() const;
    virtual void Show();

    virtual void OnEvent(RenderFX::Event&);

private:
    int messageId;
    int pressedButton;
};

class Confirm : public Dialog {
public:
    explicit Confirm(const char* name);
    virtual void UpdateLocalization();
};

class ConfirmPayment : public Confirm {
public:
    ConfirmPayment();
    void SetPrice(int amount);
    virtual void UpdateLocalization();

private:
    int price;
};
}

#endif
