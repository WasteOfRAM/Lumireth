#pragma once

#include "ColliderBase.h"

namespace Lumireth
{
    class CircleCollider : public ColliderBase
    {
    private:
        float radius{10}; 

    public:
        CircleCollider();
        ~CircleCollider();

        virtual void SetScale(float scale) override;

        virtual void SetLocation(Vector2 location) override;

        virtual void Debug() override;
    };
}