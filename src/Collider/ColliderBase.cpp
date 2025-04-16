#include "ColliderBase.h"

void ColliderBase::SetLocation(Vector2 location)
{
    this->location = location;
}

Vector2 ColliderBase::GetLocation() const
{
    return this->location;
}
