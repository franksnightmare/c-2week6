#include "task.ih"

void Task::countVowel()
{
    string vowel = "vowel";
    int myCount = count_if(begin(), end(),
        [&] (char character)
        {
            countChar(vowel, character);
        }
    );
    cout << "Vowels: " << myCount << "\n";
}
