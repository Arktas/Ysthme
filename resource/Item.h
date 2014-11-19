#ifndef ITEM_CLASS
#define ITEM_CLASS

#include "../misc/util.h"

class Item
{
    private:
        sf::Sprite* itemData;
        float X;
        float Y;
        std::string name;
    public:
        Item(sf::Sprite *itemData,float x,float y,std::string name);
        ~Item();
        float getItemRealX(){return X;};
        float getItemRealY(){return Y;};
        sf::Sprite display(float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC){itemData->setPosition(sf::Vector2f(X+(*ORIGIN_DIFF_X_DYNAMIC),Y+(*ORIGIN_DIFF_Y_DYNAMIC)));return *itemData;};
        char* getName(){return (char*)name.c_str();};
};

#endif
