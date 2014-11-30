#include "yMapGenerator.h"

#include "yMapGenerator_priv.h"

using namespace yMapGenerator_priv;

yMapGenerator::yMapGenerator()
{
    m_contextInitialized = false;
}

yMapGenerator::~yMapGenerator()
{
}

void yMapGenerator::initContext()
{
    /// Create context
    m_mapContext = new yMapContext();
    m_mapContext->clear();
    m_mapContext->setTileset("tileset-test.png");
    for(unsigned char tiletype=0; tiletype<7; ++tiletype)
    {
        for(unsigned char patternID=0; patternID<16; ++patternID)
        {
            yMapContext::yTileLink tilelink;
            tilelink.ID = (unsigned char)tiletype*16 + (unsigned char)patternID;

            t_pos position = patternIdToPos(patternID);
            t_pos tileTypePos = tileTypeToPos(tiletype);

            tilelink.x1 = (position.x + tileTypePos.x)*32;
            tilelink.y1 = (position.y + tileTypePos.y)*32;
            tilelink.x2 = tilelink.x1 + 32;
            tilelink.y2 = tilelink.y1 + 32;

            m_mapContext->addLink(tilelink);
        }
    }

    m_contextInitialized = true;
}

yMap* yMapGenerator::generateNewMap()
{

    if(m_contextInitialized == false)
        initContext();

    /// Perlin
    Perlin perlinGen(1024, 1024, 0, 255);
    perlinGen.generateSeedMap();
    perlinGen.smoothSeedMap();
    for(int i=0; i<PERLIN_OCTAVE_COUNT; ++i)
        perlinGen.generateOctaveMap(i);
    perlinGen.compileResult();

    /// converting
    t_perlinMap perlinMap = perlinGen.getResult();
    yMap map(perlinMap.width, perlinMap.height);
    float ratio = (float)NB_TILE_TYPE/256.f;
    for(int x=0; x<perlinMap.width; ++x)
    for(int y=0; y<perlinMap.height; ++y)
    {
        float value = perlinMap.data[INDEX_XY(x,y,perlinMap.width, perlinMap.height)];
        unsigned char cval = (unsigned char)(value*ratio);
        checkTileType(cval);
        map.setValue(x,y,cval);
    }

    /// Tiling
    yMap* resultmap = new yMap(perlinMap.width, perlinMap.height);
    resultmap->setContext(m_mapContext);
    for(int x=0; x<perlinMap.width; ++x)
    for(int y=0; y<perlinMap.height; ++y)
    {
        unsigned char patternID = getPatternID(map.getValue(x,y),
                                  map.getValue(x-1,y),
                                   map.getValue(x+1,y),
                                   map.getValue(x,y-1),
                                   map.getValue(x,y+1));

        unsigned char value = map.getValue(x,y);
        unsigned char vcode = value*16 + patternID;

        resultmap->setValue(x, y, vcode);
    }

    return resultmap;
}
