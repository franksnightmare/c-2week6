#ifndef MAIN_H
#define MAIN_H

#include "safequeue.h"
#include <iostream>

void printer(SafeQueue &queue, std::mutex *queueLock);

#endif
