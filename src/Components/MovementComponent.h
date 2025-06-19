#pragma once

#include "raylib.h"


namespace Lumireth
{
    class MovementComponent
    {
    private:
        const float gravity = 1000;

        Vector2 velocity{ 0, 0 };
        float jumpVelocity = -600;
        float moveSpeed = 300;

        bool inAir = false;

    public:
        MovementComponent();
        ~MovementComponent();

        Vector2 GetVelocity() const;
        void SetVelocity(Vector2 velocity);

        float GetMoveSpeed() const;
        void SetMoveSpeed(float moveSpeed);

        float GetJumpVelocity() const;
        void SetJumpVelocity(float jumpVelocity);

        bool GetInAir() const;
        void SetInAir(bool inAir);
    };
}
