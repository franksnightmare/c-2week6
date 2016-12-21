#include "safequeue.ih"

SafeQueue::RefProxy::~RefProxy()
{
	d_queue->mutex()->unlock();
}
