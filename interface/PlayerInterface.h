#ifndef PLAYER_INTERFACE
#define PLAYER_INTERFACE

#include "../misc/util.h"
#include "../resource/Data.h"

class PlayerInterface
{
    private:
        sf::Font playerFont;
        sf::Text playerLife;
        Data* dataContainer;
        sf::Texture texture;
        sf::Sprite lifebar_big_sprite;
        sf::Sprite spellBar_down_sprite;
        sf::Sprite heart_sprite;
    public:
        //constructor and destructor
        PlayerInterface(Data* dataContainer);
        ~PlayerInterface();

        //UI display functions
        sf::Text display_lifeText(int life,float X,float Y);
        sf::Sprite display_lifeBar_big(int life,float X,float Y);
        sf::Sprite display_spellbar_down(float X,float Y);
        sf::Sprite display_heart(float X,float Y);
};


#endif // MONSTER_INTERFACE

