#include "safequeue.ih"

SafeQueue::RefProxy SafeQueue::front()
{
	return RefProxy(this, d_queue.front());
}
