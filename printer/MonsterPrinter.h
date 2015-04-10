#ifndef MONSTER_PRINTER
#define MONSTER_PRINTER

#include "../misc/util.h"
#include "../resource/Data.h"
#include "../resource/Monster.h"

class MonsterPrinter{
    protected:
        sf::Texture texture;
        sf::Sprite* spriteTab;
        int nbSprite;
        int nbSpriteAnim;
    public:
        //constructor and destructor
        MonsterPrinter(Data* dataContainer,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,int nbSprite,int nbSpriteAnim);
        ~MonsterPrinter();
        void refreshPosition(Monster* monster);
        sf::Sprite getMonsterSprite(Monster* monster){refreshPosition(monster);return spriteTab[(monster->getSpriteIndex()*nbSpriteAnim)+monster->getIndexAnim()];};


};

#endif // MONSTER_PRINTER
