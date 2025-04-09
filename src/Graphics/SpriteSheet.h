#pragma once

#include <string>
#include "raylib.h"

namespace Lumireth
{
    class SpriteSheet
    {
    private:
        Texture2D spriteTexture;

    public:
        SpriteSheet(std::string fileName);
        ~SpriteSheet();

        const Texture2D& GetTexture() const;
    };
}