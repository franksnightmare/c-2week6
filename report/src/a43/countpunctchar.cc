#include "task.ih"

void Task::countPunctChar()
{
    size_t ret = 0;
    for_each(begin(), end(),
        [&] (char c)
        {
            if (ispunct(c))
                ++ret;
        }
    );
    cout << "Punctuation characters: " << ret << "\n";
}
