#include "Inventory.h"

Inventory::Inventory()
{
    XsizeOfInventory = INVENTORY_H;
    YsizeOfInventory = INVENTORY_L;
    inventoryUse = (int*)malloc(sizeof(int)*(YsizeOfInventory*XsizeOfInventory));
    for(int h=0;h<YsizeOfInventory;h++)
    {
        for(int l=0;l<XsizeOfInventory;l++)
        {
            inventoryUse[l+h*XsizeOfInventory] = 0;
        }
    }
}


Inventory::~Inventory()
{
    //free(inventoryUse);
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
        bool assign_itemSlot = false;
        for(int h=0;h<YsizeOfInventory;h++)
        {
            for(int l=0;l<XsizeOfInventory;l++)
            {
                if(inventoryUse[l+h*XsizeOfInventory] == 0)
                {
                     std::cout << "free slot found -> " << l << ":" << h << std::endl;
                    inventoryUse[l+h*XsizeOfInventory] = 1;
                    new_item.x = l;
                    new_item.y = h;
                    assign_itemSlot = true;
                    break;
                }
            }
            if(assign_itemSlot)
                break;
        }
        inventory[name] = new_item;
    }
    std::cout << inventory[name].item->getName() << " add to your inventory stack number(" << (int)inventory[name].item_stack<<")" << " at " << (int)inventory[name].x << ":" << (int)inventory[name].y << std::endl;
}

void Inventory::setNewPositionOnInventory(int x,int y)
{
    if(inventoryUse[y*YsizeOfInventory+x] == 0)
    {
        inventoryUse[itemToMoove->y*XsizeOfInventory+itemToMoove->x] = 0;
        itemToMoove->x = x;
        itemToMoove->y = y;
        inventoryUse[y*YsizeOfInventory+x] = 1;
    }
}

 std::map<std::string,item_inventory>* Inventory::getInventory()
{
    return &inventory;
}

void Inventory::saveThisItemSlot(item_inventory *itemToSave)
{
    this->itemToMoove = itemToSave;
}

