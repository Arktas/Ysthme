#ifndef PLAYER
#define PLAYER

#include "../misc/util.h"
#include "Character.h"
#include "Item.h"

typedef struct item_inventory{
Item* item;
unsigned char item_stack;
}item_inventory;

class Character;

class Player : public Character
{
    private :
        std::map<std::string,item_inventory> inventory;
        int state;
    public :
        //constructor and destructor
        Player(Data* dataContainer,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,int x,int y,int life,int nbSprite,int nbSpriteAnim,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC);
        ~Player();

        //moving functions
        void doRotation(int angle);
        void moving(float x,float y);
        void idle(){indexAnim=indexAnimIdle;};

        //appearance
        void changeTexture(int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize);

        //context functions
        bool hit(int x,int y,int damage);
        bool alive();


        //getters and setters
        sf::Sprite getPlayerSprite(){return spriteTab[(spriteIndex*nbSpriteAnim)+indexAnim];};
        void cast();
        int getPlayerRotation(){return rotation;/*spriteTab[state].getRotation()*/};
        float getPlayerX(){return (*ORIGIN_DIFF_X_DYNAMIC)-X;};
        float getPlayerY(){return (*ORIGIN_DIFF_Y_DYNAMIC)-Y;};
        float getPlayerRealX(){return X;};
        float getPlayerRealY(){return Y;};
        int getLife(){return life;};
        void setDirection(int direction){spriteIndex = direction;};
        void setState(int newState){state = newState;};
        void addItemToInventory(Item* item);
};

#endif
