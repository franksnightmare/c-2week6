#include "task.ih"

void Task::countDigit()
{
	size_t ret = 0;
	for_each(begin(), end(),
		[&] (char c)
		{
			if (string("1234567890").find(c)
				!= string::npos)
				
				++ret;
		}
	);
	cout << "Digits: " << ret << "\n";
}
