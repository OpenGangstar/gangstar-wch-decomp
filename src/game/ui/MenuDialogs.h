#ifndef WCH_UI_MENU_DIALOGS_H
#define WCH_UI_MENU_DIALOGS_H

#include "WidgetDialog.h"

class MenuWidget;
namespace RenderFX { class Event; }

// Partial interface in retail virtual slot order.
namespace Menus {
class Dialog {
public:
    virtual ~Dialog();
    void SetMessage(int id);

protected:
    virtual void Create();
    virtual void Show();
    virtual void Hide();
    virtual void GotFocus();
    virtual void LostFocus();
    virtual void Update();
    virtual void Update(int elapsed);
    virtual bool OnEvent(RenderFX::Event& event);
    virtual void OnFSCommand(const char* command, const char* args);
    virtual bool CanHandleEvent(RenderFX::Event& event);
    virtual void UpdateLocalization();
    virtual bool Notify(const MenuWidget* widget, int event);
    virtual bool IsModal() const;
    virtual Widgets::Dialog* GetWidget() = 0;
};
class Confirm : public Dialog {
public:
    virtual ~Confirm();
    bool Confirmed() const;

protected:
    virtual Widgets::Confirm* GetWidget();

private:
    unsigned char unknown4[0x68];
    bool confirmed;
};
class ConfirmPayment : public Confirm {
public:
    virtual ~ConfirmPayment();
    void SetPrice(int amount);

protected:
    virtual Widgets::ConfirmPayment* GetWidget();
};
}

#endif
