#pragma once

#include "raylib.h"
#include "Sprite.h"
#include "SpriteSheet.h"
#include "GraphicsEnums.h"

namespace Lumireth
{
    class SpriteImage : public Sprite
    {
    public:
        SpriteImage(const SpriteSheet& spriteSheet, int tileColumn = 0, int tileRow = 0);
        ~SpriteImage();

        virtual void Update(float posX, float posY, float frameTime) override;
    };
}