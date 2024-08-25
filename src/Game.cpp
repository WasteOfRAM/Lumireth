#include "Game.h"

#include <string>
#include "raylib.h"

#include "Graphics/SpriteImage.h"

Lumireth::Game::Game()
{
    this->mainCamera.target = {0, 0};
    this->mainCamera.zoom = 5.f;
    this->mainCamera.offset = {0, 0};

    // TODO: Only test remove
    this->knigthSS = std::make_shared<SpriteSheet>("Resources/Idle.png", 4, 2);
    this->knight = std::make_unique<PlayerCharacter>();
    this->knight->AddSpriteAnimation(knigthSS.get(), "idle", 1, 2, 1, 4, 8);
    map = LoadTexture("Resources/mapOne.png");
}

Lumireth::Game::~Game()
{
    // TODO: Only test remove
    UnloadTexture(map);
}

void Lumireth::Game::Update()
{
    //TODO: Only test remove
    knight->Update((float)GetMonitorWidth(0) / 2 - 350, (float)GetMonitorHeight(0) / 2 + 60, GetFrameTime());

    mainCamera.target = {(float)GetMonitorWidth(0) / 2 - 400, (float)GetMonitorHeight(0) / 2 - 100};
}

void Lumireth::Game::Render()
{
    BeginDrawing();
    ClearBackground(BLACK);

        BeginMode2D(this->mainCamera);

            // TODO: Only test remove
            DrawTexture(map, 0, 0, WHITE);
            knight->Render(WHITE);

        EndMode2D();

    EndDrawing();
}