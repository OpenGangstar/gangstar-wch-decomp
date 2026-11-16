#ifndef WCH_UI_WIDGET_DIALOG_H
#define WCH_UI_WIDGET_DIALOG_H

namespace Widgets {
class Dialog {
public:
    void SetMessage(int id);
    int GetPressedButton() const;

private:
    unsigned char prefix[0x14];
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
