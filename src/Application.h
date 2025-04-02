#pragma once

#include "raylib.h"

namespace Lumireth
{
    class Application
    {
    private:
        int windowWidth{0};
        int windowHeight{0};    
        const char* windowTitle = "Lumireth";

    public:
        void Run();
    };
}