#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <vector>

class Task: public std::vector<char>
{
    public:
        Task(std::istream &file);
        void countVowel();
        void countDigit();
        void countHexDec();
        void countPunctChar();
};

#endif
