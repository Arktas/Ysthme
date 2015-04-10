#ifndef ITEM_CLASS
#define ITEM_CLASS

#include "../misc/util.h"

class Item
{
    private:
        float X;
        float Y;
        float* ORIGIN_DIFF_X_DYNAMIC;
        float* ORIGIN_DIFF_Y_DYNAMIC;
        std::string name;
    public:
        Item(float x,float y,std::string name,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC);
        ~Item();
        float getItemRealX(){return X;};
        float getItemRealY(){return Y;};
        float getItemX(){return (X+(*ORIGIN_DIFF_X_DYNAMIC));};
        float getItemY(){return (Y+(*ORIGIN_DIFF_Y_DYNAMIC));};
        //sf::Sprite display(float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC){itemData->setPosition(sf::Vector2f(X+(*ORIGIN_DIFF_X_DYNAMIC),Y+(*ORIGIN_DIFF_Y_DYNAMIC)));return *itemData;};
        char* getName(){return (char*)name.c_str();};
};

#endif
