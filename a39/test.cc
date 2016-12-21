#include "watch.h"

int main()
{
    watch clock;

    clock.startPoint();
    //Code here - main content here
    for (std::size_t ind = 0; ind < 100000000; ++ind)
        ++ind;

    clock.endPoint();

    clock.startShowTime();

    clock.endShowTime();

    clock.timePassed();
}
