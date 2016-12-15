#include "safequeue.ih"

RefProxy::operator string const &() const
{
	lock_guard<mutex> lock(*d_mutex);
	return d_string;
}
