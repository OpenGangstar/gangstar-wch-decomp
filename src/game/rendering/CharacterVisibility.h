#ifndef WCH_RENDERING_CHARACTER_VISIBILITY_H
#define WCH_RENDERING_CHARACTER_VISIBILITY_H

namespace gameswf { class character; }

// The retail character and sprite_instance vtables share set_visible and
// get_visible at slots 81 and 82.
struct CharacterVisibility {
    void (*otherMethods[81])();
    void (*setVisible)(gameswf::character*, bool);
    bool (*getVisible)(const gameswf::character*);
};

inline void setCharacterVisible(gameswf::character* character, bool visible)
{
    const CharacterVisibility* methods =
        *reinterpret_cast<const CharacterVisibility* const*>(character);
    methods->setVisible(character, visible);
}

inline bool isCharacterVisible(const gameswf::character* character)
{
    const CharacterVisibility* methods =
        *reinterpret_cast<const CharacterVisibility* const*>(character);
    return methods->getVisible(character);
}

#endif
