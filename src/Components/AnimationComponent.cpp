#include "Components/AnimationComponent.h"

Lumireth::AnimationComponent::AnimationComponent()
{
}

Lumireth::AnimationComponent::~AnimationComponent()
{
}

void Lumireth::AnimationComponent::AddAnimation(const std::string& name, SpriteAnimation* animation)
{
    this->animations.insert({name, animation});
}

void Lumireth::AnimationComponent::SetActiveAnimation(const std::string& name)
{
    auto it = this->animations.find(name);
    this->activeAnimation.name = it->first;
    this->activeAnimation.animation = it->second;
}

Lumireth::SpriteAnimation* Lumireth::AnimationComponent::GetAnimation(const std::string& name) const
{
    auto it = this->animations.find(name);
    if (it != this->animations.end())
    {
        return it->second;
    }
    
    return nullptr;
}