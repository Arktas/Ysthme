#ifndef ITEM_MANAGER
#define ITEM_MANAGER

#include "../misc/util.h"
#include "../resource/Item.h"
#include "../resource/Player.h"

class ItemManager
{
    private:
        float* ORIGIN_DIFF_X_DYNAMIC;
        float* ORIGIN_DIFF_Y_DYNAMIC;
        Player *player;
        std::string nameTab[3];
        sf::Texture itemTexture;
        std::map<std::string,sf::Sprite> itemMap;
        std::list<Item*> itemList;
    public:
        ItemManager(float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC,Data* dataContainer,Player* player);
        ~ItemManager();
        void checkEvent(sf::Event& event,sf::RenderWindow* window);
        void addItem(std::string itemName,float x,float y);
};
#endif
