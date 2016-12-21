#include "main.ih"

int main(int argc, char **argv)
{
	watch clock;
	clock.startPoint();

	printFolderSize("./testfolder");

	clock.endPoint();

	clock.startShowTime();
    clock.endShowTime();
    clock.timePassed();
}
