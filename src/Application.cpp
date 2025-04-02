#include "Application.h"

void Lumireth::Application::Run()
{
    InitWindow(this->windowWidth, this->windowHeight, this->windowTitle);

    this->windowWidth = GetMonitorWidth(0);
    this->windowHeight = GetMonitorHeight(0);

    SetWindowSize(this->windowWidth, this->windowHeight);

    SetTargetFPS(GetMonitorRefreshRate(0));

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);


        EndDrawing();
    }
    
    CloseWindow();
}