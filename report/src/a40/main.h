#ifndef MAIN_H
#define MAIN_H

#include "safequeue.h"

void printer(SafeQueue &queue, std::mutex *queueLock);

#endif
