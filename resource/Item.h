#ifndef ITEM_CLASS
#define ITEM_CLASS

#include "../misc/util.h"

class Item
{
    private:
        float X;
        float Y;
        int Xmin, Xmax, Ymin, Ymax;
        int Xsize,Ysize;
        float* ORIGIN_DIFF_X_DYNAMIC;
        float* ORIGIN_DIFF_Y_DYNAMIC;
        std::string name;
        bool inIventory;
    public:
        Item(float x,float y,std::string name,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC,int XSpriteSize,int YSpriteSize);
        ~Item();

        bool hitbox(int Xmin_test,int Xmax_test,int Ymin_test,int Ymax_test);


        float getItemRealX(){return X;};
        float getItemRealY(){return Y;};
        int getXmin(){return Xmin;};
        int getYmin(){return Ymin;};
        int getXmax(){return Xmax;};
        int getYmax(){return Ymax;};
        float getItemX(){return (X+(*ORIGIN_DIFF_X_DYNAMIC));};
        float getItemY(){return (Y+(*ORIGIN_DIFF_Y_DYNAMIC));};
        //sf::Sprite display(float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC){itemData->setPosition(sf::Vector2f(X+(*ORIGIN_DIFF_X_DYNAMIC),Y+(*ORIGIN_DIFF_Y_DYNAMIC)));return *itemData;};
        char* getName(){return (char*)name.c_str();};

        void itemTaken();
        void setPosition(int x, int y);
        void drop(int x,int y);
};

#endif
