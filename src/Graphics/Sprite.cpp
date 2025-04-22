#include "Sprite.h"

Lumireth::Sprite::Sprite(SpriteSheet* spriteSheet, float spriteWidth, float spriteHeight, float spriteOriginX, float spriteOriginY)
    : spriteSheet(spriteSheet)
{
    this->spriteSource.width = spriteWidth;
    this->spriteSource.height = spriteHeight;
    this->spriteSource.x = spriteOriginX;
    this->spriteSource.y = spriteOriginY;

    this->transform.x = 0;
    this->transform.y = 0;
    this->transform.width = spriteWidth;
    this->transform.height = spriteHeight;
}

Lumireth::Sprite::~Sprite()
{
}

void Lumireth::Sprite::Draw(Color tint)
{
    DrawTexturePro(this->spriteSheet->GetTexture(), this->spriteSource, this->transform, this->origin, this->rotation, WHITE);
}

void Lumireth::Sprite::SetLocation(float posX, float posY)
{
    this->transform.x = posX;
    this->transform.y = posY;
}

Vector2 Lumireth::Sprite::GetLocation() const
{
    return Vector2{this->transform.x, this->transform.y};
}

void Lumireth::Sprite::SetRotation(float rotation)
{
    this->rotation = rotation;
}

float Lumireth::Sprite::GetRotation() const
{
    return this->rotation;
}

void Lumireth::Sprite::SetOrientation(Orientation spriteOrientation)
{
    this->spriteSource.width *= static_cast<int>(spriteOrientation);
}

void Lumireth::Sprite::SetScale(float scale)
{
    this->scale = scale;

    this->transform.width = this->spriteSource.width * this->scale;
    this->transform.height = this->spriteSource.height * this->scale;
}

float Lumireth::Sprite::GetScale() const
{
    return this->scale;
}

void Lumireth::Sprite::SetOrigin(Vector2 origin)
{
    this->origin.x = origin.x * this->scale;
    this->origin.y = origin.y * this->scale;
}

Vector2 Lumireth::Sprite::GetOrigin() const
{
    return this->origin;
}
