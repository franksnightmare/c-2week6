#include "main.ih"

int main(int argc, char **argv)
{
	if (argc <= 1)
	{
		cerr << "Please supply a folder path.\n";
		return 1;
	}
	
	bool completed = false;
	size_t bytes = 0;
	thread byteCounter(countBytes, 
		std::ref(completed), std::ref(bytes), argv[1]);
	thread progressBar(timeProcess,
		std::ref(completed));
	
	byteCounter.join();
	progressBar.join();
	
	cout << bytes << " bytes\n";
}
