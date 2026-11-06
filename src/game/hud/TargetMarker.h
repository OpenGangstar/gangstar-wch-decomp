#ifndef WCH_HUD_TARGET_MARKER_H
#define WCH_HUD_TARGET_MARKER_H

class ASprite;

class TargetMarker {
public:
    static TargetMarker* getInstance() __attribute__((weak, used));
    void init(ASprite* sprite, int markerFrame, int targetFrame);

private:
    TargetMarker();
    ~TargetMarker();

    ASprite* sprite;
    int markerFrame;
    int targetFrame;
    float depth;
    int offsetX, offsetY;
    bool enabled;
};

#endif
