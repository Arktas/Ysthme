#ifndef YMAPGENERATOR_PRIV_H
#define YMAPGENERATOR_PRIV_H

#include "perlin/Perlin.h"

#define NB_TILE_TYPE 7

namespace yMapGenerator_priv
{
    struct t_pos
    {
        int x;
        int y;
    };

    enum e_tilePattern
    {
        tile_none = 0b0000,
        tile_all = 0b1111,
        tile_left = 0b1000,
        tile_right = 0b0100,
        tile_top = 0b0010,
        tile_bot = 0b0001,
        tile_left_top = 0b1010,
        tile_left_bot = 0b1001,
        tile_left_right = 0b1100,
        tile_right_top = 0b0110,
        tile_right_bot = 0b0101,
        tile_top_bot = 0b0011,
        tile_left_right_top = 0b1110,
        tile_left_right_bot = 0b1101,
        tile_left_top_bot = 0b1011,
        tile_right_top_bot = 0b0111
    };

    enum e_tileType
    {
        tile_rock = 0,
        tile_dirt_dark = 1,
        tile_dirt_light = 2,
        tile_grass_small_dark = 3,
        tile_grass_small_light = 4,
        tile_grass_big_dark = 5,
        tile_grass_big_light = 6,
        tile_water = 7
    };

    void checkTileType(unsigned char& value);

    unsigned char getPatternID(int center, int left, int right, int top, int bot);

    t_pos patternIdToPos(unsigned char patternID);
    t_pos tileTypeToPos(unsigned char tileType);
};

#endif // YMAPGENERATOR_PRIV_H
