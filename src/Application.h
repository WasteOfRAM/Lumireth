#pragma once

#include "raylib.h"
#include "Game.h"

#include <memory>

namespace Lumireth
{
    class Application
    {
    private:
        int windowWidth{0};
        int windowHeight{0};    
        const char* windowTitle = "Lumireth";

        std::unique_ptr<Game> game;

    public:
        void Run();
    };
}