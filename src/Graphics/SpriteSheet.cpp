#include "SpriteSheet.h"

Lumireth::SpriteSheet::SpriteSheet(std::string fileName)
{
    this->spriteTexture = LoadTexture(fileName.c_str());
}

Lumireth::SpriteSheet::~SpriteSheet()
{
    UnloadTexture(this->spriteTexture);
}

const Texture2D& Lumireth::SpriteSheet::GetTexture() const
{
    return this->spriteTexture;
}