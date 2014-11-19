#include "XMLparser.h"

XMLparser::XMLparser()
{
}

XMLparser::~XMLparser()
{
    free(buffer);
}
void XMLparser::parse(std::string file)
{
    std::ifstream xmlFile;
    xmlFile.open(file.c_str(),std::ifstream::binary);
    std::filebuf* xmlFileBuff = xmlFile.rdbuf();
    std::size_t fileSize = xmlFileBuff->pubseekoff(0,xmlFile.end,xmlFile.in);
    xmlFileBuff->pubseekpos(0,xmlFile.in);
    buffer = (char*)malloc(sizeof(char)*(fileSize+1));
    xmlFileBuff->sgetn(buffer,fileSize);
    buffer[fileSize] = '\0';
    rapidxml::xml_document<> doc;
    doc.parse<0>(buffer);
    rapidxml::xml_node<> *pRoot = doc.first_node();
    rapidxml::xml_node<> *pNode = pRoot->first_node("attributes");
    pNode = pNode->first_node("life");
    //rapidxml::xml_attribute<> *pAttr = pNode->first_attribute();
    //std::cout << pAttr->value()[0] << std::endl;

}
