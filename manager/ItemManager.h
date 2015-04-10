#ifndef ITEM_MANAGER
#define ITEM_MANAGER

#include "../misc/util.h"
#include "../resource/Item.h"
#include "../resource/Player.h"
#include "../resource/Inventory.h"
#include "../printer/ItemPrinter.h"

class ItemManager
{
    private:
        float* ORIGIN_DIFF_X_DYNAMIC;
        float* ORIGIN_DIFF_Y_DYNAMIC;
        Player *player;
        Inventory *inventory;
        std::list<Item*> itemList;
        ItemPrinter *itemPrinter;

    public:
        ItemManager(float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC,Data* dataContainer,Player* player,Inventory* inventory);
        ~ItemManager();
        void checkEvent(sf::Event& event,sf::RenderWindow* window);
        void addItem(std::string itemName,float x,float y);
};
#endif
