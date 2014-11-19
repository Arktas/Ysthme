#include "ItemManager.h"

ItemManager::ItemManager(float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC,Data* dataContainer,Player* player)
{
    this->player = player;
    this->ORIGIN_DIFF_X_DYNAMIC = ORIGIN_DIFF_X_DYNAMIC;
    this->ORIGIN_DIFF_Y_DYNAMIC = ORIGIN_DIFF_Y_DYNAMIC;
    nameTab[0] = "potion_vie";
    nameTab[1] = "potion_mana";
    nameTab[2] = "bourse_or";
    if (!itemTexture.loadFromImage(dataContainer->getImage("item"),sf::IntRect(0,0,384,384))){}
    for(int i=0;i<3;i++)
    {
        sf::Sprite temp;
        temp.setTexture(itemTexture);
        temp.setTextureRect(sf::IntRect((0+i*64),0,64,64));
        temp.setOrigin(32,32);
        itemMap[nameTab[i].c_str()] = temp;
    }
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
                player->addItemToInventory(itemTemp);
           // }
        }
        else
        {
           window->draw(itemTemp->display(ORIGIN_DIFF_X_DYNAMIC,ORIGIN_DIFF_Y_DYNAMIC));
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
    itemList.push_front(new Item(&(itemMap[itemName.c_str()]),x,y,itemName));
}
