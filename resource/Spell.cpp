#include "Spell.h"

Spell::Spell(Data *dataContainer,int nbSprite,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,float mX,float mY,float bX,float bY,int rotation,int damage,int source,int speed,int range,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC)
{
    maxIndex = nbSprite-1;
    spriteIndex = 0;
    delay = 5;
    moveX = mX;
    moveY = mY;
    this->rotation = rotation;
    this->ORIGIN_DIFF_X_DYNAMIC = ORIGIN_DIFF_X_DYNAMIC;
    this->ORIGIN_DIFF_Y_DYNAMIC = ORIGIN_DIFF_Y_DYNAMIC;
    X = bX-(*ORIGIN_DIFF_X_DYNAMIC);
    Y = bY-(*ORIGIN_DIFF_Y_DYNAMIC);
    Xmin = X-(XSpriteSize/2-3);
    Ymin = Y-(YSpriteSize/2-8);
    Xmax = X+(XSpriteSize/2-3);
    Ymax = Y+(YSpriteSize/2-8);
    Xsize = XSpriteSize;
    Ysize = YSpriteSize;
    this->damage = damage;
    this->source = source;
    this->speed = speed;
    this->range = range;
}

Spell::~Spell()
{
}

void Spell::moving()
{
    delay--;
    if(delay<=0)
    {
        delay = 5;
        spriteIndex++;
        if(spriteIndex>maxIndex)
        {
            spriteIndex = 0;
        }
    }
    X+= moveX*speed;
    Y+= moveY*speed;
    Xmin = X-(Xsize/2-3);
    Ymin = Y-(Ysize/2-8);
    Xmax = X+(Xsize/2-3);
    Ymax = Y+(Ysize/2-8);
    range -= round(sqrt(pow((moveX*speed),2)+pow((moveY*speed),2)));
    //std::cout << Xmax <<" : "<<Ymax << " | " << Xmin <<" : "<<Ymin << std::endl;
}
