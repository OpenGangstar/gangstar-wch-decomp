#ifndef WCH_PERSISTENCE_TEXT_STYLE_H
#define WCH_PERSISTENCE_TEXT_STYLE_H

class DataStream;

// Observed 40-byte serialized record; font field names remain provisional.
namespace Structs {
struct TextStyle {
    void Read(DataStream& stream);
    int unknown0;
    char* fontName;
    int fontSize;
    bool unknown12;
    int unknown16;
    int unknown20;
    int unknown24;
    int unknown28;
    int unknown32;
    bool unknown36;
    bool unknown37;
};
}

#endif
