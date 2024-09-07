#pragma once

#include "raylib.h"
#include "GraphicsEnums.h"
#include "SpriteSheet.h"

namespace Lumireth
{
    class Sprite
    {
    protected:
        const SpriteSheet& spriteSheet;

        Rectangle spriteSource;
        Rectangle dest;
        float spriteWidth, spriteHeight;
        float scale{1.f};

        Vector2 orientation{1, 1};
        Vector2 pivot{0, 0};

    public:
        Sprite(const SpriteSheet& spriteSheet);
        ~Sprite() = default;

        virtual void Update(float posX, float posY, float frameTime) = 0;
        virtual void Draw(Color tint);

        virtual void SetOrientationX(Orientation upDown);
        virtual void SetOrientationY(Orientation leftRight);

        virtual Vector2 GetOrientation() const;

        virtual void SetSpriteSize(float width, float height);
        virtual float GetSpriteWidth() const;
        virtual float GetSpriteHeight() const;

        virtual void SetScale(float scale);

        virtual void SetPivot(Vector2 pivot);
        virtual Vector2 GetPivot() const;
    };
}