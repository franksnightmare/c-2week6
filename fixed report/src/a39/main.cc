#include "main.ih"
#include <iostream>
#include <chrono>
#include <ctime>

int main(int argc, char **argv)
{
	// Time block
	chrono::time_point<chrono::system_clock> start,
		end;
	
	start = chrono::system_clock::now();
	
	if (argc <= 1)
	{
		cerr << "Please supply a folder path.\n";
		return 0;
	}
	
	mutex statusMutex;
	bool completed = false;
	size_t bytes = 0;
	thread byteCounter(countBytes,
		std::ref(statusMutex), std::ref(completed),
		std::ref(bytes), argv[1]);
	thread progressBar(timeProcess,
		std::ref(statusMutex), std::ref(completed));
	
	byteCounter.join();
	
	end = chrono::system_clock::now();
	progressBar.join();
	cout << bytes << " bytes\n";
	
	// Print block
	
	time_t startTime =
		chrono::system_clock::to_time_t(start);
	cout << " Program starts at "
		<< ctime(&startTime) << '\n';

	time_t endTime =
		chrono::system_clock::to_time_t(end);
	cout << " Program ends at "
		<< ctime(&endTime) << '\n';

	chrono::duration<double> totalTime =
		end - start;
	cout << "Total time passed "
		<< totalTime.count() << '\n';
}
