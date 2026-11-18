// Unmatched Cash::draw2d reconstruction; its assembly remains pending.
// Retained to verify the genuine compiler-generated secondary-base thunk.
#include "../../src/game/ui/Cash.h"
#include "../../src/game/app/Application.h"
#include "../../src/game/characters/PlayerTest.h"
#include "../../src/game/core/ASprite.h"
#include "../../src/game/core/IrrlichtDevice.h"
#include "../../src/game/core/VideoDriver.h"
#include "../../src/game/core/Matrix4.h"

void Cash::draw2d() const
{
    if (PlayerTest::GetPlayer() && (flags & 1)) {
        Application::GetInstance()->GetDevice()->getVideoDriver()->setTransform(
            irr::video::ETS_WORLD, irr::core::matrix4());
        int x = positionX;
        if (alignedLeft) {
            if (unknown116 != -1) {
                sprite->PaintFrame(unknown116, x, positionY, 0);
                x = sprite->GetFrameWidth(unknown116) + (x + 1);
                sprite->PaintFrame(unknown116, x, positionY, 0);
                x = sprite->GetFrameWidth(unknown116) + (x + 1);
            }
            drawCash(cash, digitFrames, x, positionY);
        } else {
            drawCash(cash, digitFrames, x, positionY);
            if (unknown116 != -1) {
                int frameWidth = sprite->GetFrameWidth(unknown116);
                x = x + 1 - frameWidth;
                sprite->PaintFrame(unknown116, x, positionY, 0);
                frameWidth = sprite->GetFrameWidth(unknown116);
                x = x + 1 - frameWidth;
                sprite->PaintFrame(unknown116, x, positionY, 0);
            }
        }
    }
}
