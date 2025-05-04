#pragma once

#include <unordered_map>
#include <string>

#include "Graphics/SpriteAnimation.h"

namespace Lumireth
{
    struct Animation
    {
        std::string name;
        SpriteAnimation* animation;
    };
    
    class AnimationComponent
    {
    private:
        std::unordered_map<std::string, SpriteAnimation*> animations;

    public:
        AnimationComponent();
        ~AnimationComponent();

        void AddAnimation(const std::string& name, SpriteAnimation* animation);
        void SetActiveAnimation(const std::string& name);
        SpriteAnimation* GetAnimation(const std::string& name) const;

        Animation activeAnimation;
    };
}