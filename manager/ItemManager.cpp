#include "ItemManager.h"

ItemManager::ItemManager(Hitbox* _INST_hitbox, float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC,Data* dataContainer,std::list<Item*> *itemList,Player* player,Inventory* inventory, _MANAGER_Flags *flags)
{
    this->itemList = itemList;
    this->player = player;
    this->inventory = inventory;
    this->ORIGIN_DIFF_X_DYNAMIC = ORIGIN_DIFF_X_DYNAMIC;
    this->ORIGIN_DIFF_Y_DYNAMIC = ORIGIN_DIFF_Y_DYNAMIC;
    this->itemPrinter = new ItemPrinter(dataContainer,"item",0,0,64,64,3);
    this->_INST_hitbox = _INST_hitbox;
    this->flags = flags;

}

ItemManager::~ItemManager()
{

}

void ItemManager::checkEvent(sf::Event& event,sf::RenderWindow* window)
{

    /////////    MAJ des item dans l'inventaire et sur la map ///////////////////////////
    std::list<Item*>::iterator it;

     for(it=itemList->begin();it!=itemList->end();it++)
    {
        if(player->hitbox((*it)->getXmin(),(*it)->getXmax(),(*it)->getYmin(),(*it)->getYmax()))
        {
                inventory->addItemToInventory((*it));
                std::list<Item*>::iterator iterase = it;
                it--;
                itemList->erase(iterase);
                this->flags->drop = true;
        }
        else
        {
            if(SHOW_HITBOX)
            {
                sf::RectangleShape hitbox(sf::Vector2f(((*it)->getXmax()-(*it)->getXmin()),((*it)->getYmax()-(*it)->getYmin())));
                hitbox.setFillColor(sf::Color(250,0,0));
                hitbox.setOrigin(((*it)->getXmax()-(*it)->getXmin())/2,((*it)->getYmax()-(*it)->getYmin())/2);
                hitbox.setPosition((*it)->getItemX(),(*it)->getItemY());
                window->draw(hitbox);
            }
           window->draw(itemPrinter->getItemSprite((*it)));
        }
    }
    ///////////////////    FIN MAJ ////////////////////////////////

    ///////////////////  Boucle sur les evenements ////////////////
    if(event.type == sf::Event::KeyPressed && event.key.code==sf::Keyboard::I) // affichage du menu d'inventaire
    {

    }



}

void ItemManager::addItem(std::string itemName,float x,float y)
{
    itemList->push_front(new Item(x,y,itemName,ORIGIN_DIFF_X_DYNAMIC,ORIGIN_DIFF_Y_DYNAMIC,64,64));
}

void ItemManager::useItem(char* itemName)
{
    if(!strcmp(itemName,"potion_vie"))
    {
        player->addLife(10);
    }
}
