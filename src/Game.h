#pragma once

#include "raylib.h"

namespace Lumireth
{
    class Game
    {
    private:
        /* data */
    public:
        Game(/* args */);
        ~Game();

        void Update();
        void Render();
    };
}