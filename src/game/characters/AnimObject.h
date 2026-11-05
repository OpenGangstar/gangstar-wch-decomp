#ifndef WCH_CHARACTERS_ANIM_OBJECT_H
#define WCH_CHARACTERS_ANIM_OBJECT_H

class ASprite;

class AnimObject {
public:
    AnimObject();
    ~AnimObject();
    virtual void Update(int elapsed);
    void SetAnim(int animation);
    void SetAnim(int animation, int frameLimit);
    void Draw();
    void Load();
    void Unload();
    void Reset();
    void SetPosition(float x, float y, float z);
    void ChangeAnim(int animation);
    void Restart();
    void UpdateFrame();
    bool IsAnimOver();

private:
    float x;
    float y;
    float z;
    int animation;
    float frame;
    int frameLimit;
    float speed;
    bool unknown32;
    float frameStep;

public:
    ASprite* sprite;
};

#endif
