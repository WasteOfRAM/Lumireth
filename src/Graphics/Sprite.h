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
        Vector2 pivot{0, 0};

    public:
        Sprite(const SpriteSheet& spriteSheet, int tileColumn = 0, int tileRow = 0);
        ~Sprite();

        void SetSpriteSize(float width, float height);
        float GetSpriteWidth() const;
        float GetSpriteHeight() const;

        void SetScale(float scale);

        void SetOrientationX(Orientation upDown);
        void SetOrientationY(Orientation leftRight);

        Vector2 GetOrientation() const;

        void SetPivot(Vector2 pivot);
        Vector2 GetPivot() const;

        Vector2 GetPosition() const;

        virtual void Update(float posX, float posY);
        virtual void Render(Color tint);
    };
}