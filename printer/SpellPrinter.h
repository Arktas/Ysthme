#ifndef SPELL_PRINTER
#define SPELL_PRINTER

#include "../misc/util.h"
#include "../resource/Data.h"
#include "../resource/Spell.h"

class SpellPrinter{
    protected:
        sf::Texture texture;
        sf::Sprite* spriteTab;
        int nbSprite;
    public:
        //constructor and destructor
        SpellPrinter(Data* dataContainer,std::string textureFile,int XTextureBegin,int YTextureBegin,int XSpriteSize,int YSpriteSize,int nbSprite);
        ~SpellPrinter();
        void refreshPosition(Spell* spell);
        sf::Sprite getSpellSprite(Spell* spell){refreshPosition(spell);return spriteTab[spell->getSpriteIndex()];};


};

#endif // MONSTER_PRINTER

