#include "safequeue.ih"

SafeQueue::RefProxy::RefProxy(SafeQueue *queue,
	string &ref)
:
	d_queue(queue),
	d_string(ref)
{
	d_queue->mutex()->lock();
}
