#include "PlayerManager.h"

PlayerManager::PlayerManager(Hitbox* _INST_hitbox, Data* dataContainer,std::list<Monster*> *monsterlist,Player* player,_MANAGER_Flags *flags,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC)
{
    this->flags = flags;
    this->monsterList = monsterlist;
    this->player = player;
    this->ORIGIN_DIFF_X_DYNAMIC = ORIGIN_DIFF_X_DYNAMIC;
    this->ORIGIN_DIFF_Y_DYNAMIC = ORIGIN_DIFF_Y_DYNAMIC;
    this->playerPrinter = new PlayerPrinter(player,dataContainer,"player",0,0,96,110,8,10);
    this->_INST_hitbox = _INST_hitbox;
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
        this->flags->down = false;
        this->flags->dirDown = false;
    }
    if(event.type == sf::Event::KeyReleased && event.key.code==sf::Keyboard::Z)
    {
        this->flags->top = false;
        this->flags->dirTop = false;
    }
    if(event.type == sf::Event::KeyReleased && event.key.code==sf::Keyboard::D)
    {
        this->flags->right = false;
        this->flags->dirRight = false;
    }
    if(event.type == sf::Event::KeyReleased && event.key.code==sf::Keyboard::Q)
    {
        this->flags->left = false;
        this->flags->dirLeft = false;
    }
    if(!(this->flags->mousePressed) || this->flags->interfaceON)
    {
        if(event.type == sf::Event::KeyPressed && event.key.code==sf::Keyboard::S)
        {
            if(!(this->flags->dirDown))
            {
                this->flags->down = true;
                this->flags->dirDown = true;
            }
        }
        if(event.type == sf::Event::KeyPressed && event.key.code==sf::Keyboard::Z)
        {
            if(!(this->flags->dirTop))
            {

                this->flags->top = true;
                this->flags->dirTop = true;
            }
        }
        if(event.type == sf::Event::KeyPressed && event.key.code==sf::Keyboard::D)
        {
            if(!(this->flags->dirRight))
            {

                this->flags->right = true;
                this->flags->dirRight = true;
            }
        }
        if(event.type == sf::Event::KeyPressed && event.key.code==sf::Keyboard::Q)
        {
            if(!(this->flags->dirLeft))
            {

                this->flags->left = true;
                this->flags->dirLeft = true;
            }
        }
        //Definition du mouvement
        float move_x=0,move_y=0;
        bool askForMoove = true;

        if((this->flags->top)&&(this->flags->left))
        {
            player->setDirection(UP_LEFT);
            //tester ici hitbox deplacement
            move_x = sqrt((pow((SPEED),2)/2));
            move_y = sqrt((pow((SPEED),2)/2));
        }
        else if((this->flags->top)&&(this->flags->right))
        {
            player->setDirection(UP_RIGHT);
            //tester ici hitbox deplacement
            move_x = -sqrt((pow((SPEED),2)/2));
            move_y = sqrt((pow((SPEED),2)/2));
        }
        else if((this->flags->down)&&(this->flags->left))
        {
            player->setDirection(DOWN_LEFT);
            //tester ici hitbox deplacement
            move_x = sqrt((pow((SPEED),2)/2));
            move_y = -sqrt((pow((SPEED),2)/2));
        }
        else if((this->flags->down)&&(this->flags->right))
        {
            player->setDirection(DOWN_RIGHT);
            //tester ici hitbox deplacement
            move_x = -sqrt((pow((SPEED),2)/2));
            move_y = -sqrt((pow((SPEED),2)/2));
        }
        else
        {
            if((this->flags->top))
            {
                player->setDirection(UP);
                //tester ici hitbox deplacement
                move_x = 0;
                move_y = SPEED;
            }
            else if((this->flags->down))
            {
                player->setDirection(DOWN);
                //tester ici hitbox deplacement
                move_x = 0;
                move_y = -SPEED;
            }
            else if((this->flags->right))
            {
                player->setDirection(RIGHT);
                //tester ici hitbox deplacement
                move_x = -SPEED;
                move_y = 0;
            }
            else if((this->flags->left))
            {
                player->setDirection(LEFT);
                //tester ici hitbox deplacement
                move_x = SPEED;
                move_y = 0;
            }
            else
            {
                askForMoove = false;
                player->idle();
            }
        }
        std::list<Monster*>::iterator it;
        if(askForMoove)
        {
            bool movement_allow = true;
            player->moving(move_x,move_y);
            for(it=monsterList->begin();it!=monsterList->end();it++)
            {
                if(player->hitbox((*it)->getXmin(),(*it)->getXmax(),(*it)->getYmin(),(*it)->getYmax()))
                {
                    movement_allow = false;
                }
            }
            if(!movement_allow)
            {
                player->moving(-move_x,-move_y);
                player->idle();
            }
        }
    }
    if(event.type == sf::Event::MouseButtonPressed && !this->flags->interfaceON)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            this->flags->mousePressed = true;
            if(this->flags->spell)
            {
                player->setState(PLAYER_CAST);
            }
        }
    }
    if(event.type == sf::Event::MouseButtonReleased && !this->flags->interfaceON)
    {
        if (event.mouseButton.button == sf::Mouse::Left)
        {
            this->flags->mousePressed = false;
            player->setState(PLAYER_PASSIVE);
        }
    }
    if(this->flags->mousePressed && !this->flags->interfaceON)
    {
        player->cast();
    }
    if(SHOW_HITBOX)
    {
        sf::RectangleShape hitbox(sf::Vector2f((player->getXmax()-player->getXmin()),(player->getYmax()-player->getYmin())));
        hitbox.setFillColor(sf::Color(250,0,0));
        hitbox.setOrigin((player->getXmax()-player->getXmin())/2,(player->getYmax()-player->getYmin())/2);
        hitbox.setPosition(player->getPlayerX(),player->getPlayerY());
        window->draw(hitbox);
    }
    window->draw(playerPrinter->getPlayerSprite(player));
}

int PlayerManager::rotation(int mX,int mY,int pX,int pY)
{
    float rad = 0.0;
    int angle = 0;
    rad = atan2(mY-pY,mX-pX);
    angle = rad*(180/PI);
    return angle;
}
