#include "safequeue.ih"

void SafeQueue::push(string const &item)
{
	d_mutex.lock();
	d_queue.push(item);
	d_mutex.unlock();
	d_semaphore.notify();
}
