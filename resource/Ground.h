#ifndef GROUND
#define GROUND

#include "../misc/util.h"

class Ground{

private:
    sf::Texture groundTexture;
    sf::Sprite* spriteTab;
    sf::Sprite* map_ressources;
    unsigned char* map_struct;
    float* ORIGIN_DIFF_X_DYNAMIC;
    float* ORIGIN_DIFF_Y_DYNAMIC;
    int origin_x;
    int origin_y;

public:
    Ground(Data *dataContainer,int nbSprite,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC);
    ~Ground();
    sf::Sprite display(int X,int Y);
    void setGroundPosition(int x_min,int x_max,int y_min,int y_max);
    float* getTilePosition(int X,int Y){float position[2];position[0]=X*80;position[1]=Y*80;return position;};
    int getOriginX(){return origin_x;};
    int getOriginY(){return origin_y;};
};
#endif
