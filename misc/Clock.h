#ifndef CLOCK
#define CLOCK

#include "windows.h"

class Clock
{
    private:
        LARGE_INTEGER frequency;
        LARGE_INTEGER startTime,stopTime;
        double elapsedTime;
    public:
        Clock();
        ~Clock();
        void start();
        void stop();
        double difftime();
};

#endif // CLOCKS
