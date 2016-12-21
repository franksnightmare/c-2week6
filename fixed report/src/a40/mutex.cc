#include "safequeue.ih"

mutex *SafeQueue::mutex()
{
	return &d_mutex;
}
