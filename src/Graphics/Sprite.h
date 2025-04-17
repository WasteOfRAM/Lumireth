#pragma once

#include "GraphicsEnums.h"
#include "SpriteSheet.h"

namespace Lumireth
{
    class Sprite
    {
    protected:
        const SpriteSheet* spriteSheet;

        Rectangle spriteSource;
        Rectangle transform;

        // Uniform scale multiplier applyed to the sprite Height and Width size in pixels.
        float scale{ 1 };

        float rotation{ 0.f };

        // The point in the sprite that will be used as origin for location, rotation and scale.
        // Pixel point from 0 to spriteWidth and 0 to spriteHeight.
        Vector2 origin{ 0, 0 };

    public:
        // spriteOriginX and spriteOriginY - Sprite location in the sprite sheet in pixels.
        Sprite(SpriteSheet* spriteSheet, float spriteWidth, float spriteHeight, float spriteOriginX = 0, float spriteOriginY = 0);
        ~Sprite();

        virtual void Draw(Color tint = WHITE);

        virtual void SetLocation(float posX, float posY);
        virtual Vector2 GetLocation() const;

        virtual void SetRotation(float rotation);
        virtual float GetRotation() const;

        // Sets texture left rigth orientation. (Flips the texture)
        virtual void SetOrientation(Orientation spriteOrientation);

        virtual void SetScale(float scale);
        virtual float GetScale() const;

        // Origin in pixels from the original unscaled sprite starting from 0 no matter the sprite position in pixels in the sprite sheet.
        // "x" from the vector is height and "y" is width 
        virtual void SetOrigin(Vector2 origin);
        virtual Vector2 GetOrigin() const;
    };
}