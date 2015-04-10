#include "ItemPrinter.h"

ItemPrinter::ItemPrinter(Data* dataContainer,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,int nbSprite)
{
    nameTab[0] = "potion_vie";
    nameTab[1] = "potion_mana";
    nameTab[2] = "bourse_or";
    if (!itemTexture.loadFromImage(dataContainer->getImage("item"),sf::IntRect(XTextureBegin,YTextureBegin,XSpriteSize*nbSprite,XSpriteSize))){}
    for(int i=0;i<nbSprite;i++)
    {
        sf::Sprite temp;
        temp.setTexture(itemTexture);
        temp.setTextureRect(sf::IntRect((0+i*XSpriteSize),0,XSpriteSize,YSpriteSize));
        temp.setOrigin(32,32);
        itemMap[nameTab[i].c_str()] = temp;
    }
}
