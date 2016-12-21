#ifndef WATCH_H
#define WATCH_H

#include <iostream>
#include <chrono>
#include <ctime>

class watch
{
    std::chrono::time_point<std::chrono::system_clock> d_start, d_end;
    public:
        void startPoint();
        void endPoint();
        void startShowTime();
        void endShowTime();
        void timePassed();
};

#endif
