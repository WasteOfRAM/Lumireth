#include "SpriteImage.h"

Lumireth::SpriteImage::SpriteImage(const SpriteSheet& spriteSheet, int tileColumn, int tileRow)
    : Sprite(spriteSheet)
{
    this->spriteWidth = spriteSheet.GetTexture().width / spriteSheet.GetTileColumnsCount();
    this->spriteHeight = spriteSheet.GetTexture().height / spriteSheet.GetTileRowsCount();
    this->spriteSource = {this->spriteWidth * tileColumn, this->spriteHeight * tileRow, this->spriteWidth, this->spriteHeight};
    this->dest = {0.f, 0.f, this->spriteWidth * this->scale, this->spriteHeight * this->scale};
}

Lumireth::SpriteImage::~SpriteImage()
{
}

void Lumireth::SpriteImage::Update(float posX, float posY, float frameTime)
{
    this->spriteSource.width = this->spriteWidth * this->orientation.y;
    this->spriteSource.height = this->spriteHeight * this->orientation.x;

    this->dest = Rectangle{posX, posY, this->spriteWidth * scale, this->spriteHeight * scale};
}