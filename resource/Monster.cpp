#include "Monster.h"

Monster::Monster(ItemManager* itemManager, Data* dataContainer,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,int x,int y,float agroradius,int life,int attackRange,int nbSprite,int nbSpriteAnim,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC) : Character::Character(dataContainer,textureFile,XTextureBegin,YTextureBegin,XSpriteSize,YSpriteSize,x,y,life,nbSprite,nbSpriteAnim,ORIGIN_DIFF_X_DYNAMIC,ORIGIN_DIFF_Y_DYNAMIC)
{
    Xsize = XSpriteSize;
    Ysize = YSpriteSize;
    this->attackRange = attackRange;
    this->canAttack = false;
    this->attackCooldown = 1000;
    this->clock = new Clock();
    this->clock->start();
    this-> AgroRadius = agroradius;
    this->moove = false;
    this->get_hit = false;
    indexAnimWalk = 0;
    indexAnim = 6;
    delay = 0;
    spriteIndex = DOWN;
    for(int i=0;i<nbSpriteAnim*nbSprite;i++)
    {
        spriteTab[i].setPosition(sf::Vector2f((*ORIGIN_DIFF_X_DYNAMIC)+X,(*ORIGIN_DIFF_Y_DYNAMIC)+Y));
    }
    this->itemManager = itemManager;
}

void Monster::doRotation(int angle)
{
    rotation = angle;
    if(rotation>(-22) && rotation<23)
        spriteIndex = RIGHT;
    else if(rotation>23 && rotation<68)
        spriteIndex = DOWN_RIGHT;
    else if(rotation>68 && rotation<113)
        spriteIndex = DOWN;
    else if(rotation>113 && rotation<158)
        spriteIndex = DOWN_LEFT;
    else if(rotation>158)
        spriteIndex = LEFT;
    else if(rotation>(-157) && rotation<(-112))
        spriteIndex = UP_LEFT;
    else if(rotation>(-112) && rotation<(-67))
        spriteIndex = UP;
    else if(rotation>(-67) && rotation<(-22))
        spriteIndex = UP_RIGHT;

    //spriteTab[0].setRotation(angle);
}

void Monster::changeTexture(int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize)
{
    spriteTab[0].setTextureRect(sf::IntRect(XTextureBegin, YTextureBegin, XSpriteSize, YSpriteSize));
}

void Monster::moving(float x,float y)
{
    indexAnim = indexAnimWalk;
    X += x;
    Y += y;
    Xmin = X;
    Ymin = Y;
    Xmax =X+Xsize;
    Ymax =Y+Ysize;
     for(int i=0;i<nbSpriteAnim*nbSprite;i++)
    {
        spriteTab[i].setPosition(sf::Vector2f((*ORIGIN_DIFF_X_DYNAMIC)+X,(*ORIGIN_DIFF_Y_DYNAMIC)+Y));
    }
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


Monster::~Monster()
{
    free(spriteTab);
}

bool Monster::hit(int x,int y,int damage)
{
    float spellMonsterDistance = sqrt(pow((x - X),2.0) + pow((y-Y),2.0));
    if(spellMonsterDistance<50)
    {
        life-=damage;
        get_hit = true;
        return true;
    }
    else{return false;}
}

bool Monster::alive()
{
    if(life>0)
    {
        return true;
    }
    else
    {
        float rand_x = X;
        float rand_y = Y;
        itemManager->addItem("bourse_or",rand_x,rand_y);
        return false;
    }
}

void Monster::agroChange(int pX,int pY)
{
    float playerMonsterDistance = sqrt(pow((pX - ((*ORIGIN_DIFF_X_DYNAMIC)+X)),2.0) + pow((pY-((*ORIGIN_DIFF_Y_DYNAMIC)+Y)),2.0));
    if(playerMonsterDistance<AgroRadius || get_hit)
    {
        agro = true;
        if(playerMonsterDistance>attackRange)
        {
            moove = true;
            canAttack = false;
        }
        else
        {
            moove = false;
            this->clock->stop();
            if(((int)(this->clock->difftime()))>attackCooldown)
            {
                this->clock->start();
                canAttack = true;
            }
            else
            {
                canAttack = false;
            }
        }
    }
    else
    {
        moove = false;
        agro = false;
    }
}

void Monster::setMonsterPosition()
{
    for(int i=0;i<nbSpriteAnim*nbSprite;i++)
    {
        spriteTab[i].setPosition(sf::Vector2f((*ORIGIN_DIFF_X_DYNAMIC)+X,(*ORIGIN_DIFF_Y_DYNAMIC)+Y));
    }
}
