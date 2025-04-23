#include "Entity.h"

void Lumireth::Entity::SetLocation(Vector2 location)
{
    this->location = location;
}

Vector2 Lumireth::Entity::GetLocation() const
{
    return this->location;
}
