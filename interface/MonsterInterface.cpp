#include "MonsterInterface.h"


MonsterInterface::MonsterInterface()
{
    monsterFont.loadFromFile("data/font/arial.ttf");
    monsterLife.setFont(monsterFont);
    monsterLife.setColor(sf::Color::Red);
    monsterLife.setCharacterSize(12);
    monsterLife.setStyle(sf::Text::Bold);
}

MonsterInterface::~MonsterInterface()
{
}

sf::Text MonsterInterface::display(int life,float X,float Y)
{
    std::stringstream ss;
    ss << "(" << life << "/10)";
    monsterLife.setString(ss.str());
    monsterLife.setPosition(X,Y);
    return monsterLife;
}
