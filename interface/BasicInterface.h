#ifndef BASIC_INTERFACE
#define BASIC_INTERFACE

#include "../misc/util.h"
#include "../resource/Data.h"

class BasicInterface
{
    private:
        Data* dataContainer;
        sf::Texture texture;
        sf::Sprite InventorySlot;
        sf::Font nbItemFont;
        sf::Text nbItemText;
    public:
        //constructor and destructor
        BasicInterface(Data* dataContainer);
        ~BasicInterface();

        //UI display functions
        sf::Sprite displayInventorySlot(float X,float Y);
        sf::Text displayNbItem(int x, int y, int nb);
};


#endif // MONSTER_INTERFACE


