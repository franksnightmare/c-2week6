#include <iostream>
#include <chrono>
#include <ctime>

int main()
{
    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
    //Code here - main content here
    end = std::chrono::system_clock::now();

    std::time_t startTime = std::chrono::system_clock::to_time_t(start);
    std::cout << " Program starts at "<< std::ctime(&startTime)<< '\n';

    std::time_t endTime = std::chrono::system_clock::to_time_t(end);
    std::cout << " Program ends at "<< std::ctime(&endTime)<< '\n';

    std::chrono::duration<double> totalTime = end - start;
    std::cout << "Total time passed " << totalTime.count() << '\n';

}
