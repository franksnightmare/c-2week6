#include "safequeue.ih"

void SafeQueue::pop()
{
	lock_guard<mutex> lock(*d_mutex);
	d_queue.pop();
}
