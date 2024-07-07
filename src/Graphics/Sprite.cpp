#include "Sprite.h"

Lumireth::Sprite::Sprite(const Texture2D& spriteSheet, int spriteSheetRows, int spriteSheetCols)
    : spriteSheet(spriteSheet)
{
    this->spriteWidth = spriteSheet.width / spriteSheetCols;
    this->spriteHeight = spriteSheet.height / spriteSheetRows;
    this->spriteSource = {0.f, 0.f, this->spriteWidth, this->spriteHeight};
    this->dest = {0.f, 0.f, this->spriteWidth * this->scale, this->spriteHeight * this->scale};
}

Lumireth::Sprite::~Sprite()
{
}

void Lumireth::Sprite::SetSpriteSize(float width, float height)
{
    this->spriteWidth = width;
    this->spriteHeight = height;
}

Vector2 Lumireth::Sprite::GetSpriteSize() const
{
    return Vector2(this->spriteWidth, this->spriteHeight);
}

void Lumireth::Sprite::SetScale(float scale)
{
    this->scale = scale;
}

void Lumireth::Sprite::Update(float x, float y, float width, float height)
{
    this->dest = Rectangle{x, y, width * scale, height * scale};
}

void Lumireth::Sprite::Render(Color tint)
{
    DrawTexturePro(this->spriteSheet, this->spriteSource, this->dest, Vector2{}, 0.f, tint);
}
