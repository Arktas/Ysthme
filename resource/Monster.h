#ifndef MONSTER_CLASS
#define MONSTER_CLASS

#include "../misc/util.h"
#include "../manager/ItemManager.h"
#include "../parser/MonsterParser.h"
#include "Character.h"
class Character;

class Monster : public Character
{
    private:
        float AgroRadius;
        bool agro;
        int attackRange;
        bool canAttack;
        bool get_hit;
        int attackCooldown;
        int lifeMax;
        Clock *clock;
        bool moove;
        ItemManager* itemManager;
        MonsterParser* monsterParser;
    public:
        //constructor and destructor
        Monster(int monsterId,ItemManager* itemManager,Data* dataContainer,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,int x,int y,float agroradius,int life,int attackRange,int nbSprite,int nbSpriteAnim,float* ORIGIN_DIFF_X_DYNAMIC,float* ORIGIN_DIFF_Y_DYNAMIC);
        ~Monster();

        //moving functions
        void doRotation(int angle);
        void moving(float x,float y);

        //appearance
        void changeTexture(int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize);

        //context functions
        void agroChange(int pX,int pY);
        bool getAgro(){return agro;};
        bool getMoove(){return moove;};
        bool hitbox(int Xmin_test,int Xmax_test,int Ymin_test,int Ymax_test);
        void hit(int damage);
        bool alive();
        void idle(){indexAnim = 6;};
        void cast(){indexAnim = 9;};
        void drop();
        //getters and setters
        int getMonsterRotation(){return rotation;/*spriteTab[spriteIndex].getRotation();*/};
        float getMonsterX(){return (*ORIGIN_DIFF_X_DYNAMIC)+X;};
        float getMonsterY(){return (*ORIGIN_DIFF_Y_DYNAMIC)+Y;};
        float getMonsterRealX(){return X;};
        float getMonsterRealY(){return Y;};
        int getLife(){return life;};
        int getMaxLife(){return lifeMax;};
        bool getCanAttack(){return canAttack;};
        void setMonsterPosition();
};

#endif
