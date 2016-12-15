#include "task.ih"

void Task::countVowel()
{
    size_t ret = 0;
    for_each(begin(), end(),
        [&] (char c)
        {
            if (string("aeiouAEIOU").find(c) != string::npos)
                ++ret;
        }
    );
    cout << "Vowels: " << ret << "\n";
}
