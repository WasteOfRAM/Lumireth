#pragma once

#include "raylib.h"

class ColliderBase
{
private:
    Vector2 location;
    
public:

    void SetLocation(Vector2 location);
    Vector2 GetLocation() const;

    // TODO: Limit the debuiging only for debug builds.
    // Drawing the collider for easyer debuging. Development only.
    virtual void Debug() = 0;
};