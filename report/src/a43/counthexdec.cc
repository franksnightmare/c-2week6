#include "task.ih"

void Task::countHexDec()
{
    size_t ret = 0;
    for_each(begin(), end(),
        [&] (char c)
        {
            if (isxdigit(c))
                ++ret;
        }
    );
    cout << "Hexadecimals: " << ret << "\n";
}
