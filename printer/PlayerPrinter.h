#ifndef PLAYER_PRINTER
#define PLAYER_PRINTER

#include "../misc/util.h"
#include "../resource/Data.h"
#include "../resource/Player.h"

class PlayerPrinter{
    protected:
        sf::Texture texture;
        sf::Sprite* spriteTab;
        int nbSprite;
        int nbSpriteAnim;
    public:
        //constructor and destructor
        PlayerPrinter(Player* player,Data* dataContainer,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,int nbSprite,int nbSpriteAnim);
        ~PlayerPrinter();
        void refreshPosition(Player* player);
        sf::Sprite getPlayerSprite(Player* player){return spriteTab[(player->getSpriteIndex()*nbSpriteAnim)+player->getIndexAnim()];};


};

#endif // PLAYER_PRINTER
