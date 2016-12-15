#include "main.ih"
#include <iostream>
#include <chrono>
#include <ctime>

int main(int argc, char **argv)
{
	// Time block
    std::chrono::time_point<std::chrono::system_clock> start, end;
	
    start = std::chrono::system_clock::now();
    
    if (argc <= 1)
	{
		cerr << "Please supply a folder path.\n";
		return 0;
	}
	
	mutex statusMutex;
	bool completed = false;
	size_t bytes = 0;
	thread byteCounter(countBytes, std::ref(statusMutex), std::ref(completed), std::ref(bytes), argv[1]);
	thread progressBar(timeProcess, std::ref(statusMutex), std::ref(completed));
	
	byteCounter.join();
    
    end = std::chrono::system_clock::now();
	progressBar.join();
	cout << bytes << " bytes\n";
	
	// Print block
	
    std::time_t startTime = std::chrono::system_clock::to_time_t(start);
    std::cout << " Program starts at "<< std::ctime(&startTime)<< '\n';

    std::time_t endTime = std::chrono::system_clock::to_time_t(end);
    std::cout << " Program ends at "<< std::ctime(&endTime)<< '\n';

    std::chrono::duration<double> totalTime = end - start;
    std::cout << "Total time passed " << totalTime.count() << '\n';

}
