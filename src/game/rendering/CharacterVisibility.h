#ifndef WCH_RENDERING_CHARACTER_VISIBILITY_H
#define WCH_RENDERING_CHARACTER_VISIBILITY_H

namespace gameswf { class character; }

// The retail character and sprite_instance vtables share set_visible at slot 81.
struct CharacterVisibility {
    void (*otherMethods[81])();
    void (*setVisible)(gameswf::character*, bool);
};

inline void setCharacterVisible(gameswf::character* character, bool visible)
{
    const CharacterVisibility* methods =
        *reinterpret_cast<const CharacterVisibility* const*>(character);
    methods->setVisible(character, visible);
}

#endif
