#include "watch.h"

void watch::endShowTime()
{
    std::time_t endTime = std::chrono::system_clock::to_time_t(d_end);
    std::cout << " Program ends at "<< std::ctime(&endTime)<< '\n';
}
