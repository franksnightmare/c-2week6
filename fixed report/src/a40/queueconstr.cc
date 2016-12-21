#include "safequeue.ih"

SafeQueue::SafeQueue(mutex *mut)
:
	d_mutex(mut)
{
}
