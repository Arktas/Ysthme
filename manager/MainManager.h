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

        _MANAGER_Flags flags;

        float ORIGIN_DIFF_X_DYNAMIC;
        float ORIGIN_DIFF_Y_DYNAMIC;

        std::list<Spell*> spellList;
        std::list<Monster*> monsterList;
        std::list<Item*> itemList;

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

        Hitbox* _INST_hitbox;

        Inventory* inventory;


    public:
        MainManager();
        ~MainManager();
        void load();
        void CheckEvent();
        void quit();
};

#endif
