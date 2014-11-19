#include "Clock.h"

Clock::Clock()
{
}

Clock::~Clock()
{
}

void Clock::start()
{
    QueryPerformanceCounter(&startTime);
}
void Clock::stop()
{
    QueryPerformanceCounter(&stopTime);
}

double Clock::difftime()
{
    QueryPerformanceFrequency(&frequency);
    return ((stopTime.QuadPart - startTime.QuadPart)*1000.0/frequency.QuadPart);
}
