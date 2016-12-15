#include "safequeue.ih"

string &RefProxy::operator=(RefProxy const &rhs)
{
	lock_guard<mutex> lock(*d_mutex);
	return d_string = rhs.d_string;
}
