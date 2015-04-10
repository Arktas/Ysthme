#include "Inventory.h"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::addItemToInventory(Item* item)
{
    std::string name = item->getName();
    if(inventory.count(name))
    {
        inventory[name].item_stack++;
    }
    else
    {
        item_inventory new_item;
        new_item.item = item;
        new_item.item_stack = 1;
        inventory[name] = new_item;
    }
    std::cout << inventory[name].item->getName() << " add to your inventory stack number(" << (int)inventory[name].item_stack<<")" << std::endl;
}

