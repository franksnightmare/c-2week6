#include "safequeue.ih"

RefProxy::RefProxy(mutex *mut, string &ref)
:
	d_mutex(mut),
	d_string(ref)
{
}
