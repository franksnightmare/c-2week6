#include "task.ih"

void Task::countHexDec()
{
    string hexadecimal = "hexadecimal";
    int myCount = count_if(begin(), end(),
        [&] (char character)
        {
            countChar(hexadecimal, character);
        }
    );
    cout << "Hexadecimals: " << myCount << "\n";
}
