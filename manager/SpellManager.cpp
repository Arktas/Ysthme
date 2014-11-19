#include "SpellManager.h"

SpellManager::SpellManager(Player* player,std::list<Monster*> *monsterlist,bool* spell,Data *dataContainer,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC)
{
    this->spell = spell;
    this->player = player;
    this->monsterList = monsterlist;
    this->dataContainer = dataContainer;
    this->ORIGIN_DIFF_X_DYNAMIC = ORIGIN_DIFF_X_DYNAMIC;
    this->ORIGIN_DIFF_Y_DYNAMIC = ORIGIN_DIFF_Y_DYNAMIC;
}
SpellManager::~SpellManager()
{
}
void SpellManager::CheckEvent(sf::Event& event,sf::RenderWindow* window)
{
    if(event.type == sf::Event::MouseButtonPressed)
    {
        if(*spell)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                float mX = (cos(player->getPlayerRotation()* PI / 180.0)/5);
                float mY = (sin(player->getPlayerRotation()* PI / 180.0)/5);
                spellList.push_back(new Spell(dataContainer,8,"fireball",0,0,40,48,mX,mY,player->getPlayerX(),player->getPlayerY(),player->getPlayerRotation(),1,PLAYER_SPELL,SPELL_SPEED,700,ORIGIN_DIFF_X_DYNAMIC,ORIGIN_DIFF_Y_DYNAMIC));
            }
            *spell = false;
        }
    }
    if(event.type == sf::Event::MouseButtonReleased)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if(!(*spell))
            {
                *spell = true;
            }
        }
    }
    std::list<Monster*>::iterator monster;
    for(monster=monsterList->begin();monster!=monsterList->end();monster++)
    {
        if((*monster)->getCanAttack())
        {
            float mX = (cos((*monster)->getMonsterRotation() * PI / 180.0)/5);
            float mY = (sin((*monster)->getMonsterRotation() * PI / 180.0)/5);
            spellList.push_back(new Spell(dataContainer,8,"fireball",0,0,40,48,mX,mY,(*monster)->getMonsterX(),(*monster)->getMonsterY(),(*monster)->getMonsterRotation(),1,MONSTER_SPELL,SPELL_SPEED,700,ORIGIN_DIFF_X_DYNAMIC,ORIGIN_DIFF_Y_DYNAMIC));
        }
    }
    if(!(spellList.empty()))
    {
        std::list<Spell*>::iterator it;
        for(it=spellList.begin();it!=spellList.end();it++)
        {
            bool touch = false;
            (*it)->moving();
            switch((*it)->getSource())
            {
                case PLAYER_SPELL:
                if(!(monsterList->empty()))
                {
                    std::list<Monster*>::iterator monster;
                    for(monster=monsterList->begin();monster!=monsterList->end();monster++)
                    {
                        if((*monster)->hit((*it)->getSpellRealX(),(*it)->getSpellRealY(),(*it)->getDamage()))
                        {
                            std::list<Spell*>::iterator iterase = it;
                            it--;
                            delete((*iterase));
                            spellList.erase(iterase);
                            touch = true;
                        }
                    }
                }
                break;
                case MONSTER_SPELL:
                if(player->hit((*it)->getSpellRealX(),(*it)->getSpellRealY(),(*it)->getDamage()))
                {
                    std::list<Spell*>::iterator iterase = it;
                    it--;
                    delete((*iterase));
                    spellList.erase(iterase);
                    touch = true;
                }
                break;
            }
            if(touch)
            {
            }
            else if((*it)->getRange()<0){
                std::list<Spell*>::iterator iterase = it;
                it--;
                spellList.erase(iterase);
            }
            else
                window->draw((*it)->getSpellSprite());
        }
    }
}

int SpellManager::rotation(int mX,int mY,int pX,int pY)
{
    float rad = 0.0;
    int angle = 0;
    rad = atan2(mY-pY,mX-pX);
    angle = rad*(180/PI);
    return angle;
}
