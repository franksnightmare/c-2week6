#include "main.h"

void usechildoutput(int count, char buffer[])
{
	int lines = 0;
	for (int bufferElement = 0;
		bufferElement <= count; ++bufferElement)
	{
		cout << buffer[bufferElement];
		if (buffer[bufferElement] == '\n')
			lines += 1;
	}
	cout << "Number of characters: " << count << "\n";
	cout << "Number of lines: " << lines << "\n";
}
