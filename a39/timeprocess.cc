#include "main.ih"

void timeProcess(bool &status)
{
	while (!status)
	{
		cout << '.' << std::flush;
		this_thread::sleep_for(chrono::seconds(1));
	}
	
	cout << std::endl;
}
