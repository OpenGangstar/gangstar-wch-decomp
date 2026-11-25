/*
* Copyright (c) 2006-2007 Erin Catto http://www.gphysics.com
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/
// Altered: licensed Box2D 2.0.1 shape definitions with native weak destructor imports.
#ifndef WCH_VEHICLE_CREATE_BODY_SHAPES_H
#define WCH_VEHICLE_CREATE_BODY_SHAPES_H
#include "../core/PhysicsBodyDef.h"
enum b2ShapeType { e_unknownShape=-1, e_circleShape, e_polygonShape, e_shapeTypeCount };
struct b2ShapeDef {
    b2ShapeDef() {
        type = e_unknownShape;
        userData = 0;
        friction = 0.2f;
        restitution = 0.0f;
        density = 0.0f;
        filter.categoryBits = 0x0001;
        filter.maskBits = 0xffff;
        filter.groupIndex = 0;
        isSensor = false;
    }
    virtual ~b2ShapeDef() {}
    b2ShapeType type;
    void* userData;
    float friction, restitution, density;
    bool isSensor;
    b2FilterData filter;
};
struct b2PolygonDef : b2ShapeDef {
    b2PolygonDef() { type = e_polygonShape; vertexCount = 0; }
    virtual ~b2PolygonDef() __attribute__((used)) {}
    void SetAsBox(float hx, float hy, const b2Vec2& center, float angle);
    b2Vec2 vertices[8];
    int vertexCount;
};
struct b2CircleDef : b2ShapeDef {
    b2CircleDef() { type = e_circleShape; localPosition.SetZero(); radius = 1.0f; }
    virtual ~b2CircleDef() __attribute__((used)) {}
    b2Vec2 localPosition;
    float radius;
};
#endif

// Diagnostic reuse: these destructor bodies already compare exactly in the
// accepted Character/GS3DStuff objects; this complete-class emission still
// requires its own native-byte proof. No synthetic noinline body is added.
