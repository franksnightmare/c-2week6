#include "safequeue.ih"

string const &SafeQueue::RefProxy::operator=(
	std::string const &rhs)
{
	d_string = rhs;
	return d_string;
}
