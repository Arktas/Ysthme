#ifndef UI_MANAGER
#define UI_MANAGER

#include "../misc/util.h"
#include "MainManager.h"

class UIManager
{
    private:
        float* ORIGIN_DIFF_X_DYNAMIC;
        float* ORIGIN_DIFF_Y_DYNAMIC;
    public:
        UIManager(float* ORIGIN_DIFF_X_DYNAMIC,float *ORIGIN_DIFF_Y_DYNAMIC);
        ~UIManager();
        void checkEvent(sf::Event& event,sf::RenderWindow* window,MainManager* mainManager);
};

#endif

