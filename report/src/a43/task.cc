#include "task.ih"

Task::Task(std::istream &file)
{
	copy(istream_iterator<char>(file),
		istream_iterator<char>(),
		back_inserter(*this));
}
