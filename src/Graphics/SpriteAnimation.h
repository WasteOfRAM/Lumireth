#pragma once

#include "SpriteSheet.h"
#include "Sprite.h"

namespace Lumireth
{
    class SpriteAnimation : public Sprite
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
        SpriteAnimation(const SpriteSheet& spriteSheet, int startFrame, int endFrame, int startLine, int endLine, int framesPreSecond);
        ~SpriteAnimation();

        void SetAnimationFrames(int startFrame, int endFrame, int startLine, int endLine);
        void SetFramePerSecond(int framesPreSecond);

        virtual void Update(float posX, float posY, float frameTime) override;
        virtual void Render(Color tint) override;

    private:
        float GetFramesPerSecond() const;
    };
}