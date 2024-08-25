#pragma once

#include <map>
#include <string>
#include <memory>

#include "raylib.h"
#include "Graphics/Sprite.h"
#include "Graphics/SpriteImage.h"
#include "Graphics/SpriteAnimation.h"
#include "Graphics/SpriteSheet.h"

namespace Lumireth
{
    class Character
    {
    protected:
        std::map<std::string, std::shared_ptr<Sprite>> sprites;

    public:
        Character();
        ~Character();

        virtual void AddSprite(SpriteSheet* spriteSheet, std::string name, int tileColumn, int tileRow);
        virtual void AddSpriteAnimation(SpriteSheet* spriteSheet, std::string name, int startFrame, int endFrame, int startLine, int endLine, int framesPreSecond = 1);

        virtual void Update(float posX, float posY, float frameTime) = 0;
        virtual void Render(Color tint) = 0;
    };
}