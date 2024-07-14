#pragma once

#include <string>
#include "raylib.h"

namespace Lumireth
{
    class SpriteSheet
    {
    private:
        Texture2D texture;
        int tileRows;
        int tileColumns;

    public:
        SpriteSheet(std::string fileName, int tileRows = 1, int tileColumns = 1);
        ~SpriteSheet();

        const Texture2D& GetTexture() const;
        int GetTileRowsCount() const;
        int GetTileColumnsCount() const;
    };
}