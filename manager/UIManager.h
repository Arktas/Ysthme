#ifndef UI_MANAGER
#define UI_MANAGER

#include "../misc/util.h"
#include "../resource/Data.h"
#include "../resource/Player.h"
#include "../resource/Inventory.h"
#include "../interface/PlayerInterface.h"
#include "../interface/MonsterInterface.h"
#include "../interface/BasicInterface.h"
#include "MainManager.h"

class UIManager
{
    private:
        float* ORIGIN_DIFF_X_DYNAMIC;
        float* ORIGIN_DIFF_Y_DYNAMIC;
        ItemPrinter *itemPrinter;
        Data* dataContainer;
        Player* player;
        PlayerInterface *playerInterface;
        MonsterInterface *monsterInterface;
        BasicInterface *basicInterface;
        std::list<Item*> *itemList;
        Inventory *inventory;
        std::list<Monster*> *monsterList;
        _MANAGER_Flags *flags;
        std::list<sf::Sprite> inventoryInterfaceSpriteSave;
        std::list<sf::Text> inventoryInterfaceTextSave;


    public:
        UIManager(Data* dataContainer,std::list<Item*> *itemList,Inventory *inventory,std::list<Monster*> *monsterList,Player* player,_MANAGER_Flags *flags,float* ORIGIN_DIFF_X_DYNAMIC,float *ORIGIN_DIFF_Y_DYNAMIC);
        ~UIManager();
        void checkEvent(sf::Event& event,sf::RenderWindow* window,MainManager* mainManager);
        void showInventory(sf::RenderWindow* window);
};

#endif

