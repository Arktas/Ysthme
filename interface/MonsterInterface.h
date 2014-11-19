#ifndef MONSTER_INTERFACE
#define MONSTER_INTERFACE

#include "../misc/util.h"

class MonsterInterface
{
    private:
        sf::Font monsterFont;
        sf::Text monsterLife;
    public:
        //constructor and destructor
        MonsterInterface();
        ~MonsterInterface();

        //UI display functions
        sf::Text display(int life,float X,float Y);
};


#endif // MONSTER_INTERFACE
