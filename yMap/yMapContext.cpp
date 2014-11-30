#include "yMapContext.h"
#include <cstring>

yMapContext::yMapContext()
{
    //ctor
}

yMapContext::~yMapContext()
{
    //dtor
}

void yMapContext::clear()
{
    m_tileLinks.clear();
}

void yMapContext::addLink(yMapContext::yTileLink tileLink)
{
    m_tileLinks.push_back(tileLink);
}

const yMapContext::yTileLink* yMapContext::getTileLink(unsigned char ID) const
{
    return &(m_tileLinks[ID]);
}

void yMapContext::setTileset(const char* tilesetFilename)
{
    strcpy(m_tilesetFilename, tilesetFilename);
}
