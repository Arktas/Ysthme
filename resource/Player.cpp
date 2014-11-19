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
    for(int i=0;i<nbSpriteAnim*nbSprite;i++)
    {
        spriteTab[i].setPosition(sf::Vector2f((*ORIGIN_DIFF_X_DYNAMIC)-X,(*ORIGIN_DIFF_Y_DYNAMIC)-Y));
    }
}

Player::~Player()
{
    free(spriteTab);
}

void Player::doRotation(int angle)
{
    rotation = angle;
    /*for(int i=0;i<nbSprite;i++)
    {
        spriteTab[i].setRotation(angle);
    }*/
}


void Player::changeTexture(int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize)
{
    spriteTab[0].setTextureRect(sf::IntRect(XTextureBegin, YTextureBegin, XSpriteSize, YSpriteSize));
}

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
    else if(rotation>158)
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
    for(int i=0;i<6*nbSprite;i++)
    {
        spriteTab[i].setPosition(sf::Vector2f((*ORIGIN_DIFF_X_DYNAMIC)-X,(*ORIGIN_DIFF_Y_DYNAMIC)-Y));
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


bool Player::hit(int x,int y,int damage)
{
    float spellPlayerDistance = sqrt(pow((x+X),2.0) + pow((y+Y),2.0));
    if(spellPlayerDistance<50)
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

void Player::addItemToInventory(Item* item)
{
    std::string name = item->getName();
    if(inventory.count(name))
    {
        inventory[name].item_stack++;
    }
    else
    {
        item_inventory new_item;
        new_item.item = item;
        new_item.item_stack = 1;
        inventory[name] = new_item;
    }
    std::cout << inventory[name].item->getName() << " add to your inventory stack number(" << (int)inventory[name].item_stack<<")" << std::endl;
}
