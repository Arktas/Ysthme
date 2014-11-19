#ifndef PLAYER_MANAGER
#define PLAYER_MANAGER

#include "../misc/util.h"
#include "../resource/Player.h"
#include "../resource/Monster.h"
class PlayerManager
{
    private:
        float* ORIGIN_DIFF_X_DYNAMIC;
        float* ORIGIN_DIFF_Y_DYNAMIC;
        bool* left;
        bool* right;
        bool* top;
        bool* down;
        bool* dirTop;
        bool* dirDown;
        bool* dirRight;
        bool* dirLeft;
        bool* mousePressed;
        bool* spell;
        sf::Vector2i mousePosition;
        Player* player;
    public:
        PlayerManager(Player* player,bool* left,bool* right,bool* top,bool* down,bool* dirTop,bool* dirDown,bool* dirRight,bool* dirLeft,bool* mousePressed,bool* spell,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC);
        ~PlayerManager();
        void checkEvent(sf::Event& event,sf::RenderWindow* window);
        int rotation(int mX,int mY,int pX,int pY);
};

#endif
