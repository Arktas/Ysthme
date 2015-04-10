#ifndef PLAYER_INTERFACE
#define PLAYER_INTERFACE

#include "../misc/util.h"

class PlayerInterface
{
    private:
        sf::Font playerFont;
        sf::Text playerLife;
    public:
        //constructor and destructor
        PlayerInterface();
        ~PlayerInterface();

        //UI display functions
        sf::Text display(int life,float X,float Y);
};


#endif // MONSTER_INTERFACE

