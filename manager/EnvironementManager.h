#ifndef ENVIRONEMENT_MANAGER
#define ENVIRONEMENT_MANAGER

#include "../misc/util.h"
#include "../resource/Ground.h"
#include "../resource/Player.h"

class EnvironementManager
{
    private:
        float* ORIGIN_DIFF_X_DYNAMIC;
        float* ORIGIN_DIFF_Y_DYNAMIC;
        Data* dataContainer;
        Ground* land;
        Player* player;
    public:
        EnvironementManager(Data *dataContainer,Player* player,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC);
        ~EnvironementManager();
        void checkEvent(sf::Event& event,sf::RenderWindow* window);
};

#endif
