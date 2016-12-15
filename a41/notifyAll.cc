#include "safequeue.ih"

void Semaphore::notify_all()
{
    lock_guard<mutex> lk(*d_mutex);
    if (d_available++ == 0)
        d_condition.notify_all();
}
