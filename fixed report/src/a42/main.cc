#include "main.h"

int main()
{
	int fileDescr[2];
	if (pipe(fileDescr) == -1)
		exit(1);

	int pID = fork();
	if (pID == 0) //Child
	{
		while ((dup2(fileDescr[1],
			STDOUT_FILENO) == -1)) {}
		close(fileDescr[1]);
		close(fileDescr[0]);
		execl("/bin/ls", "ls", (char *) 0);
		_exit(1);
	}

	char buffer[4096];
	while (1)
	{
		int count = read(fileDescr[0], buffer,
			sizeof(buffer));
		if (count == -1)
		{
			exit(1);
		}
		else if (count == 0)
		{
			break;
		}
		else
		{
			usechildoutput(count, buffer);
			exit(1);
		}
	}
	close(fileDescr[0]);
	wait(0);
}
