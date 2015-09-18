#ifndef DATA_RESOURCE
#define DATA_RESOURCE

#include "../misc/util.h"
#include "../parser/MonsterParser.h"
class Data
{
    private:
        std::map<std::string,MonsterParser*> dataInfoMap;
        std::map<std::string,sf::Image> dataResourceMap;
    public:
        Data();
        ~Data();
        void load(std::string xmlResourceFile);
        sf::Image getImage(std::string index){return dataResourceMap[index];};
        MonsterParser* getInfo(std::string id);

};

#endif // DATA_RESOURCE
