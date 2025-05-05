#include "Entity.h"

Lumireth::Entity::Entity()
{
}

Lumireth::Entity::~Entity()
{
}

void Lumireth::Entity::SetLocation(Vector2 location)
{
    this->location = location;
}

void Lumireth::Entity::SetLocation(float posX, float posY)
{
    this->location.x = posX;
    this->location.y = posY;
}

Vector2 Lumireth::Entity::GetLocation() const
{
    return this->location;
}