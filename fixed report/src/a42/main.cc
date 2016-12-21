#include "main.h"

int main()
{
	pid_t pID;
	
	pID = fork();
	if (pID == 0) // Child
	{
		dup2(1, STDOUT_FILENO); // Copies from one file descriptor to another
														// Argument 1 to 2, 0=stdin, 1=stdout, 2=stderr
		execl("/bin/ls", "ls", (char *) 0); // execute command
		
		close(1); // close file descriptor
	}
	else if (pID > 0) // Parent
	{
		// should access file descriptor, (argument 2 in line 10)
		// must display the standard output(files+directories), lines and characters
		 cout << "lines: " <<  << '\n';
	}
	else
		cout << "Fork failed: \n";
		return 1;
}
