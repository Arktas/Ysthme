#include "yMapGenerator_priv.h"

void yMapGenerator_priv::checkTileType(unsigned char& value)
{
    if(value == 7)
        value = 6;
}

/*int getValue(t_perlinMap& map, int x, int y)
{
    if(x<0 || y<0 || x>=map.width || y>=map.height)
        return 0;

    return map.data[INDEX_XY(x,y,map.width, map.height)];
}*/

unsigned char yMapGenerator_priv::getPatternID(int center, int left, int right, int top, int bot)
{
    unsigned char bleft = 0, bright = 0, btop = 0, bbot = 0;

    if(center <= left) bleft=1;
    if(center <= right) bright=1;
    if(center <= top) btop=1;
    if(center <= bot) bbot=1;

    unsigned char result = (bleft<<3)|(bright<<2)|(btop<<1)|(bbot<<0);
    return result;
}

yMapGenerator_priv::t_pos yMapGenerator_priv::patternIdToPos(unsigned char index)
{
    yMapGenerator_priv::t_pos position;

    switch(index)
    {
        case tile_none:
            position.x = 3;
            position.y = 1;
        return position;
        case tile_all:
            position.x = 1;
            position.y = 1;
        return position;
        case tile_left:
            position.x = 5;
            position.y = 0;
        return position;
        case tile_left_top:
            position.x = 2;
            position.y = 2;
        return position;
        case tile_left_bot:
            position.x = 2;
            position.y = 0;
        return position;
        case tile_right_top:
            position.x = 0;
            position.y = 2;
        return position;
        case tile_right_bot:
            position.x = 0;
            position.y = 0;
        return position;
        case tile_left_right:
            position.x = 4;
            position.y = 0;
        return position;
        case tile_left_right_top:
            position.x = 1;
            position.y = 2;
        return position;
        case tile_left_right_bot:
            position.x = 1;
            position.y = 0;
        return position;
        case tile_left_top_bot:
            position.x = 2;
            position.y = 1;
        return position;
        case tile_right_top_bot:
            position.x = 0;
            position.y = 1;
        return position;
        case tile_right:
            position.x = 3;
            position.y = 0;
        return position;
        case tile_top:
            position.x = 6;
            position.y = 2;
        return position;
        case tile_bot:
            position.x = 6;
            position.y = 0;
        return position;
        case tile_top_bot:
            position.x = 6;
            position.y = 1;
        return position;
        default:
        break;
    }

    return position;
}

yMapGenerator_priv::t_pos yMapGenerator_priv::tileTypeToPos(unsigned char tileType)
{
    yMapGenerator_priv::t_pos position;

    switch(tileType)
    {
        case tile_rock:
            position.x = 10;
            position.y = 0;
            break;
        case tile_dirt_dark:
            position.x = 0;
            position.y = 15;
            break;
        case tile_dirt_light:
            position.x = 0;
            position.y = 6;
            break;
        case tile_grass_small_dark:
            position.x = 0;
            position.y = 12;
            break;
        case tile_grass_small_light:
            position.x = 0;
            position.y = 3;
            break;
        case tile_grass_big_dark:
            position.x = 0;
            position.y = 0;
            break;
        case tile_grass_big_light:
            position.x = 0;
            position.y = 9;
            break;
        case tile_water:
            position.x = 0;
            position.y = 18;
            break;
        default:
            position.x = 0;
            position.y = 0;
            break;
    }

    return position;
}
