#include "main.ih"

void printer(SafeQueue &queue, mutex *queueLock)
{
	bool status = true;
	while (status)
	{
		string word = queue.front();
		queue.pop();
		cout << word << '\n';

		status = !queue.empty();
	}
}
