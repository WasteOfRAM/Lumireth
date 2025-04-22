#include "CircleCollider.h"

Lumireth::CircleCollider::CircleCollider()
{
}

Lumireth::CircleCollider::~CircleCollider()
{
}

void Lumireth::CircleCollider::SetScale(float scale)
{
    this->scale = scale;

    this->radius *= scale;
}

void Lumireth::CircleCollider::SetLocation(Vector2 location)
{
    this->location = location;
}

void Lumireth::CircleCollider::Debug()
{
    DrawCircleV(this->location, this->radius, Color(0, 158, 47, 100));
}
