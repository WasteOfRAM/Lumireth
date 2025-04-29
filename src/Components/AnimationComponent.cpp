#include "AnimationComponent.h"

Lumireth::AnimationComponent::AnimationComponent()
{
}

Lumireth::AnimationComponent::~AnimationComponent()
{
}

void Lumireth::AnimationComponent::AddAnimation(std::string name, SpriteAnimation* animation)
{
    this->animations.insert({name, animation});
}

void Lumireth::AnimationComponent::SetActiveAnimation(std::string name)
{
    this->activeAnimation = this->animations[name];
}