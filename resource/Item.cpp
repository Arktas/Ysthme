#include "Item.h"

Item::Item(sf::Sprite *itemData,float x,float y,std::string name)
{
    this->name = name;
    this->itemData = itemData;
    this->X = x;
    this->Y = y;
    itemData->setPosition(sf::Vector2f(X,Y));
}

Item::~Item()
{
}
