#pragma once

#include "raylib.h"

namespace Lumireth
{
    class Sprite
    {
    private:
        Texture2D spriteSheet;

    protected:
        Rectangle spriteSource;
        Rectangle dest;
        float spriteWidth, spriteHeight;
        float scale{1.f};

    public:
        Sprite(const Texture2D &spriteSheet, int spriteSheetRows = 1, int spriteSheetCols = 1);
        ~Sprite();

        void SetSpriteSize(float width, float height);
        Vector2 GetSpriteSize() const;

        void SetScale(float scale);

        virtual void Update(float posX, float posY);
        virtual void Render(Color tint);
    };
}