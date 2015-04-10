#include "ItemManager.h"

ItemManager::ItemManager(float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC,Data* dataContainer,Player* player,Inventory* inventory)
{
    this->player = player;
    this->inventory = inventory;
    this->ORIGIN_DIFF_X_DYNAMIC = ORIGIN_DIFF_X_DYNAMIC;
    this->ORIGIN_DIFF_Y_DYNAMIC = ORIGIN_DIFF_Y_DYNAMIC;
    this->itemPrinter = new ItemPrinter(dataContainer,"item",0,0,64,64,3);

}

ItemManager::~ItemManager()
{

}

void ItemManager::checkEvent(sf::Event& event,sf::RenderWindow* window)
{
    std::list<Item*> itemListTemp;

    while(!itemList.empty())
    {
        Item* itemTemp = itemList.back();
        //std::cout << "plaxer Y : "<< player->getPlayerRealY() << " compare to " << ((-(itemTemp->getItemRealY())-2)) << " | " << ((-(itemTemp->getItemRealY()))+2) << std::endl;
        if(player->getPlayerRealX()>((-(itemTemp->getItemRealX())-32)) && player->getPlayerRealX()<((-(itemTemp->getItemRealX())+32)) && player->getPlayerRealY()>((-(itemTemp->getItemRealY())-32)) && player->getPlayerRealY()<((-(itemTemp->getItemRealY()))+32))
        {
          //  if()
           // {
                inventory->addItemToInventory(itemTemp);
           // }
        }
        else
        {
           window->draw(itemPrinter->getItemSprite(itemTemp));
           itemListTemp.push_front(itemTemp);
        }
        itemList.pop_back();
    }
    while(!itemListTemp.empty())
    {
        itemList.push_front(itemListTemp.back());
         itemListTemp.pop_back();
    }
}

void ItemManager::addItem(std::string itemName,float x,float y)
{
    itemList.push_front(new Item(x,y,itemName,ORIGIN_DIFF_X_DYNAMIC,ORIGIN_DIFF_Y_DYNAMIC));
}
