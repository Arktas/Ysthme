#include "yMapStream.h"
#include "yMap.h"
#include <cstdio>
#include <cstring>

void fwriteTileLink(const yMapContext::yTileLink* tileLink, FILE* f)
{
    fwrite(&(tileLink->ID), sizeof(unsigned char), 1, f);
    fwrite(&(tileLink->x1), sizeof(int), 1, f);
    fwrite(&(tileLink->y1), sizeof(int), 1, f);
    fwrite(&(tileLink->x2), sizeof(int), 1, f);
    fwrite(&(tileLink->y2), sizeof(int), 1, f);
}

void freadTileLink(yMapContext::yTileLink* tileLinkOut, FILE* f)
{
    fread(&(tileLinkOut->ID), sizeof(unsigned char), 1, f);
    fread(&(tileLinkOut->x1), sizeof(int), 1, f);
    fread(&(tileLinkOut->y1), sizeof(int), 1, f);
    fread(&(tileLinkOut->x2), sizeof(int), 1, f);
    fread(&(tileLinkOut->y2), sizeof(int), 1, f);
}

yMap* yMapStream::loadFromFile(const char* filename, bool binary, bool compressed)
{
    // 'binary' & 'compressed' not used

    yMap* map = NULL;

    FILE* f = fopen(filename, "rb");
    if(f != NULL)
    {

        unsigned int width, height, tileLinkCount;
        char tilesetName[512];

        fread(&width, sizeof(unsigned int), 1, f);
        fread(&height, sizeof(unsigned int), 1, f);
        fread(&tileLinkCount, sizeof(unsigned int), 1, f);
        fread(tilesetName, 1, 512, f);

		yMapContext* outContext = new yMapContext();
        outContext->clear();
        outContext->setTileset(tilesetName);

        for(unsigned int i=0; i<tileLinkCount;++i)
        {
            yMapContext::yTileLink tileLink;
            // fread(&tileLink, sizeof(tileLink), 1, f);
            freadTileLink(&tileLink, f);
            outContext->addLink(tileLink);
        }

        map = new yMap(width, height);
        unsigned char* data = new unsigned char[width*height];
        fread(data, sizeof(unsigned char), width*height, f);
        map->setValues(data);
        delete [] data;

		map->setContext(outContext);

        fclose(f);
    }

    return map;
}

void yMapStream::saveToFile(const char* filename, const yMap& map, bool binary, bool compressed)
{
	yMapContext* context = map.getContext();

    // 'binary' & 'compressed' not used

    FILE* f = fopen(filename, "wb");

    unsigned int buff;

    buff = map.getWidth();
    fwrite(&(buff), sizeof(unsigned int), 1, f);
    buff = map.getHeight();
    fwrite(&(buff), sizeof(unsigned int), 1, f);
    buff = context->getTileLinkCount();
    fwrite(&(buff), sizeof(unsigned int), 1, f);

    char filenameBuff[512];
    strcpy(filenameBuff, context->getTilesetFilename());
    fwrite(filenameBuff, 1, 512, f);

    for(unsigned int i=0; i<context->getTileLinkCount();++i)
        {
            fwriteTileLink(context->getTileLink(i), f);
        }
        //fwrite(context->getTileLink(i), sizeof(yMapContext::yTileLink), 1, f);

    fwrite(map.getValues(), sizeof(char), map.getWidth()*map.getHeight(), f);

    fclose(f);
}
