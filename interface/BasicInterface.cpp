#include "BasicInterface.h"


BasicInterface::BasicInterface(Data* dataContainer)
{
    this->dataContainer = dataContainer;
    this->nbItemFont.loadFromFile("data/font/arial.ttf");
    this->nbItemText.setFont(this->nbItemFont);
    this->nbItemText.setColor(sf::Color::Red);
    this->nbItemText.setCharacterSize(12);
    this->nbItemText.setStyle(sf::Text::Bold);
}

BasicInterface::~BasicInterface()
{
}

sf::Sprite BasicInterface::displayInventorySlot(float X,float Y)
{
    if (!texture.loadFromImage(dataContainer->getImage("case"),sf::IntRect(0, 0, 68, 68))){}
    InventorySlot.setTexture(texture);
    InventorySlot.setPosition(X,Y);
    return InventorySlot;
}

sf::Text BasicInterface::displayNbItem(int x, int y,int nb)
{
    std::stringstream ss;
    ss << nb;
    this->nbItemText.setString(ss.str());
    this->nbItemText.setPosition(x,y);
    return this->nbItemText;
}
