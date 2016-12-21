#include "safequeue.ih"

bool SafeQueue::empty()
{
	return d_queue.empty();
}
