#include "safequeue.ih"

RefProxy SafeQueue::front()
{
	lock_guard<mutex> lock(*d_mutex);
	return RefProxy(d_mutex, d_queue.front());
}
