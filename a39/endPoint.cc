#include "watch.h"

void watch::endPoint()
{
    d_end = std::chrono::system_clock::now();
}
