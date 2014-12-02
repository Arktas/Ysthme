#ifndef YMAPGENERATOR_H
#define YMAPGENERATOR_H

#include "yMap.h"

class yMapGenerator
{
    public:
        yMapGenerator();
        virtual ~yMapGenerator();

        void initContext();
        yMap* generateNewMap();

    protected:
    private:

        bool m_contextInitialized;
        yMapContext* m_mapContext;
};

#endif // YMAPGENERATOR_H
