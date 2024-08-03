#pragma once

#include "Sprite.h"

namespace Lumireth
{
    class AnimatedSprite : public Sprite
    {
    private:
        int startingFrame{};
        int statringLine{};

        int endFrame{};
        int endLine{};

        int currentFrame{};
        int currentLine{};

        float framesCounter{};
        int frameSpeed{};

    public:
        AnimatedSprite(const SpriteSheet& spriteSheet);
        AnimatedSprite(const SpriteSheet& spriteSheet, int startFrame, int endFrame, int startLine, int endLine);
        ~AnimatedSprite();

        void SetAnimationFrames(int startFrame, int endFrame, int startLine, int endLine);
        void SetFramePerSecond(int framesPreSecond);

        virtual void Update(float posX, float posY) override;

    private:
        float GetFramesPerSecond() const;
    };
}