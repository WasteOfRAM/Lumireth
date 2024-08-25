#include "PlayerCharacter.h"

Lumireth::PlayerCharacter::PlayerCharacter()
{

}

Lumireth::PlayerCharacter::~PlayerCharacter()
{
}

void Lumireth::PlayerCharacter::Update(float posX, float posY, float frameTime)
{
    currentSprite = sprites.begin()->first;
    sprites[currentSprite]->Update(posX, posY, frameTime);
}

void Lumireth::PlayerCharacter::Render(Color tint)
{
    sprites[currentSprite]->Render(tint);
}