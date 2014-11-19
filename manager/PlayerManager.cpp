#include "PlayerManager.h"

PlayerManager::PlayerManager(Player* player,bool* left,bool* right,bool* top,bool* down,bool* dirTop,bool* dirDown,bool* dirRight,bool* dirLeft,bool* mousePressed,bool* spell,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC)
{
    this->left = left;
    this->right = right;
    this->top = top;
    this->down = down;
    this->dirTop = dirTop;
    this->dirDown = dirDown;
    this->dirRight = dirRight;
    this->dirLeft = dirLeft;
    this->mousePressed = mousePressed;
    this->spell = spell;
    this->player = player;
    this->ORIGIN_DIFF_X_DYNAMIC = ORIGIN_DIFF_X_DYNAMIC;
    this->ORIGIN_DIFF_Y_DYNAMIC = ORIGIN_DIFF_Y_DYNAMIC;
}
PlayerManager::~PlayerManager()
{
}
void PlayerManager::checkEvent(sf::Event& event,sf::RenderWindow* window)
{
    mousePosition = sf::Mouse::getPosition(*window);
    player->doRotation(rotation(mousePosition.x,mousePosition.y,player->getPlayerX(),player->getPlayerY()));
    if(event.type == sf::Event::KeyReleased && event.key.code==sf::Keyboard::S)
    {
        *down = false;
        *dirDown = false;
    }
    if(event.type == sf::Event::KeyReleased && event.key.code==sf::Keyboard::Z)
    {
        *top = false;
        *dirTop = false;
    }
    if(event.type == sf::Event::KeyReleased && event.key.code==sf::Keyboard::D)
    {
        *right = false;
        *dirRight = false;
    }
    if(event.type == sf::Event::KeyReleased && event.key.code==sf::Keyboard::Q)
    {
        *left = false;
        *dirLeft = false;
    }
    if(!(*mousePressed))
    {
        if(event.type == sf::Event::KeyPressed && event.key.code==sf::Keyboard::S)
        {
            if(!(*dirDown))
            {
                *down = true;
                *dirDown = true;
            }
        }
        if(event.type == sf::Event::KeyPressed && event.key.code==sf::Keyboard::Z)
        {
            if(!(*dirTop))
            {

                *top = true;
                *dirTop = true;
            }
        }
        if(event.type == sf::Event::KeyPressed && event.key.code==sf::Keyboard::D)
        {
            if(!(*dirRight))
            {

                *right = true;
                *dirRight = true;
            }
        }
        if(event.type == sf::Event::KeyPressed && event.key.code==sf::Keyboard::Q)
        {
            if(!(*dirLeft))
            {

                *left = true;
                *dirLeft = true;
            }
        }
        if((*top)&&(*left))
        {
            player->setDirection(UP_LEFT);
            player->moving(sqrt((pow((SPEED),2)/2)),sqrt((pow((SPEED),2)/2)));
        }
        else if((*top)&&(*right))
        {
            player->setDirection(UP_RIGHT);
            player->moving(-sqrt((pow((SPEED),2)/2)),sqrt((pow((SPEED),2)/2)));
        }
        else if((*down)&&(*left))
        {
            player->setDirection(DOWN_LEFT);
            player->moving(sqrt((pow((SPEED),2)/2)),-sqrt((pow((SPEED),2)/2)));
        }
        else if((*down)&&(*right))
        {
            player->setDirection(DOWN_RIGHT);
            player->moving(-sqrt((pow((SPEED),2)/2)),-sqrt((pow((SPEED),2)/2)));
        }
        else
        {
            if((*top))
            {
                player->setDirection(UP);
                player->moving(0,SPEED);
            }
            else if((*down))
            {
                player->setDirection(DOWN);
                player->moving(0,-SPEED);
            }
            else if((*right))
            {
                player->setDirection(RIGHT);
                player->moving(-SPEED,0);
            }
            else if((*left))
            {
                player->setDirection(LEFT);
                player->moving(SPEED,0);
            }
            else
            {
                player->idle();
            }
        }
    }
    if(event.type == sf::Event::MouseButtonPressed )
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            *mousePressed = true;
            if(spell)
            {
                player->setState(PLAYER_CAST);
            }
        }
    }
    if(event.type == sf::Event::MouseButtonReleased)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            *mousePressed = false;
            player->setState(PLAYER_PASSIVE);
        }
    }
    if(*mousePressed)
    {
        player->cast();
    }
    window->draw(player->getPlayerSprite());
}

int PlayerManager::rotation(int mX,int mY,int pX,int pY)
{
    float rad = 0.0;
    int angle = 0;
    rad = atan2(mY-pY,mX-pX);
    angle = rad*(180/PI);
    return angle;
}
