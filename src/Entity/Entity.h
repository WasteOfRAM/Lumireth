#pragma once

#include "raylib.h"

namespace Lumireth
{
    class Entity
    {
    private:
        Vector2 location{ 0, 0 };

    public:
        Entity();
        ~Entity();

        virtual void SetLocation(Vector2 location);
        virtual Vector2 GetLocation() const;

        virtual void Update(float frameTime) = 0;
        virtual void Draw(Color tint = WHITE) = 0;
    };
}