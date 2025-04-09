#pragma once

#include "SpriteSheet.h"

namespace Lumireth
{
    class Sprite
    {
    private:
        const SpriteSheet* spriteSheet;

        Rectangle spriteSource;
        Rectangle location{0, 0};
        
        float spriteWidth, spriteHeight;
        float scale{1.f};
        float rotation{0.f};

        Vector2 pivot{0, 0};

    public:
        Sprite(SpriteSheet* spriteSheet);
        ~Sprite();

        virtual void Draw(Color tint = WHITE);

        virtual void SetLocation(float posX, float posY);
        virtual Vector2 GetLocation() const;
        virtual void SetRotation(float rotation);
        virtual float GetRotation() const;
        virtual void SetScale(float scale);

        virtual void SetPivot(Vector2 pivot);
    };
}