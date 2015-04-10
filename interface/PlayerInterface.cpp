
#include "PlayerInterface.h"


PlayerInterface::PlayerInterface()
{
    playerFont.loadFromFile("data/font/arial.ttf");
    playerLife.setFont(playerFont);
    playerLife.setColor(sf::Color::Red);
    playerLife.setCharacterSize(20);
    playerLife.setStyle(sf::Text::Bold);
}

PlayerInterface::~PlayerInterface()
{
}

sf::Text PlayerInterface::display(int life,float X,float Y)
{
    std::stringstream ss;
    ss << "LIFE : " << life << "/100";
    playerLife.setString(ss.str());
    playerLife.setPosition(X,Y);
    return playerLife;
}
