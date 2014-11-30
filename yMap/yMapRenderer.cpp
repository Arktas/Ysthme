#include "yMapRenderer.h"

#include <cstdio>

// private function
unsigned char extractTileType(unsigned char code)
{
    // trunc
    return code/16;
}

unsigned char extractPatternID(unsigned char code)
{
    code -= extractTileType(code)*16;
    return code;
}

void extractTileTypeAndPatternID(unsigned char code,unsigned char& tileType, unsigned char& patternID)
{
    tileType = extractTileType(code);
    patternID = code - tileType*16;
}
// ----------------


yMapRenderer::yMapRenderer()
{
    setMap(NULL);
	setFieldOfView(sf::IntRect(0,0,600,400));
	setPosition(sf::Vector2i(0,0));
	setScale(sf::Vector2f(1.f,1.f));
}

yMapRenderer::yMapRenderer(const yMap* map, const sf::IntRect& fieldOfView)
{
	setMap(map);
	setFieldOfView(fieldOfView);
	setPosition(sf::Vector2i(0,0));
	setScale(sf::Vector2f(1.f,1.f));
}

yMapRenderer::~yMapRenderer()
{
    //dtor
}

void yMapRenderer::setMap(const yMap* map)
{
	m_map = map;
	tileset.loadFromFile(map->getContext()->getTilesetFilename());
	// tileset.setSmooth(true);
}

void yMapRenderer::setFieldOfView(const sf::IntRect& fieldOfView)
{
	m_fieldOfView = fieldOfView;
}

void yMapRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Sprite tile;
	tile.setTexture(tileset);
	for(int x=m_fieldOfView.left-2; x<m_fieldOfView.left+m_fieldOfView.width+2; ++x)
	for(int y=m_fieldOfView.top-2; y<m_fieldOfView.top+m_fieldOfView.height+2; ++y)
	{
	    if(x<0 || y<0 || x>=(int)m_map->getWidth() || y>=(int)m_map->getHeight())
            continue;

		tile.setPosition((x*32+m_position.x)*m_scale.x, (y*32+m_position.y)*m_scale.y);
		tile.setScale(m_scale);
		unsigned char tileID = m_map->getValue(x,y);

        unsigned char patternID, tileType;
        extractTileTypeAndPatternID(tileID, tileType, patternID);

        unsigned char underTileID = tileType-1;
        if(underTileID >= 0 && patternID != 0b1111)
        {
            underTileID *= 16;
            underTileID += 0b1111;
            const yMapContext::yTileLink* underTilelink = m_map->getContext()->getTileLink(underTileID);
            tile.setTextureRect(sf::IntRect(underTilelink->x1, underTilelink->y1, 32, 32));
            target.draw(tile);
        }

		const yMapContext::yTileLink* tilelink = m_map->getContext()->getTileLink(tileID);
		tile.setTextureRect(sf::IntRect(tilelink->x1, tilelink->y1, 32, 32));
		target.draw(tile);
	}
}
