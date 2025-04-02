#include "SpriteSheet.h"

lit::SpriteSheet::SpriteSheet(std::string fileName)
{
    this->spriteTexture = LoadTexture(fileName.c_str());
}

lit::SpriteSheet::~SpriteSheet()
{
    UnloadTexture(this->spriteTexture);
}

const Texture2D& lit::SpriteSheet::GetTexture() const
{
    return this->spriteTexture;
}
