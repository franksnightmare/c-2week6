#include "safequeue.ih"

void SafeQueue::push(string item)
{
	lock_guard<mutex> lock(*d_mutex);
	d_queue.push(item);
}
