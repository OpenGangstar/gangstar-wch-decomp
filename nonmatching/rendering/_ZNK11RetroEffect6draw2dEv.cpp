// Unmatched parent remains pending; the compiler-generated ARM thunk is verified.
#include "../../src/game/rendering/RetroEffect.cpp"
#include "../../src/game/hud/MenuManager.h"
#include "../../src/game/ui/WidgetDialog.h"
extern "C" long lrand48();

void RetroEffect::draw2d() const
{
    MenuWidget* widget = MenuManager::getInstance()->getWidgetByIndex(29);
    const unsigned int drawMask = 1;
    if ((flags & drawMask) == drawMask) {
        if (!widget->IsVisible())
            widget->Show();
    } else {
        if (widget->IsVisible())
            widget->Hide(true);
        return;
    }

    irr::video::IVideoDriver* driver = Application::GetInstance()->GetDevice()->getVideoDriver();
    driver->set2DMaterial(const_cast<irr::video::SMaterial&>(material));
    driver->getViewPort();
    driver->draw2DImage(texture, irr::core::position2d<int>(lrand48() % 4 - 2, lrand48() % 4 - 2),
                        irr::core::rect<int>(0, 0, 854, 480), 0,
                        irr::video::SColor(255, 255, 255, 255), drawMask);
    irr::video::SMaterial defaultMaterial;
    driver->set2DMaterial(defaultMaterial);
}


