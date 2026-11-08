#ifndef WCH_CORE_PHYSICS_H
#define WCH_CORE_PHYSICS_H

class LevelObject;
namespace irr { namespace scene { class ISceneNode; } }

// Partial retail Box2D call interfaces and observed field prefixes only.
// b2Body/b2Shape/b2World are call-only views: do not instantiate them.
// The small vector, bounds and segment records describe the observed call ABI.
// No complete engine object layouts or additional matched symbols are asserted.
struct b2Vec2 {
    float x, y;
    b2Vec2() {}
};
struct b2AABB { b2Vec2 lowerBound, upperBound; };
struct b2Segment { b2Vec2 p1, p2; };
struct b2XForm { b2Vec2 position; float rotation[4]; };
struct b2FilterData { unsigned short categoryBits, maskBits; short groupIndex; };
struct PhysicsBodyData {
    LevelObject* owner;
    irr::scene::ISceneNode* node;
    float lowerHeight, upperHeight;
};
class b2Shape;
class b2Body {
public:
    unsigned char unknown0[4];
    const b2XForm& GetXForm() const { return transform; }
    void* GetUserData() const { return data; }
    b2XForm transform;
    unsigned char unknown28[72];
    b2Shape* shapeList;
    unsigned char unknown104[40];
    void* data;
};
class b2Shape {
public:
    virtual void unknown0();
    virtual int TestSegment(const b2XForm&, float*, b2Vec2*, const b2Segment&, float) const;
    unsigned char unknown4[4];
    b2Shape* next;
    b2Body* body;
    unsigned char unknown16[18];
    b2FilterData filter;
    bool isSensor;
    const b2FilterData& GetFilterData() const { return filter; }
    bool IsSensor() const { return isSensor; }
    b2Body* GetBody() { return body; }
};
class b2World {
public:
    ~b2World();
    void DestroyBody(b2Body* body);
    void Refilter(b2Shape* shape);
    void Step(float, int);
    int Query(const b2AABB&, b2Shape**, int);
};

struct b2ContactPoint;
struct b2ContactResult;
class b2ContactListener {
public:
    virtual ~b2ContactListener() {}
    virtual void Add(const b2ContactPoint*) {}
    virtual void Persist(const b2ContactPoint*) {}
    virtual void Remove(const b2ContactPoint*) {}
    virtual void Result(const b2ContactResult*) {}
};
class b2ContactFilter {
public:
    virtual ~b2ContactFilter() {}
    virtual bool ShouldCollide(b2Shape* first, b2Shape* second);
};

#endif
