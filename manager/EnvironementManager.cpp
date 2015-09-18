#include "EnvironementManager.h"

EnvironementManager::EnvironementManager(Data *dataContainer,Player* player,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC)
{
    this->dataContainer = dataContainer;
    land = new Ground(this->dataContainer,1,"grass",32,32,32,32,ORIGIN_DIFF_X_DYNAMIC,ORIGIN_DIFF_Y_DYNAMIC);
    this->ORIGIN_DIFF_X_DYNAMIC = ORIGIN_DIFF_X_DYNAMIC;
    this->ORIGIN_DIFF_Y_DYNAMIC = ORIGIN_DIFF_Y_DYNAMIC;
    this->player = player;
}


EnvironementManager::~EnvironementManager()
{

}

void EnvironementManager::checkEvent(sf::Event& event,sf::RenderWindow* window)
{
    float* tile_position;
    int x_max = (land->getOriginX()-(round((player->getPlayerRealX()-(XMAX/2))/32)))+2;
    int x_min = (land->getOriginX()-(round((player->getPlayerRealX()+(XMAX/2))/32)))-2;
    int y_max = (land->getOriginY()-(round((player->getPlayerRealY()-(YMAX/2))/32)))+2;
    int y_min = (land->getOriginY()-(round((player->getPlayerRealY()+(YMAX/2))/32)))-2;
    if(x_min<0)
        x_min = 0;
    if(x_min>MAP_SIZE_X)
        x_min = MAP_SIZE_X;
    if(x_max>MAP_SIZE_X)
        x_max = MAP_SIZE_X;
    if(x_max<0)
        x_max = 0;
    if(y_min<0)
        y_min = 0;
    if(y_min>MAP_SIZE_Y)
        y_min = MAP_SIZE_Y;
    if(y_max>MAP_SIZE_Y)
        y_max = MAP_SIZE_Y;
    if(y_max<0)
        y_max = 0;
    land->setGroundPosition(x_min,x_max,y_min,y_max);
   // std::cout << x_min << " | " << x_max << "||||||" << y_min << " | " << y_max << " origin " << land->getOriginY()<< std::endl;
   //  std::cout << player->getPlayerRealX() << " | " << player->getPlayerRealY() << std::endl;
    for(int i=y_min;i<y_max;i++)
    {
        for(int j=x_min;j<x_max;j++)
        {
                    window->draw(land->display(j,i));
        }
    }
}
