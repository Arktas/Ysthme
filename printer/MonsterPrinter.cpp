
#include "MonsterPrinter.h"

MonsterPrinter::MonsterPrinter(Data* dataContainer,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,int nbSprite,int nbSpriteAnim)
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
}

void MonsterPrinter::refreshPosition(Monster* monster)
{
    for(int i=0;i<nbSpriteAnim*nbSprite;i++)
    {
        spriteTab[i].setPosition(sf::Vector2f(monster->getMonsterX(),monster->getMonsterY()));
    }
}


