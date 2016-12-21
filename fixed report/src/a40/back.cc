#include "safequeue.ih"

SafeQueue::RefProxy SafeQueue::back()
{
	return RefProxy(this, d_queue.back());
}
