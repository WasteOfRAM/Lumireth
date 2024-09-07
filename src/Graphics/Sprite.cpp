#include "Sprite.h"

Lumireth::Sprite::Sprite(const SpriteSheet& spriteSheet)
    : spriteSheet(spriteSheet)
{
}

void Lumireth::Sprite::Draw(Color tint)
{
    DrawTexturePro(this->spriteSheet.GetTexture(), this->spriteSource, this->dest, this->pivot, 0.f, tint);
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

void Lumireth::Sprite::SetPivot(Vector2 pivot)
{
    this->pivot = pivot;
}

Vector2 Lumireth::Sprite::GetPivot() const
{
    return this->pivot;
}