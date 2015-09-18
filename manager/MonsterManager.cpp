#include "MonsterManager.h"

MonsterManager::MonsterManager(Hitbox* _INST_hitbox, Data* dataContainer,Player* player, std::list<Monster*> *monsterlist,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC)
{
    this->player = player;
    this->monsterList = monsterlist;
    this->monsterInterface = new MonsterInterface();
    this->monsterPrinter = new MonsterPrinter(dataContainer,"zombie",0,0,96,110,8,10);
    this->ORIGIN_DIFF_X_DYNAMIC=ORIGIN_DIFF_X_DYNAMIC;
    this->ORIGIN_DIFF_Y_DYNAMIC=ORIGIN_DIFF_Y_DYNAMIC;
    this->_INST_hitbox = _INST_hitbox;
}

MonsterManager::~MonsterManager()
{
}

void MonsterManager::checkEvent(sf::Event& event,sf::RenderWindow* window)
{
    if(!(monsterList->empty()))
    {
        std::list<Monster*>::iterator it;

        for(it=monsterList->begin();it!=monsterList->end();it++)
        {
            if((*it)->getMonsterRealX()>(-(player->getPlayerRealX()+LIFE_MANAGEMENT_RANGE)) && (*it)->getMonsterRealX()<(-(player->getPlayerRealX()-LIFE_MANAGEMENT_RANGE)) && (*it)->getMonsterRealY()>(-(player->getPlayerRealY()+LIFE_MANAGEMENT_RANGE)) && (*it)->getMonsterRealY()<(-(player->getPlayerRealY()-LIFE_MANAGEMENT_RANGE)))
            {
                if((*it)->getCanAttack())
                {
                    (*it)->doRotation(rotation(player->getPlayerX(),player->getPlayerY(),(*it)->getMonsterX(),(*it)->getMonsterY()));
                    (*it)->cast();
                }
                else
                {
                    (*it)->cast();
                }
                (*it)->agroChange(player->getPlayerX(),player->getPlayerY());
                if((*it)->getAgro())
                {
                    (*it)->doRotation(rotation(player->getPlayerX(),player->getPlayerY(),(*it)->getMonsterX(),(*it)->getMonsterY()));
                    if((*it)->getMoove())
                    {
                        //tester ici la hitbox deplacement monstre
                        float mX = (cos((*it)->getMonsterRotation()* PI / 180.0)*2);
                        float mY = (sin((*it)->getMonsterRotation()* PI / 180.0)*2);
                        bool movement_allow = true;
                        (*it)->moving(mX,mY);
                        if((*it)->hitbox((this->player)->getXmin(),(this->player)->getXmax(),(this->player)->getYmin(),(this->player)->getYmax()))
                        {
                            movement_allow = false;
                        }
                        if(!movement_allow)
                        {
                            (*it)->moving(-mX,-mY);
                            (*it)->idle();
                        }
                    }
                    else
                    {
                       //(*it)->idle();
                    }
                }

                if((*it)->alive())
                {
                    (*it)->setMonsterPosition();
                    if(SHOW_HITBOX)
                    {
                        sf::RectangleShape hitbox(sf::Vector2f(((*it)->getXmax()-(*it)->getXmin()),((*it)->getYmax()-(*it)->getYmin())));
                        hitbox.setFillColor(sf::Color(250,0,0));
                        hitbox.setOrigin(((*it)->getXmax()-(*it)->getXmin())/2,((*it)->getYmax()-(*it)->getYmin())/2);
                        hitbox.setPosition((*it)->getMonsterX(),(*it)->getMonsterY());
                        window->draw(hitbox);
                    }
                    window->draw(monsterInterface->display((*it)->getMaxLife(),(*it)->getLife(),(*it)->getMonsterX()-20,((*it)->getMonsterY()-70)));
                    window->draw(monsterPrinter->getMonsterSprite((*it)));
                }
                else
                {
                    std::list<Monster*>::iterator iterase = it;
                    it--;
                    delete((*iterase));
                    monsterList->erase(iterase);
                }
            }
        }
    }

}

int MonsterManager::rotation(int mX,int mY,int pX,int pY)
{
    float rad = 0.0;
    int angle = 0;
    rad = atan2(mY-pY,mX-pX);
    angle = rad*(180/PI);
    return angle;
}
