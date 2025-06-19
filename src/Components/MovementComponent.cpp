#include "MovementComponent.h"

Lumireth::MovementComponent::MovementComponent()
{
}

Lumireth::MovementComponent::~MovementComponent()
{
}

Vector2 Lumireth::MovementComponent::GetVelocity() const
{
    return this->velocity;
}

void Lumireth::MovementComponent::SetVelocity(Vector2 velocity)
{
    this->velocity = velocity;
}

float Lumireth::MovementComponent::GetMoveSpeed() const
{
    return this->moveSpeed;
}

void Lumireth::MovementComponent::SetMoveSpeed(float moveSpeed)
{
    this->moveSpeed = moveSpeed;
}

float Lumireth::MovementComponent::GetJumpVelocity() const
{
    return this->jumpVelocity;
}

void Lumireth::MovementComponent::SetJumpVelocity(float jumpVelocity)
{
    this->jumpVelocity = jumpVelocity;
}

bool Lumireth::MovementComponent::GetInAir() const
{
    return this->inAir;
}

void Lumireth::MovementComponent::SetInAir(bool inAir)
{
    this->inAir = inAir;
}
