#include "MonsterManager.h"

MonsterManager::MonsterManager(Player* player, std::list<Monster*> *monsterlist,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC)
{
    this->player = player;
    this->monsterList = monsterlist;
    this->monsterInterface = new MonsterInterface();
    this->ORIGIN_DIFF_X_DYNAMIC=ORIGIN_DIFF_X_DYNAMIC;
    this->ORIGIN_DIFF_Y_DYNAMIC=ORIGIN_DIFF_Y_DYNAMIC;
}

MonsterManager::~MonsterManager()
{
}

void MonsterManager::checkEvent(sf::Event& event,sf::RenderWindow* window)
{
   // std::cout << player->getPlayerRealX() << " P " << player->getPlayerRealY() << std::endl;
    if(!(monsterList->empty()))
    {
        std::list<Monster*>::iterator it;

        for(it=monsterList->begin();it!=monsterList->end();it++)
        {
            if((*it)->getCanAttack())
            {
                (*it)->doRotation(rotation(player->getPlayerX(),player->getPlayerY(),(*it)->getMonsterX(),(*it)->getMonsterY()));
                (*it)->cast();
            }
            // std::cout << (*it)->getMonsterRealX() << " M " << (*it)->getMonsterRealY() << std::endl;
            if((*it)->getMonsterRealX()>(-(player->getPlayerRealX()+LIFE_MANAGEMENT_RANGE)) && (*it)->getMonsterRealX()<(-(player->getPlayerRealX()-LIFE_MANAGEMENT_RANGE)) && (*it)->getMonsterRealY()>(-(player->getPlayerRealY()+LIFE_MANAGEMENT_RANGE)) && (*it)->getMonsterRealY()<(-(player->getPlayerRealY()-LIFE_MANAGEMENT_RANGE)))
            {
                (*it)->agroChange(player->getPlayerX(),player->getPlayerY());
                if((*it)->getAgro())
                {
                    (*it)->doRotation(rotation(player->getPlayerX(),player->getPlayerY(),(*it)->getMonsterX(),(*it)->getMonsterY()));
                    if((*it)->getMoove())
                    {
                        float mX = (cos((*it)->getMonsterRotation()* PI / 180.0)*2);
                        float mY = (sin((*it)->getMonsterRotation()* PI / 180.0)*2);
                        (*it)->moving(mX,mY);
                    }
                    else
                    {
                       (*it)->idle();
                    }
                }

                if((*it)->alive())
                {
                    (*it)->setMonsterPosition();
                    window->draw(monsterInterface->display((*it)->getLife(),(*it)->getMonsterX()-5,((*it)->getMonsterY()-70)));
                    window->draw((*it)->getMonsterSprite());
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
