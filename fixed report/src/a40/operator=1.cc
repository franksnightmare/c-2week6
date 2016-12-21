#include "safequeue.ih"

string &RefProxy::operator=(std::string const &rhs)
{
	lock_guard<mutex> lock(*d_mutex);
	return d_string = rhs;
}
