#ifndef SPELL_MANAGER
#define SPELL_MANAGER

#include "../misc/util.h"
#include "../resource/Spell.h"
#include "../resource/Player.h"
#include "../resource/Monster.h"

class SpellManager
{
    private:
        float* ORIGIN_DIFF_X_DYNAMIC;
        float* ORIGIN_DIFF_Y_DYNAMIC;
        bool* spell;
        std::list<Spell*> spellList;
        Player* player;
        std::list<Monster*> *monsterList;
        Data *dataContainer;
    public:
        SpellManager(Player* player,std::list<Monster*> *monsterlist,bool* spell,Data *dataContainer,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC);
        ~SpellManager();
        void CheckEvent(sf::Event& event,sf::RenderWindow* window);
        int rotation(int mX,int mY,int pX,int pY);
};

#endif