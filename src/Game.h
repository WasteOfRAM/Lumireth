#pragma once

#include "raylib.h"

namespace Lumireth
{
    class Game
    {
    private:
        Camera2D mainCamera = { 0 };

    public:
        Game();
        ~Game();

        void Update();
        void Render();
    };
}