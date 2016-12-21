#include "main.ih"

void printer(SafeQueue &queue)
{
	while (!queue.empty())
	{
		string word = queue.front();
		queue.pop();
		cout << this_thread::get_id() << " printed " << word << '\n';
		this_thread::yield();
	}
	
	cout << this_thread::get_id() << " stopping...\n";
}
