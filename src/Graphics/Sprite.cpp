#include "Sprite.h"

Lumireth::Sprite::Sprite(SpriteSheet* spriteSheet)
    : spriteSheet(spriteSheet)
{
}

Lumireth::Sprite::~Sprite()
{
}

void Lumireth::Sprite::Draw(Color tint)
{
    DrawTexturePro(this->spriteSheet->GetTexture(), this->spriteSource, this->location, this->pivot, this->rotation, WHITE);
}

void Lumireth::Sprite::SetLocation(float posX, float posY)
{
    this->location.x = posX;
    this->location.y = posY;
}

Vector2 Lumireth::Sprite::GetLocation() const
{
    return Vector2{this->location.x, this->location.y};
}

void Lumireth::Sprite::SetRotation(float rotation)
{
    this->rotation = rotation;
}

float Lumireth::Sprite::GetRotation() const
{
    return this->rotation;
}

void Lumireth::Sprite::SetScale(float scale)
{
    this->scale = scale;
}

void Lumireth::Sprite::SetPivot(Vector2 pivot)
{
    this->pivot = pivot;
}
