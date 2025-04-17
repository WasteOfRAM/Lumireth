#include "RectangleCollider.h"

RectangleCollider::RectangleCollider()
{
}

RectangleCollider::~RectangleCollider()
{
}

void RectangleCollider::SetSize(float width, float height)
{
    this->collider.width = width * this->scale;
    this->collider.height = height * this->scale;
}

void RectangleCollider::SetScale(float scale)
{
    this->scale = scale;

    this->collider.width *= scale;
    this->collider.height *= scale;
}

void RectangleCollider::SetLocation(Vector2 location)
{
    this->location.x = location.x;
    this->location.y = location.y;

    this->collider.x = location.x;
    this->collider.y = location.y;
}

void RectangleCollider::Debug()
{
    DrawRectangleRec(this->collider, Color(102, 191, 255, 100));
}