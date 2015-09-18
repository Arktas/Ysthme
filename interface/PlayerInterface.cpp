
#include "PlayerInterface.h"


PlayerInterface::PlayerInterface(Data* dataContainer)
{
    playerFont.loadFromFile("data/font/arial.ttf");
    playerLife.setFont(playerFont);
    playerLife.setColor(sf::Color::Red);
    playerLife.setCharacterSize(20);
    playerLife.setStyle(sf::Text::Bold);
    this->dataContainer = dataContainer;
}

PlayerInterface::~PlayerInterface()
{
}

sf::Sprite PlayerInterface::display_lifeBar_big(int life,float X,float Y)
{
    if (!texture.loadFromImage(dataContainer->getImage("lifebar_big"),sf::IntRect(0, 0, 340, 68))){}
    lifebar_big_sprite.setTexture(texture);
    lifebar_big_sprite.setPosition(X,Y);
    return lifebar_big_sprite;
}

sf::Sprite PlayerInterface::display_spellbar_down(float X,float Y)
{
    if (!texture.loadFromImage(dataContainer->getImage("case"),sf::IntRect(0, 0, 68, 68))){}
    spellBar_down_sprite.setTexture(texture);
    spellBar_down_sprite.setPosition(X,Y);
    return spellBar_down_sprite;
}

sf::Sprite PlayerInterface::display_heart(float X,float Y)
{
    if (!texture.loadFromImage(dataContainer->getImage("heart"),sf::IntRect(0, 0, 34, 34))){}
    heart_sprite.setTexture(texture);
    heart_sprite.setPosition(X,Y);
    return heart_sprite;
}

sf::Text PlayerInterface::display_lifeText(int life,float X,float Y)
{
    std::stringstream ss;
    ss << "LIFE : " << life << "/100";
    playerLife.setString(ss.str());
    playerLife.setPosition(X,Y);
    return playerLife;
}
