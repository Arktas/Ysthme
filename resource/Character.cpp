#include "Character.h"

Character::Character(Data* dataContainer,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,int x,int y,int life,int nbSprite,int nbSpriteAnim,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC)
{
    this->nbSprite = nbSprite;
    this->nbSpriteAnim = nbSpriteAnim;
    maxIndex = 0;
    spriteIndex = 0;
    X = x;
    Y = y;
    Xmin = x-XSpriteSize/2+30;
    Ymin = y-YSpriteSize/2+40;
    Xmax = x+XSpriteSize/2-30;
    Ymax = y+YSpriteSize/2;
    Xsize=XSpriteSize;
    Ysize=YSpriteSize;
    this->ORIGIN_DIFF_X_DYNAMIC=ORIGIN_DIFF_X_DYNAMIC;
    this->ORIGIN_DIFF_Y_DYNAMIC=ORIGIN_DIFF_Y_DYNAMIC;
    this->life = life;
}

Character::~Character()
{
}
