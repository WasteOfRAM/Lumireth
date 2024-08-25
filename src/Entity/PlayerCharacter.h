#pragma once

#include "Graphics/SpriteAnimation.h"
#include "Character.h"

namespace Lumireth
{
    class PlayerCharacter : public Character
    {
    private:
        std::string currentSprite;

    public:
        PlayerCharacter();
        ~PlayerCharacter();

        virtual void Update(float posX, float posY, float frameTime);
        virtual void Render(Color tint);
    };
}