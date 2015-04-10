#include "Character.h"

Character::Character(Data* dataContainer,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,int x,int y,int life,int nbSprite,int nbSpriteAnim,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC)
{
    this->nbSprite = nbSprite;
    this->nbSpriteAnim = nbSpriteAnim;
    maxIndex = 0;
    spriteIndex = 0;
    X = x;
    Y = y;
    Xmin = x;
    Ymin = y;
    Xmax = x+XSpriteSize;
    Ymax = y+YSpriteSize;
    Xsize=XSpriteSize;
    Ysize=YSpriteSize;
    this->ORIGIN_DIFF_X_DYNAMIC=ORIGIN_DIFF_X_DYNAMIC;
    this->ORIGIN_DIFF_Y_DYNAMIC=ORIGIN_DIFF_Y_DYNAMIC;
    this->life = life;
}

Character::~Character()
{
}
