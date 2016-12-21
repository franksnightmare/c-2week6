#include "task.ih"
#include <thread>
#include <chrono>

int main(int argc, char **argv)
{
    using namespace std::chrono;
    time_point<system_clock> start;
    start = system_clock::now();

    Task task(cin);

    if (argc >=2) //perform threads in sequence
    {
        thread vowelThread(&Task::countVowel, task);
        vowelThread.join();
        thread digitThread(&Task::countDigit, task);
        digitThread.join();
        thread hexdecThread(&Task::countHexDec, task);
        hexdecThread.join();
        thread punctThread(&Task::countPunctChar, task);
        punctThread.join();
    }
    else //perform threads in parallel
    {
        thread vowelThread(&Task::countVowel, task);
        thread digitThread(&Task::countDigit, task);
        thread hexdecThread(&Task::countHexDec, task);
        thread punctThread(&Task::countPunctChar, task);
        vowelThread.join();
        digitThread.join();
        hexdecThread.join();
        punctThread.join();
    }
    
    time_point<system_clock> end;
    end = system_clock::now();
    duration<double> program_runtime = end-start;
    cout << "Program runtime: " << program_runtime.count() << "s \n";
}
