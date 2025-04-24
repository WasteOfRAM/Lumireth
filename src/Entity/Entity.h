#pragma once

#include "raylib.h"

namespace Lumireth
{
    class Entity
    {
    private:
        Vector2 location{ 0, 0 };

    public:
        Entity(/* args */);
        ~Entity();

        virtual void SetLocation(Vector2 location);
        virtual Vector2 GetLocation() const;
    };
}