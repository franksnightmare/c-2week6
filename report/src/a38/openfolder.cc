#include "main.ih"

size_t openFolder(string path)
{
	DIR *dir = opendir(path.c_str());
	if (dir == 0)
		return 0;
	
	size_t bytes = 0;
	struct dirent *pent = 0;
	while((pent = readdir(dir)))
	{
		struct stat sb;
		lstat(pent->d_name, &sb);
		
		bytes += sb.st_size;
		
		if (S_ISDIR(sb.st_mode) == 0)
		{
			string newPath = path + '/' + pent->d_name;
			bytes += openFolder(newPath);
		}
	}
	closedir(dir);
	
	return bytes;
}
