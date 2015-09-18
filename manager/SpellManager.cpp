#include "SpellManager.h"

SpellManager::SpellManager(Hitbox* _INST_hitbox, Player* player,std::list<Monster*> *monsterlist,_MANAGER_Flags *flags,Data *dataContainer,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC)
{
    this->flags = flags;
    this->player = player;
    this->monsterList = monsterlist;
    this->dataContainer = dataContainer;
    this->ORIGIN_DIFF_X_DYNAMIC = ORIGIN_DIFF_X_DYNAMIC;
    this->ORIGIN_DIFF_Y_DYNAMIC = ORIGIN_DIFF_Y_DYNAMIC;
    this->spellPrinter = new SpellPrinter(dataContainer,"fireball",0,0,40,48,8);
    this->_INST_hitbox = _INST_hitbox;
}
SpellManager::~SpellManager()
{
}
void SpellManager::CheckEvent(sf::Event& event,sf::RenderWindow* window)
{
    if(event.type == sf::Event::MouseButtonPressed && !this->flags->interfaceON)
    {
        if(this->flags->spell)
        {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
                float mX = (cos(player->getPlayerRotation()* PI / 180.0)/5);
                float mY = (sin(player->getPlayerRotation()* PI / 180.0)/5);
                spellList.push_back(new Spell(dataContainer,8,"fireball",0,0,40,48,mX,mY,player->getPlayerX(),player->getPlayerY(),player->getPlayerRotation(),1,PLAYER_SPELL,SPELL_SPEED,700,ORIGIN_DIFF_X_DYNAMIC,ORIGIN_DIFF_Y_DYNAMIC));
            }
            this->flags->spell = false;
        }
    }
    if(event.type == sf::Event::MouseButtonReleased && !this->flags->interfaceON)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            if(!(this->flags->spell))
            {
                this->flags->spell = true;
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
            //tester ici la hitbox
            (*it)->moving();
            switch((*it)->getSource())
            {
                case PLAYER_SPELL:
                if(!(monsterList->empty()))
                {
                    std::list<Monster*>::iterator monster;
                    for(monster=monsterList->begin();monster!=monsterList->end();monster++)
                    {
                        if((*monster)->hitbox((*it)->getXmin(),(*it)->getXmax(),(*it)->getYmin(),(*it)->getYmax()))
                        {
                            (*monster)->hit((*it)->getDamage());
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
                if(player->hitbox((*it)->getXmin(),(*it)->getXmax(),(*it)->getYmin(),(*it)->getYmax()))
                {
                    player->hit((*it)->getDamage());
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
            {
                if((*it)!=NULL)
                {
                    if(SHOW_HITBOX)
                    {
                        sf::RectangleShape hitbox(sf::Vector2f(((*it)->getXmax()-(*it)->getXmin()),((*it)->getYmax()-(*it)->getYmin())));
                        hitbox.setFillColor(sf::Color(250,0,0));
                        hitbox.setOrigin(((*it)->getXmax()-(*it)->getXmin())/2,((*it)->getYmax()-(*it)->getYmin())/2);
                        hitbox.setPosition((*it)->getSpellX(),(*it)->getSpellY());
                        window->draw(hitbox);
                    }
                    window->draw(spellPrinter->getSpellSprite((*it)));
                }
            }

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
