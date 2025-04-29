#pragma once

#include <unordered_map>

#include "Graphics/SpriteAnimation.h"

namespace Lumireth
{
    class AnimationComponent
    {
    private:
        std::unordered_map<std::string, SpriteAnimation*> animations;

    public:
        AnimationComponent();
        ~AnimationComponent();

        void AddAnimation(std::string name, SpriteAnimation* animation);
        void SetActiveAnimation(std::string name);

        SpriteAnimation* activeAnimation;
    };
}