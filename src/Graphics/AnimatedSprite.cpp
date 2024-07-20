#include "AnimatedSprite.h"

Lumireth::AnimatedSprite::AnimatedSprite(const SpriteSheet& spriteSheet)
    : Sprite(spriteSheet)
{
}

// Starting frame and line start from 1;
Lumireth::AnimatedSprite::AnimatedSprite(const SpriteSheet &spriteSheet, int startFrame, int startLine, int endFrame, int endLine)
    : Sprite(spriteSheet), startingFrame(startFrame - 1), statringLine(startLine - 1), endFrame(endFrame), endLine(endLine)
{
    this->currentFrame = this->startingFrame;
    this->currentLine = this->statringLine;
}

Lumireth::AnimatedSprite::~AnimatedSprite()
{
}

// Starting frame and line start from 1;
void Lumireth::AnimatedSprite::SetAnimationFrames(int startFrame, int startLine, int endFrame, int endLine)
{
    this->startingFrame = startFrame - 1;
    this->statringLine = startLine - 1;
    this->endFrame = endFrame;
    this->endLine = endLine;

    this->currentFrame = this->startingFrame;
    this->currentLine = this->statringLine;
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