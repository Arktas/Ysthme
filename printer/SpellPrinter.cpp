

#include "SpellPrinter.h"

SpellPrinter::SpellPrinter(Data* dataContainer,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,int nbSprite)
{
    spriteTab = (sf::Sprite*)malloc(sizeof(sf::Sprite)*nbSprite);
    if (!texture.loadFromImage(dataContainer->getImage(textureFile.c_str()),sf::IntRect(XTextureBegin, YTextureBegin, XSpriteSize*nbSprite, YSpriteSize))){}
    for(int i=0;i<nbSprite;i++)
    {
        sf::Sprite temp;
        temp.setTexture(texture);
        temp.setTextureRect(sf::IntRect((0+i*XSpriteSize), 0, XSpriteSize, YSpriteSize));
        temp.setOrigin(XSpriteSize/2,YSpriteSize/2);
        spriteTab[i] = temp;
    }
    this->nbSprite = nbSprite;
}

void SpellPrinter::refreshPosition(Spell* spell)
{
    for(int i=0;i<nbSprite;i++)
    {
        spriteTab[i].setRotation(spell->getRotation()+90);
        spriteTab[i].setPosition(sf::Vector2f(spell->getSpellX(),spell->getSpellY()));
    }
}


