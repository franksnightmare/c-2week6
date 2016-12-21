#include "task.ih"

void Task::countDigit()
{
    string digit = "digit";
    int myCount = count_if(begin(), end(),
        [&] (char character)
        {
            return countChar(digit, character);
        }
    );
    cout << "Digits: " << myCount << "\n";
}
