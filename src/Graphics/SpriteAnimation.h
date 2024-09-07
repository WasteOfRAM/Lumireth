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

        bool loop{false};
        bool isPlaying{false};

    public:
        SpriteAnimation(const SpriteSheet& spriteSheet, int startFrame, int endFrame, int startLine, int endLine, int framesPreSecond);
        ~SpriteAnimation();

        void SetAnimationFrames(int startFrame, int endFrame, int startLine, int endLine);
        void SetFramePerSecond(int framesPreSecond);

        virtual void Update(float posX, float posY, float frameTime) override;

        void Play();
        void Pause();
        void Stop();

        void SetLooping(bool loop);
        bool IsLooping() const;

        bool IsPlaying() const;

    private:
        float GetFramesPerSecond() const;
    };
}