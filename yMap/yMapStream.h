#ifndef YMAPLOADER_H
#define YMAPLOADER_H

#include "yMap.h"

namespace yMapStream
{
    yMap* loadFromFile(const char* filename, bool binary = true, bool compressed = false);

    void saveToFile(const char* filename, const yMap& map, bool binary = true, bool compressed = false);
};

#endif // YMAPLOADER_H
