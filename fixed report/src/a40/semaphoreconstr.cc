#include "semaphore.ih"

Semaphore::Semaphore(size_t count)
:
	d_counter(count)
{
}
