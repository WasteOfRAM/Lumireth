#include "Application.h"

void Lumireth::Application::Run()
{
    InitWindow(this->windowWidth, this->windowHeight, this->windowTitle);

    this->windowWidth = GetMonitorWidth(0);
    this->windowHeight = GetMonitorHeight(0);

    SetWindowSize(this->windowWidth, this->windowHeight);

    SetTargetFPS(GetMonitorRefreshRate(0));

    this->game = std::make_unique<Game>();

    while (!WindowShouldClose())
    {
        this->game->Update();
        this->game->Render();
    }
    
    CloseWindow();
}