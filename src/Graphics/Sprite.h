#pragma once

#include "raylib.h"
#include "SpriteSheet.h"
#include "GraphicsEnums.h"

namespace Lumireth
{
    class Sprite
    {
    private:
        const SpriteSheet& spriteSheet;

    protected:
        Rectangle spriteSource;
        Rectangle dest;
        float spriteWidth, spriteHeight;
        float scale{1.f};

        Vector2 orientation{1, 1};

    public:
        Sprite(const SpriteSheet& spriteSheet, int tileColumn = 0, int tileRow = 0);
        ~Sprite();

        void SetSpriteSize(float width, float height);
        Vector2 GetSpriteSize() const;

        void SetScale(float scale);

        void SetOrientationX(Orientation upDown);
        void SetOrientationY(Orientation leftRight);

        Vector2 GetOrientation() const;

        virtual void Update(float posX, float posY);
        virtual void Render(Color tint);
    };
}