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
    if (!img.loadFromFile("data/orks.png")){}
    dataResourceMap["zombie"] = img;
    if (!img.loadFromFile("data/Wizard.png")){}
    dataResourceMap["player"] = img;
    if (!img.loadFromFile("data/Fireball.png")){}
    dataResourceMap["fireball"] = img;
    if (!img.loadFromFile("data/Grass.png")){}
    dataResourceMap["grass"] = img;
     if (!img.loadFromFile("data/Items.png")){}
    dataResourceMap["item"] = img;

}

