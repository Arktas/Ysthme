#ifndef XMLPARSER
#define XMLPARSER

#include "rapidxml/rapidxml.hpp"

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <string.h>

typedef struct{
    char* key;
    char* data;
}dataStore;
class XMLparser
{
    private:
        char *buffer;
        std::list<dataStore> contents;
    public:
        XMLparser();
        ~XMLparser();
        void parse(std::string file);
};



#endif // XMLPARSER
