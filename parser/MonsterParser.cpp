
#include "MonsterParser.h"

MonsterParser::MonsterParser()
{
}

MonsterParser::~MonsterParser()
{
}
void MonsterParser::parse(std::string file)
{
    std::ifstream xmlFile;
    xmlFile.open(file.c_str(),std::ifstream::in);
    std::filebuf* xmlFileBuff = xmlFile.rdbuf();
    xmlFileBuff->pubseekpos(0,xmlFile.in);
    std::size_t fileSize = xmlFileBuff->pubseekoff(0,xmlFile.end,xmlFile.in);
    xmlFileBuff->pubseekpos(0,xmlFile.in);
    buffer = (char*)malloc(sizeof(char)*(fileSize+1));
    int indexEnd = xmlFileBuff->sgetn(buffer,fileSize);
    buffer[indexEnd] = '\0';
    doc.parse<0>(buffer);

    //std::cout << pNode->value() << std::endl;
    free(buffer);
    xmlFile.close();
    xmlFileBuff->close();

}

int MonsterParser::getLife()
{
    rapidxml::xml_node<> *pRoot = doc.first_node();
    rapidxml::xml_node<> *pNode = pRoot->first_node("attributes");
    pNode = pNode->first_node("life");
    return atoi(pNode->value());
}

int MonsterParser::getAgroRange()
{
    rapidxml::xml_node<> *pRoot = doc.first_node();
    rapidxml::xml_node<> *pNode = pRoot->first_node("attack");
    pNode = pNode->first_node("agrorange");
    return atoi(pNode->value());
}

int MonsterParser::getAttackRange()
{
    rapidxml::xml_node<> *pRoot = doc.first_node();
    rapidxml::xml_node<> *pNode = pRoot->first_node("attack");
    pNode = pNode->first_node("attackrange");
    return atoi(pNode->value());
}

int MonsterParser::getAttackCooldown()
{
    rapidxml::xml_node<> *pRoot = doc.first_node();
    rapidxml::xml_node<> *pNode = pRoot->first_node("attack");
    pNode = pNode->first_node("attackcooldown");
    return atoi(pNode->value());
}


