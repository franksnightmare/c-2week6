#include "main.ih"

void watch::startShowTime()
{
    std::time_t startTime =
        std::chrono::system_clock::to_time_t(d_start);
    std::cout << " Program starts at "
        << std::ctime(&startTime)<< '\n';
}
