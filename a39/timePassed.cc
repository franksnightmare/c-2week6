#include "watch.h"

void watch::timePassed()
{
    std::chrono::duration<double> totalTime = d_end - d_start;
    std::cout << "Total time passed " << totalTime.count() << '\n';
}
