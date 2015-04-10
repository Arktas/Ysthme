#include "Player.h"

Player::Player(Data* dataContainer,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,int x,int y,int life,int nbSprite,int nbSpriteAnim,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC) : Character(dataContainer,textureFile,XTextureBegin,YTextureBegin,XSpriteSize,YSpriteSize,x,y,life,nbSprite,nbSpriteAnim,ORIGIN_DIFF_X_DYNAMIC,ORIGIN_DIFF_Y_DYNAMIC)
{
    state = PLAYER_PASSIVE;
    spriteIndex = DOWN;
    indexAnimWalk = 0;
    indexAnimIdle = 6;
    indexAnimSpell = 9;
    indexAnim = indexAnimIdle;
    delay = 0;
}

Player::~Player()
{
}

void Player::doRotation(int angle)
{
    rotation = angle;
    /*for(int i=0;i<nbSprite;i++)
    {
        spriteTab[i].setRotation(angle);
    }*/
}


/*void Player::changeTexture(int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize)
{
    spriteTab[0].setTextureRect(sf::IntRect(XTextureBegin, YTextureBegin, XSpriteSize, YSpriteSize));
}*/

void Player::cast()
{
    if(rotation>(-22) && rotation<23)
        spriteIndex = RIGHT;
    else if(rotation>23 && rotation<68)
        spriteIndex = DOWN_RIGHT;
    else if(rotation>68 && rotation<113)
        spriteIndex = DOWN;
    else if(rotation>113 && rotation<158)
        spriteIndex = DOWN_LEFT;
    else if(rotation>158 || rotation<(-157))
        spriteIndex = LEFT;
    else if(rotation>(-157) && rotation<(-112))
        spriteIndex = UP_LEFT;
    else if(rotation>(-112) && rotation<(-67))
        spriteIndex = UP;
    else if(rotation>(-67) && rotation<(-22))
        spriteIndex = UP_RIGHT;
    indexAnim = 9;
}

void Player::moving(float x,float y)
{
    indexAnim = indexAnimWalk;
    X += x;
    Y += y;
    *ORIGIN_DIFF_X_DYNAMIC += x;
    *ORIGIN_DIFF_Y_DYNAMIC += y;
    delay++;
    if(delay>5)
    {
        delay=0;
        if(indexAnimWalk<(5))
            indexAnimWalk++;
        else
            indexAnimWalk=0;
    }

}


bool Player::hit(int x,int y,int damage)
{

    float spellPlayerDistance = sqrt(pow((x+X),2.0) + pow((y+Y),2.0));
    if((-x)>(X-Xsize/2) && (-x)<(X+Xsize/2) && (-y)>(Y-Ysize/2) && (-y)<(Y+Ysize/2))
    {
        life-=damage;
        return true;
    }
    else{return false;}
}

bool Player::alive()
{
    if(life>0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
