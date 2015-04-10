
#ifndef INVENTORY
#define INVENTORY

#include "../misc/util.h"
#include "Item.h"

typedef struct item_inventory{
Item* item;
unsigned char item_stack;
}item_inventory;


class Inventory
{
    private :
        std::map<std::string,item_inventory> inventory;
    public :
        //constructor and destructor
        Inventory();
        ~Inventory();

        //context functions
        void addItemToInventory(Item* item);

        //getters and setters

};

#endif
