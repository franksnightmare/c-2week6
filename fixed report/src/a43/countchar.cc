#include <iostream>
#include <cstring>

using namespace std;

bool countChar(string &characterType, char character)
{
    bool retBool;

    if (characterType == "vowel")
        retBool = (string("aeiouAEIOU").find(character) != string::npos);
    else if (characterType == "digit")
        retBool = (string("1234567890").find(character) != string::npos);
    else if (characterType == "hexadecimal")
        retBool = (isxdigit(character));
    else if (characterType == "punctuation")
        retBool = (ispunct(character));
    else
        cout << "Wrong argument, use: vowel, digit, hexadecimal or punctuation";

    return retBool;
}
