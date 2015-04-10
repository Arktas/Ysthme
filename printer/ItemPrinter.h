#ifndef ITEM_PRINTER
#define ITEM_PRINTER

#include "../misc/util.h"
#include "../resource/Item.h"
#include "../resource/Data.h"

class ItemPrinter
{
    private:
        std::string nameTab[3];
        sf::Texture itemTexture;
        std::map<std::string,sf::Sprite> itemMap;

    public:
        ItemPrinter(Data* dataContainer,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,int nbSprite);
        ~ItemPrinter();
        void refreshPosition(Item* item){(itemMap[item->getName()]).setPosition(sf::Vector2f(item->getItemX(),item->getItemY()));}
        sf::Sprite getItemSprite(Item* item){refreshPosition(item);return (itemMap[item->getName()]);};
};

#endif

