#ifndef SAFEQUEUE_H
#define SAFEQUEUE_H

#include <mutex>
#include <queue>
#include <string>
#include <condition_variable>

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

class Semaphore
{
	std::mutex *d_mutex;
	std::condition_variable d_condition;
	std::size_t d_available;

	public:
		Semaphore(std::size_t aval);
		void wait();
		void notify_all();
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
