#include "UIManager.h"


UIManager::UIManager(ItemManager* itemManager,Data* dataContainer,std::list<Item*> *itemList,Inventory *inventory,std::list<Monster*> *monsterList,Player* player,_MANAGER_Flags *flags,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC)
{
    this->dataContainer = dataContainer;
    this->player = player;
    this->ORIGIN_DIFF_X_DYNAMIC = ORIGIN_DIFF_X_DYNAMIC;
    this->ORIGIN_DIFF_Y_DYNAMIC = ORIGIN_DIFF_Y_DYNAMIC;
    this->playerInterface = new PlayerInterface(dataContainer);
    this->basicInterface = new BasicInterface(dataContainer);
    this->inventory = inventory;
    this->itemList = itemList;
    this->monsterList = monsterList;
    this->flags = flags;
    this->itemPrinter = new ItemPrinter(dataContainer,"item",0,0,64,64,3);
    this->itemManager = itemManager;
}
UIManager::~UIManager()
{
}

void UIManager::checkEvent(sf::Event& event,sf::RenderWindow* window,MainManager* mainManager)
{
            ///////////////////  Boucle sur les evenements ////////////////
    if(event.type == sf::Event::KeyPressed && event.key.code==sf::Keyboard::Escape)
    {
        mainManager->quit();
    }
    if(event.type == sf::Event::KeyPressed && event.key.code==sf::Keyboard::I)
    {
        if(this->flags->inventoryShowed)
        {
            this->flags->inventoryShowed = false;
            this->flags->interfaceON = false;
        }
        else
        {
            this->flags->inventoryShowed = true;
            this->flags->interfaceON = true;
            this->flags->updateInventoryInterface = true;
        }

    }
    if(this->flags->inventoryShowed)
    {
        if(this->flags->updateInventoryInterface || this->flags->drop)
        {
            this->showInventory(window);
            this->flags->drop = false;
            this->flags->updateInventoryInterface = false;
        }
        std::list<sf::Sprite>::iterator it_sprite;
        for(it_sprite=inventoryInterfaceSpriteSave.begin();it_sprite!=inventoryInterfaceSpriteSave.end();it_sprite++)
        {
            window->draw(*it_sprite);
        }
        std::list<sf::Text>::iterator it_text;
        for(it_text=inventoryInterfaceTextSave.begin();it_text!=inventoryInterfaceTextSave.end();it_text++)
        {
            window->draw(*it_text);
        }
    }

    //Gestion du clic
    sf::Vector2i mouse_position;
    if(event.type == sf::Event::MouseButtonPressed && this->flags->interfaceON)
    {
        if (event.mouseButton.button == sf::Mouse::Left && !this->flags->mousePressed)
        {
            this->flags->mousePressed = true;
                mouse_position = sf::Mouse::getPosition(*window);
                for(int l=0;l<INVENTORY_L;l++)
                {
                    for(int h=0;h<INVENTORY_H;h++)
                    {
                        int Xmin = (((XMAX-INVENTORY_SLOT_SIZE*INVENTORY_L)/2)+INVENTORY_SLOT_SIZE*l);
                        int Xmax = (Xmin+INVENTORY_SLOT_SIZE);
                        int Ymin = (((YMAX-INVENTORY_SLOT_SIZE*INVENTORY_H)/2)+INVENTORY_SLOT_SIZE*h);
                        int Ymax = (Ymin + INVENTORY_SLOT_SIZE);
                        if(mouse_position.x>Xmin && mouse_position.x<Xmax && mouse_position.y>Ymin && mouse_position.y<Ymax) // on verifie si la sourie est sur un slot de l'inventaire
                        {
                            std::map<std::string,item_inventory>* inventoryMap = inventory->getInventory();
                            std::map<std::string,item_inventory>::iterator it;
                            for(it=inventoryMap->begin();it!=inventoryMap->end();it++)
                            {
                                    if(it->second.x == l && it->second.y == h)
                                    {
                                        it->second.item->setPosition(mouse_position.x,mouse_position.y);
                                        _TEMP_item = new Item(mouse_position.x,mouse_position.y,it->second.item->getName(),ORIGIN_DIFF_X_DYNAMIC,ORIGIN_DIFF_Y_DYNAMIC,64,64);//it->second.item;
                                        inventory->saveThisItemSlot(&(it->second));
                                        this->flags->moovingItem = true;
                                    }
                            }
                        }
                    }
                }
        }
    }
    if(event.type == sf::Event::MouseButtonPressed && this->flags->interfaceON)
    {
        if (event.mouseButton.button == sf::Mouse::Right && !this->flags->mousePressed_R)
        {
            this->flags->mousePressed_R = true;
                mouse_position = sf::Mouse::getPosition(*window);
                for(int l=0;l<INVENTORY_L;l++)
                {
                    for(int h=0;h<INVENTORY_H;h++)
                    {
                        int Xmin = (((XMAX-INVENTORY_SLOT_SIZE*INVENTORY_L)/2)+INVENTORY_SLOT_SIZE*l);
                        int Xmax = (Xmin+INVENTORY_SLOT_SIZE);
                        int Ymin = (((YMAX-INVENTORY_SLOT_SIZE*INVENTORY_H)/2)+INVENTORY_SLOT_SIZE*h);
                        int Ymax = (Ymin + INVENTORY_SLOT_SIZE);
                        if(mouse_position.x>Xmin && mouse_position.x<Xmax && mouse_position.y>Ymin && mouse_position.y<Ymax) // on verifie si la sourie est sur un slot de l'inventaire
                        {
                            std::map<std::string,item_inventory>* inventoryMap = inventory->getInventory();
                            std::map<std::string,item_inventory>::iterator it;
                            for(it=inventoryMap->begin();it!=inventoryMap->end();it++)
                            {
                                    if(it->second.x == l && it->second.y == h)
                                    {
                                        char* tempName = it->second.item->getName();
                                        it++;
                                        itemManager->useItem(tempName);
                                        inventory->deleteItemByName(tempName);

                                    }
                            }
                        }
                    }
                }
        }
    }
    if(this->flags->mousePressed && this->flags->inventoryShowed)
    {
        mouse_position = sf::Mouse::getPosition(*window);
        _TEMP_item->setPosition(mouse_position.x,mouse_position.y);
        window->draw(itemPrinter->getItemSprite(_TEMP_item));
    }
    if(event.type == sf::Event::MouseButtonReleased && this->flags->interfaceON)
    {
        if (event.mouseButton.button == sf::Mouse::Right)
        {
            this->flags->mousePressed_R = false;
        }
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            this->flags->mousePressed = false;
            if(this->flags->moovingItem)
            {
                mouse_position = sf::Mouse::getPosition(*window);
                for(int l=0;l<INVENTORY_L;l++)
                {
                    for(int h=0;h<INVENTORY_H;h++)
                    {
                        int Xmin = (((XMAX-INVENTORY_SLOT_SIZE*INVENTORY_L)/2)+INVENTORY_SLOT_SIZE*l);
                        int Xmax = (Xmin+INVENTORY_SLOT_SIZE);
                        int Ymin = (((YMAX-INVENTORY_SLOT_SIZE*INVENTORY_H)/2)+INVENTORY_SLOT_SIZE*h);
                        int Ymax = (Ymin + INVENTORY_SLOT_SIZE);
                        if(mouse_position.x>Xmin && mouse_position.x<Xmax && mouse_position.y>Ymin && mouse_position.y<Ymax) // on verifie si la sourie est sur un slot de l'inventaire
                        {
                            inventory->setNewPositionOnInventory(l,h);
                            this->flags->moovingItem=false;
                            this->flags->drop = true;
                        }
                    }
                }
            }
        }
    }


        //window->draw(playerInterface->display_lifeText(player->getLife(),20,YMAX-30));
    float life_percent = (player->getLife()/100.0)*100;
    sf::RectangleShape life_rect(sf::Vector2f((life_percent/100)*260, 17));
    life_rect.setPosition(52,24);

    if(life_percent>75)
        life_rect.setFillColor(sf::Color(0, 250, 40));
    else if(life_percent>50)
        life_rect.setFillColor(sf::Color(((75-life_percent)/25.0)*250, 250, 40));
    else if(life_percent>25)
        life_rect.setFillColor(sf::Color(250, 250-((50-life_percent)/25.0)*250, 40));
    else
        life_rect.setFillColor(sf::Color(250, 0, 40));

    window->draw(life_rect);
    int X_spellBar = (XMAX-68*10)/2-68;
    window->draw(playerInterface->display_spellbar_down((X_spellBar+68*10),YMAX-70));
    window->draw(playerInterface->display_spellbar_down((X_spellBar+68*9),YMAX-70));
    window->draw(playerInterface->display_spellbar_down((X_spellBar+68*8),YMAX-70));
    window->draw(playerInterface->display_spellbar_down((X_spellBar+68*7),YMAX-70));
    window->draw(playerInterface->display_spellbar_down((X_spellBar+68*6),YMAX-70));
    window->draw(playerInterface->display_spellbar_down((X_spellBar+68*5),YMAX-70));
    window->draw(playerInterface->display_spellbar_down((X_spellBar+68*4),YMAX-70));
    window->draw(playerInterface->display_spellbar_down((X_spellBar+68*3),YMAX-70));
    window->draw(playerInterface->display_spellbar_down((X_spellBar+68*2),YMAX-70));
    window->draw(playerInterface->display_spellbar_down((X_spellBar+68*1),YMAX-70));
    window->draw(playerInterface->display_heart(5,15));
    window->draw(playerInterface->display_lifeBar_big(player->getLife(),20,0));

}

void UIManager::showInventory(sf::RenderWindow* window)
{
    inventoryInterfaceSpriteSave.clear();
    inventoryInterfaceTextSave.clear();
    for(int l=0;l<INVENTORY_L;l++)
    {
        for(int h=0;h<INVENTORY_H;h++)
        {
            inventoryInterfaceSpriteSave.push_back(basicInterface->displayInventorySlot((((XMAX-INVENTORY_SLOT_SIZE*INVENTORY_L)/2)+INVENTORY_SLOT_SIZE*l),(((YMAX-INVENTORY_SLOT_SIZE*INVENTORY_H)/2)+INVENTORY_SLOT_SIZE*h)));
        }
    }
    std::map<std::string,item_inventory>* inventoryMap = inventory->getInventory();
    std::map<std::string,item_inventory>::iterator it;
    for(it=inventoryMap->begin();it!=inventoryMap->end();it++)
    {
        if(it->second.item_stack>0)
        {
            it->second.item->setPosition((((XMAX-INVENTORY_SLOT_SIZE*INVENTORY_L)/2)+INVENTORY_SLOT_SIZE*it->second.x),(((YMAX-INVENTORY_SLOT_SIZE*INVENTORY_H)/2)+INVENTORY_SLOT_SIZE*it->second.y));
            inventoryInterfaceSpriteSave.push_back(itemPrinter->getItemSprite(it->second.item));
            inventoryInterfaceTextSave.push_back(basicInterface->displayNbItem((((XMAX-INVENTORY_SLOT_SIZE*INVENTORY_L)/2)+INVENTORY_SLOT_SIZE*it->second.x+STACK_NUMBER_DECAL_L),(((YMAX-INVENTORY_SLOT_SIZE*INVENTORY_H)/2)+INVENTORY_SLOT_SIZE*it->second.y+STACK_NUMBER_DECAL_H),it->second.item_stack));
        }
    }
}
