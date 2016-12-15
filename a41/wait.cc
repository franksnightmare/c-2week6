#include "safequeue.ih"

void Semaphore::wait()
{
    unique_lock<mutex> lk(*d_mutex);
    while (d_available == 0)
        d_condition.wait(lk);

    --d_available;
}
