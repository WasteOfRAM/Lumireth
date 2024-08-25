#include "Character.h"

Lumireth::Character::Character()
{
}

Lumireth::Character::~Character()
{
}

void Lumireth::Character::AddSprite(SpriteSheet* spriteSheet, std::string name, int tileColumn, int tileRow)
{
    sprites.emplace(name, std::make_shared<SpriteImage>(*spriteSheet, tileColumn, tileRow));
}

void Lumireth::Character::AddSpriteAnimation(SpriteSheet* spriteSheet, std::string name, int startFrame, int endFrame, int startLine, int endLine, int framesPreSecond)
{
    sprites.emplace(name, std::make_shared<SpriteAnimation>(*spriteSheet, startFrame, endFrame, startLine, endLine, framesPreSecond));
}