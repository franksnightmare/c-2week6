#include "reader.ih"

void countBytes(bool &status, size_t &bytes, string path)
{
	bytes = openFolder(path);
	status = true;
}
