#pragma once

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

        int framesPerSecond{1};

        int currentFrame{};
        int currentLine{};

        float framesCounter{};

        bool loop{false};
        bool isPlaying{false};
        
    public:
        SpriteAnimation(SpriteSheet* spriteSheet, float frameWidth, float frameHeight);
        ~SpriteAnimation();

        void FrameUpdate(float frameTime);

        // Starting frame and line start from 1;
        void SetAnimationFrames(int startFrame, int endFrame, int startLine, int endLine, int framesPerSecond = 1);

        void Play();
        void Pause();
        void Stop();

        void SetLooping(bool loop);
        bool IsLooping() const;

        bool IsPlaying() const;
    };
}