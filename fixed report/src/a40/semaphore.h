#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include <condition_variable>
#include <mutex>
#include <cstddef>

class Semaphore
{
	std::mutex d_mutex;
	std::condition_variable d_condition;
	std::size_t d_counter = 0;
	
	public:
		Semaphore() = default;
		Semaphore(std::size_t count);
		
		void notify();
		void wait();
};

#endif
