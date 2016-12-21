#include "safequeue.ih"

SafeQueue::RefProxy::operator string const &() const
{
	return d_string;
}
