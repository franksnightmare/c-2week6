#include "safequeue.ih"

Semaphore::Semaphore(size_t aval)
:
    d_available(aval)
{
}
