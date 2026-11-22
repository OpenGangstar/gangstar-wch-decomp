void RenderFX::UpdateCursor(Cursor& cursor, int index)
{
    gameswf::render_handler* handler = gameswf::get_render_handler();
    const int orientation = renderHandlerMethods(handler).getOrientation(handler);
    CursorRootView& display = *reinterpret_cast<CursorRootView*>(root.get());
    float viewWidth, viewHeight, width, height;
    if (orientation != 0 && orientation != 2) {
        viewWidth = display.viewportWidth;
        viewHeight = display.viewportHeight;
        width = display.definition->yMax - display.definition->yMin;
        height = display.definition->xMax - display.definition->xMin;
    } else {
        viewWidth = display.viewportWidth;
        viewHeight = display.viewportHeight;
        width = display.definition->xMax - display.definition->xMin;
        height = display.definition->yMax - display.definition->yMin;
    }
    const float x = (cursor.unknown0 - display.viewportX) /
        (viewWidth / (width / 20.0f));
    const float y = (cursor.unknown4 - display.viewportY) /
        (viewHeight / (height / 20.0f));
    if (controllers[index].third.get()) {
        gameswf::matrix matrix;
        matrix.concatenate_translation(x * 20.0f, y * 20.0f);
        matrix.set_scale_rotation(1.0f, 1.0f, cursor.unknown8);
        CharacterTransform& transform = *reinterpret_cast<CharacterTransform*>(controllers[index].third.get());
        transform.placement = matrix;
        transform.hasPlacement = true;
    }
    if (!controllers[index].enabled || !context ||
        ((inputBehavior & 16) && controllers[index].fourth.get()))
        return;
    root->notify_mouse_state(static_cast<int>(x), static_cast<int>(y), 0);
    bool pressed, released, moved;
    if (cursor.unknown12) {
        pressed = !controllers[index].unknown12;
        released = false;
        moved = cursor.unknown0 != controllers[index].unknown0 ||
                cursor.unknown4 != controllers[index].unknown4;
    } else {
        pressed = false;
        released = controllers[index].unknown12 != 0;
        moved = false;
    }
    gameswf::smart_ptr<gameswf::character> target((inputBehavior & 4) ? reinterpret_cast<CursorRootView*>(root.get())->movie : context);
    gameswf::smart_ptr<gameswf::character> hit(
        (**reinterpret_cast<const CursorHitMethods* const*>(target.get())).hit(target.get(), x * 20.0f, y * 20.0f));
    gameswf::smart_ptr<gameswf::character> previousFocus(controllers[index].first.get());
    if (!controllers[index].fifth.get() && (pressed || !(inputBehavior & 8)))
        SetFocus(hit.get(), index);
    if (pressed && controllers[index].first.get() != controllers[index].fourth.get())
        controllers[index].fourth.set_ref(0);
    if (controllers[index].fifth.get() && !CanHandleMouseEvent(controllers[index].fifth.get()))
        controllers[index].fifth.set_ref(0);
    Event event;
    if (hit.get() != controllers[index].second.get()) {
        if (controllers[index].second.get() && CanHandleMouseEvent(controllers[index].second.get())) {
            gameswf::point point = GetLocalPosition(controllers[index].second.get(), x, y);
            event.character = controllers[index].second.get();
            event.payload.y = 0.0f;
            event.payload.x = 0.0f;
            event.payload.z = 0.0f;
            event.payload.unknown24 = 0;
            event.type = 9;
            event.characterName = reinterpret_cast<CursorCharacterName*>(controllers[index].second.get())->name.c_str();
            event.characterPath[0] = 0;
            event.consumed = false;
            event.payload.controller = index;
            event.payload.unknown24 = cursor.unknown12;
            event.payload.x = point.x;
            event.payload.y = point.y;
            SendEvent(event);
        }
        if (hit.get() && CanHandleMouseEvent(hit.get())) {
            gameswf::point point = GetLocalPosition(hit.get(), x, y);
            event.character = hit.get();
            event.payload.y = 0.0f;
            event.payload.x = 0.0f;
            event.payload.z = 0.0f;
            event.payload.unknown24 = 0;
            event.type = 8;
            event.characterName = reinterpret_cast<CursorCharacterName*>(hit.get())->name.c_str();
            event.characterPath[0] = 0;
            event.consumed = false;
            event.payload.controller = index;
            event.payload.unknown24 = cursor.unknown12;
            event.payload.x = point.x;
            event.payload.y = point.y;
            SendEvent(event);
        }
    }
    controllers[index].second.set_ref(hit.get());
    gameswf::smart_ptr<gameswf::character> focus(controllers[index].first.get());
    if (focus.get() && CanHandleMouseEvent(focus.get())) {
        gameswf::point input(x * 20.0f, y * 20.0f);
        gameswf::point point;
        gameswf::matrix world = _ZN7gameswf9character16get_world_matrixEv(focus.get());
        gameswf::matrix inverse;
        inverse.set_inverse(world);
        inverse.transform(&point, input);
        if (pressed) {
            if ((inputBehavior & 1) || hit.get()) {
                PlayAnim(focus.get(), pressedAnimation, 0);
                event.character = focus.get();
                event.payload.y = 0.0f;
                event.payload.x = 0.0f;
                event.payload.z = 0.0f;
                event.payload.unknown24 = 0;
                event.type = 4;
                event.characterName = reinterpret_cast<CursorCharacterName*>(focus.get())->name.c_str();
                event.characterPath[0] = 0;
                event.consumed = false;
                event.payload.controller = index;
                event.payload.unknown24 = cursor.unknown12;
                event.payload.x = point.x;
                event.payload.y = point.y;
                SendEvent(event);
            } else {
                ResetFocus(index);
            }
        } else if (moved) {
            event.character = focus.get();
            event.payload.y = 0.0f;
            event.payload.x = 0.0f;
            event.payload.z = 0.0f;
            event.payload.unknown24 = 0;
            event.type = 5;
            event.characterName = reinterpret_cast<CursorCharacterName*>(focus.get())->name.c_str();
            event.characterPath[0] = 0;
            event.consumed = false;
            event.payload.controller = index;
            event.payload.unknown24 = cursor.unknown12;
            event.payload.x = point.x;
            event.payload.y = point.y;
            SendEvent(event);
            controllers[index].fifth.set_ref(focus.get());
        } else if (released) {
            if ((inputBehavior & 1) || hit.get() == focus.get()) {
                event.character = focus.get();
                event.payload.y = 0.0f;
                event.payload.x = 0.0f;
                event.payload.z = 0.0f;
                event.payload.unknown24 = 0;
                event.type = 6;
                event.characterName = reinterpret_cast<CursorCharacterName*>(focus.get())->name.c_str();
                event.characterPath[0] = 0;
                event.consumed = false;
                event.payload.controller = index;
                event.payload.unknown24 = cursor.unknown12;
                event.payload.x = point.x;
                event.payload.y = point.y;
                if (listener->CanHandleEvent(event)) {
                    bool animated = PlayAnim(focus.get(), releasedAnimation, 0);
                    if (!animated)
                        animated = PlayAnim(focus.get(), clickedAnimation, 0);
                    SendEvent(event);
                    if (!animated) {
                        Event click;
                        click.character = focus.get();
                        click.payload.y = 0.0f;
                        click.payload.x = 0.0f;
                        click.payload.z = 0.0f;
                        click.payload.unknown24 = 0;
                        click.type = 2;
                        click.characterName = reinterpret_cast<CursorCharacterName*>(focus.get())->name.c_str();
                        click.characterPath[0] = 0;
                        click.consumed = false;
                        click.payload.controller = index;
                        click.payload.x = point.x;
                        click.payload.y = point.y;
                        SendEvent(click);
                    } else {
                        controllers[index].fourth.set_ref(focus.get());
                    }
                }
            } else {
            event.character = focus.get();
            event.payload.y = 0.0f;
            event.payload.x = 0.0f;
            event.payload.z = 0.0f;
            event.payload.unknown24 = 0;
            event.type = 7;
            event.characterName = reinterpret_cast<CursorCharacterName*>(focus.get())->name.c_str();
            event.characterPath[0] = 0;
            event.consumed = false;
            event.payload.controller = index;
            event.payload.unknown24 = cursor.unknown12;
            event.payload.x = point.x;
            event.payload.y = point.y;
            SendEvent(event);
                ResetFocus(index);
            }
            controllers[index].fifth.set_ref(0);
        } else if (!(inputBehavior & 1) && !hit.get() && !controllers[index].fifth.get()) {
            ResetFocus(index);
        }
    }
    __builtin_memcpy(&controllers[index].unknown0, &cursor, sizeof(Cursor));
}
