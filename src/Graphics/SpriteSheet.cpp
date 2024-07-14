#include "SpriteSheet.h"

Lumireth::SpriteSheet::SpriteSheet(std::string fileName, int tileRows, int tileColumns)
    :tileRows(tileRows), tileColumns(tileColumns)
{
    this->texture = LoadTexture(fileName.c_str());
}

Lumireth::SpriteSheet::~SpriteSheet()
{
    UnloadTexture(this->texture);
}

const Texture2D &Lumireth::SpriteSheet::GetTexture() const
{
    return this->texture;
}

int Lumireth::SpriteSheet::GetTileRowsCount() const
{
    return this->tileRows;
}

int Lumireth::SpriteSheet::GetTileColumnsCount() const
{
    return this->tileColumns;
}