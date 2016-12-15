#include "safequeue.ih"

void SafeQueue::pop()
{
	lock_guard<mutex> lock(*d_mutex);
	/*
	while (true)
	{
		filled.wait();
		string word = d_queue.front();
		d_queue.pop();
		available.notify_all();
	}
	*/
	d_queue.pop();
}
