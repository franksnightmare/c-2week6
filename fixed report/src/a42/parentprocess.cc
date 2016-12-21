#include "main.h"

void processPipe(size_t pipe)
{
	size_t characters = 0;
	size_t lines = 0;
	
	char temp;
	while (true)
	{
		if (read(pipe, &temp, sizeof(char)) != 1) {
			cout << "\nNumber of characters: " << characters
				<< "\n" << "Number of lines: " << lines
				<< "\n";
			break;
		}
		if (temp == '\n')
			++lines;
		++characters;
		
		cout << temp;
	}
}
