#ifndef SAFEQUEUE_H
#define SAFEQUEUE_H

#include <mutex>
#include <queue>
#include <string>

class RefProxy
{
	std::mutex *d_mutex;
	std::string &d_string;
	
	public:
		RefProxy(std::mutex *mut, std::string &ref);
		std::string &operator=(RefProxy const &rhs);
		std::string &operator=(std::string const &rhs);
		operator std::string const &() const;
};

class SafeQueue
{
	std::mutex *d_mutex;
	std::queue<std::string> d_queue;
	
	public:
		SafeQueue(std::mutex *mut);
		
		bool empty();
		
		RefProxy front();
		RefProxy back();
		
		void pop();
		void push(std::string item);
};

#endif
