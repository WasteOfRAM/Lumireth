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

float Lumireth::Sprite::GetSpriteWidth() const
{
    return this->spriteWidth;
}

float Lumireth::Sprite::GetSpriteHeight() const
{
    return this->spriteHeight;
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

void Lumireth::Sprite::SetPivot(Vector2 pivot)
{
    this->pivot = pivot;
}

Vector2 Lumireth::Sprite::GetPivot() const
{
    return this->pivot;
}

Vector2 Lumireth::Sprite::GetPosition() const
{
    return Vector2(this->dest.x, this->dest.y);
}

void Lumireth::Sprite::Update(float posX, float posY)
{
    this->spriteSource.width = this->spriteWidth * this->orientation.y;
    this->spriteSource.height = this->spriteHeight * this->orientation.x;

    this->dest = Rectangle{posX, posY, this->spriteWidth * scale, this->spriteHeight * scale};
}

void Lumireth::Sprite::Render(Color tint)
{
    DrawTexturePro(this->spriteSheet.GetTexture(), this->spriteSource, this->dest, this->pivot, 0.f, tint);
}
