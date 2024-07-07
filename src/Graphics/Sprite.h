#pragma once

#include "raylib.h"

namespace Lumireth
{
    class Sprite
    {
    private:
        Texture2D spriteSheet;
        Rectangle spriteSource;
        Rectangle dest;
        float spriteWidth, spriteHeight;
        float scale{1.f};

    public:
        // TODO: How to take the Texture2D as a ref or ??? unique or shared ptr?
        Sprite(Texture2D spriteSheet, int spriteSheetRows = 1, int spriteSheetCols = 1);
        ~Sprite();

        void SetSpriteSize(float width, float height);
        Vector2 GetSpriteSize() const;

        void SetScale(float scale);

        virtual void Update(float x, float y, float width, float height);
        virtual void Render(Color tint);
    };
}