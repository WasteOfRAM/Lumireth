#pragma once

#include "raylib.h"

class ColliderBase
{
protected:
    Vector2 location;
    float scale{ 1 };

public:

    virtual void SetScale(float scale) = 0;
    virtual float GetScale() const;
 
    virtual void SetLocation(Vector2 location) = 0;
    virtual Vector2 GetLocation() const;

    // TODO: Limit the debuiging only for debug builds.
    // Drawing the collider for easyer debuging. Development only.
    virtual void Debug() = 0;
};