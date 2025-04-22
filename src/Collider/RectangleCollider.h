#pragma once

#include "ColliderBase.h"

class RectangleCollider : public ColliderBase
{
private:
    Rectangle collider{0, 0, 100, 100};

public:
    RectangleCollider();
    ~RectangleCollider();

    void SetSize(float width, float height);
    virtual void SetScale(float scale) override;
    
    virtual void SetLocation(Vector2 location) override;

    virtual void Debug() override;
};