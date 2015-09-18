#include "Item.h"

Item::Item(float x,float y,std::string name,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC,int XSpriteSize,int YSpriteSize)
{
    this->ORIGIN_DIFF_X_DYNAMIC = ORIGIN_DIFF_X_DYNAMIC;
    this->ORIGIN_DIFF_Y_DYNAMIC = ORIGIN_DIFF_Y_DYNAMIC;
    this->name = name;
    this->X = x;
    this->Y = y;
    this->Xmin = x-XSpriteSize/2;
    this->Ymin = y-YSpriteSize/2;
    this->Xmax = x+XSpriteSize/2;
    this->Ymax = y+YSpriteSize/2;
    this->Xsize = XSpriteSize;
    this->Ysize = YSpriteSize;
    this->inIventory = false;
}

bool Item::hitbox(int Xmin_test,int Xmax_test,int Ymin_test,int Ymax_test)
{
    if(inIventory)
    {
        return false;
    }
    else
    {
        if((Xmin>=Xmin_test && Xmin<=Xmax_test) || (Xmax>=Xmin_test && Xmax<=Xmax_test) || (Xmin_test>=Xmin && Xmin_test<=Xmax) || (Xmax_test>=Xmin && Xmax_test<=Xmax))
        {
            if((Ymin>=Ymin_test && Ymin<=Ymax_test) || (Ymax>=Ymin_test && Ymax<=Ymax_test) || (Ymin_test>=Ymin && Ymin_test<=Ymax) || (Ymax_test>=Ymin && Ymax_test<=Ymax))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
}

Item::~Item()
{
}

void Item::itemTaken()
{
    this->inIventory = true;
}

void Item::setPosition(int x,int y)
{
    this->X = x-(*ORIGIN_DIFF_X_DYNAMIC)+Xsize/2+2;
    this->Y = y-(*ORIGIN_DIFF_Y_DYNAMIC)+Ysize/2+2;
    this->Xmin = x-Xsize/2-(*ORIGIN_DIFF_X_DYNAMIC);
    this->Ymin = y-Ysize/2-(*ORIGIN_DIFF_Y_DYNAMIC);
    this->Xmax = x+Xsize/2-(*ORIGIN_DIFF_X_DYNAMIC);
    this->Ymax = y+Ysize/2-(*ORIGIN_DIFF_Y_DYNAMIC);
}

void Item::drop(int x,int y)
{
    this->inIventory = false;
}

