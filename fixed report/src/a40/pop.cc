#include "safequeue.ih"

void SafeQueue::pop()
{
	d_mutex.lock();
	while(d_queue.size() == 0)
	{
		d_mutex.unlock();
		d_semaphore.wait();
		d_mutex.lock();
	}
	d_queue.pop();
	d_mutex.unlock();
}
