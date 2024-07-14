#pragma once

#include "raylib.h"
#include "SpriteSheet.h"

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

    public:
        Sprite(const SpriteSheet& spriteSheet, int tileColumn = 0, int tileRow = 0);
        ~Sprite();

        void SetSpriteSize(float width, float height);
        Vector2 GetSpriteSize() const;

        void SetScale(float scale);

        virtual void Update(float posX, float posY);
        virtual void Render(Color tint);
    };
}