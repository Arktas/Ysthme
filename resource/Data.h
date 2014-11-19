#ifndef DATA_RESOURCE
#define DATA_RESOURCE

#include "../misc/util.h"

class Data
{
    private:
        std::map<std::string,sf::Image> dataResourceMap;
    public:
        Data();
        ~Data();
        void load(std::string xmlResourceFile);
        sf::Image getImage(std::string index){return dataResourceMap[index];};

};

#endif // DATA_RESOURCE
