#ifndef WCH_UI_MENU_DIALOGS_H
#define WCH_UI_MENU_DIALOGS_H

#include "WidgetDialog.h"
#include "MenuState.h"

// Partial interface in retail virtual slot order.
namespace Menus {
class Dialog : public MenuState {
public:
    explicit Dialog(const char* name);
    virtual inline ~Dialog();
    void SetMessage(int id);

protected:
    virtual void GotFocus();
    virtual void LostFocus();
    virtual Widgets::Dialog* GetWidget() = 0;
};
class Confirm : public Dialog {
public:
    explicit Confirm(const char* name);
    virtual inline ~Confirm();
    bool Confirmed() const;

protected:
    virtual bool IsModal() const;
    virtual void GotFocus();
    virtual bool Notify(const MenuWidget* widget, int event);
    virtual Widgets::Confirm* GetWidget();

private:
    unsigned char beforeConfirmed[4];
    bool confirmed;
};
class ConfirmPayment : public Confirm {
public:
    explicit ConfirmPayment(const char* name);
    virtual inline ~ConfirmPayment();
    void SetPrice(int amount);

protected:
    virtual Widgets::ConfirmPayment* GetWidget();
};
}

#endif
