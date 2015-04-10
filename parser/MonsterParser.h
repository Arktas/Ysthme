
#ifndef MONSTER_PARSER
#define MONSTER_PARSER

#include "../misc/rapidxml/rapidxml.hpp"
#include "../misc/variables.h"

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <string.h>

class MonsterParser
{
    private:
        char *buffer;
        std::list<dataStore> contents;
        rapidxml::xml_document<> doc;
    public:
        MonsterParser();
        ~MonsterParser();
        void parse(std::string file);
        int getLife();
        int getAgroRange();
        int getAttackRange();
        int getAttackCooldown();
};



#endif // XMLPARSER
