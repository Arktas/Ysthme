#ifndef HITBOX
#define HITBOX

#include "util.h"
//#include "../resource/Item.h"
//#include "../resource/Monster.h"
//#include "../resource/Player.h"
//#include "../resource/Spell.h"

typedef struct
{
    int Xmin;
    int Ymin;
    int Xmax;
    int Ymax;
    int type;
}Info_position;

class Hitbox
{
    private:
        std::list<Info_position> info_list;
        std::list<Info_position> info_list_temp;
        //std::list<Monster*> monster_list;
        //std::list<Player*> player_list;
        //std::list<Item*> Item_list;
        //std::list<Spell*> Spell_list;
    public:
        Hitbox();
        ~Hitbox();
        int check(int Xmin,int Ymin,int Xmax, int Ymax, int type);
        void save(int Xmin,int Ymin,int Xmax, int Ymax, int type);
       // void synchSpell(Spell* spell);
       //  void synchPlayer(Player* player);
       // void synchItem(Item* item);
       // void synchMonster(Monster* monster);
        void reset();
};

#endif // C
