#ifndef MAIN_MANAGER
#define MAIN_MANAGER

#include "../misc/util.h"
#include "MonsterManager.h"
#include "SpellManager.h"
#include "PlayerManager.h"
#include "UIManager.h"
#include "EnvironementManager.h"
#include "../resource/Data.h"

class MainManager
{
    private:
        //move flag
            bool left;
            bool right;
            bool top;
            bool down;
            bool dirTop;
            bool dirDown;
            bool dirRight;
            bool dirLeft;
            bool spell;
            bool mousePressed;


            float ORIGIN_DIFF_X_DYNAMIC;
            float ORIGIN_DIFF_Y_DYNAMIC;

            std::list<Spell*> spellList;
            std::list<Monster*> monsterList;

            sf::RenderWindow* window;
            sf::Event event;

            sf::Vector2i mousePosition;
            Player* player;
            float X,Y;
            Monster* monster;

            PlayerManager* playerManager;
            MonsterManager* monsterManager;
            SpellManager* spellManager;
            UIManager* uiManager;
            EnvironementManager* environementManager;
            ItemManager* itemManager;

            Data *dataContainer;
            Clock *clock;

            MonsterInterface* monsterInterface;


    public:
        MainManager();
        ~MainManager();
        void load();
        void CheckEvent();
        void quit();
};

#endif
