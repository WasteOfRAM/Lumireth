#pragma once

#include "raylib.h"

class ColliderBase
{
protected:
    Vector2 location;
    
public:

    virtual void SetLocation(Vector2 location) = 0;
    virtual Vector2 GetLocation() const;

    // TODO: Limit the debuiging only for debug builds.
    // Drawing the collider for easyer debuging. Development only.
    virtual void Debug() = 0;
};