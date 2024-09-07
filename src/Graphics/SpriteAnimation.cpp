#include "SpriteAnimation.h"

// Starting frame and line start from 1;
Lumireth::SpriteAnimation::SpriteAnimation(const SpriteSheet& spriteSheet, int startFrame, int endFrame, int startLine, int endLine, int framesPreSecond = 1)
    : Sprite(spriteSheet), startingFrame(startFrame - 1), statringLine(startLine - 1), endFrame(endFrame), endLine(endLine), frameSpeed(framesPreSecond)
{
    this->spriteWidth = spriteSheet.GetTexture().width / spriteSheet.GetTileColumnsCount();
    this->spriteHeight = spriteSheet.GetTexture().height / spriteSheet.GetTileRowsCount();
    this->spriteSource = { this->spriteWidth * startingFrame, this->spriteHeight * statringLine, this->spriteWidth, this->spriteHeight };
    this->dest = { 0.f, 0.f, this->spriteWidth * this->scale, this->spriteHeight * this->scale };

    this->currentFrame = this->startingFrame;
    this->currentLine = this->statringLine;
}

Lumireth::SpriteAnimation::~SpriteAnimation()
{
}

// Starting frame and line start from 1;
void Lumireth::SpriteAnimation::SetAnimationFrames(int startFrame, int endFrame, int startLine, int endLine)
{
    this->startingFrame = startFrame - 1;
    this->statringLine = startLine - 1;
    this->endFrame = endFrame;
    this->endLine = endLine;

    this->currentFrame = this->startingFrame;
    this->currentLine = this->statringLine;
}

void Lumireth::SpriteAnimation::SetFramePerSecond(int framesPreSecond)
{
    this->frameSpeed = framesPreSecond;
}

void Lumireth::SpriteAnimation::Update(float posX, float posY, float frameTime)
{
    // TODO: Separate the animation and dest?
    
    this->dest = Rectangle{ posX, posY, this->spriteWidth * scale, this->spriteHeight * scale };

    if (isPlaying)
    {
        framesCounter += frameTime;
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
                                   this->spriteWidth * this->orientation.y,
                                   this->spriteHeight * this->orientation.x };
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

float Lumireth::SpriteAnimation::GetFramesPerSecond() const
{
    return 1.f / this->frameSpeed;
}