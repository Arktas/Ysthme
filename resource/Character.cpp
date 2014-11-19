#include "Character.h"

Character::Character(Data* dataContainer,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,int x,int y,int life,int nbSprite,int nbSpriteAnim,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC)
{
        spriteTab = (sf::Sprite*)malloc(sizeof(sf::Sprite)*nbSprite*nbSpriteAnim);
    if (!texture.loadFromImage(dataContainer->getImage(textureFile.c_str()),sf::IntRect(XTextureBegin, YTextureBegin, XSpriteSize*nbSpriteAnim, YSpriteSize*nbSprite))){}
    for(int i=0;i<nbSprite;i++)
    {
        for(int j=0;j<nbSpriteAnim;j++)
        {
            sf::Sprite temp;
            temp.setTexture(texture);
            temp.setTextureRect(sf::IntRect((XTextureBegin+j*XSpriteSize), (YTextureBegin+i*YSpriteSize), XSpriteSize, YSpriteSize));
            temp.setOrigin(45,70);
            temp.setRotation(0);
            spriteTab[(i*nbSpriteAnim)+j] = temp;
        }
    }
    this->nbSprite = nbSprite;
    this->nbSpriteAnim = nbSpriteAnim;
    maxIndex = 0;
    spriteIndex = 0;
    X = x+45;
    Y = y+70;
    Xmin = x;
    Ymin = y;
    Xmax = x+XSpriteSize;
    Ymax = y+YSpriteSize;
    this->ORIGIN_DIFF_X_DYNAMIC=ORIGIN_DIFF_X_DYNAMIC;
    this->ORIGIN_DIFF_Y_DYNAMIC=ORIGIN_DIFF_Y_DYNAMIC;
    for(int i=0;i<nbSprite;i++)
    {
        spriteTab[i].setPosition(sf::Vector2f(X,Y));
    }
    this->life = life;
}

Character::~Character()
{
}
