#include "main.h"

int main()
{
	pid_t pID;
	
	int pipeFD[2];
	if (pipe(pipeFD) != 0)
	{
		cout << "Piping failed!\n";
		return 1;
	}
	
	pID = fork();
	if (pID == 0) // Child
	{
		// Close read pipe and send output to write pipe.
		close(pipeFD[0]);
		dup2(pipeFD[1], STDOUT_FILENO);
		
		// execute command
		execl("/bin/ls", "ls", (char *) 0);
	}
	else if (pID > 0) // Parent
	{
		// Close write pipe and process from the read pipe
		close(pipeFD[1]);
		processPipe(pipeFD[0]);
	}
	else
		cout << "Fork failed: \n";
		return 1;
}
