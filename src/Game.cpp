#include "Game.h"

#include "raylib.h"

Lumireth::Game::Game()
{
    this->mainCamera.target = {0, 0};
    this->mainCamera.zoom = 1.f;
    this->mainCamera.offset = {0, 0};
}

Lumireth::Game::~Game()
{
}

void Lumireth::Game::Update()
{

}

void Lumireth::Game::Render()
{
    BeginDrawing();

    ClearBackground(WHITE);

    BeginMode2D(this->mainCamera);

        //DrawText("Test", GetMonitorWidth(0) / 2, GetMonitorHeight(0) / 2, 70, RED);

    EndMode2D();

    EndDrawing();
}
