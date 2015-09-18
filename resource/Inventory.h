
#ifndef INVENTORY
#define INVENTORY

#include "../misc/util.h"
#include "Item.h"

typedef struct item_inventory{
    Item* item;
    unsigned char item_stack;
    int x;
    int y;
}item_inventory;


class Inventory
{
    private :
        int* inventoryUse;
        int XsizeOfInventory,YsizeOfInventory;
        std::map<std::string,item_inventory> inventory;
        item_inventory *itemToMoove;
    public :
        //constructor and destructor
        Inventory();
        ~Inventory();

        //context functions
        void addItemToInventory(Item* item);
        std::map<std::string,item_inventory>* getInventory();
        void setNewPositionOnInventory(int x,int y);
        void saveThisItemSlot(item_inventory *itemToSave);
        //getters and setters

};

#endif
