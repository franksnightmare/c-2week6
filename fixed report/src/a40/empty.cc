#include "safequeue.ih"

bool SafeQueue::empty()
{
	lock_guard<mutex> lock(*d_mutex);
	return d_queue.empty();
}
