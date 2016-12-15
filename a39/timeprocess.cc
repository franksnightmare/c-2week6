#include "main.ih"

void timeProcess(mutex &statusMutex, bool &status)
{
	bool localStatus = false;
	while (!localStatus)
	{
		cout << '.' << std::flush;
		
		statusMutex.lock();
		localStatus = status;
		statusMutex.unlock();
		
		this_thread::sleep_for(chrono::seconds(1));
	}
	
	cout << std::endl;
}
