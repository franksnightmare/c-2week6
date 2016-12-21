#ifndef SAFEQUEUE_H
#define SAFEQUEUE_H

#include "semaphore.h"
#include <queue>
#include <string>

class SafeQueue
{
	Semaphore d_semaphore;
	std::mutex d_mutex;
	std::queue<std::string> d_queue;
	
	// The RefProxy locks the mutex at creation
	// and unlocks it at destruction.
	class RefProxy
	{
		SafeQueue *d_queue;
		std::string &d_string;
		
		public:
			RefProxy(SafeQueue *queue, std::string &ref);
			~RefProxy();
			
			RefProxy &operator=(
				RefProxy const &rhs) = delete;
			
			std::string const &operator=(
				std::string const &rhs);
			operator std::string const &() const;
	};
	
	std::mutex *mutex();
	
	public:
		bool empty();
		
		RefProxy front();
		RefProxy back();
		
		void pop();
		void push(std::string const &item);
};

#endif
