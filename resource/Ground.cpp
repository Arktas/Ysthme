#include "Ground.h"


Ground::Ground(Data *dataContainer,int nbSprite,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC)
{
    map_struct = (unsigned char*)malloc(sizeof(unsigned char)*MAP_SIZE_Y*MAP_SIZE_X);
    map_ressources = (sf::Sprite*)malloc(sizeof(sf::Sprite)*1);
    origin_x = round(MAP_SIZE_X/2)+1;
    origin_y = round(MAP_SIZE_Y/2)+1;
    if(!groundTexture.loadFromImage(dataContainer->getImage(textureFile.c_str()),sf::IntRect(XTextureBegin, YTextureBegin, XSpriteSize, YSpriteSize))){}
    for(int i=0;i<MAP_SIZE_Y;i++)
    {
        for(int j=0;j<MAP_SIZE_X;j++)
        {
            map_struct[j+i*MAP_SIZE_Y] = GRASS;
        }
    }
    for(int i=0;i<1;i++)
    {
        sf::Sprite temp;
        temp.setTexture(groundTexture);
        temp.setTextureRect(sf::IntRect(0,0, XSpriteSize, YSpriteSize));
        temp.setOrigin(0,0);
        map_ressources[i] = temp;
    }
    this->ORIGIN_DIFF_X_DYNAMIC = ORIGIN_DIFF_X_DYNAMIC;
    this->ORIGIN_DIFF_Y_DYNAMIC = ORIGIN_DIFF_Y_DYNAMIC;

}

Ground::~Ground()
{

}

sf::Sprite Ground::display(int X,int Y)
{
    switch(map_struct[X+Y*MAP_SIZE_Y])
    {
        case GRASS:
            sf::Sprite temp = map_ressources[GRASS];
            temp.setPosition(sf::Vector2f(((X-origin_x)*32)+round(*ORIGIN_DIFF_X_DYNAMIC),(Y-origin_y)*32+round(*ORIGIN_DIFF_Y_DYNAMIC)));
            return temp;
        break;
    }
}

void Ground::setGroundPosition(int x_min,int x_max,int y_min,int y_max)
{
}
