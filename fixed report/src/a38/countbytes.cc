#include "main.ih"

void countBytes(mutex &statusMutex, bool &status, size_t &bytes, string path)
{
	bytes = openFolder(path);
	
	statusMutex.lock();
	status = true;
	statusMutex.unlock();
}
