#ifndef PLAYER_MANAGER
#define PLAYER_MANAGER

#include "../misc/util.h"
#include "../resource/Player.h"
#include "../resource/Monster.h"
#include "../printer/PlayerPrinter.h"
#include "../resource/Data.h"

class PlayerManager
{
    private:
        float* ORIGIN_DIFF_X_DYNAMIC;
        float* ORIGIN_DIFF_Y_DYNAMIC;
        _MANAGER_Flags *flags;
        sf::Vector2i mousePosition;
        Player* player;
        PlayerPrinter* playerPrinter;
        Hitbox* _INST_hitbox;
        std::list<Monster*> *monsterList;

    public:
        PlayerManager(Hitbox* _INST_hitbox, Data* dataContainer,std::list<Monster*> *monsterlist,Player* player,_MANAGER_Flags *flags,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC);
        ~PlayerManager();
        void checkEvent(sf::Event& event,sf::RenderWindow* window);
        int rotation(int mX,int mY,int pX,int pY);
};

#endif
