#include "Data.h"

Data::Data()
{
}

Data::~Data()
{
}

void Data::load(std::string xmlResourceFile)
{
    sf::Image img;

    //Monster
    if (!img.loadFromFile("data/orks.png")){}
    dataResourceMap["zombie"] = img;

    //player
    if (!img.loadFromFile("data/Wizard.png")){}
    dataResourceMap["player"] = img;

    //spell
    if (!img.loadFromFile("data/Fireball.png")){}
    dataResourceMap["fireball"] = img;

    //environment
    if (!img.loadFromFile("data/Grass.png")){}
    dataResourceMap["grass"] = img;

    //item
    if (!img.loadFromFile("data/Items.png")){}
    dataResourceMap["item"] = img;

    //interface
    if (!img.loadFromFile("data/LifeBar.png")){}
    dataResourceMap["lifebar_big"] = img;
    if (!img.loadFromFile("data/case.png")){}
    dataResourceMap["case"] = img;
    if (!img.loadFromFile("data/Heart.png")){}
    dataResourceMap["heart"] = img;

}

MonsterParser* Data::getInfo(std::string id)
{
    MonsterParser *mp = new MonsterParser();
    std::stringstream ss;
    ss << "data/properties/ID_" << id << ".xml";
    mp->parse(ss.str());
    return mp;
}
