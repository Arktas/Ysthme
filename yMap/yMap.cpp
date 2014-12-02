#include "yMap.h"
#include "cstring" //memset, memcpy

#define INDEX_XY(x,y,h) (x*h+y)

yMap::yMap(unsigned int width, unsigned int height, unsigned char defaultValue)
{
    m_width = width;
    m_height = height;
    m_data = new unsigned char[m_width*m_height];
    memset(m_data, defaultValue, width*height);
}

yMap::~yMap()
{
    if(m_data == NULL)
        delete [] m_data;
}

unsigned char yMap::getValue(unsigned int x, unsigned int y) const
{
    if(x<0 || y<0 || x>=m_width || y>=m_height)
        return 0;

    if(m_data != NULL)
        return m_data[INDEX_XY(x,y,m_height)];

    return 0;
}

void yMap::setValue(unsigned int x, unsigned int y, unsigned char value)
{
    if(m_data != NULL)
        m_data[INDEX_XY(x,y,m_height)] = value;
}

void yMap::setValues(unsigned char* data)
{
    memcpy(m_data, data, m_width*m_height);
}
