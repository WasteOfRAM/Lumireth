#include "SpriteAnimation.h"

Lumireth::SpriteAnimation::SpriteAnimation(SpriteSheet* spriteSheet, float frameWidth, float frameHeight)
    : Sprite(spriteSheet, frameWidth, frameHeight)
{
}

Lumireth::SpriteAnimation::~SpriteAnimation()
{
}

void Lumireth::SpriteAnimation::FrameUpdate(float frameTime)
{
    if (isPlaying)
    {
        framesCounter += frameTime;
        if (framesCounter >= (1.f / this->framesPerSecond))
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

                    if (!loop)
                    {
                        Stop();
                        return;
                    }
                }
            }
            framesCounter = 0;
        }
    }

    this->spriteSource = Rectangle{ this->spriteWidth * currentFrame,
                                    this->spriteHeight * currentLine,
                                    this->spriteWidth,
                                    this->spriteHeight };
}

void Lumireth::SpriteAnimation::SetAnimationFrames(int startFrame, int endFrame, int startLine, int endLine, int framesPerSecond)
{
    this->startingFrame = startFrame - 1;
    this->endFrame = endFrame;
    this->statringLine = startLine - 1;
    this->endLine = endLine;

    this->framesPerSecond = framesPerSecond;
}

void Lumireth::SpriteAnimation::Play()
{
    this->isPlaying = true;
}

void Lumireth::SpriteAnimation::Pause()
{
    this->isPlaying = false;
}

void Lumireth::SpriteAnimation::Stop()
{
    this->isPlaying = false;
    this->currentFrame = this->startingFrame;
    this->currentLine = this->statringLine;
}

void Lumireth::SpriteAnimation::SetLooping(bool loop)
{
    this->loop = loop;
}

bool Lumireth::SpriteAnimation::IsLooping() const
{
    return this->loop;
}

bool Lumireth::SpriteAnimation::IsPlaying() const
{
    return this->isPlaying;
}
