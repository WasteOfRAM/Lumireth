#include "Sprite.h"

#include <iostream>

Lumireth::Sprite::Sprite(const SpriteSheet& spriteSheet, int tileColumn, int tileRow)
    : spriteSheet(spriteSheet)
{
    this->spriteWidth = spriteSheet.GetTexture().width / spriteSheet.GetTileColumnsCount();
    this->spriteHeight = spriteSheet.GetTexture().height / spriteSheet.GetTileRowsCount();
    this->spriteSource = {this->spriteWidth * tileColumn, this->spriteHeight * tileRow, this->spriteWidth, this->spriteHeight};
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

void Lumireth::Sprite::Update(float posX, float posY)
{
    this->dest = Rectangle{posX, posY, this->spriteWidth * scale, this->spriteHeight * scale};
}

void Lumireth::Sprite::Render(Color tint)
{
    DrawTexturePro(this->spriteSheet.GetTexture(), this->spriteSource, this->dest, Vector2{}, 0.f, tint);
}
