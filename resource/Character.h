#ifndef CHARACTER
#define CHARACTER

#include "../misc/util.h"
#include "Data.h"

class Character{
    protected:
        int maxIndex;
        int spriteIndex;
        float X,Y;
        int Xsize,Ysize;
        int Xmin, Xmax, Ymin, Ymax;
        int life;
        int lifeMax;
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
        int getSpriteIndex(){return spriteIndex;};
        int getIndexAnim(){return indexAnim;};
        int getXmin(){return Xmin;};
        int getYmin(){return Ymin;};
        int getXmax(){return Xmax;};
        int getYmax(){return Ymax;};


};

#endif // CHARACTER
