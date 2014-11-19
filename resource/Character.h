#ifndef CHARACTER
#define CHARACTER

#include "../misc/util.h"
#include "Data.h"

class Character{
    protected:
        sf::Texture texture;
        sf::Sprite* spriteTab;
        int maxIndex;
        int spriteIndex;
        float X,Y;
        int Xmin, Xmax, Ymin, Ymax;
        int life;
        int nbSprite;
        int indexAnim;
        int indexAnimWalk;
        int indexAnimSpell;
        int indexAnimIdle;
        int nbSpriteAnim;
        int delay;
        int rotation;
        float* ORIGIN_DIFF_X_DYNAMIC;
        float* ORIGIN_DIFF_Y_DYNAMIC;
    public:
        //constructor and destructor
        Character(Data* dataContainer,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,int x,int y,int life,int nbSprite,int nbSpriteAnim,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC);
        ~Character();


};

#endif // CHARACTER
