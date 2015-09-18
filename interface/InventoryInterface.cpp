#include "InventoryInterface.h"

InventoryInterface::InventoryInterface(Data* data)
{
    if (!itemTexture.loadFromImage(dataContainer->getImage("slot_HUD"),sf::IntRect(0,0,68,68))){}

    inventorySize = 10;
    this->data = data;
    hud_x = 300;
    hud_y = 150;
}

InventoryInterface::~InventoryInterface()
{
}

InventoryInterface::display
{
    for(int i = 0;i<inventorySize;i++)
    {

    }
}
