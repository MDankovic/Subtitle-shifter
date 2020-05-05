#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"
#include "dz5.h"

#define FPS 25

int menu()
{
	int opt;

	printf("1. Pomeri titlove u vremenu\n");
	printf("2. Konvertuj titlove\n");
	printf("3. Kraj\n");
	printf("Opcija: ");
	scanf("%d", &opt);

	switch (opt)
	{
	case 1:
	case 2:
	case 3:
		return opt;
		break;
	default:
		printf("Niste odabrali validnu opciju");
		return 0;
		break;
	}
}

int main(int argc, char *argv[])
{
	char oldFileName[MAX_LEN], newFileName[MAX_LEN];
	double shift;
	double fps = 23.976; // TODO: sredi
	int error;

	if(argc < 3) {
		printf("Not correct number of command line arguments!");
		exit(EXIT_FAILURE);
	}
	
	strcpy(oldFileName, argv[1]);
	strcpy(newFileName, argv[2]);
	shift = atoi(argv[3]);

	if (!strcmp(oldFileName, newFileName)) {
		printf("Can't choose the same file!");
		exit(EXIT_FAILURE);
	}
	
	List titles = createList();
	titles = loadTitles(oldFileName);

	int opt = menu();
	while (opt != 3) {
		switch (opt)
		{
		case 1:
			shiftTitles(titles, FPS, shift);
			break;
		case 2:
			convertTitles(titles, newFileName, FPS);
			break;
		default:
			break;
		}
		opt = menu();
	}

	//shiftTitles(titles, 25, shift);
	//convertTitles(titles, newFile, 25);

	deleteList(titles);

	return 0;
}