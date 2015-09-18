#include "Monster.h"

Monster::Monster(int monsterId,ItemManager* itemManager, Data* dataContainer,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,int x,int y,float agroradius,int life,int attackRange,int nbSprite,int nbSpriteAnim,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC) : Character::Character(dataContainer,textureFile,XTextureBegin,YTextureBegin,XSpriteSize,YSpriteSize,x,y,life,nbSprite,nbSpriteAnim,ORIGIN_DIFF_X_DYNAMIC,ORIGIN_DIFF_Y_DYNAMIC)
{
    //Chargement des paramètres
    std::stringstream ss_mid;
    ss_mid << monsterId;


    this->life = dataContainer->getInfo(ss_mid.str())->getLife();
    this->lifeMax = dataContainer->getInfo(ss_mid.str())->getLife();
    this-> AgroRadius = dataContainer->getInfo(ss_mid.str())->getAgroRange();
    this->attackRange = dataContainer->getInfo(ss_mid.str())->getAttackRange();
    this->canAttack = false;
    this->attackCooldown = dataContainer->getInfo(ss_mid.str())->getAttackCooldown();


    this->clock = new Clock();
    this->clock->start();
    this->moove = false;
    this->get_hit = false;
    indexAnimWalk = 0;
    indexAnim = 6;
    delay = 0;
    spriteIndex = DOWN;
    this->itemManager = itemManager;
    ///////////////////////////
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
}

void Monster::moving(float x,float y)
{
    indexAnim = indexAnimWalk;
    X += x;
    Y += y;
    Xmin = X-Xsize/2+30;
    Ymin = Y-Ysize/2+40;
    Xmax = X+Xsize/2-30;
    Ymax = Y+Ysize/2;
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
}

bool Monster::hitbox(int Xmin_test,int Xmax_test,int Ymin_test,int Ymax_test)
{
     if((Xmin>=Xmin_test && Xmin<=Xmax_test) || (Xmax>=Xmin_test && Xmax<=Xmax_test) || (Xmin_test>=Xmin && Xmin_test<=Xmax) || (Xmax_test>=Xmin && Xmax_test<=Xmax))
     {
        if((Ymin>=Ymin_test && Ymin<=Ymax_test) || (Ymax>=Ymin_test && Ymax<=Ymax_test) || (Ymin_test>=Ymin && Ymin_test<=Ymax) || (Ymax_test>=Ymin && Ymax_test<=Ymax))
        {
            return true;
        }
        else
        {
            return false;
        }
     }
     else
     {
         return false;
     }
}

void Monster::hit(int damage)
{
        life-=damage;
        get_hit = true;
}

bool Monster::alive()
{
    if(life>0)
    {
        return true;
    }
    else
    {
        this->drop();
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
        idle();
        moove = false;
        agro = false;
    }
}

void Monster::setMonsterPosition()
{
}

void Monster::drop()
{
    float rand_x = X;
    float rand_y = Y;
    // DROP
    srand (time(NULL));
    int item = rand() % 4;
    switch(item)
    {
        case 1:
            itemManager->addItem("bourse_or",rand_x,rand_y);
        break;
        case 2:
            itemManager->addItem("potion_mana",rand_x,rand_y);
        break;
        case 3:
            itemManager->addItem("potion_vie",rand_x,rand_y);
        break;
    }
}

