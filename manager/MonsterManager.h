#ifndef MONSTER_MANAGER
#define MONSTER_MANAGER

#include "../misc/util.h"
#include "../resource/Monster.h"
#include "../resource/Player.h"
#include "../interface/MonsterInterface.h"
#include "ItemManager.h"

class MonsterManager
{
    private:
        float* ORIGIN_DIFF_X_DYNAMIC;
        float* ORIGIN_DIFF_Y_DYNAMIC;
        Player* player;
        std::list<Monster*> *monsterList;
        MonsterInterface* monsterInterface;
    public:
        MonsterManager(Player* player, std::list<Monster*> *monsterlist,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC);
        ~MonsterManager();
        void checkEvent(sf::Event& event,sf::RenderWindow* window);
        int rotation(int mX,int mY,int pX,int pY);
};

#endif
