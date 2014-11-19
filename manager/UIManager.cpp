#include "UIManager.h"


UIManager::UIManager(float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC)
{
    this->ORIGIN_DIFF_X_DYNAMIC = ORIGIN_DIFF_X_DYNAMIC;
    this->ORIGIN_DIFF_Y_DYNAMIC = ORIGIN_DIFF_Y_DYNAMIC;
}
UIManager::~UIManager()
{
}

void UIManager::checkEvent(sf::Event& event,sf::RenderWindow* window,MainManager* mainManager)
{
    if(event.type == sf::Event::KeyPressed && event.key.code==sf::Keyboard::Escape)
    {
        mainManager->quit();
    }
}
