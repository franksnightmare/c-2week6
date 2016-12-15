#include "safequeue.ih"

RefProxy SafeQueue::front()
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
	return RefProxy(d_mutex, d_queue.front());
}
