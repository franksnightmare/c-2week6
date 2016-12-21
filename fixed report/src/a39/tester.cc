#include "tester.ih"

void printFolderSize(string path)
{	
	bool completed = false;
	size_t bytes = 0;
	thread byteCounter(countBytes, 
		std::ref(completed), std::ref(bytes), path);
	thread progressBar(timeProcess,
		std::ref(completed));
	progressBar.detach();
	
	byteCounter.join();
	
	cout << '\n' << bytes << " bytes\n";
}
