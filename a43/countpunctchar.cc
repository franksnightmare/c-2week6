#include "task.ih"

void Task::countPunctChar()
{
    string punctuation = "punctuation";
    int myCount = count_if(begin(), end(),
        [&] (char character)
        {
            return countChar(punctuation, character);
        }
    );
    cout << "Punctuation characters: " << myCount << "\n";
}
