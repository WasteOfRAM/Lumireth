#include "Sprite.h"

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

void Lumireth::Sprite::SetOrientationX(Orientation upDown)
{
    this->orientation.x = static_cast<float>(upDown);
}

void Lumireth::Sprite::SetOrientationY(Orientation leftRight)
{
    this->orientation.y = static_cast<float>(leftRight);
}

Vector2 Lumireth::Sprite::GetOrientation() const
{
    return this->orientation;
}

void Lumireth::Sprite::Update(float posX, float posY)
{
    this->spriteSource.width = this->spriteWidth * this->orientation.y;
    this->spriteSource.height = this->spriteHeight * this->orientation.x;

    this->dest = Rectangle{posX, posY, this->spriteWidth * scale, this->spriteHeight * scale};
}

void Lumireth::Sprite::Render(Color tint)
{
    // Origin set to bottom middle of the sprite.
    DrawTexturePro(this->spriteSheet.GetTexture(), this->spriteSource, this->dest, Vector2{this->dest.width / 2, this->dest.height}, 0.f, tint);
}
