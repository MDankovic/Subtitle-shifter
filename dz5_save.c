#include "dz5.h"
#include <stdio.h>
#include <stdlib.h>

// Ispisuje u izlaznu datoteku titlove konvertovane u odgovarajuci format
void convertTitles(List titles, char newFileName[MAX_LEN], double fps)
{
	int error;
	FILE *newFile;
	error = (newFile = fopen(newFileName, "w")) == NULL;
	if (error)
		exit(EXIT_FAILURE);

	Node *curr = titles.first;
	FrameTime fTime;
	double sinceBeginning = 0;
	while (curr) {
		sinceBeginning += curr->data->time.wait;
		fTime = timeToFPS(curr->data->time, sinceBeginning, fps);
		fprintf(newFile, "{%d}{%d}%s\n", fTime.startFrame, fTime.endFrame, curr->data->text);
		sinceBeginning += curr->data->time.length;
		curr = curr->next;
	}

	fclose(newFile);
}