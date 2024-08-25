#pragma once

#include <memory>

#include "raylib.h"

#include "Graphics/SpriteImage.h"
#include "Graphics/SpriteAnimation.h"
#include "Entity/PlayerCharacter.h"

namespace Lumireth
{
    class Game
    {
    private:
        Camera2D mainCamera = { 0 };

        // TODO: Testing only remove
        std::unique_ptr<Character> knight;
        std::shared_ptr<SpriteSheet> knigthSS;
        Texture map;

    public:
        Game();
        ~Game();

        void Update();
        void Render();
    };
}