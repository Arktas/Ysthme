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
        std::list<Item*> *itemList;
        ItemPrinter *itemPrinter;
        Hitbox* _INST_hitbox;
        _MANAGER_Flags *flags;

    public:
        ItemManager(Hitbox* _INST_hitbox, float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC,Data* dataContainer,std::list<Item*> *itemList,Player* player,Inventory* inventory, _MANAGER_Flags *flags);
        ~ItemManager();
        void checkEvent(sf::Event& event,sf::RenderWindow* window);
        void addItem(std::string itemName,float x,float y);
        void useItem(char* itemName);
};
#endif
