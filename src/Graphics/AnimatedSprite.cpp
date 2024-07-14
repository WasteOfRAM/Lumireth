#include "AnimatedSprite.h"

Lumireth::AnimatedSprite::AnimatedSprite(const SpriteSheet& spriteSheet)
    : Sprite(spriteSheet)
{
}

Lumireth::AnimatedSprite::AnimatedSprite(const SpriteSheet &spriteSheet, int startFrame, int startLine, int endFrame, int endLine)
    : Sprite(spriteSheet), startingFrame(startFrame), statringLine(startLine), endFrame(endFrame), endLine(endLine)
{
}

Lumireth::AnimatedSprite::~AnimatedSprite()
{
}

void Lumireth::AnimatedSprite::SetAnimationFrames(int startFrame, int startLine, int endFrame, int endLine)
{
    this->startingFrame = startFrame;
    this->statringLine = startLine;
    this->endFrame = endFrame;
    this->endLine = endLine;
}

void Lumireth::AnimatedSprite::SetFramePerSecond(int framesPreSecond)
{
    this->frameSpeed = framesPreSecond;
}

void Lumireth::AnimatedSprite::Update(float posX, float posY)
{
    framesCounter += GetFrameTime();
    if (framesCounter >= this->GetFramesPerSecond())
    {
        framesCounter = 0;
        currentFrame++;

        if (currentFrame >= endFrame)
        {
            currentFrame = startingFrame;
            currentLine++;

            if (currentLine >= endLine)
            {
                currentLine = statringLine;
            }
        }
        framesCounter = 0;
    }

    this->spriteSource = Rectangle{this->spriteWidth * currentFrame, this->spriteHeight * currentLine, this->spriteWidth, this->spriteHeight};
    this->dest = Rectangle{posX, posY, this->spriteWidth * scale, this->spriteHeight * scale};
}

float Lumireth::AnimatedSprite::GetFramesPerSecond() const
{
    return 1.f / this->frameSpeed;
}