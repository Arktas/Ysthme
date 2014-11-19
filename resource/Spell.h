#ifndef SPELL
#define SPELL
#include "../misc/util.h"

class Spell
{
    private:
        sf::Texture spellTexture;
        sf::Sprite* spriteTab;
        int spriteIndex;
        int maxIndex;
        float moveX;
        float moveY;
        float X,Y;
        int delay;
        int damage;
        int speed;
        int source;
        float* ORIGIN_DIFF_X_DYNAMIC;
        float* ORIGIN_DIFF_Y_DYNAMIC;
        int range;

    public:
        //constructor and destructor
        Spell(Data *dataContainer,int nbSprite,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,float mX,float mY,float bX,float bY,int rotation,int damage,int source,int speed,int range,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC);
        ~Spell();

        //moving functions
        void moving();

        //getters and setters
        sf::Sprite getSpellSprite(){return spriteTab[spriteIndex];};
        float getSpellX(){return X+(*ORIGIN_DIFF_X_DYNAMIC);};
        float getSpellY(){return Y+(*ORIGIN_DIFF_Y_DYNAMIC);};
        float getSpellRealX(){return X;};
        float getSpellRealY(){return Y;};
        int getDamage(){return damage;};
        int getSource(){return source;};
        int getRange(){return range;};
};

#endif
