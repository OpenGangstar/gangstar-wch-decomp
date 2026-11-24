// UNMATCHED: 420 function/input bytes versus 416 native; no native-address link.
// Historical full-TU fragment with private helper dependencies; not standalone.
namespace {
struct CharacterFindFields {
    unsigned char prefix[128];
    mutable gameswf::player_weak_ptr::proxy_ptr parentReference;
    mutable gameswf::character* parent;
    gameswf::tu_string name;
};
inline void checkFindParent(CharacterFindFields& fields)
{
    if (fields.parent) {
        const unsigned int aliveAddress = reinterpret_cast<unsigned int>(fields.parentReference.value)
            + __builtin_offsetof(MovieWeakReference, alive);
        if (!*reinterpret_cast<const bool*>(aliveAddress)) {
            fields.parentReference.clear();
            fields.parent = 0;
        }
    }
}
inline gameswf::character* findParentCharacter(gameswf::character* character)
{
    CharacterFindFields& fields = *reinterpret_cast<CharacterFindFields*>(character);
    checkFindParent(fields);
    return fields.parent;
}
}

gameswf::character* RenderFX::Find(const char* name, gameswf::character* parent)
{
    char component[256];
    if (!name)
        return 0;
    const int nameLength = strlen(name);
    const char* part = name;
    do {
        const char* end = strchr(part, '.');
        if (!end)
            end = name + nameLength;
        const int length = end - part;
        memcpy(component, part, length);
        component[length] = 0;
        const gameswf::array<gameswf::character*>& candidates = FindCharacters(parent, component, 0);
        gameswf::character* result = 0;
        int bestDepth = 1000;
        for (int i = 0; i < candidates.size; ++i) {
            gameswf::character* character = candidates.elements[i];
            const char* candidateName = reinterpret_cast<const CharacterCollectionFields*>(character)->get_name().c_str();
            if (!*candidateName)
                continue;
            if (strstr(part, candidateName) != part)
                continue;
            if (length != strlen(candidateName))
                continue;
            int depth = 0;
            if (character != parent) {
                do {
                    ++depth;
                    character = findParentCharacter(character);
                } while (character != parent && character);
            }
            if (depth < bestDepth) {
                result = candidates.elements[i];
                bestDepth = depth;
            }
        }
        if (!result)
            return 0;
        parent = result;
        part = end + 1;
        if (part >= name + nameLength)
            return result;
    } while (true);
}
