#include "tester.h"
#include <iostream>
#include <chrono>
#include <ctime>

int main(int argc, char **argv)
{
	// Time block
	chrono::time_point<chrono::system_clock> start,
		end;
	
	start = chrono::system_clock::now();
	
	printFolderSize("./testfolder");
	
	end = chrono::system_clock::now();
	
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
